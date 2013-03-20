#include <stdio.h>
#include <stdlib.h>
#include <cstl/cstring.h>
#include <cstl/cvector.h>
#include <cstl/calgorithm.h>
static void _print(const void* cpv_input, void* pv_output)
{
	printf("%s ", (char*)cpv_input);
}
int main()
{
	vector_t* pvec_sentence = create_vector(char*);
	vector_iterator_t it_pos;
	if(pvec_sentence == NULL)
	{
		return -1;
	}
	vector_init(pvec_sentence);
	/* reserve memory for five elements to avoid reallocation */
	vector_reserve(pvec_sentence, 5);
	/* append some element */
	vector_push_back(pvec_sentence, "Hello,");
	vector_push_back(pvec_sentence, "how");
	vector_push_back(pvec_sentence, "are");
	vector_push_back(pvec_sentence, "you");
	vector_push_back(pvec_sentence, "?");
	/* print all elements with space */
	algo_for_each(vector_begin(pvec_sentence), vector_end(pvec_sentence), _print);
	printf("\n");
	/* print technial data */
	printf("max size: %u\n", vector_max_size(pvec_sentence));
	printf("size : %u\n", vector_size(pvec_sentence));
	printf("capacity: %u\n", vector_capacity(pvec_sentence));
	/* swap the second and fourth elements */
	algo_iter_swap(iterator_next(vector_begin(pvec_sentence)),
		iterator_next_n(vector_begin(pvec_sentence), 3));
	/* insert "always" before "?" */
	it_pos = algo_find(vector_begin(pvec_sentence), vector_end(pvec_sentence), "?");
	vector_insert(pvec_sentence, it_pos, "always");
	/* print all elements with space */
	algo_for_each(vector_begin(pvec_sentence), vector_end(pvec_sentence), _print);
	printf("\n");
	/* print technial data again */
	printf("max size: %u\n", vector_max_size(pvec_sentence));
	printf("size : %u\n", vector_size(pvec_sentence));
	printf("capacity: %u\n", vector_capacity(pvec_sentence));
	vector_destroy(pvec_sentence);

	system("pause");
	return 0;
}
