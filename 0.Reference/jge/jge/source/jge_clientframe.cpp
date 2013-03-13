#include "jge_clientFrame.h"
#include "jge_time.h"
#include "jge_timemanager.h"
#include "jge_debug.h"
#include "jge_graphics.h"
#include "jge_input.h"
#include "jge_key_map.h"
//每秒畫的次數
#define DEF_RENDER_INTERVAL (DEF_JGE_ONE_SEC/60)
namespace JGE
{
	JGE::TimerStop fnOnTimeRender(uint nData);
	//////////////////////////////////////////////////////////////////////////
	ClientFrame::ClientFrame() : mpCurStage(0),mptmRender(0)
	{

	}
	//////////////////////////////////////////////////////////////////////////////////////////
	ClientFrame::~ClientFrame()
	{
		
	}
	//////////////////////////////////////////////////////////////////////////////////////////

	errcode ClientFrame::Initialize(IStage* pFirstStage)
	{
		mptmRender = new Timer(fnOnTimeRender,DEF_RENDER_INTERVAL,0);
		//////////////////////////////////////////////////////////////////////////
		// 註冊繪製Timer		
		JGE::TimeManager::fnGetInstancePtr()->Register(mptmRender);
		//////////////////////////////////////////////////////////////////////////
		// register KeyMap to Input
		JGE::Input::fnGetInstancePtr()->Register(DEF_JGE_INPUTLISTENER_KEYMAP,JGE::KeyMap::fnGetInstancePtr());

		//////////////////////////////////////////////////////////////////////////
		// 設定遊戲主體
		PushStage(pFirstStage);
		return DEF_JGE_OK;
	}
	//////////////////////////////////////////////////////////////////////////////////////////
	void ClientFrame::Release()
	{
		JGE::Input::fnGetInstancePtr()->Unregister(JGE::KeyMap::fnGetInstancePtr());
		JGE::TimeManager::fnGetInstancePtr()->Unregister(mptmRender);
		_ReleaseStages();
		if(mptmRender)
		{
			delete mptmRender;
			mptmRender = 0;
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////////
	errcode ClientFrame::Process()
	{
		errcode ec = _ProcStage();
		if(ec == DEF_JGE_OK)
		{
			if(JGE::TimeManager::fnGetInstancePtr())
			{
				JGE::TimeManager::fnGetInstancePtr()->Update();		
				return DEF_JGE_OK;
			}
			else
				return DEF_JGE_NO_TIMEMANAGER;
		}
		return ec;
	}
	//////////////////////////////////////////////////////////////////////////
	errcode ClientFrame::Render()
	{
		
		if(JGE::Graphics::fnGetInstancePtr())
		{	
			JGE::Graphics::fnGetInstancePtr()->Render();
			return DEF_JGE_OK;
		}
		return DEF_JGE_NO_RENDER;
	}
	//////////////////////////////////////////////////////////////////////////
	errcode ClientFrame::_ProcStage()
	{
		/************************************************************************/
		/* 處理遊戲舞台
			檢查是否還有待處理的舞台
				有的話,Leave掉目前的遊戲舞台 並且釋放舞台
				將第一個舞台抽出 放入目前處理的舞台指標
		*/
		/************************************************************************/		

		StagePtrSet::iterator it = mStagePtrs.begin();
		if(it != mStagePtrs.end())
		{
			if(mpCurStage)
			{
				mpCurStage->Leave();
				delete mpCurStage;
				mpCurStage = 0;
			}
			IStage* pStage = *it;
			if (pStage)
			{
				mpCurStage = pStage;
				mpCurStage->Enter()		;						
			}
			
			mStagePtrs.erase(it);
		}
		return (mpCurStage != 0)?DEF_JGE_OK:DEF_JGE_GAMEEND;
	}
	//////////////////////////////////////////////////////////////////////////
	void ClientFrame::_ReleaseStages()
	{
		if(mpCurStage)
		{
			mpCurStage->Leave();
			delete mpCurStage;
			mpCurStage = 0;
		}

		StagePtrSet::iterator it = mStagePtrs.begin();
		for( ; it != mStagePtrs.end() ;++it)
		{
			IStage* pStage = *it;
			if (pStage)
			{
				delete pStage;
			}			
		}
		mStagePtrs.clear();
		
	}
	//////////////////////////////////////////////////////////////////////////
	void ClientFrame::PushStage(IStage* pStage)
	{
		mStagePtrs.push_back(pStage);
	}
	//////////////////////////////////////////////////////////////////////////

	JGE::TimerStop fnOnTimeRender(uint nData)
	{
		errcode ec = ClientFrame::fnGetInstancePtr()->Render();
		
		if(DEF_JGE_OK != ec)
		{
			// debug log 
			_JGE_DBGLOGLN(L"Render Error.(%d)",ec);
		}
		return false;
	}
	//////////////////////////////////////////////////////////////////////////

	
}