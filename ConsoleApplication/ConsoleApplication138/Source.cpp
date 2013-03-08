#include <iostream>
#include <limits>
using namespace std;

class Date
{
public:
	Date(int Number,float Price):number(Number),price(Price){}
	float GetPrice()const{return price;}
	int GetNumber()const{return number;}
	virtual void print()const=0;
	virtual ~Date(){}
private:
	int number;
	float price;
};
class Book:public Date
{
public:
	Book(int Number,float Price):Date(Number,Price){}
	virtual void print()const
	{
		cout<<"Book is Number is: "<<GetNumber()<<endl;
		cout<<"Book is Price is: "<<GetPrice()<<endl;
	}
private:
};
class Drug:public Date
{
public:
	Drug(int Number,float Price):Date(Number,Price){}
	virtual void print()const
	{
		cout<<"Drug is Number is: "<<GetNumber()<<endl;
		cout<<"Drug is Price is: "<<GetPrice()<<endl;
	}
private:
};
class Node
{
public:
	Node(Date*pDate):itsDate(pDate),itsNext(0){}
	~Node(){delete itsDate;itsDate=0;}
	void SetNext(Node*node){itsNext=node;}
	Node*GetNext()const{return itsNext;}
	Date*GetDate()const
	{
		if(itsDate)
		{
			return itsDate;
		}
		else
			return NULL;
	}
private:
	Date*itsDate;
	Node*itsNext;
};
class List
{
public:
	List():head(0),count(0){}
	~List();
	Date*GetFirst()const;
	Date*operator[](int)const;
	void show()const;
	int GetCount()const{return count;}
	void InSert(Date*);
	void Delete(int num);
	Date*Find(int number)const;
private:
	Node*head;
	int count;
};
List::~List()
{
	Node*l=head;
	Node*m=0;
	int n=0;
	while(l)
	{
		m=l;
		l=l->GetNext();
		delete m;
		n++;
		cout<<"delete the first "<<n<<" nodes\n";
	}
}
Date*List::GetFirst()const
{
	if(head)
	{
		return head->GetDate();
	}
	else
		return NULL;
}
Date*List::operator[](int offset)const
{
	Node*pn=head;
	if(!head)
	{
		return NULL;
	}
	if(offset >= count)
	{
		return NULL;
	}
	for(int i=0;i<offset;i++)
	{
		pn=pn->GetNext();
	}
	return pn->GetDate();
}
void List::show()const
{
	if(!head)
	{
		return ;
	}
	Node*pn=head;
	do
	{
		pn->GetDate()->print();
	} while(pn=pn->GetNext());
}
void List::InSert(Date*pDate)
{
	Node*pn=new Node(pDate);
	Node*pNow=head;
	Node*pNext=0;
	int New=pDate->GetNumber();
	int next=0;
	count++;
	if(!head)
	{
		head=pn;
		return;
	}
	if(head->GetDate()->GetNumber() > New)
	{
		pn->SetNext(head);
		head=pn;
		return;
	}
	for(;;)
	{
		if(!pNow->GetNext())
		{
			pNow->SetNext(pn);
			return;
		}
		pNext=pNow->GetNext();
		next=pNext->GetDate()->GetNumber();
		if(next > New)
		{
			pNow->SetNext(pn);
			pn->SetNext(pNext);
			return;
		}
		pNow=pNext;
	}
}
void List::Delete(int num)
{
	Node*pBack=head;
	Node*pNow=head;
	if(!head)
	{
		cout<<"No data can be deleted! \n";
		return;
	}
	if(head->GetDate()->GetNumber() == num)
	{
		if(!head->GetNext())
		{
			delete head;
			cout<<"Data is cleared! \n";
			head=0;
			count--;
			return;
		}
		else
		{
			head=head->GetNext();
			delete pNow;
			pNow=0;
			cout<<"Deleted successfully! \n";
			count--;
			return;
		}
	}
	while(pBack)
	{
		if(pBack->GetNext() == NULL)
		{
			cout<<"Can not find the number you want to delete. \n";
			return;
		}
		if(pBack->GetNext()->GetDate()->GetNumber() == num)
		{
			pNow=pBack->GetNext();
			pBack->SetNext(pNow->GetNext());
			delete pNow;
			cout<<"Successful delete data! \n";
			count--;
			return;
		}
		pBack=pBack->GetNext();
	}
	cout<<"This number is not exist! \n";
}
Date*List::Find(int number)const
{
	Node*pn=0;
	for(pn=head;pn!=NULL;pn=pn->GetNext())
	{
		if(pn->GetDate()->GetNumber()==number)
		{
			break;
		}
	}
	if(pn==NULL)
	{
		return NULL;
	}
	else
		return pn->GetDate();
}
int main()
{
	List pl;
	Date*pDate=0;
	int number;
	float price;
	int choice;
	bool quit=false;
	while(1)
	{
		system("cls");
		cout<<"(1)Increasing commodity (2)List All Products (3)Remove items (4)Find products (5)Number of commodities (6)Quit:";
		cin>>choice;
		switch(choice)
		{
		case 1:
			while(1)
			{
				cout<<"(0)Return (1)Book (2)Drugs:";
				cin>>choice;
				if(!choice)
				{
					break;
				}
				else if(choice == 1 || choice == 2)
				{
					cout<<"please enter number:";
					cin>>number;
					if(choice == 1)
					{
						cout<<"please enter book price:";
						cin>>price;
						pDate = new Book(number,price);
						pl.InSert(pDate);
					}
					else if (choice == 2)
					{
						cout<<"please enter drugs price:";
						cin>>price;
						pDate = new Drug(number,price);
						pl.InSert(pDate);
					}
					else
					{
						cout<<"please enter 0-2 number between\n";
					}
				}
			}
			break;
		case 2:
			if(pl.GetFirst()==0)
			{
				cout<<"your merchandise is empty, increasing commodity, \n"<<"press the enter key to return to the main window"<<endl;
				cin.get();
				cin.get();
			}
			else
			{
				pl.show();
				cout<<"please enter return main window"<<endl;
				cin.get();
				cin.get();
			}
			break;
		case 3:			
			cout<<"please enter the product number you want to delete"<<endl;
			cin>>number;
			pl.Delete(number);
			cin.get();
			cin.get();
			break;
		case 4:

			while(1)
			{
				cout<<"(0)Return (1)query by number (2)query by serial:";
				cin>>choice;
				if(!choice)
				{
					break;
				}
				else if(choice == 1 || choice == 2)
				{					
					if(choice == 1)
					{
						cout<<"please enter the number to want to find places Goods:"<<endl;
						cin>>number;
						Date*result=pl.Find(number);
						if(result==0)
						{
							cout<<"This number can not be found. \n";
						}
						else
							result->print();
					}
					else if (choice == 2)
					{
						cout<<"please enter the data you wnat to find the serial number:"<<endl;
						cin>>number;
						if(pl[number-1])
						{
							pl[number-1]->print();
						}
						else
							cout<<"can not find the data you want to query. \n";						
					}					
				}
				else
						cout<<"please enter 0-2 number between\n";
			}
			break;
		case 5:
			cout<<"The link table Total "<<pl.GetCount()<<" node\n";
			cin.get();
			cin.get();
			break;
		case 6:
			quit = true;
			break;
		default:
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout<<"you can enter a number between 1-6,please re-enter"<<endl<<"press Enter to go back and re-entry"<<endl;
			cin.get();
			break;
		}
		if(quit)
		{
			cout<<"The end of the program\n";
			break;
		}
	}
	system("pause");
	return 0;
}
