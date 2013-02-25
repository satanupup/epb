#include <iostream>
#include <string>
using namespace std;
class A
{
public:
	A(int x,int y){rx=x;ry=y;}
//private:
	int rx;
	int ry;
};
ostream&operator<<(ostream&s,const A&c)
{
	s<<c.rx;
	s<<c.ry;
	return s;
}
void main()
{
	A a(3,4),b(5,6);
	cout<<a<<b<<endl;
	system("pause");
}
