char *test_serect();
char* LockVarR(char *A,int size);
void LockVarW(char *A,int size);
void loadtable();
void SDCARD_LOCK_IO_TST(int startbit,int size,char* buff,char* buff2);
void SDCARD_READ_tst(int startbit,int size,char* buff);




//實際使用
void SDCARD_READ(int startbit,int size,char* buff);  //SDCARD 家秘毒入
void SDCARD_WRITE(int startbit,int size,char* buff); //SDCARD 加密輸出
void loadtable();