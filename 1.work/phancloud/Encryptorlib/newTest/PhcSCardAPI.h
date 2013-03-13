
//PhcSCardAPI.h

#define MaxPoolSize 4000  // 4000
#define MaxTotalLine 40   // 4000/100
#define StringLen 100     // String
#define IntArrLen 10      // IntArray

int SCard_Load(int StartLine, int Lines);
int SCard_Save(int StartLine, int Lines);

int SCard_GetString(int Line, char *Str);
int SCard_SetString(int Line, char *Str);

int SCard_GetIntArr(int Line, int *IntArr);
int SCard_SetIntArr(int Line, int *IntArr);
char* Show_pool(int Line);
int* Show_pool_int(int LINE);