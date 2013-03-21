#include <stdio.h>
#include <cstl/clist.h>
#pragma comment(lib,"..\\Debug\\libcstl.lib")
int main()
{
	
	// list container for character elements
	list_t* plist_coll = create_list(char);
	char c = '\0';

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

	//print all elements
	// - while there are elements
	// - print and remove the first element
	while(!list_empty(plist_coll))
	{
		printf("%c ", *(char*)list_front(plist_coll));
		list_pop_front(plist_coll);
	}
	printf("\n");

	list_destroy(plist_coll);

	system("pause");
	return 0;
}