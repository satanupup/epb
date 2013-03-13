#ifndef _jge_file_read_20080212am1259_
#define _jge_file_read_20080212am1259_
#include "jge_type.h"
#include "jge_file_def.h"
#include <stdio.h>
_JGE_BEGIN


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
class FileRead : public IStreamRead
{
	FILE*		mpFile;
public:
				FileRead	();
	virtual		~FileRead	();

	errcode		Open		(const char8* pszPath);
	void		Close		();

	errcode		Read		(void* pBuffer,uint nBufferSize,uint* pnReadSize = 0);
	boole		IsEof		() const;

	uint		GetSize		() ;
};

_JGE_END
#endif