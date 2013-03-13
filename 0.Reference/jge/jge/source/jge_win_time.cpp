#include "jge_win_time.h"
#include "jge_debug.h"
_JGE_BEGIN

LARGE_INTEGER WinTime::mLintTC;
//////////////////////////////////////////////////////////////////////////
WinTime::WinTime() : mnTime(0)
{
	//紀錄開始時間
	SetZero();
}
//////////////////////////////////////////////////////////////////////////
WinTime::~WinTime()
{

}
//////////////////////////////////////////////////////////////////////////
boole WinTime::fnInitialize()
{
	//取得每秒cpu頻率
	QueryPerformanceFrequency(&mLintTC);
	_JGE_DBGLOGLN(L"cpu每%f秒更新率 : %I64d",1.0f/DEF_JGE_ONE_SEC,mLintTC.QuadPart/DEF_JGE_ONE_SEC);
	return mLintTC.QuadPart > DEF_JGE_ONE_SEC;
}


//////////////////////////////////////////////////////////////////////////
void WinTime::SetZero() 
{
	mnTime = 0;
	QueryPerformanceCounter(&mLintBegin);
}
//////////////////////////////////////////////////////////////////////////
void WinTime::Get(TimeData& timeData) const
{
	
	
}
//////////////////////////////////////////////////////////////////////////
void WinTime::Get(uint64& nTime) const
{	
	//取得秒數
	nTime = mnTime / (mLintTC.QuadPart / DEF_JGE_ONE_SEC);

}
//////////////////////////////////////////////////////////////////////////
//更新經過時間
void WinTime::Update()
{
	if(QueryPerformanceCounter(&mLintEnd) == TRUE)
		mnTime = mLintEnd.QuadPart - mLintBegin.QuadPart;
#ifdef DEF_JGE_DEBUG
	else
	{
		_JGE_DBGLOGLN(L"WinTime::Update QueryPerformanceCounter Fail.");
	}

#endif
}

_JGE_END