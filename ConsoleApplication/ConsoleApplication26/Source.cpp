#include <iostream>
using namespace std;

class area
{
public:
	area(int l,int w){length=l;width=w;cout<<"調用構造函數設置長和寬的值,"<<"長: "<<length<<"寬: "<<width<<endl;}
	~area(){cout<<"調用析構函數釋放內存,"<<"長: "<<length<<"寬: "<<width<<endl;}
	int get(){return length*width;}
	void set(int l,int w){length=l;width=w;}

private:
	int length;
	int width;
};
int main()
{
	for(int i=0;i<10000;i++)
	{
		area *one=new area(4,5*i);
		cout<<"area["<<i<<"]:";
		cout<<one->get()<<endl;
		delete one;
	}

	system("pause");
	return 0;
};
