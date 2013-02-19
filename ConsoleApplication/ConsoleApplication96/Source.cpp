#include <iostream>
#include <string>
using namespace std;
int main()
{
	//char ch1[15];
	//char *p , c = 'w';
	string str1("hello worldw");
	//int f = str1.find('w',0);
//	int f = str1.find_last_of('w');
//	int f = str1.find_last_not_of('w');
	int f = str1.rfind('w',10);
	if(f != string::npos)
	{
		cout<<"In the first "<<f<<" characters"<<endl;
	}
	else
	{
		cout<<"Did not find"<<endl;
	}
	//strcpy_s(ch1,"hello world");
	//p = strchr(ch1,c);
	/*
	if(p)
	{
		cout<<"str "<<c<<" located "<<p-ch1<<endl;
	}
	else 
		cout<<"Did not find"<<endl;*/
	system("pause");
	return 0;
}
