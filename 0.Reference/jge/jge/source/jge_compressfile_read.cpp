#include "jge_compressfile_read.h"
#include <memory.h>

_JGE_BEGIN
//////////////////////////////////////////////////////////////////////////
CompressFileRead::PFN_READ_HEADER CompressFileRead::mPfnReadHeaders[DEF_JGE_COMPRESS_VER] =
{
	&CompressFileRead::_ReadHeader_v1
};
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

CompressFileRead::CompressFileRead() :mpUncompressBuf(0)
{
	memset(&mHeader,0,sizeof(CompressFileHeader));
}
//////////////////////////////////////////////////////////////////////////
CompressFileRead::~CompressFileRead()
{

}
//////////////////////////////////////////////////////////////////////////
errcode CompressFileRead::Open(const char8* pszPath)
{
	errcode ec = FileRead::Open(pszPath);
	if(ec == DEF_JGE_OK)
	{
 		memset(&mHeader,0,sizeof(CompressFileHeader));
 		// read header
		CompressFileVer ver ;
		FileRead::Read(&ver,sizeof(CompressFileVer));
		mHeader.nVer = ver.nVer;
		for(uint i =ver.nVer-1 ; i < DEF_JGE_COMPRESS_VER ; ++i)
		{
			(this->*mPfnReadHeaders[i])(mHeader);
		}
		//建立Buffer		
		
// 		mpUncompressBuf	=new BYTE[mHeader.nCompBufSize];
// 		if(mpUncompressBuf==NULL )
// 			return false;
// 		if(m_ucUnCompBuf==NULL )
// 			return false;
// 		//讀取原始檔案大小
// 		CFileAccress::Read(&m_dwFileSize,sizeof(m_dwFileSize));	
	}
	return ec;
}
//////////////////////////////////////////////////////////////////////////
void CompressFileRead::Close()
{
	if(mpUncompressBuf)
	{
		delete mpUncompressBuf;
	}
}
//////////////////////////////////////////////////////////////////////////
JGE::errcode CompressFileRead::Read(void* pBuffer,uint nBufferSize,uint* pnReadSize)
{
	if(!FileRead::IsEof())
	{

	}
	return 0;

}
//////////////////////////////////////////////////////////////////////////
uint CompressFileRead::_ReadFileToUncompBuf()
{
	if(!FileRead::IsEof() )
	{
// 		uint32 nDesBufSize;
// 		uint32 nSrcBufSize;
// 		//讀取檔頭
// 		if(FileRead::Read(&nDesBufSize,sizeof(nDesBufSize)) != DEF_JGE_OK)//讀取原長度
// 			return 0;
// 		if(FileRead::Read(&nSrcBufSize,sizeof(nSrcBufSize)) != DEF_JGE_OK)//讀取壓縮長度
// 			return 0;
// 
// 		//讀取長度
// 		uint32 nReadBufSize ;
// 		if(FileRead::Read(mCompressBuf,nSrcBufSize,&nReadBufSize) != DEF_JGE_OK)
// 			return 0;
// 
// 		uncompress((Bytef *)m_ucUnCompBuf,&dwDesBufSize,(Bytef*)m_ucCompBuf,dwSrcBufSize);
// 
// 		
// 
// 		m_dwUnCompIdx=dwDesBufSize; //Idx
// 		m_dwUnCompSize=dwDesBufSize;//實際讀取大小
// 		return m_dwUnCompIdx;
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////
void CompressFileRead::_ReadHeader_v1(CompressFileHeader& header)
{
	CompressFileHeader_v1 ver_v1;
	if(FileRead::Read(&ver_v1,sizeof(CompressFileHeader_v1)) == DEF_JGE_OK)
	{
		header.nCompBufSize = ver_v1.nCompBufSize;
		header.nFileSize	= ver_v1.nFileSize;
	}

}
_JGE_END