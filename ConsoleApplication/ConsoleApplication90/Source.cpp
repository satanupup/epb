#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str1 = "gh";
	char str2[] = "abcdef";
	char str3 = 'T';
	//str1.replace(0,1,str2,4,2);
	str1.replace(0,2,2,str3);
	cout<<str1<<endl;
	
	system("pause");
	return 0;
}
