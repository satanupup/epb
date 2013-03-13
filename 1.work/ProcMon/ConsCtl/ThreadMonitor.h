//---------------------------------------------------------------------------
//
// ThreadMonitor.h
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
#if !defined(_THREADMONITOR_H_)
#define _THREADMONITOR_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//---------------------------------------------------------------------------
//
// Includes
//
//---------------------------------------------------------------------------
#include "CustomThread.h"
#include "QueueContainer.h"

//---------------------------------------------------------------------------
//
// Typedefs
//
//---------------------------------------------------------------------------

//
// Structure for process callback information
//
typedef struct _ProcessCallbackInfo
{
    HANDLE  hParentId;
    HANDLE  hProcessId;
    BOOLEAN bCreate;
} PROCESS_CALLBACK_INFO, *PPROCESS_CALLBACK_INFO;

//---------------------------------------------------------------------------
//
// Aplication scope consts and typedefs
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
// Forward declarations
//
//---------------------------------------------------------------------------
class CNtDriverController;
//---------------------------------------------------------------------------
//
// class CProcessThreadMonitor
//
//---------------------------------------------------------------------------
class CProcessThreadMonitor: public CCustomThread  
{
public:
	CProcessThreadMonitor(
		TCHAR*               pszThreadGuid,     // Thread unique ID
		CNtDriverController* pDriverController, // service controller
		CQueueContainer*     pRequestManager    // The underlying store
		);
	virtual ~CProcessThreadMonitor();
private:
	//
	// A pointer to an instance of the class responsible for 
	// loading and unloading the kernel driver
	//
	CNtDriverController* m_pDriverCtl;
protected:
	//
	// A user supplied implementation of the thread function.
	// Override Run() and insert the code that should be executed when 
	// the thread runs.
	//
	virtual void Run();
	//
	// Perform action prior to activate the thread  
	//
	virtual BOOL OnBeforeActivate();
	//
	// Called after the thread function exits
	//
	virtual void OnAfterDeactivate();
	//
	// Attach to kernel mode created event handle
	//
	BOOL OpenKernelModeEvent();
	//
	// Retrieve data from the kernel mode driver.
	//
	void RetrieveFromKernelDriver();
	//
	// The underlying store wrapped up by the custom template
	//
	CQueueContainer* m_pRequestManager;
	//
	// Kernel mode created event
	//
	HANDLE m_hKernelEvent;
	//
	// A handle for accessing the kernel driver
	//
	HANDLE m_hDriverFile;
	//
	// Keep the state of the last received event
	//
	PROCESS_CALLBACK_INFO  m_LastCallbackInfo;
};

#endif // !defined(_THREADMONITOR_H_)
//----------------------------End of the file -------------------------------