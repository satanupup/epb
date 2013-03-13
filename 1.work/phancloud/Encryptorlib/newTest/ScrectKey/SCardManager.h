//---------------------------------------------------------------------------

#ifndef SCardManagerH
#define SCardManagerH
//---------------------------------------------------------------------------
#include <windows.h>
#include <WinSCard.h>
#pragma comment (lib,"Winscard.lib")
#ifndef HIGHBYTE
    #define HIGHBYTE(x)  x >> 8
#endif

#ifndef LOWBYTE
    #define LOWBYTE(x)   x & 0xFF
#endif

#define STAT_OK                                 0       // OK
#define STAT_SESSION_NOT_OPEN                   2       // SESSION IS NOT OPEN,
#define STAT_DATA_CORRUPTED                     10
#define STAT_DATA_INCORRECT_LENGTH              11      // LENGTH OF GIVEN DATA IS INCORRECT
#define STAT_SCARD_ERROR                        34      // SCARD FUNCTIONS ERROR
#define STAT_UNKNOWN_SCARD_PROTOCOL             36
#define STAT_VALUE_NOT_READ                     104

// ISO7816 ERRORS
#define SW_FILE_FULL				0x6A84
#define SW_UNKNOWN  				0x6F00
#define SW_CLA_NOT_SUPPORTED 			0x6E00
#define SW_INS_NOT_SUPPORTED 			0x6D00
#define SW_CORRECT_LENGTH_00 			0x6C00
#define SW_WRONG_P1P2   			0x6B00
#define SW_LC_INCONSISTENT_WITH_P1P2		0x6A87
#define SW_INCORRECT_P1P2			0x6A86
#define SW_RECORD_NOT_FOUND 			0x6A83
#define SW_FILE_NOT_FOUND 			0x6A82
#define SW_FUNC_NOT_SUPPORTED			0x6A81
#define SW_WRONG_DATA   			0x6A80
#define SW_APPLET_SELECT_FAILED 		0x6999
#define SW_COMMAND_NOT_ALLOWED 			0x6986
#define SW_CONDITIONS_NOT_SATISFIED		0x6985
#define SW_DATA_INVALID 			0x6984
#define SW_FILE_INVALID 			0x6983
#define SW_SECURITY_STATUS_NOT_SATISFIED	0x6982
#define SW_WRONG_LENGTH         		0x6700
#define SW_BYTES_REMAINING_00       		0x6100
#define SW_NO_ERROR             		0x9000

// JCSTATUS (used in OpenPlatform cards)
#define SW_JCDOMAIN_ALGORITHM_NOT_SUPPORTED     0x9484
#define SW_JCDOMAIN_APPLET_INVALIDATED          0x6283
#define SW_JCDOMAIN_AUTHENTICATION_FAILED       0x6300
#define SW_JCDOMAIN_AUTHORIZATION_FAILED        0x9482
#define SW_JCDOMAIN_CHECKSUM_FAILED             0x9584
#define SW_JCDOMAIN_DECRYPTION_FAILED           0x9583
#define SW_JCDOMAIN_INSTALLATION_FAILED         0x9585
#define SW_JCDOMAIN_INVALID_STATE               0x9481
#define SW_JCDOMAIN_NO_SPECIFIC_DIAGNOSIS       0x6400
#define SW_JCDOMAIN_REFERENCE_DATA_NOT_FOUND    0x6A88
#define SW_JCDOMAIN_REGISTRATION_FAILED         0x9586
#define SW_JCDOMAIN_SIGNATURE_CHECK_FAILED      0x9582
#define SW_JCDOMAIN_SM_INCORRECT                0x6988
#define SW_JCDOMAIN_SM_MISSING                  0x6987

#define	MAX_APDU_LEN		512
#define	MAX_RESPONSE		512
#define MAX_READERS		32

#define MAX_DATA_LENGTH         255


// 存放Slot資訊的結構
typedef	struct {
    char szReaderName[MAX_PATH];

} SCReader;

// 存放APDU資訊的結構
typedef struct {
    unsigned char  CLA;
    unsigned char  INS;
    unsigned char  P1;
    unsigned char  P2;
    unsigned char  Lc;
    unsigned char  Le;
    unsigned char *DataIn;
    unsigned char *DataOut;
    union {
        unsigned short Status;
        struct {
            unsigned char SW2;
            unsigned char SW1;
        };
    };

} CARDAPDU;         


class CSCardManager
{
    public:
        CSCardManager();    // 構造函數
	~CSCardManager();   // 解構函數

	BOOL SCardGetPcscList(void);
        BOOL SCardOpen(int nIndex);
        BOOL SCardClose(void);
        BOOL SCardReset(char *strResp);
	BOOL SCardTransmit(char *strApdu, char *strResp, WORD *SW);
	BOOL SCardExchangeAPDU(CARDAPDU *pADPU);
        BOOL SCardOpen(BYTE *pAID, BYTE AID_Len);
        
        SCReader	    ReaderList[MAX_READERS];  // Slot清單
        int		    ReaderCount;              // 可用Slot個數
	char		    ErrorMsg[1024];           // 錯誤訊息
	int 		    ErrorCode;                // 錯誤碼

    private:
	int		    m_Index;            // 目前Slot ID
	SCARDCONTEXT	    m_ContextHandle;    // Context
        SCARDHANDLE	    m_CardHandle;       // Handle of SCReader
        DWORD		    m_ActiveProtocol;
        SCARD_IO_REQUEST    m_IO_Request;

};
//---------------------------------------------------------------------------
#endif
