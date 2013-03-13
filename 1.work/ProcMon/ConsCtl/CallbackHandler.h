//---------------------------------------------------------------------------
//
// CallbackHandler.h
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
#if !defined(_CALLBACKHANDLER_H_)
#define _CALLBACKHANDLER_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


//---------------------------------------------------------------------------
//
//                   typedefs for PSAPI.DLL functions 
//
//---------------------------------------------------------------------------
typedef BOOL (WINAPI * PFNENUMPROCESSMODULES)(
    HANDLE   hProcess,
    HMODULE *lphModule,
    DWORD    cb,
    LPDWORD  lpcbNeeded
	);

typedef DWORD (WINAPI * PFNGETMODULEFILENAMEEX)(
    HANDLE  hProcess,
    HMODULE hModule,
    LPTSTR  lpFilename,
    DWORD   nSize
	);

//---------------------------------------------------------------------------
//
// class CCallbackHandler
//
//---------------------------------------------------------------------------
class CCallbackHandler  
{
public:
	CCallbackHandler();
	virtual ~CCallbackHandler();
	//
	// Define an abstract interface for receiving notifications
	//
	virtual void OnProcessEvent(
		PQUEUED_ITEM pQueuedItem, 
		PVOID        pvParam
		) = 0;
protected:
	//
	// Return the name of the process by its ID using PSAPI
	//
	 BOOL GetProcessName(
		DWORD  dwProcessId,
		LPTSTR lpFileName, 
		DWORD  dwLen
		);
private:
	HMODULE                 m_hModPsapi;
	PFNENUMPROCESSMODULES   m_pfnEnumProcessModules;	
	PFNGETMODULEFILENAMEEX  m_pfnGetModuleFileNameEx;
};

#endif // !defined(_CALLBACKHANDLER_H_)
//----------------------------End of the file -------------------------------
