#include <iostream>
#include <string>
using namespace std;

class book{
public:
	int num;
	float price;
	book*next;
};

book*head=NULL;

bool check(string str)
{
	int rrnum=str.length();
	for(int i=0;i<rrnum;i++)
	{
		if((str[i]>'9'||str[i]<'0')&&(str[i]!='.'))
			return false;
	}
	return true;

}
book*creat()
{
	book*p1,*p2;
	p1=new book;
	head=p1;
	p2=p1;
	cout<<"請輸入圖書的編號, 以 0 結束"<<endl;
	string str;
	cin>>str;
	while(!check(str))
	{
		cout<<"輸入的不是數字.請重新輸入,按0返回!!!"<<endl;
		cin>>str;
	}
	p1->num=atoi(str.c_str());
	
	if(p1->num!=0)
	{
		cout<<"請輸入圖書的價格"<<endl;		
		cin>>str;
		while(!check(str))
		{
			cout<<"輸入的不是數字.請重新輸入,按0返回!!!"<<endl;
			cin>>str;
		}
		p1->price=(float)atof(str.c_str());
	}
	else
	{
		delete p1;
		p2=NULL;
		p2->next=NULL;
		head=NULL;
		return head;
	}
	while(p1->num!=0)
	{
		p2 = p1;
		p1 = new book;
		cout<<"請輸入圖書的編號, 以 0 結束"<<endl;		
		cin>>str;
		while(!check(str))
		{
			cout<<"輸入的不是數字.請重新輸入,按0返回!!!"<<endl;
			cin>>str;
		}
		p1->num=atoi(str.c_str());
		if(p1->num!=0)
		{
			cout<<"請輸入圖書的價格"<<endl;
			cin>>str;
			while(!check(str))
			{
				cout<<"輸入的不是數字.請重新輸入,按0返回!!!"<<endl;
				cin>>str;
			}
			p1->price=(float)atof(str.c_str());
			
		}
		p2->next=p1;
	}
	delete p1;
	p2->next=NULL;
	return head;
}
void showbook(book*head)
{
	cout<<endl;
	cout<<"圖書信息如下： "<<endl;
	while(head)
	{
		cout<<"圖書編號: "<<head->num<<"\t";
		cout<<"price: "<<head->price<<endl;
		head=head->next;
	}
}
void Delete(book*head,int num)
{
	book*l;
	if(head->num==num)
	{
		l=head;
		head=head->next;
		::head=head;
		delete l;
		cout<<"操作成功"<<endl;
		return;
	}
	while(head)
	{
		if(head->next==NULL)
		{
			cout<<"找不到要刪除的編號 "<<endl;
			return;
		}
		if(head->next->num==num)
		{
			l=head->next;
			head->next=l->next;
			delete l;
			cout<<"操作成功"<<endl;
			return;
		}
		head=head->next;
	}
	cout<<"找不到要刪除的編號"<<endl;
}
void insert(book*head,int num,float price)
{
	book*list=new book;	
	list->num=num;
	list->price=price;
	if(num<=head->num)
	{
		list->next=head;
		::head=list;
		return;
	}
	book*temp=NULL;
	while((num>head->num)&&(head->next!=NULL))
	{
		temp=head;
		head=head->next;
	}
	if(num>head->num)
	{
		head->next=list;
	}
	else
	{
		temp->next=list;
		list->next=head;
	}
}
int main()
{
	

	head=creat();
	showbook(head);
	cout<<"請輸入你要刪除的圖書編號: ";
	int BookNum;
	cin>>BookNum;
	Delete(head,BookNum);
	showbook(head);
	cout<<"請輸入您要插入的圖書編號: ";
	cin>>BookNum;
	cout<<"請輸入您要插入的價格: ";
	float BookPrice;
	cin>>BookPrice;
	insert(head,BookNum,BookPrice);
	showbook(head);
	system("pause");
	return 0;
};
