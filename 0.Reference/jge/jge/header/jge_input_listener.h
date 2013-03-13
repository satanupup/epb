#ifndef _jge_input_listener_20080207am0156_
#define _jge_input_listener_20080207am0156_
#include "jge_type.h"
#include "jge_input_message.h"
_JGE_BEGIN


//////////////////////////////////////////////////////////////////////////
typedef boole	PassMessage;
class IInputListener
{
public:
						IInputListener	();
	virtual				~IInputListener	();
	virtual	PassMessage	OnMessage		(const Message& msg) = 0;

};
_JGE_END

#endif