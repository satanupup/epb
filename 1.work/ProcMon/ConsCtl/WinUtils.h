//---------------------------------------------------------------------------
//
// WinUtils.h
//
// SUBSYSTEM:   
//              Monitoring process creation and termination  
//				
// DESCRIPTION: Common header 
//             
// AUTHOR:		Ivo Ivanov
//
//---------------------------------------------------------------------------
#if !defined(_WINUTILS_H_)
#define _WINUTILS_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//---------------------------------------------------------------------------
//
// Includes
//
//---------------------------------------------------------------------------
#include "Common.h"
#include <tchar.h>

//---------------------------------------------------------------------------
// ReplaceFileName
//
//---------------------------------------------------------------------------
static BOOL ReplaceFileName(
	TCHAR* pszOldFileName,
	TCHAR* pszBaseNewFileName,
	TCHAR* pszNewFileName
	)
{
	BOOL  bResult = TRUE;
	TCHAR *pdest;
	_TINT   ch = TEXT('\\');
	::ZeroMemory((PBYTE)pszNewFileName, sizeof(MAX_PATH));	
	//_tcscpy(pszNewFileName, pszOldFileName);	
	wcscpy_s(pszNewFileName,MAX_PATH,pszOldFileName);
	// Search backward and replaces the dll name with the hook one
	pdest = _tcsrchr(pszNewFileName, ch);
	if( pdest != NULL )
	//	_tcscpy(&pdest[1], pszBaseNewFileName);		
		wcscpy_s(&pdest[1],MAX_PATH,pszBaseNewFileName);
	else
	//	_tcscpy(pszNewFileName, pszBaseNewFileName);
		wcscpy_s(pszNewFileName,MAX_PATH,pszBaseNewFileName);

	return bResult;
}

//---------------------------------------------------------------------------
// GetProcessHostFullName
//
// Return the path and the name of the current process
//---------------------------------------------------------------------------
static BOOL GetProcessHostFullName(TCHAR* pszFullFileName)
{
	DWORD dwResult = 0;
	::ZeroMemory((PBYTE)pszFullFileName, MAX_PATH);
	dwResult = ::GetModuleFileName(
		NULL,                   // handle to module
		pszFullFileName,        // file name of module
		MAX_PATH                // size of buffer
		);

	return (dwResult != 0);
}

//---------------------------------------------------------------------------
// VerifyIsWindowsNtRequired
//
// Verify the OS and current OS doesn't meet the requirement it exits
//---------------------------------------------------------------------------
static void VerifyIsWindowsNtRequired() 
{
	OSVERSIONINFO vi = { sizeof(vi) };
	::GetVersionEx(&vi);
	if (vi.dwPlatformId != VER_PLATFORM_WIN32_NT) 
		::ExitProcess(0);
}


#endif // !defined(_WINUTILS_H_)

//--------------------- End of the file -------------------------------------
