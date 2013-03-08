#include <ctime>
#include <iostream>
#include <string>
//#include "Header.h"

void EncodeDecode(char *str);
typedef struct point2d {
    int x;
    int y;
}point2d;
typedef struct point3d {
	int x;
	int y;
	int z;
}point3d;

typedef struct cstr{
	char *ch1;
}cstr;
typedef struct line{
	point2d start;
	point2d end;
}line;
typedef struct coordinate {	
	struct cstr c1;
	struct line l1;
	struct point2d p2d;
	struct point3d p3d;
}coordinate;

typedef struct HttpQueue {
    char *name;
}HttpQueue;

static void startFileHandler(HttpQueue *q)
{
	//q->name = "cchuuuuuue\n";
	//char*q = "apple";
	//std::cout<<*(q); //a
	char ch=0;
  int len=0, i=0;
  if ((len=strlen(q->name))<=0) return;
  
 for (i=0; i<len; i++)
  {
    switch(i%4)
    {
      case 0: case 3:
		  printf("0~3\t%d,\t%d\n",len,i);
        *(q->name+i) = *(q->name+i)^0xDB;
        break;
      default:
		  printf("\t%d,\t%d\n",len,i);
        *(q->name+i) = *(q->name+i)^ 0xDB;
        break;
    }
  }/*  

  for (i=0; i+3<len; i+=4)
  {
    ch=q->name[i];
    q->name[i]=q->name[i+3];
    q->name[i+3]=ch;
    ch=q->name[i+1];
    q->name[i+1]=q->name[i+2];
    q->name[i+2]=ch;
  }
  */
}
typedef struct list{
	char *name;
	struct list *nextPtr;
}list;


typedef struct HeadNode{
	HeadNode *head;
}HeadNode;
void abc(HttpQueue *str)
{
	str->name = "che";
//  str->name[i]=str->name[i]^0xDB;
}
struct stu
{
	int num;
	char sex;
	float score;
}pupil[5]={
	{101,'M',45.8},
	{102,'M',62.5},
	{103,'F',92.5},
	{104,'F',87.6},
	{105,'M',58.8},
};
int main()
{	
	system("pause");
        return 0;
}

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