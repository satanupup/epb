#ifndef _jge_input_message_20080207am0317_
#define _jge_input_message_20080207am0317_

#define JGECMD_KEY_UPDATE	1
#define JGECMD_MOUSE_MOVE	2
#define JGECMD_USER			10000



_JGE_BEGIN

struct Message
{
	uint32	Command;
	union
	{
		struct  
		{
			uint32	LoParam;
			uint32	HiParam;			
		};
		uint64	Param;
	};	
	sint16	x;
	sint16	y;
};



_JGE_END

#define JGEMSG JGE::Message
#endif