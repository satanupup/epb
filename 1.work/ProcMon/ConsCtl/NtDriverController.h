//---------------------------------------------------------------------------
//
// NtDriverController.h
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

#if !defined(_NTDRIVERCONTROLLER_H_)
#define _NTDRIVERCONTROLLER_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//---------------------------------------------------------------------------
//
// class CNtDriverController
//
//---------------------------------------------------------------------------
class CNtDriverController  
{
public:
	CNtDriverController();
	virtual ~CNtDriverController();
	//
	// Stop the driver and remove it from the system
	//
	void StopAndRemove();
private:
	//
	// Obtain manager handle
	//
	BOOL Open();
	//
	// Close handle obtained from Open()
	//
	void Close();
	//
	//
	//
	BOOL WaitForState(
		DWORD           dwDesiredState, 
		SERVICE_STATUS* pss
		);
	//
	// Add the driver to the system and start it up
	//
	BOOL InstallAndStart();
private:
	SC_HANDLE m_hSCM;
	SC_HANDLE m_hDriver;
	BOOL      m_bDriverStarted;
	BOOL      m_bErrorOnStart;
	TCHAR     m_szName[MAX_PATH];
	TCHAR     m_szInfo[MAX_PATH];
	TCHAR     m_szFullFileName[MAX_PATH];
};

#endif // !defined(_NTDRIVERCONTROLLER_H_)
//----------------------------End of the file -------------------------------