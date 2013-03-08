#include <iostream>
using namespace std;

typedef void (*HttpQueueOpen)(struct HttpQueue *q);

typedef struct HttpQueue {    
    char               *name;                 
    HttpQueueOpen       open;                 
} HttpQueue;
void abc(struct HttpQueue *q)
{
	printf("world\n");
}
void def(struct HttpQueue *q)
{
	printf("hello\n");
}
int main()
{
	HttpQueue q;
	q.open = abc;
	q.open(&q);
	
	q.open = def;
	q.open(&q);

system("pause");
return 0;
}
