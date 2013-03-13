#ifndef SCardAPI_H
#define SCardAPI_H

#include "SCardManager.h"

#pragma pack(push,pk1,1)

#ifdef __cplusplus
extern "C" {
#endif


#ifndef SC_STATUS
#define SC_STATUS                   unsigned  long
#define SC_API                      __stdcall
//typedef void *                      SC_HANDLE;
#endif


//
// Status return values
//

#define SC_SUCCESS                  0x00
#define SC_CANNOT_OPEN_DRIVER       0x01
#define SC_INVALID_DRVR_VERSION     0x02
#define SC_INVALID_COMMAND          0x03
#define SC_ACCESS_DENIED            0x04
#define SC_ALREADY_ZERO             0x05
#define SC_UNIT_NOT_FOUND           0x06
#define SC_DEVICE_REMOVED           0x07
#define SC_COMMUNICATIONS_ERROR     0x08
#define SC_DIR_NOT_FOUND            0x09
#define SC_FILE_NOT_FOUND           0x0A
#define SC_MEM_CORRUPT              0x0B
#define SC_INTERNAL_HW_ERROR        0x0C
#define SC_INVALID_RESP_SIZE        0x0D
#define SC_PIN_EXPIRED              0x0E
#define SC_ALREADY_EXISTS           0x0F
#define SC_NOT_ENOUGH_MEMORY        0x10
#define SC_INVALID_PARAMETER        0x11
#define SC_ALIGNMENT_ERROR          0x12
#define SC_INPUT_TOO_LONG           0x13
#define SC_INVALID_FILE_SELECTED    0x14
#define SC_DEVICE_IN_USE            0x15
#define SC_INVALID_API_VERSION      0x16
#define SC_TIME_OUT_ERROR           0x17
#define SC_ITEM_NOT_FOUND           0x18
#define SC_COMMAND_ABORTED          0x19
#define SC_INVALID_STATUS           0xff


// Maximum size of names and labels

#define SC_BLOCK_SIZE           240




/////////////////////////////////////////////////////////////////////////////
//
// Device access services
//
/////////////////////////////////////////////////////////////////////////////

SC_STATUS SC_API SC_Open( void );

SC_STATUS SC_API SC_Close( void );

SC_STATUS SC_API SC_Transmit(
    CARDAPDU *Apdu                             // [in][out]
);


/////////////////////////////////////////////////////////////////////////////
//
// File access services
//
/////////////////////////////////////////////////////////////////////////////

SC_STATUS SC_API SC_Read(
    unsigned long  Offset,                     // [in]
    unsigned char *Buffer,                     // [out]
    unsigned long  Size                        // [in]
);
// Flags is reserved for future use and must be 0.

SC_STATUS SC_API SC_Write(
    unsigned long  Offset,                     // [in]
    unsigned char *Buffer,                     // [in]
    unsigned long  Size                        // [in]
);


#ifdef __cplusplus
}
#endif

#pragma pack(pop,pk1)

#endif // SCardAPI_H
