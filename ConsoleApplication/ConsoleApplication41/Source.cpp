#include <iostream>
using namespace std;
class Shape
{
public:
	virtual double area()=0;
};
class Triangle:public Shape
{
protected:
	double h,w;
public:
	Triangle(double H,double W)
	{
		h=H,w=W;
	}
	double area()
	{
		return h*w/2;
	}
};
class Square:public Triangle
{
public:
	Square(double H,double W):Triangle(H,W){}
	double area(){return h*w;}
};
class Circle:public Shape
{
protected:
	double radius;
public:
	Circle(double r){radius=r;}
	double area(){return radius*radius*3.14;}
};

int main()
{
	Shape*p;
	int choice=0;
	while(1)
	{
		bool quit=false;
		cout<<"(0)quit(1)Triangle(2)Square(3)Circle"<<endl;
		cout<<"please: ";
		cin>>choice;
		switch (choice)
		{
		case 0:quit=true;
			break;
		case 1:p=new Triangle(5.0,6.0);
			cout<<"Triangle is area :"<<p->area()<<endl;
			break;
		case 2:p=new Square(70.0,70.0);
			cout<<"Square is area: "<<p->area()<<endl;
			break;
		case 3:p=new Circle(9.0);
			cout<<"Circle is area: "<<p->area()<<endl;
		default:cout<<"please input 0 - 3 is number. \n";
			break;
		}
		if(choice<4&&choice>0)
		{
			delete p;
		}
		if(quit)
		{
			break;
		}
	}
	system("pause");
	return 0;
}