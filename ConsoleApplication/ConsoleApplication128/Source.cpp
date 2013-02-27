#include <iostream>
using namespace std;
class String 
{
public:
	String();
	~String()
	{
		cout<<"destructor exection\n";
		delete []str;len=0;
	}
	String(const char*const ch);
	
	int getlen()const{return len;}	
	friend ostream&operator<<(ostream&o,const String&str)
	{
		o<<str.str;
		return o;
	}
	friend istream&operator>>(istream&i,String&str)
	{
		i>>str.str;
		return i;
	}
	friend bool operator<(const String&str1,const String&str2)
	{
		if(strcmp(str1.str,str2.str)<0)
		{
			return 1;
		}
		return 0;
	}
	friend bool operator>(const String&str1,const String&str2)
	{
		if(strcmp(str1.str,str2.str)>0)
		{
			return 1;
		}
		return 0;
	}
	friend bool operator==(const String&str1,const String&str2)
	{
		if(strcmp(str1.str,str2.str)==0)
		{
			return 1;
		}
		return 0;
	}
	char &operator[](unsigned short int length);
	char operator[](unsigned short int length)const;
	String(const String&rs);
	String&operator=(const String &s);
	String operator+(const String&s);
	void operator+=(const String&s);
private:
	String(unsigned short int);
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
	}
	str[len]='\0';
}
String::String(unsigned short int length)
{
	cout<<"With a int parameter constructor\n";
	len=length;
	str=new char[len+1];
	for(int i=0;i<=len;i++)
	{
		str[i]='\0';		
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
String String::operator+(const String&s)
{
	
	cout<<"operator+ function is executed\n";
	int total=len+s.getlen();
	String temp(total);
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

void String::operator+=(const String&s)
{
	
	cout<<"operator+= function is executed\n";
	int total=len+s.getlen();
	String temp(total);
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
void main()
{
	//這個String類涉及的知識有邏輯運算符、IF語句、循環語句、類與對象、指針、引用、數組、函數和運算符重載
	String s1="hello world";
	cout<<s1.getlen()<<endl;
	String s2;
	s2=s1;
	cout<<s1<<" "<<s2<<endl;
	//cin>>s1>>s2;
	cout<<s1<<" "<<s2<<endl;
	char ch[11]="not at all";
	s1=ch;
	cout<<s1<<endl;
	String s3;
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
	String s4("a");
	cout<<"given the value "<<s1.getlen()<<" characters\n";
	s1=s4;
	cout<<"given the value "<<s1.getlen()<<" characters\n";

	system("pause");
}
