#include <stdio.h>
#include <cstl/cvector.h>

int main()
{
	//vector conatiner for integer elements
	vector_t* pvec_coll = create_vector(int);
	int i=0;

	if(pvec_coll == NULL)
	{
		return -1;
	}
	vector_init(pvec_coll);

	for(i = 1; i <= 6; ++i)
	{
		vector_push_back(pvec_coll,i);
	}
	for(i = 0; i < vector_size(pvec_coll); ++i)
	{
		printf("%d ", *(int*)vector_at(pvec_coll,i));
	}
	printf("\n");
	vector_destroy(pvec_coll);
	system("pause");
	return 0;
}