#include <stdio.h>
#include <string.h>

typedef struct {
int product_num;
char product_name[80];
char product_type[80];
double product_price;
} product_t;



int
main()
{
FILE *inventoryp;
FILE *binaryp;
int input_status;
    product_t x;

inventoryp = fopen("catalog.txt", "r");
binaryp = fopen("product_list.bin", "wb");
//
// 上面這一行,你之前把它放在while 裡面, 這樣每個loop都會清掉上一次的資料
// 
while (input_status != EOF) {

memset(&x,0,sizeof(product_t));
//
// 不做這個動作的話, 你的data裡會有很多亂碼
//

input_status = fscanf(inventoryp, "%d", &x.product_num);
input_status = fscanf(inventoryp, "%s", x.product_name);
input_status = fscanf(inventoryp, "%s", x.product_type);
input_status = fscanf(inventoryp, "%lf", &x.product_price);

fwrite(&x, sizeof(product_t), 1, binaryp);
//
// 這個之前講過了, 這樣會讓費很多的檔案空間, 當然某些時候 這樣做是必要的
// 如果不想這樣, 建議你對 product_t 的每個member做write的動作
//

}

fclose(inventoryp);
fclose(binaryp);
    
return 0;
}