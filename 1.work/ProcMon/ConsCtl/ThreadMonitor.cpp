
//---------------------------------------------------------------------------
//
// ThreadMonitor.cpp
//
// SUBSYSTEM: 
//              Monitoring process creation and termination  
//監視進程創建和終止
//				
// MODULE:    
//              Thread management
//
// DESCRIPTION:
//              Implement abstract interface provided by CCustomThread
//
//實現抽象接口由CCustomThread提供
// AUTHOR:		Ivo Ivanov
//                                                                         
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//
// Includes
//
//---------------------------------------------------------------------------
#include "ThreadMonitor.h"
#include "NtDriverController.h"

//---------------------------------------------------------------------------
//
// class CThreadMonitor
//
//---------------------------------------------------------------------------
CProcessThreadMonitor::CProcessThreadMonitor(
	TCHAR*               pszThreadGuid,     // Thread unique ID
	CNtDriverController* pDriverController, // service controller
	CQueueContainer*     pRequestManager    // The underlying store
	):
	CCustomThread(pszThreadGuid),
	m_pRequestManager(pRequestManager),
	m_hKernelEvent(INVALID_HANDLE_VALUE),
	m_hDriverFile(INVALID_HANDLE_VALUE)
{
	assert(NULL != pDriverController);
	//
	// Store the pointe to the service controller, thus
	// we can use it later
//存儲足尖服務控制器，從而
//我們可以用它購買
	//
	m_pDriverCtl = pDriverController;

	::ZeroMemory((PBYTE)&m_LastCallbackInfo, sizeof(m_LastCallbackInfo));
}

CProcessThreadMonitor::~CProcessThreadMonitor()
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
void CProcessThreadMonitor::Run()
{
	HANDLE handles[2] = 
	{
		m_hShutdownEvent,
		m_hKernelEvent
	};

	while (TRUE)
	{
		DWORD dwResult = ::WaitForMultipleObjects(
			sizeof(handles)/sizeof(handles[0]), // number of handles in array
			&handles[0],                        // object-handle array數組中句柄數量
			FALSE,                              // wait option
			INFINITE                            // time-out interval超時時間間隔
			);
		//
		// the system shuts down
		//
		if (handles[dwResult - WAIT_OBJECT_0] == m_hShutdownEvent)
			break;
		//
		// The kernel event has been just signaled
//內核事件已信號
		//
		else
			RetrieveFromKernelDriver();
	} // while
}

//
// Perform action prior to activate the thread
//執行行動之前激活的線程
//
BOOL CProcessThreadMonitor::OnBeforeActivate()
{
	BOOL bResult = FALSE;
	//
	// Try opening the device driver
//嘗試打開設備驅動程序
	//
	m_hDriverFile = ::CreateFile(
		TEXT("\\\\.\\ProcObsrv"),
		GENERIC_READ | GENERIC_WRITE, 
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		0,                     // Default security
		OPEN_EXISTING,
		FILE_FLAG_OVERLAPPED,  // Perform asynchronous I/O
		0);                    // No template
	if (INVALID_HANDLE_VALUE != m_hDriverFile)
		//
		// Attach to kernel mode created event handle
//附加到內核模式下創建的事件句柄
		//
		bResult = OpenKernelModeEvent();

	return bResult;
}

//
// Called after the thread function exits
//線程函數退出後調用
//
void CProcessThreadMonitor::OnAfterDeactivate()
{
	if (INVALID_HANDLE_VALUE != m_hKernelEvent)
	{
		::CloseHandle(m_hKernelEvent);
		m_hKernelEvent = INVALID_HANDLE_VALUE;
	}
	if (INVALID_HANDLE_VALUE != m_hDriverFile)
	{
		::CloseHandle(m_hDriverFile);
		m_hDriverFile = INVALID_HANDLE_VALUE;
	}
}

//
// Attach to the particular kernel mode created event handle
//附加到特定的內核模式下創建的事件句柄
//
BOOL CProcessThreadMonitor::OpenKernelModeEvent()
{
	m_hKernelEvent = ::OpenEvent(
		SYNCHRONIZE, FALSE, TEXT("ProcObsrvProcessEvent") );

	return (INVALID_HANDLE_VALUE != m_hKernelEvent);
}

//
// Retrieve data from the kernel mode driver.
//檢索數據從內核模式驅動程序。
//
void CProcessThreadMonitor::RetrieveFromKernelDriver()
{
	OVERLAPPED  ov          = { 0 };
	BOOL        bReturnCode = FALSE;
	DWORD       dwBytesReturned;
	PROCESS_CALLBACK_INFO  callbackInfo;
	QUEUED_ITEM queuedItem;         
	//
    // Create an event handle for async notification from the driver
//從驅動器中創建一個異步通知事件句柄
	//
	ov.hEvent = ::CreateEvent(
		NULL,  // Default security默認的安全性;
		TRUE,  // Manual reset手動復位
		FALSE, // non-signaled state非信號狀態
		NULL
		); 
	//
	// Get the process info
//獲取進程信息
	//
	bReturnCode = ::DeviceIoControl(
		m_hDriverFile,
		IOCTL_PROCOBSRV_GET_PROCINFO,
		0, 
		0,
		&callbackInfo, sizeof(callbackInfo),
		&dwBytesReturned,
		&ov
		);
	//
	// Wait here for the event handle to be set, indicating
	// that the IOCTL processing is completed.
//等待事件句柄設置，說明
//的IOCTL處理完畢。
	//
	bReturnCode = ::GetOverlappedResult(
		m_hDriverFile, 
		&ov,
		&dwBytesReturned, 
		TRUE
		);
	//
	// Prevent duplicated events
//防止重複事件
	//
	if ( (m_LastCallbackInfo.bCreate != callbackInfo.bCreate) ||
	     (m_LastCallbackInfo.hParentId != callbackInfo.hParentId) ||
		 (m_LastCallbackInfo.hProcessId != callbackInfo.hProcessId) )
	{
		//
		// Setup the queued element
//設置排隊元素
		//
		::ZeroMemory((PBYTE)&queuedItem, sizeof(queuedItem));
		queuedItem.hParentId = callbackInfo.hParentId;
		queuedItem.hProcessId = callbackInfo.hProcessId;
		queuedItem.bCreate = callbackInfo.bCreate;
		//
		// and add it to the queue
//並把它添加到隊列
		//
		m_pRequestManager->Append(queuedItem);
		//
		// Hold last event
//保持上屆展會
		//
		m_LastCallbackInfo = callbackInfo;
	} // if
	//
	//
	//
	if (ov.hEvent != NULL) 
		CloseHandle(ov.hEvent); 
		
}

//----------------------------End of the file -------------------------------

