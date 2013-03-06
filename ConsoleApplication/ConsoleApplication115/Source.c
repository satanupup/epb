#include <stdio.h> 
#include <stdlib.h>
                                                                                
int main(int argc, char* argv[]) {
	
    unsigned char ch; 
    int count = 0; 
	char ch1[] = "C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\test.txt";
    FILE *file;// = fopen(ch1, "rb");

	
	errno_t err;       
	
    if(err = fopen_s(&file,ch1, "rb")) { 
        puts("來源檔案開啟失敗"); 
        return 1; 
    }



    while(!feof(file)) { 
        fread(&ch, sizeof(char), 1, file);
        
        printf("%2X ", ch);
        count++; 
        if(count > 16) {  // 換行 
            putchar('\n');
            count = 0; 
        } 
    } 
    putchar('\n');

    fclose(file);
        
	system("pause");
    return 0; 
}