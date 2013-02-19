#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str = "abcdefghijklmn";
	char ch2[] = "1234567890";
	cout<<"str1: "<<ch2<<endl;
	int n = str.copy(ch2,10,0);
	cout<<"copy "<<n<<endl;
	cout<<"str1: "<<ch2<<endl;
	system("pause");
	return 0;
}
