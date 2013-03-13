#ifndef _jge_win_graphics_20080206pm0953_
#define _jge_win_graphics_20080206pm0953_
#include "jge_graphics.h"
#include "jge_win_type.h"

/************************************************************************/
/*	¨Ï¥ÎDirectX
*/
/************************************************************************/


_JGE_BEGIN
typedef HRESULT (CALLBACK *LPDXUTCALLBACKDEVICECREATED)( D3dDevicePtr pd3dDevice );
typedef HRESULT (CALLBACK *LPDXUTCALLBACKDEVICERESET)( D3dDevicePtr pd3dDevice );
typedef void    (CALLBACK *LPDXUTCALLBACKDEVICEDESTROYED)();
typedef void    (CALLBACK *LPDXUTCALLBACKDEVICELOST)();

class WinGraphics :public Graphics
{
	D3dDevicePtr			mpDevice;
	D3dPtr					mpD3d;

	D3dVertexBufferPtr		mpVB;
	D3DPRESENT_PARAMETERS	md3dpp;

	LPDXUTCALLBACKDEVICECREATED         mDeviceCreatedFunc;        // device created callback
	LPDXUTCALLBACKDEVICERESET           mDeviceResetFunc;          // device reset callback
	LPDXUTCALLBACKDEVICELOST            mDeviceLostFunc;           // device lost callback
	LPDXUTCALLBACKDEVICEDESTROYED       mDeviceDestroyedFunc;      // device destroyed callback

	boole			_InitVertexBuffer	();
	boole			_InitMatrices		(uint16 nScreenWidth,uint16 nScreenHeight);

	errcode			_D3dDraw				(D3dTexturePtr pD3dTxr,sint16 x,sint16 y,sint16 w,sint16 h,uint32 nDiffColor = 0xffffffff) ;
	
public:
					WinGraphics		();
					~WinGraphics	();
		errcode		Initialize		(HWND hWnd,uint16 nScreenWidth,uint16 nScreenHeight,boole bFullScreen = false);
		void		Release			();
		//////////////////////////////////////////////////////////////////////////
		
		void		Render			();

		ITexturePtr	CreateTexture	(IStreamRead* pStream,uint32 nColorKey)	;
		ITexturePtr	CreateTexture	(uint nWidth,uint nHeight)	;
		void		DestoryTexture	(ITexturePtr pTxr)		;
		errcode		Draw			(ITexturePtr pTxr,sint16 x,sint16 y,uint32 nDiffColor = 0xffffffff) ;
		errcode		DrawToTexture	(ITexturePtr pTarget,ITexturePtr pTxr,sint16 x,sint16 y,uint32 nDiffColor = 0xffffffff ) ;

		inline JGE::D3dDevicePtr GetDevice() {return mpDevice;};

		void SetCallbackDeviceCreated( LPDXUTCALLBACKDEVICECREATED pCallbackDeviceCreated )
		{ mDeviceCreatedFunc = pCallbackDeviceCreated; }
		void SetCallbackDeviceReset( LPDXUTCALLBACKDEVICERESET pCallbackDeviceReset )
		{ mDeviceResetFunc = pCallbackDeviceReset; }
		void SetCallbackDeviceLost( LPDXUTCALLBACKDEVICELOST pCallbackDeviceLost )
		{ mDeviceLostFunc = pCallbackDeviceLost; }
		void SetCallbackDeviceDestroyed( LPDXUTCALLBACKDEVICEDESTROYED pCallbackDeviceDestroyed )
		{ mDeviceDestroyedFunc = pCallbackDeviceDestroyed; }
};

_JGE_END
#endif