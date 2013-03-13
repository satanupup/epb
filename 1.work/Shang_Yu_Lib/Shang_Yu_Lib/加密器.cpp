#include <stdlib.h>
#include <stdio.h>
#include "phc_tst.h"
#define DNA1_size 52
#define DNA2_size 10

char outputpool[240]="\0";
int testpool [100];
char test[100]="123456789012345678901234567890123456789012345678901234567890";
	int table_DNA1[DNA1_size];
	int table_DNA2[DNA2_size];

void set_table(int* a,int* b,int asize,int bsize)
{
	int i,v;
	for (i=0;i<asize;i++)
	{
		a[i]=i;
	}
	for (v=1;v<bsize+1;v++)
	{
		b[v]=v;
		a[2*v]+=v+1;
	}

}


///使用者自訂加密模快未連結//////////
typedef char* (*OP)(int,int,char*,char*);

void User_lock(OP p,int bufsize,int outputbufsize,char* intput_buf,char* output_buf)
{
	p(bufsize,outputbufsize,intput_buf,output_buf);
}
void User_unlock(OP p,int bufsize,int outputbufsize,char* intput_buf,char* output_buf)
{
	p(bufsize,outputbufsize,intput_buf,output_buf);
}
/////////////////////////////

void loadtable()
{
 	set_table(table_DNA1,table_DNA2,DNA1_size,DNA2_size);	
}



void LockVarW(char *A,int size)
{
	int a;
	int i;
	//loadtable();
	for (i=0;i<size;i++)
	{
		
		a=i;
		if(i>DNA1_size)
		{
			a=i%DNA1_size;
		}
		testpool[i]=A[i]+table_DNA1[a];
		A[i]=testpool[i];
	}
	//return outputpool;
}
char* LockVarR(char *A,int size)
{
	int a;
	int i=0;
	//loadtable();
	for (i=0;i<size;i++)
	{
		
		a=i;
		if(i>DNA1_size)
		{
			a=i%DNA1_size;
		}
		//testpool[i]=A[i]+table_DNA1[a];
		A[i]-=table_DNA1[a];
	}
	return outputpool;
}
void SetVar(char *A,int size)
{
	int a=0;
	int i=0;	
	for (i;i<size;i++)
	{
		
		a=i;
		if(i>DNA1_size)
		{
			a=i%DNA1_size;
		}
		outputpool[i]=testpool[i]-table_DNA1[a];

	}
	
}
void GetVar(char *A,int size)
{
	//loadtable();
	int a=0;
	int i=0;	
	for (i;i<size;i++)
	{
		
		a=i;
		if(i>DNA1_size)
		{
			a=i%DNA1_size;
		}
		outputpool[i]=testpool[i]-table_DNA1[a];

	}
}

char* test_serect()
{
	loadtable();
	SetVar(test,100);
	GetVar(outputpool,100);
	return outputpool;
}