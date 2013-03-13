#ifndef _jge_clientFrame_20080126pm0631_
#define _jge_clientFrame_20080126pm0631_
#include "jge_timer.h"

#include "jge_stage.h"
#include "jge_singleton.h"
#include "jge_containers.h"

namespace JGE
{ 
	class ClientFrame : public TSingleton<ClientFrame>
	{
		typedef std::list<IStage*> StagePtrSet;
		//  
		Timer*			mptmRender;
		
		StagePtrSet		mStagePtrs;
		IStage*			mpCurStage;

		errcode		_ProcStage		();
		void		_ReleaseStages	();
	public:
		
					ClientFrame		();
		virtual		~ClientFrame	();

		errcode		Initialize		(IStage* pFirstStage);
		void		Release			();
		errcode		Process			();
		errcode 	Render			();
		
		void		PushStage		(IStage* pStage);
	};

}
#define _JGE_GAMEEND JGE::ClientFrame::fnGetInstance().PushStage(0)
#endif