//---------------------------------------------------------------------------
//
// ApplicationScope.cpp
//
// SUBSYSTEM:   
//              Monitoring process creation and termination  
//				
// MODULE:      
//              Main interface of the user-mode app
//             
// DESCRIPTION: 
//              A class that wraps up different implementations and provide 
//              single interface
// 				
// AUTHOR:		Ivo Ivanov
//
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//
// Includes
//
//---------------------------------------------------------------------------
#include "ApplicationScope.h"
#include "NtDriverController.h"
#include "ThreadMonitor.h"
#include "WinUtils.h"
#include "ThreadMonitor.h"
#include "QueueContainer.h"

//---------------------------------------------------------------------------
//
// class CApplicationScope 
//
//---------------------------------------------------------------------------

//
// Structure for holding info about activating/deactivating the driver
//
typedef struct _ActivateInfo
{
    BOOLEAN  bActivate;
} ACTIVATE_INFO, *PACTIVATE_INFO;


//---------------------------------------------------------------------------
//
// Static memeber declarations
//
//---------------------------------------------------------------------------
CApplicationScope* CApplicationScope::sm_pInstance = NULL;

//---------------------------------------------------------------------------
//
// Constructor
//
//---------------------------------------------------------------------------
CApplicationScope::CApplicationScope(
	CCallbackHandler* pHandler       // User-supplied object for handling notifications
	):
	m_pDriverCtl(NULL),
	m_bIsActive(FALSE),
	m_pProcessMonitor(NULL),
	m_pRequestManager(NULL)
{
	m_pRequestManager = new CQueueContainer(pHandler);	
	//
	// An instance of the class responsible for loading and unloading
	// the kernel driver
	//
	m_pDriverCtl = new CNtDriverController();
}

//---------------------------------------------------------------------------
//
// Destructor 
//
//---------------------------------------------------------------------------
CApplicationScope::~CApplicationScope()
{
	StopMonitoring();
	if (m_bIsActive)
		m_pDriverCtl->StopAndRemove();
	delete m_pDriverCtl;
	delete m_pRequestManager;
}

//---------------------------------------------------------------------------
//
// Copy constructor
//
//---------------------------------------------------------------------------
CApplicationScope::CApplicationScope(const CApplicationScope& rhs)
{

}

//---------------------------------------------------------------------------
//
// Assignment operator
//
//---------------------------------------------------------------------------
CApplicationScope& CApplicationScope::operator=(const CApplicationScope& rhs)
{
	if (this == &rhs) 
		return *this;

	return *this; // return reference to left-hand object
}



//---------------------------------------------------------------------------
// GetInstance
//
// Implements the "double-checking" locking pattern combined with 
// Scott Meyers single instance
// For more details see - 
// 1. "Modern C++ Design" by Andrei Alexandrescu - 6.9 Living in a 
//     Multithreaded World
// 2. "More Effective C++" by Scott Meyers - Item 26
//---------------------------------------------------------------------------
CApplicationScope& CApplicationScope::GetInstance(
	CCallbackHandler* pHandler       // User-supplied object for handling notifications
	) 
{
	VerifyIsWindowsNtRequired();
	if (!sm_pInstance)
	{
		CLockMgr<CCSWrapper> guard(g_AppSingeltonLock, TRUE);
		if (!sm_pInstance)
		{
			assert( NULL != pHandler );
			static CApplicationScope instance(pHandler);
			sm_pInstance = &instance;
		}
	} // if

	return *sm_pInstance;
}

//
// Activate/deactivate the monitoring process
//
BOOL CApplicationScope::SetActive(BOOL bActive)
{
	BOOL bResult     = FALSE;
	//
	// Verify the system hasn't been activate before
	//
	if (m_bIsActive != bActive)
	{
		BOOL           bReturnCode = FALSE;
		ACTIVATE_INFO  activateInfo;
		HANDLE         hDriverFile;
		DWORD          dwBytesReturned = 0;     // byte count

		if (bActive)
		{
			if (!m_pRequestManager->StartReceivingNotifications())
				return FALSE;
		}
		else
			m_pRequestManager->StopReceivingNotifications();
		//
		// Try opening the device driver
		//
		hDriverFile = ::CreateFile(
			TEXT("\\\\.\\ProcObsrv"),
			GENERIC_READ | GENERIC_WRITE, 
			FILE_SHARE_READ | FILE_SHARE_WRITE,
			0,                     // Default security
			OPEN_EXISTING,
			0,                     // Perform synchronous I/O
			0);                    // No template
 		if (INVALID_HANDLE_VALUE == hDriverFile)
			return FALSE;
		//
		// and if the driver can be opened activate the monitoring
		// thread
		//
		if (NULL == m_pProcessMonitor)
		{
			m_pProcessMonitor = new CProcessThreadMonitor(
				TEXT("{30F8934F-F57F-4ced-93A6-AF68CD0F6E79}"), 
				m_pDriverCtl,
				m_pRequestManager
				);
			m_pProcessMonitor->SetActive( TRUE );
		}
		else
		{
			//
			// Stop and release the monitoring thread
			//
			delete m_pProcessMonitor;
			m_pProcessMonitor = NULL;
		}
		//
		// Inform the driver only when it has to be activated or
		// deactivated 
		//
		if (bActive)
		{
			//
			// Set input parameters for the driver routine
			//
			activateInfo.bActivate = bActive;
			//
			// Activate/Deactivate the process
			//
			bReturnCode = ::DeviceIoControl(
				hDriverFile,
				IOCTL_PROCOBSRV_ACTIVATE_MONITORING,
				&activateInfo, 
				sizeof(activateInfo),
				NULL, 
				0,
				&dwBytesReturned,
				NULL
				);
		} // if
		m_bIsActive = bActive;
		bResult   = TRUE;
		if (INVALID_HANDLE_VALUE != hDriverFile)
			::CloseHandle(hDriverFile);
	} // if
	return bResult;
}

//
// Initiates process of monitoring process creation/termination
//
BOOL CApplicationScope::StartMonitoring(
	PVOID pvParam        // Pointer to a parameter value passed to the object 
	)
{
	CLockMgr<CCSWrapper> guard(m_Lock, TRUE);
	BOOL bResult = FALSE;
	//
	// Verify the system hasn't been activate before
	//
	if (!m_bIsActive)
	{
		m_pRequestManager->SetExternalParam( pvParam );
		//
		// Activate the monitoring process
		//
		bResult = SetActive( TRUE ); 
	} // if
	
	return bResult;
}

//
// Ends up the whole process of monitoring
//
void CApplicationScope::StopMonitoring()
{
	CLockMgr<CCSWrapper> guard(m_Lock, TRUE);
	//
	// Deactivate the monitoring process
	//
	SetActive( FALSE );
	return;
}

//----------------------------End of the file -------------------------------
//---------------------------------------------------------------------------
//
// CallbackHandler.cpp
//
// SUBSYSTEM:   
//              Monitoring process creation and termination  
//				
// MODULE:      
//              An abstract interface for receiving notification when a 
//              process has been created or terminated  
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
#include "CallbackHandler.h"

//---------------------------------------------------------------------------
//
// class CCallbackHandler
//
//---------------------------------------------------------------------------
CCallbackHandler::CCallbackHandler():
	m_hModPsapi(NULL),
	m_pfnEnumProcessModules(NULL),
	m_pfnGetModuleFileNameEx(NULL)
{
    //
    // Get to the function in PSAPI.DLL dynamically.  We can't
    // be sure that PSAPI.DLL has been installed
    //
    if (NULL == m_hModPsapi)
        m_hModPsapi = ::LoadLibrary(TEXT("PSAPI.DLL"));
    if (NULL != m_hModPsapi)
	{
		m_pfnEnumProcessModules = reinterpret_cast<PFNENUMPROCESSMODULES>
			( ::GetProcAddress(m_hModPsapi, "EnumProcessModules") );
#ifdef _UNICODE
		CHAR szFuncName[] = "GetModuleFileNameExW";
#else
		CHAR szFuncName[] = "GetModuleFileNameExA";
#endif
		m_pfnGetModuleFileNameEx = reinterpret_cast<PFNGETMODULEFILENAMEEX>
			( ::GetProcAddress(m_hModPsapi, szFuncName) );
	} // if
}

CCallbackHandler::~CCallbackHandler()
{
	if (NULL != m_hModPsapi)
		::FreeLibrary(m_hModPsapi);
}

//
// Return the name of the process by its ID using PSAPI
//
BOOL CCallbackHandler::GetProcessName(
	DWORD  dwProcessId,
	LPTSTR lpFileName, 
	DWORD  dwLen
	)
{
	BOOL bResult = FALSE;
	if (!::IsBadStringPtr(lpFileName, dwLen))
	{
		::ZeroMemory(
			reinterpret_cast<PBYTE>(lpFileName),
			dwLen * sizeof(TCHAR)
			);
		if ((NULL != m_pfnEnumProcessModules) && 
			(NULL != m_pfnGetModuleFileNameEx))
		{
			// Let's open the process
			HANDLE hProcess = ::OpenProcess(
				PROCESS_QUERY_INFORMATION |	PROCESS_VM_READ,
				FALSE, 
				dwProcessId
				);
			if (NULL != hProcess)
			{
				HMODULE hModuleArray[1024];
				DWORD   cbNeeded;
				DWORD   nModules;
				// EnumProcessModules function retrieves a handle for 
				// each module in the specified process. 
				if (m_pfnEnumProcessModules(
						hProcess, 
						hModuleArray,
						sizeof(hModuleArray), 
						&cbNeeded))
				{
					// Calculate number of modules in the process                                   
					nModules = cbNeeded / sizeof(hModuleArray[0]);
					if (nModules > 0)
					{
						// First module is the EXE.  
						HMODULE hModule = hModuleArray[0];
						DWORD dwCharRead = m_pfnGetModuleFileNameEx(
							hProcess, 
							hModule,
							lpFileName, 
							dwLen
							);
					} // if
				} // if
				::CloseHandle(hProcess);
			} // if
		} // if
	} // if
	return bResult;
}

//--------------------- End of the file -------------------------------------
//---------------------------------------------------------------------------
//
// ConsCtl.cpp
//
// SUBSYSTEM: 
//              Monitoring process creation and termination  
//
// MODULE:    
//				Control application for monitoring NT process and 
//              DLLs loading observation. 
//
// DESCRIPTION:
//
// AUTHOR:		Ivo Ivanov
//                                                                         
//---------------------------------------------------------------------------

#include "Common.h"
#include <conio.h>
#include <tchar.h>
#include "ApplicationScope.h"
#include "CallbackHandler.h"

//
// This constant is declared only for testing putposes and
// determines how many process will be created to stress test
// the system
//
const int MAX_TEST_PROCESSES = 10;
//---------------------------------------------------------------------------
// 
// class CWhatheverYouWantToHold
//
// Implements a dummy class that can be used inside provide callback 
// mechanism. For example this class can manage sophisticated methods and 
// handles to a GUI Win32 Window. 
//
//---------------------------------------------------------------------------
class CWhatheverYouWantToHold
{
public:
	CWhatheverYouWantToHold()
	{
		_tcscpy(m_szName, TEXT("This could be any user-supplied data."));
		hwnd = NULL;
	}
private:
	TCHAR  m_szName[MAX_PATH];
	// 
	// You might want to use this attribute to store a 
	// handle to Win32 GUI Window
	//
	HANDLE hwnd;
};


//---------------------------------------------------------------------------
// 
// class CMyCallbackHandler
//
// Implements an interface for receiving notifications
//
//---------------------------------------------------------------------------
class CMyCallbackHandler: public CCallbackHandler
{
	//
	// Implements an event method
	//
	virtual void OnProcessEvent(
		PQUEUED_ITEM pQueuedItem, 
		PVOID        pvParam
		)
	{
		TCHAR szFileName[MAX_PATH];
		//
		// Deliberately I decided to put a delay in order to 
		// demonstrate the queuing / multithreaded functionality 
		//
		::Sleep(500);
		//
		// Get the dummy parameter we passsed when we 
		// initiated process of monitoring (i.e. StartMonitoring() )
		//
		CWhatheverYouWantToHold* pParam = static_cast<CWhatheverYouWantToHold*>(pvParam);
		//
		// And it's about time to handle the notification itself
		//
		if (NULL != pQueuedItem)
		{
			TCHAR szBuffer[1024];
			::ZeroMemory(
				reinterpret_cast<PBYTE>(szBuffer),
				sizeof(szBuffer)
				);
			GetProcessName(
				reinterpret_cast<DWORD>(pQueuedItem->hProcessId), 
				szFileName, 
				MAX_PATH
				);
			if (pQueuedItem->bCreate)
				//
				// At this point you can use OpenProcess() and
				// do something with the process itself
				//
				wsprintf(
					szBuffer,
					TEXT("Process has been created: PID=0x%.8X %s\n"),
					pQueuedItem->hProcessId,
					szFileName
					);
			else
				wsprintf(
					szBuffer,
					TEXT("Process has been terminated: PID=0x%.8X\n"),
					pQueuedItem->hProcessId);
			//
			// Output to the console screen
			//
			_tprintf(szBuffer);
		} // if
	}
};

//---------------------------------------------------------------------------
// Perform
//
// Thin wrapper around __try..__finally
//---------------------------------------------------------------------------
void Perform(
	CCallbackHandler*        pHandler,
	CWhatheverYouWantToHold* pParamObject
	)
{
	DWORD processArr[MAX_TEST_PROCESSES] = {0};
	int i;
	STARTUPINFO si = { sizeof(si) };
	PROCESS_INFORMATION pi;
	TCHAR szBuffer[MAX_PATH];  // buffer for Windows directory
	::GetWindowsDirectory(szBuffer, MAX_PATH);
	_tcscat(szBuffer, TEXT("\\notepad.exe"));

	//
	// Create the only instance of this object
	//
	CApplicationScope& g_AppScope = CApplicationScope::GetInstance(
		pHandler     // User-supplied object for handling notifications
		);
	__try
	{
		//
		// Initiate monitoring
		//
		g_AppScope.StartMonitoring(
			pParamObject // Pointer to a parameter value passed to the object 
			);
		for (i = 0; i < MAX_TEST_PROCESSES; i++)
		{
			// Spawn Notepad's instances
			if ( ::CreateProcess(NULL, szBuffer, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) 
			{
				::WaitForInputIdle(pi.hProcess, 1000);
				processArr[i] = pi.dwProcessId;
				::CloseHandle(pi.hThread);
				::CloseHandle(pi.hProcess);
			} // if
		} // for
		::Sleep(5000);
		for (i = 0; i < MAX_TEST_PROCESSES; i++)
		{
			HANDLE hProcess = ::OpenProcess(
				PROCESS_ALL_ACCESS, 
				FALSE,
				processArr[i]
				);
			if (NULL != hProcess)
			{
				__try
				{
					// Close Notepad's instances
					::TerminateProcess(hProcess, 0);
				}
				__finally
				{
					::CloseHandle(hProcess);
				}
			} // if
			::Sleep(10);
		} // for
	
		while(!kbhit())
		{
		}
		_getch();
	}
	__finally
	{
		//
		// Terminate the process of observing processes
		//
		g_AppScope.StopMonitoring();
	}
}

//---------------------------------------------------------------------------
// 
// Entry point
//
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
	CMyCallbackHandler      myHandler;
	CWhatheverYouWantToHold myView; 

	Perform( &myHandler, &myView );

	return 0;
}
//--------------------- End of the file -------------------------------------
//---------------------------------------------------------------------------
//
// CustomThread.cpp
//
// SUBSYSTEM: 
//              Monitoring process creation and termination  
// MODULE:    
//              Thread management 
//
// DESCRIPTION:
//              This is an abstract class that enables creation of separate 
//              threads of execution in an application. 
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
//                                                                         
//---------------------------------------------------------------------------

HANDLE CCustomThread::sm_hThread = NULL;

CCustomThread::CCustomThread(TCHAR* pszThreadGuid):
	m_hShutdownEvent(NULL),
	m_bThreadActive(NULL),
	m_dwThreadId(NULL)
{
	if (NULL != pszThreadGuid)
		_tcscpy(m_szThreadGuid, pszThreadGuid);
	else
		_tcscpy(m_szThreadGuid, TEXT(""));
}

CCustomThread::~CCustomThread()
{	
	SetActive( FALSE );
}

//
// Activate / Stop the thread 
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
					//
					::SetEvent(m_hShutdownEvent);
				//
				// Wait until the thread is done
				//
				while (GetIsActive())
				{
				}
				//
				// Called after the thread function exits
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
//
BOOL CCustomThread::GetIsActive()
{
	CLockMgr<CCSWrapper> lockMgr(m_CritSec, TRUE);	
	return m_bThreadActive;
}

//
// Setup the attribute
//
void CCustomThread::SetIsActive(BOOL bValue)
{
	CLockMgr<CCSWrapper> lockMgr(m_CritSec, TRUE);	
	m_bThreadActive = bValue;
}


//
// Return the handle to the thread's shut down event
//
HANDLE CCustomThread::Get_ShutdownEvent() const
{
	return m_hShutdownEvent;
}

//
// Primary thread entry point
//
unsigned __stdcall CCustomThread::ThreadFunc(void* pvParam)
{
	CCustomThread* pMe = (CCustomThread*)( pvParam );
	// retrieves a pseudo handle for the current thread
	sm_hThread = GetCurrentThread();
	try
	{
		pMe->SetIsActive( TRUE );
		// Execute the user supplied method
		pMe->Run();
	}
	catch (...)
	{
		// Handle all exceptions
	}
	pMe->SetIsActive( FALSE );
	_endthreadex(0);
	return 0;
}


//
// Perform action prior to activate the thread
//
BOOL CCustomThread::OnBeforeActivate()
{
	// Provide default implementation
	return TRUE;
}

//
// Called after the thread function exits
//
void CCustomThread::OnAfterDeactivate()
{
	// Do nothing
}

//----------------------------End of the file -------------------------------//---------------------------------------------------------------------------
//
// LockMgr.cpp
//
// SUBSYSTEM: 
//				Generic libraries
// MODULE:    
//              Interface declaration of CCSWrapper CRITICAL_SECTION wrapper 
//
// DESCRIPTION:
//              
//
// AUTHOR:		Ivo Ivanov
//                                                                         
//---------------------------------------------------------------------------
#include "LockMgr.h"

//---------------------------------------------------------------------------
//
// class CCSWrapper 
//
// CRTICIAL_SECTION user object wrapper
//
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//
// Constructor
//
//---------------------------------------------------------------------------
CCSWrapper::CCSWrapper()
{
	m_nSpinCount = 0;
	::InitializeCriticalSection( &m_cs );
}

//---------------------------------------------------------------------------
//
// Destructor
//
//---------------------------------------------------------------------------
CCSWrapper::~CCSWrapper()
{
	::DeleteCriticalSection( &m_cs );
}


//---------------------------------------------------------------------------
// Enter 
//
// This function waits for ownership of the specified critical section object 
//---------------------------------------------------------------------------
void CCSWrapper::Enter()
{
	::EnterCriticalSection( &m_cs );
	m_nSpinCount++;
}

//---------------------------------------------------------------------------
// Leave
//
// Releases ownership of the specified critical section object. 
//---------------------------------------------------------------------------
void CCSWrapper::Leave()
{
	m_nSpinCount--;
	::LeaveCriticalSection( &m_cs );
}

//--------------------- End of the file -------------------------------------
//---------------------------------------------------------------------------
//
// NtDriverController.cpp
//
// SUBSYSTEM: 
//              Monitoring process creation and termination  
//				
// MODULE:    
//				Provides simple interface for managing device driver 
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
		_tcscpy(m_szName, TEXT("ProcObsrv"));
		_tcscpy(m_szInfo, TEXT("Process creation detector."));
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
		while (1)
		{
			// Get current state of driver
			bResult = ::QueryServiceStatus(m_hDriver, pss);
			// If we can't query the driver, we're done
			if (!bResult) 
				break;
			// If the driver reaches the desired state
			if (pss->dwCurrentState == dwDesiredState) 
				break;
			// We're not done, wait the specified period of time
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
			if (!bResult)
			{
				// Mark the service for deletion.
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
//
void CNtDriverController::StopAndRemove()
{
	if ((NULL != m_hDriver) && (!m_bErrorOnStart))
	{
		BOOL bResult;
		SERVICE_STATUS serviceStatus = { 0 };
		// Notifies a service that it should stop. 
		bResult = ::ControlService(m_hDriver, SERVICE_CONTROL_STOP, &serviceStatus);
		if (bResult)
			bResult = WaitForState(SERVICE_STOPPED, &serviceStatus);	
		// Mark the service for deletion.
		::DeleteService(m_hDriver);
	} // if
}

//----------------------------End of the file -------------------------------//---------------------------------------------------------------------------
//
// ProcObsrv.c
//
// SUBSYSTEM: 
//				System monitor
// MODULE:    
//				Driver for monitoring NT process and DLLs mapping
//              monitoring. 
//
// DESCRIPTION:
//              This code is based on the James Finnegan’s sample 
//              (MSJ January 1999).
//
// Ivo Ivanov, January 2002
//                                                                         
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//
// Includes
//  
//---------------------------------------------------------------------------
#include <ntddk.h>

//---------------------------------------------------------------------------
//
// Defines
//  
//---------------------------------------------------------------------------

#define FILE_DEVICE_UNKNOWN             0x00000022
#define IOCTL_UNKNOWN_BASE              FILE_DEVICE_UNKNOWN
#define IOCTL_PROCOBSRV_ACTIVATE_MONITORING    \
	CTL_CODE(IOCTL_UNKNOWN_BASE, 0x0800, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_PROCOBSRV_GET_PROCINFO    \
	CTL_CODE(IOCTL_UNKNOWN_BASE, 0x0801, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
//---------------------------------------------------------------------------
//
// Forward declaration
//  
//---------------------------------------------------------------------------
void UnloadDriver(
	PDRIVER_OBJECT DriverObject
	);
NTSTATUS DispatchCreateClose(
	IN PDEVICE_OBJECT DeviceObject, 
	IN PIRP Irp
	);
NTSTATUS DispatchIoctl(
	IN PDEVICE_OBJECT DeviceObject, 
	IN PIRP Irp
	);
//
// Process function callback
//  
VOID ProcessCallback(
	IN HANDLE  hParentId, 
	IN HANDLE  hProcessId, 
	IN BOOLEAN bCreate
	);
//
// Structure for holding info about activating/deactivating the driver
//
typedef struct _ActivateInfo
{
    BOOLEAN  bActivated;
} ACTIVATE_INFO, *PACTIVATE_INFO;

//
// Structure for process callback information
//
typedef struct _ProcessCallbackInfo
{
    HANDLE  hParentId;
    HANDLE  hProcessId;
    BOOLEAN bCreate;
} PROCESS_CALLBACK_INFO, *PPROCESS_CALLBACK_INFO;

//
// Private storage for process retreiving 
//
typedef struct _DEVICE_EXTENSION 
{
    PDEVICE_OBJECT DeviceObject;
	//
	// Shared section
	//
    HANDLE  hProcessId;
	//
	// Process section data
	//
    PKEVENT ProcessEvent;
    HANDLE  hParentId;
    BOOLEAN bCreate;
} DEVICE_EXTENSION, *PDEVICE_EXTENSION;

//
// Global variables
//
PDEVICE_OBJECT g_pDeviceObject;
ACTIVATE_INFO  g_ActivateInfo;

//
// The main entry point of the driver module
//
NTSTATUS DriverEntry(
	IN PDRIVER_OBJECT DriverObject, 
	IN PUNICODE_STRING RegistryPath
	)
{
    NTSTATUS                  ntStatus;
    UNICODE_STRING            uszDriverString;
    UNICODE_STRING            uszDeviceString;
    UNICODE_STRING            uszProcessEventString;
    PDEVICE_OBJECT            pDeviceObject;
    PDEVICE_EXTENSION         extension;
	HANDLE                    hProcessHandle;

	//    
	// Point uszDriverString at the driver name
	//
    RtlInitUnicodeString(&uszDriverString, L"\\Device\\ProcObsrv");
	//
    // Create and initialize device object
	//
    ntStatus = IoCreateDevice(
		DriverObject,
        sizeof(DEVICE_EXTENSION),
        &uszDriverString,
        FILE_DEVICE_UNKNOWN,
        0,
        FALSE,
        &pDeviceObject
		);
    if(ntStatus != STATUS_SUCCESS)
        return ntStatus;
    //
	// Assign extension variable
	//
    extension = pDeviceObject->DeviceExtension;
    //
	// Point uszDeviceString at the device name
	//
    RtlInitUnicodeString(&uszDeviceString, L"\\DosDevices\\ProcObsrv");
    //
	// Create symbolic link to the user-visible name
	//
    ntStatus = IoCreateSymbolicLink(&uszDeviceString, &uszDriverString);

    if(ntStatus != STATUS_SUCCESS)
    {
		//
        // Delete device object if not successful
		//
        IoDeleteDevice(pDeviceObject);
        return ntStatus;
    }
	//
    // Assign global pointer to the device object for use by the callback functions
	//
    g_pDeviceObject = pDeviceObject;
	//
	// Setup initial state
	//
	g_ActivateInfo.bActivated = FALSE;
	//
    // Load structure to point to IRP handlers
	//
    DriverObject->DriverUnload                         = UnloadDriver;
    DriverObject->MajorFunction[IRP_MJ_CREATE]         = DispatchCreateClose;
    DriverObject->MajorFunction[IRP_MJ_CLOSE]          = DispatchCreateClose;
    DriverObject->MajorFunction[IRP_MJ_DEVICE_CONTROL] = DispatchIoctl;
	//
    // Create event for user-mode processes to monitor
	//
    RtlInitUnicodeString(
		&uszProcessEventString, 
		L"\\BaseNamedObjects\\ProcObsrvProcessEvent"
		);
    extension->ProcessEvent = IoCreateNotificationEvent(
		&uszProcessEventString, 
		&hProcessHandle
		);
	//
    // Clear it out
	//
    KeClearEvent(extension->ProcessEvent);
	//
    // Return success
	//
    return ntStatus;
}

//
// Create and close routine
//
NTSTATUS DispatchCreateClose(IN PDEVICE_OBJECT DeviceObject, IN PIRP Irp)
{
    Irp->IoStatus.Status      = STATUS_SUCCESS;
    Irp->IoStatus.Information = 0;
    IoCompleteRequest(Irp, IO_NO_INCREMENT);
    return STATUS_SUCCESS;
}

//
// Process function callback
//
VOID ProcessCallback(
	IN HANDLE  hParentId, 
	IN HANDLE  hProcessId, 
	IN BOOLEAN bCreate
	)
{
	PDEVICE_EXTENSION extension;
	//
    // Assign extension variable
	//
	extension = g_pDeviceObject->DeviceExtension;
	//
    // Assign current values into device extension.  
	// User-mode apps will pick it up using DeviceIoControl calls.
	//
    extension->hParentId  = hParentId;
    extension->hProcessId = hProcessId;
    extension->bCreate    = bCreate;
	//
    // Signal the event thus the user-mode apps listening will be aware
    // that something interesting has happened.  
	//
    KeSetEvent(extension->ProcessEvent, 0, FALSE);
    KeClearEvent(extension->ProcessEvent);
}

//
// IOCTL handler for setting the callback
//
NTSTATUS ActivateMonitoringHanlder(
	IN PIRP           Irp
	)
{
	NTSTATUS               ntStatus = STATUS_UNSUCCESSFUL;
	PIO_STACK_LOCATION     irpStack  = IoGetCurrentIrpStackLocation(Irp);
	PACTIVATE_INFO         pActivateInfo;
	
	if (irpStack->Parameters.DeviceIoControl.InputBufferLength >= 
	   sizeof(ACTIVATE_INFO))		
	{
		pActivateInfo = Irp->AssociatedIrp.SystemBuffer;
		if (g_ActivateInfo.bActivated != pActivateInfo->bActivated)
		{
			if (pActivateInfo->bActivated) 
			{
				//
				// Set up callback routines
				//
				ntStatus = PsSetCreateProcessNotifyRoutine(ProcessCallback, FALSE);
				if (ntStatus != STATUS_SUCCESS)
				{
					return ntStatus;
				}
				//
				// Setup the global data structure
				//
				g_ActivateInfo.bActivated = pActivateInfo->bActivated; 
			} // if
			else
			{
				//
				// restore the call back routine, thus givinig chance to the 
				// user mode application to unload dynamically the driver
				//
				ntStatus = PsSetCreateProcessNotifyRoutine(ProcessCallback, TRUE);
				if (ntStatus != STATUS_SUCCESS)
					return ntStatus;
				else
					g_ActivateInfo.bActivated = FALSE;
			}
			ntStatus = STATUS_SUCCESS;
		} // if
	} // if

	return ntStatus;
}

//
// The dispatch routine
//
NTSTATUS DispatchIoctl(
	IN PDEVICE_OBJECT DeviceObject, 
	IN PIRP           Irp
	)
{
    NTSTATUS               ntStatus = STATUS_UNSUCCESSFUL;
    PIO_STACK_LOCATION     irpStack  = IoGetCurrentIrpStackLocation(Irp);
    PDEVICE_EXTENSION      extension = DeviceObject->DeviceExtension;
    PPROCESS_CALLBACK_INFO pProcCallbackInfo;
	//
    // These IOCTL handlers are the set and get interfaces between
    // the driver and the user mode app
	//
    switch(irpStack->Parameters.DeviceIoControl.IoControlCode)
    {
		case IOCTL_PROCOBSRV_ACTIVATE_MONITORING:
			{
				ntStatus = ActivateMonitoringHanlder( Irp );
				break;
			}
        case IOCTL_PROCOBSRV_GET_PROCINFO:
			{
				if (irpStack->Parameters.DeviceIoControl.OutputBufferLength >= 
				   sizeof(PROCESS_CALLBACK_INFO))
				{
					pProcCallbackInfo = Irp->AssociatedIrp.SystemBuffer;
					pProcCallbackInfo->hParentId  = extension->hParentId;
					pProcCallbackInfo->hProcessId = extension->hProcessId;
					pProcCallbackInfo->bCreate    = extension->bCreate;
    
					ntStatus = STATUS_SUCCESS;
				}
				break;
			}

        default:
            break;
    }

    Irp->IoStatus.Status = ntStatus;
	//
    // Set number of bytes to copy back to user-mode
	//
    if(ntStatus == STATUS_SUCCESS)
        Irp->IoStatus.Information = 
			irpStack->Parameters.DeviceIoControl.OutputBufferLength;
    else
        Irp->IoStatus.Information = 0;

    IoCompleteRequest(Irp, IO_NO_INCREMENT);
    return ntStatus;
}

//
// Driver unload routine
//
void UnloadDriver(
	IN PDRIVER_OBJECT DriverObject
	)
{
    UNICODE_STRING  uszDeviceString;
	//
	//  By default the I/O device is configured incorrectly or the 
	// configuration parameters to the driver are incorrect.
	//
	NTSTATUS        ntStatus = STATUS_DEVICE_CONFIGURATION_ERROR;

	if (g_ActivateInfo.bActivated)
		//
		// restore the call back routine, thus givinig chance to the 
		// user mode application to unload dynamically the driver
		//
		ntStatus = PsSetCreateProcessNotifyRoutine(ProcessCallback, TRUE);

	IoDeleteDevice(DriverObject->DeviceObject);

	RtlInitUnicodeString(&uszDeviceString, L"\\DosDevices\\ProcObsrv");
	IoDeleteSymbolicLink(&uszDeviceString);
}

//----------------------------End of the file -------------------------------//---------------------------------------------------------------------------
//
// QueueContainer.cpp
//
// SUBSYSTEM: 
//              Monitoring process creation and termination  
//				
// MODULE:    
//              Implement a multithreaded thread safe queue
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
			&handles[0],                        // object-handle array
			FALSE,                              // wait option
			INFINITE                            // time-out interval
			);
		//
		// the system shuts down
		//
		if (handles[dwResult - WAIT_OBJECT_0] == m_evtShutdownRemove)
			break;
		//
		// An element just became available in the queue
		//
		else
		{
			DoOnProcessCreatedTerminated();
		}
	} // while
}

//
// A method for accessing handle to an internal event handle
//
HANDLE CQueueContainer::Get_ElementAvailableHandle() const
{
	return m_evtElementAvailable;
}

//
// Initates the process of handling notification in the queue
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
//
void CQueueContainer::StopReceivingNotifications()
{
	if (m_pRetrievalThread->GetIsActive())
		::SetEvent(m_evtShutdownRemove);
}

//
// Initialize the system
//
void CQueueContainer::Init()
{
	//
	// Create the monitoring mutex
	//
	m_mtxMonitor = ::CreateMutex(NULL, FALSE, NULL);
	assert(NULL != m_mtxMonitor);	//
	// Create the "remove" event
	//
	m_evtElementAvailable = ::CreateEvent(NULL, FALSE, FALSE, NULL);
	assert(NULL != m_evtElementAvailable);
	//
	// Create an event for shutting down the remove operation
	//
	m_evtShutdownRemove = ::CreateEvent(NULL, FALSE, FALSE, NULL);
	assert(NULL != m_evtShutdownRemove);
	//
	// Create a thread for picking up posted in the queue item notifications
	//
	m_pRetrievalThread = new CRetrievalThread(
		TEXT("{4EA19E49-1E3F-48da-AE16-2F2FD6A11F59}"),
		this
		);
}

//
// Release all allocated resources
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
		//
		m_Queue.push_back(element);
		//
		// Notify the waiting thread that there is 
		// available element in the queue for processing 
		//
		::SetEvent(m_evtElementAvailable);
	}//
	::ReleaseMutex(m_mtxMonitor);
	return bResult;
}

//
// Implement specific behavior when kernel mode driver notifies 
// the user-mode app
//
void CQueueContainer::DoOnProcessCreatedTerminated()
{
	QUEUED_ITEM element;
	// Initially we have atleast one element for processing
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
			if (bRemoveFromQueue)
			{
				// Get the element from the queue
				element = m_Queue.front();	
				m_Queue.pop_front();
			} // if
			else
				//
				// Let's make sure that the event hasn't been 
				// left in signaled state if there are no items 
				// in the queue 
				//
				::ResetEvent(m_evtElementAvailable);
		} // if
		::ReleaseMutex(m_mtxMonitor);
		//
		// Process it only there is an element that has 
		// been picked up
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
//
void CQueueContainer::SetExternalParam(PVOID pvParam)
{
	m_pvParam = pvParam;
}

//
// Delegate this method to a call of CCallbackHandler 
//
void CQueueContainer::OnProcessEvent(PQUEUED_ITEM pQueuedItem)
{
	if (pQueuedItem->bCreate)
		::OutputDebugString(TEXT("Process created.\n")); 
	else
		::OutputDebugString(TEXT("Process terminated.\n")); 

	m_pHandler->OnProcessEvent(
			pQueuedItem,
			m_pvParam
			);
}

//----------------------------End of the file -------------------------------//---------------------------------------------------------------------------
//
// RetrievalThread.cpp
//
// SUBSYSTEM: 
//              Monitoring process creation and termination  
//				
// MODULE:    
//              Provides an interface for handling queued items
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
//
void CRetrievalThread::Run()
{
	m_pQueue->WaitOnElementAvailable();
}

//----------------------------End of the file -------------------------------//---------------------------------------------------------------------------
//
// ThreadMonitor.cpp
//
// SUBSYSTEM: 
//              Monitoring process creation and termination  
//				
// MODULE:    
//              Thread management
//
// DESCRIPTION:
//              Implement abstract interface provided by CCustomThread
//
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
			&handles[0],                        // object-handle array
			FALSE,                              // wait option
			INFINITE                            // time-out interval
			);
		//
		// the system shuts down
		//
		if (handles[dwResult - WAIT_OBJECT_0] == m_hShutdownEvent)
			break;
		//
		// The kernel event has been just signaled
		//
		else
			RetrieveFromKernelDriver();
	} // while
}

//
// Perform action prior to activate the thread
//
BOOL CProcessThreadMonitor::OnBeforeActivate()
{
	BOOL bResult = FALSE;
	//
	// Try opening the device driver
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
		//
		bResult = OpenKernelModeEvent();

	return bResult;
}

//
// Called after the thread function exits
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
//
BOOL CProcessThreadMonitor::OpenKernelModeEvent()
{
	m_hKernelEvent = ::OpenEvent(
		SYNCHRONIZE, FALSE, TEXT("ProcObsrvProcessEvent") );

	return (INVALID_HANDLE_VALUE != m_hKernelEvent);
}

//
// Retrieve data from the kernel mode driver.
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
	//
	ov.hEvent = ::CreateEvent(
		NULL,  // Default security
		TRUE,  // Manual reset
		FALSE, // non-signaled state
		NULL
		); 
	//
	// Get the process info
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
	//
	bReturnCode = ::GetOverlappedResult(
		m_hDriverFile, 
		&ov,
		&dwBytesReturned, 
		TRUE
		);
	//
	// Prevent duplicated events
	//
	if ( (m_LastCallbackInfo.bCreate != callbackInfo.bCreate) ||
	     (m_LastCallbackInfo.hParentId != callbackInfo.hParentId) ||
		 (m_LastCallbackInfo.hProcessId != callbackInfo.hProcessId) )
	{
		//
		// Setup the queued element
		//
		::ZeroMemory((PBYTE)&queuedItem, sizeof(queuedItem));
		queuedItem.hParentId = callbackInfo.hParentId;
		queuedItem.hProcessId = callbackInfo.hProcessId;
		queuedItem.bCreate = callbackInfo.bCreate;
		//
		// and add it to the queue
		//
		m_pRequestManager->Append(queuedItem);
		//
		// Hold last event
		//
		m_LastCallbackInfo = callbackInfo;
	} // if
	//
	//
	//
	::CloseHandle(ov.hEvent);
}

//----------------------------End of the file -------------------------------
