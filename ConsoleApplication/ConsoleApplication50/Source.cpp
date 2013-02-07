#include <iostream>
#include <string>
using namespace std;
void (*p[5])(int&,int&);
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
void print(float&x,float&y)
{
	cout<<"length: "<<x<<"\t"<<"width: "<<y<<endl;
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
		cout<<"First "<<i+1<<" Times executed to the end of the 5th\n";
		cout<<"Initial value\n";
		print(a,b);
		cout<<"Now call the function pointer array p["<<i<<"] Function pointed to by...\n";
		p[i](a,b);
		cout<<"After the operation\n";
		print(a,b);
	}

	system("pause");
	return 0;
}