#ifndef _epb_win_time_20120622pm0945_
#define _epb_win_time_20120622pm0945_
#include "epb_time.h"
#include <windows.h>
_EPB_BEGIN

class WinTime : public ITime
{
	static LARGE_INTEGER	mLintTC;		//每秒計數次數

	LARGE_INTEGER			mLintBegin;		//開始累積次數
	LARGE_INTEGER			mLintEnd;		//結束累積次數
	uint64					mnTime;			//經過的時間
			
public:
					WinTime		();
					~WinTime	();

	static	boole	fnInitialize();
			void	SetZero		() ;
			void	Get			(TimeData& timeData) const ;
			void	Get			(uint64& nTime)	const ;
			void	Update		();
};

_EPB_END
#endif