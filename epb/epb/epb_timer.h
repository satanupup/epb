#ifndef _epb_timer_20120622pm0945_
#define _epb_timer_20120622pm0945_

#include "epb_type.h"
_EPB_BEGIN

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

_EPB_END

#endif