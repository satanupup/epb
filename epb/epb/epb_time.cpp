#include "epb_time.h"

_EPB_BEGIN
//1�������
const uint gOneSec = 1000000;
//////////////////////////////////////////////////////////////////////////
ITime::ITime()
{
	
}
//////////////////////////////////////////////////////////////////////////
ITime::~ITime()
{
	
}
//////////////////////////////////////////////////////////////////////////
uint ITime::fnGetOneSec() 
{
	return gOneSec;
}

_EPB_END