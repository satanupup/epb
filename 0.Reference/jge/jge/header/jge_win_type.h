#ifndef _jge_win_type_20080206pm1008_ 
#define _jge_win_type_20080206pm1008_ 
#include <d3d9.h>
#include <d3dx9.h>
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>

#pragma comment (lib, "dxguid.lib")
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")
#pragma comment (lib, "dinput8.lib")


_JGE_BEGIN

typedef LPDIRECT3D9				D3dPtr;
typedef LPDIRECT3DDEVICE9		D3dDevicePtr;
typedef LPDIRECT3DVERTEXBUFFER9	D3dVertexBufferPtr;
typedef LPDIRECT3DTEXTURE9		D3dTexturePtr;

typedef LPDIRECTINPUT8			DInPtr;
typedef LPDIRECTINPUTDEVICE8	DInDevicePtr;
typedef D3DVIEWPORT9			D3dViewPort;


_JGE_END

#endif 
