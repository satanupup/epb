#ifndef _jge_compressfile_read_20080212pm1248_
#define _jge_compressfile_read_20080212pm1248_
#include "jge_type.h"
#include "jge_file_read.h"
#include "jge_compressfile_header.h"
_JGE_BEGIN



#define DEF_JGE_COMPRESS_VER 1
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

class CompressFileRead : public FileRead
{
	CompressFileHeader	mHeader;

	//////////////////////////////////////////////////////////////////////////
	//
	
	//m_ucUnCompBuf // 解壓縮區塊
	uint8*		mpUncompressBuf;
	
	uint		_ReadFileToUncompBuf	();
	//////////////////////////////////////////////////////////////////////////
	// 檔頭讀取
	typedef void (CompressFileRead::*PFN_READ_HEADER)(CompressFileHeader& header) ;
	static PFN_READ_HEADER	mPfnReadHeaders[DEF_JGE_COMPRESS_VER];
	void		_ReadHeader_v1			(CompressFileHeader& header);
public:
				CompressFileRead		();
				~CompressFileRead		();

	errcode		Open					(const char8* pszPath);
	void		Close					();

	errcode		Read					(void* pBuffer,uint nBufferSize,uint* pnReadSize = 0);

};

_JGE_END

#endif