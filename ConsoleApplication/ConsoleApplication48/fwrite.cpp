
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <Windows.h>
using namespace std;

void save()
{	
	FILE *fp; 
	size_t result;
	size_t result2;
	long lSize;
	char * buffer;
	char ch;
	char src[] = "C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\player.swf";
	char dst[] = "C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\player3.swf";
	errno_t err;	// 回傳錯誤的數值 	
	if (( err = fopen_s(&fp,src, "rb")) != NULL)	
		 exit(1);
	
	// obtain file size:
	fseek (fp , 0 , SEEK_END);
	lSize = ftell (fp);
	rewind (fp);
		
  // allocate memory to contain the whole file:
	buffer = (char*) malloc (sizeof(char)*lSize);

	if (buffer == NULL) {
		fputs ("Memory error",stderr); 
		exit (2);
	}
	//測試時寫要先
	//寫
	//////////////////////////
	FILE *fppp;
	errno_t errrr;	// 回傳錯誤的數值 
	if (( errrr = fopen_s(&fppp,dst, "wb")) != NULL)	
		 exit(3);

	while(fread(&ch,sizeof(ch),1,fp) != 0)    
		fwrite(&ch,sizeof(ch),1,fppp);

	///讀
	///////////////////////////////////////////////////////////
	result = fread (buffer,1,lSize,fp);  
	cout<<result<<"\t"<<lSize<<endl;
	/*
	if (result != lSize) 
	{
		fputs ("Reading error",stderr);
		exit (3);
	}
	
	FILE *fpp; 		
	errno_t errr;	// 回傳錯誤的數值 
	
	if (( errr = fopen_s(&fpp,"C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\player2.swf", "wb")) != NULL)	
	{
	 printf("cant open the file");	 
	 exit(1);
	}
		
	int ir;

	std::string str = "";
	str += buffer;
	std::string str2 = str.substr (0,result); 
	
	str2 +="elppa";

	char *cstr = new char[str2.length() + 1];
	strcpy_s(cstr, str2.length() + 1,str2.c_str());
	
	fwrite (cstr , str2.length() , 1 , fpp );
	
	/////////////

		


	////////////////////////////
	delete [] cstr;
	fclose(fppp);
	fclose(fpp);
	fclose(fp);	
	free(buffer);
	*/
}

int main()
{
	save();  
	system("pause");
 return 0;
}
