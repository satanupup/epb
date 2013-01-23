#include <iostream>
using namespace std;
bool add(int a[],int n);
int main()
{
	int a[]={22,44,66,88,1,32,64};
	bool check = add(a,4);
	if(check==true)
	{
		cout<<"數組有按照順序排列"<<endl;
	}
	else 
	{
		cout<<"數組沒有按照順序排列"<<endl;
	}

	system("pause");
	return 0;
};
bool add(int a[],int n)
{
	for(int i=1;i<n;i++)
	{
		if(a[i]<a[i-1])
		{
			return false;
		}
	}		
	return true;
}