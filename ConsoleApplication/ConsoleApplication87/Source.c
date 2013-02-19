#include <stdio.h> 
#include <stdlib.h>
                                                                                
int main(int argc, char* argv[]) {
	
	errno_t err;
    char ch;  
    FILE *file1;
    FILE *file2;
	char ch1[] = "C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\a.txt";
	char ch2[] = "C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\b.txt";
	                        
	
    if(err = fopen_s(&file1,ch1, "r")) { 
        puts("來源檔案開啟失敗"); 
        return 1; 
    }
    
    if(err = fopen_s(&file2,ch2, "w")) { 
        puts("目的檔案開啟失敗"); 
        return 1; 
    }    
                                    
    while((ch = fgetc(file1)) != EOF) { 
        fputc(ch, file2);
    } 
          
    fclose(file1);
    fclose(file2);
        
	system("pause");
    return 0; 
}