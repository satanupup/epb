#include <iostream>
using namespace std;
class father
{
public:
	virtual void run()const{cout<<"Father can run ten thousand meters";}	
	void jump()const{cout<<"Father can jump five steps\n";}
};
class son:public father
{
	void run()const{cout<<"Son can run 100,000 thousand meters\n";}
	void jump()const{cout<<"Son can jump ten steps\n";}
};
int main()
{ 
	father*p=new son;
	p->jump();
	p->run();
	delete p;
	system("pause");
	return 0;
}