#include <iostream>
#include <string>
using namespace std;
int get(const char []);
int main()
{
	char ch[15]="hello world";
	char *p="very well";
	int a=get(ch);
	int b=get(p);
	cout<<ch<<"a total of "<<a<<" characters"<<endl;
	cout<<p<<"a total of "<<b<<" characters"<<endl;

	system("pause");
	return 0;
}
int get(const char p[])
{
	int count=0;
	while(*p)
	{
		count++;
		p++;
	}
	return count;
}