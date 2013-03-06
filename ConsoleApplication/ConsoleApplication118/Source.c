#include <stdio.h> 
#include <stdlib.h>
                                                                                
int main(int argc, char* argv[]) {
	
	errno_t err;	// 回傳錯誤的數值
	
	char ch1[] = "C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\data.txt";
	

    FILE *file;// = fopen("C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\data.txt", "r");
    char name[30]; 
    int request, account, score; 
     
	if (( err = fopen_s(&file,ch1, "r")) != 0)
	{
	 printf("cant open the file");
	 exit(1);
	}


    puts("輸入選項:");
    puts("1) 顯示所有學生與分數");
    puts("2) 顯示及格學生與分數");
    puts("3) 顯示不及格學生與分數");
    puts("4) 離開");

    while(1) { 
        printf("\n選項? "); 
        scanf_s("%d", &request); 
        if(request == 4) {
            break; 
        }

        switch(request) { 
            case 1: 
                puts("\n所有學生與分數:");
                break; 
            case 2: 
                puts("\n及格學生與分數:");
                break; 
            case 3: 
                puts("\n不及格學生與分數:");
                break; 
        } 

        fscanf_s(file, "%d\t%s\t%d", &account, name, &score); 
        while(!feof(file)) { 
            if((request == 1) || (request == 2 && score >= 60) || 
               (request == 3 && score < 60)) {
                printf("%d\t%s\t%d\n", account, name, score);     
            }

            fscanf_s(file, "%d\t%s\t%d", &account, name, &score); 
        } 

        rewind(file);  // 重置游標，也可使用 fseek(file, 0, SEEK_SET);
    } 

    fclose(file); 
    
	system("pause");
    return 0; 
}