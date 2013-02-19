#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s("give me");
	cout<<"s: "<<s<<endl;
	s.erase(2,2);
	cout<<"s: "<<s<<endl;
	s.erase(2);
	cout<<"s: "<<s<<endl;
	s.erase();
	cout<<"s: "<<s<<endl;
	system("pause");
	return 0;
}
