#include <iostream>
using namespace std;
class aspl
{
public:
	aspl(float p){price=p;TotalPrice=p+TotalPrice;}
	~aspl(){TotalPrice=TotalPrice-price;}
	static float get(){return TotalPrice;}
private:
	float price;
	static float TotalPrice;
};
float aspl::TotalPrice=0;
int main()
{	
	float f;
	cout<<"aspl is number TotalPrice : ";
	cout<<aspl::get()<<endl;
	int i=0;
	cout<<"please input is"<<i<<"¦¸buy aspl price: ";
	cin>>f;
	aspl*p[5];
	p[i]=new aspl(f);
	cout<<"aspl is number TotalPrice : ";
	cout<<aspl::get()<<endl;
	i++;	
	cout<<"please input is"<<i<<"¦¸buy aspl price: ";
	cin>>f;	
	p[i]=new aspl(f);
	cout<<"aspl is number TotalPrice : ";
	cout<<aspl::get()<<endl;
	cout<<"please input shell aspl is number, number is Many times the purchase: ";
	cin>>i;
	delete p[i];
	
	cout<<"aspl is number TotalPrice : ";
	cout<<aspl::get()<<endl;

	system("pause");
	return 0;
}