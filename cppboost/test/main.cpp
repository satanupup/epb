
#include <stdio.h>
#include <string.h>
#include "IronShell.h"


//#define _DEBUG_


#ifdef _DEBUG_
#include "AddShell.h"

void Test()
{
	void AddShellTest();
	AddShellTest();
}

#endif


//////////////////////////////////////////////////////////////////////////////////
// main
//////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
	int i;
	if (argc<=1)
	{
		printf("Usage: IronShell [-e][-n] file1 file2 file3...\n");
		return -1;
	}

	for (i=1; i<argc; i++)
	{
		ToLower(argv[i]);
		if (argv[i][0]=='-')
		{
			if (strlen(argv[i])!=2)
			{
				printf("Usage: IronShell [-e][-n] file1 file2 file3...\n");
				return -1;
			}

			switch(argv[i][1])
			{
			case 'e':
				ProcessingEscapeCharacter=1;
				break;
			case 'n':
				ProcessingEscapeCharacter=0;
				break;
			}
		}
	}

	for (i=1; i<argc; i++)
	{
		if (strcmp(argv[i], CFILE)==0 || strcmp(argv[i], HFILE)==0)
		{
			printf("Name Error File[%d]=%s\n", i, argv[i]);
			return -1;
		}
	}

	FILE *catfile;
	FILE *hatfile;
	FILE *tatfile;
	catfile = fopen(CFILE, "w");
	hatfile = fopen(HFILE, "w");
	tatfile = fopen(TFILE, "w");
	IronShell_Init(catfile, hatfile, tatfile);

	for (i=1; i<argc; i++)
	{
		char* filename = argv[i];
		if (argv[i][0]!='-' && FileExist(filename))
		{
			printf("(%d) File = %s --> %s.out\n", i, filename, filename);
			IronShell_Making(filename, catfile, hatfile, tatfile);
		}
	}

	IronShell_Term(catfile, hatfile, tatfile);
	fclose(catfile);
	fclose(hatfile);
	fclose(tatfile);

#ifdef _DEBUG_

	Test();

#endif
	
	return 0;
}



