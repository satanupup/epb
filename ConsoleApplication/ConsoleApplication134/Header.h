#include <iostream>
using namespace std;
class epbString 
{
public:
	epbString();
	~epbString()
	{
		std::cout<<"destructor exection\n";
		delete []str;len=0;
	}
	epbString(const char*const ch);
	
	int getlen()const{return len;}	
	friend ostream&operator<<(ostream&o,const epbString&str)
	{
		o<<str.str;
		return o;
	}
	friend istream&operator>>(istream&i,epbString&str)
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

epbString::epbString()
{
	cout<<"Constructor without arguments\n";
	len = 0;
	str = new char[1];
	str[0]='\0';
}
epbString::epbString(const char*const ch)
{
	cout<<"With a parameter constructor\n";
	len=strlen(ch);
	str=new char[len+1];
	for(int i=0;i<len;i++)
	{
		str[i]=ch[i];		
	}
	str[len]='\0';
}
epbString::epbString(unsigned short int length)
{
	cout<<"With a int parameter constructor\n";
	len=length;
	str=new char[len+1];
	for(int i=0;i<=len;i++)
	{
		str[i]='\0';		
	}	
}
char & epbString::operator[](unsigned short int length)
{	
	cout<<"operator[] execution\n";
	if(length>len)
	{
		return str[len-1];
	}
	else
		return str[length];
}
char epbString::operator[](unsigned short int length)const
{	
	cout<<"operator[] const execution\n";
	if(length>len)
	{
		return str[len-1];
	}
	else
		return str[length];
}
epbString::epbString(const epbString&rs)
{
	cout<<"copy constructor execution\n";
	len=rs.getlen();
	str=new char[len+1];
	for(int i=0;i<len;i++)
	{
		str[i]=rs[i];
	}
	str[len]='\0';
}
epbString & epbString::operator=(const epbString &s)
{
	cout<<"operator= execution\n";
	if(this==&s)
	{
		return *this;
	}
	delete []str;
	len=s.getlen();
	str=new char[len+1];
	for(int i=0;i<len;i++)
	{
		str[i]=s[i];
	}
	str[len]='\0';
	return *this;
}
epbString epbString::operator+(const epbString&s)
{
	
	cout<<"operator+ function is executed\n";
	int total=len+s.getlen();
	epbString temp(total);
	int i,j;
	for(i=0;i<len;i++)
	{
		temp[i]=str[i];
	}
	for(j=0;j<s.getlen();j++,i++)
	{
		temp[i]=s[j];
	}
	return temp;
}

void epbString::operator+=(const epbString&s)
{
	
	cout<<"operator+= function is executed\n";
	int total=len+s.getlen();
	epbString temp(total);
	int i,j;
	for(i=0;i<len;i++)
	{
		temp[i]=str[i];
	}
	for(j=0;j<s.getlen();j++,i++)
	{
		temp[i]=s[j];
	}
	*this=temp;
}