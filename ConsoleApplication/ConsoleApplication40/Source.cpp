#include <iostream>
using namespace std;
class Human
{
public:
	Human(){cout<<"ºc³yHuman\n";}
	virtual void smart()=0;
	virtual void beautiful()=0;
	virtual ~Human(){cout<<"ªRºcHuman\n";}
};
class father:virtual public Human
{
public:
	father(){cout<<"ºc³yfather\n";}
	virtual void smart()
	{
		cout<<"father is int\n";
	}	
	virtual void beautiful(){cout<<"father no is handsome\n";}
	virtual ~father(){cout<<"ªRºc father"<<endl;}
};
class mother:virtual public Human
{
public:
	mother(){cout<<"ºc³ymother\n";}
	virtual void beautiful(){cout<<"mother is beautiful\n";}
	virtual void smart(){cout<<"mother no is int\n";}
	virtual ~mother(){cout<<"ªRºc mother"<<endl;}
};
class son:public father,public mother
{
public:
	son(){cout<<"ºc³yson\n";}
	virtual void beautiful(){cout<<"son is handsome\n";};
	virtual void smart(){cout<<"son is int\n";}
	virtual ~son(){cout<<"ªRºc son"<<endl;}
};
int main()
{
	Human*p;	
	int choice=0;
	while(choice < 99)
	{
		bool quit=false;
		cout<<"(0)quit(1)father(2)son:(3)mother:";
		cin>>choice;
		switch(choice){
		case 0:quit=true;
			break;
		case 1:p=new father;
			p->beautiful();
			p->smart();
			delete p;
			break;
		case 2:p=new son;
			p->beautiful();
			p->smart();
			delete p;
			break;
		case 3:p=new mother;
			p->beautiful();
			p->smart();
			delete p;
			break;
		default:
			cout<<"please input 0 to 2 number ";
			break;
		}
		if(quit)
		{
			break;
		}

	}
	cout<<"end"<<endl;
	system("pause");
	return 0;
}