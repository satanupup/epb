#include <iostream>
using namespace std;

int main()
{
	char ch1[10] = "ab";
	char ch2[] = "abcdef";
	strncat_s(ch1,ch2,3);
	cout<<ch1<<endl;
	system("pause");
	return 0;
}
