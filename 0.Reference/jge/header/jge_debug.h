#ifndef _jge_debug_20080204pm1150_
#define _jge_debug_20080204pm1150_

#include "jge_type.h"
#include "jge_singleton.h"
#include <stdio.h>
#include <time.h>
//#define DEF_JGE_DEBUG   1
_JGE_BEGIN

//////////////////////////////////////////////////////////////////////////
/*
	
*/
class DebugLog : public TSingleton<DebugLog>
{
	FILE*			mpFile;	
	time_t			mStartTime;	
	char16			mProjectName[DEF_JGE_PROJECT_NAME_LEN];


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

_JGE_END
#ifdef DEF_JGE_DEBUG

#define _JGE_DBGLOG		JGE::DebugLog::fnGetInstance().Log
#define _JGE_DBGLOGLN	JGE::DebugLog::fnGetInstance().LogLn


#else

#define _JGE_DBGLOG		__noop
#define _JGE_DBGLOGLN	__noop

#endif

#endif