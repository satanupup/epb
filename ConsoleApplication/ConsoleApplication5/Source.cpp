#include <iostream>
using namespace std;

class num
{
public:
	num(){n=1;cout<<"篶硑ㄧ计磅︽\n";}
	num(int i){n=i;cout<<"盿把计篶硑ㄧ计磅︽\n";}
	num(const num&s){n=s.n;cout<<"狡籹篶硑ㄧ计磅︽\n";}
	~num(){cout<<"猂篶ㄧ计磅︽\n";}
	int get()const{return n;}
	void set(int x){n=x;}
	//num add(const num&r){return num(n+r.get());}
	const num operator+(const num&r){return num(n+r.get());}
	const num &operator++()
	{
		++n;				
		return *this;
	}
	const num operator++(int o)
	{
		num temp(*this);
		++n;
		return temp;
	}
	const num equal(const num&r){n=r.get();return *this;}
private:
	int n;
};

int main()
{
	num one(1),two(2);
	num three = one.equal(two);
	
	cout<<three.get()<<endl;


	system("pause");
	return 0;
}