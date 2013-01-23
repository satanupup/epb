#include <iostream>
using namespace std;
class father
{
public:
	father(int x){a=x;cout<<"構造父類對象 成員a的值為:"<<a<<endl;}
	~father(){cout<<"析構父類對象  成員a的值為:"<<a<<endl;}
private:
	int a;
};
class son:public father
{
public:
	son(int z,int x,int y):father(x),Mick(y){b=z;cout<<"構造子類對象 成員b的值為:"<<b<<endl;}
	~son(){cout<<"析構子類對象 \n";}
private:
	int b;
	father Mick;
};
int main()
{
	son Jack(1,2,3);

	system("pause");
	return 0;
}