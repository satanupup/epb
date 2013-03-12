#include<iostream>
using namespace std;
#define NULL 0
int main()
{ 
	
	FILE *fp;	
	long lSize;
	char * buffer;
	size_t result;
	size_t i;
	char src[] = "a.txt";
	char dst[] = "b.txt";	

	errno_t err;	

	//¼g
	if (( err = fopen_s(&fp,src, "wb+")) != 0)	
		 exit(3);
	

	if (fp==NULL) {fputs ("File error",stderr); exit (1);}
	
	// allocate memory to contain the whole file:
	buffer = (char*) malloc (sizeof(char)*7);
	if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}
	
	buffer[0] = 'r';
	buffer[1] = 'f';
	buffer[2] = 'i';
	buffer[3] = 'd';
	buffer[4] = '1';
	buffer[5] = '2';	
	buffer[6] = '3';

	fwrite (buffer , 7 , 1 , fp );

	
	fclose (fp);
	free (buffer);
	
	if (( err = fopen_s(&fp,src, "rb")) != 0)	
		exit(1);
	
	
	// obtain file size:
	fseek (fp , 0 , SEEK_END);
	lSize = ftell (fp);
	rewind (fp);

	// allocate memory to contain the whole file:
	buffer = (char*) malloc (sizeof(char)*lSize+1);
	if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}

	result = fread (buffer,1,lSize,fp);  

	if (result != lSize) {fputs ("Reading error",stderr); exit (3);}
	
	for(i=0;i<result;i++)
		cout<<buffer[i];
	buffer[result] = '\0';
	cout<<endl;
		

	
	if (( err = fopen_s(&fp,dst, "wb")) != 0)	
		 exit(1);
	buffer[0] = 'a';
	buffer[1] = 'p';
	buffer[2] = 'p';
	buffer[3] = 'l';
	buffer[4] = 'e';

	fwrite (buffer , 5 , 1 , fp );
	// terminate

	fclose (fp);
	free (buffer);

	
	system("pause");
}

