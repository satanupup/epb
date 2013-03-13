//---------------------------------------------------------------------------
#ifndef UtilityH
#define UtilityH

//#include <vcl.h>
#include <stdio.h>
#include<Windows.h>
//---------------------------------------------------------------------------
// Miscellaneous helper functions
//---------------------------------------------------------------------------
#define SAFE_DELETE(p)       { if(p) { delete (p);     (p)=NULL; } }
#define SAFE_DELETE_ARRAY(p) { if(p) { delete[] (p);   (p)=NULL; } }
#define SAFE_RELEASE(p)      { if(p) { (p)->Release(); (p)=NULL; } }
#define SAFE_FREE(p)         { if(p) { free(p); (p) = NULL; } }

#define max(x,y)       ( (x > y) ? x : y )
#define min(x,y)       ( (x < y) ? x : y )
#define DiffTickCount(old_tick_count, time_out) (( GetTickCount() - old_tick_count )>= time_out)

//---------------------------------------------------------------------------
int  dprintf(char *format, ...);
void ByteToStr(BYTE *pbBinary, DWORD cbBinary, char *pszString);
int  StrToByte(char *pszString, DWORD cchString, BYTE *pbBinary);
void ReverseBytes(BYTE *pbInBytes, BYTE *pbOutBytes, int dwBytesLength);

//---------------------------------------------------------------------------
#endif  // #ifndef UtilityH