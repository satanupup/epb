#include <stdio.h> 
#include <stdlib.h>
#include "Student.h" 

int main(int argc, char* argv[]) {
    struct Student student; 
    int count = 0; 
	char ch1[] = "C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\data.txt";
    FILE *file = fopen(ch1, "r+b"); 
	/*
    if(argc < 2) { 
        puts("指令: write <filename>"); 
        return 1; 
    } */

    if(!file) { 
        puts("無法讀取檔案"); 
        return 1; 
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
        scanf("%d", &(student.studyNumber)); 
        if(student.studyNumber == 0) {
            break; 
        }
        
        printf("輸入姓名 分數\n? ");
        scanf("%s %lf", student.name, &(student.score)); 

        fseek(file, (student.studyNumber - 1) * sizeof(student), SEEK_SET); 
        fwrite((char*) &student, sizeof(student), 1, file); 
    } 

    fclose(file); 
    
	system("pause");
    return 0; 
}