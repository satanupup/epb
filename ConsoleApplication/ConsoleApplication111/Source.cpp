#include <iostream>
#include <string>
using namespace std;
const string& show(const string &p)
{
	cout<<p<<endl;
	return p;
}
void main()
{
	string str="hello world";
	string str1=show(str);
	cout<<str1<<endl;
	system("pause");
}
