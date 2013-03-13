//---------------------------------------------------------------------------
//
// QueueContainer.cpp
//
// SUBSYSTEM: 
//              Monitoring process creation and termination  
//監視進程創建和終止
//				
// MODULE:    
//              Implement a multithreaded thread safe queue
//實現一個多線程的線程安全的隊列
// 
// DESCRIPTION:
//
// AUTHOR:		Ivo Ivanov
//                                                                         
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//
// Includes
//
//---------------------------------------------------------------------------

#include "common.h"
#include "QueueContainer.h"

//---------------------------------------------------------------------------
//
// class CQueueContainer
//
//---------------------------------------------------------------------------

//
// Queue's constructor
//
CQueueContainer::CQueueContainer(CCallbackHandler* pHandler):
	m_pHandler(pHandler)
{
	Init();
}

//
// Queue's destructor
//
CQueueContainer::~CQueueContainer()
{
	Done();
}

//
// Get data from the kernel mode driver
//獲取數據從內核模式驅動程序
//
void CQueueContainer::WaitOnElementAvailable()
{
	HANDLE handles[2] = 
	{
		m_evtShutdownRemove,
		m_evtElementAvailable
	};

	while (TRUE)
	{
		DWORD dwResult = ::WaitForMultipleObjects(
			sizeof(handles)/sizeof(handles[0]), // number of handles in array
			&handles[0],                        // object-handle array//數組中句柄數量
			FALSE,                              // wait option
			INFINITE                            // time-out interval超時時間間隔
			);
		//
		// the system shuts down關閉系統
		//
		if (handles[dwResult - WAIT_OBJECT_0] == m_evtShutdownRemove)
			break;
		//
		// An element just became available in the queue元素成為隊列中
		//
		else
		{
			DoOnProcessCreatedTerminated();
		}
	} // while
}

//
// A method for accessing handle to an internal event handle
//訪問內部的事件處理句柄的方法
//
HANDLE CQueueContainer::Get_ElementAvailableHandle() const
{
	return m_evtElementAvailable;
}

//
// Initates the process of handling notification in the queue
//處理通知的過程中，在隊列Initates
//
BOOL CQueueContainer::StartReceivingNotifications()
{
	BOOL bResult = FALSE;
	if (!m_pRetrievalThread->GetIsActive())
	{
		m_pRetrievalThread->SetActive( TRUE );
		bResult = m_pRetrievalThread->GetIsActive();
	}
	return bResult;
}

//
// Shutdown if there is something in progress
//關閉過程中，如果有東西
//
void CQueueContainer::StopReceivingNotifications()
{
	if (m_pRetrievalThread->GetIsActive())
		::SetEvent(m_evtShutdownRemove);
}

//
// Initialize the system
//初始化系統
//
void CQueueContainer::Init()
{
	//
	// Create the monitoring mutex
//創建監測互斥
	//
	m_mtxMonitor = ::CreateMutex(NULL, FALSE, NULL);
	assert(NULL != m_mtxMonitor);	//
	// Create the "remove" event
	//
	m_evtElementAvailable = ::CreateEvent(NULL, FALSE, FALSE, NULL);
	assert(NULL != m_evtElementAvailable);
	//
	// Create an event for shutting down the remove operation
//創建一個事件，對關停的刪除操作
	//
	m_evtShutdownRemove = ::CreateEvent(NULL, FALSE, FALSE, NULL);
	assert(NULL != m_evtShutdownRemove);
	//
	// Create a thread for picking up posted in the queue item notifications
//創建一個線程拿起張貼在隊列項目的通知
	//
	m_pRetrievalThread = new CRetrievalThread(
		TEXT("{4EA19E49-1E3F-48da-AE16-2F2FD6A11F59}"),
		this
		);
}

//
// Release all allocated resources
//釋放所有分配的資源
//
void CQueueContainer::Done()
{
	StopReceivingNotifications();
	delete m_pRetrievalThread;
	if (NULL != m_evtElementAvailable)
		::CloseHandle(m_evtElementAvailable);
	if (NULL != m_evtShutdownRemove)
		::CloseHandle(m_evtShutdownRemove);
	if (NULL != m_mtxMonitor)
		::CloseHandle(m_mtxMonitor);
}
	
//
// Insert data into the queue
//插入到隊列中的數據
//
BOOL CQueueContainer::Append(const QUEUED_ITEM& element)
{
	BOOL bResult = FALSE;
	DWORD dw = ::WaitForSingleObject(m_mtxMonitor, INFINITE);
	bResult = (WAIT_OBJECT_0 == dw);
	if (bResult)
	{
		//
		// Add it to the STL queue
//將它添加到STL的隊列
		//
		m_Queue.push_back(element);
		//
		// Notify the waiting thread that there is 
		// available element in the queue for processing 
//通知等待線程有
//可以在處理隊列中的元素
		//
		::SetEvent(m_evtElementAvailable);
	}//
	::ReleaseMutex(m_mtxMonitor);
	return bResult;
}

//
// Implement specific behavior when kernel mode driver notifies 
// the user-mode app
//實現特定的行為時，內核模式驅動程序通知
//用戶模式應用程序
//
void CQueueContainer::DoOnProcessCreatedTerminated()
{
	QUEUED_ITEM element;
	// Initially we have atleast one element for processing
//首先，我們必須處理atleast一個元素
	BOOL bRemoveFromQueue = TRUE;
	while (bRemoveFromQueue)
	{
		DWORD dwResult = ::WaitForSingleObject(
			m_mtxMonitor, INFINITE
			);
		if (WAIT_OBJECT_0 == dwResult)
		{
			bRemoveFromQueue = (m_Queue.size() > 0); 
			// Is there anything in the queue
//隊列中有什麼
			if (bRemoveFromQueue)
			{
				// Get the element from the queue
//從隊列中獲取元素
				element = m_Queue.front();	
				m_Queue.pop_front();
			} // if
			else
				//
				// Let's make sure that the event hasn't been 
				// left in signaled state if there are no items 
				// in the queue 
//讓我們確保該事件一直沒有
//留在信號的狀態，如果有任何項目
//隊列中
				//
				::ResetEvent(m_evtElementAvailable);
		} // if
		::ReleaseMutex(m_mtxMonitor);
		//
		// Process it only there is an element that has 
		// been picked up
//處理它只能有一個元素有
//被拾起
		//
		if (bRemoveFromQueue)	
			m_pHandler->OnProcessEvent( &element, m_pvParam );
		else
			break;
	} // while
}

//
// Set an external parameter, thus we could take the advantage 
// of it later on in the callback routine
//設置一個外部參數，因此我們可能採取的優勢
//它後來在回調例程
//
void CQueueContainer::SetExternalParam(PVOID pvParam)
{
	m_pvParam = pvParam;
}

//
// Delegate this method to a call of CCallbackHandler 
//此方法委託的通話CCallbackHandler
//
void CQueueContainer::OnProcessEvent(PQUEUED_ITEM pQueuedItem)
{
	if (pQueuedItem->bCreate )
		::OutputDebugString(TEXT("Process created.\n")); 
	else
		::OutputDebugString(TEXT("Process terminated.\n")); 

	m_pHandler->OnProcessEvent(
			pQueuedItem,
			m_pvParam
			);
}

//----------------------------End of the file -------------------------------