#include <iostream>
using namespace std;

class area
{
public:
	area(int l,int w){length=l;width=w;cout<<"�եκc�y��Ƴ]�m���M�e����,"<<"��: "<<length<<"�e: "<<width<<endl;}
	~area(){cout<<"�եΪR�c������񤺦s,"<<"��: "<<length<<"�e: "<<width<<endl;}
	int get(){return length*width;}
	void set(int l,int w){length=l;width=w;}

private:
	int length;
	int width;
};
int main()
{
	area one[4]={area(10,10),area(13,34),area(20,30),area(40,40)};	
	cout<<one[0].get()<<endl;
	one[0].set(30,40);
	for(int i=0;i<4;i++)
	cout<<one[i].get()<<endl;


	system("pause");
	return 0;
};