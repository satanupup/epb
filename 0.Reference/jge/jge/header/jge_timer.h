#ifndef _jge_timer_20080204am0103_
#define _jge_timer_20080204am0103_

#include "jge_type.h"
_JGE_BEGIN

typedef boole TimerStop;
typedef TimerStop (*PFN_ONTIME)(uint nData);
/////////////////////////////////////////////////////////////////////////////////////////////
class Timer 
{
	uint		mnInterval; 
	uint		mnData;		
	PFN_ONTIME	mpfnCallBack;		
	
public:

		Timer	(PFN_ONTIME pfn,uint nInterval,uint nData = 0);
		~Timer	();		
		//////////////////////////////////////////////////////////////////////////
		//
		void	SetOnTimeFunction	(PFN_ONTIME pfn);
		void	SetInterval			(uint nInterval);
		void	SetData				(uint nData );

		//////////////////////////////////////////////////////////////////////////
		//
		TimerStop	OnTime			();
		uint		GetInterval		() const;
};


typedef Timer*	TimerPtr;

_JGE_END

#endif