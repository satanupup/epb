/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef enum { true = 1 ==1 , false =1 ==0} bool;
bool on(char* str)
{
int i;
for(i=0;i<100;++i)
{
if(*(str++)=='\0') 
{ 
return true;
break; 
}
}
return false;

}
char* fget(FILE* po,char* as, char ca)
{ 
char b=' ';
char* b1=&b;

for(;(b=fgetc(po))!=ca;++as)
*as=b; 
return "take\"@\"symbol\n";
}

int main()
{   
char p1[100]=" ", p2[100]=" ";
char a1='\0';
bool s1=false;
char add[]="#";


errno_t err;	
FILE * wf;// = fopen("out.dat", "rb");
FILE * wfp;// = fopen("out.dat", "ab");


printf("Please input a string,i will put it into the \" out.txt\"\n");
printf("\0!!\n");
scanf_s("%s",p1); 
strcat_s(p1,100,add);

if (( err = fopen_s(&wf,"out.dat", "rb")) != 0)
{
printf("cant open the file");
exit(0);
}
fclose(wf);

if (( err = fopen_s(&wfp,"out.dat", "ab")) != 0)
{
printf("cant open the file");
exit(0);
}

fflush(wfp); 
fclose(wfp);
printf("now I will read  the string from the \" out.txt\"\n ");


while(!feof(wf))
{	
fget(wf,p2,'#');
printf("p2=%s\n p4=\n",p2);
fseek(wf,1L,SEEK_END);
if(feof(wf))
return 0;
else 
fseek(wf,-1L,SEEK_END);
}

system("pause");
return 0;
}       */

#include <stdio.h>
#include <stdlib.h>


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
printf("%s",buffer[i]);
buffer[result] = '\0';
printf("\n");



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
/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
bool on(char* str)
{
	for(int i=0;i<100;++i)
	{ if(*(str++)=='\0') { return true; break; }}
	return false;

}
char* fget(FILE* po,char* as, char ca)
{ char b=' ';char* b1=&b;
;
for(;(b=fgetc(po))!=ca;++as)
	*as=b; 
return "take\"@\"symbol\n";
}

int main()
{   char * buffer; long lSize=0; long result=0 ;
char p1[100]=" "; char a1='\0'; bool s1=false; char add[]="#";
printf("Please input a string,i will put it into the \" out.txt\"\n");
scanf("%s",p1); strcat(p1,add);
FILE * wfp = fopen("out.dat", "a");
if (wfp == NULL)
{
	fprintf(stderr, "cannot open file\n");
	exit(0);
}
else { fprintf(wfp,"%s",p1);
fflush(wfp); }
fclose(wfp);
printf("now I will read  the string from the \" out.txt\"\n ");
FILE * wf = fopen("out.dat", "r");
if (wf == NULL)
{
	fprintf(stderr, "I  cannot open file\n");
	exit(0);
}
// obtain file size:
fseek (wf , 0 , SEEK_END);
lSize = ftell (wf);
rewind (wf);

// allocate memory to contain the whole file:
buffer = (char*) malloc (sizeof(char)*lSize+1);
if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}

result = fread (buffer,1,lSize,wf);  

if (result != lSize) {fputs ("Reading error",stderr); exit (3);}
for(int i=0;i<result;i++)
	printf("%c",buffer[i]);
fclose(wf);
for(int q=0;q!=lSize;)
{
	int i=0; char p2[100]=" ";
	for(;(*(buffer+q))!='#';++i,++q)
		p2[i]=buffer[q];
	p2[i]='\000';
	printf("%s\n",p2); 
}
system("pause");
return 0;


}    */