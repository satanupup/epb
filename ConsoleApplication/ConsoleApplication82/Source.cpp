#include <iostream>
using namespace std;

int main()
{
	char ch1[50]="what's your name";
	char ch2[]="my name is Jack";
	strcat_s(ch1,ch2);
	cout<<ch1<<endl;
	cout<<ch2<<endl;
	system("pause");
	return 0;
}
