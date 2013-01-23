#include <iostream>
using namespace std;

class A
{
public:
	A(){x= new int; *x=5;}
	~A(){delete x; x=NULL;}
	A(const A&a)
	{/*
		cout<<"複製構造函數執行...\n"<<endl;
		x=a.x;*/		
		cout<<"複製構造函數執行...\n"<<endl;
		x=new int;
		*x=*(a.x);
	}
	int print()const{return *x;}
	void set(int i){*x=i;}
private:
	int *x;
};


int main()
{
	A*a=new A();
	A b=(*a);
	
	cout<<"a:"<<a->print()<<endl;
	cout<<"b:"<<b.print()<<endl;
	a->set(32);	
	b.set(31);
	cout<<"b:"<<b.print()<<endl;	
	cout<<"a:"<<a->print()<<endl;	
	delete a;		
	cout<<"b:"<<b.print()<<endl;



	system("pause");
	return 0;
}