#include <iostream>
using namespace std;
//c
/*
struct book{
	int num;
	float price;
	struct book*next;
};*/
//c++
class book{
public:
	int num;
	float price;
	book*next;
};

int main()
{
//c
	/*
	void*p=malloc(sizeof(book));
	free(p);*/
//c++
	book*p=new book;
	delete p;

	system("pause");
	return 0;
};
