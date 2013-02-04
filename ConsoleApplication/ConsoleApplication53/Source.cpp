#include <iostream>
using namespace std;
class A
{
public:
	void set(int x,int y)
	{
		a=x;
		b=y;
	}
	void show()
	{
		cout<<"a:"<<a<<"\t"<<"b:"<<b<<endl;
	}
private:
	int a;
	int b;
};
void(A::*p)(int,int);
int main()
{	
	A a;
	p=&A::set;
	int x=2,y=3;
	(a.*p)(x,y);
	a.show();


	system("pause");
	return 0;
}