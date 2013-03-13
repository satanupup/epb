//=========
// encode.c
//=========

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>

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

int main()
{
   char x[]="12345ABCDEFG!@#$%^&*()";

   printf("1) %s\n", x);

   EncodeDecode(x);

   printf("2) %s\n", x);

   EncodeDecode(x);

   printf("3) %s\n", x);

   return 0;
}
