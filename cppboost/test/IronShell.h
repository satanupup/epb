
#pragma once

#define LenShort  256
#define LenLong   1024
#define LenHuge   20000
#define null      NULL

#define TRUE 1
#define FALSE 0
#define OK 1
#define NO 0

#define HFILE "AddShell.h"
#define CFILE "AddShell.cpp"
#define TFILE "AddShellTest.cpp"

extern int ProcessingEscapeCharacter;

char *Token(char *string, int *result);

int Split(char *string, int *listCC, char **list);
void StrSplit(char *string);
void StrSplit_Gen(char *string);
int StrSplit_Shell(char *string, char *msg, char *line, FILE *outfile, FILE *catfile, FILE *hatfile, FILE *tatfile);

void swap(int *x, int* y);
void shuffling(int n);
char *gen_code(char *string, char *func);

int FileExist(char *filename);
void ToLower(char *string);
void IronShell_Init(FILE *catfile, FILE *hatfile, FILE *tatfile);
void IronShell_Term(FILE *catfile, FILE *hatfile, FILE *tatfile);
void IronShell_Making(char *filename, FILE *catfile, FILE *hatfile, FILE *tatfile);

