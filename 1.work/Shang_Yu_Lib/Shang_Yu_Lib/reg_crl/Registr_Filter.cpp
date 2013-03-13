#include "Registr_Filter.h"
/* BOOLEAN Create_Key_Entry(std::wstring ws)
 {
	 //建立進入點
	 //RegCreateKey(
	 //建立節點
	 //形成資料對應
	 //節點測試
	 //轉向

	 

	 return FALSE;
 }*/

VOID item_filter_enrty(std::string s[] ,int s_size);


Mylistlink  *MylistlinkNew() {
  Mylistlink *str = (Mylistlink*)malloc(sizeof(Mylistlink));
  str->s = (wchar_t*)malloc(sizeof(wchar_t));
  str->s[0] = L'\0';
  str->item = 0;
  str->size = sizeof(wchar_t);
  str->next = NULL;
  return str;
}
BOOLEAN MylistlinkAppend(Mylistlink a,Mylistlink b )
{
	if (a.next == NULL)
	{
		a.next = &b;
	}
	return FALSE;

}
Mylistlink  *MylistlinkMapper(Mylistlink *mylistlink, wchar_t *s,int size)
{
	Mylistlink *Mypper;

	Mypper= mylistlink;
	while(true)
	{
		if(memcmp(Mypper->s,s,size*sizeof(wchar_t)) == 0)
		{
			return Mypper;
		}

		else if(mylistlink->next != NULL)
		{
			Mypper = mylistlink->next;
		}
		else
		{
			break;
		}
	}
	return NULL;
}



 BOOLEAN outIndexFile(char* filename,std::wstring str)
 {
	FILE *fp;
	printf("%S\n",str.c_str());
	fp =fopen(filename,"ab");
	if(fp != NULL)
	{
		fwrite(str.c_str(),sizeof(wchar_t),(str.length()),fp);
		fwrite(L"\n",sizeof(wchar_t),1,fp);
		fclose(fp);
		return TRUE;
	}
	 return FALSE;


 }

  BOOLEAN reg_item_load()
 {
	 
	 return FALSE;
 }
 BOOLEAN Output_Index(char* filename)
 {
	// fopen
	 return FALSE;
 }


//malloc(newSize)
BOOLEAN find_worda(wchar_t c, FILE* p)
{
	wchar_t temp;
	BOOLEAN  a= FALSE;
	while(true)
	{
		temp= getwc(p);
		if(temp!=WEOF)
		{
			if(temp == c)
			{
			//	printf("\n");
				a= TRUE;
				break;
			}
		}
		else
		{
			//printf("d\n");
			break;
			//return a;
		}
	}
	return a;
}


/*BOOLEAN find_word_fiter(wchar_t c, FILE* p)
{

	std::wstring str = L"";
	wchar_t temp;
	BOOLEAN  a= FALSE;
	while(true)
	{
		temp= getwc(p);
		if(temp!=WEOF)
		{
			if(temp == c)
			{
			//	printf("\n");
				a= TRUE;
				break;
			}
			//printf("%c",temp);
		

			str +=  temp;
		}
		else
		{
			printf("d");
			break;
		//	return a;
		}

	}
	//char* et ="aaaaaaa";
	// ArrayAdd(&array1,(void*)((str.c_str())));
	outIndexFile(chg_Index,str);
	return a;
}*/
BOOLEAN find_word(wchar_t c, FILE* p)
{

	std::wstring str = L"";
	wchar_t temp;
	BOOLEAN  a= FALSE;
	while(true)
	{
		temp= getwc(p);
		if(temp!=WEOF)
		{
			if(temp == c)
			{
			//	printf("\n");
				a= TRUE;
				break;
			}
			//printf("%c",temp);
		

			str +=  temp;
		}
		else
		{
			printf("d");
			break;
		//	return a;
		}

	}
	//char* et ="aaaaaaa";
	// ArrayAdd(&array1,(void*)((str.c_str())));
	outIndexFile(chg_Index,str);

	return a;
}

BOOLEAN regfile_load(char* filename)
{

	int i=0;
	FILE *fp;
	fp = fopen(filename,"rb");

	if(fp == NULL)
	{
		return FALSE;
	}


	while (true)
	{
		if(fp == NULL)
		{
				return FALSE;
		}
		if(i==0)
		{
			if(find_worda(L'[',fp ))
			{
				i=1;
			}
			else
			{
				i=3;
			}
		}
		else if(i==1)
		{
			if(find_word(L']',fp ))
			{
				i=0;
			}
			else
			{
				i=3;
			}

		}
		else
		{
			break;
		}
	}
	fclose(fp);
	return TRUE;
}

void PH_Add_key(HKEY hkey,HKEY newhkey, LPSTR keyname)
{
	//建立 進入點
	HKEY phkey;

	//RegCreateKey(
	RegCreateKey(hkey,keyname,&phkey);

	//建立 轉移點
	//RegSetKeyValue(phkey,keyname,
	//輸入資料到轉儀點
}
void PH_reg_index_make()
{

}





BOOLEAN regfile_load_tst()
{
	FILE *fp;
	fp=fopen(chg_Index,"wb");
	fclose(fp);


	regfile_load("ControlSet_c_1_i");

	regfile_load("ControlSet_e_1_i");


	regfile_load("ControlSet_e_2_i");
	regfile_load("ControlSet_c_2_i");
	printf ("---------------------Services------------------------");
	
	regfile_load("ControlSet_s_2_i");
	regfile_load("ControlSet_s_1_i");

	//all install show
	return TRUE;
 }



int item_filterA(std::string str,char c,int startmove)
{
	std::string item="";
	int point= startmove;
	while (true)
	{
		if((point) >= str.length()  )
		{
			printf (item.c_str());
			break;
		}
		if(str.c_str()[point] == c)
		{
			point++;
			printf (item.c_str());
			return (point); 
		}
		item+=str.c_str()[point];
		point++;
	}
	
	return (point);
}







int item_filterW(std::wstring str, wchar_t c,int startmove,Rorich a)
{
	std::wstring item=L"";
	int point=0;
	while (true)
	{
		if(point >= str.length())
		{
			printf ("%S",item.c_str());
			break;
		}
		if(str.c_str()[point+startmove] == c)
		{
			point++;
			printf ("%S",item.c_str());
			return point; 
		}
		item+=c;
		point++;
	}
	
	return point ;
}


VOID rorich_new(Rorich *newroeich)
{
	newroeich->a = 0;
	newroeich->subitem=NULL;
	newroeich->next=NULL;
	newroeich->s = "";
}

//-----------------------------------------------------------------------
Rorich* rorich_append(Rorich *neroeich_start,Rorich *neroeich_new)
{


		if(neroeich_start->next==NULL)
		{
			neroeich_start->next=neroeich_new;
			return neroeich_new;
		}
		else
		{
			return rorich_append(neroeich_start->next,neroeich_new);
		}	
}
RorichW* rorichW_append(RorichW *neroeich_start,RorichW *neroeich_new)
{


		if(neroeich_start->next==NULL)
		{
			neroeich_start->next=neroeich_new;
			return neroeich_new;
		}
		else
		{
			return rorichW_append(neroeich_start->next,neroeich_new);
		}	
}
RorichW* rorichW_append_map(RorichW *neroeich_start,RorichW *neroeich_new)
{
		if(wcscmp(neroeich_start->s.c_str(),neroeich_new->s.c_str()) == 0) 
		{
			return neroeich_start;
		}
		if(neroeich_start->next==NULL)
		{
			neroeich_start->next=neroeich_new;
			neroeich_new->last = neroeich_start;
			return neroeich_new;
		}
		else
		{

				//printf("g\n");

			return rorichW_append_map(neroeich_start->next,neroeich_new);
		}	
}
//-----------------------------------------------------------------------------





//--------------------------------------------------------------------
Rorich* rorich_append_sub(Rorich *neroeich_start,Rorich *neroeich_new)
{


		if(neroeich_start->subitem==NULL)
		{
			neroeich_start->subitem=neroeich_new;
			return neroeich_new;
		}
		else
		{
			return rorich_append(neroeich_start->subitem,neroeich_new);
		}	
}
RorichW* rorichW_append_sub(RorichW *neroeich_start,RorichW *neroeich_new)
{


		if(neroeich_start->subitem==NULL)
		{
			neroeich_start->subitem=neroeich_new;
			return neroeich_new;
		}
		else
		{
			return rorichW_append(neroeich_start->subitem,neroeich_new);
		}	
}




RorichW* rorichW_append_sub_map(RorichW *neroeich_start,RorichW *neroeich_new)
{


		if(neroeich_start->subitem==NULL)
		{
			neroeich_start->subitem=neroeich_new;
			return neroeich_new;
		}
		else
		{
			neroeich_new->RootDir = neroeich_start;
			return rorichW_append_map(neroeich_start->subitem,neroeich_new);
		}	
}
//-----------------------------------------------------------

Rorich *rorich_mapper(std::string s,Rorich *newroeich,BOOLEAN *b)
{

	
		if(newroeich == NULL)
		{
			printf( "return NULL %s" ,cont_n);
			*b= TRUE;
			return NULL;
		}
		if(strcmp(newroeich->s.c_str(),s.c_str())==0)
		{
			printf( "%s == %s \n",newroeich->s.c_str(),s.c_str() );
			*b= FALSE;
			return newroeich;
		}
		printf( "%s != %s \n",newroeich->s.c_str(),s.c_str() );
		return rorich_mapper(s,newroeich->next,b);
	
	
}
VOID rorich_Init(Rorich *newroeich, int i,std::string str,Rorich *next,Rorich *subitem )
{
    newroeich->a = i;
	newroeich->next=next;
	newroeich->subitem =subitem ;
	newroeich->s = str;
	
}
VOID rorichW_Init(RorichW *newroeich, int i,std::wstring str,RorichW *next,RorichW *subitem )
{
    newroeich->a = i;
	newroeich->next=next;
	newroeich->subitem =subitem ;
	newroeich->s = str;
	
}

//---------------------------------------------------item_show
VOID rorich_show(Rorich *neroeich_start)
{

		if(neroeich_start!=NULL)
		{
			printf(neroeich_start->s.c_str());
			printf("---");
		
			rorich_show(neroeich_start->next);
		}
}

VOID rorichW_show(RorichW *neroeich_start)
{

		if(neroeich_start!=NULL)
		{
			printf("%d.> %S",neroeich_start->a,neroeich_start->s.c_str());
			printf("---");
		
			rorichW_show(neroeich_start->next);
		}
}
//---------------------------------------------------------
VOID rorich_show_sub(Rorich *neroeich_start)
{
	if(neroeich_start!=NULL)
	{
		printf(neroeich_start->s.c_str());
		printf("%s---%s",cont_n,cont_n);
		if(neroeich_start->subitem != NULL)
		{
			rorich_show(neroeich_start->subitem);
			rorich_show_sub(neroeich_start->subitem);			
		}
	}
}
VOID rorichW_show_sub(RorichW *neroeich_start)
{
	if(neroeich_start!=NULL)
	{
		//printf("%S",neroeich_start->s.c_str());
	//printf("%d.> %S",neroeich_start->a,neroeich_start->s.c_str());
		if(neroeich_start->subitem != NULL)
		{
			printf(cont_n);
			rorichW_show(neroeich_start->subitem);
			rorichW_show_sub(neroeich_start->subitem);			
		}
	}
}

//----------------------------------------------------------------------------




/*int item_filterA2(std::string str,char c,int startmove,Rorich *newroeich)
{
	BOOLEAN b;
	Rorich *a;
	Rorich *temp = new Rorich;
	std::string item="";
	int point= startmove;
	while (true)
	{
		if((point) >= str.length()  )
		{
			
			printf (item.c_str());
			rorich_mapper(item,newroeich,&b);
			if(b)
			{
				//rorich_new(&a);
				rorich_Init(temp,0,item,NULL,NULL);
				rorich_append(newroeich,temp);
			}
			break;
		}
		if(str.c_str()[point] == c)
		{
			  point++;
			  rorich_mapper(item,newroeich,&b);
			if(b)
			{
				//rorich_new(&a);
				printf ("-----------------------------\n");
				rorich_Init(temp,0,item,NULL,NULL);
				rorich_append(newroeich,temp);
			}
			else
			{

				printf ("#################################\n");
				//newroeich = newroeich->subitem;
			}

			//printf (item.c_str());
			return (point); 
		}
		item+=str.c_str()[point];
		
		point++;
	}
	
	return (point);
}
int item_filterA3(std::string str,char c,int startmove,Rorich *newroeich)
{
	BOOLEAN b;
	Rorich *a;
	Rorich *temp = new Rorich;
	std::string item="";
	int point= startmove;
	while (true)
	{
		if((point) >= str.length()  )
		{
			
			printf (item.c_str());
			rorich_mapper(item,newroeich->subitem,&b);
			if(b)
			{
				//rorich_new(&a);
				rorich_Init(temp,0,item,NULL,NULL);
				rorich_append_sub(newroeich,temp);
			}
			break;
		}
		if(str.c_str()[point] == c)
		{
			  point++;
			  rorich_mapper(item,newroeich->subitem,&b);
			if(b)
			{
				//rorich_new(&a);
				printf ("-----------------------------%s",cont_n);
				rorich_Init(temp,0,item,NULL,NULL);
				rorich_append_sub(newroeich,temp);
			}
			else
			{

				printf ("#################################\n");
				//newroeich = newroeich->subitem;
			}

			printf (item.c_str());
			return (point); 
		}
		item+=str.c_str()[point];
		
		point++;
	}
	
	return (point);
}
BOOLEAN item_mak_tree2(Rorich *strt, int point,std::string a)
{
			   int c =0;
			   if(point >= a.length())
			   {
				  return TRUE;
			   }
			   c = item_filterA3(a,'\\',point,strt);
			   point=c;
			   item_mak_tree2(strt->subitem, point,a);
}
BOOLEAN item_mak_tree(Rorich *strt, int point,std::string a)
{
	int c =0;

			   if(point >= a.length())
			   {
				  return TRUE;
			   }
			   c = item_filterA2(a,'\\',point,strt);
			   point=c;
			   item_mak_tree2(strt, point,a);
}*/



//------------------------------------------------

int Str_table2_remake()
{
	return 0;
}
Str_fter_u item_filterA_new(std::string str,char c,Str_fter_u g)
{
	//std::string item="";
	g.s = "";
	while (true)
	{
		if((g.i) >= str.length()  )
		{
			//printf (item.c_str());
			
			break;
		}
		if(str.c_str()[g.i] == c)
		{
			g.i++;
			//printf (item.c_str());
		
			return g; 
		}
		g.s+=str.c_str()[g.i];
		g.i++;
	}
	
	return g;
}

Str_fter_uW item_filterW_new(std::wstring str,wchar_t c,Str_fter_uW g)
{
	//std::string item="";
	g.s = L"";
	while (true)
	{
		if((g.i) >= str.length()  )
		{
			//printf (item.c_str());
			
			break;
		}
		if(str.c_str()[g.i] == c)
		{
			g.i++;
			//printf (item.c_str());
		
			return g; 
		}
		g.s+=str.c_str()[g.i];
		g.i++;
	}
	
	return g;
}
//--------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------
BOOLEAN item_mak_tree_sub(Rorich *strt, Str_fter_u g)
{
	//int c =0;
	Str_fter_u c;
	Rorich *crret;
	Rorich *temp = new Rorich;
					
				
			   if(g.i >= g.s.length())
			   {
				  return TRUE;
			   }
			   c = item_filterA_new(g.s,'\\',g);
			   g.i=c.i;
			   rorich_Init(temp,0,c.s,NULL,NULL);
			   crret=rorich_append_sub(strt,temp);
			   return item_mak_tree_sub(crret, g);
}
BOOLEAN item_mak_tree_subW(RorichW *strt, Str_fter_uW g)
{
	//int c =0;
	Str_fter_uW c;
	RorichW *crret;
	RorichW *temp = new RorichW;
					
				
			   if(g.i >= g.s.length())
			   {
				  return TRUE;
			   }
			   c = item_filterW_new(g.s,L'\\',g);
			   g.i=c.i;

			   rorichW_Init(temp,0,c.s,NULL,NULL);
			   crret=rorichW_append_sub_map(strt,temp); 
			   return item_mak_tree_subW(crret, g);
}



//--------------------------------------------------------



/**********************************/
BOOLEAN find_worda2(wchar_t c, FILE* p)
{
	wchar_t temp;
	BOOLEAN  a= FALSE;
		temp= getwc(p);
		if(temp!=WEOF)
		{
			if(temp == c)
			{
				return TRUE;		
			}
			find_worda2(c,p);
		}
		else
		{
			//printf("d\n");
			return FALSE;
		}
}
std::wstring  find_word2(wchar_t c, FILE* p)
{
	std::wstring str = L"";
	wchar_t temp;
	BOOLEAN  a= FALSE;
	while(true)
	{
		temp= getwc(p);
		if(temp!=WEOF)
		{
			if(temp == c)
			{
				a= TRUE;
				break;
			}
			str +=  temp;
		}
		else
		{
		//	printf("d");
			break;
		}

	}
	//outIndexFile(chg_Index,str);
	//return a;
	return str;
}
/************************/


VOID item_mak_tree_subW_easy(RorichW *strt , std::wstring s)
{
	Str_fter_uW g;
	g.s=s;
	g.i=0;
	item_mak_tree_subW(strt, g);
}



VOID rorichW_ALL_show(RorichW *strt)
{
	
	if(strt != NULL)
	{
		printf("%S  --",strt->s.c_str());
		if(strt->next!= NULL)
		{
			rorichW_ALL_show(strt->next);
		}
	}
}
VOID item_set_num ( RorichW *root ,int num)
{
	if(root != NULL)
	{
		root->a = num;
		if(root->subitem != NULL)
		{
			 item_set_num (root->subitem ,0);
		}
		num++;
		item_set_num(root->next,num);
	}
}

VOID item_filter_enrty(char *filename)
{
	printf("%s----------#%s#--------%s",cont_n,filename,cont_n);
	int i=0;
	FILE *fp;
	fp = fopen(filename,"rb");
	std::wstring temp;
	RorichW strt;
	RorichW *mak;
	rorichW_Init(&strt,0,L"root",NULL,NULL);
	if(fp == NULL)
	{
		printf("NO FILE \n");
	}
	else
	{
		while (true)
		{
			if(fp == NULL)
			{
				break;
			}
			if(i==0)
			{
				if(find_worda(L'[',fp ))
				{
					i=1;
				}
				else
				{
					i=3;
				}
			}
			else if(i==1)
			{
				temp =find_word2(L']',fp );
				//printf("%S\n",temp.c_str());
				item_mak_tree_subW_easy(&strt , temp);
				i=0;

			}
			else
			{
				break;
			}
		}
//	printf("%S\n", strt.s.c_str());
//	rorichW_show_sub(strt.subitem);
	fclose(fp);	
	}
	
	/*if((&strt)->subitem != NULL)
	{
		mak = (&strt)->subitem->subitem->subitem->subitem->subitem;
		if( mak != NULL)
			{
				rorichW_ALL_show(mak);
			}
	}*/
	item_set_num ( &strt ,0);

	rorichW_show_sub(&strt);

	//rorichW_show(strt.subitem);
	printf("%s-----------------------------------------------------%s",cont_n,cont_n);
}

VOID tem_filter_tst()
{
printf(cont_n);
item_filter_enrty("ControlSet_c_1_i");
printf(cont_n);
	

	item_filter_enrty("ControlSet_e_1_i");
	printf(cont_n);

	item_filter_enrty("ControlSet_e_2_i");
	printf(cont_n);
	item_filter_enrty("ControlSet_c_2_i");
	printf(cont_n);
	
	item_filter_enrty("ControlSet_s_2_i");
	printf(cont_n);
	item_filter_enrty("ControlSet_s_1_i");
	printf(cont_n);
/*

	/*std::string a = "a\\b\\c\\d\\e\\e\\f";
	std::string a2 = "b\\b\\c\\d\\e\\e\\h";
	std::wstring w =L"a\\b\\c\\d\\e\\e\\f";
	Rorich strt;
	Rorich strt2;
	rorich_Init(&strt,0,"00000000\n",NULL,NULL);
	rorich_Init(&strt2,0,"acbbbb\n",NULL,NULL);
	rorich_append(&strt,&strt2);
//printf(strt.next->s.c_str());
//printf(strt.s.c_str());
        /*   while(true)
		   {
			   if(point >= w.length())
			   {
				   break;
			   }
			   point = item_filterW(w,L'\\',point);
		   }*/
/*		//   point =0;
		    while(true)
		   {
			   if(point >= a.length())
			   {
				   break;
			   }
			   c = item_filterA(a,'\\',point);
			   point=c;
		   }
        //   item_mak_tree(&strt, 0,a);
Str_fter_u g;
g.s=a;
g.i=0;
			item_mak_tree_sub(&strt, g);
			printf(cont_n);
g.s=a2;
g.i=0;
			item_mak_tree_sub(&strt, g);
			printf(cont_n);			
			//rorich_show(&strt);
			rorich_show_sub(&strt);
			printf(cont_n);*/

}

VOID chang_tst()
{
	FILE *FP;
	char b[2];
	char a[2] ="B";
	int num = 3;
	FP = fopen("g.txt","rb+");
	if(FP != NULL)
	{
		    //fread(b,sizeof(char),2,FP);
		fseek(FP, 6*sizeof(char), SEEK_SET);

			//printf("%s done\n",b);
		//	fwrite(a,sizeof(char),1,FP);

	//	fgetc(FP);
		fputc(L'B',FP);
		fclose(FP);
	}
	else
	{
     	printf("NO FILE\n");
	}
}



VOID stream_asl()
{

}