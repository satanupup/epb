#ifndef _jge_stream_def_20080213am0139_
#define _jge_stream_def_20080213am0139_

#include "jge_type.h"

_JGE_BEGIN
struct IStream
{
	
};

class IStreamRead : public IStream
{
public:
	virtual errcode		Read		(void* pBuffer,uint nBufferSize,uint* pnReadSize = 0) = 0;
	virtual uint		GetSize		() = 0;
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
class IStreamWrite : public IStream
{
public:
	virtual errcode		Write		(void* pBuffer,uint nBufferSize,uint* pnWriteSize = 0) = 0;
};

_JGE_END
#endif