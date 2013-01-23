#include <iostream>
using namespace std;
float average(int *,int);
int main()
{
	int a[100];
	float average;
	int num=100;
	
	for (int i=0;i<100;i++)
	{
		a[i]=num;
		num++;
		cout<<a[i]<<endl;
	}
	cout<<"";
	system("pause");
	return 0;
};
