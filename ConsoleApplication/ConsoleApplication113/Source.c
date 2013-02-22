#include <stdio.h> 
#include <stdlib.h>
                                                                                
int main(int argc, char* argv[]) {
	
	errno_t err;
    char ch;  
    FILE *file;    
	char name[10];
	int score;
	char ch1[] = "C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\test.txt";
	                        
	
    if(err = fopen_s(&file,ch1, "w")) { 
        puts("來源檔案開啟失敗"); 
        return 1; 
    }
    
	fprintf(file,"%s\t%d\r\n", "Justin", 90);
    fprintf(file, "%s\t%d\r\n", "momor", 80);
    fprintf(file, "%s\t%d\r\n", "bush", 75);    
	
    fclose(file);

	 if(err = fopen_s(&file,ch1, "r")) { 
        puts("來源檔案開啟失敗"); 
        return 1; 
    }



	 puts("Name\tScore");
	 while(fscanf(file, "%s\t%d", name, &score) != EOF) 
	 {
		 printf("%s\t%d\n", name, score);
	 }
	 fclose(file);
        
	system("pause");
    return 0; 
}