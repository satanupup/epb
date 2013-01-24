#include <iostream>
using namespace std;

class A
{
public:
	A(int l){length=l;size=new char[length];}
	~A(){delete []size;}
	int GetLength(){return length;}
	char&operator[](int i)
	{
		if(i>=0&&i<length)
		{
			return size[i];
		}
		else
		{
			cout<<"\n¶W¥X½d³ò¡C ";
			return size[length-1];
		}
	}
private:
	int length;
	char *size;
};

int main()
{
	A a(6);
	char *ch="hello12";
	for(int i=0;i<8;i++)
	{
		a[i]=ch[i];			
	}
	cout<<"\n\n";
	for(int i=0;i<8;i++)
	{
		cout<<a[i];
	}

	system("pause");
	return 0;
};
