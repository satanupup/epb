#include <stdio.h>
#include <cstl/cvector.h>

#ifdef _DEBUG  
#pragma comment(lib,"..\\Debug\\libcstl.lib")
#else 
#pragma comment(lib,"..\\Release\\libcstl.lib")
#endif // _DEBUG 


int main()
{
	vector_t* pvec_v1 = create_vector(int);

	if(pvec_v1 == NULL)
	{
		return -1;
	}

	vector_init(pvec_v1);

	vector_push_back(pvec_v1, 1);
	printf("Vector length is %d. \n",vector_size(pvec_v1));

	vector_push_back(pvec_v1, 2);
	printf("Vector length is now %d. \n", vector_size(pvec_v1));

	vector_destroy(pvec_v1);
	system("pause");

	return 0;
}