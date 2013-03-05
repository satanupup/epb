#include <stdio.h>
#include <stdlib.h>

void main()
{
	FILE *fp;	
	long lSize;
	char * buffer;
	size_t result;
	size_t i;
	char ch1[10];
	char src[] = "C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\a.txt";

	errno_t err;	
	if (( err = fopen_s(&fp,src, "rb")) != 0)	
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
  for(i =0;i<result;i++)
	  ch1[i] = buffer[i];
  
	ch1[result+1] = '\0';
	printf(ch1);
		
	// terminate
    	
	fclose (fp);  
	free (buffer);
	
	system("pause");
}