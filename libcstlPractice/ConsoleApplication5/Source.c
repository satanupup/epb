#include <stdio.h>
#include <cstl/cmap.h>
#include <cstl/cutility.h>

#ifdef _DEBUG  
#pragma comment(lib,"..\\Debug\\libcstl.lib")
#else 
#pragma comment(lib,"..\\Release\\libcstl.lib")
#endif // _DEBUG 

int main()
{
	//multimap container for int/c-string value
	multimap_t* pmmap_coll = create_multimap(int, char*);
	multimap_iterator_t it_pos;
	pair_t* ppair_elem = create_pair(int, char*);
	
	if(pmmap_coll == NULL || ppair_elem == NULL)
	{
		return -1;
	}

	multimap_init(pmmap_coll);
	pair_init(ppair_elem);

	//insert some elements in arbitray order
	// - a value with key 1 gets inserted twice
	pair_make(ppair_elem, 5, "tagged");
	multimap_insert(pmmap_coll, ppair_elem);
	pair_make(ppair_elem, 2, "a");
	multimap_insert(pmmap_coll, ppair_elem);
	pair_make(ppair_elem, 1, "this");
	multimap_insert(pmmap_coll, ppair_elem);
	pair_make(ppair_elem, 4, "of");
	multimap_insert(pmmap_coll, ppair_elem);
	pair_make(ppair_elem, 6, "strings");
	multimap_insert(pmmap_coll, ppair_elem);
	pair_make(ppair_elem, 1, "is");
	multimap_insert(pmmap_coll, ppair_elem);
	pair_make(ppair_elem, 3, "ppair_elem");
	multimap_insert(pmmap_coll, ppair_elem);

	//print all element values
	// - iterate over all elements
	// - element member second is vaule
	for(it_pos = multimap_begin(pmmap_coll);
		!iterator_equal(it_pos, multimap_end(pmmap_coll));
		it_pos = iterator_next(it_pos))
	{
		printf("%s ", (char*)pair_second(iterator_get_pointer(it_pos)));
	}
	printf("\n");

	multimap_destroy(pmmap_coll);
	pair_destroy(ppair_elem);

	system("pause");
	return 0;
}