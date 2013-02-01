#include <iostream>
using namespace std;
class A
{
public:
	void static show(){cout<<A::n;n++;}
	void get(){cout<<n;}
	A(){m=0;}
private:
	static int n;
	int m;
};
class B:public A
{
public:

};
int A::n = 0;
int main()
{	
	A::show();
	A a;
	a.get();
	B::show();


	system("pause");
	return 0;
}