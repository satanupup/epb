//=========
// main.c
//=========

void main()
{
	FILE *infile;
	infile = fopen("callbacks-list.c", "r");
	if (infile == NULL) 
	{
		printf("file open error!\n");
		return;
	}

	const char delim[] = " ,;(){}\t\n\r'";
	char line[LenLong];
	char str[LenLong];
	while (!feof(infile))
	{
		if (fgets(line, LenLong, infile)!= NULL)
		{
			printf("%s", line);
			printf("--------------------------------------------------\n");
			strcpy(str, line);
			StrSplit_Gen(str);
			printf("==================================================\n");
		}
	}
	fclose(infile);

	char teststr[LenShort];
	sprintf(teststr,"%%s=\"%%s\"\n");
	printf(teststr, "xyz", "123");
	
	char *ppp=(char *)zz00000000();
	printf(ppp, "xxxxxxxxxxx"); printf("\n");
	printf((char *)zz00000000(), "yyyyyyyyyyy"); printf("\n");
	printf((char *)zz00000000(), "123456"); printf("\n");
	printf("##################################################\n");
}