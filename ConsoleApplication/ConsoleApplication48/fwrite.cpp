
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream> 
#include <iomanip> 
using namespace std;


void EncodeDecode(char *str)
{
  char ch;
  int len, i;
  if ((len=strlen(str))<=0) return;
  for (i=0; i<len; i++)
  {
    switch(i%4)
    {
      case 0: case 3:
        str[i]=str[i]^0xDB;
        break;
      default:
        str[i]=str[i]^0xBD;
        break;
    }
  }

  for (i=0; i+3<len; i+=4)
  {
    ch=str[i];
    str[i]=str[i+3];
    str[i+3]=ch;
    ch=str[i+1];
    str[i+1]=str[i+2];
    str[i+2]=ch;
  }
}

void dynamically_allocated_memory_buffer()
{
	FILE *fp;	
	long lSize;
	char * buffer;
	size_t result;
	char src[] = "C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\a.txt";

	errno_t err;	
	if (( err = fopen_s(&fp,src, "rb")) != NULL)	
		 exit(1);

	if (fp==NULL) {fputs ("File error",stderr); exit (1);}

	// obtain file size:
	fseek (fp , 0 , SEEK_END);
	lSize = ftell (fp);
	rewind (fp);
		
  // allocate memory to contain the whole file:
	buffer = (char*) malloc (sizeof(char)*lSize);
	if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}
	
	result = fread (buffer,1,lSize,fp);  
	
  if (result != lSize) {fputs ("Reading error",stderr); exit (3);}
	
	/* the whole file is now loaded in the memory buffer. */	
	for(size_t i=0;i<result;i++)
		cout<< buffer[i] ;
	cout<<endl;

	// terminate
    	
	fclose (fp);
	
  
	free (buffer);
}
void Rewrite_the_buffer()
{	
	FILE *fp; 

	size_t result;
	long lSize;
	char * buffer;
	//char src[] = "C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\player.swf";
	//char dst[] = "C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\player2.swf";
	char src[] = "C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\Hisaishi.mp4";
	char dst[] = "C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\Hisaishi2.mp4";
	
	errno_t err;	// 回傳錯誤的數值 	
	if (( err = fopen_s(&fp,src, "rb")) != NULL)	
		 exit(1);

	if (fp==NULL) {fputs ("File error",stderr); exit (1);}

	// obtain file size:
	fseek (fp , 0 , SEEK_END);
	lSize = ftell (fp);
	rewind (fp);
		
  // allocate memory to contain the whole file:
	buffer = (char*) malloc (sizeof(char)*lSize);
	if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}
	//測試時寫要先
	result = fread (buffer,1,lSize,fp);  
		
	//寫
	//////////////////////////
	FILE *fppp;
	if (( err = fopen_s(&fppp,dst, "wb")) != NULL)	
		 exit(3);
	

	char *cstr = buffer;


	fwrite (cstr , lSize , 1 , fppp );

	fclose(fp);	
	fclose(fppp);
	free(buffer);

	
}
void Rewrite_the_buffer2()
{	
	FILE *fp; 

	size_t result;
	long lSize;
	char * buffer;
	char src[] = "C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\player.swf";
	char dst[] = "C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\player2.swf";
	errno_t err;	// 回傳錯誤的數值 	
	if (( err = fopen_s(&fp,src, "rb")) != NULL)	
		 exit(1);

	if (fp==NULL) {fputs ("File error",stderr); exit (1);}

	// obtain file size:
	fseek (fp , 0 , SEEK_END);
	lSize = ftell (fp);
	rewind (fp);
		
  // allocate memory to contain the whole file:
	buffer = (char*) malloc (sizeof(char)*lSize);
	if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}
	//測試時寫要先
	result = fread (buffer,1,lSize,fp);  
		
	//寫
	//////////////////////////
	FILE *fppp;
	if (( err = fopen_s(&fppp,dst, "wb")) != NULL)	
		 exit(3);
		
	EncodeDecode(buffer);
	char *cstr = buffer;	
	fwrite (cstr , lSize , 1 , fppp );

	fclose(fp);	
	fclose(fppp);
	free(buffer);

	
}

//Encryption 加密
int enc()
{	
	
    char ch;        
	cout << "指令: copy <input> <output>\n" << endl; 

    ifstream fin("C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\player.swf", ios::in | ios::binary); 
    ofstream fout("C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\player2.swf", ios::out | ios::binary); 
	

	fout.seekp(1234,ios::beg); 

    if(!fin) { 
        cout << "檔案讀入失敗" << endl; 
        return 1; 
    } 

    if(!fout) { 
        cout << "檔案輸出失敗" << endl; 
        return 1; 
    } 

    while(!fin.eof()) { 
        fin.get(ch); 
        if(!fin.eof()) 
            fout.put(ch); 
    } 

	char cc[1024];

	sprintf_s(cc,"%s","aa");


	EncodeDecode(cc);

    fout.write((char*) cc, sizeof(cc)); 

    fin.close(); 
    fout.close(); 


	return 0;
}
//Decryption 解密
int dec()
{		
    char ch;        
	cout << "指令: copy <input> <output>\n" << endl; 
	
    //ifstream fin("C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\player2.swf", ios::in | ios::binary); 
    //ofstream fout("C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\player3.swf", ios::out | ios::binary); 
    ifstream fin("C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\Hisaishi2.mp4", ios::in | ios::binary); 
    ofstream fout("C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\Hisaishi3.mp4", ios::out | ios::binary); 
	
	fin.seekg(1234,ios::beg); 

    if(!fin) { 
        cout << "檔案讀入失敗" << endl; 
        return 1; 
    } 

    if(!fout) { 
        cout << "檔案輸出失敗" << endl; 
        return 1; 
    } 

    while(!fin.eof()) { 
        fin.get(ch); 
        if(!fin.eof()) 
            fout.put(ch); 
    } 

	char cc[1024];

	sprintf_s(cc,"%s","aa");


	EncodeDecode(cc);

    fout.write((char*) cc, sizeof(cc)); 

    fin.close(); 
    fout.close(); 

	return 0;
}

int main()
{	
	bool quit = false;
	int choice;
	while(quit == false)
	{
		cout<<"please input: (0)quit\t(1)dynamically_allocated_memory_buffer\t(2)Rewrite_the_buffer\t(3)Rewrite_the_buffer2\t(4)enc\t(5)dec\t"<<endl;
		cin>>choice;
		switch(choice)
		{
		case 0:
			quit = true;
			break;
		case 1:	
			dynamically_allocated_memory_buffer();
			break;
		case 2:
			Rewrite_the_buffer();
			break;
		case 3:
			Rewrite_the_buffer2();
			break;
		case 4:	
			enc();
			break;
		case 5:
			dec();
			break;
		default:
			cout<<"please input 1,2,3,4,5 or 0"<<endl;
			break;
		}
	}

	system("pause");
 return 0;
}
