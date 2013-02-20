#include <iostream>
using namespace std;
//The structure and the function returns the 
//address of the structure to avoid the copy constructor
struct time
{
	int hour;
	int minute;
};
const int perhour=60;
time *sum(time t1,time t2);
void show(time t)
{
	cout<<t.hour<<":"<<t.minute<<endl;
}
void main()
{
	time one={8,15};
	time two={6,55};
	time *day = sum(one,two);
	cout<<"Total for two days: ";
	show(*day);
	time day3={9,35};
	cout<<"Total for three days: ";
	time *p=sum(*day,day3);
	show(*p);
	delete day;
	delete p;
	system("pause");
}
time *sum(time t1,time t2)
{
	time *total=new time;
	total->minute = (t1.minute+t2.minute)%perhour;
	total->hour = t1.hour+t2.hour+(t1.minute+t2.minute)/perhour;
	return total;
}