#include "Utility.h"

//---------------------------------------------------------------------------
// function used to output debug messagebox
//---------------------------------------------------------------------------
int dprintf(char *format, ...)
{
    char buffer[2048];
    int len;
    va_list args;

    va_start(args,format);

    len = vsnprintf(buffer, sizeof(buffer), format, args);
    buffer[sizeof(buffer)-1] = '\0';
    OutputDebugString(buffer);

    va_end(args);

    return len;
}

//----------------------------------------------------------------------------
void ByteToStr(BYTE *pbBinary, DWORD cbBinary, char *pszString)
{
    BYTE *pb = pbBinary; 
    int i;
    int b;

    for (i=0; i <(int)cbBinary; i++)
    {
        b = (*pb & 0xF0) >> 4;
        *pszString++ = (b <= 9) ? b + '0' : (b - 10) + 'A';
        b = *pb & 0x0F;
        *pszString++ = (b <= 9) ? b + '0' : (b - 10) + 'A';
        pb++;
    }

    *pszString = 0;
}

//----------------------------------------------------------------------------
int StrToByte(char *pszString, DWORD cchString, BYTE *pbBinary)
{
    int cbBinary;
    BYTE byTemp;
    char cTemp;
    int  i;

    if (cchString % 2)
    {
        return 0;
    }

    cbBinary = cchString / 2;
    for (i=0; i < cbBinary; i++)
    {
        cTemp = toupper(pszString[i*2]);
        pbBinary[i] = (cTemp > '9' ? cTemp - 'A' + 10 : cTemp - '0');
        if (pbBinary[i] > 15)
	    break;

        pbBinary[i] <<= 4;

        cTemp = toupper(pszString[i*2 + 1]);
        byTemp = (BYTE)(cTemp > '9' ? cTemp - 'A' + 10 : cTemp - '0');
        if (byTemp > 15)
	    break;

        pbBinary[i] |= byTemp;
    }

    return i;
}
//----------------------------------------------------------------------------
void ReverseBytes(BYTE *pbInBytes, BYTE *pbOutBytes, int dwBytesLength)
{
    if  (pbInBytes == NULL || pbOutBytes == NULL || dwBytesLength == 0)
        return;

    for (int i=0; i<dwBytesLength; i++)
    {
        pbOutBytes[i] = pbInBytes[dwBytesLength - 1 - i];
    }   
}
// end-of-file
//////////////////////////////////////////////////////////////////////////
