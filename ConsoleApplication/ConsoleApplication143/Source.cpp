#include <iostream>
using namespace std;

class dicedate
{
public:
	dicedate(){		
		memset(Role_Name,0,256);
		memset(Dice_reasons,0,1024);
		memset(Quantity,0,256);
		memset(Dice_face,0,256);
		memset(Adjusted_value,0,256);
	}
	char Role_Name[256];
	char Dice_reasons[1024];
	char Quantity[256];
	char Dice_face[256];
	char Adjusted_value[256];
};
typedef struct
{
	int a;
	int b;
	int (* callback)(int a,int b);
}struct_b;
int mylib(struct_b );
int add(int a,int b);

void cbfunc()
{
	printf("called");
}

int main()
{	
	dicedate ch;
	sprintf_s(ch.Role_Name,"apple");
	cout<<ch.Role_Name<<endl;

	void (*callback)();
	callback = &cbfunc;
	callback();
	
	//int a,b;
	struct_b st_b;

	//Here u r passing higher level function to lower level function through structure
	st_b.callback = add;
	st_b.a = 10;
	st_b.b = 12;
	printf("\nsum of a and b is = %d",mylib(st_b));
	
	system("pause");
	return 0;
}
/*This is ur higher level function definition*/
int add(int a,int b)
{
	return a+b;
}

int mylib(struct_b st_b)
{
	/*Here u r calling higher level function with the help of call back function*/
	return st_b.callback(st_b.a,st_b.b);
}