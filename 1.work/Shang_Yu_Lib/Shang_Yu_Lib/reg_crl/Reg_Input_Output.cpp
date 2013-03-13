#include "Registr_Filter.h"
#define notdatali L""

VOID Reg_entry_point_make(HKEY phk)
{
	//RegSetKeyValue(phk,
}


PHKEY REG_FUN_make(LPCSTR s,LPCSTR s2)
{
	PHKEY pkey,pkey2;
	RegCreateKey(NULL,s,pkey);
	RegCreateKey ( NULL,s2,pkey2);
	return pkey2;
}

//2重寫入 星期五以前必須完成
//下星期依正常運作
PCWSTR WstringoPCSTR(std::wstring str)
{
	return str.c_str();
}


PHKEY REG_NODE_ReCreateW_fun(PHKEY hkey ,RorichW* strt)
{
	PHKEY pkey;
	RegCreateKeyW(*hkey,WstringoPCSTR(strt->s),pkey);
	return pkey;
}

//列舉全ITEM
VOID RorichW_DATA_SET(RorichW* strt ,std::wstring s)
{
	strt->s  = s;
}

VOID  RorichW_Insert_Item(RorichW* last ,RorichW* newitem)
{
	newitem->last = last;
	newitem->next = last->next;
	last->next = newitem;
}

std::wstring RorichW_remake_Wstring_show(RorichW *s,std::wstring subitem)
{

	std::wstring outstr;
	outstr = s->s + subitem;
	return outstr;
}

VOID  RorichW_Delete_Item(RorichW *s)
{
	if(s->last != NULL)
	{
		s->last->next = s->next;
	}
	if(s->next != NULL)
	{
		s->next->last = s->last;
	}
	//KILL SON
	delete s;
}

VOID RorichW_MOVE_Item(RorichW *newup , RorichW *s)
{

}
VOID item_All_show(RorichW* strt)
{
	printf("%S",strt->s);
	if(strt->subitem != NULL )
	{
		item_All_show(strt->subitem);
	}
	if(strt->next !=NULL)
	{
		item_All_show(strt->next);
	}
}

PHKEY REG_NODE_ReCreateW_make(PHKEY hkey ,RorichW* strt)
{
	PHKEY p= REG_NODE_ReCreateW_fun(hkey ,strt);
	if(strt->subitem !=NULL)
	{
		return REG_NODE_ReCreateW_make(p ,strt->subitem);
	}
	return p;
}

 

