#include "applay_entry.h"
#include "command_str_mapper.h"
int command_str_mapper(std::string str)
{
			 if(command_line_run (str,"reg_show"))
			 {
				// regfile_load("a.txt");
				 regfile_load_tst();
				 return 1;
			 }
			 if(command_line_run(str,"net_tst"))
			 {
			  N_TTlist_ll_ppp();
			  
			  return 1;
			 }
			 if(command_line_run(str,"thread_tst"))
			 {
				 DWORD Id[2];
				 HANDLE hThread[2];
				 //
				char *a ="lokme";
				// DWORD a=1;
				 hThread[0]=CreateThread(NULL,0,ThreadProc_tst,a,0,&Id[0]);
				 return 1;
			 }
			 if(command_line_run(str,"item_tsr"))
			 {
				 tem_filter_tst();
				 return 1;
			 }
			 if(command_line_run(str,"th_tst2"))
			 {
				 DWORD Id[2];
				 HANDLE hThread[2];
				 //
				 char c;
				 char *a ="lokme";
				// DWORD a=1;
				 hThread[0]=CreateThread(NULL,0,ThreadProc_bmap_tst,a,0,&Id[0]);
				
				while(1)
				{
					c = fgetc(stdin);
					if(c=='\n')
					{
						SuspendThread(hThread[0]);
					    CloseHandle(hThread[0]);
					 break;
					}
				}
				 return 1;
			 }
			 if(command_line_run(str,"th_tst3"))
			 {
				 DWORD Id[2];
				 HANDLE hThread[2];
				 //
				 char c;
				char *a ="lokme";
				// DWORD a=1;
				 hThread[0]=CreateThread(NULL,0,ThreadProc_bmap_tst2,a,0,&Id[0]);
				
				while(1)
				{
					c = fgetc(stdin);
					if(c=='\n')
					{
						SuspendThread(hThread[0]);
					    CloseHandle(hThread[0]);
					 break;
					}
				}
				 return 1;
			 }
		     if(command_line_run(str,"cls"))
			 {
				 system("cls");
				 printf("\n\n\n\n\n");
				 bitmap_test();	 
				 return 1;
			 }
			 if(command_line_run(str,"chg_w"))
			 {
				  chang_tst();
				 return 1;
			 }
			 if(command_line_run(str,"cmd"))
			 {
				 system("cmd");
				 return 1;
			 }
			 if(command_line_run(str,"iamroot"))
			 {
				 printf("you will be god.\n");
				 CreateSystemProcess("cmd");

				 printf("you are a human.\n");
				 return 1;
			 }
			 if(command_line_run(str,"bmp_show"))
			 {
				bitmap_test();	 
				 return 1;
			 }

			 if( command_line_run(str,"version") )
			 {
				 printf("version:\t%s\t", version);
				 
				 printf("kernal by shang yu lee \n");
				return 1;
			 }
			 if( command_line_run(str,"howtodo"))
			 {
				 //
				 //set filesystem
				 printf("step.1\t"); printf("\"locao\" or \"localvs\"\n");
				 //set regsystem
				 printf("step.2\t"); printf("star\n");
				 printf("\n");
				 return 1;
			 }
			 if(command_line_run(str,"?"))
			 {
				 printf("exit\nhowtodo\n");
				 printf("version\n");
				 printf("howtodo\n");
				 
				 printf("\"locao\" or \"locavs\"\n");
				 printf("star\n");
				 printf("----------mode----------\n");
				 printf("1. load_sys\n");
				 printf("2. hive_mode" );
				 printf("\n");
				 
				return 1;
			 }
			 if(command_line_run(str,"gdi_tst"))
			 {
				 gdi_tst ();
				 return 1;
			 }
			 return 0;
}
