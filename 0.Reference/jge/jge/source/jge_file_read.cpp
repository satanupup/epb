#include "jge_file_read.h"
#include <io.h>
_JGE_BEGIN
FileRead::FileRead() : mpFile(0)
{

}
//////////////////////////////////////////////////////////////////////////
FileRead::~FileRead()
{

}
//////////////////////////////////////////////////////////////////////////
errcode FileRead::Open(const char8* pszPath)
{
	//開啟檔案
	mpFile=fopen(pszPath,"r+b");
	
	if(mpFile!=NULL)
	{		
		return DEF_JGE_OK;
	}
	

	return DEF_JGE_FILE_OPEN_FAIL;
}
//////////////////////////////////////////////////////////////////////////
void FileRead::Close()
{
	if(mpFile)
	{
		close(fileno(mpFile));
		mpFile = 0;
	}		
}
//////////////////////////////////////////////////////////////////////////

errcode FileRead::Read(void* pBuffer,uint nBufferSize,uint* pnReadSize )
{
#define _set_read_size(size) if(pnReadSize) *pnReadSize = size;
	if(feof(mpFile))
	{
		//檔案已到結尾
		_set_read_size(0);
		return DEF_JGE_END_OF_FILE;
	}
	size_t stRealReadSize=fread(pBuffer,1,nBufferSize,mpFile);
	_set_read_size(stRealReadSize);
	if(stRealReadSize==nBufferSize)
	{	
		//讀取成功
		
		return DEF_JGE_OK;
	}

	else if(stRealReadSize==0)
	{
		//讀取失敗
		
		if(feof(mpFile))
		{
			//檔案已到結尾
			return DEF_JGE_END_OF_FILE;
		}
		
		return DEF_JGE_FILE_READ_ERROR;
	}
	else if (stRealReadSize < nBufferSize)
	{
		//如果真實讀到的大小小於原本的大小
		//代表檔案已到結尾
		//讀取成功,但是並不是完整的緩衝大小\0";
		return DEF_JGE_OK;
	}
	return DEF_JGE_FILE_READ_ERROR;
}
//////////////////////////////////////////////////////////////////////////
boole FileRead::IsEof() const
{
	if(mpFile)
		return feof(mpFile) == 0;
	return false;
}
//////////////////////////////////////////////////////////////////////////
uint FileRead::GetSize() 
{
	if(mpFile)
	{
		return ftell(mpFile);
	}
	return 0;
	
}
_JGE_END