#include "..\applay_entry.h"
#include "Registr_Filter_fun.h"
#define chg_Index "chg_Index"
#define cont_n "\n"
typedef struct Mylistlink {
  int item, size;
  wchar_t *s;

  Mylistlink *next;
  Mylistlink *sub;
}Mylistlink ;


//------------------------------------------------------------

typedef struct Rorich			//ACSII 32bit
{
	int a;
	std::string s;
	Rorich *subitem;
	Rorich *next;
	Rorich *last;
}Rorich;

typedef struct RorichW			//UNICODE OR 64bit
{
	int a;
	std::wstring s;

	RorichW *RootDir; //¡ô                      o
	RorichW *subitem; //¡õ						|
						//						o--o--o
	RorichW *next;	  //¡ö						|  |
	RorichW *last;	  //¡÷						o  o--o
}RorichW;

//------------------------------------------------------------------

//------------------------------------------------------------------

typedef struct Rorichnow      //ACSII
{
	int a;
	Rorich *ptr;
	//Rorich *last;
}Rorichnow;

typedef struct RorichnowW    //UNICODE
{
	int a;
	RorichW *ptr;
	//Rorich *last;
}RorichnowW;
//---------------------------------------------------------------------
typedef struct Str_fter_u   //ACSII
{
	int i;
	std::string s;
	//Rorich *last;
}Str_fter_u;

typedef struct Str_fter_uW //UNICODE
{
	int i;
	std::wstring s;
	//Rorich *last;
}Str_fter_uW;

//----------------------------------------------------------------


typedef struct Mymem_Unit
{
	int data_size;
	void* data;
}
Mymem_Unit;
Str_fter_u item_filterA_new(std::string str,char c,Str_fter_u g);			//ACSII
Str_fter_uW item_filterW_new(std::wstring str,wchar_t c,Str_fter_uW g);		//UNICODE