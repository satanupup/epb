#ifndef _jge_graphics_render_20080222pm0214_
#define _jge_graphics_render_20080222pm0214_
#include "jge_type.h"
#include "jge_containers.h"
_JGE_BEGIN

class IRender
{
public:
					IRender		();
	virtual			~IRender	();
	virtual	void	Render		() = 0;
};
//////////////////////////////////////////////////////////////////////////
typedef		IRender*				IRenderPtr;
typedef		std::map<uint,IRenderPtr>	IRenderSet;
_JGE_END


#endif