#include <iostream>
using namespace std;
class Human
{
public:
	void stand(){cout<<"人類能夠直立行走"<<endl;}

};
class Father:public Human
{
};
class Mother:public Human
{
};
class Son:public Father,public Mother
{
};

int main()
{
	Son Tom;
	Tom.Mother::stand();

	system("pause");
	return 0;
}