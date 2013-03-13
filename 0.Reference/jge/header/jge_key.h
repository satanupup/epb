#ifndef _jge_key_20080207am0302_
#define _jge_key_20080207am0302_
#include "jge_type.h"
_JGE_BEGIN
//////////////////////////////////////////////////////////////////////////
typedef boole KeyPress;
struct Key
{
	KeyPress	bPress;
	uint64		nUpdateTime;
};

_JGE_END
#endif