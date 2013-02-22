#include <stdio.h> 
                                                                                
int main(int argc, char* argv[]) {
    char ch; 
    char name[10]; 
    int score; 

    FILE *file = fopen("C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\test.txt", "w"); 
    if(!file) { 
	// 寫到標準錯誤
        fprintf(stderr, "無法寫入檔案\n"); 
        return 1; 
    } 

    fprintf(file, "%s\t%d\r\n", "Justin", 90);
    fprintf(file, "%s\t%d\r\n", "momor", 80);
    fprintf(file, "%s\t%d\r\n", "bush", 75);    

    fclose(file);

    file = fopen("C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\test.txt", "r");; 
    if(!file) { 
	// 寫到標準錯誤
        fprintf(stderr, "無法讀入檔案\n");  
        return 1; 
    } 
    
    
    puts("Name\tScore"); 
    while(fscanf(file, "%s\t%d", name, &score) != EOF) { 
        // 寫到標準輸出
        fprintf(stdout, "%s\t%d\n", name, score); 
    } 

    fclose(file);

    return 0; 
}