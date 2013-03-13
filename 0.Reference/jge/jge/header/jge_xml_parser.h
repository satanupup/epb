#ifndef _jge_xml_parser_20080214pm1210_
#define _jge_xml_parser_20080214pm1210_
#include "jge_stream_def.h"
_JGE_BEGIN

namespace XML
{
	typedef enum {
		 NONE
		,NOT_UNICODE_TEXT
		,FMT_ERROR
		} Error;
	class IListener
	{
	public:
						IListener		();
		virtual 		~IListener		();
		//////////////////////////////////////////////////////////////////////////
		virtual void	OnDocStart		() = 0;
		virtual void	OnDocEnd		() = 0;
		//////////////////////////////////////////////////////////////////////////
		virtual	void	OnElementStart	(const char16* pszElement,uint nElementLen) = 0;
		virtual	void	OnElementEnd	(const char16* pszElement,uint nElementLen) = 0;
		virtual	void	OnAttrib		(const char16* pszAttrib,uint nAttribLen,const char16* pszValue,uint nValueLen) = 0;
		virtual	void	OnText			(const char16* pszText,uint nTextLen) = 0;
		//////////////////////////////////////////////////////////////////////////
		virtual void	OnError			(Error err,const char16* pszLabel,uint nLabelLen) = 0;
	};
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
#define DEF_JGE_XML_LABEL_LEN 64+2
#define DEF_JGE_XML_VALUE_LEN 260+2
	class Parser
	{
		IListener*		mpListener;
		IStreamRead*	mpStream;
		//////////////////////////////////////////////////////////////////////////
		typedef
			enum
			{
				ElementStart,AttribName,AttribValue,Text,ElementEnd
			}
		CurrentParser;
		CurrentParser	mCurrentParser;
		
		char16			mLabel[DEF_JGE_XML_LABEL_LEN];
		char16			mValue[DEF_JGE_XML_VALUE_LEN];
		uint			mnLabelLen;
		uint			mnValueLen;
		//////////////////////////////////////////////////////////////////////////

		void	_ReadStream	();
		void	_Parser		(const uint16* pSrcBuffer,uint nSrcSize);
		boole	_UnicodeText();

		//////////////////////////////////////////////////////////////////////////
		typedef uint (Parser::*PFN_PARSER)(const uint16* pSrcBuffer,uint nSrcSize);
			
		uint	_ParserElementStart		(const uint16* pSrcBuffer,uint nSrcSize);
		uint	_ParserAttribName		(const uint16* pSrcBuffer,uint nSrcSize);
		uint	_ParserAttribValue		(const uint16* pSrcBuffer,uint nSrcSize);
		uint	_ParserText				(const uint16* pSrcBuffer,uint nSrcSize);
		uint	_ParserElementEnd		(const uint16* pSrcBuffer,uint nSrcSize);
		//////////////////////////////////////////////////////////////////////////
		
	public:
		static PFN_PARSER	mvPfnParser[];
				Parser		();
				~Parser		();

		void	Start		(IStreamRead* pStream,IListener* pListener);
	};
};

_JGE_END
#endif