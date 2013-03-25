#include <stdio.h>
#include <stdlib.h>
#include <cstl/cstring.h>

#ifdef _DEBUG  
#pragma comment(lib,"..\\Debug\\libcstl.lib")
#else 
#pragma comment(lib,"..\\Release\\libcstl.lib")
#endif // _DEBUG 

int main()
{
	size_t t_end = 0;
	size_t t_index = 0;
	string_t* pstr_s = create_string();
	
	if(pstr_s == NULL)
	{
		return -1;
	}
	string_init_cstr(pstr_s, "C://Users//naseem//Desktop//test2//windows-x86-vsdebug//web//movie.mp4.mp3");
	
	t_end = string_length(pstr_s);
	t_index = string_find_last_of_cstr(pstr_s, ".", t_end);	
	pstr_s = string_substr(pstr_s,t_index,t_end);
	printf("%s", string_c_str(pstr_s));
	string_destroy(pstr_s);

	system("pause");
	return 0;
}
