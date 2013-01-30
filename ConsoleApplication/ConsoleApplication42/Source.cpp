#include <iostream>
using namespace std;
class Animal
{
public:
	Animal(int);
	virtual ~Animal(){cout<<"Destructor Animal...\n";}
	virtual int GetAge(){return itsage;}
	virtual void Sleep()=0;
	virtual void Propagate()=0;
	virtual void Move()=0;
	virtual void Body()=0;
	virtual void Eat()=0;
	virtual void Show()=0;
private:
	int itsage;
};
Animal::Animal(int age):itsage(age)
{
	cout<<"create Animal...\n";
}
class Mammalia:public Animal
{
public:
	Mammalia(int age):Animal(age)
	{
		cout<<"create Mammalia...\n";
	}
	virtual ~Mammalia()
	{
		cout<<"Destructor Mammalia...\n";
	}
	virtual void Propagate()
	{
		cout<<"Mammalia is Propagate Animal,Embryos breed.\n";
	}
};
class Bird:public Animal
{
public:
	Bird(int age):Animal(age)
	{
		cout<<"create bird... \n";
	}
	virtual ~Bird()
	{
		cout<<"Destructor bird... \n";
	}
	virtual void Sleep()
	{
		cout<<"bird like stand sleep. \n";
	}
};
class Pig:public Mammalia
{
public:
	Pig(int age):Mammalia(age)
	{
		cout<<"create Pig. \n";
	}
	virtual ~Pig()
	{
		cout<<"Destructor Pig... \n";
	}
	virtual void Sleep()
	{
		cout<<"The pig likes to sleep in the mud. \n";
	}
	virtual void Eat()
	{
		cout<<"Pigs are omnivorous animals. \n";
	}
};

int main()
{

	system("pause");
	return 0;
}