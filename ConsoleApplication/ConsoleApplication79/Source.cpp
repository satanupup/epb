#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str="string";
	char ch[]="char";
	cout<<str<<endl;
	cout<<ch<<endl;
	cout<<"please enter \"dog\" is english: "<<endl;
	cin>>str;
	if(str == "dog")
	{
		cout<<"dog: "<<str<<endl;
		cout<<str<<"The first character: "<<str[0] <<endl;
	}
	else
		cout<<"enter error\n";

	cout<<"please enter \"pig\" is english: "<<endl;
	cin>>ch;
	if(strcmp(ch,"pig") == 0)
	{
		cout<<"pig: "<<ch<<endl;
		cout<<ch<<"The first character: "<<ch[0] <<endl;
	}
	else
		cout<<"enter error\n";

	system("pause");
	return 0;
}
