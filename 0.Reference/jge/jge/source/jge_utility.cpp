#include "jge_utility.h"

_JGE_BEGIN
namespace Utility
{
	boole ControllCharW(const char16 c)
	{
		return (c >= 0 && c <= 31);
	}
	//////////////////////////////////////////////////////////////////////////
	boole ControllCharA(const char8 c)
	{
		return (c >= 0 && c <= 31);
	}
	//////////////////////////////////////////////////////////////////////////
	boole ControllChar(const tchar c)
	{
#ifdef DEF_JGE_UNICODE
		return ControllCharW(c);
#else
		return ControllCharA(c);
#endif
	}
};


_JGE_END