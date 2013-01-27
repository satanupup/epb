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
	int rrnum = str.length();
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
		//p2->next=NULL;
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
		list->next=NULL;
	}
	else
	{
		temp->next=list;
		list->next=head;
	}
}
int getBookNum(book*head)
{
	int num=0;
	while(head)
	{
		num++;
		head=head->next;
	}
	return num;
}
int main()
{
	string str;
begin:
	cout<<"1->重建圖書2->顯示圖書3->插入圖書4->刪除圖書5->圖書數目Q->離開"<<endl;
	cin>>str;
	if(str[0]=='1')
	{
		::head=creat();
		system("cls");
		goto begin;
	}
	else if(str[0]=='2')
	{
		if(head==NULL)
		{
			cout<<"您的圖書現在是空的，請增加圖書"<<endl<<"按確定返回主程序"<<endl;
			cin.get();
			cin.get();
			system("cls");
			goto begin;
		}
		showbook(head);
	}
	else if(str[0]=='3')
	{
		if(head==NULL)
		{
			cout<<"您的圖書現在是空的，請增加圖書"<<endl<<"按確定返回主程序"<<endl;
			cin.get();
			cin.get();
			system("cls");
			goto begin;
		}
		cout<<"請輸入要插入的圖書編號, 以 0 返回"<<endl;
		string str;
		int num;
		float price;
		cin>>str;
		while(!check(str))
		{
			cout<<"輸入的不是數字.請重新輸入,按0返回!!!"<<endl;
			cin>>str;
		}
		num=atoi(str.c_str());
	
		if(num!=0)
		{
			cout<<"請輸入圖書的價格"<<endl;		
			cin>>str;
			while(!check(str))
			{
				cout<<"輸入的不是數字.請重新輸入,按0返回!!!"<<endl;
				cin>>str;
			}
			
			price=(float)atof(str.c_str());
		}
		else
		{
			system("cls");
			goto begin;
		}
		insert(head,num,price);
		cout<<"操作完畢，按確定返回主程序"<<endl;
	}	
	else if(str[0]=='4')
	{
		if(head==NULL)
		{
			cout<<"您的圖書現在是空的，請增加圖書"<<endl<<"按確定返回主程序"<<endl;
			cin.get();
			cin.get();
			system("cls");
			goto begin;
		}
		cout<<"請輸入要刪除的圖書編號, 以 0 返回"<<endl;
		string str;
		int num;
		
		cin>>str;
		while(!check(str))
		{
			cout<<"輸入的不是數字.請重新輸入,按0返回!!!"<<endl;
			cin>>str;
		}
		num=atoi(str.c_str());
	
		Delete(head,num);
		cout<<"操作完畢，按確定返回主程序"<<endl;
	}
	else if(str[0]=='5')
	{
		cout<<"圖書數目是: "<<getBookNum(head)<<endl<<"按確定鍵返回主程序"<<endl;
		cin.get();
		cin.get();
		system("cls");
		goto begin;
	}
	else
	{
		if(str[0]!='Q'&&str[0]!='q')
		{
			cout<<"請輸入數字!按確定返回繼續操作";
		}
	}
	if(str[0]!='Q'&&str[0]!='q')
	{
		cin.get();
		cin.get();
		system("cls");
		goto begin;
	}

	system("pause");
	return 0;
};
