#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str1 = "12789";
	string str2 = "3456";
	str1.insert(2,str2,0,4);
	cout<<str1<<endl;
	system("pause");
	return 0;
}
