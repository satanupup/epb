#include <iostream>
#include <string>
using namespace std;
//<<  按位左移運算符
//num<<1 
//16進位00000001
//16進位00000010  往左移
//10進位變成2
//cout<< 輸出運算符 or 提取運算符
void main()
{
	int num=1;
	int x=num<<1;
	cout<<x;
	system("pause");
}
