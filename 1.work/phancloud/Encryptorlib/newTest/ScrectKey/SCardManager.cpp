
#include "Utility.h"
#include "SCardManager.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSCardManager::CSCardManager()
{
    wsprintf(ErrorMsg, "%s", "No error.");
    ReaderCount = 0;
    m_Index = 0;
    m_ContextHandle = NULL;
    m_CardHandle = NULL;
}

CSCardManager::~CSCardManager()
{
    if (m_CardHandle)
    {
    	SCardDisconnect(m_CardHandle, SCARD_EJECT_CARD);
    	m_CardHandle = NULL;
    }

    if (m_ContextHandle)
    {
    	SCardReleaseContext(m_ContextHandle);
        m_ContextHandle = NULL;
    }

}

///////////////////////////////////////////////////////////////////////////////
// Get SCard Reader's List
BOOL CSCardManager::SCardGetPcscList(void)
{
    char    ResponseBuffer[1024];
    DWORD   ResponseLength = sizeof(ResponseBuffer);
    memset(ResponseBuffer, 0x0, sizeof(ResponseBuffer));

    if (m_ContextHandle)
    {
    	SCardReleaseContext(m_ContextHandle);
        m_ContextHandle = NULL;
    }

    ErrorCode = SCardEstablishContext(SCARD_SCOPE_USER,
    				      NULL,
    				      NULL,
    				      &m_ContextHandle);

    if (ErrorCode != SCARD_S_SUCCESS)
    {
    	wsprintf(ErrorMsg, "Function SCardEstablishContext returned 0x%08X error code.", ErrorCode);
    	return FALSE;
    }

    ErrorCode = SCardListReaders(m_ContextHandle, NULL,
    			         ResponseBuffer,
    			         &ResponseLength);

    if (ErrorCode != SCARD_S_SUCCESS)
    {
    	wsprintf(ErrorMsg, "No reader available. (%x)", ErrorCode);
    	return FALSE;
    }

    // Build the Reader List
    ReaderCount = 0;
    UINT StringLen = 0;
    while (ResponseLength > (StringLen+1))
    {
         SCReader *pReader = &ReaderList[ReaderCount];

         ZeroMemory(pReader->szReaderName, sizeof(pReader->szReaderName));

         strcpy(pReader->szReaderName, ResponseBuffer+StringLen);

         StringLen += strlen(ResponseBuffer+StringLen+1);
         StringLen += 2;

         ReaderCount++;
         if (ReaderCount >= MAX_READERS)
             break;
    }

    return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
// Open a SCard Reader by its index
BOOL CSCardManager::SCardOpen(int nIndex)
{

    if (nIndex >= ReaderCount || nIndex < 0)
    {
    	wsprintf(ErrorMsg, "%s", "Index out of bound.");
    	return FALSE;
    }

    if (m_CardHandle)
    {
    	SCardDisconnect(m_CardHandle, SCARD_EJECT_CARD);
    	m_CardHandle = NULL;
    }   

    SCReader *pReader = &ReaderList[nIndex];

    ErrorCode = SCardConnect(m_ContextHandle,
                             pReader->szReaderName,
		      	     SCARD_SHARE_SHARED,
			     SCARD_PROTOCOL_T0 | SCARD_PROTOCOL_T1,
			     &m_CardHandle,
			     &m_ActiveProtocol);

    if (ErrorCode != SCARD_S_SUCCESS)
    {
        wsprintf(ErrorMsg, "Cannot connect to this reader(Err: 0x%08x)", ErrorCode);
       	return FALSE;
    }

    m_Index = nIndex;
    m_IO_Request.dwProtocol = m_ActiveProtocol;
    m_IO_Request.cbPciLength = (DWORD)sizeof(SCARD_IO_REQUEST);

    return TRUE;
}


///////////////////////////////////////////////////////////////////////////////
// Close a SCard Reader connection
BOOL CSCardManager::SCardClose(void)
{
    if (m_CardHandle)
    {
    	SCardDisconnect(m_CardHandle, SCARD_EJECT_CARD);
    	m_CardHandle = NULL;
    }

    return TRUE;
}


///////////////////////////////////////////////////////////////////////////////
// Get ATR from a open SCard Reader
BOOL CSCardManager::SCardReset(char *strResp)
{
    BYTE  pbATR[40];
    DWORD dwATRLength = sizeof(pbATR);
    DWORD dwLength = 300;
    DWORD dwCardState = 0;
    DWORD dwActiveProtocol = 0;

    strResp = "";

    // hCardHandle was set by a previous call to SCardConnect.
    ErrorCode = SCardReconnect(m_CardHandle,
                               SCARD_SHARE_SHARED,
                               SCARD_PROTOCOL_T0 | SCARD_PROTOCOL_T1,
                               SCARD_UNPOWER_CARD,
                               &dwATRLength );

    if (ErrorCode != SCARD_S_SUCCESS)
    {
	return FALSE;
    }

    SCReader *pReader = &ReaderList[m_Index];	// Get reader name from ReaderArray

    ErrorCode = SCardStatus(m_CardHandle,				// Trick
                            pReader->szReaderName,
		            &dwLength,
		            &dwCardState,
		            &dwActiveProtocol,
		            pbATR,
		            &dwATRLength);

    ErrorCode = SCardStatus(m_CardHandle,				// Trick
                            pReader->szReaderName,
		            &dwLength,
		            &dwCardState,
		            &dwActiveProtocol,
		            pbATR,
		            &dwATRLength);

    if (ErrorCode != SCARD_S_SUCCESS)
    {   
	return FALSE;
    }

    // String convertion
    ByteToStr(pbATR, dwATRLength, strResp);

    return TRUE;
}


///////////////////////////////////////////////////////////////////////////////
//Execute APDU COMMAND , szApdu strResp Format is Hex String
BOOL CSCardManager::SCardTransmit(char *strApdu, char *strResp, WORD *SW)
{	
    BYTE   sendData[300];
    BYTE   recvData[300];
    DWORD  sendLen;
    DWORD  recvLen;
    int    len;


    len = strlen(strApdu);
    if ((len+1) > MAX_APDU_LEN)
    {
        return FALSE;
    }  

    sendLen = StrToByte(strApdu, len, sendData);   // string convertion
    recvLen = sizeof(recvData);
    ZeroMemory(recvData, sizeof(recvData));

    ErrorCode = ::SCardTransmit(m_CardHandle,			// SCard API
    				&m_IO_Request,
    				sendData,
    				sendLen,
    				NULL,
    				recvData,
    				&recvLen);

    if (ErrorCode != SCARD_S_SUCCESS)
    {
    	wsprintf(ErrorMsg, "SCardTransmit.Error(0x%08X): %s", ErrorCode, strApdu);
        return FALSE;
    }

    if (recvLen != 0)
    {
	ByteToStr(recvData, recvLen - 2, strResp);
	*SW = ((BYTE)(recvData[recvLen - 2]) * 256) +
		(BYTE)recvData[recvLen - 1];
    }

    // T=0協議中, 應用程式不能同時向智能卡發送數據,並從智能卡接收數據, 即發送到智能卡的指令中, 不能同時有Lc和Le.
    // 這只能分兩個步驟實現: 向智能卡發送數據, 接收智能卡返回的狀態碼, 其中SW2是智能卡將要返回的數據數目.
    // 從智能卡接收數據 (指令為0x00, 0xC0, 0x00, 0x00, Le)

    // RECEIVE RESPONSE DATA, IF ANY
    if (((*SW & 0xFF00) == SW_BYTES_REMAINING_00) ||
           ((*SW & 0xFF00) == SW_CORRECT_LENGTH_00))
    {

        // GET RESPONSE
        sendData[0] = 0x00;
        sendData[1] = 0xC0;
        sendData[2] = 0x00;
        sendData[3] = 0x00;
        sendData[4] = LOWBYTE(*SW);
        sendLen = 5;

        recvLen = sizeof(recvData);

        // SEND APDU
        ErrorCode = ::SCardTransmit(m_CardHandle, &m_IO_Request, sendData, sendLen, NULL, recvData, &recvLen);
        if (ErrorCode != SCARD_S_SUCCESS)
        {
            wsprintf(ErrorMsg, "SCardTransmit.Error(0x%08X)", ErrorCode);
            return FALSE;
        }

        if (recvLen != 0)
        {
            ByteToStr(recvData, recvLen - 2, strResp);
	    *SW = ((BYTE)(recvData[recvLen - 2]) * 256) +
	            (BYTE)recvData[recvLen - 1];
        }
    }

    return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
// Transmit Apdu
BOOL CSCardManager::SCardExchangeAPDU(CARDAPDU *pAPDU)
{
    BYTE   sendData[300];
    BYTE   recvData[300];
    DWORD  sendLen;
    DWORD  recvLen;

    sendData[0] = pAPDU->CLA;
    sendData[1] = pAPDU->INS;
    sendData[2] = pAPDU->P1;
    sendData[3] = pAPDU->P2;
    sendLen = 4;

    if (pAPDU->Lc != 0 && pAPDU->DataIn != NULL)
    {
        sendData[4] = pAPDU->Lc;
        sendLen++;
        memcpy(sendData+5, pAPDU->DataIn, pAPDU->Lc);
        sendLen += pAPDU->Lc;
    }

    if (pAPDU->Le != 0)
    {
        sendData[sendLen] = pAPDU->Le;
        sendLen++;
    }

    recvLen = sizeof(recvData);
    ZeroMemory(recvData, sizeof(recvData));

    // SEND APDU
    ErrorCode = ::SCardTransmit(m_CardHandle, &m_IO_Request, sendData, sendLen, NULL, recvData, &recvLen);

    if (ErrorCode != SCARD_S_SUCCESS)
    {
        wsprintf(ErrorMsg, "SCardTransmit.Error(0x%08X)", ErrorCode);
        return FALSE;
    }


    pAPDU->Le = (BYTE)(recvLen - 2);
    if (pAPDU->Le != 0 && pAPDU->DataOut != NULL)
    {
    	memcpy(pAPDU->DataOut, recvData, pAPDU->Le);  // 回傳的資料      DATA
    }
    pAPDU->SW1 = recvData[recvLen - 2];               // 最後第二 BYTE   SW1
    pAPDU->SW2 = recvData[recvLen - 1];               // 最後一個 BYTE   SW2


    // T=0協議中, 應用程式不能同時向智能卡發送數據,並從智能卡接收數據, 即發送到智能卡的指令中, 不能同時有Lc和Le.
    // 這只能分兩個步驟實現: 向智能卡發送數據, 接收智能卡返回的狀態碼, 其中SW2是智能卡將要返回的數據數目.
    // 從智能卡接收數據 (指令為0x00, 0xC0, 0x00, 0x00, Le)

    // RECEIVE RESPONSE DATA, IF ANY
    if (((pAPDU->Status & 0xFF00) == SW_BYTES_REMAINING_00) ||
           ((pAPDU->Status & 0xFF00) == SW_CORRECT_LENGTH_00))
    {

        // GET RESPONSE
        sendData[0] = 0x00;
        sendData[1] = 0xC0;
        sendData[2] = 0x00;
        sendData[3] = 0x00;
        sendData[4] = pAPDU->SW2;
        sendLen = 5;

        recvLen = sizeof(recvData);

        // SEND APDU
        ErrorCode = ::SCardTransmit(m_CardHandle, &m_IO_Request, sendData, sendLen, NULL, recvData, &recvLen);
        if (ErrorCode != SCARD_S_SUCCESS)
        {
            wsprintf(ErrorMsg, "SCardTransmit.Error(0x%08X)", ErrorCode);
            return FALSE;
        }

        pAPDU->Le = (BYTE)(recvLen - 2);
        if (pAPDU->Le != 0 && pAPDU->DataOut != NULL)
        {
            memcpy(pAPDU->DataOut, recvData, pAPDU->Le);    // 回傳的資料      DATA
        }
        pAPDU->SW1 = recvData[recvLen - 2];                 // 最後第二 BYTE   SW1
        pAPDU->SW2 = recvData[recvLen - 1];                 // 最後一個 BYTE   SW2

    }     

    return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
// Open a SCard Reader by Applet AID
BOOL CSCardManager::SCardOpen(BYTE *pAID, BYTE AID_Len)
{
    CARDAPDU  Apdu;
    SCReader *pReader;

    for (int nIndex=0; nIndex < ReaderCount; nIndex++)
    {
        pReader = &ReaderList[nIndex];

        ErrorCode = SCardConnect(m_ContextHandle,
                                 pReader->szReaderName,
		      	         SCARD_SHARE_SHARED,
			         SCARD_PROTOCOL_T0 | SCARD_PROTOCOL_T1,
			         &m_CardHandle,
			         &m_ActiveProtocol);

        if (ErrorCode == SCARD_S_SUCCESS)
        {
            m_Index = nIndex;
            m_IO_Request.dwProtocol = m_ActiveProtocol;
            m_IO_Request.cbPciLength = (DWORD)sizeof(SCARD_IO_REQUEST);  

            // Select Applet
            Apdu.CLA = 0x00;
            Apdu.INS = 0xA4;
            Apdu.P1  = 0x04;
            Apdu.P2  = 0x00;
            Apdu.Lc  = AID_Len;
            Apdu.Le  = 0;
            Apdu.DataIn = pAID;

            if (SCardExchangeAPDU(&Apdu))
            {
                if (Apdu.Status == SW_NO_ERROR)
                {
                    return TRUE;  // 成功
                }
            }
        }

        if (m_CardHandle)
        {
    	    SCardDisconnect(m_CardHandle, SCARD_EJECT_CARD);
    	    m_CardHandle = NULL;
        }

    }
    return FALSE;
}



