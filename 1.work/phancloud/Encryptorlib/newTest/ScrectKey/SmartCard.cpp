#include "Utility.h"
#include "SCardAPI.h"   

CSCardManager SCard;
//---------------------------------------------------------------------------
// ヘ:琩тゴ秨SmartCard杆竚
// 把计:
// 肚:
//---------------------------------------------------------------------------
SC_STATUS SC_API SC_Open()
{
    BYTE Applet_AID[]= {0xa0, 0x00, 0x00, 0x00, 0x62, 0x03, 0x01, 0x0c, 0x01, 0x01};

    SCard.SCardGetPcscList();
    SCard.SCardOpen(Applet_AID, sizeof(Applet_AID));

    return SC_SUCCESS;
}

//---------------------------------------------------------------------------
// ヘ:闽超籔SmartCard杆竚穦杠
// 把计:
// 肚:
//---------------------------------------------------------------------------
SC_STATUS SC_API SC_Close()
{
    SCard.SCardClose();

    return SC_SUCCESS;
}

//---------------------------------------------------------------------------
// ヘ:钡肚患㏑倒SmartCard杆竚
// 把计:
// 肚:
//---------------------------------------------------------------------------
SC_STATUS SC_API SC_Transmit(
    CARDAPDU *Apdu                            // [in][out]
){

    if (!SCard.SCardExchangeAPDU(Apdu))
    {
        return SC_DEVICE_REMOVED;        // 杆竚砆簿埃
    }

    if (Apdu->Status != SW_NO_ERROR)
    {
        return SC_COMMUNICATIONS_ERROR;  // 砞称礚臫莱
    }

    return SC_SUCCESS;                  // ㏑Θ磅︽
}

//---------------------------------------------------------------------------
// ヘ: 弄﹚ず甧
// 把计:
// 肚:
//---------------------------------------------------------------------------
SC_STATUS SC_API SC_Read(
    unsigned long  Offset,                     // [in]
    unsigned char *Buffer,                     // [out]
    unsigned long  Size                        // [in]

){
    CARDAPDU  apdu;
    SC_STATUS status;


    if (Buffer == NULL)
        return  SC_INVALID_PARAMETER;                 //礚把计,叫浪琩把计
    if (Size == 0)
        return  SC_INVALID_PARAMETER;                 //礚把计,叫浪琩把计

    apdu.CLA = 0x80;
    apdu.INS = 0x31;
    apdu.P1  = (Offset >> 8);                     // Offest High Byte
    apdu.P2  = (Offset & 0xFF);                   // Offest Low Byte
    apdu.Lc  = 0;
    apdu.Le  = SC_BLOCK_SIZE;
    apdu.DataIn = NULL;
    apdu.DataOut = Buffer;

    while (Size > 0)
    {
        if (Size > SC_BLOCK_SIZE)
        {
            status = SC_Transmit(&apdu);
            if (status != SC_SUCCESS)
                break;
            Offset += SC_BLOCK_SIZE;
            Size -= SC_BLOCK_SIZE;
            apdu.P1  = (Offset >> 8);
            apdu.P2  = (Offset & 0xFF);
            apdu.DataOut += SC_BLOCK_SIZE;
        }
        else
        {
            apdu.Le = Size;
            status = SC_Transmit(&apdu);
            break;
        }
    }
    return (status);

}
//---------------------------------------------------------------------------
// ヘ: 糶﹚ず甧
// 把计:
// 肚:
//---------------------------------------------------------------------------
SC_STATUS SC_API SC_Write(
    unsigned long  Offset,                     // [in]
    unsigned char *Buffer,                     // [in]
    unsigned long  Size                       // [in]     ﹚璶糶Byte计
){
    CARDAPDU  apdu;
    SC_STATUS status;

    if (Buffer == NULL)
        return  SC_INVALID_PARAMETER;                 //礚把计,叫浪琩把计
    if (Size == 0)
        return  SC_INVALID_PARAMETER;                 //礚把计,叫浪琩把计


    apdu.CLA = 0x80;
    apdu.INS = 0x33;
    apdu.P1  = (Offset >> 8);        // Offest High Byte
    apdu.P2  = (Offset & 0xFF);      // Offest Low Byte
    apdu.Lc  = SC_BLOCK_SIZE;
    apdu.Le  = 0;
    apdu.DataIn  = Buffer;
    apdu.DataOut = NULL;
    while (Size > 0)
    {
        if (Size > SC_BLOCK_SIZE)
        {
            status = SC_Transmit(&apdu);
            if (status != SC_SUCCESS)
                break;
            Offset += SC_BLOCK_SIZE;
            Size -= SC_BLOCK_SIZE;
            apdu.P1  = (Offset >> 8);
            apdu.P2  = (Offset & 0xFF);
            apdu.DataIn += SC_BLOCK_SIZE;
        }
        else
        {
            apdu.Lc = Size;
            status = SC_Transmit(&apdu);
            break;
        }
    }
    return (status);
}




