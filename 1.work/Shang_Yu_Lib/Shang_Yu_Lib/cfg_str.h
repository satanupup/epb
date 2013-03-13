#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include <hash_map>
#include <time.h>
#include <Windows.h>
using namespace std;
/*systemget*/
#include <tlhelp32.h>
#include <shlwapi.h>
#include <aclapi.h>
/*systemget*/
#define Mapper_Index_filename  "flist"
#define Mapper_SerIndx_filename "serlist"

#define Reg_user_add_output		"output\\HKEY_USERS(inst).reg"		   //比對輸出的(USER)REG位址(新增)
#define Reg_user_chg_output		"output\\HKEY_USERS(chg).reg"		   //比對輸出的(USER)REG位址(變動)
#define Reg_machine_add_output	"output\\HKEY_LOCAL_MACHINE(inst).reg" //比對輸出的(Machine)REG位址(新增)
#define Reg_machine_chg_output  "output\\HKEY_LOCAL_MACHINE(chg).reg"  //比對輸出的(Machine)REG位址(變動)
#define Reg_Server_add_output	"output\\Server(inst).reg"		   //比對輸出的(服務)REG位址(新增)
#define Reg_Server_chg_output	"output\\Server(chg).reg"		   //比對輸出的(服務)REG位址(變動)


#define Reg_machine_before_file "bef\\HKEY_LOCAL_MACHINE\\SOFTWARE"	 //安裝前的(Machine)REG位址
#define Reg_machine_affter_file "affter\\HKEY_LOCAL_MACHINE\\SOFTWARE" //安裝後的(Machine)REG位址

#define Reg_user_before_file	"bef\\HKEY_USERS.reg"		     //安裝前的(USER)REG位址
#define Reg_user_affter_file	"affter\\HKEY_USERS.reg"         //安裝後的(USER)REG位址
#define Reg_server_before_file	"bef\\Services"
#define Reg_server_affter_file	"affter\\Services"


#define Reg_machine_software "HKEY_LOCAL_MACHINE\\SOFTWARE"
#define Reg_machine_system_setup_allowstart       "HKEY_LOCAL_MACHINE\\SYSTEM\\setup\\AllowStart"
#define Reg_machine_system_controlset00X_Control  "HKEY_LOCAL_MACHINE\\SYSTEM\\ControlSet00%d\\Control"
#define Reg_machine_system_controlset00X_Enum     "HKEY_LOCAL_MACHINE\\SYSTEM\\ControlSet00%d\\Enum"
#define Reg_machine_system_controlset00X_Enum_max 44


#define Reg_machine_system_controlset00X_Services "HKEY_LOCAL_MACHINE\\SYSTEM\\ControlSet00%d\\Services"
#define Reg_machine_system_controlset00X_subname  "SYSTEM\\ControlSet00%d"
#define Reg_machine_system_controlset00X_name	  "HKEY_LOCAL_MACHINE\\SYSTEM\\ControlSet00%d"
#define Reg_machine_system_controlsetXXX_Control_before_file  "bef\\HKEY_LOCAL_MACHINE\\SYSTEM\\ControlSet%d\\Control"
#define Reg_machine_system_controlsetXXX_Enum_before_file     "bef\\HKEY_LOCAL_MACHINE\\SYSTEM\\ControlSet%d\\Enum"
#define Reg_machine_system_controlsetXXX_Services_before_file "bef\\HKEY_LOCAL_MACHINE\\SYSTEM\\ControlSet%d\\Services"
#define Reg_machine_system_controlset00X_Control_before_file  "bef\\HKEY_LOCAL_MACHINE\\SYSTEM\\ControlSet00%d\\Control"
#define Reg_machine_system_controlset00X_Enum_before_file     "bef\\HKEY_LOCAL_MACHINE\\SYSTEM\\ControlSet00%d\\Enum"
#define Reg_machine_system_controlset00X_Services_before_file "bef\\HKEY_LOCAL_MACHINE\\SYSTEM\\ControlSet00%d\\Services"

#define Reg_out_ControlSeti "output\\ControlSet_%c_%d_i"
#define Reg_out_ControlSetc "output\\ControlSet_%c_%d_c"
#define Reg_machine_system_controlsetXXX_Control_affter_file  "affter\\HKEY_LOCAL_MACHINE\\SYSTEM\\ControlSet%d\\Control"
#define Reg_machine_system_controlsetXXX_Enum_affter_file 	  "affter\\HKEY_LOCAL_MACHINE\\SYSTEM\\ControlSet%d\\Enum"
#define Reg_machine_system_controlsetXXX_Services_affter_file "affter\\HKEY_LOCAL_MACHINE\\SYSTEM\\ControlSet%d\\Services"
#define Reg_machine_system_controlset00X_Control_affter_file  "affter\\HKEY_LOCAL_MACHINE\\SYSTEM\\ControlSet00%d\\Control"
#define Reg_machine_system_controlset00X_Enum_affter_file 	  "affter\\HKEY_LOCAL_MACHINE\\SYSTEM\\ControlSet00%d\\Enum"
#define Reg_machine_system_controlset00X_Services_affter_file "affter\\HKEY_LOCAL_MACHINE\\SYSTEM\\ControlSet00%d\\Services"

#define File_output_zip_name	"P:\\out.7z"
#define File_output_password	"phancloud"

#define Config_to_UI_softname

#define Cmdline_spase			" "



#define XML_INFO_title "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
#define StartMeun_Xml_Name       "Start_Meun.xml"			   //start_bar表單輸出			
#define LinkTablrString		 "c:\\Documents and Settings\\All Users\\「開始」功能表"
#define Err_File_Indx_R "Error:Can't read file index tempfile\n"   //未取得檔案分析索引
void win_comm_RUN();
void before_callback();



DWORD Show_File_time(LPSTR patch);

//dialg
static HWND entry1 = NULL;
static HWND entry2 = NULL;
static HWND entry3 = NULL;
static HWND Lable2 = NULL;
static HWND Lable1 = NULL;

/*
typedef pair<string, FILETIME > fsPair;
hash_map<string, FILETIME > fmapA;  //  Deleted!
hash_map<string, FILETIME > fmapB1; //  Inserted!
hash_map<string, FILETIME > fmapB2; //  Updated!
hash_map<string, FILETIME >::const_iterator fmapA_ptr, fmapB_ptr,fmap_ptr;
hash_map<string, FILETIME >::size_type fmap_n;*/





