#include <iostream>
using namespace std;
class Human
{
public:
	virtual void run()=0;
	virtual void eat()=0;
};
class Mother : public Human
{
public:
	void run(){cout<<"The mother ran one hundred meters to spend twenty seconds \n";}
	void eat(){cout<<"Mother like snacking\n";}
};
class Father : public Human
{
public:
	void run(){cout<<"The Father ran one hundred meters to spend ten seconds \n";}
	void eat(){cout<<"The father did not like to eat snacks\n";}
};
class Uncle : public Human
{
public:
	void run(){cout<<"The Uncle ran one hundred meters to spend fifteen seconds \n";}
	void eat(){cout<<"The uncle likes eating snacks\n";}
};
int main()
{	
	void (Human::*pf)()=0;
	Human*p=0;
	char choice1,choice2;
	bool quit=false;
	while(quit == false)
	{
		cout<<"(0)quit(1)mother(2)father(3)uncle: ";
		cin>>choice1;
		switch(choice1)
		{
		case '0':	quit = true;	break;
		case '1':	p = new Mother;	break;
		case '2':	p = new Father;	break;
		case '3':	p = new Uncle;	break;
		default:	choice1 = 'q';	break;
		}
		if(quit)
		{
			break;
		}
		if(choice1=='q')
		{
			cout<<"please enter a number between 0-3\n";
			continue;
		}
		cout<<"(1)run(2)eat\n";
		cin>>choice2;
		switch(choice2)
		{
		case '1':	pf=&Human::run;	break;
		case '2':	pf=&Human::eat;	break;
		default:					break;
		}
		(p->*pf)();
		delete p;
	}

	system("pause");
	return 0;
}