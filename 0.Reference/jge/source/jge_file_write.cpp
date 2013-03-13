#include "jge_file_write.h"
#include <io.h>
_JGE_BEGIN
FileWrite::FileWrite() : mpFile(0)
{
}
//////////////////////////////////////////////////////////////////////////
FileWrite::~FileWrite()
{

}
//////////////////////////////////////////////////////////////////////////
errcode	FileWrite::Create(const char8* pszPath)
{	
	mpFile=fopen(pszPath,"w+b");

	if(mpFile==NULL)
	{	
		//無法建立檔案
		return DEF_JGE_FILE_CREATE_FAIL;
	}
	
	return DEF_JGE_OK;
}
//////////////////////////////////////////////////////////////////////////
void FileWrite::Close()
{
	if(mpFile)
	{
		close(fileno(mpFile));
		mpFile = 0;
	}	
}
//////////////////////////////////////////////////////////////////////////
errcode	FileWrite::Write(void* pBuffer,uint nBufferSize,uint* pnWriteSize)
{
#define _set_write_size(size) if(pnWriteSize) *pnWriteSize = size;
	if(mpFile)
	{
		uint nWriteSize = fwrite(pBuffer,nBufferSize,1,mpFile);
		_set_write_size(nWriteSize);
		fflush(mpFile);
		//ftell(mpFile);
		return DEF_JGE_OK;
	}
	return DEF_JGE_FILE_WRITE_ERROR;
}
_JGE_END