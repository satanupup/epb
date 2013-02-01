#include <iostream>
using namespace std;
class A
{
public:
	A(int num):it(num){total++;}
	static int total;
	~A(){total--;}
	int get(){return it;}
	void set(int age){it=age;}
private:
	int it;

};
int A::total = 0;
void show()
{
	cout<<A::total<<endl;
}

int main()
{	
	/*
	const int max=5;
	A*a[max];
	for(int i=0;i<max;i++)
	{
		a[i]=new A(i);
	}
	for(int i=0;i<max;i++)
	{
		cout<<"該類有"<<A::total<<endl;
		cout<<"正在刪除第"<<a[i]->get()<<"個對象.\n";
		delete a[i];
	}
	*/
	//A a(1),b(2),c(3);
	//cout<<a.total<<endl<<b.total<<endl<<c.total;
	//cout<<a.get()<<endl<<b.get()<<endl<<c.get()<<endl;
	//cout<<A::total<<endl;
	for(int i=0;i<5;i++)
	{
		A::total++;
		show();
	}
	
	system("pause");
	return 0;
}