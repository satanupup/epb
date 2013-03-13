
//---------------------------------------------------------------------------
//
// NtDriverController.cpp
//
// SUBSYSTEM: 
//              Monitoring process creation and termination  
//監視進程創建和終止
//				
// MODULE:    
//				Provides simple interface for managing device driver 
//提供簡單的界面管理設備驅動程序
//              administration
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
#include "Common.h" 
#include "NtDriverController.h"
#include <tchar.h>
#include "winutils.h"


//---------------------------------------------------------------------------
//
// class CNtDriverController
//
//---------------------------------------------------------------------------

CNtDriverController::CNtDriverController():
	m_hSCM(NULL),
	m_hDriver(NULL),
	m_bDriverStarted(FALSE),
	m_bErrorOnStart(FALSE)
{
	if (TRUE == Open())
	{
		wcscpy_s(m_szName, TEXT("ProcObsrv"));
		wcscpy_s(m_szInfo, TEXT("Process creation detector."));
		TCHAR szFullFileName[MAX_PATH];
		GetProcessHostFullName(szFullFileName);
		if ( TRUE == 
			 ReplaceFileName(
				szFullFileName, TEXT("ProcObsrv.sys"), m_szFullFileName) )
			m_bDriverStarted = InstallAndStart();
	} // if
}

CNtDriverController::~CNtDriverController()
{
	Close();
}


//
// Obtain manager handle
//
BOOL CNtDriverController::Open()
{
	m_hSCM = ::OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	return (m_hSCM != NULL);
}

//
// Close handle obtained from Open()
//
void CNtDriverController::Close()
{
	if (m_hDriver != NULL)
	{
		::CloseServiceHandle(m_hDriver);
		m_hDriver = NULL;
	}
	if (m_hSCM != NULL)
	{
		::CloseServiceHandle(m_hSCM);
		m_hSCM = NULL;
	} 
}

//
// Wait until driver reaches desired state or error occurs
//驅動程序等待，直到達到理想狀態或發生錯誤
//
BOOL CNtDriverController::WaitForState(
	DWORD           dwDesiredState, 
	SERVICE_STATUS* pss
	) 
{
	BOOL bResult = FALSE;
	if (NULL != m_hDriver)
	{
		// Loop until driver reaches desired state or error occurs
//循環驅動程序，直到達到理想狀態或發生錯誤
		while (1)
		{
			// Get current state of driver
//獲取驅動程序的當前狀態
			bResult = ::QueryServiceStatus(m_hDriver, pss);
			// If we can't query the driver, we're done
//如果我們不能查詢驅動程序，我們就大功告成了
			if (!bResult) 
				break;
			// If the driver reaches the desired state
//如果司機達到理想的狀態
			if (pss->dwCurrentState == dwDesiredState) 
				break;
			// We're not done, wait the specified period of time
//我們沒有這樣做，等待指定的時間內
			DWORD dwWaitHint = pss->dwWaitHint / 10;    // Poll 1/10 of the wait hint
			if (dwWaitHint <  1000) dwWaitHint = 1000;  // At most once a second
			if (dwWaitHint > 10000) dwWaitHint = 10000; // At least every 10 seconds
			::Sleep(dwWaitHint);
		} // while
	} // if

	return bResult;
}


//
// Add the driver to the system and start it up
//添加驅動系統，並啟動它
//
BOOL CNtDriverController::InstallAndStart()
{
	BOOL bResult = FALSE;

	if (NULL != m_hSCM)
	{
		m_hDriver = ::CreateService(
			m_hSCM, 
			m_szName, 
			m_szInfo,
			SERVICE_ALL_ACCESS,
			SERVICE_KERNEL_DRIVER,
			SERVICE_DEMAND_START,
			SERVICE_ERROR_NORMAL,
			m_szFullFileName, 
			NULL, 
			NULL,
			NULL, 
			NULL, 
			NULL
			);
		if (NULL == m_hDriver)
		{
			if ( (::GetLastError() == ERROR_SERVICE_EXISTS) ||
			     (::GetLastError() == ERROR_SERVICE_MARKED_FOR_DELETE) )
				m_hDriver = ::OpenService(
					m_hSCM,
					m_szName,
					SERVICE_ALL_ACCESS
					);
		}
		if (NULL != m_hDriver)
		{
			SERVICE_STATUS serviceStatus = { 0 };
			bResult = ::StartService(m_hDriver, 0, NULL);
 			if (bResult)
				bResult = WaitForState(SERVICE_RUNNING, &serviceStatus);	
			else
				bResult = (::GetLastError() == ERROR_SERVICE_ALREADY_RUNNING);
			// We should call DeleteService() if the SCM reports an error
			// on StartService(). Otherwise, the service will remain loaded
			// in an undesired state
//我們應該呼籲DeleteService（）如果SCM報告錯誤
//上的StartService（）。否則，該服務將繼續加載
//在一個不受歡迎的狀態
			if (!bResult)
			{
				// Mark the service for deletion.
//標記為刪除的服務。
				::DeleteService(m_hDriver);
				if (m_hDriver != NULL)
				{
					::CloseServiceHandle(m_hDriver);
					m_hDriver = NULL;
				}
				m_bErrorOnStart = TRUE;
			}
		} // if
	} // if

	return bResult;
}

//
// Stop the driver and remove it from the system
//停止驅動程序，並從系統中刪除
//
void CNtDriverController::StopAndRemove()
{
	if ((NULL != m_hDriver) && (!m_bErrorOnStart))
	{
		BOOL bResult;
		SERVICE_STATUS serviceStatus = { 0 };
		// Notifies a service that it should stop. 
//通知服務，它應該停止。
		bResult = ::ControlService(m_hDriver, SERVICE_CONTROL_STOP, &serviceStatus);
		if (bResult)
			bResult = WaitForState(SERVICE_STOPPED, &serviceStatus);	
		// Mark the service for deletion.
//標記為刪除的服務。
		::DeleteService(m_hDriver);
	} // if
}

//----------------------------End of the file -------------------------------