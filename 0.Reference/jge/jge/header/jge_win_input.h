#ifndef _jge_win_input_20080207pm0355_
#define _jge_win_input_20080207pm0355_
#include "jge_input.h"
#include "jge_win_type.h"
#include <windows.h>



_JGE_BEGIN
/************************************************************************/
/*	接收微軟視窗訊息
	並採用direct input來接受任何裝置鍵入資料
*/
/************************************************************************/

class WinInput : public Input
{
	DInPtr			mpDIn;
	DInDevicePtr	mpKBDevice;
	DInDevicePtr	mpMSDevice;
	DInDevicePtr	mpJEDevice;

	uint8			mvKeyStatus[256*2];
	uint8			mvDIKeyToJGEKeyMap[256];
	uint8*			mpCurKeyStatus;
	uint8*			mpPreKeyStatus;

	errcode			_CreateKeyBoard		(HWND hWnd);
	void			_UpdateKeyBoard		();
	void			_ReleaseKeyBoard	();	
	uint8			_DIKeyToJGEKey		(uint8 nDIKey);
	void			_FlipKeyStatus		();
	void			_RegisterKeys		();
	
public:
						WinInput	();
						~WinInput	();

			errcode		Initialize		(HINSTANCE hinst,HWND hWnd);
			void		Release			();
			void		Update			();
	
			void		RegisterKey	(uint8 nDIKey,uint8 nJGEKey);
};

_JGE_END
#endif