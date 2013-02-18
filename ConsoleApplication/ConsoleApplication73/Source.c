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

void main()
{	
	book*p=(book*)malloc(sizeof(book));	
	p->schar = "11111";
	p->price = 1.5;	
	printf("%f,Confirm whether digital = %d\t%s\n\n",(float)p->price,(int)check(p->schar),(char*)p->schar);
	
	if(p != NULL){p = NULL;free(p);	}		
	
	
	system("pause");
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
