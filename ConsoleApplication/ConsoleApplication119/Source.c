#include <stdio.h> 
#include <stdlib.h>
#include "Student.h" 

int main(int argc, char* argv[]) 
{
	errno_t err;	// 回傳錯誤的數值
	char ch1[] = "C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\data.txt";
    FILE *file ;//= fopen(ch1, "wb"); 
	
    int count; 
    struct Student student = {0, "", 0.0}; 
    int i;

	
	if (( err = fopen_s(&file,ch1, "wb")) != 0)
	{
	 printf("cant open the file");
	 exit(1);
	}

    printf("要建立幾筆資料？ "); 
    scanf_s("%d", &count); 

    for(i = 0; i < count; i++) { 
        fwrite((char*) &student, sizeof(student), 1, file); 
    } 

    fclose(file);
        
	system("pause");
    return 0; 
}