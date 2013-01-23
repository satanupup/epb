#include <iostream>
using namespace std;
class a
{
public:
	int num(){return 1;}
};
class b:public  a
{
public:
	int num(){return 2;}

};
class c:public  a
{
public:
	int num(){return 3;}

};
class d:public  b,public c
{
public:
	//int num(){return 4;}
	int B(){return b::num();}
};

int main()
{
	d d;
	cout<<d.B()<<endl;


	system("pause");
	return 0;
}