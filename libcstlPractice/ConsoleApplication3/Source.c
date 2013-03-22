#include <stdio.h>
#include <cstl/clist.h>

#ifdef _DEBUG  
#pragma comment(lib,"..\\Debug\\libcstl.lib")
#else 
#pragma comment(lib,"..\\Release\\libcstl.lib")
#endif // _DEBUG 

int main()
{
	//list container for character elements
	list_t* plist_coll = create_list(char);
	list_iterator_t it_pos;
	char c= '\0';

	if(plist_coll == NULL)
	{
		return -1;
	}

	list_init(plist_coll);

	//append elements from 'a' to 'z'
	for(c = 'a'; c <= 'z'; ++c)
	{
		list_push_back(plist_coll, c);
	}
	
	// print all elements
	// - iterate over all elements
	for(it_pos = list_begin(plist_coll);
		!iterator_equal(it_pos, list_end(plist_coll));
		it_pos = iterator_next(it_pos))
	{
		printf("%c ", *(char*)iterator_get_pointer(it_pos));
	}
	printf("\n");

	list_destroy(plist_coll);


	system("pause");
	return 0;
}