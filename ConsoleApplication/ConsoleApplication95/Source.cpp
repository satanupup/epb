#include <iostream>
using namespace std;
int main()
{
	char ch1[15];
	char *p , c = 'w';
	strcpy_s(ch1,"hello world");
	p = strchr(ch1,c);
	if(p)
	{
		cout<<"str "<<c<<" located "<<p-ch1<<endl;
	}
	else 
		cout<<"Did not find"<<endl;
	system("pause");
	return 0;
}
