//---------------------------------------------------------------------------
//
// RetrievalThread.cpp
//
// SUBSYSTEM: 
//              Monitoring process creation and termination  
//監視進程創建和終止
//				
// MODULE:    
//              Provides an interface for handling queued items
//提供一個接口處理排隊項目
//
// DESCRIPTION:
//
// AUTHOR:		Ivo Ivanov
//                                                                         
//---------------------------------------------------------------------------
#include "RetrievalThread.h"
#include "QueueContainer.h"

//---------------------------------------------------------------------------
//
// class CRetrievalThread
//
//---------------------------------------------------------------------------

CRetrievalThread::CRetrievalThread(
	TCHAR*            pszThreadGuid,
	CQueueContainer*  pQueue
	):
	CCustomThread(pszThreadGuid),
	m_pQueue(pQueue)
{
	assert( NULL != m_pQueue );
}

CRetrievalThread::~CRetrievalThread()
{

}


//
// A user supplied implementation of the thread function.
// Override Run() and insert the code that should be executed when 
// the thread runs.
//用戶提供的線程函數的執行。
//重寫run（）中插入代碼，應執行時
//線程運行。
//
void CRetrievalThread::Run()
{
	m_pQueue->WaitOnElementAvailable();
}

//----------------------------End of the file -------------------------------