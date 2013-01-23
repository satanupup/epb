#include <iostream>
using namespace std;
class poser
{
public:
	virtual void beat()const {cout<<"General power of the players for 260 pounds\n";}
protected:
	int age;
};
class Ali:public poser
{
public:
	virtual void beat()const{cout<<"Ali punch force of 420 pounds\n";}
};
class Lewis:public poser
{
public:
	virtual void beat()const{cout<<"Lewis punch force of 480 pounds\n";}
};
class Tyson:public poser
{
public:
	virtual void beat()const{cout<<"Tyson punch force of 500 pounds\n";}
};
class Holy:public poser
{
public:
	virtual void beat()const{cout<<"Holy punch force of 350 pounds\n";}
};

int main()
{
	poser *p[5];
	poser *p1;
	int choice;
	for(int i=0;i<5;i++)
	{
		cout<<"(1)Ali(2)Lewis(3)Tyson(4)Holy: ";
		cin>>choice;
		switch(choice)
		{
		case 1:p1=new Ali;
			break;
		case 2:p1=new Lewis;
			break;
		case 3:p1=new Tyson;
			break;
		case 4:p1=new Holy;
			break;
		default:p1=new poser;
			break;
		}
		p[i]=p1;
		p[i]->beat();
	}

	system("pause");
	return 0;
}