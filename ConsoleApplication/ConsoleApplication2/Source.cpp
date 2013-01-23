#include <iostream>

using namespace std;

class A
{
public:
	explicit A(int x,int y){i=x;cout<<"aaa"<<i<<endl;}
	~A(){cout<<"bbb"<<i<<endl;}
	void get(){cout<<i<<endl;}
private:
	int i;
};

//A*p=new A;


int main()
{
	A a(99,25);
	a.get();
	a=A(1000,5);


	//delete p;
	system("pause");
	return 0;
}