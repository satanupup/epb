#include "Ph_kernal.h"

#include "command_str_mapper.h"
//#include<omp.h>
static boolean sys_woking = false;
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


int is_brfore_start();

std::string systemdisk = "C:";

///std::string intprtdir;
std::string cpcommand = "xcopy /Y/H/C/E/Z/R/F ";
std::string regeditset="regedit/s ";
std::string ph_dir = CFG_InstalledDir;
void Reg_server_SET(std::string softname);
bool singe_file_cp(std::string form,std::string to);
#define GreenManTst
#ifdef GreenManTst
HANDLE sys_loadThread = NULL; 
#endif
void tst_0523() //克難時期
{

}

HANDLE device;
HANDLE THRR;
bool bdrv;
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
void load_softreg()
{
	
	HKEY GF;
	RegOpenKey(HKEY_LOCAL_MACHINE,"SoftWar2",&GF);
	RegRestoreKey(
  __in  GF,
  __in  "E:\\SOFTWARE",
  __in  REG_WHOLE_HIVE_VOLATILE
);


}
LONG tsthiv2()
{
	







	return RegReplaceKey(  
        HKEY_LOCAL_MACHINE
,     // handle to open key  
        "SOFTWAR2", // address of name of subkey  
        "C:\\SOFTWARE", //在替換前生成新的備份文件
        "D:\\SOFTWARE" //需要覆蓋上註冊表的文件  
      );  

}




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
			if(pp2 != NULL)
			{
					systemtype[13]=1;
					fwrite(systemtype,sizeof(int),14,pp2);
					fclose(pp2);
			}

		for(int i=0;i<item_num;i++)
		{

			 Reg_server_SET(list[i]);
		}
	//	restart_cmd();
	
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
		char* name=(char*)&outputbuff[8];
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
		else 
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
	#ifdef GreenManTst
	DWORD Id;
    char *a ="lokme";
	#endif
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
//		TCHAR   str[64]; 
		bdrv = false;
		//MSG_show(MSG_error_loadsys_false);

	}
	else
	{
		bdrv = true;
		MSG_show(MSG_loadsys_turn);

	}
	DWORD * addr=(DWORD *)(1+(DWORD)GetProcAddress(GetModuleHandle("ntdll.dll"),"NtCreateProcess"));
	ZeroMemory(outputbuff,256);
	controlbuff[0]=addr[0];
	controlbuff[1]=(DWORD)&outputbuff[0];

	MSG_show(MSG_loadsys_fin);

	#ifdef GreenManTst
	if(bdrv)
	{
	  sys_loadThread=CreateThread(NULL,0,ThreadProc_bmap_tst2,a,0,&Id);
	}
	Sleep(100);
	#endif
	return bdrv;
	
}
void ClearBUFF()
{

	system("delete E:\\SOFTWARE2");
	system("delete E:\\SYSTEM");
	system("delete E:\\USER");
}

void CloseSrv()
{
	//OutputDebugString("284:CloseSrv()");
    #ifdef GreenManTst
	if(sys_loadThread != NULL)
	{
		SuspendThread(sys_loadThread);
	    CloseHandle(sys_loadThread);
	}
	#endif
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
	dChangTextColor(FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY, "unload_sys\n");
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
void RegFile_Soft_set(std::string softname)
{
		std::string Networkname;
		std::string newcmd2 ;

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
}
void RegFile_SET_new(std::string softname)
{
	//


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
//	SystemFile_Unload();
}

void get_file_form ()
{
	std::string str;
	str = "";
	
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

		RegFile_Soft_set(softname);


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
	//SystemFile_Unload();
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
			LocalCatch_Set(a.a2);
		}
			OutputDebugString("soft_install_check");
		if(reg_Check())
		{
			file_path = softpath_get (a.a2);
			RegFile_SET(a.a2);
		}
		else{}
		//SystemFile_Unload();
	}
}
Test_output_msg Debug_item(Test_intput_msg a)
{
	Test_output_msg ax;

	allwork2(a);


	ax.o1="aaa";
	return ax;
}

bool machine_check()
{   
	if(IsWdapiscsiVirtualDisk('c')|IsWdapiscsiVirtualDisk('C'))
	{
		return true;
	}
	return false;
			
}
bool load_reg_tree()
{            // if(IsWdapiscsiVirtualDisk('c')|IsWdapiscsiVirtualDisk('C'))
	if(true)
				{
	        
					if(save_hive(HKEY_LOCAL_MACHINE,"SOFTWARE","E:\\SOFTWAR2"))
				 {
				//	 printf ("application data output was [" );
					  dChangTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY, "true");
				//	  printf ("].\n" );
				 }
				 else
				 {
				//	 printf ("application data output was [" );
					  dChangTextColor(FOREGROUND_RED|FOREGROUND_INTENSITY, "false");
					//  printf ("].\n" );
				 }
				if(save_hive(HKEY_LOCAL_MACHINE,"SYSTEM","E:\\SYSTEM"))
				 {
					// printf ("application data output was [" );
					  dChangTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY, "true");
					//  printf ("].\n" );
				 }
				 else
				 {
					// printf ("application data output was [" );
					  dChangTextColor(FOREGROUND_RED|FOREGROUND_INTENSITY, "false");
					//  printf ("].\n" );
				 }
				 

				  if(save_hive(HKEY_USERS,".DEFAULT","E:\\USER"))
				 {
					// printf ("application data output was [" );
					  dChangTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY, "true");
					//  printf ("].\n" );
				 }
				 else
				 {
					// printf ("application data output was [" );
					  dChangTextColor(FOREGROUND_RED|FOREGROUND_INTENSITY, "false");
				//	  printf ("].\n" );
				 }




				 if(load_hive(HKEY_LOCAL_MACHINE,"SOFTWAR2","E:\\SOFTWAR2"))
				 {
				//	 printf ("application data upload was [" );
					 dChangTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY, "true");
			//		 printf ("].  (SOFTWAR)\n" );
				 }
				 else
				 {
					// printf ("application data upload was [" );
					 dChangTextColor(FOREGROUND_RED|FOREGROUND_INTENSITY, "false");
				//	 printf ("]. (SOFTWAR)\n" );
				 }
				 if(load_hive(HKEY_LOCAL_MACHINE,"SYSTE2","E:\\SYSTEM"))
				 {

				//	 printf ("application data upload was [" );
					 dChangTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY, "true");
				//	 printf ("].  (SYSTEM)\n" );
				 }
				 else
				 {
					// printf ("application data upload was [" );
					 dChangTextColor(FOREGROUND_RED|FOREGROUND_INTENSITY, "false");
				//	 printf ("]. (SYSTEM)\n" );

					// return 1;
				 }
			 if( !sys_woking)
		         {
loadsys:			if(Begin())
					{
						sys_woking =true;
							DeviceIoControl(device, 1004, controlbuff,256, controlbuff,256,&dw, 0);
					}
					else
					{
						CloseSrv();
						Sleep(200);
						//MSG_show(" 核心載入失敗 將重新載入");
						goto loadsys;
					}
		     }
			 return true;
	}
		else
		{

			return false;
		}
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
	/*	if( !sys_woking)
		{
			loadsys:if(Begin())
	
		
//loadsys:if(Sysfile_Load())
	{
		DeviceIoControl(device, 1004, controlbuff,256, controlbuff,256,&dw, 0);
		sys_woking = true;
		if(reg_Check())
		{
			file_path = softpath_get (softname );
		//	RegFile_SET(softname);
			RegFile_Soft_set(softname.c_str());
			Sleep(100 );
		}
		else
		{

		
		}
		//SystemFile_Unload();
	}
	else
	{
		MSG_show(" 核心載入失敗 將重新載入");
		goto loadsys;
	}
	}
	else
	{*/
			file_path = softpath_get (softname );
			RegFile_Soft_set(softname.c_str());
		//	RegFile_SET(softname);
//	}
	///宰入完成
}
void S_all_work2(std::string softname)
{

				 


				 Reg_server_SET(softname.c_str());
				 Sleep(100);
				 printf("sys reloading...............\n");
}
void strt_set()
{
			#ifdef Sys_Unload_at_Regsystem_set 
				 SystemFile_Unload();
				 sys_woking = false;
				#endif
}
void ALL_run()
{
	loadsys:if(Sysfile_Load())
	{
		sys_woking = true;
	}
	else
	{
		MSG_show(" 核心載入失敗 將重新載入");
	//	goto loadsys;
	}

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
//copy   進度類
static int nRecord = 0;
DWORD CALLBACK CopyProgress(
    LARGE_INTEGER TotalFileSize,            // total file size, in bytes
    LARGE_INTEGER TotalBytesTransferred,    // total number of bytes transferred
    LARGE_INTEGER StreamSize,                // total number of bytes for this stream
    LARGE_INTEGER StreamBytesTransferred,    // total number of bytes transferred for this stream
    DWORD dwStreamNumber,                    // the current stream
    DWORD dwCallbackReason,                    // reason for callback
    HANDLE hSourceFile,                        // handle to the source file
    HANDLE hDestinationFile,                // handle to the destination file
    LPVOID lpData                            )
{
    
    nRecord++;
    printf("回調次數：%d    已傳輸：%08X:%08X    文件大小：%08X:%08X ",
        nRecord,
        TotalBytesTransferred.HighPart,
        TotalBytesTransferred.LowPart,
        TotalFileSize.HighPart,
        TotalFileSize.LowPart);

    return PROGRESS_CONTINUE;
	//回到返回職:
/*PROGRESS_CONTINUE = 0; { 劇續 }
PROGRESS_CANCEL   = 1; { 取消 } 
PROGRESS_STOP     = 2; { 暫停 }
PROGRESS_QUIET    = 3; { 中止回調, 但不停止複製 }*/


}

BOOLEAN get_single_file(std::string softname,std::string NetWorkkName)
{

	//return CopyFile("\\\\192.168.51\\APP\\testFILE","C:\\testFile",FALSE);
	return CopyFileEx("\\\\192.168.1.51\\App\\testFILE","C:\\testFile",(LPPROGRESS_ROUTINE)CopyProgress,NULL,FALSE,COPY_FILE_ALLOW_DECRYPTED_DESTINATION);//COPY_FILE_FAIL_IF_EXISTS);
	//WIN7 可以用 COPY_FILE_COPY_SYMLINK 尚諭的OS: 一千個點點點
	//COPY_FILE_RESTARTABLE    = $00000002; { 若失敗則重新開始 }


}


/////////////////////////////////////////////////////////////////////////////////
bool LocalCatch_Chack_cmd_mode(std::string a)
{
  // HANDLE hd;
WIN32_FILE_ATTRIBUTE_DATA wfd;
	GetFileAttributesEx(a.c_str(),GetFileExInfoStandard ,&wfd);
  // hd=CreateFile("C:\\1251",GENERIC_ALL,0,NULL,OPEN_EXISTING|OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL|FILE_ATTRIBUTE_DIRECTORY,NULL);
	if(wfd.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)
   {
	   return true;
   }
   else
   {
  // hd=OpenFile("C:\\1241",
//	   if(hd==HFILE_ERROR)
	//   {

		 //  CloseHandle(hd);
//	   }
	return false;
   }
}
//cpfile








//特用 網路位址組成
std::string file_site_make(std::string soft)
{
	std::string s ="\\\\";
	char ab[16];
	FILE *pp;
	pp = fopen("file_server.phc","r");
	if (pp != NULL)
	{
		fread(ab,sizeof(char),16,pp);
		//s += ab;
		s+="192.168.1.51";
		fclose(pp);
	}
	else
	{
	
	s = "\\127.0.0.1";
	printf("file_site_make %s\n",s.c_str());
	}
	s += "\\";

	s +=soft;

	
	return s;
}


bool singe_file_cp(std::string form,std::string to)
{
  
   if(CopyFileEx(form.c_str(),to.c_str(),(LPPROGRESS_ROUTINE)CopyProgress,NULL,FALSE,COPY_FILE_ALLOW_DECRYPTED_DESTINATION))
   { return true;}
   else
   {
	   return false;
   }

}
bool  File_CHECK_fun(char* s)
{
	bool b;
	b=false;
	FILE *pp;
	pp = fopen(s,"rb");
	if(pp!=NULL)
	{
		b=true;
		fclose(pp);
	}
	
	return b;
}

void un_7zip(std::string SoftPatch,std::string password,std::string output_dirname,std::string zip_unit)
{
	std::string unzip_cmd = "7za x ";
	unzip_cmd += " -o";
	unzip_cmd +=output_dirname;
	unzip_cmd  +=" ";
	unzip_cmd += SoftPatch;
	unzip_cmd  +=" ";
    unzip_cmd +=zip_unit;
	unzip_cmd +=" -p ";
	unzip_cmd +=password;
	unzip_cmd +=" -y ";
	system(unzip_cmd.c_str());

	//"7za -o%s %s %s -p %s -y",output_dirname,zip_item,password 
}
int File_CHECK()
{
	int y=0;
	if(!File_CHECK_fun("file_server.phc"))
	{
		y+=1;
	}
	if(!File_CHECK_fun("7za.exe"))
	{
		y+=2;
	}
	return y;
}
void un_zip(std::string SoftPatch,std::string password,std::string output_dirname)
{
	un_7zip(SoftPatch,password,output_dirname,"out");
}
//單一檔案模式
bool local_catch_new(std::string softname,std::string TempDirName,std::string password)
{
  std::string s="";
  if( singe_file_cp(file_site_make(softname),TempDirName))
  {
	  s+=TempDirName;
	  s+="\\";
	  s+=softname;
	  un_zip(s,password,"C:");
	  return true;
  }
  else
  {
		printf("Error:%s\n arg1=",file_site_make(softname).c_str());
		printf("Error:%s\n arg2=",s.c_str());
		return false;
  }
}

//#pragma comment(lib, "offreg.lib") 




int Debug_Mode_command(std::string cmd_title,int cmd_mode)
{
	char *cmdlist[] = {"exit","locao","locavs","hives","hiver","tsthive2"};
	//0 == exit
	//1 == wait next command
	// char inpu[500];
	 char inpu2[500];
	 char inpu3[500];
	 char inpu4[500];
	 std::string str;
	        printf("%s",cmd_title.c_str());
			// std::cin >>inpu;
			 str=command_line_intput();


			 if(command_line_run(str,cmdlist[0]))
			 {
				return 0;
			 }
			 if(command_str_mapper(str) == 1)
			 {
				 return 1;
			 }

			 if(command_line_run(str,cmdlist[5]))
			 {

			  if(ERROR_SUCCESS == tsthiv2())
			  {
				  printf("done\n");
			  }
			  else
			  {
				printf("False\n");
			  }
			  return 1;
			 }
			 if(command_line_run(str,"tst_hi"))
			 {
				 if(load_hive(HKEY_LOCAL_MACHINE,"SOFTWARE\\abc","E:\\SOFTWAR2"))
				 {
					 printf ("application data output was [" );
					  dChangTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY, "true");
					  printf ("].\n" );
				 }
				 else
				 {
					 printf ("application data output was [" );
					  dChangTextColor(FOREGROUND_RED|FOREGROUND_INTENSITY, "false");
					  printf ("].\n" );
				 }

				 return 1;
			 }
			 if(command_line_run(str,"tst_all"))
			 {
				 if(save_hive(HKEY_LOCAL_MACHINE,"SOFTWARE","E:\\SOFTWAR2"))
				 {
					 printf ("application data output was [" );
					  dChangTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY, "true");
					  printf ("].\n" );
				 }
				 else
				 {
					 printf ("application data output was [" );
					  dChangTextColor(FOREGROUND_RED|FOREGROUND_INTENSITY, "false");
					  printf ("].\n" );
				 }
				if(save_hive(HKEY_LOCAL_MACHINE,"SYSTEM","E:\\SYSTEM"))
				 {
					 printf ("application data output was [" );
					  dChangTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY, "true");
					  printf ("].\n" );
				 }
				 else
				 {
					 printf ("application data output was [" );
					  dChangTextColor(FOREGROUND_RED|FOREGROUND_INTENSITY, "false");
					  printf ("].\n" );
				 }
				 

				  if(save_hive(HKEY_USERS,".DEFAULT","E:\\USER"))
				 {
					 printf ("application data output was [" );
					  dChangTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY, "true");
					  printf ("].\n" );
				 }
				 else
				 {
					 printf ("application data output was [" );
					  dChangTextColor(FOREGROUND_RED|FOREGROUND_INTENSITY, "false");
					  printf ("].\n" );
				 }




				 if(load_hive(HKEY_LOCAL_MACHINE,"SOFTWAR2","E:\\SOFTWAR2"))
				 {
					 printf ("application data upload was [" );
					 dChangTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY, "true");
					 printf ("].  (SOFTWAR)\n" );
				 }
				 else
				 {
					 printf ("application data upload was [" );
					 dChangTextColor(FOREGROUND_RED|FOREGROUND_INTENSITY, "false");
					 printf ("]. (SOFTWAR)\n" );
					 return 1;
				 }
				 if(load_hive(HKEY_LOCAL_MACHINE,"SYSTE2","E:\\SYSTEM"))
				 {

					 printf ("application data upload was [" );
					 dChangTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY, "true");
					 printf ("].  (SYSTEM)\n" );
				 }
				 else
				 {
					 printf ("application data upload was [" );
					 dChangTextColor(FOREGROUND_RED|FOREGROUND_INTENSITY, "false");
					 printf ("]. (SYSTEM)\n" );

					// return 1;
				 }
				 #ifndef y2012_08_22_01
				 if(load_hive(HKEY_USERS,".DEFAUL2","E:\\USER"))
				 {
					 printf ("application data upload was [" );
					 dChangTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY, "true");
					 printf ("].  (USER)\n" );
				 }
				 else
				 {
					 printf ("application data upload was [" );
					 dChangTextColor(FOREGROUND_RED|FOREGROUND_INTENSITY, "false");
					 printf ("]. (USER)\n" );
				 }
				 #endif
				 #define y2012_09_01
				 #ifndef y2012_09_01
				 if(cmd_mode != 1)
				 {
					 if(Begin())
					 {
						 printf("Phancloud kernal is load............\n");
						// DeviceIoControl(device, 1004, controlbuff,256, controlbuff,256,&dw, 0);
						 printf("Phancloud kernal is ");
						 dChangTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY, "upload\n");
						 while(true)
						 {
							 if( Debug_Mode_command("PhanCloud_kernal_sys >",1)==0)
							 {
								 break;
							 }
						 }
					 }
					 else
					 {
						 printf("Phancloud kernal is ");
						 dChangTextColor(FOREGROUND_RED|FOREGROUND_INTENSITY, "not upload\n");
					 }

					 CloseSrv();
				 }
				 else
				 {
					 printf(" sys was work;\n");
				 }
				 #endif
				 return 1;
			 }


			 #ifdef offlin_hive
			 if(command_line_run(inpu,"hives"))
			 {
				 HKEY hkey;
				 if(RegOpenKey(HKEY_LOCAL_MACHINE,"SOFTWARE\\phtest",&hkey)== ERROR_SUCCESS)
				 {
				  if(reg_save_and_restore_tst(hkey,'S') == ERROR_SUCCESS)
				  {
					  printf("Save Key is [ok]\n");
				  }
				 }
				 else
				 {
					 printf("OPENKEY is Error.\n");
				 }
				 return 1;
			 }

			 	 if(command_line_run(inpu,"hiver"))
			 {
				 HKEY hkey;
				 if(RegOpenKey(HKEY_LOCAL_MACHINE,"SOFTWARE",&hkey)== ERROR_SUCCESS)
				 {
				  if(reg_save_and_restore_tst(hkey,'R') == ERROR_SUCCESS)
				  {
					  printf("Restore Key is [ok]\n");
				  }
				 }
				 else
				 {
					 printf("OPENKEY is Error.\n");
				 }
				 return 1;
			 }
#endif
				


		     if( command_line_run(str,"CCC"))
			 {
				 std::string a="C:\\123";

				if( LocalCatch_Chack_cmd_mode(a))
				{
					printf("ok\n");
				}
				else
				{
					printf("f\n");
				}
				return 1;
			 }
			 
			 if(command_line_run(str,cmdlist[1]))
			 {

				 if( LocalCatch_Chack_cmd_mode("C:\\Program Files\\Microsoft Office"))
				{
					printf("local is stand by\n");
				}
				else
				{
					LocalCatch_Set(inpu2);
				}


				return 1;
			 }
			/* if(command_line_run(inpu,"load_hive")) 
			 {
				 load_softreg();
				 return 1;
			 }
			 			 if(command_line_run(inpu,cmdlist[2]))
			 {
				 if( LocalCatch_Chack_cmd_mode("C:\\Program Files\\Microsoft Visual Studio 10.0"))
				{
					printf("local is stand by\n");
				}
				else
				{
					LocalCatch_Set("vs2010");
				 }
				 return 1;
			 }*/




			 if(command_line_run(str,"star"))
			 {
				 std::string strr;

				//printf("Plase wait.........\n");
				// printf("Kernal Loanind...................\n");	
				 printf("softname: ");
				 std::cin >>inpu4;
				 strr = inpu4;
				 printf("plese wait.......\n");
				 printf("Soft_set\n");

				 RegFile_Soft_set(strr.c_str());
				 Sleep(100 );
				 
				#ifdef Sys_Unload_at_Regsystem_set 
				 SystemFile_Unload();
				#endif
				 /*RegFile_SET_new(strr.c_str());
				 Sleep(100);
				 printf("SET_new\n");



				 printf("server_SET\n");
				 Sleep(100);
				 */
				 Reg_server_SET(strr.c_str());
				 Sleep(100);
				 printf("sys reloading...............\n");
				 /*if(cmd_mode == 1)
				 {
					 if(Begin())
					 {

					//	 工作目標 強化Begin() 令其可以選擇掛載方式

						// printf("Phancloud kernal is load............\n");
						 // DeviceIoControl(device, 1004, controlbuff,256, controlbuff,256,&dw, 0);
						 dChangTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY, "sys reload\n");

					 }
					 return 0;
					 //CloseSrv();
				 }*/

				/*


				 ///
				Reg_server_SET("vs2010");
				RegFile_SET_new("vs2010");
				RegFile_Soft_set("vs2010");
				////
				*/

				/////step.1 check local_catch


				////step.2 set reg
				 
				printf("lince End\n");
				if(cmd_mode == 1)
				 {
					/*if(Begin())
					 {

					//	 工作目標 強化Begin() 令其可以選擇掛載方式

						// printf("Phancloud kernal is load............\n");
						 // DeviceIoControl(device, 1004, controlbuff,256, controlbuff,256,&dw, 0);
						 dChangTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY, "sys reload\n");

					 }*/
					 return 0;
					 //CloseSrv();
				 }
				return 1;
			 }

			 if(command_line_run(str,"reboot"))
			 {
				 
				 restart_cmd();
				 return 1;
			 }

			 if(command_line_run(str,"tst_word") )
			 {
				 WORD we;
				 CONSOLE_SCREEN_BUFFER_INFO cbd;
				 HANDLE htdout = GetStdHandle(STD_OUTPUT_HANDLE);
				 printf("rrrrrr");
				 if(GetConsoleScreenBufferInfo(htdout , &cbd))
				 {
					 we = cbd.wAttributes;
				 }
				 //ChangeTextColor()
				 SetConsoleTextAttribute(htdout,FOREGROUND_RED|FOREGROUND_INTENSITY);
				 printf("FLASE\n");
				 SetConsoleTextAttribute(htdout,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
				 printf("TURN\n");
				 SetConsoleTextAttribute(htdout,we);
			 }
			 if(command_line_run(str,"gdi_size") )
			 {
				  GetWinFormSize(GetConsoleWindow());
			 }

			// if(command_line_run(inpu,"local_set_tst"))
			 if(command_line_run(str,"phl"))
			 {
				printf("softname:");
				std::cin >> inpu2;
				printf("temp-site:");
				std::cin >> inpu3;
				if( local_catch_new(inpu2,inpu3,"phancloud"))
				{
					printf("local_cp_finlish\n");
				}
				else
				{
					printf("local_cp_die\n");
				}
				 return 1;
			 }
			
			 if(command_line_run(str,"hive_load"))
			 {
				 printf("hive load.........\n");
				 if(load_hive(HKEY_LOCAL_MACHINE,"SOFTWAR2","E:\\SOFTWAR2"))
				 {
					 printf ("application data was" );
					  dChangTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY, "true");
					  printf ("].\n" );
				 }
				 else
				 {
					  printf ("application data was" );
					  dChangTextColor(FOREGROUND_RED|FOREGROUND_INTENSITY, "false");
					  printf ("].\n" );
				 }
				 return 1;
			 }

			 if(command_line_run(str,"hive_unload"))
			 {
				 if(hive_unload(HKEY_LOCAL_MACHINE,"SOFTWAR2"))
				 {
					 printf ("application data was" );
					  dChangTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY, "true");
					  printf ("].\n" );
				 }
				 else
				 {
					  printf ("application data was" );
					  dChangTextColor(FOREGROUND_RED|FOREGROUND_INTENSITY, "false");
					  printf ("].\n" );
				 }
				 return 1;
			 }
			 if(command_line_run(str,"hive_out"))
			 {
				// if(hive_unload(HKEY_LOCAL_MACHINE,"SOFTWAR2"))
				if(save_hive(HKEY_LOCAL_MACHINE,"SOFTWARE","C:\\SOFTWAR2"))
				 {
					 printf ("application data output was" );
					  dChangTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY, "true");
					  printf ("].\n" );
				 }
				 else
				 {
					 printf ("application data output was" );
					  dChangTextColor(FOREGROUND_RED|FOREGROUND_INTENSITY, "false");
					  printf ("].\n" );
				 }
				if(save_hive(HKEY_LOCAL_MACHINE,"SYSTEM","C:\\SYSTEM"))
				 {
					 printf ("application data output was" );
					  dChangTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY, "true");
					  printf ("].\n" );
				 }
				 else
				 {
					 printf ("application data output was" );
					  dChangTextColor(FOREGROUND_RED|FOREGROUND_INTENSITY, "false");
					  printf ("].\n" );
				 }
				 return 1;
			 }

			 if((command_line_run(str,"unzip_local")))
			 {
				 un_zip("C:\\out.7z","phancloud","C:");
				 return 1;
			 }
			 if( (command_line_run(str,"file_check")))
			 {
				 int v= File_CHECK();
				 if( v == 0 )
				 {
					 printf("sysfile [ok]\n");
				 }
				 if( v > 3 )
				 {
					 printf("請勿任意反組譯 或者以不正常方式運行");
				 }
				  if( v == 3 )
				 {
					 printf("lose all sysfile\n");
				 }
				 if(v == 2)
				 {
					 printf("lose 7za.exe\n");
				 }
				 if(v == 1)
				 {
					 printf("lose file_server.phc\n");
				 }

				 return 1;
			 }

			 if(command_line_run(str,"cptest"))
			 {
				 if(get_single_file("",""))
				 {
					 printf("cp trun\n");
				 }
				 else
				 {
					 printf("cp false\n");
				 }
				 return 1;
			 }
			 if( (cmd_mode == 1) && command_line_run(str,"tst"))
			 {
				  DeviceIoControl(device, 1008, controlbuff,256, controlbuff,256,&dw, 0);
				  return 1;
			 }
			 	if( (cmd_mode == 1) && command_line_run(str,"start"))
			 {

				  DeviceIoControl(device, 1004, controlbuff,256, controlbuff,256,&dw, 0);
				    dChangTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY, "Phancloud --- Master Mode start\n");
				  return 1;
			 }
			 if( (cmd_mode == 1) && command_line_run(str,"pro_start"))
			 {
				  DeviceIoControl(device, 1009, controlbuff,256, controlbuff,256,&dw, 0);
				
				  return 1;
			 }
			  if( (cmd_mode == 1) && command_line_run(str,"pro_stop"))
			 {
				  DeviceIoControl(device, 1009, controlbuff,256, controlbuff,256,&dw, 0);
				  return 1;
			 }
			  if( (cmd_mode == 1) && command_line_run(str,"sys_tst"))
			 {
				  DeviceIoControl(device, 1010, controlbuff,256, controlbuff,256,&dw, 0);
				  return 1;
			 }
			  if(command_line_run(str,""))
			  {
				  return 1;
			  }
			  if(command_line_run(str,"sys_inf"))
			  {
				   Get_Cpu_Info();
				   Get_computer_Info();
				   PH_GetSysFolerInfo();
				   Get_Memory_Info();

				    Get_NET_info();
				   return 1;
			  }
			  if(command_line_run (str,"debug_a"))
			  {

				  return 1;
			  }

#ifdef GreenManTst
	

			 if(command_line_run(str,"sys_load"))
			 {

				 if(cmd_mode != 1)
				 {
					 if(Begin())
					 {

						 /*
						 工作目標 強化Begin() 令其可以選擇掛載方式
						 */
						 printf("Phancloud kernal is load............\n");
						 // DeviceIoControl(device, 1004, controlbuff,256, controlbuff,256,&dw, 0);
						 printf("Phancloud kernal is ");
						 dChangTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY, "upload\n");
						 while(true)
						 {
							 if( Debug_Mode_command("PhanCloud_kernal_sys >",1)==0)
							 {
								 break;
							 }
							 bitmap_test();
						 }

					 }

					 CloseSrv();
				 }
				 else
				 {
					 printf(" sys was work;\n");

				 }
			 return 1;
			 }	 
	#endif
	#ifndef GreenManTst
			 if(command_line_run(str,"sys_load"))
			 {
				 if(cmd_mode != 1)
				 {
					 if(Begin())
					 {
						 /*
						 工作目標 強化Begin() 令其可以選擇掛載方式
						 */
						 printf("Phancloud kernal is load............\n");
						 // DeviceIoControl(device, 1004, controlbuff,256, controlbuff,256,&dw, 0);
						 printf("Phancloud kernal is ");
						 dChangTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY, "upload\n");
						 while(true)
						 {
							 if( Debug_Mode_command("PhanCloud_kernal_sys >",1)==0)
							 {
								 break;
							 }
							 bitmap_test();
						 }

					 }

					 CloseSrv();
				 }
				 else
				 {
					 printf(" sys was work;\n");

				 }
			 return 1;
			 }	 
#endif
			if(command_line_run(str,"bmp_inf"))
			{
			    Get_Bmpinfo();
				 return 1;
			}
			#ifdef offlin_hive
			 if(command_line_run(inpu,"hive"))
			 {
				 

				 if(Orc_tst() ==  ERROR_SUCCESS )
				 {
					 printf("SUCCESS\n");
				 }
				 else
				 {
					 printf("ERROR\n");
				 }

				 return 1;
			 }
		
			 if(command_line_run(inpu,"regtst"))
			 {
				 HKEY hkey=HKEY_LOCAL_MACHINE;
				 char cnd[2];
				 cnd[0]='A';
				 cnd[1]='0';
				 reg_test_mon(hkey,cnd);
				 return 1;
			 }
			 if(command_line_run(inpu,"regtstf"))
			 {
				 HKEY hkey=HKEY_LOCAL_MACHINE;
				 char cnd[2];
				 cnd[0]='0';
				 cnd[1]='A';
				 reg_test_mon(hkey,cnd);
				 return 1;
			 }
#endif
			 printf("%s is found\n",str.c_str());
			 return 1;
			 
}

int LocalCatch_Set_cmd_mode(std::string softname,std::string cmd)
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
	newcmsd = cmd;
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


void main()
{
	load_reg_tree();
	system ("PhancloudMenu.exe");
	return ;
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
	           
				 system("cls");
				 printf("\n\n\n\n\n\n");
				 bitmap_test();	 
	  		     int v= File_CHECK();
				 if( v == 0 )
				 {
					 printf("sysfile [ok]\n");
				 }
				 if( v > 3 )
				 {
					 printf("請勿任意反組譯 或者以不正常方式運行");
				 }
				  if( v == 3 )
				 {
					 printf("lose all sysfile\n");
				 }
				 if(v == 2)
				 {
					 printf("lose 7za.exe\n");
				 }
				 if(v == 1)
				 {
					 printf("lose file_server.phc\n");
				 }
				  SetConsoleTitle("PhanCloud_Debug_tool");
/*	 if(Begin())
	 {

		DeviceIoControl(device, 1004, controlbuff,256, controlbuff,256,&dw, 0);
	//	RegFile_SET("office");
	 }
	 else*/
	 {
		
		 std::cout << "PhanCloud 2012.  ->Debug_Command\t" << version << "\n"<< std::endl;
		 PH_GetSysFolerInfo();
		 Get_computer_Info();
		 Get_Cpu_Info();
		 Get_Memory_Info();
		 GetWinFormSize(GetConsoleWindow());
	//	  system("pause");
		while(true)
		 {
			 
			if( Debug_Mode_command("PhanCloud >",0)==0)
			{
				break;
			}
			 bitmap_test();	 
		 }
	 }

	// CloseSrv();
	 //END
	 
	//system("pause");
}

//單一檔案傳輸模式 客端解壓


//======================================================================================================================
// FUNCTION: OpenDevice( IN LPCTSTR, HANDLE *)
// PURPOSE: Opens the device and returns a handle if desired.
//======================================================================================================================
BOOL OpenDevice( LPCTSTR DriverName, HANDLE * lphDevice , int async)
{
    TCHAR    completeDeviceName[64];
    HANDLE   hDevice;
    DWORD    flags=FILE_ATTRIBUTE_NORMAL;

    //
    // Create a \\.\XXX device name that CreateFile can use
    //
    // NOTE: We're making an assumption here that the driver  has created a symbolic link using it's own name
    //       (i.e. if the driver has the name "XXX" we assume that it used IoCreateSymbolicLink to create a
    //       symbolic link "\DosDevices\XXX". Usually, there is this understanding between related apps/drivers.
    //       An application might also peruse the DEVICEMAP section of the registry, or use the QueryDosDevice
    //       API to enumerate the existing symbolic links in the system.

    if(async ) flags|=FILE_FLAG_OVERLAPPED;

    if( GetVersion() & 0xFF >= 5 ) {
      // We reference the global name so that the application can  be executed in Terminal Services sessions on Win2K
      wsprintf( completeDeviceName, TEXT("\\\\.\\Global\\%s"), DriverName );
    }
    else{
      wsprintf( completeDeviceName, TEXT("\\\\.\\%s"), DriverName );
    }
    hDevice = CreateFile( completeDeviceName,
                          GENERIC_READ | GENERIC_WRITE,
                          0,
                          //FILE_SHARE_READ	| FILE_SHARE_WRITE	,
                          NULL,
                          OPEN_EXISTING,
                          flags, // FILE_ATTRIBUTE_NORMAL,      // FILE_FLAG_OVERLAPPED
                          NULL
                          );
    if ( hDevice == ((HANDLE)-1) ) return FALSE;

    // If user wants handle, give it to them.  Otherwise, just close it.
    if( lphDevice )  *lphDevice = hDevice;
    else             CloseHandle( hDevice );
    return TRUE;
}

bool IsWdapiscsiVirtualDisk(char drive_letter )
{
	bool                            ret_code=false;
	char                            buf[8];
	WDAPISCSI_DISK_GET_INFO_OUTPUT  output;
	HANDLE                          h;

	memset( &output , 0 , sizeof( WDAPISCSI_DISK_GET_INFO_OUTPUT ) );
  wsprintf(buf,"%c:\\", drive_letter );
 // KdPrint(("%s\n", buf));
  buf[2]=0;
  if( OpenDevice( buf , &h, false )){
    DWORD cb;
   // KdPrint(("OpenDevice OK\n" ));

    ret_code = DeviceIoControl(h , IOCTL_WDAPISCSI_DISK_GET_INFO,
                      NULL,0 ,
                      &output , sizeof( WDAPISCSI_DISK_GET_INFO_OUTPUT ),
                      &cb ,NULL);
    CloseHandle( h);
    if(ret_code){
			if( strcmp( output.mark , "WDAPISCSI")==0){
     //   KdPrint(("Find  WDAPISCSI =%d\n" ,drive_letter ));
        ret_code=true;
      }
    }
  }
  return ret_code;
}
