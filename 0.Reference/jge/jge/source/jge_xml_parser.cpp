#include "jge_xml_parser.h"
#include "jge_Define.h"
#include "jge_utility.h"
#ifdef DEF_JGE_DEBUG
#include <memory.h>
#endif
_JGE_BEGIN

namespace XML
{
	
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////		
	//////////////////////////////////////////////////////////////////////////
	IListener::IListener()
	{
		
	}
	//////////////////////////////////////////////////////////////////////////
	IListener::~IListener()
	{
		
	}
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	
	//////////////////////////////////////////////////////////////////////////
	Parser::PFN_PARSER Parser::mvPfnParser[]=
	{
		&Parser::_ParserElementStart,
		&Parser::_ParserAttribName,
		&Parser::_ParserAttribValue,
		&Parser::_ParserText,
		&Parser::_ParserElementEnd
	};	
	//////////////////////////////////////////////////////////////////////////
	Parser::Parser() : 
		 mpListener(0) 
		,mpStream(0) 		
		,mCurrentParser(Text) 
		,mnLabelLen(0)
		,mnValueLen(0)	
	{
		
	}
	//////////////////////////////////////////////////////////////////////////
	Parser::~Parser()
	{
		mpListener	= 0;
		mpStream	= 0;
	}
	//////////////////////////////////////////////////////////////////////////
	void Parser::Start(IStreamRead* pStream,IListener* pListener)
	{
		if(pListener == 0 || pStream == 0)
			return ;
		
		mpListener	= pListener;
		mpStream	= pStream;
		// check unicode
		if(_UnicodeText())
		{
			mpListener->OnDocStart();
			_ReadStream();
			mpListener->OnDocEnd();
		}
		else
		{
			mpListener->OnError(NOT_UNICODE_TEXT,0,0);
		}
	}
	//////////////////////////////////////////////////////////////////////////
	boole Parser::_UnicodeText()
	{
		uint16 nUnicodeHeader ;
		mpStream->Read(&nUnicodeHeader,sizeof(uint16));
		return nUnicodeHeader == DEF_JGE_UNICODE_HEADER;
	}
	//////////////////////////////////////////////////////////////////////////
	void Parser::_ReadStream()
	{
		const uint nBufferSize = 8;
		uint16 vBuffer[nBufferSize] ={0};
		uint nReadBytes;
		do 
		{
			nReadBytes = 0;
			if(mpStream->Read(vBuffer,nBufferSize*sizeof(uint16),&nReadBytes) == DEF_JGE_OK)
			{
				_Parser(vBuffer,nReadBytes/sizeof(uint16));
			}
		} while(nReadBytes/sizeof(uint16) == nBufferSize);
		
	}
	//////////////////////////////////////////////////////////////////////////
	void Parser::_Parser(const uint16* pSrcBuffer,uint nSrcSize)
	{
		/************************************************************************/
		/* 
			xml 解晰 遇到什麼解析什麼	
		*/
		/************************************************************************/
		uint i;
		for(i = 0; i < nSrcSize; )
		{
			i += (this->*mvPfnParser[mCurrentParser])(&pSrcBuffer[i],nSrcSize - i);
		}
	}
	//////////////////////////////////////////////////////////////////////////
	uint Parser::_ParserElementStart(const uint16* pSrcBuffer,uint nSrcSize)
	{
		uint i;
		for(i = 0; i < nSrcSize; ++i)
		{
			if(Utility::ControllCharW(pSrcBuffer[i]) == true)
				continue;
			if( (pSrcBuffer[i] == L' ') && mnLabelLen == 0)
				continue;

			mLabel[mnLabelLen] = pSrcBuffer[i];
			// check elementstart end?
			if(mLabel[mnLabelLen] == L' ')
			{				
				
				mpListener->OnElementStart(mLabel,mnLabelLen);
#ifdef DEF_JGE_DEBUG
				memset(mLabel,0,sizeof(mLabel));
#endif
				mnLabelLen = 0;
				mCurrentParser = AttribName;
				return i+1;
			}
			// />
			else if(mnLabelLen > 1 && mLabel[mnLabelLen] == L'>' && mLabel[mnLabelLen-1] == L'/')
			{
				mCurrentParser = ElementStart;				
				mpListener->OnElementStart(mLabel,mnLabelLen-1);
#ifdef DEF_JGE_DEBUG
				memset(mLabel,0,sizeof(mLabel));
#endif
				mnLabelLen = 0;
				return i+1;
			}
			else if(mLabel[mnLabelLen] == L'>')
			{				
				mpListener->OnElementStart(mLabel,mnLabelLen);
#ifdef DEF_JGE_DEBUG
				memset(mLabel,0,sizeof(mLabel));
#endif
				mnLabelLen = 0;
				mCurrentParser = Text;
				return i+1;
			}
			mnLabelLen ++;
		}
		return i;
	}
	
	//////////////////////////////////////////////////////////////////////////
	uint Parser::_ParserAttribName(const uint16* pSrcBuffer,uint nSrcSize)
	{
		uint i;
		for(i = 0; i < nSrcSize; ++i)
		{
			if(Utility::ControllCharW(pSrcBuffer[i]) == true)
				continue;
			if( pSrcBuffer[i] == L' ')
				continue;
			
			mLabel[mnLabelLen] = pSrcBuffer[i];
			// check attribname end?
			if(mLabel[mnLabelLen] == L'=')
			{
				mCurrentParser = AttribValue;
				return i+1;
			}
			// />
			else if(mnLabelLen > 1 && mLabel[mnLabelLen] == L'>' && mLabel[mnLabelLen-1] == L'/')
			{
				
				mCurrentParser = ElementStart;
#ifdef DEF_JGE_DEBUG
				memset(mLabel,0,sizeof(mLabel));
#endif
				mnLabelLen = 0;
				return i+1;
			}
			else if(mLabel[mnLabelLen] == L'>')
			{								
				mCurrentParser = Text;
#ifdef DEF_JGE_DEBUG
				memset(mLabel,0,sizeof(mLabel));
#endif
				mnLabelLen = 0;
				return i+1;
			}	
			mnLabelLen++;
		}
		return i;
	}
	//////////////////////////////////////////////////////////////////////////
	uint Parser::_ParserAttribValue(const uint16* pSrcBuffer,uint nSrcSize)
	{
		uint i;
		for(i = 0; i < nSrcSize; ++i)
		{
			if(Utility::ControllCharW(pSrcBuffer[i]) == true)
				continue;
			if(pSrcBuffer[i] != L'\"' && mnValueLen == 0)
				continue;

			mValue[mnValueLen] = pSrcBuffer[i];
			if(mValue[mnValueLen] == L'\"' && mnValueLen != 0)
			{
				mpListener->OnAttrib(mLabel,mnLabelLen,&mValue[1],mnValueLen-1);
#ifdef DEF_JGE_DEBUG
				memset(mLabel,0,sizeof(mLabel));
#endif
				mnLabelLen = 0;
				mnValueLen = 0;
				mCurrentParser = AttribName;
				return i+1;
			}
		
			mnValueLen++;
		}
		return i;
	}
	//////////////////////////////////////////////////////////////////////////
	uint Parser::_ParserText(const uint16* pSrcBuffer,uint nSrcSize)
	{
		uint i;
		for(i = 0; i < nSrcSize; ++i)
		{	
			if(Utility::ControllCharW(pSrcBuffer[i]) == true)
				continue;
			mValue[mnValueLen] = pSrcBuffer[i];
			if(mnValueLen > 0 && mValue[mnValueLen-1] == L'<')
			{
				if(mValue[mnValueLen] != L'/')
				{
					if(mnValueLen > 2)
						mpListener->OnError(FMT_ERROR,&mValue[0],mnValueLen-2);
#ifdef DEF_JGE_DEBUG
					memset(mValue,0,sizeof(mValue));
#endif
					mnValueLen = 0;
					mCurrentParser = ElementStart;
					return i;
				}
				else if(mValue[mnValueLen] == L'/')
				{
					if(mnValueLen > 1)
						mpListener->OnText(&mValue[0],mnValueLen-1);
#ifdef DEF_JGE_DEBUG
					memset(mValue,0,sizeof(mValue));
#endif
					mnValueLen = 0;
					mCurrentParser = ElementEnd;
					return i+1;
				}
			}
			

			mnValueLen++;
		}
		return i;
	}
	//////////////////////////////////////////////////////////////////////////
	uint Parser::_ParserElementEnd(const uint16* pSrcBuffer,uint nSrcSize)
	{
		uint i;
		for(i = 0; i < nSrcSize; ++i)
		{
			if(Utility::ControllCharW(pSrcBuffer[i]) == true)
				continue;
			if(pSrcBuffer[i] == L' ')
			{
				continue;
			}

			mLabel[mnLabelLen] = pSrcBuffer[i];
			if(mLabel[mnLabelLen] == L'>')
			{
				if(mnLabelLen > 0)
					mpListener->OnElementEnd(&mLabel[0],mnLabelLen);
#ifdef DEF_JGE_DEBUG
				memset(mLabel,0,sizeof(mLabel));
#endif
				mnLabelLen = 0;
				mCurrentParser = Text;
				return i+1;
			}
			mnLabelLen ++;
		}
		return i;
	}
};
_JGE_END