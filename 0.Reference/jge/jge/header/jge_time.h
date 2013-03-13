#ifndef _jge_time_20080205pm0100_
#define _jge_time_20080205pm0100_
#include "jge_type.h"
_JGE_BEGIN
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


#define DEF_JGE_ONE_SEC ITime::fnGetOneSec()
_JGE_END

#endif