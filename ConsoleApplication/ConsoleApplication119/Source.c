#include <stdio.h> 
#include <stdlib.h>
#include "Student.h" 

int main(int argc, char* argv[]) 
{
	char ch1[] = "C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\data.txt";
    FILE *file = fopen(ch1, "wb"); 
	
    int count; 
    struct Student student = {0, "", 0.0}; 
    int i;
	/*
    if(argc != 2) { 
        puts("指令: create <filename>"); 
        return 1; 
    } */

    if(!file) { 
        puts("檔案輸出失敗"); 
        return 1; 
    } 

    printf("要建立幾筆資料？ "); 
    scanf("%d", &count); 

    for(i = 0; i < count; i++) { 
        fwrite((char*) &student, sizeof(student), 1, file); 
    } 

    fclose(file);
        
	system("pause");
    return 0; 
}