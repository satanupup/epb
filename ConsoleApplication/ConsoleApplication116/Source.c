#include <stdio.h> 
#include <stdlib.h>

                                                                                
int main(int argc, char* argv[]) { 	
    char ch; 		
	errno_t err;	
	
	char ch1[] = "C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\a.txt";
	char ch2[] = "C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\b.txt";
	
    FILE *file1 ;//= fopen(ch1, "rb"); 
    FILE *file2 ;//= fopen(ch2, "wb"); 

if (( err = fopen_s(&file1,ch1, "rb")) != 0)
	{
	 printf("cant open the file");
	 exit(1);
	}
if (( err = fopen_s(&file2,ch1, "wb")) != 0)
	{
	 printf("cant open the file");
	 exit(1);
	}
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