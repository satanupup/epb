#include <iostream>
#include <string>
using namespace std;
float(*fp)(float&,float&);
void(*p)(float&,float&);
float triangle(float &x,float &y)
{
	return x*y*(float)0.5;
}
float rectangle(float &x,float &y)
{
	return x*y;
}
void swap(float &x,float &y)
{
	float n;
	n=x;
	x=y;
	y=n;
}
void print(float &x,float &y)
{
	cout<<"ªø¬°: "<<x<<" "<<"¼e¬°: "<<y<<endl;
}
bool check(string str)
{
	int barnumber = str.length();
	for(int i=0;i<barnumber;i++)
	{
		if((str[i]>'9'||str[i]<'0')&&(str[i]!='.'))
		{
			return false;
		}		
	}
	return true;
}
void get(float &x,float &y)
{
	cout<<"please input x is new number: ";
	string str1;
	cin>>str1;
	while(!check(str1))
	{
		cout<<"input is no number ,please Re-enter!!!" <<endl;
		cin>>str1;
	}
	x=(float)atof(str1.c_str());
	cout<<"please input y is new number: ";
	string str2;
	cin>>str2;
	while(!check(str2))
	{
		cout<<"input is no number ,please Re-enter!!!" <<endl;
		cin>>str2;
	}
	y=(float)atof(str2.c_str());

}
int main()
{	
	bool quit=false;
	float a=2,b=3;
	int choice;
	while(quit == false)
	{
		cout<<"(0)quit(1)Set length and width(2)Triangle(3)Rectangle(4)Exchange length and width:";
		cin>>choice;
		switch(choice)
		{
		case 1:
			cout<<"The length and width of the value set before: ";
			/*
			print(a,b);
			get(a,b);
			cout<<"The value of the set after a long and wide: ";
			print(a,b);*/
			p=get;
			break;
		case 2:
			//print(a,b);
			//cout<<"Triangle is area : ";
			//<<triangle(a,b)<<endl;
			fp=triangle;
			break;
		case 3:
			//print(a,b);
		//	cout<<"rectangle is area : ";
			//<<rectangle(a,b)<<endl;
			fp=rectangle;
			break;
		case 4:
			cout<<"The value of the exchange before long and wide: ";
			/*
			print(a,b);
			swap(a,b);
			cout<<"Exchange value after the length and width of the: ";
			print(a,b);
			*/
			p=swap;
			break;
		default:
			quit=true;
			break;
		}
		if(choice == 1 || choice == 4)
		{
			print(a,b);
			p(a,b);
			print(a,b);
		}
		else if(choice == 2 || choice == 3)
		{
			print(a,b);
			cout<<"area is : "<<fp(a,b)<<endl;
		}
	}


	system("pause");
	return 0;
}