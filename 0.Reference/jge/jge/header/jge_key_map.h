#ifndef _jge_key_map_20080207am0303_
#define _jge_key_map_20080207am0303_
#include "jge_key.h"
#include "jge_keymap_define.h"
#include "jge_singleton.h"
#include "jge_input_listener.h"
_JGE_BEGIN
//////////////////////////////////////////////////////////////////////////
class KeyMap : public IInputListener , public TSingleton<KeyMap>
{
	Key	mKeys[KeyMapDefine::Count];
public:
				KeyMap		();
	virtual		~KeyMap		();
	void		Set			(uint16 nKey,KeyPress bPress);
	const Key*	Get			(uint16 nKey)	const;

	PassMessage	OnMessage	(const Message& msg) ;
};
_JGE_END
#endif