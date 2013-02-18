#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1 = "ab";
	string str2 = "abcdef";
	str1.append(str2,2,3);
	cout<<str1<<endl;
	system("pause");
	return 0;
}
