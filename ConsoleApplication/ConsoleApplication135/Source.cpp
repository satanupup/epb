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

class InterNode:public Node
{
public:
	InterNode(Date*one,Node*next);
	~InterNode(){delete Next;delete thisdate;}
	virtual Node*insert(Date*one);
	virtual void print(){thisdate->print();Next->print();}
private:
	Date*thisdate;
	Node*Next;
};
InterNode::InterNode(Date*one,Node*next):thisdate(one),Next(next){}
Node*InterNode::insert(Date*one)
{
	int result=thisdate->compare(*one);
	switch(result)
	{
	case same:
	case large:
		{
			InterNode*NodeDate=new InterNode(one,this);
			return NodeDate;
		}
	case small:
		{
			Next = Next->insert(one);
			return this;
		}
	}
	return this;
}
class TailNode:public Node
{
public:
	virtual Node*insert(Date*one);
	virtual void print(){}
};
Node*TailNode::insert(Date*one)
{
	InterNode*datenode=new InterNode(one,this);
	return datenode;
}
class HeadNode:public Node
{
public:
	HeadNode();
	~HeadNode(){delete Next;}
	virtual Node*insert(Date*one);
	virtual void print(){Next->print();}
private:
	Node*Next;
};
Node*HeadNode::insert(Date*one)
{
	Next=Next->insert(one);
	return this;
}
HeadNode::HeadNode()
{
	Next=new TailNode;
}
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
	Date*pdate;
	int val;
	Label ll;
	for(;;)
	{
		cout<<"what val? (0 is stop) : ";
		cin>>val;
		if(!val)
		{
			break;
		}
		pdate=new Date(val);
		ll.insert(pdate);
	}
	ll.printall();
	system("pause");
	return 0;
}
