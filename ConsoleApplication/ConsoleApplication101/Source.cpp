#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str="hello world";
	const char*ch;
	ch=str.c_str();
	cout<<ch<<endl;
	system("pause");
	return 0;
}
