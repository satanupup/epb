#include <iostream>
using namespace std;
int main()
{
	char man[12]={"hello world"};	
	cout<<man<<endl;
	cout<<"strlen(man):"<<strlen(man)<<endl;
	cout<<"sizeof(man):"<<sizeof(man)<<endl;
	man[5]='\0';	
	cout<<man<<endl;	
	cout<<"strlen(man):"<<strlen(man)<<endl;
	cout<<"sizeof(man):"<<sizeof(man)<<endl;
	system("pause");
	return 0;
}