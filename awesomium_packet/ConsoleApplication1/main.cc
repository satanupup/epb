#include "../common/application.h"
#include "../common/view.h"
#include "../common/method_dispatcher.h"
#include <Awesomium/WebCore.h>
#include <Awesomium/DataPak.h>
#include <Awesomium/STLHelpers.h>


#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <Windows.h>
#endif

#pragma comment(lib, "awesomium.lib") 

using namespace Awesomium;


typedef struct {
int product_num;
char product_name[80];
char product_type[80];
double product_price;
} product_t;


void pakto2();
void EncodeDecode(char *str);

int main() {
	unsigned short cc = 0;
	WriteDataPak(ToWebString("abc.epb"),ToWebString("C:\\c++\\ConsoleApplication1\\Release\\cca\\"),ToWebString(""),cc);
	
	pakto2();

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



void pakto2()
{
	
	
FILE *inventoryp;
FILE *binaryp;
int input_status;
    product_t x;

inventoryp = fopen("catalog.txt", "r");
binaryp = fopen("product_list.bin", "wb");

while (input_status != EOF) {

memset(&x,0,sizeof(product_t));


input_status = fscanf(inventoryp, "%d", &x.product_num);
input_status = fscanf(inventoryp, "%s", x.product_name);
input_status = fscanf(inventoryp, "%s", x.product_type);
input_status = fscanf(inventoryp, "%lf", &x.product_price);

fwrite(&x, sizeof(product_t), 1, binaryp);

}

fclose(inventoryp);
fclose(binaryp);
    


}