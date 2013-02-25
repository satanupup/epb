#include <iostream>
#include <string>
using namespace std;
//http://www.enet.com.cn/eschool/video/autohtml/310/2821/47.shtml
class A
{
public:
	A(int x){rx=x;}
	friend ostream&operator<<(ostream&s,const A&c)
	{
		s<<c.rx;
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
	cout<<++a<<a++<<endl;
	system("pause");
}
