#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef const char cchar;
typedef struct book{
	cchar               *name;
	int					num;
	char				*schar;
	float				price;
	struct book			*next;
}book;
book*head=NULL;

int check(char *str);
void EncodeDecode(char *str);
void main()
{	
	char zBuf[100]="ccccccccb";


	book*p=(book*)malloc(sizeof(book));	
	p->schar = "11111";
	p->price = 1.5;	
	printf("%f,Confirm whether digital = %d\t%s\n\n",(float)p->price,(int)check(p->schar),(char*)p->schar);

	
	EncodeDecode(zBuf);	
	printf("%s\n",zBuf);
	
	EncodeDecode(zBuf);	
	printf("%s\n",zBuf);


	if(p != NULL){p = NULL;free(p);	}		
	
	
	system("pause");
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

int check(char *str)
{
	int rrnum=strlen(str);
	int i;
	for(i=0;i<rrnum;i++)
	{
		if((str[i]>'9'||str[i]<'0')&&(str[i]!='.'))
			return 0;
	}
	return 1;
}
