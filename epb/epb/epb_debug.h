#ifndef _epb_debug_20120622pm0945_
#define _epb_debug_20120622pm0945_

#include "epb_type.h"
#include "epb_singleton.h"
#include <stdio.h>
#include <time.h>
//#define DEF_EPB_DEBUG   1
_EPB_BEGIN

//////////////////////////////////////////////////////////////////////////
/*
	
*/
class DebugLog : public TSingleton<DebugLog>
{
	FILE*			mpFile;	
	time_t			mStartTime;	
	char16			mProjectName[DEF_EPB_PROJECT_NAME_LEN];


	void		_MakeUnicodeHeader	();
	void		_WriteLogInfo		();
	void		_WriteDone			();
	void		_WriteStart			();
	void		_PassTime			(tm* ptm);
public:
			DebugLog	();
			~DebugLog	();
	
	errcode	Create		(const char16 *sProjectName);
	void	Destory		();
	void	Log			(const char16 *pszFormat, ...) ;
	void	LogLn		(const char16 *pszFormat, ...) ;
	
};

_EPB_END
#ifdef DEF_EPB_DEBUG

#define _EPB_DBGLOG		EPB::DebugLog::fnGetInstance().Log
#define _EPB_DBGLOGLN	EPB::DebugLog::fnGetInstance().LogLn


#else

#define _EPB_DBGLOG		__noop
#define _EPB_DBGLOGLN	__noop

#endif

#endif