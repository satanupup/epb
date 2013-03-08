
#include<iostream>
#define NULL 0
int* bsearch(int* t,int n,int x)
{ 
	int* lo=t, *hi=t+n;
	int *mid=0;
	if(x==*t) return t;
	for(lo,hi;lo!=hi-1;)
	{
		mid=lo+((hi-lo)>>1);
		if(x==*mid) 
			return mid;
		else if(x>*mid) 
			lo=mid;
		else if(x<*mid) 
			hi=mid;
		else if(x==*mid)
			return mid;
	}
	return NULL;
}

int main()
{ 
	int std[10]={1,2,3,4,5,6,7,8,9,10}; 
	int q=0;
	int* a=&std[0];
	std::cout<<"Please enter an integer, I will determine whether he is located internal"<<std::endl;
	for(;;) 
	{ 
		std::cin>>q;
		int* p=bsearch(a,10,q);
		if(p==(int*)0) 
			std::cout<<"This value is not found"<<q;
		else 
			printf("Found this value %d ,Is the first %d Elements",*p,p-a+1);
		printf("Do you want to continue to query it? If you would like to continue, please press the Y key, otherwise press N\n");
		char s='q';
		std::cin>>s;
		if(s=='Y'||s=='y')continue;
		else 
			return 0; 
	}
}