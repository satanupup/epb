#ifndef _jge_userinterface_manager_20080214ap1114_
#define _jge_userinterface_manager_20080214ap1114_
#include "jge_type.h"
#include "jge_singleton.h"

#include "jge_containers.h"
#include "jge_input_listener.h"
#include "jge_graphics_render.h"
#include "jge_texture.h"
_JGE_UI_BEGIN

typedef uint	UIId;
class Window 
{	
	typedef std::list<Window*>	WindowSet;
	UIId			mId;
	Window*			mpParent;	
	WindowSet		mChilds;
	
public:
					Window		(UIId nId,Window* pParent);
	virtual			~Window		();

	virtual	void	OnDraw		();			

	virtual	void	AddChild	(Window* pWnd);

};

/************************************************************************/
/*	
	管理ui window
	決定將wnd message送到哪個ui window
*/
/************************************************************************/
class Manager : public TSingleton<Manager> , public IInputListener , public IRender
{
	ITexturePtr	mpBack;
public:
				Manager		();
				~Manager	();

	boole		Initialize	();
	PassMessage	OnMessage	(const Message& msg) ;
	void		Render		();
	errcode		UpdateDraw	(sint16 x,sint16 y,uint nWidth,uint nHeight,ITexturePtr pTxr);
};

_JGE_UI_END
#endif