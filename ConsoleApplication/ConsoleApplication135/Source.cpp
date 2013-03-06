#include <iostream>
using namespace std;
enum{small,large,same};
class Date
{
public:
	Date(int i):date(i){}
	~Date(){}
	int compare(const Date&);
	void print(){cout<<date<<endl;}
private:
	int date;
};
int Date::compare(const Date&two)
{
	if(date<two.date)	
		return small;
	if(date>two.date)
		return large;
	else
		return same;
	
}
class Node
{
public:
	Node(){}
	virtual ~Node(){}
	virtual Node*insert(Date*one)=0;
	virtual void print()=0;
};
class Label
{
public:
	Label();
	~Label(){delete head;}
	void insert(Date*one);
	void printall(){head->print();}
private:
	HeadNode *head;
};
Label::Label()
{
	head=new HeadNode;
}
void Label::insert(Date*one)
{
	head->insert(one);
}

int main()
{

	system("pause");
	return 0;
}
