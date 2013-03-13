#include "jge_input.h"
#include "jge_debug.h"

_JGE_BEGIN

Input::Input()
{
	uint i = 0;
	for(; i < LISTENER_SLOTS;++i)
	{
		mListenerPtrs[i] = 0;
	}
}
//////////////////////////////////////////////////////////////////////////
Input::~Input()
{

}
//////////////////////////////////////////////////////////////////////////
boole Input::Register(uint nLevel,IInputListener* pListener)
{
	if(nLevel < LISTENER_SLOTS)
	{		
		mListenerPtrs[nLevel] = pListener;
		return true;
	}
	_JGE_DBGLOGLN(L"Input Listener Level=%d",nLevel);
	return false;
}
//////////////////////////////////////////////////////////////////////////
boole Input::Unregister	(IInputListener* pListener)
{
	uint i = 0;
	for(; i < LISTENER_SLOTS;++i)
	{
		if(mListenerPtrs[i] != pListener)
			continue;

		mListenerPtrs[i] = 0;
		return true;
	}
	return false;
}
//////////////////////////////////////////////////////////////////////////
PassMessage	Input::OnMessage(const Message& msg) 
{
	uint i = 0;
	PassMessage bPass = true;
	for(; i < LISTENER_SLOTS && bPass;++i)
	{
		if(mListenerPtrs[i])
		{
			bPass = mListenerPtrs[i]->OnMessage(msg);
		}
	}
	return bPass;
}

_JGE_END