#include "jge_key_map.h"
#include "jge_timemanager.h"
#include "jge_debug.h"
_JGE_BEGIN
KeyMap::KeyMap()
{
	memset(mKeys,0,sizeof(Key) * KeyMapDefine::Count);
}
//////////////////////////////////////////////////////////////////////////
KeyMap::~KeyMap()
{

}
//////////////////////////////////////////////////////////////////////////
void KeyMap::Set(uint16 nKey,KeyPress bPress)
{
	if(nKey < KeyMapDefine::Count)
	{
		mKeys[nKey].bPress = bPress;
		TimeManager::fnGetInstancePtr()->GetTime()->Get(mKeys[nKey].nUpdateTime);
		return ;
	}
	_JGE_DBGLOGLN(L"Not Key Define KeyNum:%d",nKey);
}
//////////////////////////////////////////////////////////////////////////
const Key* KeyMap::Get(uint16 nKey)	const
{
	if(nKey < KeyMapDefine::Count)
	{		
		return &mKeys[nKey];
	}

	_JGE_DBGLOGLN(L"Not Key Define KeyNum:%d",nKey);
	return 0;
}
//////////////////////////////////////////////////////////////////////////
PassMessage KeyMap::OnMessage(const Message& msg) 
{
	if(msg.Command == JGECMD_KEY_UPDATE)
	{
		Set(msg.HiParam,msg.LoParam!=0);
	}
	return true;
}

_JGE_END