#ifndef _jge_compressfile_header_20080213am1239_
#define _jge_compressfile_header_20080213am1239_
#include "jge_type.h"

_JGE_BEGIN
#pragma pack(push, 1)
typedef struct
{
	uint32	nVer;
} CompressFileVer;
//////////////////////////////////////////////////////////////////////////
struct CompressFileHeader_v1
{
	uint32			nFileSize;
	uint32			nCompBufSize;
	uint32			nUncompBufSize;
};
//////////////////////////////////////////////////////////////////////////

struct CompressFileHeader :public CompressFileVer, public CompressFileHeader_v1
{
};
#pragma pack(pop)


_JGE_END
#endif