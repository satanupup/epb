//---------------------------------------------------------------------------

//#include <vcl.h>
#include <stdio.h>
#include <conio.h>
//#include "..\\cfg_str.h"
#include<Windows.h>
#pragma hdrstop

#include "SCardAPI.h"
//---------------------------------------------------------------------------

#pragma argsused

#define MAX_LEN 4*1024

char *GetErrorMsg(unsigned char code)
{
    switch (code)
    {
     	case SC_SUCCESS:                 return "Success!";
	case SC_CANNOT_OPEN_DRIVER:      return "failed to open the driver!";
	case SC_INVALID_DRVR_VERSION:    return "Invalid driver version!";
	case SC_INVALID_COMMAND:	 return "Invalid command!";
	case SC_ACCESS_DENIED:  	 return "access denied!";
        case SC_ALREADY_ZERO:            return "already zero!";
	case SC_UNIT_NOT_FOUND:          return "unit was not found!";
        case SC_DEVICE_REMOVED:          return "the device was removed!";
        case SC_COMMUNICATIONS_ERROR:    return "communication terminated abnormally!";
	case SC_DIR_NOT_FOUND:           return "The directory was not found!";
        case SC_FILE_NOT_FOUND:          return "The file was not found!";
	case SC_MEM_CORRUPT:             return "Memory inside the token was corrupted!";
	case SC_INTERNAL_HW_ERROR:       return "Internal hardware error occured!";
        case SC_INVALID_RESP_SIZE:       return "Abnormal response received from the token!";
	case SC_PIN_EXPIRED:             return "The PIN retry counter register return zero!";
	case SC_ALREADY_EXISTS:          return "The item already exist!";
	case SC_NOT_ENOUGH_MEMORY:       return "Insufficient memory to perform the command!";
        case SC_INVALID_PARAMETER:       return "Invalid parameter was assigned to the function!";
	case SC_INPUT_TOO_LONG:          return "The length of the input data is too long!";
	case SC_INVALID_FILE_SELECTED:   return "The selected file is invalid!";
	case SC_DEVICE_IN_USE:           return "The device is currently used by another application!";
	case SC_INVALID_API_VERSION:     return "The version of the API library is invalid!";
	case SC_TIME_OUT_ERROR:          return "The operation time out!";
	case SC_ITEM_NOT_FOUND:          return "The item was not found!";
	case SC_COMMAND_ABORTED:         return "Command aborted abnormally!";
        case SC_INVALID_STATUS:          return "Invalid return value received from the token!";
 	default:	      		 return "Unknown error occured!";
    }
}

void DumpHex( LPBYTE lpData, long lLen )
{
    for( long l=0; l<lLen; l++ )
    {
      //  printf( "%02X ", *(lpData+l) );
        if( (l%16)==15 )
        {
           // printf( "\n" );
        }
    }
  //  printf( "\n" );
}

char* Phc_Key_test()
{
    BYTE byData[MAX_LEN];
 //   BYTE byData2[MAX_LEN];
//    DWORD len,len2;
    BYTE ret;
//    int i;


    printf("Step 1 - SC_Open\n");
    ret = SC_Open();
    printf("SC_Open Return %s (%02X)\n", GetErrorMsg(ret), ret);

    printf("Step 2 - 寫入Data\n");
    //for( i=0; i<MAX_LEN; i++ )	byData[i]=i;
	 //unsigned char aout[240]="12345";
   // ret = SC_Write(0, byData, MAX_LEN);
	//ret = SC_Write(0, byData, MAX_LEN);
	 //ret = SC_Write(0, aout, MAX_LEN);
   // printf("寫入Data Return %s (%02X)\n", GetErrorMsg(ret), ret);

    //printf("Step 3 - 讀取Data\n");
    //memset(byData, 0x00, MAX_LEN);
    ret = SC_Read(0, byData, MAX_LEN);
  //  printf("讀取Data Return %s (%02X)\n", GetErrorMsg(ret), ret);
   // if (ret == SC_SUCCESS) DumpHex(byData, MAX_LEN);

 //   printf("Step 4 - SC_Close\n");
    ret = SC_Close();
   // printf("SC_Close Return %s (%02X)\n", GetErrorMsg(ret), ret);
	
	return (char*)byData;
   // printf("Press any key to continue...\n");

  //  getch();
   // return 0;
	
}
//---------------------------------------------------------------------------

