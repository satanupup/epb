#include <iostream>
using namespace std;

class area
{
public:
	area(){length=0;width=0;}
	~area(){cout<<"執行析構函數釋放內存"<<endl;}
	int get(){return length*width;}
	void set(int l,int w){length=l;width=w;}
private:
	int length;
	int width;
};
int main()
{
	area *one=new area[10000];
	for(int i=0;i<10000;i++)
	{
		one[i].set(4,5*i);
	}
	cout<<one[1].get()<<endl;
	
	delete []one;
	
	system("pause");
	return 0;
};
