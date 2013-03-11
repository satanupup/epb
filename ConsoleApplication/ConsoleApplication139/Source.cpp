#include <iostream>
using namespace std;
class A
{
public:
	void Set(int a,int b)
	{
		x=a;
		y=b;
	}
	void Show()
	{
		cout<<x<<endl<<y<<endl;
	}
protected:
	int x;
private:
	int y;
};
class B:protected A
{
public:	
	void SetB(int a,int b)
	{
		Set(a,b);
		x=0;
	}
	void ShowB()
	{
		Show();
	}
};
class C:protected B
{
public:
	void SetC(int a,int b)
	{
		Set(a,b);
		x=0;
	}
	void ShowC()
	{
		Show();
	}

};
int main()
{
	B b;
	b.SetB(1,2);
	b.ShowB();
	system("pause");
	return 0;
}