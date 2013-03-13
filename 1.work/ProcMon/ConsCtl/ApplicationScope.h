//---------------------------------------------------------------------------
//
// ApplicationScope.h
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

#if !defined(_APPLICATIONSCOPE_H_)
#define _APPLICATIONSCOPE_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//---------------------------------------------------------------------------
//
// Includes
// 
//---------------------------------------------------------------------------
#include "LockMgr.h"
#include "QueuedItem.h"
#include "ThreadMonitor.h"

//---------------------------------------------------------------------------
//
// Forward declarations
// 
//---------------------------------------------------------------------------
class CNtDriverController;
class CProcessThreadMonitor;

//---------------------------------------------------------------------------
//
// Global variables
// 
//---------------------------------------------------------------------------

//
// A global guard object used for protecting singelton's instantiation 
//
static CCSWrapper g_AppSingeltonLock;

//---------------------------------------------------------------------------
//
// class CApplicationScope 
//
//---------------------------------------------------------------------------
class CApplicationScope  
{
private:
	//
	// Note: Intentionally hide the defualt constructor,
	// copy constructor and assignment operator 
	//

	//
	// Default constructor
	//
	CApplicationScope(
		CCallbackHandler* pHandler       // User-supplied object for handling notifications
		);
	//
	// Copy constructor
	//
	CApplicationScope(const CApplicationScope& rhs);
	//
	// Assignment operator
	//
	CApplicationScope& operator=(const CApplicationScope& rhs);
	//
	// Activate/deactivate the monitoring process
	//
	BOOL SetActive(BOOL bActive);
	//
	// Instance's pointer holder
	//
	static CApplicationScope* sm_pInstance;
	//
	// A store for all events that have been supplied by the 
	// kernel driver
	//
	CQueueContainer* m_pRequestManager;
	//
	// An instance of the class responsible for loading and unloading
	// the kernel driver
	//
	CNtDriverController* m_pDriverCtl;
	//
	// Hold the state determining whether or not the system is active 
	//
	BOOL m_bIsActive;
	//
	// A thread for receiving notification from the kernel-mode driver
	//
	CProcessThreadMonitor* m_pProcessMonitor;
	//
	// A guard object used for protecting access to the class attributes
	//
	CCSWrapper m_Lock;
public:
	//
	// Implements the "double-checking" locking pattern combined with 
	// Scott Meyers single instance
	// For more details see - 
	// 1. "Modern C++ Design" by Andrei Alexandrescu - 6.9 Living in a 
	//     Multithreaded World
	// 2. "More Effective C++" by Scott Meyers - Item 26
	//
	static CApplicationScope& GetInstance(
		CCallbackHandler* pHandler       // User-supplied object for handling notifications
		);
	//
	// Destructor
	//
	virtual ~CApplicationScope();
	//
	// Initiates process of monitoring process creation/termination
	//
	BOOL StartMonitoring(
		PVOID pvParam        // Pointer to a parameter value passed to the object 
		);
	//
	// Ends up the whole process of monitoring
	//
	void StopMonitoring();
};

#endif // !defined(_APPLICATIONSCOPE_H_)

//----------------------------End of the file -------------------------------
