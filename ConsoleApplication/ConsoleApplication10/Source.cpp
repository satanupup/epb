#include <iostream>
using namespace std;
class Father
{
public:
	void hello(){cout<<"hello"<<endl;}
	void hello(int i){cout<<"1 hello"<<i<<endl;}
};
class Son:public Father
{
public:
	void hello(){cout<<"hello2"<<endl;}
	void hello()const{cout<<"const hello2"<<endl;}
	void hello(int i){cout<<"1 hello2 "<<i<<endl;}
	void hello(int i)const{cout<<"const 1 hello2 "<<i<<endl;}
};
int main()
{
	const Son a;
	a.hello();
	a.hello(5);
	system("pause");
	return 0;
}