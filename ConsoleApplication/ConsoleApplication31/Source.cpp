#include <iostream>
using namespace std;


int main()
{
	char a[12];
	cout<<":"<<endl;
	//cin>>a;
	//gets(a);
	cin.get(a,12);
	
	cout<<":"<<a<<endl;
	system("pause");
	return 0;
};
