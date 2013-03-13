#ifndef _applay_entry_H
#include "../applay_entry.h"
#endif
#ifdef offlin_hive
#pragma comment(lib,"offreg.lib")
#endif
#pragma comment (lib,"Advapi32.lib")
BOOLEAN hive_unload(HKEY key,LPCTSTR subkey)
{
	return  (ERROR_SUCCESS == RegUnLoadKey(key,subkey));
}

BOOLEAN load_hive(HKEY key,LPCTSTR subkey,LPCTSTR filename)
{
	ULONG A;
	HANDLE hToken = NULL;
	//LUID rLuid;
	//LUID bLuid;
	OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES|TOKEN_QUERY, &hToken);
	TOKEN_PRIVILEGES tkp;

	//LookupPrivilegeValue(NULL, SE_BACKUP_NAME, &tkp.Privileges[0].Luid);
	//LookupPrivilegeValue(NULL, SE_RESTORE_NAME, &tkp.Privileges[1].Luid);
	//tkp.PrivilegeCount = 2;
	tkp.PrivilegeCount = 1;
	LookupPrivilegeValue(NULL, SE_RESTORE_NAME, &tkp.Privileges[0].Luid);


	//tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	//tkp.Privileges[1].Attributes = SE_PRIVILEGE_ENABLED;

	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	if(AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, NULL, 0))
	{

		//explam RegLoadKey(HKEY_USERS, L"Test\\", L"C:\\Documents and Settings\\test\\NTUSER.DAT");'
	//	A=RegLoadKey(HKEY_LOCAL_MACHINE,subkey,filename);
		A=RegLoadKey(key,subkey,filename);
		//printf("%d",A);
		CloseHandle(hToken);
		return (ERROR_SUCCESS == A);
	}

	CloseHandle(hToken);
	printf (" AdjustTokenPrivileges is false \n");
	return FALSE;
}
//LONG WINAPI RegUnLoadKey(
//  _In_      HKEY hKey,
 // _In_opt_  LPCTSTR lpSubKey
//    );


BOOLEAN save_hive(HKEY key,LPCSTR subkey,LPCSTR filename)
{
	ULONG A;
	HANDLE hToken = NULL;
	HKEY hkey; 
	TOKEN_PRIVILEGES tkp;
	//SECURITY_ATTRIBUTES sa; 
	DWORD S;

	OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES|TOKEN_QUERY, &hToken);

	tkp.PrivilegeCount = 1;
	LookupPrivilegeValue(NULL, SE_BACKUP_NAME, &tkp.Privileges[0].Luid);
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	if(AdjustTokenPrivileges(hToken, FALSE, &tkp, sizeof(tkp), (PTOKEN_PRIVILEGES)NULL, 0))
	{
		//if(ERROR_SUCCESS ==RegOpenKeyEx(key, subkey, 0, KEY_QUERY_VALUE, &hkey))

		if((RegCreateKeyEx(key,subkey,0,NULL,REG_OPTION_BACKUP_RESTORE, KEY_QUERY_VALUE,NULL, &hkey,&S))==ERROR_SUCCESS)

		{
		//explam RegLoadKey(HKEY_USERS, L"Test\\", L"C:\\Documents and Settings\\test\\NTUSER.DAT");
		
	/*	sa.nLength=sizeof(SECURITY_ATTRIBUTES); 
		sa.lpSecurityDescriptor =NULL; 
		sa.bInheritHandle =TRUE; */
		


		A=RegSaveKey(hkey,filename,NULL);
		//printf("%d",A);
		CloseHandle(hToken);
		/*if(hkey)
		{
			RegCloseKey(hkey);
		}*/
		printf("msg code %d\n",A);
		return (ERROR_SUCCESS == A);
		}

		else
		{
			CloseHandle(hToken);
			printf("key opend [false]\n");
			return FALSE;
		}
	}
	CloseHandle(hToken);
	printf (" AdjustTokenPrivileges is false \n");
	return FALSE; 
}
#ifdef offlin_hive
DWORD Oc_Create_H(PORHKEY pokey)
{
	return ORCreateHive(pokey);

}
DWORD Oc_Close_H(PORHKEY pokey)

{
	return ORCloseHive(*pokey);
}

DWORD Orc_tst()
{
	DWORD A=0;
	try
	{
	ORHKEY phkResult;
    A=OROpenHive(L"C:\\h.hive",&phkResult);
	
	if(A==ERROR_SUCCESS)
	{
	  A = Oc_Close_H(&phkResult);
	  printf("%d",A);
	  if(A==ERROR_SUCCESS)
	  {
		  return A;
	  }
	}
	else
	{
		printf("%d\n",A);
		if(A== ERROR_FILE_NOT_FOUND)
		{
			printf(" ERROR_FILE_NOT_FOUND ::");
		}


		if(A==ERROR_ACCESS_DENIED)
		{
			printf("ERROR_ACCESS_DENIED ::");
		}


		if(A== ERROR_BADDB)
		{
			printf("ERROR_BADDB ::");

		}
		if(A==ERROR_NOT_REGISTRY_FILE)
		{
			printf("ERROR_NOT_REGISTRY_FILE ::");
		}

	}
	
	}
    catch (...)
	{
		return A;
	}
	return A;
}
LONG  connectlkey(   __in_opt  LPCTSTR lpMachineName,
  __in      HKEY hKey,
  __out     PHKEY phkResult)
{
	return RegConnectRegistry(lpMachineName, hKey,phkResult);
}

LONG predukey( __in      HKEY hKey, __in_opt  HKEY hNewHKey)
{
	return RegOverridePredefKey(hKey,hNewHKey);
}
LONG free_predukey()
{

	return  RegDisablePredefinedCache();
}

void reg_test_mon(HKEY hkey,char command[2])
{
	if(command[0]=='A')
	{
	HKEY rekey=NULL;
	HKEY rekey2=NULL;
	HKEY tstkey=HKEY_LOCAL_MACHINE;
		if(command[1]=='A')
	{
		RegOverridePredefKey(tstkey,NULL);
	}
	/*if((RegOpenKey(HKEY_LOCAL_MACHINE,"SOFTWARE\\phtest2",&rekey)==ERROR_SUCCESS)&&(RegOpenKey(HKEY_LOCAL_MACHINE,"SOFTWARE\\phtest",&rekey2)==ERROR_SUCCESS));
	{
		if( ERROR_SUCCESS ==  RegOverridePredefKey(tstkey,rekey2))
		{
			printf("map fin");system("regedit");
		}
		else
		{
			
			printf("map die\n");
		}
	//	RegCloseKey(rekey);
	//	RegCloseKey(rekey2);
	}*/
	}
	else
	{
		printf("open key is false\n");
	}

}
void easy_reg_add()
{

}
LONG reg_save_and_restore_tst(HKEY hKey,char crl_c)
{
	
	LONG Return_Info;
	DWORD dwFlags;
	LPCTSTR lpFile="C:\\gh.hive";
	if(crl_c == 'S')
	{
	//LPSECURITY_ATTRIBUTES lpSecurityAttributes=NULL;
	Return_Info=	RegSaveKey(__in      hKey,__in      lpFile,NULL);
		if(Return_Info == ERROR_SUCCESS)
		{
			printf("save is [ok]\n");
		}
		else
		{
			printf("Save Key is %d die\n",Return_Info);
		}

		return Return_Info;
	}

	if(crl_c=='R')
	{
		dwFlags=REG_FORCE_RESTORE;// REG_FORCE_RESTORE or REG_WHOLE_HIVE_VOLATILE



		Return_Info=RegRestoreKey(__in  hKey,__in  lpFile,__in  dwFlags);
		return Return_Info;
	}
	Return_Info=!ERROR_SUCCESS;
	return Return_Info;
}
#endif