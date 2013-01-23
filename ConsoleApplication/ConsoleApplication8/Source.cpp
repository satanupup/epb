#include <iostream>
#include <string>
using namespace std;

class Father
{
public:
	Father(){cout<<"構造基類對象\n";}
	Father(string a,int i){name=a;tall=i;cout<<"構造帶兩個參數的基類對象\n";}
	~Father(){cout<<"析構基類對象\n";}
	void print(){cout<<name<<"身高為"<<tall<<"cm\n";}
protected:
	string name;
	int tall;
};
class Son:public Father
{
public:
	Son(string a,int i,int j):Father(a,i){weight=j;cout<<"構造子類對象\n";}
	~Son(){cout<<"析構子類對象\n";}
	void print1(){print();cout<<"體重為:"<<weight;}
protected:
	int weight;
};
int main()
{
	Son Mike("Mike",180,80);
	Mike.print1();
	//Mike.print();
	cout<<"\n程序結束\n";
	system("pause");
	return 0;
}