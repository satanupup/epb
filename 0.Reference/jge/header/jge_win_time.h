#ifndef _jge_win_time_20080205pm0108_
#define _jge_win_time_20080205pm0108_
#include "jge_time.h"
#include <windows.h>
_JGE_BEGIN

class WinTime : public ITime
{
	static LARGE_INTEGER	mLintTC;		//–璸计Ω计

	LARGE_INTEGER			mLintBegin;		//秨﹍仓縩Ω计
	LARGE_INTEGER			mLintEnd;		//挡仓縩Ω计
	uint64					mnTime;			//竒筁丁
			
public:
					WinTime		();
					~WinTime	();

	static	boole	fnInitialize();
			void	SetZero		() ;
			void	Get			(TimeData& timeData) const ;
			void	Get			(uint64& nTime)	const ;
			void	Update		();
};

_JGE_END
#endif