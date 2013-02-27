#include <stdio.h>
#include <stdlib.h>

static char *mapHyphen(char *str);

void main()
{	
	char bb[2] = "-";

    char *key;
	key = mapHyphen(bb);
	printf(key);
	
	system("pause");
}


static char *mapHyphen(char *str)
{
    char    *cp;

    for (cp = str; *cp; cp++) {
        if (*cp == '-') {
            *cp = '_';
        }
    }
    return str;
}
