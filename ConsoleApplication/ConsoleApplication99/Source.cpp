#include <iostream>
#include <string>
using namespace std;
int main()
{
	char ch1[15]="ofru";
	char ch2[15]="";
	swab(ch1,ch2,strlen(ch1));
	cout<<ch1<<endl;
	cout<<ch2<<endl;

	system("pause");
	return 0;
}
