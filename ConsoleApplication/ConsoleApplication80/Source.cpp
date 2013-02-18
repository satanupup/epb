#include <iostream>

using namespace std;

int main()
{
	char ch1[]="give me";
	char ch2[]="a cup";
	strcpy_s(ch1,ch2);
	cout<<ch1<<endl;
	cout<<ch2<<endl;
	system("pause");
	return 0;
}
