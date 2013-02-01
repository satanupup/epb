#include <iostream>
using namespace std;
class A
{
public:
	void Func(){cout<<A::x;}
private:
	static int x;
};
int A::x = 1000;
int main()
{	
	A a;
	a.Func();
	system("pause");
	return 0;
}