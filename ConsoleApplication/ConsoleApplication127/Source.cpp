#include <iostream>
#include <string>
using namespace std;
class A
{
public:
	A(int x){rx=x;}
	friend ostream&operator<<(ostream&s,const A&c)
	{
		s<<c.rx;
		return s;
	}
	friend istream&operator>>(istream&s,A&c)
	{
		s>>c.rx;
		return s;
	}
	int operator++(){cout<<"++i\n";rx++;return rx;}
	int operator++(int){cout<<"i++\n";int i=rx;rx++;return i;}
private:
	int rx;
};

void main()
{
	A a(3),b(5);
	cin>>a>>b;
	cout<<a<<b<<endl;
	system("pause");
}
