#ifndef _jge_win_clientframe_20080206pm0333_
#define _jge_win_clientframe_20080206pm0333_
#include "jge_win32_platform.h"
#include "jge_type.h"
#include "jge_stage.h"
#include <windows.h>
#include <jge_win_graphics.h>

typedef struct
{
	HINSTANCE		hinst;
	HWND			hWnd;
	const JGE::char16*	sProjectName;
	JGE::IStage*			pFirst;
	JGE::uint16			nScreenW;
	JGE::uint16			nScreenH;
	JGE::boole			bFullScreen;
	JGE::LPDXUTCALLBACKDEVICECREATED pCallbackDeviceCreated;
	JGE::LPDXUTCALLBACKDEVICERESET pCallbackDeviceReset ;
	JGE::LPDXUTCALLBACKDEVICELOST pCallbackDeviceLost;
	JGE::LPDXUTCALLBACKDEVICEDESTROYED pCallbackDeviceDestroyed ;

} WinClientSystemInfo;
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
namespace WinClientSystem 
{	
	JGE::errcode	fnInitialize		(const WinClientSystemInfo& winClientSystemInfo);
	void	fnRelease			();
	JGE::errcode	fnUpdate			();
};



//////////////////////////////////////////////////////////////////////////
#define _JGE_INITIALIZE_WIN_CLIENT_SYSTEM	WinClientSystem::fnInitialize
#define _JGE_RELEASE_WIN_CLIENT_SYSTEM		WinClientSystem::fnRelease
#define _JGE_UPDATE_WIN_CLIENT_SYSTEM		WinClientSystem::fnUpdate

#endif