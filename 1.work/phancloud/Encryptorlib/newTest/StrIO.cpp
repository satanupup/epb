#ifdef linux

#else
#include "ScrectKey\\SCardAPI.h"
#endif
#include "phc_tst.h"



//interface
#define Interface_SDCARD 1
#define Interface_NETWORK  2
#define Interface_LOCAL    3

//


class Media_IO
{
	BYTE ret;
public: void open(int media)
	{
		if(media == Interface_SDCARD)
		{
			
			 ret = SC_Open();
		}
	}
public:	void Set_data_to_media(int startbit,int maxlen,unsigned char* byData, int MEDIA)
	{
		if(MEDIA == Interface_SDCARD)
		{
			 ret = SC_Write(startbit, byData, maxlen);
		}
	}
public: void get_data_form_media(int startbit,int maxlen,unsigned char* byData, int MEDIA)
	{
		if(MEDIA == Interface_SDCARD)
		{
		  ret = SC_Read(startbit, byData, maxlen);
		}
	}
public:	void close(int media)
	{	
		if(media == Interface_SDCARD)
		{
		 ret = SC_Close();
		}
	}
};
void NETWORK_READ(int startbit,int size,char* buff)
{

	Media_IO test;
	test.open(Interface_NETWORK);
	
	test.get_data_form_media(startbit,size,(BYTE*)buff,Interface_NETWORK);
	LockVarR(buff,size);
	test.close(Interface_NETWORK);

}
void NETWORK_WRITE(int startbit,int size,char* buff)
{

	Media_IO test;
	test.open(Interface_NETWORK);
	LockVarW(buff,size);
	test.Set_data_to_media(startbit,size,(BYTE*)buff,Interface_NETWORK);
	
	test.close(Interface_NETWORK);

}


void SDCARD_READ_tst(int startbit,int size,char* buff)
{

	Media_IO test;
	test.open(Interface_SDCARD);
	
	test.get_data_form_media(startbit,size,(BYTE*)buff,Interface_SDCARD);
	test.close(Interface_SDCARD);

}
void SDCARD_READ(int startbit,int size,char* buff)
{

	Media_IO test;
	test.open(Interface_SDCARD);
	
	test.get_data_form_media(startbit,size,(BYTE*)buff,Interface_SDCARD);
	LockVarR(buff,size);
	test.close(Interface_SDCARD);

}
void SDCARD_WRITE(int startbit,int size,char* buff)
{

	Media_IO test;
	test.open(Interface_SDCARD);
	LockVarW(buff,size);
	test.Set_data_to_media(startbit,size,(BYTE*)buff,Interface_SDCARD);
	
	test.close(Interface_SDCARD);

}

#include "PhcSCardAPI.h"

int Pool_size=POOL_size;
char pool[POOL_size]="";
int Pool_Load(int startbyte ,int userbufsize,char *userbuf,char *pool_buff)
{
	for(int i=0;i<userbufsize;i++)
	{
		userbuf[i]= pool_buff[i+startbyte];
	}
}
int Pool_Load_safe(int startbyte ,int userbufsize,char *userbuf)
{
	
	for(int i=0;i<userbufsize;i++)
	{
		if((i+startbyte)>=Pool_size)
		{
			return 1;
		}
		else
		{
			userbuf[i]= pool[i+startbyte];
			
		}
	}
	return 0;
}
int Pool_Save_safe(int startbyte ,int userbufsize,char *userbuf)
{
	
	for(int i=0;i<userbufsize;i++)
	{
		if((i+startbyte)>=Pool_size)
		{
			return 1;
		}
		else
		{
			 pool[i+startbyte] = userbuf[i];
			
		}
	}
	return 0;
}
char* Show_pool(int LINE)
{
	char temp[StringLen];
	for(int i=0;i<StringLen;i++)
	{
		temp[i]=pool[i+(LINE*StringLen)];
	}
	return temp;
}
int* Show_pool_int(int LINE)
{
	char temp[StringLen];
	for(int i=0;i<StringLen;i++)
	{
		temp[i]=pool[i+(LINE*StringLen)];
	}
	return (int*)temp;
}

int SCard_Load(int StartLine, int Lines)
{
	char temp[100];

	loadtable();
	for (int num = 0;num < Lines;num++)
	{
		SDCARD_READ(StartLine*StringLen+num*StringLen,StringLen,temp);
		for(int i=0;i<StringLen;i++)
		{
			pool[i+StartLine*StringLen+num*StringLen]=temp[i];
		}
	}
	return 0;
}

int SCard_Save(int StartLine, int Lines)
{
	char temp[100];
	loadtable();
		for (int num = 0;num < Lines;num++)
	{
	for(int i=0;i<StringLen;i++)
	{
			temp[i]=pool[i+StartLine*StringLen+num*StringLen];
	}
	SDCARD_WRITE((StartLine*StringLen)+num*StringLen,StringLen,temp);
	}
	return 0;
}

int SCard_GetString(int Line, char *Str)
{
	loadtable();
	 return Pool_Load_safe((Line*StringLen),StringLen,Str);
}
int SCard_SetString(int Line, char *Str)
{
	loadtable();
	return Pool_Save_safe((Line*StringLen),StringLen,Str);
}

int SCard_GetIntArr(int Line, int *IntArr)
{
	loadtable();
	return Pool_Load_safe((Line*StringLen),StringLen,(char*)IntArr);
}
int SCard_SetIntArr(int Line, int *IntArr)
{
	loadtable();
	return Pool_Save_safe((Line*StringLen),StringLen,(char*)IntArr);
	
}






void SDCARD_LOCK_IO_TST(int startbit,int size,char* buff,char* buff2)
{
	loadtable();
	SDCARD_WRITE(startbit,size,buff);
	SDCARD_READ(startbit,size,buff2);
}