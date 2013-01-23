#include <iostream>
using namespace std;
class A
{
public:
	A(){cout<<"A"<<endl;}
	virtual void func(){cout<<"class A"<<endl;}
	virtual ~A(){cout<<"ªRºcA"<<endl;}
	virtual int get(){return 0;}

};
class B:public A
{
public:
	
	B(){cout<<"B"<<endl;}
	virtual void func(){cout<<"class B"<<endl;}
	~B(){cout<<"ªRºcB"<<endl;}

	int get(){return 1;}
};
int main()
{
	A*p=new B;
	p->func();
	delete p;
	system("pause");
	return 0;
};
