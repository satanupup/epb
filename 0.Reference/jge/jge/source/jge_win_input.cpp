#include "jge_win_input.h"
#include "jge_debug.h"
#include "jge_keymap_define.h"
#define KEYDOWN(name, key) (name[key] & 0x80)

_JGE_BEGIN
#define DEF_DI_KEY_COUNT (DIK_MEDIASELECT-DIK_ESCAPE)


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

WinInput::WinInput() 
: mpDIn(0) ,mpKBDevice(0) ,mpMSDevice(0),mpJEDevice(0)
{
	memset(mvKeyStatus,0,sizeof(mvKeyStatus));
	mpCurKeyStatus = &mvKeyStatus[0];
	mpPreKeyStatus = &mvKeyStatus[256];

	memset(mvDIKeyToJGEKeyMap,KeyMapDefine::KB_NULL,sizeof(mvDIKeyToJGEKeyMap));
}
//////////////////////////////////////////////////////////////////////////
WinInput::~WinInput()
{
	
}
//////////////////////////////////////////////////////////////////////////
errcode WinInput::Initialize(HINSTANCE hinst,HWND hWnd)
{
	HRESULT hr; 
	errcode ec;
	hr = DirectInput8Create(hinst, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&mpDIn, NULL); 
	if FAILED(hr) 
	{ 
		// DirectInput not available; take appropriate action 
		return DEF_JGE_DIN_CREATE_FAIL;
	} 
	
	ec = _CreateKeyBoard(hWnd);
	if(ec != DEF_JGE_OK)
	{
		Release();
		return ec;
	}

	_RegisterKeys();

	return DEF_JGE_OK;
}
//////////////////////////////////////////////////////////////////////////
void WinInput::Release()
{
	_ReleaseKeyBoard();
	if(mpDIn)
	{
		mpDIn->Release();
		mpDIn = 0;
	}
}
//////////////////////////////////////////////////////////////////////////
errcode	WinInput::_CreateKeyBoard(HWND hWnd)
{
	HRESULT hr; 
	//////////////////////////////////////////////////////////////////////////
	// create keyboard device 
	hr = mpDIn->CreateDevice(GUID_SysKeyboard, &mpKBDevice, NULL); 
	if FAILED(hr) 
	{ 	
		return DEF_JGE_DIN_CREATE_KB_FAIL; 
	} 

	hr = mpKBDevice->SetDataFormat(&c_dfDIKeyboard); 
	if FAILED(hr) 
	{ 	
		return DEF_JGE_DIN_CREATE_KB_FAIL; 
	} 

	hr = mpKBDevice->SetCooperativeLevel(hWnd,DISCL_FOREGROUND | DISCL_NONEXCLUSIVE); 
	if FAILED(hr) 
	{ 	
		return DEF_JGE_DIN_CREATE_KB_FAIL; 
	} 
	
	
	return DEF_JGE_OK;
}
//////////////////////////////////////////////////////////////////////////
void WinInput::_UpdateKeyBoard()
{
	if (mpKBDevice) 
	{
		mpKBDevice->Acquire(); 
		mpKBDevice->GetDeviceState(sizeof(uint8) * 256,mpCurKeyStatus);
		uint i=0;
		for( ; i< 256;++i)
		{
			if(mpCurKeyStatus[i] == mpPreKeyStatus[i])
				continue;

			// ¦³ÅÜªºkey
			Message msg;
			memset(&msg,0,sizeof(Message));
			msg.Command = JGECMD_KEY_UPDATE;
			msg.HiParam = _DIKeyToJGEKey(i);
			msg.LoParam = KEYDOWN(mpCurKeyStatus,i);
			
			OnMessage(msg);
		}

		_FlipKeyStatus();		
	}
}
//////////////////////////////////////////////////////////////////////////
void WinInput::_ReleaseKeyBoard()
{
	if(mpKBDevice)
	{
		mpKBDevice->Unacquire();
		mpKBDevice->Release();
		mpKBDevice = 0;
	}
}

//////////////////////////////////////////////////////////////////////////
void WinInput::_FlipKeyStatus()
{
// 	(uint)(mpCurKeyStatus) ^= (uint)(mpPreKeyStatus); 
// 	(uint)(mpPreKeyStatus) ^= (uint)(mpCurKeyStatus); 
// 	(uint)(mpCurKeyStatus) ^= (uint)(mpPreKeyStatus); 

	uint8* pTmp = mpCurKeyStatus;
	mpCurKeyStatus = mpPreKeyStatus;
	mpPreKeyStatus = pTmp;
}
//////////////////////////////////////////////////////////////////////////
uint8 WinInput::_DIKeyToJGEKey(uint8 nDIKey)
{
	if(nDIKey < 256)
		return mvDIKeyToJGEKeyMap[nDIKey];

	_JGE_DBGLOGLN(L"error dikey:%d",nDIKey);
	return KeyMapDefine::KB_NULL;
}
//////////////////////////////////////////////////////////////////////////
void WinInput::Update()
{
	_UpdateKeyBoard();
}
//////////////////////////////////////////////////////////////////////////
void WinInput::RegisterKey(uint8 nDIKey,uint8 nJGEKey)
{
	if(nDIKey < 256)
	{
		mvDIKeyToJGEKeyMap[nDIKey] = nJGEKey;
		return;
	}
	_JGE_DBGLOGLN(L"register error dikey:%d",nDIKey);
}
//////////////////////////////////////////////////////////////////////////
void WinInput::_RegisterKeys()
{
	RegisterKey(DIK_RETURN,KeyMapDefine::KB_ENTER);
	RegisterKey(DIK_SYSRQ,KeyMapDefine::KB_PRINT);
	RegisterKey(DIK_F5,KeyMapDefine::KB_F5);

	RegisterKey(DIK_0,KeyMapDefine::KB_0);
	RegisterKey(DIK_1,KeyMapDefine::KB_1);
	RegisterKey(DIK_2,KeyMapDefine::KB_2);
	RegisterKey(DIK_3,KeyMapDefine::KB_3);
	RegisterKey(DIK_4,KeyMapDefine::KB_4);
	RegisterKey(DIK_5,KeyMapDefine::KB_5);
	RegisterKey(DIK_6,KeyMapDefine::KB_6);
	RegisterKey(DIK_7,KeyMapDefine::KB_7);
	RegisterKey(DIK_8,KeyMapDefine::KB_8);
	RegisterKey(DIK_9,KeyMapDefine::KB_9);

	RegisterKey(DIK_NUMPAD0,KeyMapDefine::KB_NUM0);
	RegisterKey(DIK_NUMPAD1,KeyMapDefine::KB_NUM1);
	RegisterKey(DIK_NUMPAD2,KeyMapDefine::KB_NUM2);
	RegisterKey(DIK_NUMPAD3,KeyMapDefine::KB_NUM3);
	RegisterKey(DIK_NUMPAD4,KeyMapDefine::KB_NUM4);
	RegisterKey(DIK_NUMPAD5,KeyMapDefine::KB_NUM5);
	RegisterKey(DIK_NUMPAD6,KeyMapDefine::KB_NUM6);
	RegisterKey(DIK_NUMPAD7,KeyMapDefine::KB_NUM7);
	RegisterKey(DIK_NUMPAD8,KeyMapDefine::KB_NUM8);
	RegisterKey(DIK_NUMPAD9,KeyMapDefine::KB_NUM9);

	RegisterKey(DIK_A,KeyMapDefine::KB_A);
	RegisterKey(DIK_B,KeyMapDefine::KB_B);
	RegisterKey(DIK_C,KeyMapDefine::KB_C);
	RegisterKey(DIK_D,KeyMapDefine::KB_D);
	RegisterKey(DIK_E,KeyMapDefine::KB_E);
	RegisterKey(DIK_F,KeyMapDefine::KB_F);
	RegisterKey(DIK_G,KeyMapDefine::KB_G);
	RegisterKey(DIK_H,KeyMapDefine::KB_H);
	RegisterKey(DIK_I,KeyMapDefine::KB_I);
	RegisterKey(DIK_J,KeyMapDefine::KB_J);
	RegisterKey(DIK_K,KeyMapDefine::KB_K);
	RegisterKey(DIK_L,KeyMapDefine::KB_L);
	RegisterKey(DIK_M,KeyMapDefine::KB_M);
	RegisterKey(DIK_N,KeyMapDefine::KB_N);
	RegisterKey(DIK_O,KeyMapDefine::KB_O);
	RegisterKey(DIK_P,KeyMapDefine::KB_P);
	RegisterKey(DIK_Q,KeyMapDefine::KB_Q);
	RegisterKey(DIK_R,KeyMapDefine::KB_R);
	RegisterKey(DIK_S,KeyMapDefine::KB_S);
	RegisterKey(DIK_T,KeyMapDefine::KB_T);
	RegisterKey(DIK_U,KeyMapDefine::KB_U);
	RegisterKey(DIK_V,KeyMapDefine::KB_V);
	RegisterKey(DIK_W,KeyMapDefine::KB_W);
	RegisterKey(DIK_X,KeyMapDefine::KB_X);
	RegisterKey(DIK_Y,KeyMapDefine::KB_Y);
	RegisterKey(DIK_Z,KeyMapDefine::KB_Z);
	
	
}
_JGE_END