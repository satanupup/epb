#include "epbString.h"
epbString::epbString()
{
	std::cout<<"class String Constructor without arguments execution...\n";
	len = 0;
	str = new char[1];
	str[0]='\0';
}
epbString::epbString(const char*const ch)
{
	std::cout<<"class String With a parameter constructor execution...\n";
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
	std::cout<<"class String is With a int parameter constructor execution...\n";
	len=length;
	str=new char[len+1];
	for(int i=0;i<=len;i++)
	{
		str[i]='\0';		
	}	
}
char & epbString::operator[](unsigned short int length)
{	
	std::cout<<"class String is operator[] execution\n";
	if(length>len)
	{
		return str[len-1];
	}
	else
		return str[length];
}
char epbString::operator[](unsigned short int length)const
{	
	std::cout<<"class String is operator[] const execution\n";
	if(length>len)
	{
		return str[len-1];
	}
	else
		return str[length];
}
epbString::epbString(const epbString&rs)
{
	std::cout<<"class String is copy constructor execution\n";
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
	std::cout<<"class String is operator= execution\n";
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
	
	std::cout<<"class String is operator+ function is executed\n";
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
	
	std::cout<<"class String is operator+= function is executed\n";
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