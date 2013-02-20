#include <iostream>
using namespace std;
struct people
{
	int age;
	double weight;
	double tall;
	char*name;
	char*native;
	bool sex;
};
void check(bool s)
{
	if(s==1)
		cout<<"male"<<endl;
	else
		cout<<"female"<<endl;
}
void main()
{
	people Jack=
	{
		32,
		179.3,
		100.5,
		"Jack",
		"che nun",
		1
	};
	cout<<Jack.name<<endl;
	cout<<Jack.native<<endl;
	cout<<Jack.tall<<endl;
	cout<<Jack.weight<<endl;
	cout<<Jack.age<<endl;
	check(Jack.sex);
	system("pause");
}
