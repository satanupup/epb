#ifndef _epb_time_20120622pm0945_
#define _epb_time_20120622pm0945_
#include "epb_type.h"
_EPB_BEGIN
//////////////////////////////////////////////////////////////////////////
struct TimeData
{
	uint16	year;
	uint8	moon;
	uint8	day;
	uint8	hour;
	uint8	min;
	uint8	sec;
};
//////////////////////////////////////////////////////////////////////////
class ITime 
{
public:
					ITime		();
	virtual			~ITime		();

	
	virtual void	SetZero		() = 0;
	virtual void	Get			(TimeData& timeData) const = 0;
	virtual void	Get			(uint64& nTime)	const = 0;
	virtual void	Update		() = 0;

	static	uint	fnGetOneSec	() ;
};


#define DEF_EPB_ONE_SEC ITime::fnGetOneSec()
_EPB_END

#endif