#ifndef _jge_file_write_20080212am0135_
#define _jge_file_write_20080212am0135_

#include "jge_type.h"
#include "jge_file_def.h"
#include <stdio.h>
_JGE_BEGIN
class FileWrite : public IStreamWrite
{
	FILE*	mpFile;
public:
			FileWrite	();
			~FileWrite	();
	
	errcode	Create		(const char8* pszPath);
	void	Close		();

	errcode	Write		(void* pBuffer,uint nBufferSize,uint* pnWriteSize);
};

_JGE_END
#endif