#include <iostream>
#include <string>
using namespace std;
void square(float&x,float&y)
{
	x=x*x;
	y=y*y;
}
void cube(float&x,float&y)
{
	x=x*x*x;
	y=y*y*y;
}
typedef void(*p)(float&,float&);
void print(p vp,float&x,float&y)
{
	cout<<"Executive function before\n";
	cout<<"x:"<<x<<"\t"<<"y:"<<y<<endl;
	vp(x,y);
	cout<<"Function is executed after\n";
	cout<<"x:"<<x<<"\t"<<"y:"<<y<<endl;
}
void swap(float&x,float&y)
{
	float z;
	z=x;
	x=y;
	y=z;
}
int main()
{	
	float a=2,b=3;
	char choice='0';	
//	void (*p[5])(float&x,float&y);
	p vp=NULL;
	for(int i=0;i<5;i++)
	{
		cout<<"(0)quit(1)square(2)cube(3)swap x and y the value : ";
		cin>>choice;
		bool quit=false;
		switch(choice)
		{
		case '0':			quit = true;			break;
		case '1':			vp = square;			break;
		case '2':			vp = cube;			break;
		case '3':			vp = swap;			break;
		default:			vp = 0;				break;
		}
		if(quit)
			break;
		if(vp==0)
		{
			cout<<"please enter a number between 0-3\n";
			i=i-1;
			continue;
		}
		print(vp,a,b);
	}

	system("pause");
	return 0;
}