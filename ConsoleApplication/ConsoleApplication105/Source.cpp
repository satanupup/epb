#include <iostream>
#include <string>

using namespace std;
char *get(char*str);
int main()
{
	char c[10];
	char *ch;
	cout<<"please enter your name! ";
	cin>>c;
	ch = get(c);	
	cout<<"your name is "<<ch<<endl;
	delete []ch;
	ch=get("Jack");
	cout<<"your name is "<<ch<<endl;
	delete []ch;
	char*ch1="Mike";
	ch=get(ch1);
	cout<<"your name is "<<ch<<endl;
	delete []ch;

	system("pause");
	return 0;
}
char *get(char*str)
{
	char *p=new char[strlen(str)+1];
	strcpy_s(p,strlen(str)+1,str);
	cout<<p;
	return p;
}
