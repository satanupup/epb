#include <iostream>
class epbString 
{
public:
	epbString();
	~epbString()
	{
		std::cout<<"class String destructor exection\n";
		delete []str;len=0;
	}
	epbString(const char*const ch);
	
	int getlen()const{return len;}	
	friend std::ostream&operator<<(std::ostream&o,const epbString&str)
	{
		o<<str.str;
		return o;
	}
	friend std::istream&operator>>(std::istream&i,epbString&str)
	{
		i>>str.str;
		return i;
	}
	friend bool operator<(const epbString&str1,const epbString&str2)
	{
		if(strcmp(str1.str,str2.str)<0)
		{
			return 1;
		}
		return 0;
	}
	friend bool operator>(const epbString&str1,const epbString&str2)
	{
		if(strcmp(str1.str,str2.str)>0)
		{
			return 1;
		}
		return 0;
	}
	friend bool operator==(const epbString&str1,const epbString&str2)
	{
		if(strcmp(str1.str,str2.str)==0)
		{
			return 1;
		}
		return 0;
	}
	char &operator[](unsigned short int length);
	char operator[](unsigned short int length)const;
	epbString(const epbString&rs);
	epbString&operator=(const epbString &s);
	epbString operator+(const epbString&s);
	void operator+=(const epbString&s);
private:
	epbString(unsigned short int);
	unsigned short int len;
	char*str;

};