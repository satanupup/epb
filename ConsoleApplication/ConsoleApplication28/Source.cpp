#include <iostream>
using namespace std;


int main()
{
	enum day{mon,tue,wen,thu,fri,sat,sun};
	double tem[sun+1]={88.2,95.4,94.8,89.5,56.8,92.3,85.9};
	int day;
	for(day=mon;day<=sun;day++)
	{
		cout<<"星期"<<day+1<<"最高溫度為"<<tem[day]<<endl;
	}


	system("pause");
	return 0;
};
