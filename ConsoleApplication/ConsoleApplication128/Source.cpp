#include <iostream>
using namespace std;
class String 
{
public:
	String();
	String(const char*const ch);
	int getlen()const{return len;}
	const char*getstr()const{return str;}
	char &operator[](unsigned short int length);
	char operator[](unsigned short int length)const;
	String(const String&rs);
	String&operator=(const String &s);
private:
	unsigned short int len;
	char*str;

};
String::String()
{
	cout<<"Constructor without arguments\n";
	len = 0;
	str = new char[1];
	str[0]='\0';
}
String::String(const char*const ch)
{
	cout<<"With a parameter constructor\n";
	len=strlen(ch);
	str=new char[len+1];
	for(int i=0;i<len;i++)
	{
		str[i]=ch[i];
		str[len]='\0';
	}
}
char & String::operator[](unsigned short int length)
{	
	cout<<"operator[] execution\n";
	if(length>len)
	{
		return str[len-1];
	}
	else
		return str[length];
}
char String::operator[](unsigned short int length)const
{	
	cout<<"operator[] const execution\n";
	if(length>len)
	{
		return str[len-1];
	}
	else
		return str[length];
}
String::String(const String&rs)
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
String & String::operator=(const String &s)
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
void main()
{
	String s1("hello"),s2("name");
	s1="name";
	String s3;
	s1=s2=s3;
	cout<<"s1:"<<s1.getstr()<<endl;
	cout<<"s2:"<<s2.getstr()<<endl;
	cout<<"s3:"<<s3.getstr()<<endl;
	
	system("pause");
}
/*
//Example
String s;
cout<<"s:"<<s.getstr()<<"\t general "<<s.getlen()<<" character"<<endl;
String s1("study hard");
cout<<"s1:"<<s1.getstr()<<"\t general "<<s1.getlen()<<" character"<<endl;
char*temp="help me";
String s3(temp);
cout<<"s3:"<<s3.getstr()<<"\t general "<<s3.getlen()<<" character"<<endl;
cin>>s3[999];
cout<<"s3:"<<s3.getstr()<<"\t general "<<s3.getlen()<<" character"<<endl;
cout<<"s3[999]:"<<s3[999]<<endl;
String s4=s3;
cout<<"s4:"<<s4.getstr()<<"\t general "<<s4.getlen()<<" character"<<endl;
*/