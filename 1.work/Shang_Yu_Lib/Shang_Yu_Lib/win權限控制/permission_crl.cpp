#include "permission_crl.h"
#include "permission_crl_fun.h"
#include <aclapi.h>
#include <tlhelp32.h>
#include <shlwapi.h>
#pragma comment(lib,"Shlwapi.lib")

BOOL EnableDebugPriv(LPCTSTR szPrivilege)
{
  HANDLE hToken;
  LUID sedebugnameValue;
  TOKEN_PRIVILEGES tkp;

  if (!OpenProcessToken(GetCurrentProcess(),
                        TOKEN_ADJUST_PRIVILEGES|TOKEN_QUERY,
                        &hToken))
  {
    return FALSE;
  }
  if (!LookupPrivilegeValue(NULL, szPrivilege, &sedebugnameValue))
  {
    CloseHandle(hToken);
    return FALSE;
  }

  tkp.PrivilegeCount = 1;
  tkp.Privileges[0].Luid = sedebugnameValue;
  tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

  if (!AdjustTokenPrivileges(hToken, FALSE, &tkp, sizeof tkp, NULL, NULL))
  {
    CloseHandle(hToken);
    return FALSE;
  }

  return TRUE;
}


DWORD GetProcessId(LPCTSTR szProcName)
{
  PROCESSENTRY32 pe;  
  DWORD dwPid;
  DWORD dwRet;
  BOOL bFound = FALSE;
  
  HANDLE hSP = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
  if (hSP)
  {
    pe.dwSize = sizeof(pe);

    for (dwRet = Process32First(hSP, &pe);
         dwRet;
         dwRet = Process32Next(hSP, &pe))
  {
      
      if (StrCmpNI(szProcName, pe.szExeFile, strlen(szProcName)) == 0)
      {
        dwPid = pe.th32ProcessID;
        bFound = TRUE;
        break;
      }
    }

    CloseHandle(hSP);

    if (bFound == TRUE)
    {
      return dwPid;
    }
  }

  return NULL;
}

BOOL CreateSystemProcess(LPTSTR szProcessName)
{
  HANDLE hProcess;
  HANDLE hToken, hNewToken;
  DWORD dwPid;

  PACL pOldDAcl = NULL;
  PACL pNewDAcl = NULL;
  BOOL bDAcl;
  BOOL bDefDAcl;
  DWORD dwRet;

  PACL pSacl = NULL;
  PSID pSidOwner = NULL;
  PSID pSidPrimary = NULL;
  DWORD dwAclSize = 0;
  DWORD dwSaclSize = 0;
  DWORD dwSidOwnLen = 0;
  DWORD dwSidPrimLen = 0;

  DWORD dwSDLen;
  EXPLICIT_ACCESS ea;
  PSECURITY_DESCRIPTOR pOrigSd = NULL;
  PSECURITY_DESCRIPTOR pNewSd = NULL;

  STARTUPINFO si;
  PROCESS_INFORMATION pi;

  BOOL bRet = true;

  if (!EnableDebugPriv("SeDebugPrivilege"))
  {
      bRet = false;
    goto Cleanup;
  }
  

  if ((dwPid = GetProcessId("WINLOGON.EXE")) == NULL)
  {
 
    bRet = false;
    goto Cleanup;
  }

  hProcess = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, dwPid);
  if (hProcess == NULL)
  {
    bRet = false;
    goto Cleanup;
  }

  if (!OpenProcessToken( hProcess, READ_CONTROL|WRITE_DAC, &hToken ))
  {

    bRet = false;
    goto Cleanup;
  }

  ZeroMemory(&ea, sizeof( EXPLICIT_ACCESS));
  BuildExplicitAccessWithName(&ea,
                             "Everyone",
                              TOKEN_ALL_ACCESS,
                              GRANT_ACCESS,
                              0);

  if (!GetKernelObjectSecurity(hToken,
                               DACL_SECURITY_INFORMATION,
                               pOrigSd,
                               0,
                               &dwSDLen))
  {
    
    if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
    {
      pOrigSd = (PSECURITY_DESCRIPTOR) HeapAlloc(GetProcessHeap(),
                                                 HEAP_ZERO_MEMORY,
                                                 dwSDLen);
      if (pOrigSd == NULL)
      {
   
        bRet = false;
        goto Cleanup;
      }
      if (!GetKernelObjectSecurity(hToken,
                                   DACL_SECURITY_INFORMATION,
                                   pOrigSd,
                                   dwSDLen,
                                   &dwSDLen))
      {
        bRet = false;
        goto Cleanup;
      }
    }
    else
    {
           bRet = false;
      goto Cleanup;
    }
  }

  if (!GetSecurityDescriptorDacl(pOrigSd, &bDAcl, &pOldDAcl, &bDefDAcl))
  {
   
    bRet = false;
    goto Cleanup;
  }

  dwRet = SetEntriesInAcl(1, &ea, pOldDAcl, &pNewDAcl); 
  if (dwRet != ERROR_SUCCESS)
  {

    pNewDAcl = NULL;

    bRet = false;
    goto Cleanup;
  }

  if (!MakeAbsoluteSD(pOrigSd,
                      pNewSd,
                      &dwSDLen,
                      pOldDAcl,
                      &dwAclSize,
                      pSacl,
                      &dwSaclSize,
                      pSidOwner,
                      &dwSidOwnLen,
                      pSidPrimary,
                      &dwSidPrimLen))
  {
    
    if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
    {
      pOldDAcl = (PACL) HeapAlloc(GetProcessHeap(),
                                  HEAP_ZERO_MEMORY,
                                  dwAclSize);
      pSacl = (PACL) HeapAlloc(GetProcessHeap(),
                               HEAP_ZERO_MEMORY,
                               dwSaclSize);
      pSidOwner = (PSID) HeapAlloc(GetProcessHeap(),
                                   HEAP_ZERO_MEMORY,
                                   dwSidOwnLen);
      pSidPrimary = (PSID) HeapAlloc(GetProcessHeap(),
                                     HEAP_ZERO_MEMORY,
                                     dwSidPrimLen);
      pNewSd = (PSECURITY_DESCRIPTOR) HeapAlloc(GetProcessHeap(),
                                                HEAP_ZERO_MEMORY,
                                                dwSDLen);

      if (pOldDAcl == NULL||
          pSacl == NULL||
          pSidOwner == NULL||
          pSidPrimary == NULL||
          pNewSd == NULL )
      {
        printf("HeapAlloc SID or ACL failed!\n");

        bRet = false;
        goto Cleanup;
      }

      if (!MakeAbsoluteSD(pOrigSd,
                          pNewSd,
                          &dwSDLen,
                          pOldDAcl,
                          &dwAclSize,
                          pSacl,
                          &dwSaclSize,
                          pSidOwner,
                          &dwSidOwnLen,
                          pSidPrimary,
                          &dwSidPrimLen))
      {

        bRet = false;
        goto Cleanup;
      }
    }
    else
    {
     
      bRet = false;
      goto Cleanup;
    }
  }

  if (!SetSecurityDescriptorDacl( pNewSd, bDAcl, pNewDAcl, bDefDAcl))
  {
   
    bRet = false;
    goto Cleanup;
  }
  
  if (!SetKernelObjectSecurity( hToken, DACL_SECURITY_INFORMATION, pNewSd))
  {


    bRet = false;
    goto Cleanup;
  }
  
  if (!OpenProcessToken( hProcess, TOKEN_ALL_ACCESS, &hToken))
  {


    bRet = false;
    goto Cleanup;
  }

  if (!DuplicateTokenEx(hToken,
                        TOKEN_ALL_ACCESS,
                        NULL,
                        SecurityImpersonation,
                        TokenPrimary,
                        &hNewToken))
  {


    bRet = false;
    goto Cleanup;
  }


  ZeroMemory(&si, sizeof(STARTUPINFO));
  si.cb = sizeof(STARTUPINFO);

  ImpersonateLoggedOnUser(hNewToken);

  if (!CreateProcessAsUser(hNewToken,
                           NULL,
                           szProcessName,
                           NULL,
                           NULL,
                           FALSE,
                           NULL,//NORMAL_PRIORITY_CLASS|CREATE_NEW_CONSOLE,
                           NULL,
                           NULL,
                           &si,
                           &pi))
  {


    bRet = false;
    goto Cleanup;
  }
  WaitForSingleObject(pi.hProcess, INFINITE);

Cleanup:
  if (pOrigSd)
  {
    HeapFree(GetProcessHeap(), 0, pOrigSd );
  }
  if (pNewSd)
  {
    HeapFree(GetProcessHeap(), 0, pNewSd );
  }
  if (pSidPrimary)
  {
    HeapFree(GetProcessHeap(), 0, pSidPrimary);
  }
  if (pSidOwner)
  {
    HeapFree(GetProcessHeap(), 0, pSidOwner);
  }
  if (pSacl)
  {
    HeapFree(GetProcessHeap(), 0, pSacl);
  }
  if (pOldDAcl)
  {
    HeapFree(GetProcessHeap(), 0, pOldDAcl);
  }

  CloseHandle(pi.hProcess);
  CloseHandle(pi.hThread);
  CloseHandle(hToken);
  CloseHandle(hNewToken);
  CloseHandle(hProcess);
  return bRet;
}


BOOLEAN ACL_crl_get()
{
	return FALSE;
}