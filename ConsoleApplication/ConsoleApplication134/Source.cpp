#include <iostream>
#include "epbString.h"
using namespace std;


class book
{
public:
	book();
	~book(){cout<<"class book destructor is executed...\n";}
	book(char*,char*,char*,float);
	const epbString& GetTitle()const{return title;}//加上別名避免複製構造函數
	const epbString& GetAuthor()const{return author;}
	epbString& GetAuthor(){return author;}
	const epbString& GetNumber()const{return number;}
	float GetPrice()const{return price;}
	void SetTitle(const epbString&Stitle){title=Stitle;}
	void SetAuthor(const epbString&Sauthor){author=Sauthor;}
	void SetNumber(const epbString&Snumber){number=Snumber;}
	void SetPrice(float Sprice){price=Sprice;}
	void Settotal(const epbString&T,const epbString&A,const epbString&N,float P)
	{
		title = T;
		number = N;
		author = A;
		price = P;
	}
private:
	epbString title;
	epbString author;
	epbString number;
	float price;
};
book::book():title(""),author(""),number(""),price(0)
{
	cout<<"class book with no arguments constructor execution\n";
}
book::book(char*Title,char*Author,char*Number,float Price):title(Title),author(Author),number(Number),price(Price)
{
	cout<<"the book with parameters constructor execution\n";
}
int main()
{
	book love("love","Jacky","001",34.1f);
	cout<<"book name: "<<love.GetTitle()<<"author: "<<love.GetAuthor()<<"number: "<<love.GetNumber()<<"price: "<<love.GetPrice()<<endl;
	love.Settotal("hate","Rose","002",56.2f);
	cout<<"book name: "<<love.GetTitle()<<"author: "<<love.GetAuthor()<<"number: "<<love.GetNumber()<<"price: "<<love.GetPrice()<<endl;
	book hate;
	hate=love;
	cout<<"book name: "<<hate.GetTitle()<<"author: "<<hate.GetAuthor()<<"number: "<<hate.GetNumber()<<"price: "<<hate.GetPrice()<<endl;
	if(love.GetNumber() == hate.GetNumber())
	{
		cout<<"The same number of two books \n";
	}
	else
	{
		cout<<"Number two books are not the same \n";
	}
	hate.SetNumber("003");
	if(love.GetNumber() == hate.GetNumber())
	{
		cout<<"The same number of two books \n";
	}
	else
	{
		cout<<"Number two books are not the same \n";
	}
	epbString LoveAndhate=love.GetAuthor()+hate.GetAuthor();
	book LoveHate;
	LoveHate.SetAuthor(LoveAndhate);
	LoveHate.SetTitle("new book");
	cout<<LoveHate.GetTitle()<<"is author: "<<LoveHate.GetAuthor()<<endl;



	system ("pause");
	return 0;
}

//example
/*

//這個String類涉及的知識有邏輯運算符、IF語句、循環語句、類與對象、指針、引用、數組、函數和運算符重載
epbString s1="hello world";
cout<<s1.getlen()<<endl;
epbString s2;
s2=s1;
cout<<s1<<" "<<s2<<endl;
//cin>>s1>>s2;
cout<<s1<<" "<<s2<<endl;
char ch[11]="not at all";
s1=ch;
cout<<s1<<endl;
epbString s3;
cout<<s1[999];
s1>s2;
s1<s2;
s1==s2;
s3=s1+s2;
cout<<"s3:"<<s3<<endl;
cout<<"plus equal to the previous,the length of s1: "<<s1.getlen()<<" characters\n";
s1+=s2;
cout<<"added is equal to the length of s1: "<<s1.getlen()<<" characters\n";	
cout<<"s1:"<<s1<<endl;
epbString s4("a");
cout<<"given the value "<<s1.getlen()<<" characters\n";
s1=s4;
cout<<"given the value "<<s1.getlen()<<" characters\n";


*/