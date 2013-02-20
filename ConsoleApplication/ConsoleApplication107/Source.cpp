#include <iostream>
#include <string>
using namespace std;
struct people
{
	people(double t_weight,double t_tall,int t_age,string t_name,string t_native,bool t_sex);
	int age;
	double weight;
	double tall;
	string name;
	string native;
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
	people Jack
	(
		180.5,
		179.3,
		32,
		"Jack",
		"che nun",
		1
	);
	cout<<Jack.name<<endl;
	cout<<Jack.native<<endl;
	cout<<Jack.tall<<endl;
	cout<<Jack.weight<<endl;
	cout<<Jack.age<<endl;
	check(Jack.sex);
	system("pause");
}
people::people(double t_weight,double t_tall,int t_age,string t_name,string t_native,bool t_sex)
{
	weight = t_weight;
	tall = t_tall;
	age = t_age;
	name = t_name;
	native = t_native;
	sex = t_sex;
}