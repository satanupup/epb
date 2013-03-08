
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <Windows.h>
using namespace std;
void read()
{
	size_t result;
	long lSize;
	char * buffer;
	FILE *fp;
	errno_t err;	// 回傳錯誤的數值
	if (( err = fopen_s(&fp,"C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\a.txt", "rb")) != NULL)
	{
	 printf("cant open the file");
	 exit(1);
	}

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

	result = fread (buffer,1,lSize,fp);  

	


	if (result != lSize) 
	{
		fputs ("Reading error",stderr);
		exit (3);
	}
	cout<<"buffer\t"<<buffer<<"\t"<<strlen(buffer)<<"\t"<<result<<endl;

	fclose(fp);
	free(buffer);
}
int main()
{		
	read(); 	   
	system("pause"); 
	return 0;
}