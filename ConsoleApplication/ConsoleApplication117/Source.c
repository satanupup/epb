

#include <stdio.h> 
#include <stdlib.h>
                                                                                
int main(int argc, char* argv[]) 
{
    
	char ch1[] = "C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\temp.txt";
	FILE *file;// = fopen(ch1, "wb");
		
	errno_t err;	// 回傳錯誤的數值
    int i;
    int arr[5] = {1, 2, 3, 4, 5}; 
	
	
	if (( err = fopen_s(&file,ch1, "wb")) != 0)
	{
	 printf("cant open the file");
	 exit(1);
	}


    fwrite((char*) arr, sizeof(arr), 1, file); 
    fclose(file);

	if (( err = fopen_s(&file,ch1, "rb")) != 0)
	{
	 printf("cant open the file");
	 exit(1);
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