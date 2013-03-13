
//---------------------------------------------------------------------------
//
// CustomThread.cpp
//
// SUBSYSTEM: 
//              Monitoring process creation and termination  
//子系統：
//監視進程創建和終止
// MODULE:    
//              Thread management 
//模塊：
//線程管理
//
// DESCRIPTION:
//              This is an abstract class that enables creation of separate 
//              threads of execution in an application. 
//這是一個抽象類，允許建立獨立
//線程應用程序的執行。
//
// AUTHOR:		Ivo Ivanov
//                                                                         
//---------------------------------------------------------------------------
#include "CustomThread.h"
#include <process.h>
#include <assert.h>

//---------------------------------------------------------------------------
//
// Thread function prototype
//
//---------------------------------------------------------------------------
typedef unsigned (__stdcall *PTHREAD_START) (void *);

//---------------------------------------------------------------------------
//
// class CCustomThread 
//
// It is an abstract class that enables creation of separate threads of 
// execution.
//這是一個抽象類，允許創建獨立線程
//執行。
//                                                                         
//---------------------------------------------------------------------------

HANDLE CCustomThread::sm_hThread = NULL;

CCustomThread::CCustomThread(TCHAR* pszThreadGuid):
	m_hShutdownEvent(NULL),
	m_bThreadActive(NULL),
	m_dwThreadId(NULL)
{
	if (NULL != pszThreadGuid)
		wcscpy_s(m_szThreadGuid, pszThreadGuid);
	else
		wcscpy_s(m_szThreadGuid, TEXT(""));
}

CCustomThread::~CCustomThread()
{	
	SetActive( FALSE );
}

//
// Activate / Stop the thread 
//激活/停止線程
//
void CCustomThread::SetActive(BOOL bValue)
{
	BOOL bCurrent = GetIsActive();

	if (bValue != bCurrent)
	{
		if (!bCurrent)
		{
			//
			// Perform action prior to activate the thread
//執行行動之前激活的線程
			//
			if (!OnBeforeActivate())
				return;

			if (0 != _tcslen(m_szThreadGuid))
				m_hShutdownEvent = ::CreateEvent(NULL, FALSE, FALSE, m_szThreadGuid);
			ULONG ulResult = _beginthreadex(
				(void *)NULL,
				(unsigned)0,
				(PTHREAD_START)CCustomThread::ThreadFunc,
				(PVOID)this,
				(unsigned)0,
				(unsigned *)&m_dwThreadId
				);
			if (ulResult != -1)
				//
				// Wait until the thread gets activated
//等待，直到該線程被激活
				//
				while (!GetIsActive())
				{
				}
		} 
		else
		{
			if ( GetIsActive() )
			{
				if (NULL != m_hShutdownEvent)
					//
					// Signal the thread's event
//信號的線程的事件
					//
					::SetEvent(m_hShutdownEvent);
				//
				// Wait until the thread is done
//等待，直到線程完成
//
				//
				while (GetIsActive())
				{
				}
				//
				// Called after the thread function exits
//線程函數退出後調用
				//
				OnAfterDeactivate();
			} // if
			if (NULL != m_hShutdownEvent)
				::CloseHandle(m_hShutdownEvent);
		}
	} // if
}

//
// Indicates whether the driver has been activated
//表示該驅動程序是否已被激活
//
BOOL CCustomThread::GetIsActive()
{
	CLockMgr<CCSWrapper> lockMgr(m_CritSec, TRUE);	
	return m_bThreadActive;
}

//
// Setup the attribute
//設置屬性
//
void CCustomThread::SetIsActive(BOOL bValue)
{
	CLockMgr<CCSWrapper> lockMgr(m_CritSec, TRUE);	
	m_bThreadActive = bValue;
}


//
// Return the handle to the thread's shut down event
//返回線程句柄的關閉事件
//
HANDLE CCustomThread::Get_ShutdownEvent() const
{
	return m_hShutdownEvent;
}

//
// Primary thread entry point
//主線程的入口點
//
unsigned __stdcall CCustomThread::ThreadFunc(void* pvParam)
{
	CCustomThread* pMe = (CCustomThread*)( pvParam );
	// retrieves a pseudo handle for the current thread
//檢索當前線程的偽句柄
	sm_hThread = GetCurrentThread();
	try
	{
		pMe->SetIsActive( TRUE );
		// Execute the user supplied method
//執行用戶提供的方法
		pMe->Run();
	}
	catch (...)
	{
		// Handle all exceptions
//處理所有異常
	}
	pMe->SetIsActive( FALSE );
	_endthreadex(0);
	return 0;
}


//
// Perform action prior to activate the thread
//執行行動之前激活的線程
//
BOOL CCustomThread::OnBeforeActivate()
{
	// Provide default implementation
//提供默認的實現
	return TRUE;
}

//
// Called after the thread function exits
//線程函數退出後調用
//
void CCustomThread::OnAfterDeactivate()
{
	// Do nothing
//什麼也不做
}

//----------------------------End of the file -------------------------------