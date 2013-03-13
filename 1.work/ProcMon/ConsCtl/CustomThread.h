//---------------------------------------------------------------------------
//
// CustomThread.h
//
// SUBSYSTEM: 
//				
// MODULE:    
//
// DESCRIPTION:
//
// AUTHOR:		Ivo Ivanov
//                                                                         
//---------------------------------------------------------------------------
#if !defined(_CUSTOMTHREAD_H_)
#define _CUSTOMTHREAD_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//---------------------------------------------------------------------------
//
// Includes
//
//---------------------------------------------------------------------------
#include "common.h"
#include <tchar.h>
#include <windows.h>
#include "LockMgr.h"


//---------------------------------------------------------------------------
//
// class CCustomThread  
//
// It is an abstract class that enables creation of separate threads of 
// execution.
//                                                                         
//---------------------------------------------------------------------------
class CCustomThread  
{
public:
	CCustomThread(TCHAR* pszThreadGuid);
	virtual ~CCustomThread();
	//
	// Activate / Stop the thread 
	//
	void SetActive(BOOL bValue);
	//
	// Indicates whether the driver has been activated
	//
	BOOL GetIsActive();
	//
	// Setup the attribute
	//
	void SetIsActive(BOOL bValue);
	//
	// Return the handle to the thread's shut down event
	//
	HANDLE Get_ShutdownEvent() const;
private:
	//
	// Primary thread entry point
	//
	static unsigned __stdcall ThreadFunc(void* pvParam);
	//
	// Thread attributes
	//
	BOOL          m_bThreadActive;
	DWORD         m_dwThreadId;
	static HANDLE sm_hThread;
	CCSWrapper    m_CritSec;
	//
	// The name of the shut down event
	//
	TCHAR         m_szThreadGuid[255];
protected:
	HANDLE        m_hShutdownEvent;
	//
	// A user supplied implementation of the thread function.
	// Override Run() and insert the code that should be executed when 
	// the thread runs.
	//
	virtual void Run() = 0;
	//
	// Perform action prior to activate the thread
	//
	virtual BOOL OnBeforeActivate();
	//
	// Called after the thread function exits
	//
	virtual void OnAfterDeactivate();
};

#endif // !defined(_CUSTOMTHREAD_H_)
//----------------------------End of the file -------------------------------