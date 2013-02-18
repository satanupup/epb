#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1="give me";
	string str2="a cup";
	//str1=str2;
	str1.assign(str2,3,1);
	cout<<str1<<endl;
	cout<<str2<<endl;
	system("pause");
	return 0;
}
