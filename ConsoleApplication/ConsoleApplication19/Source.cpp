#include <iostream>
using namespace std;

class father
{
public:
	virtual void run()const{cout<<"Father can run ten thousand meters\n";}	
	//void jump()const{cout<<"Father can jump five steps\n";}
};
class son:public father
{
	void run()const{cout<<"Son can run 100,000 thousand meters\n";}
	//void jump()const{cout<<"Son can jump ten steps\n";}
};
class daughter:public father
{
public:
	void run()const{cout<<"Daughter can run 50,000 thousand meters\n";}
};
void one(father);
void two(father*);
void three(father&);
int main()
{
	father*p=0;
	int choice;
	while(1)
	{
		bool quit=false;
		cout<<"(0)quit (1)son (2)daughter(3)father:";
		cin>>choice;
		switch(choice)
		{
		case 0:quit=true;
			break;
		case 1:p=new son;
			one(*p);
			break;
		case 2:p=new daughter;
			two(p);
			break;
		case 3:p=new father;
			three(*p);
			break;
		default:
			cout<<"please input 1,2 or 3 ,quit input 0:\n";
			break;
		}
		if(quit)
		{
			break;
		}
	}
	system("pause");
	return 0;
};
void one(father one)
{
	one.run();
}
void two(father*two)
{
	two->run();
}
void three(father&three)
{
	three.run();
}
