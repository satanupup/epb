#include <iostream>
#include <thread>
#include <string>
#include <Windows.h>
using namespace std; 
 
static int i=0;
static char buf[64];
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

void hello_world() 
{	
	sprintf_s(buf,"%s%d","cd",i++);	
	EncodeDecode(buf);
	cout << " " <<buf<< endl;
	
	EncodeDecode(buf);
	cout << " " <<buf<< endl;
}
void hello_world2() 
{
	sprintf_s(buf,"%s%d","cd",i--);	
	EncodeDecode(buf);
	cout << " " <<buf<< endl;
	
	EncodeDecode(buf);
	cout << " " <<buf<< endl;
}
int main()
{
	while(1)
	{
		thread my_thread(&hello_world);  
		my_thread.join();
		Sleep(100);
		cout<<"------------------"<<endl;
		thread my_thread2(&hello_world2);  
		my_thread2.join();
		i++;
	}
	

		system("pause");
	return 0;
}