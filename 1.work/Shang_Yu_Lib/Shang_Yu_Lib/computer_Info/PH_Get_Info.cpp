
#include "PH_Get_Info.h"
#include "PH_Get_Info_fun.h"
#include <LMCons.h>
#define MAX_PATHa 1024
TCHAR SystemDirectory[MAX_PATHa];
TCHAR WindowDirectory[MAX_PATHa];


//取得系統環境
void PH_GetSysFolerInfo()
{
	GetSystemDirectory(SystemDirectory,MAX_PATHa);
	GetWindowsDirectory(WindowDirectory,MAX_PATHa);
	printf("系統目錄    : %s\nWIN目錄     : %s\n",SystemDirectory,WindowDirectory);
}
//取得系統資訊
void Get_computer_Info()
{
	
	
	DWORD ComputerName_Size = (MAX_COMPUTERNAME_LENGTH+1);
	TCHAR ComputerName[MAX_COMPUTERNAME_LENGTH+1];

	DWORD UserName_Size = (UNLEN+1);
	TCHAR UserName[UNLEN+1];
	DWORD temp;
	temp = ComputerName_Size;
	GetComputerName(ComputerName,&temp);
	printf("電腦名稱    : %s\n",ComputerName);

	temp =UserName_Size;
	GetUserName(UserName,&temp);
	printf("使用者名稱  : %s\n",ComputerName);
	//GetComputerNameEx(
}

//取得記憶體資訊
void Get_Memory_Info()
{
	SYSTEM_INFO sysinfo;
	GetSystemInfo(&sysinfo);
	printf("記憶體分頁大小:0x%.8X\n",sysinfo.dwPageSize);
	printf("記憶體啟始位址:0x%.8X\n",sysinfo.lpMinimumApplicationAddress);
	printf("記憶體結束位址:0x%.8X\n",sysinfo.lpMaximumApplicationAddress);
}

//取得CPU資訊
void Get_Cpu_Info()
{
	SYSTEM_INFO sysinfo;
	GetSystemInfo(&sysinfo);
	printf("處理器個數  : %d\n",sysinfo.dwNumberOfProcessors);
	printf("處理器類型  : ");
	switch(sysinfo.dwProcessorType)
	{
	case PROCESSOR_INTEL_386:
		break;
	 
		printf("%s","");
case PROCESSOR_INTEL_486     :printf("%s","INTEL_486");break;
case PROCESSOR_INTEL_PENTIUM :printf("%s","INTEL_PENTIUM");break;
case PROCESSOR_INTEL_IA64    :printf("%s","INTEL_IA64");break;
case PROCESSOR_AMD_X8664     :printf("%s","AMD_X8664");break;
case PROCESSOR_MIPS_R4000    :printf("%s","MIPS_R4000");break;
case PROCESSOR_ALPHA_21064   :printf("%s","ALPHA_21064");break;
case PROCESSOR_PPC_601       :printf("%s","PPC_601");break;
case PROCESSOR_PPC_603       :printf("%s","PPC_603 ");break;
case PROCESSOR_PPC_604       :printf("%s","PPC_604");break;
case PROCESSOR_PPC_620       :printf("%s","PPC_620");break;
case PROCESSOR_HITACHI_SH3   :printf("%s","HITACHI_SH3");break;
case PROCESSOR_HITACHI_SH3E  :printf("%s","HITACHI_SH3E ");break;   // Windows CE
case PROCESSOR_HITACHI_SH4   :printf("%s","HITACHI_SH4");break;  // Windows CE
case PROCESSOR_MOTOROLA_821  :printf("%s","MOTOROLA_821");break;    // Windows CE
case PROCESSOR_SHx_SH3       :printf("%s","SHx_SH3");break;     // Windows CE
case PROCESSOR_SHx_SH4       :printf("%s","SHx_SH4");break;     // Windows CE
case PROCESSOR_STRONGARM     :printf("%s","STRONGARM");break;   // Windows CE - 0xA11
case PROCESSOR_ARM720        :printf("%s","ARM720");break;   // Windows CE - 0x720
case PROCESSOR_ARM820        :printf("%s","ARM820 ");break;   // Windows CE - 0x820
case PROCESSOR_ARM920        :printf("%s","ARM920");break;    // Windows CE - 0x920
case PROCESSOR_ARM_7TDMI     :printf("%s","ARM_7TDMI");break;   // Windows CE
case PROCESSOR_OPTIL         :printf("%s","OPTIL");break; 


	}
	printf("\n");
	printf("處理器架構  : ");
	switch(sysinfo.wProcessorArchitecture)
	{
		case PROCESSOR_ARCHITECTURE_INTEL:
			printf("intel\n");
			printf("CPU世代:%d 版本 %d\n",sysinfo.wProcessorLevel,sysinfo.wProcessorRevision);
			break;
			#define PROCESSOR_ARCHITECTURE_MIPS             1
		case PROCESSOR_ARCHITECTURE_ALPHA            :
			printf("ALPHA \n");
			printf("CPU世代:%d 版本 %d\n",sysinfo.wProcessorLevel,sysinfo.wProcessorRevision);
			break;
		case PROCESSOR_ARCHITECTURE_PPC              :
			printf("PPC\n");
			printf("CPU世代:%d 版本 %d\n",sysinfo.wProcessorLevel,sysinfo.wProcessorRevision);
			break;
		case PROCESSOR_ARCHITECTURE_SHX              :
			printf("SHX\n");
			printf("CPU世代:%d 版本 %d\n",sysinfo.wProcessorLevel,sysinfo.wProcessorRevision);
			break;
		case PROCESSOR_ARCHITECTURE_ARM              :
			printf("ARM\n");
			printf("CPU世代:%d 版本 %d\n",sysinfo.wProcessorLevel,sysinfo.wProcessorRevision);
			break;
		case PROCESSOR_ARCHITECTURE_IA64             :
			printf("IA64\n");
			printf("CPU世代:%d 版本 %d\n",sysinfo.wProcessorLevel,sysinfo.wProcessorRevision);
			break;
		case PROCESSOR_ARCHITECTURE_ALPHA64          :
			printf("ALPHA64\n");
			printf("CPU世代:%d 版本 %d\n",sysinfo.wProcessorLevel,sysinfo.wProcessorRevision);
			break;
		case PROCESSOR_ARCHITECTURE_MSIL             :
			printf("MSIL\n");
			printf("CPU世代:%d 版本 %d\n",sysinfo.wProcessorLevel,sysinfo.wProcessorRevision);
			break;
		case PROCESSOR_ARCHITECTURE_AMD64            :
			printf("AMD64\n");
			printf("CPU世代:%d 版本 %d\n",sysinfo.wProcessorLevel,sysinfo.wProcessorRevision);
			break;
		case PROCESSOR_ARCHITECTURE_IA32_ON_WIN64    :
			printf("IA32_ON_WIN64\n");
			printf("CPU世代:%d 版本 %d\n",sysinfo.wProcessorLevel,sysinfo.wProcessorRevision);
			break;
		case PROCESSOR_ARCHITECTURE_UNKNOWN			:
			printf("UNKNOWN	\n");
			printf("CPU世代:%d 版本 %d\n",sysinfo.wProcessorLevel,sysinfo.wProcessorRevision);
			break;
	}


}
void Get_NET_info()
{
	DWORD temp;
	DWORD ComputerName_Size = (MAX_COMPUTERNAME_LENGTH+1);
	TCHAR ComputerName[MAX_COMPUTERNAME_LENGTH+1];
	temp = ComputerName_Size;
	GetComputerNameEx(ComputerNameNetBIOS,ComputerName,&temp);
	printf("ComputerNameNetBIOS : %s\n",ComputerName);

	temp = ComputerName_Size;
	GetComputerNameEx(ComputerNameDnsHostname,ComputerName,&temp);
	printf("ComputerNameDnsHostname : %s\n",ComputerName);

	temp = ComputerName_Size;
	GetComputerNameEx( ComputerNameDnsDomain,ComputerName,&temp);
	printf(" ComputerNameDnsDomain : %s\n",ComputerName);

	temp = ComputerName_Size;
	GetComputerNameEx(ComputerNameDnsFullyQualified,ComputerName,&temp);
	printf("ComputerNameDnsFullyQualified : %s\n",ComputerName);

	temp = ComputerName_Size;
	GetComputerNameEx(ComputerNamePhysicalDnsHostname,ComputerName,&temp);
	printf("ComputerNamePhysicalDnsHostname : %s\n",ComputerName);


	temp = ComputerName_Size;
	GetComputerNameEx(ComputerNamePhysicalDnsDomain,ComputerName,&temp);
	printf("ComputerNamePhysicalDnsDomain : %s\n",ComputerName);

	temp = ComputerName_Size;
	GetComputerNameEx(ComputerNamePhysicalDnsFullyQualified,ComputerName,&temp);
	printf("ComputerNamePhysicalDnsFullyQualified : %s\n",ComputerName);


	temp = ComputerName_Size;
	GetComputerNameEx(ComputerNameMax,ComputerName,&temp);
	printf("ComputerNameMax : %s\n",ComputerName);
}