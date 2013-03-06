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
void print1(book one);
void print2(const book&two);
int main()
{
	book love("love","Jacky","001",34.1f);
	cout<<"call print1 function\n";
	print1(love);
	cout<<"call print2 function\n";
	print2(love);

	system ("pause");
	return 0;
}
void print1(book one)
{
	cout<<"book name: "<< one.GetTitle()<<"author: "<<one.GetAuthor()<<"number: "<<one.GetNumber()<<"price: "<<one.GetPrice()<<endl;
}

void print2(const book&two)
{
	cout<<"book name: "<< two.GetTitle()<<"author: "<<two.GetAuthor()<<"number: "<<two.GetNumber()<<"price: "<<two.GetPrice()<<endl;
}