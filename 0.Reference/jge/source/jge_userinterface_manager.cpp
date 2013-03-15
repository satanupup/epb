#include "jge_userinterface_manager.h"


_JGE_UI_BEGIN

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
Window::Window(UIId nId,Window* pParent) : mId(nId) ,mpParent(pParent)
{
	
}
//////////////////////////////////////////////////////////////////////////
Window::~Window()
{

}

//////////////////////////////////////////////////////////////////////////
void Window::OnDraw()
{
	WindowSet::iterator it = mChilds.begin(); 
	for (; it != mChilds.end() ; ++it)
	{		
		Window* pWnd = *it;
		pWnd->OnDraw();
	}
}


//////////////////////////////////////////////////////////////////////////
void Window::AddChild(Window* pWnd)
{
	mChilds.push_back(pWnd);
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

Manager::Manager()
{

}
//////////////////////////////////////////////////////////////////////////
Manager::~Manager()
{

}
//////////////////////////////////////////////////////////////////////////
PassMessage Manager::OnMessage(const Message& msg) 
{
	return true;
}
//////////////////////////////////////////////////////////////////////////
void Manager::Render()
{	
	if(mpBack)
	{
		//JgeGraphics.Draw(mpBack,0,0);
	}
}
//////////////////////////////////////////////////////////////////////////
errcode Manager::UpdateDraw(sint16 x,sint16 y,uint nWidth,uint nHeight,ITexturePtr pTxr)
{
	return DEF_JGE_OK;
}
_JGE_UI_END