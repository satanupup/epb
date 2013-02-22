

#include <stdio.h> 
#include <stdlib.h>
                                                                                
int main(int argc, char* argv[]) 
{
    
	char ch1[] = "C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\temp.txt";
	FILE *file = fopen(ch1, "wb");
		
    int i;

    int arr[5] = {1, 2, 3, 4, 5}; 
	
    if(!file) { 
        puts("無法讀取檔案"); 
        return 1; 
    } 

    fwrite((char*) arr, sizeof(arr), 1, file); 
    fclose(file);

    file = fopen(ch1, "rb"); 
    if(!file) { 
        puts("無法讀取檔案"); 
        return 1; 
    } 
    
    fread((char*) arr, sizeof(arr), 1, file); 
    printf("arr: "); 
    for(i = 0; i < 5; i++) {
        printf("%d ", arr[i]); 
    }
    putchar('\n');

    fclose(file); 
    
    system("pause");
    return 0; 
}