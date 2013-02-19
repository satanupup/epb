#include <iostream>
using namespace std;
int main()
{
	char ch1[15] = "abcdefghijklmn";
	char ch2[] = "1234567890";
	cout<<"ch1: "<<ch1<<endl;
	memmove(ch1,ch2,10);
	cout<<"ch1: "<<ch1<<endl;
	system("pause");
	return 0;
}
