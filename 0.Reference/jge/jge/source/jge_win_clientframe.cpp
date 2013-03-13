#include "StdAfx.h"
#include "fdo_preheader.h"
#include "jge_win_clientframe.h"
#include "jge_win_time.h"
#include "jge_win_graphics.h"
#include "jge_win_input.h"
#include "jge_timemanager.h"
#include "jge_debug.h"
#include "jge_clientFrame.h"
#include "jge_key_map.h"
#include "dsound.h"
#include "J_SoundManager.h"
#include "PhenixD3D9RenderSystem.h"
#include "JLCamera.h"
#include "JLAnimation2DManager.h"
#include "Timer.h"
#include "BinaryTableManager.h"
#include "DrawPlane.h"
#include "ResourceManager.h"
#include "FDO_RoleMemoryMgr.h"
#include "CDXUTUIBuilder.h"
//#include "Phenix.h"
#define	DEF_INPUT_UPDATE_TIME (DEF_JGE_ONE_SEC/100)


#define  _PHENIX
class PhenixGraphics : public JGE::Graphics
{
	
	FDO::D3D9RenderSystem*		mpFdoD3dSys;
public:
	PhenixGraphics(FDO::D3D9RenderSystem* pFdoD3dSys = 0) : mpFdoD3dSys(pFdoD3dSys)
	{

	}
	virtual ~PhenixGraphics()
	{		
		
	}

	//////////////////////////////////////////////////////////////////////////
	virtual	void		Render			()
	{
	if(mpFdoD3dSys)
		{
			if(mpFdoD3dSys->BeginFrame())
			{
				JGE::Graphics::Render();	
				mpFdoD3dSys->EndFrame();
			}
		}
		
	}
	virtual	void		DestoryTexture	(JGE::ITexturePtr pTxr)		
	{

	}

};


namespace WinClientSystem
{
	using namespace JGE;
	// jge system objects
	JGE::ClientFrame*	gpFrame		= 0;
	JGE::TimeManager*	gpTimeMgr	= 0;
	JGE::DebugLog*		gpLog		= 0;
	JGE::KeyMap*		gpKeyMap	= 0;			

	// win system objects
	JGE::WinTime*		gpTime		= 0;
	//PhenixSystem::CPhenixGraphics*		gpGraphics	= 0;
	
#ifdef _PHENIX
	JGE::Graphics* gpGraphics	= 0;
#else
	JGE::WinGraphics*	gpGraphics	= 0;
#endif	


	
	JGE::WinInput*		gpInput		= 0;

	// other objects
	JGE::Timer*			gpInputTimer= 0;
	FDO::CSoundManager*	gpSoundMgr = 0;
	FDO::D3D9RenderSystem*		gpFdoD3dSys = 0;
	FDO::CRenderer* gpRenderer = 0;
	FDO::BinaryTableManager*		gpBinaryTableManager = 0;
	FDO::RoleMemoryMgr           gRoleMemoryMgr;
	FDO::CImageManager           gRoleImageManager;
	// camera
	FDO::JLCamera* gpCamera = 0;

	// 
	FDO::JLAnimation2DManager* gpAni2DMgr = 0;
	//
	JGE::TimerStop fnInputUpdate(JGE::uint nData);

	//////////////////////////////////////////////////////////////////////////
	JGE::errcode	fnInitialize(const WinClientSystemInfo& wcsi)
	{
		
		
		// new win system objects
		gpTime		= new JGE::WinTime;
		gpSoundMgr	= new FDO::CSoundManager;
		gpInput		= new JGE::WinInput;
		

		// new other object
		gpInputTimer= new JGE::Timer(fnInputUpdate,DEF_INPUT_UPDATE_TIME,0);
		
#ifdef _PHENIX
		
		JGE::Graphics* pGrp;
		/*PhenixSystem::CreatePhenixGraphics(wcsi.hWnd)*/
		gpFdoD3dSys = new FDO::D3D9RenderSystem;
		gpCamera = new FDO::JLCamera;		
		gpAni2DMgr = new FDO::JLAnimation2DManager;
		pGrp	= new PhenixGraphics(gpFdoD3dSys);		
		FDO::Timer* pTime = new FDO::Timer;
		

#else
		JGE::WinGraphics* pGrp;
		pGrp	= new JGE::WinGraphics;		
#endif
		
		// new jge system objects
		gpLog		= new JGE::DebugLog;
		gpTimeMgr	= new JGE::TimeManager(gpTime);
		gpKeyMap	= new JGE::KeyMap;
		gpFrame		= new JGE::ClientFrame;		
		
		gpGraphics = pGrp ;
		
		// init system objects		
		JGE::errcode ec;
		if( (ec = gpLog->Create(wcsi.sProjectName)) == DEF_JGE_OK)
		{
			JGE::WinTime::fnInitialize();
			_JGE_DBGLOGLN(L"begin initial frame.");
			g_FDOXML.CreateFonts(0);
			if( (ec = gpFrame->Initialize(wcsi.pFirst)) == DEF_JGE_OK)
			{
				_JGE_DBGLOGLN(L"done initial frame.");
				//////////////////////////////////////////////////////////////////////////
				_JGE_DBGLOGLN(L"begin initial input system.");
				ec = gpInput->Initialize(wcsi.hinst,wcsi.hWnd);
				if(ec != DEF_JGE_OK)
				{
					_JGE_DBGLOGLN(L"Input Init Error.(%d)",ec);
				}
				else
				{
					gpTimeMgr->Register(gpInputTimer,false);
				}
				_JGE_DBGLOGLN(L"done initial input system.");
				//////////////////////////////////////////////////////////////////////////
#ifndef _PHENIX
				gpGraphics->SetCallbackDeviceCreated(wcsi.pCallbackDeviceCreated);
				gpGraphics->SetCallbackDeviceReset(wcsi.pCallbackDeviceReset);
				gpGraphics->SetCallbackDeviceLost(wcsi.pCallbackDeviceLost);
				gpGraphics->SetCallbackDeviceDestroyed(wcsi.pCallbackDeviceDestroyed);
				ec = gpGraphics->Initialize(wcsi.hWnd,wcsi.nScreenW,wcsi.nScreenH,wcsi.bFullScreen);
				if(ec != DEF_JGE_OK)
				{					
					_JGE_DBGLOGLN(L"Graphics Init Error.(%d)",ec);
				}				
#else
				if(gpFdoD3dSys)
				{					
					gpFdoD3dSys->SetCallbackDeviceCreated(wcsi.pCallbackDeviceCreated);
					gpFdoD3dSys->SetCallbackDeviceReset(wcsi.pCallbackDeviceReset);
					gpFdoD3dSys->SetCallbackDeviceLost(wcsi.pCallbackDeviceLost);
					gpFdoD3dSys->SetCallbackDeviceDestroyed(wcsi.pCallbackDeviceDestroyed);
					_JGE_DBGLOGLN(L"begin initial fdo d3d system.");
					if(gpFdoD3dSys->Initialize(wcsi.hWnd) == false)
						_JGE_DBGLOGLN(L"fdo d3d system initial error");
					
					_JGE_DBGLOGLN(L"done initial fdo d3d system.");

					gpRenderer = new FDO::CRenderer(gpFdoD3dSys->GetD3DDevice() , 1000 , 100000);	
					CDXUTDialog::SetRenderer(gpRenderer);
				}				
#endif
				//////////////////////////////////////////////////////////////////////////
				if(gpSoundMgr->_Initialize( wcsi.hWnd, DSSCL_PRIORITY, 32, 32 ) == false)
				{
					_JGE_DBGLOGLN(L"sound initial error!");
				}

				gRoleMemoryMgr.CreatePools();
				gpBinaryTableManager = new FDO::BinaryTableManager;
				FDO::ControlBuilder::fnSetTextDatabase(&gpBinaryTableManager->mCodeInlineTextBin);
				return ec;				
			}

			// frame init error
			_JGE_DBGLOGLN(L"frame init error.(%d)",ec);
		}
		else
		{
			// debug log init error
		}

		return ec;
	}
	//////////////////////////////////////////////////////////////////////////
	void fnRelease()
	{
		gRoleImageManager.Destory();
		gRoleMemoryMgr.DeletePools();

		delete gpRenderer;

 		delete gpBinaryTableManager;
 		gpBinaryTableManager = 0;

		if(FDO::Timer::GetSingletonPtr())
			delete FDO::Timer::GetSingletonPtr();

		if(gpSoundMgr) 
		{			
			delete gpSoundMgr;
			gpSoundMgr = 0;
		}
		if(gpCamera)
		{			
			delete gpCamera;
			gpCamera = 0;
		}
		if(gpAni2DMgr)
		{
			delete gpAni2DMgr;
			gpAni2DMgr = 0;
		}
		if(gpFdoD3dSys)
		{				
			delete gpFdoD3dSys ;
			gpFdoD3dSys = 0;
		}	
		
		


		// release & delete objects	
		if(gpInputTimer != 0)
		{
			gpTimeMgr->Unregister(gpInputTimer);
			delete gpInputTimer;
			gpInputTimer = 0;
		}
		if(gpFrame!=0)
		{
			gpFrame->Release();
			delete gpFrame;
			gpFrame = 0;
		}
		if(gpGraphics != 0)
		{
			//gpGraphics->Release();
			delete gpGraphics;
			gpGraphics = 0;
		}
		if(gpTime!=0)
		{			
			delete gpTime;
			gpTime = 0;
		}
		if(gpInput !=0 )
		{
			gpInput->Release();
			delete gpInput;
			gpInput = 0;
		}
		if(gpKeyMap != 0)
		{
			delete gpKeyMap;
			gpKeyMap = 0;
		}
		if(gpTimeMgr)
		{
			delete gpTimeMgr;
			gpTimeMgr = 0;
		}
		if(gpLog)
		{
			gpLog->Destory();
			delete gpLog;
			gpLog = 0;
		}

		
	}
	//////////////////////////////////////////////////////////////////////////
	JGE::errcode	fnUpdate()
	{
		if(gpFrame)
		{
			return gpFrame->Process();
		}
		return DEF_JGE_NO_FRAME;
	}
	//////////////////////////////////////////////////////////////////////////
	JGE::TimerStop fnInputUpdate(JGE::uint nData)
	{
		gpInput->Update();
		gRoleImageManager.ProcessImageBuffer();
		return false;
	}
	
}

