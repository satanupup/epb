#include <stdio.h>
#include <stdlib.h>
void EncodeDecode(char *str);
void dynamically_allocated_memory_buffer();

int main()
{	
	dynamically_allocated_memory_buffer();
	system("pause");
	return 0;
}

void dynamically_allocated_memory_buffer()
{
	FILE *fp;	
	long lSize;
	char * buffer;
	size_t result;
	size_t i;
	char data[4096];
	size_t len = 4096;
	//char src[] = "C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\movie.mp4";
//	char dst[] = "C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\movie2.mp4";	
	char src[] = "C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\Hisaishi.mp4";
	char dst[] = "C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\Hisaishi2.mp4";	

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
	//¼g
	if (( err = fopen_s(&fp,dst, "wb")) != 0)	
		 exit(3);
	
	for(i=0;i<len;i++)
	{	
		data[i] = buffer[i];		
	}		
		
	EncodeDecode(data);
//	EncodeDecode(data);
	
	for(i=0;i<len;i++)
	{	
		buffer[i] = data[i];
	}		
	fwrite (buffer , lSize , 1 , fp );
	
	// terminate

	fclose (fp);
	free (buffer);
}


void EncodeDecode(char *str)
{	
	char ch;
	size_t len = 4096, i;
//	if ((len=strlen(str))<=0) return;
//	if (len<=0) return;  
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