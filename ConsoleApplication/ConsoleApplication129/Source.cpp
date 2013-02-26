#include <iostream>
using namespace std;
//http://www.enet.com.cn/eschool/video/autohtml/310/2821/55.shtml
class A
{
public:
	A(int i,int j){x=i;y=j;}
	void set(int s1,int s2){x = s1;y=s2;}
	void print(){cout<<x<<endl;}
	void print()const{cout<<y<<endl;}
private:
	int x,y;
};
void main()
{
	const A a(2,3);
	a.print();
	//a.set(1,2);
	A b(4,5);
	b.print();
	b.set(1,2);
	b.print();
	system("pause");
}