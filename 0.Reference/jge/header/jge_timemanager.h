#ifndef _jge_timemanager_20080126pm0740_
#define _jge_timemanager_20080126pm0740_
#include "jge_containers.h"
#include "jge_timer.h"
#include "jge_time.h"
#include "jge_singleton.h"
namespace JGE
{
	
	//////////////////////////////////////////////////////////////////////////
	class TimeManager : public TSingleton<TimeManager>
	{ 
		struct TimerData
		{
			TimerPtr	pTimer;
			uint64		nLastTime;
			TimerStop	bStop;
		};
		typedef TimerData*	TimerDataPtr;
		typedef std::list<TimerDataPtr>	TimerDataSet;

		TimerDataSet	mTimeDatas;
		ITime*			mpTime;
				
		boole			_IsOnTime		(TimerDataPtr ptd);
	public:
						TimeManager		(ITime* pTime);
		virtual			~TimeManager	();

		void			Register		(TimerPtr pTimer,TimerStop bStop = false);
		void			Unregister		(TimerPtr pTimer);

		void			Update			();
		//////////////////////////////////////////////////////////////////////////
		const ITime*	GetTime			() const ;
	};
}
#endif