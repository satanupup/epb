#include <iostream>
using namespace std;
namespace epb
{
	class get
	{
	public:
		int a[5];

	};
}
int main()
{
	epb::get one[5];
	for(int i=0;i<5;i++)
	{
		cin>>one[i].a[i];
	}
	for(int i=0;i<5;i++)
	{
		cout<<"one["<<i<<"]:";
		cout<<one[i].a[i]<<endl;

	}
	system("pause");
	return 0;
};
