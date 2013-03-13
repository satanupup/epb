#include "jge_debug.h"
#include <stdarg.h>
#include <string.h>

#define DEF_YEAR 1900
_JGE_BEGIN
tm mZeroTime;
//////////////////////////////////////////////////////////////////////////
DebugLog::DebugLog() : mpFile(0) ,mStartTime(0)
{

}
//////////////////////////////////////////////////////////////////////////
DebugLog::~DebugLog()
{

}
////////////////////////////////////////////////////////////////////////
errcode DebugLog::Create(const char16 *sProjectName)
{
	char path[DEF_JGE_PATH_LEN] ={0};
	if(wcslen(sProjectName) > DEF_JGE_PROJECT_NAME_LEN)
		return DEF_JGE_PROJECT_NAME_TOO_LONG;
#ifdef DEF_JGE_DEBUG	
	wcscpy(mProjectName,sProjectName);
	struct tm *newtime;

	mStartTime = 0;
	newtime = localtime( &mStartTime ); 
	memcpy(&mZeroTime,newtime,sizeof(tm));

	mStartTime = time(0);
	newtime = localtime( &mStartTime ); 

	/*
		!! - 會有記憶體複寫的錯誤之可能性 ...
		原因: path長度是project長度之ㄧ半
	*/
	
	sprintf(path,"DebugLog_%.4d%.2d%.2d_%.2d%.2d%.2d.txt"
			,newtime->tm_year+DEF_YEAR,newtime->tm_mon+1,newtime->tm_mday
			,newtime->tm_hour,newtime->tm_min,newtime->tm_sec);
	
	mpFile = fopen(path,"wb");
	if(mpFile)
	{		
		_MakeUnicodeHeader();
		_WriteLogInfo();
		
		_WriteStart();
		return DEF_JGE_OK;
	}
#else
	return DEF_JGE_OK;
#endif
	return DEF_JGE_DEBUG_LOG_OPENFILE_FAIL;		
}
//////////////////////////////////////////////////////////////////////////
void DebugLog::Destory()
{
#ifdef DEF_JGE_DEBUG	
	_WriteDone();
	if(mpFile != 0)
	{
		fclose(mpFile);
		mpFile = 0;
	}
#endif
}
////////////////////////////////////////////////////////////////////////
void DebugLog::Log(const char16 *pszFormat, ...)
{
	char16 newFormat[1024];
	tm newtime  ;
	_PassTime(&newtime);

	swprintf(newFormat,L"[%.2d/%.2d/%.2d-%.2d:%.2d:%.2d]%s"
		,newtime.tm_year,newtime.tm_mon,newtime.tm_mday
		,newtime.tm_hour,newtime.tm_min,newtime.tm_sec
		,pszFormat);

	if(mpFile)
	{
		va_list args;
		va_start(args,pszFormat);
		vfwprintf(mpFile,newFormat,args);
		va_end(args);
		fflush(mpFile);
	}
	
	
}
//////////////////////////////////////////////////////////////////////////
void DebugLog::LogLn(const char16 *pszFormat, ...) 
{
	char16 newFormat[1024];
	tm newtime  ;
	_PassTime(&newtime);
	
	swprintf(newFormat,L"[%.2d/%.2d/%.2d-%.2d:%.2d:%.2d]%s\r\n"
		,newtime.tm_year,newtime.tm_mon,newtime.tm_mday
		,newtime.tm_hour,newtime.tm_min,newtime.tm_sec
		,pszFormat);
	
	if(mpFile)
	{
		va_list args;
		va_start(args,pszFormat);
		vfwprintf(mpFile,newFormat,args);
		va_end(args);
		fflush(mpFile);
	}
}
//////////////////////////////////////////////////////////////////////////
void DebugLog::_MakeUnicodeHeader()
{
	unsigned short unicode = DEF_JGE_UNICODE_HEADER ;
	fwrite( (void*)&unicode,1,sizeof(unsigned short),mpFile) ;
	fflush(mpFile);
}
//////////////////////////////////////////////////////////////////////////
void DebugLog::_WriteLogInfo()
{
	const char16* pszHeaderInfoFmt = L"Project:%s\r\nDate:%.4d/%.2d/%.2d %.2d:%.2d:%.2d\r\n\r\n";
	struct tm *newtime;
	newtime = localtime( &mStartTime );
	fwprintf(mpFile,pszHeaderInfoFmt,mProjectName
		,newtime->tm_year+DEF_YEAR,newtime->tm_mon+1,newtime->tm_mday
		,newtime->tm_hour,newtime->tm_min,newtime->tm_sec);
	
	fflush(mpFile);
}
//////////////////////////////////////////////////////////////////////////
void DebugLog::_WriteDone()
{
	Log(L"Done.");
}
//////////////////////////////////////////////////////////////////////////
void DebugLog::_WriteStart()
{
	LogLn(L"Start.");
}
//////////////////////////////////////////////////////////////////////////
void DebugLog::_PassTime(tm* ptm)
{
	time_t passTime = time(0) - mStartTime;
	
	tm * passtime = localtime(&passTime)	;
	memcpy(ptm,passtime,sizeof(tm));

	ptm->tm_sec		-=mZeroTime.tm_sec	;     /* seconds after the minute - [0,59] */
	ptm->tm_min		-=mZeroTime.tm_min	;     /* minutes after the hour - [0,59] */
	ptm->tm_hour	-=mZeroTime.tm_hour	;   /* hours since midnight - [0,23] */
	ptm->tm_mday	-=mZeroTime.tm_mday	;    /* day of the month - [1,31] */
	ptm->tm_mon		-=mZeroTime.tm_mon	;    /* months since January - [0,11] */
	ptm->tm_year	-=mZeroTime.tm_year	;  /* years since 1900 */
	ptm->tm_wday	-=mZeroTime.tm_wday	; /* days since Sunday - [0,6] */
	ptm->tm_yday	-=mZeroTime.tm_yday	;    /* days since January 1 - [0,365] */
	ptm->tm_isdst	-=mZeroTime.tm_isdst;	   /* daylight savings time flag */
	
}


_JGE_END