#include <stdio.h>
#include <cstl/cdeque.h>

#ifdef _DEBUG  
#pragma comment(lib,"..\\Debug\\libcstl.lib")
#else 
#pragma comment(lib,"..\\Release\\libcstl.lib")
#endif // _DEBUG 

int main()
{
	
	// deque container for float-point elements
	deque_t* pdq_coll = create_deque(float);
	int i=0;
	int deqs = 0;

	if(pdq_coll == NULL)
	{
		return -1;
	}

	deque_init(pdq_coll);

	// insert elements form 1.1 to 6.6 each at the front
	for(i = 1; i <= 6; ++i)
	{
		//insert at the front
		deque_push_front(pdq_coll, i * 1.1 );
	}
	deqs = deque_size(pdq_coll);
	//print all elements followed by a space
	for(i = 0; i < deqs; ++i)
	{
		printf("%f ", *(float*)deque_at(pdq_coll, i));
	}
	printf("\n");
	deque_destroy(pdq_coll);

	system("pause");
	return 0;
}