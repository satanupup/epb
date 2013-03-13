
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "IronShell.h"

//////////////////////////////////////////////////////////////////////////////////
// Table & Stack
//////////////////////////////////////////////////////////////////////////////////

#define KEYWORDSIZE 10240
char Keyword[KEYWORDSIZE][LenShort];
char Replace[KEYWORDSIZE][LenShort];

int ProcessingEscapeCharacter = 1;
int KeywordCC = 0;

void TableInit()
{
	KeywordCC = 0;
}


#define STACKSIZE 128

int Stack[STACKSIZE];
int *StackTop;
int *StackBot;
int *StackCurr;

void StackInit()
{
	StackTop = Stack + STACKSIZE - 1;
	StackBot = Stack;
	StackCurr = Stack - 1;
}

void Push(int val)
{
	if (StackCurr >= StackTop) 
	{
		printf("Stack Overflow.\n");
		return;
	}
	*(++StackCurr) = val;
}

int Pop()
{
	if (StackCurr < StackBot) 
	{
		printf("Stack Underflow.\n");
		return -1;
	}
	return *StackCurr--;
}

int GetStackTop()
{
	if (StackCurr < StackBot) 
	{
		return -1;
	}
	return *StackCurr;
}

int GetStackLevel()
{
	return (StackCurr - StackBot);
}

void StackTest()
{
	StackInit();
	Push(1);
	Push(2);
	Push(3);
	printf("StackPop: %d\n", Pop());
	printf("StackPop: %d\n", Pop());
	Push(4);
	Push(5);
	Push(6);
	printf("StackPop: %d\n", Pop());
	printf("StackPop: %d\n", Pop());
	printf("StackPop: %d\n", Pop());
	printf("StackPop: %d\n", Pop());
	printf("StackPop: %d\n", Pop());
}



//////////////////////////////////////////////////////////////////////////////////
// Token
//////////////////////////////////////////////////////////////////////////////////

#define TOKEN_ERROR   (-1)
#define TOKEN_EMPTY   0
#define TOKEN_SUCCESS 1

static char *_TOKEN;
static char NulDelim[] = " \t()[]*+-&|=,\n\r<>:?~^";
static char KeyDelim[] = ";{}/\"'#";
static char nulmap[32];
static char keymap[32];

static int hit_string = FALSE;
static int hit_char = FALSE;
static int hit_commstar = FALSE;
static int hit_commslsl = FALSE;
static int cnt_include = 0;

void TokenInit()
{
	char *ctrl;
	int i;
	for (i=0; i<32; i++)
	{
		nulmap[i] = 0;
		keymap[i] = 0;
	}

	// Set bits in delimiter table 
	ctrl = NulDelim;
	do {              
		nulmap[*ctrl >> 3] |= (1 << (*ctrl & 7));
	} while (*ctrl++);
	
	ctrl = KeyDelim;
	do {              
		keymap[*ctrl >> 3] |= (1 << (*ctrl & 7));
	} while (*ctrl++);
}

void TokenReset()
{
	hit_string = FALSE;
	hit_char = FALSE;
	hit_commstar = FALSE;
	hit_commslsl = FALSE;
	cnt_include = 0;
}

char *Token(char *string, int *result)
{
	char *str;

	// Initialize str pointer
	if (string)               
		str = string;
	else              
		str = _TOKEN;

	// Find beginning of token
	if (!hit_commstar)
	{
		while ((nulmap[*str >> 3] & (1 << (*str & 7))) && *str)
			str++;
	}
	string = str;

	// Find the end of the token
	while (*str)
	{
		if (hit_string)
		{
			if (*str=='\\' && *(str+1)=='"')
			{
				str++;
			}
			else if (*str=='"')
			{
				hit_string = FALSE;
				*str = '\0';
				break;
			}
			str++;
			continue;
		}
		if (hit_char)
		{
			if (*str=='\\' && *(str+1)=='\'')
			{
				str++;
			}
			else if (*str=='\'')
			{
				hit_char = FALSE;
				*str = '\0';
				break;
			}
			str++;
			continue;
		}
		else if (hit_commstar)
		{
			if (*str=='*' && *(str+1)=='/')
			{
				hit_commstar = FALSE;
				*str++ = '\0';
			}
			*str++ = '\0';
			string = str;
			continue;
		}
		else if (hit_commslsl)
		{
			*str++ = '\0';
			string = str;
			continue;
		}

		int ended = FALSE;
		if (keymap[*str >> 3] & (1 << (*str & 7)))
		{
			switch (*str)
			{
			case ';':
				ended = TRUE;
				break;
			case '{':
				ended = TRUE;
				break;
			case '}':
				ended = TRUE;
				break;
			case '/':
				switch(*(str+1))
				{
				case '*':
					hit_commstar = TRUE;
					break;
				case '/':
					hit_commslsl = TRUE;
					break;
				}
				*str++ = '\0';
				string = str;
				break;
			case '"':
				hit_string = TRUE;
				break;
			case '\'':
				hit_char = TRUE;
				break;
			case '#':
				cnt_include = 1;
				ended = TRUE;
				break;
			}
		}

		// Find the end
		if (ended)
		{
			if (string == str)
			{
				*str++ = '\0';
				string = str;
				continue;
			}
			else
			{
				*str = '\0';
				break;
			}
		}
		else if (!hit_commstar && (nulmap[*str >> 3] & (1 << (*str & 7))))
		{
			*str = '\0';
			break;
		}

		str++;
	}
	// Update nextoken
	_TOKEN = str + 1;

	// Determine if a token has been found 
	if (string == str)
	{
		if (hit_commslsl)
		{
			hit_commslsl = FALSE;
		}
		*result = TOKEN_EMPTY;
		return NULL;
	}
	else
	{
		if (cnt_include==1 && strcmp(string, "include")==0)
		{
			cnt_include=2;
		}
		else if (cnt_include==2)
		{
			cnt_include=3;
		}
		else
		{
			cnt_include=0;
		}
		*result = TOKEN_SUCCESS;
		
		/*
		printf("%s\n", string);
		if (KeywordCC<KEYWORDSIZE-1)
			strcpy(Keyword[KeywordCC++], string);
		*/

		return string;
	}
}


//////////////////////////////////////////////////////////////////////////////////
// Split
//////////////////////////////////////////////////////////////////////////////////

void SplitInit()
{
	TokenInit();
	TokenReset();
}

int Split(char *string, int *listCC, char **list)
{
	int i = 0;
	int flag = TOKEN_SUCCESS;
	int result;
	char *item = Token(string, &result);
	while (item != TOKEN_EMPTY)
	{
		i++;
		*list++ = item;
		item = Token(NULL, &result);
		if (result == TOKEN_ERROR)
			flag = TOKEN_ERROR;
	}
	*listCC = i;
	return flag;
}


// char string[] = "{1, ( 2 ),( 3 )}";
// const char delim[] = " ,(){}\t";
void SplitTest(char *string)
{
	int listCC;
	char *list[LenShort];

	Split(string, &listCC, list);

	int i = 0;
	while (i < listCC)
	{
		printf("%s\n", *(list+i++));
	}
}

void StrSplit_Gen(char *string)
{
	int listCC;
	char *list[LenShort];

	int flag = Split(string, &listCC, list);

	srand((unsigned int)time(NULL));

	int i = 0;
	while (i < listCC)
	{
		char *str = *(list+i++);
		if (*str != '"' || flag == TOKEN_ERROR)
		{
			printf("%s\n", str);
		}
		else
		{
			char *gen_code(char *string, char *func);
			char func[LenShort];
			char *gen=gen_code(str,func);
			printf("%s\"------->\n", str);
			printf("%s\n", gen);
		}
	}
}

void StrSplit_Shell_Init()
{
	SplitInit();
	TableInit();
}

int StrSplit_Shell(char *string, char *msg, char *line, FILE *outfile, FILE *catfile, FILE *hatfile, FILE *tatfile)
{
	int listCC;
	char *list[LenShort];

	int flag = Split(string, &listCC, list);
	if (flag == TOKEN_ERROR)
	{
		sprintf(msg, "String Imcomplete in Line");
		return NO;
	}

	srand((unsigned int)time(NULL));

	// header string output
	list[listCC] = string + strlen(line);
	char *p1=line;
	char *p2=line+(list[0]-string);
	char *p;
	for (p=p1; p<p2; p++)
		fputc(*p, outfile);

	int i = 0;
	int funcStat = 0;
	while (i < listCC)
	{
		int not_gened = TRUE;

		p1=line+(list[i]-string);
		p2=line+(list[i+1]-string);
		char *str = *(list+i++);
		int slen=strlen(str);
		if (*str == '"' && flag != TOKEN_ERROR && cnt_include<3 && slen>1 && slen<LenLong)
		{
			char *gen_code(char *string, char *func);
			char funcName[LenShort];
			char *gen=gen_code(str,funcName);
			int len = strlen(gen);
			if (len>0)
			{
				fprintf(catfile, "//%s", line);
				fprintf(catfile, "%s\n", gen);
				fprintf(hatfile, "//%s", line);
				fprintf(hatfile, "char *%s();\n\n", funcName);
				fprintf(tatfile, "  printf(\"%s=\\n\");\n", funcName); 
				fprintf(tatfile, "  printf(\" [F] %%s\\n\",%s());\n", funcName); 
				fprintf(tatfile, "  printf(\" [S] %%s\\n\",%s\");\n", str);

				// string output
				fprintf(outfile, "%s()", funcName);
				for (p=p2-1; p>=p1; p--)
					if (*p=='"') break;
				for (p++; p<p2; p++)
					fputc(*p, outfile);
				not_gened = FALSE;
			}
		}

		// normal case
		if (not_gened)
		{
			// string output
			for (p=p1; p<p2; p++)
				fputc(*p, outfile);
		}
	}
	msg[0]='\0';
	return OK;
}


//////////////////////////////////////////////////////////////////////////////////
// Gen Code
//////////////////////////////////////////////////////////////////////////////////

static int FunctionCC = 0;
char code[LenHuge];
int shuffle[LenLong];

void swap_i(int *x, int *y)
{
	int t = *x;
	*x = *y;
	*y = t;
}

void swap_uc(unsigned char *x, unsigned char *y)
{
	unsigned char t = *x;
	*x = *y;
	*y = t;
}

void shuffling(int n)
{
	int i, j;
	for (i=0; i<n; i++)
		shuffle[i] = i;

	for (i=0; i<n; i++)
	{
		j = rand() % n;
		swap_i(shuffle + i, shuffle + j);
	}
}

char *gen_code(char *inStr, char *func)
{
	char string[LenShort];
	char *p1, *p2, *pe;
	strcpy(string, inStr);

	if (ProcessingEscapeCharacter==1)
	{
		p1=p2=string+1;
		pe=string+strlen(string);
		while (p2<=pe)
		{
			if (*p2=='\\')
			{
				p2++;
				switch(*p2)
				{
				case 'n':
					*p2='\n';
					break;
				case 'r':
					*p2='\r';
					break;
				case '"':
					*p2='"';
					break;
				case '\'':
					*p2='\'';
					break;
				case 't':
					*p2='\t';
					break;
				case '\\':
					*p2='\\';
					break;
				case 'f':
					*p2='\f';
					break;
				case 'a':
					*p2='\a';
					break;
				case 'b':
					*p2='\b';
					break;
				default:
					printf("There is an unknown escape character: \\%c\n", *p2);
					break;
				}
			}

			if (p1!=p2)	*p1=*p2;
			p1++;
			p2++;
		}
	}
	
	char *str = string+1;
	unsigned char val[LenLong];
	int idx1[LenLong];
	int idx2[LenLong];

	int n, i;
	int seed;
	char buf[LenLong];

	code[0]='\0';
	if (string == NULL || (str = string + 1) == '\0' || (n=strlen(str)) == 0) 
		return code;

	///////////////////////////////////////////////////////
	// rand init
	seed = rand() % 10000;
	srand(seed);

	int m = n/2+1;
	for (i=0; i<m; i++)
	{
		idx1[i] = rand()%n;
		idx2[i] = rand()%n;
	}

	// rotation
	for (i=0; i<n; i++)
	{
		unsigned char a = str[i];
		int r = rand()%7+1;
		val[i] = (a>>r) | (a<<(8-r));
	}

	// swap
	for (i=m-1; i>=0; i--)
	{
		swap_uc(val+idx1[i], val+idx2[i]);
	}

	// end~
	val[n] = rand()%256;

	///////////////////////////////////////////////////////
	// gen code
	sprintf(buf, "unsigned char s%08d[]={", FunctionCC); strcat(code, buf);
	for (i=0; i<=n; i++)
	{
		sprintf(buf, "0x%02X%s", val[i], ((i<n)?",":"")); strcat(code, buf);
	}
	strcat(code, "};\n");

	sprintf(func, "z%08d", FunctionCC);
	sprintf(buf, "char *%s()\n", func); strcat(code, buf);
	strcat(code, "{\n");
	sprintf(buf, "  unsigned char *p=s%08d;\n", FunctionCC); strcat(code, buf);
	strcat(code, "  int i,r;\n");
	sprintf(buf, "  if (p[%d]!=0)\n", n); strcat(code, buf);
	strcat(code, "  {\n");
	sprintf(buf, "    srand(%d);\n", seed); strcat(code, buf);
	sprintf(buf, "    for (i=0;i<%d;i++)\n", m); strcat(code, buf);
	strcat(code, "    {\n");
	sprintf(buf, "      swap_uch(p+(rand()%%%d), p+(rand()%%%d));\n", n, n); strcat(code, buf);
	strcat(code, "    }\n");
	sprintf(buf, "    for (i=0;i<%d;i++,p++)\n", n); strcat(code, buf);
	strcat(code, "    {\n");
	strcat(code, "      r=rand()%7+1;\n");
	strcat(code, "      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));\n");
	strcat(code, "    }\n");
	strcat(code, "    *p=0;\n");
	sprintf(buf, "    p-=%d;\n", n); strcat(code, buf);
	strcat(code, "  }\n");
	strcat(code, "  return (char *)p;\n");
	strcat(code, "}\n");

	FunctionCC++;
	return code;
}



//////////////////////////////////////////////////////////////////////////////////
// File
//////////////////////////////////////////////////////////////////////////////////

int FileExist(char *filename)
{
	FILE *fp = fopen(filename,"r");
	if (fp)
	{
		fclose(fp);
		return OK;
	}
	else 
	{
		return NO;
	}
}

void ToLower(char *string)
{
	if (string == NULL) return;
	int i;
	int n=strlen(string);
	for (i=0; i<n; i++)
		string[i] = tolower(string[i]);
}

void IronShell_Init(FILE *catfile, FILE *hatfile, FILE *tatfile)
{
	fprintf(catfile, "#include <stdlib.h>\n");
	fprintf(catfile, "#include \"%s\"\n", HFILE);
	fprintf(catfile, "\n");
	fprintf(catfile, "void swap_uch(unsigned char *x, unsigned char *y)\n");
	fprintf(catfile, "{\n");
	fprintf(catfile, "	unsigned char t = *x;\n");
	fprintf(catfile, "	*x = *y;\n");
	fprintf(catfile, "	*y = t;\n");
	fprintf(catfile, "}\n");
	fprintf(catfile, "\n");

	fprintf(hatfile, "void AddShellTest();\n\n");

	fprintf(tatfile, "#include <stdio.h>\n");
	fprintf(tatfile, "#include \"%s\"\n", HFILE);
	fprintf(tatfile, "\n");
	fprintf(tatfile, "void AddShellTest()\n");
	fprintf(tatfile, "{\n");
}

void IronShell_Term(FILE *catfile, FILE *hatfile, FILE *tatfile)
{
	fprintf(tatfile, "}\n");
}


void IronShell_Making(char *filename, FILE *catfile, FILE *hatfile, FILE *tatfile)
{
	FILE *infile;
	FILE *outfile;

	char outname[LenShort];
	sprintf(outname, "%s.out", filename);
	infile = fopen(filename, "r");
	outfile = fopen(outname, "w");

	if (infile == NULL || outfile == NULL) 
	{
		printf("file open error!\n");
		return;
	}

	StrSplit_Shell_Init();
	fprintf(outfile, "#include \"%s\"\n", HFILE);

	char line[LenLong];
	char str[LenLong];
	char msg[LenShort];
	while (!feof(infile))
	{
		if (fgets(line, LenLong, infile) != NULL)
		{
			strcpy(str, line);
			if (!StrSplit_Shell(str, msg, line, outfile, catfile, hatfile, tatfile))
			{
				printf("Error: %s\n", msg);
			}
		}
	}
	fclose(infile);
	fclose(outfile);
}

