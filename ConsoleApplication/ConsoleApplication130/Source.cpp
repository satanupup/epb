#include <iostream>
using namespace std;
class A
{
public:
	A(){x=0;}
	A(int i){x=i;}
	void get(){cout<<x;}
private:
	int x;
};
class B
{
public:
	B(){y=0;}
	B(int i,int j,int k):a(i),b(j){y=k;}
	A geta(){return a;}
	A getb(){return b;}
	int gety(){return y;}
private:
	A a;
	A b;
	int y;
};
void main()
{	
	B b(1,2,3);
	b.geta().get();
	b.getb().get();
	cout<<b.gety();
	system("pause");
}

