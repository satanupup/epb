#include <iostream>
using namespace std;
int main()
{
	char ch1[10] = "gh";
	char ch2[] = "abcdef";
	strncpy_s(ch1,ch2,3);

	cout<<ch1<<endl;
	cout<<ch2<<endl;

	system("pause");
	return 0;
}
