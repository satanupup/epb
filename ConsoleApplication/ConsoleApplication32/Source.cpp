#include <iostream>
using namespace std;


static char *mapHyphen(char *str);
int main()
{/*//把兩個數組相加
	char a[20]="This is a ";
	char b[]="Sparta";
	cout<<strcat(a,b)<<endl;
	cout<<a;*/

	/*//把b複製給a
	char a[20]="This is a ";
	char b[]="Sparta";
	cout<<strcpy(a,b)<<endl;
	cout<<a;*/

	/*//判斷兩個數組是否相同
	char a[]="This is a ";
	char b[]="Sparta";
	char c[]="Sparta";
	cout<<strcmp(a,b)<<endl;//> = 1 ,< = -1 , == 0
	cout<<a;*/

	/*//把小寫轉換為大寫
	char a[]="this is a Sparta";
	strupr(a);
	cout<<a<<endl;*/
	/*
	//把大寫轉換為小寫
	char a[]="THIS IS A SPARTA";
	strlwr(a);
	cout<<a<<endl;
	*/
	/*
	//計算字符串長度,該長度不包括結束符'\0'
	char a[]="THIS IS A SPARTA";	
	cout<<strlen(a)<<endl;*/

	/*	
	char        *key;
	key = "abc-cba";
	printf(key);
	key = mapHyphen("-");	
	printf(key);
	*/
	system("pause");
	return 0;
};


static char *mapHyphen(char *str)
{	
    char    *cp;
    for (cp = str; *cp; cp++) {
        if (cp == "-") {
            cp = "_";	
			str = cp;
        }
	}
    return str;
}