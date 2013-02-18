
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
void main(int argc, char **argv)
{
	
	char a[512]="";	

	sprintf_s(a,"","..\\..\\..\\ConsoleApplication\\Debug\\out");

	char * outfname = "epb.jgp";
	
    ZeroMemory(outfname,512); 

	for(int i=0;i<512;i++)
		 outfname[i] = a[i] ;
	   

	/*
    TCHAR chBuf[512];
    ZeroMemory(chBuf,512);     
    if (GetModuleFileName(NULL,chBuf,512))  //獲取的是當前EXE所在路徑
    {
		wprintf(chBuf);
		printf("\n");
    }*/

	system("pause");

}