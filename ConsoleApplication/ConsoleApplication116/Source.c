#include <stdio.h> 
#include <stdlib.h>

                                                                                
int main(int argc, char* argv[]) { 
	/*
    if(argc != 3) { 
        puts("指令: copy <input> <output>"); 
        return 1; 
    } */
    char ch; 
	
	char ch1[] = "C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\a.txt";
	char ch2[] = "C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\b.txt";
	
    FILE *file1 = fopen(ch1, "rb"); 
    FILE *file2 = fopen(ch2, "wb"); 

    if(!file1) { 
        puts("檔案讀入失敗"); 
        return 1; 
    } 

    if(!file2) { 
        puts("檔案輸出失敗"); 
        return 1; 
    } 
    

    while(!feof(file1)) { 
        fread(&ch, sizeof(char), 1, file1);
        
        if(!feof(file1)) { 
            fwrite(&ch, sizeof(char), 1, file2);
        }
    } 

    fclose(file1); 
    fclose(file2); 
    system("pause");

    return 0; 
}