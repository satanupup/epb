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
void print(void(*p)(float&,float&),float&x,float&y)
{
	cout<<"Executive function before\n";
	cout<<"x:"<<x<<"\t"<<"y:"<<y<<endl;
	p(x,y);
	cout<<"Function is executed after\n";
	cout<<"x:"<<x<<"\t"<<"y:"<<y<<endl;
}
void swap(float&x,float&y)
{
	int z;
	z=x;
	x=y;
	y=z;
}
int main()
{	
	float a=2,b=3;
	char choice='0';	
	void (*p[5])(float&x,float&y);
	for(int i=0;i<5;i++)
	{
		cout<<"(0)quit(1)square(2)cube(3)swap x and y the value : ";
		cin>>choice;
		bool quit=false;
		switch(choice)
		{
		case '0':			quit = true;			break;
		case '1':			p[i] = square;			break;
		case '2':			p[i] = cube;			break;
		case '3':			p[i] = swap;			break;
		default:			p[i] = 0;				break;
		}
		if(quit)
			break;
		if(p[i]==0)
		{
			cout<<"please enter a number between 0-3\n";
			i=i-1;
			continue;
		}
		print(p[i],a,b);
	}

	system("pause");
	return 0;
}