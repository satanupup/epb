//#include "stdafx.h"
#include "Ph_kernal.h"


//#include<omp.h>
#define ERROR_no_ACESS 1;
#define softs_MAX 256
#define Controlset_size 10
#define cmdspace " "
char allen[26]="C:xcopy/YQh ";
char Reg_machine_system_controlset00X_subname[22]                      = "SYSTEM\\ControlSet00%d";
//char Reg_machine_system_controlset00X_subname_o[21];
char crtset_c[19] = "ControlSet_%c_%d_c";
char crtset_i[19]=  "ControlSet_%c_%d_i";
char SOFT_c[11] = "software_c";
char SOFT_i[11]=  "software_i";
char USER_i[7]="USER_i";
char USER_c[7]="USER_c";
char Command_restart_now[17]="shutdown -r -t 0";
char software_reg[31]= "HKEY_LOCAL_MACHINE\\SOFTWARE_%c";
void Reg_server_SET(std::string softname);

int is_brfore_start();

std::string systemdisk = "C:";

///std::string intprtdir;
std::string cpcommand = "xcopy /Y/H/C/E/Z/R/F ";
std::string regeditset="regedit/s ";
std::string ph_dir = CFG_InstalledDir;
void tst_0523() //克難時期
{

}

HANDLE device;
HANDLE THRR;
BOOL bdrv;
DWORD dw;
static int shyutetcrlcode=0;
int ShareMem[2]={1,0};
DWORD controlbuff[64];
char* strings[softs_MAX]; 
DWORD stringcount;
LPCTSTR shyudebugshow;

char outputbuff[256];
bool Begin();
void steup();
void thread();
void server_reg()
{

	//Reg_server_SET(softname);
}
/*std::string GET_reg_path(std::string softname)
{

}*/
void restart_cmd()
{
	if(MessageBox(0, "Restart computer now","WARNING",MB_YESNO|MB_ICONQUESTION|0x00200000L)==IDYES)
	{
	    system("shutdown -r -t 0");
	}

}
int soft_list(std::string list[] ,int item_num)
{
	int systemtype[14]; 

	//if(is_brfore_start()==0)
	//////
	//{
	FILE *pp,*pp2;
	
	pp=fopen("typeconfig","rb");

	if(pp !=NULL)
	{
		fread(systemtype,sizeof(int),14,pp);
		if(systemtype[13]==1)
		{
			fclose(pp);
			return 0;
		}
		fclose(pp);
	}
	
			pp2=fopen("typeconfig","wb");
			if(pp2!=NULL)
			{
					systemtype[13]=1;
					fwrite(systemtype,sizeof(int),14,pp2);
					fclose(pp2);
			}

		for(int i=0;i<item_num;i++)
		{

			 Reg_server_SET(list[i]);
		}
		restart_cmd();
	
	//}

	//set server reg here
		return 1;
}




//判斷
void thread()
{
	//	OutputDebugString("執行續建立");
	//多執行續
	DWORD a;
	char msgbuff[512];
	char *pdest;
	int  result;
	while(ShareMem[0])
	{
		memmove(&a,&outputbuff[0],4);
		if(!a)
		{
			Sleep(10);
			continue;
		}
		char*name=(char*)&outputbuff[8];
		pdest = strstr(name,"##");
		if (pdest != NULL)
		{
			result = pdest-name;
		}
		else if((pdest=strstr(name,"$$")) != NULL)
		{
		}
		else
		{

		}
		if(IDYES==MessageBox(0, msgbuff,"WARNING",MB_YESNO|MB_ICONQUESTION|0x00200000L))
		{		
			a=1; 
			strings[stringcount]=_strdup(name);
			stringcount++;
		}
		else a=0;
		//shyutst
		{	
		//shyudebugshow = _strdup(name);
		}

		//shyutst
//skip:
		memmove(&outputbuff[4],&a,4);
	 
	 
	 a=0;
	
	 memmove(&outputbuff[0],&a,4);
	}
	//CopyMenory();
	//OutputDebugString("執行續終結");
}
void steup()
{
	OutputDebugString("steup() is start");
	int i;
	char namebuff[256];
	SC_HANDLE sch,scm;
	GetModuleFileName(NULL,namebuff,256);
	i = strlen(namebuff);
	while (namebuff[i] != '\\')
	{
		i--;
	}
	i++;
	strcpy(&namebuff[i],sysfilename);
	sch = OpenSCManager(NULL,NULL,SC_MANAGER_ALL_ACCESS);
	scm = CreateService(sch,
						sername,
						sername,
						SERVICE_START|SERVICE_STOP,
						SERVICE_KERNEL_DRIVER,
						SERVICE_DEMAND_START,
						SERVICE_ERROR_NORMAL,
						namebuff,
						0,
						0,
						0,
						0,
						0);
	StartService(scm,NULL,NULL);
	CloseServiceHandle(scm);
}
bool Begin()
{
	steup();	
	CloseHandle(device);
	Sleep(100);
     if(shyutetcrlcode == 0)
	 {
	THRR=CreateThread(0,0,(LPTHREAD_START_ROUTINE)thread,0,0,&dw);
	shyutetcrlcode =1;
	 }
	device=CreateFile(	serentry ,
						GENERIC_READ|GENERIC_WRITE,
						0,
						0,
						OPEN_EXISTING,
						FILE_ATTRIBUTE_SYSTEM,
						0);
	
	if (device == INVALID_HANDLE_VALUE)
	{
		TCHAR   str[64]; 
		bdrv = FALSE;
		//MSG_show(MSG_error_loadsys_false);

	}
	else
	{
		bdrv = TRUE;
		MSG_show(MSG_loadsys_turn);

	}
	DWORD * addr=(DWORD *)(1+(DWORD)GetProcAddress(GetModuleHandle("ntdll.dll"),"NtCreateProcess"));
	ZeroMemory(outputbuff,256);
	controlbuff[0]=addr[0];
	controlbuff[1]=(DWORD)&outputbuff[0];
	MSG_show(MSG_loadsys_fin);
	return bdrv;
	
}
void CloseSrv()
{
	//OutputDebugString("284:CloseSrv()");
	CloseHandle(device);
	OutputDebugString("284:CloseSrv()::CloseHandle(device);");
	SC_HANDLE sch ;
	SERVICE_STATUS ss;
	sch = OpenSCManager(NULL,0,0);
	SC_HANDLE scm ;
	scm = OpenService(sch,sername,SERVICE_ALL_ACCESS);
	ControlService(scm,SERVICE_CONTROL_STOP,&ss);
	DeleteService(scm);
	CloseServiceHandle(scm);
	Sleep(100);
}

void R3_load()  //cc混淆
{
	char cpstr[12];
	char abc[2] ;
	abc[0]=allen[0];
	abc[1]=allen[1];
	systemdisk =abc;
	cpstr[0]=allen[2];
	cpstr[1]=allen[3];
	cpstr[2]=allen[4];
	cpstr[3]=allen[5];
	cpstr[4]=allen[6];
	cpstr[5]=allen[7];
	cpstr[6]=allen[8];
	cpstr[7]=allen[7];
	cpstr[8]=allen[9];
	cpstr[9]=allen[10];
	cpstr[11]=allen[11];
	cpcommand = cpstr;
	
}


void start_bar_unit(std::string name)
{
	
}
bool Sysfile_Load()
{
//檔案存在確認
	bool n = Begin();
	if(n)
	{
		DeviceIoControl(device, 1004, controlbuff,256, controlbuff,256,&dw, 0);
	}
	return n;
}
void SystemFile_Unload()
{
		 CloseSrv();
}
std::string IntputDirName_Get(std::string softname)
{
	std::string patchname;
	//x連結sql
	//xcopy \\samba\\phancloud\\office C:\\

	//輸出
	return patchname;
}

void Isfilehere()
{
	system("");
}

int is_brfore_start()
{
	int systemtype[20]={1};
	FILE *pp,*pp2;
	pp=fopen("typeconfig","rb");
	if(pp!=NULL)
	{
		fread(systemtype,sizeof(int),20,pp);
		if(systemtype[13]==0)
		{
			return 0;
		}
		else if(systemtype[13]==1)
		{
			return 1;
		}
		else
		{
			pp2=fopen("typeconfig","wb");
			if(pp2!=NULL)
			{
					systemtype[13]=1;
					fwrite(systemtype,sizeof(int),20,pp);
					fclose(pp2);
			
			
				return 0;
			}
			else
			{
				return ERROR_no_ACESS;
			}
		}	
		
	
	}
	else
	{
		pp=fopen("typeconfig","wb");
		if(pp!=NULL)
		{
			systemtype[13]=1;
			fwrite(systemtype,sizeof(int),20,pp);
			fclose(pp);
		}
		else
		{
		  return ERROR_no_ACESS;
		}
	
	    return 0;
		
	}

}



void Reg_server_SET(std::string softname)
{	
	std::string newcmd2;
	std::string Networkname;
	std::string patch=ph_dir+"\\"+softname;
	std::string newcmd;
	char Buff_crtset_c[17];
	char Buff_crtset_i[17];
			Networkname = regeditset;
		Networkname +="\"";
		Networkname += CFG_ServerIP;
		Networkname += "\\";
		Networkname += CFG_FilesysSite;
		Networkname += CFG_FileRegSite;
		Networkname += "\\";
		Networkname += softname;
		Networkname += "\\";
		for(int temp_num=0;temp_num<Controlset_size;temp_num++)
		{

		sprintf(Buff_crtset_c,crtset_c,'s',temp_num);
			/*
				檔案存在確認，中止環節
			*/
        newcmd2 = Networkname;
	   
		newcmd2 +=Buff_crtset_c;

		newcmd2 +="";
		newcmd2 +="\"";
		//MSG_show(newcmd2.c_str());
		system(newcmd2.c_str());


		sprintf(Buff_crtset_i,crtset_i,'s',temp_num);
		newcmd2 = Networkname;
		newcmd2 +=Buff_crtset_i;

		newcmd2 +="";
		newcmd2 +="\"";
		system(newcmd2.c_str());

		sprintf(Buff_crtset_c,crtset_c,'c',temp_num);
			/*
				檔案存在確認，中止環節
			*/
        newcmd2 = Networkname;
	   
		newcmd2 +=Buff_crtset_c;

		newcmd2 +="";
		newcmd2 +="\"";
		//MSG_show(newcmd2.c_str());
		system(newcmd2.c_str());


		sprintf(Buff_crtset_i,crtset_i,'c',temp_num);
		newcmd2 = Networkname;
		newcmd2 +=Buff_crtset_i;

		newcmd2 +="";
		newcmd2 +="\"";
		system(newcmd2.c_str());

		sprintf(Buff_crtset_c,crtset_c,'e',temp_num);
			/*
				檔案存在確認，中止環節
			*/
        newcmd2 = Networkname;
	   
		newcmd2 +=Buff_crtset_c;

		newcmd2 +="";
		newcmd2 +="\"";
		//MSG_show(newcmd2.c_str());
		system(newcmd2.c_str());


		sprintf(Buff_crtset_i,crtset_i,'e',temp_num);
		newcmd2 = Networkname;
		newcmd2 +=Buff_crtset_i;
		newcmd2 +="";
		newcmd2 +="\"";
		system(newcmd2.c_str());
		}


}

void RegFile_SET(std::string softname)
{

	std::string newcmd;
	std::string patch=ph_dir+"\\"+softname;
	newcmd =strage1;
	if(access(patch.c_str(),0) == 0)  //
	{



	std::string cmd;
	cmd = regeditset+ph_dir+"\\"+softname;
	//Sysfile_Load();
	//std::cout << cmd << std::endl;
	system(cmd.c_str());
	//regintput
	}
	else
	{
		std::string Networkname;
		std::string newcmd2 ;
	
		std::string temp;
		//for
		//if(fopen(c_s_cdir
		//c_s_c詢問
		//


		Networkname = regeditset;
		Networkname +="\"";
		Networkname += CFG_ServerIP;
		Networkname += "\\";
		Networkname += CFG_FilesysSite;
		Networkname += CFG_FileRegSite;
		Networkname += "\\";

		newcmd2 = Networkname;
		newcmd2 +=softname;
		newcmd2 +="\\";
		newcmd2 +=SOFT_i;
		newcmd2 +="";
		newcmd2 +="\"";
		system(newcmd2.c_str());


		newcmd2 = Networkname;
		newcmd2 +=softname;
		newcmd2 +="\\";
		newcmd2 +=SOFT_c;
		newcmd2 +="";
		newcmd2 +="\"";
		system(newcmd2.c_str());



		//MSG_show(Networkname.c_str());

	//	system(Networkname.c_str());
				newcmd2 = Networkname;
		newcmd2 +=softname;
		newcmd2 +="\\";
		newcmd2 +=USER_c;
		newcmd2 +="";
		newcmd2 +="\"";
		system(newcmd2.c_str());

		newcmd2 = Networkname;
		newcmd2 +=softname;
		newcmd2 +="\\";
		newcmd2 +=USER_i;
		newcmd2 +="";
		newcmd2 +="\"";
		system(newcmd2.c_str());


	}
	SystemFile_Unload();
}

int LocalCatch_Clear(std::string softname)
{
	return false;
}
int LocalCatch_Set(std::string softname)
{
	std::string debug_msg = "sottname = ";
	debug_msg+=softname;
	MSG_show(debug_msg);
	std::string cmdmake;
	//std::string patch = "\"\\\\192.168.3.115\\project\\office\" ";
	std::string patch = "\"";
	patch+=CFG_ServerIP;
	patch+="\\";
	patch+=CFG_FilesysSite;
	//patch +="office";
	patch+=softname;
	patch+="\" ";

	std::string newcmsd;
	newcmsd = strage1;
	newcmsd += patch;
	newcmsd += systemdisk;
	newcmsd += "\\";
	//cmdmake = cpcommand + patch ;
	//cmdmake +=cmdspace;
	//cmdmake +=systemdisk;
	//MSG_show(MSG_loading);

	//debug only
	//MSG_show(newcmsd.c_str());
	//debugonly

	return system(newcmsd.c_str());
	 
}
void allwork2(Test_intput_msg a)
{
std::string file_path;
	if(Sysfile_Load())
	{

		if(soft_install_check(a.a1))
		{

		}
		//if(soft_install_check("C:\\Program Files\\AutoCAD 2004")){}
	
		else
		{
			OutputDebugString("soft_install_check");
			LocalCatch_Set(a.a2);
		}
		if(reg_Check())
		{
			file_path = softpath_get (a.a2);
			RegFile_SET(a.a2);
		}
		else{}
		SystemFile_Unload();
	}
}
Test_output_msg Debug_item(Test_intput_msg a)
{
	Test_output_msg ax;

	allwork2(a);


	ax.o1="aaa";
	return ax;
}
void all_work(std::string softname,std::string chack_catah)
{
	//MSG_show(chack_catah);
	std::string file_path;


		if(soft_install_check(chack_catah))
		{

			MSG_show(chack_catah);
		}
		//if(soft_install_check("C:\\Program Files\\AutoCAD 2004")){}
	
		else
		{
			OutputDebugString("soft_install_check");
			LocalCatch_Set(softname);
		}
	if(Sysfile_Load())
	{
		if(reg_Check())
		{
			file_path = softpath_get (softname );
			RegFile_SET(softname);
			Sleep(2000);
			/*
			
			*/
		}
		else
		{

		}
		SystemFile_Unload();
	}
	else
	{
		MSG_show(" 核心載入失敗");
	}
	///宰入完成
}
void network()
{

}
void exe_only_crl()
{
	
}
void bef_rebot()
{

}
int Debug_Mode_command()
{
	//0 == exit
	//1 == wait next command
	 char inpu[500];
			 printf("PhanCloud >");
			 std::cin >>inpu;
			 if(inpu[0] == 'e' && inpu[1]=='x' && inpu[2] == 'i' && inpu [3] == 't' && inpu [4] == '\0')
			 {
				return 0;
			 }
			 if(inpu[0] == '?' && inpu[1]=='\0')
			 {
				 printf("exit");
				 printf("\n");
				return 1;
			 }
		     if(inpu[0] == 'v' && inpu[1]=='e' && inpu[2] == 'r' && inpu [3] == 's' && inpu [4] == 'i'&& inpu[5]=='o' && inpu[6] == 'n' && inpu [7] == '\0' )
			 {
				 printf("version:1.0\t");
				 printf("kernal by shang yu lee \n");
				return 1;
			 }
			 printf("%s\n",inpu);
			

}
void main()
{
	
	//標準流程
	// Begin();
	// DeviceIoControl(device, 1004, controlbuff,256, controlbuff,256,&dw, 0);
     //output file type 判斷為開及前後*	 char buf[24];
	/* FILE *fo;
	 if(fopen ("start-type","r")!=NULL)
	 {
		 //結構
		 fread(buf,0,24,fo);
		printf("%S",buf);
	 }
	 else
	 {
		 printf("檔案遺失");
	 }*/
//	 is_first_start();


	 
	 if(Begin())
	 {

		DeviceIoControl(device, 1004, controlbuff,256, controlbuff,256,&dw, 0);
	//	RegFile_SET("office");
	 }
	 else
	 {
		
		 std::cout << "PhanCloud 2012 ->Debug_mode \n"<< std::endl;
		 while(true)
		 {
			if( Debug_Mode_command()==0)
			{
				break;
			}
		 }
	 }

	 CloseSrv();
	 //END
	 
	//system("pause");
}