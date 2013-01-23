#include <iostream>
using namespace std;
class a
{
public:
	void hello(){cout<<"a hello"<<endl;}
};
class b
{
public:
	void hello(){cout<<"b hello"<<endl;}
	void print(){cout<<"b print"<<endl;}
};
class c:public a,public b
{
public:	
	void print(){cout<<"c print"<<endl;}

};
int main()
{
	c c;
	a a;
	b b;

	a.hello();
	b.print();

	c.a::hello();
	c.b::hello();
	c.b::print();
	c.print();

	system("pause");
	return 0;
}