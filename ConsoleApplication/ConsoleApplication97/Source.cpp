#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1 = "155";
	string s2 = "52";
	char c[] = "34";
	int i,j,k,l,m,n;
	i = s1.compare(s2);
	j = s2.compare(c);
	k = s1.compare(0,2,s2);
	l = s1.compare(1,1,s2,0,1);
	m = s1.compare(1,1,c,0,1);
	n = s1.compare(1,1,c,1);
	// 將 s1 與 s2 的第一個元素 比較 , 0 為相等 , 1 為 s1 大於 s2 , -1 為 s1 小於 s2
	cout<<s1<<":"<<s2<<"="<<i<<endl;
	cout<<s2<<":"<<c<<"="<<j<<endl;
	cout<<s1[0]<<s1[1]<<":"<<s2<<"="<<k<<endl;
	cout<<s1[1]<<":"<<s2[0]<<"="<<l<<endl;
	cout<<s1[1]<<":"<<c[0]<<"="<<m<<endl;
	cout<<s1[1]<<":"<<c[0]<<"="<<n<<endl;

	system("pause");
	return 0;
}
