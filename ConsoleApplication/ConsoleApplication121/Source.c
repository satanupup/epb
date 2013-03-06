#include <stdio.h> 
#include <stdlib.h>
#include "Student.h" 

int main(int argc, char* argv[]) {
    struct Student student; 
    int count = 0, number; 
	errno_t err;	// 回傳錯誤的數值
	char ch1[] = "C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\data.txt";
   
    FILE *file;// = fopen(ch1, "r"); 


	if (( err = fopen_s(&file,ch1, "r")) != 0)
	{
	 printf("cant open the file");
	 exit(1);
	}

    while(1) { 
        fread((char*) &student, sizeof(student), 1, file); 
        if(!feof(file)) {
            count++; 
        }
        else {
            break;
        }
    } 
    rewind(file);

    printf("輸入學號(1-%d)\n", count);
    puts("輸入0離開"); 

    while(1) { 
        printf("\n學號? "); 
        scanf_s("%d", &number);
        if(number == 0) {
            break; 
        }
        else if(number > count) { 
            printf("輸入學號(1-%d)\n", count);
            continue; 
        } 

        puts("\n學號\t姓名\t\t分數"); 

        fseek(file, (number - 1) * sizeof(student), SEEK_SET); 
        fread((char*) &student, sizeof(student), 1, file); 
        printf("%d\t%s\t%f\n", 
            student.studyNumber, student.name, student.score); 
    } 

    fclose(file);
    system("pause");
    return 0; 
}