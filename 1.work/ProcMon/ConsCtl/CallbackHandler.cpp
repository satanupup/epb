
//---------------------------------------------------------------------------
//
// CallbackHandler.cpp
//
// SUBSYSTEM:   
//              Monitoring process creation and termination  
//子系統：
//監視進程創建和終止
//				
// MODULE:      
//              An abstract interface for receiving notification when a 
//              process has been created or terminated  
//模塊：
//一個抽象的接口接到通知時
//過程已創建或終止
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
	//獲取動態PSAPI.DLL功能。我們不能
	//一定PSAPI.DLL已安裝
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
//返回進程的名稱，其ID使用PSAPI
//
//#include <iostream>
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
//讓我們打開過程
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
// EnumProcessModules的函數獲取一個句柄
//每個模塊在指定的進程。
				if (m_pfnEnumProcessModules(
						hProcess, 
						hModuleArray,
						sizeof(hModuleArray), 
						&cbNeeded))
				{
					// Calculate number of modules in the process     
//計算的過程中模塊的數量                              
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
						
				//	std::cout<<"hello="<<lpFileName<<std::endl;
					} // if
				} // if
				::CloseHandle(hProcess);
			} // if
		} // if
	} // if
	return bResult;
}

//--------------------- End of the file -------------------------------------
