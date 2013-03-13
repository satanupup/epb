#ifndef _jge_input_20080126pm0651_
#define _jge_input_20080126pm0651_
#include "jge_type.h"
#include "jge_singleton.h"
#include "jge_input_listener.h"
#define DEF_JGE_INPUTLISTENER_DEBUG			0
#define DEF_JGE_INPUTLISTENER_KEYMAP		1
#define DEF_JGE_INPUTLISTENER_INTERFACE		2
#define DEF_JGE_INPUTLISTENER_RESERVE		3
#define DEF_JGE_INPUTLISTENER_USER			4

namespace JGE
{
	class Input :public TSingleton<Input>
	{
		enum{ LISTENER_SLOTS = 10};
		IInputListener*	mListenerPtrs[LISTENER_SLOTS];
	public:

					Input		();
		virtual		~Input		();
		boole		Register	(uint nLevel,IInputListener* pListener);
		boole		Unregister	(IInputListener* pListener);

		PassMessage	OnMessage	(const Message& msg) ;

	};
};

#define JgeInput JGE::Input::fnGetInstance()
#endif