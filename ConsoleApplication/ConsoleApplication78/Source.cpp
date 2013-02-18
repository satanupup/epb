#include <iostream>
#include <string>
using namespace std;

bool check(char ch[],char ch1[]);
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
	if(check(ch,"pig"))
	{
		cout<<"pig: "<<ch<<endl;
		cout<<ch<<"The first character: "<<ch[0] <<endl;
	}
	else
		cout<<"enter error\n";

	system("pause");
	return 0;
}

bool check(char ch[],char ch1[])
{	
	bool quit = false;
	int tt = strlen(ch1);
	for(int i=0;i<tt;i++)
	{
		if(ch[i]!=ch1[i])
		{
			quit = true;
			break;
		}
	}
	if(quit==false)
	{
		return 1;
	}
	else
		return 0;
}