#include <iostream>
using namespace std;
class father
{
public:
	father():age(54){cout<<"Call the parent class constructor and initialize the value of the age: "<<age<<"\n";}
	~father(){cout<<"Call the parent class Destructor\n";}
	void jump()const{cout<<"Father can jump five steps\n";}
	void run()const{cout<<"Father can run ten thousand meters";}
protected:
	int age;
};
class son:public father
{
public:
	son(){cout<<"To call the constructor of the subclass\n";}
	~son(){cout<<"To call the Destructon\n";}
	void math(){cout<<"Son might Mathematics";}
	void jump()const{cout<<"Son can jump ten steps\n";}
	void run()const{cout<<"Son can run 100,000 thousand meters\n";}

};
int main()
{ 
	son*p=new son;
	p->jump();
	p->run();
	p->math();
	delete p;
	system("pause");
	return 0;
}