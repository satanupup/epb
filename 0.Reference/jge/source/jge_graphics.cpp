#include "jge_graphics.h"

namespace JGE
{
	Graphics::Graphics()
	{

	}
	//////////////////////////////////////////////////////////////////////////
	Graphics::~Graphics()
	{
		
	}	
	//////////////////////////////////////////////////////////////////////////
	void Graphics::Render()
	{
		
		IRenderSet::iterator it = mIRenderSet.begin();
		for (; it != mIRenderSet.end() ; ++it)
		{
			IRenderPtr pRender = (*it).second;
			pRender->Render();
		}
		
		
	}
	//////////////////////////////////////////////////////////////////////////
	boole Graphics::Register(uint nLevel,IRenderPtr pRender)
	{
		IRenderSet::iterator it = mIRenderSet.find(nLevel);
		if(it == mIRenderSet.end())
		{
			mIRenderSet[nLevel] = pRender;
			return true;
		}	
		return false;
	}
	//////////////////////////////////////////////////////////////////////////
	void Graphics::Unregister(IRenderPtr pRender)
	{
		IRenderSet::iterator it = mIRenderSet.begin();
		for (; it != mIRenderSet.end() ; ++it)
		{
			IRenderPtr pRender2 = (*it).second;
			if(pRender != pRender2)
				continue;

			mIRenderSet.erase(it);
			return;
		}
	}
	//////////////////////////////////////////////////////////////////////////
	errcode Graphics::Draw(ITexturePtr pTxr,sint16 x,sint16 y,uint32 nDiffColor)
	{
		return DEF_JGE_GRAPHICS_NO_DRAW;
	}
	//////////////////////////////////////////////////////////////////////////
	errcode Graphics::DrawToTexture(ITexturePtr pTarget,ITexturePtr pTxr,sint16 x,sint16 y,uint32 nDiffColor ) 
	{
		return DEF_JGE_GRAPHICS_NO_DRAW;
	}
	//////////////////////////////////////////////////////////////////////////
	ITexturePtr Graphics::CreateTexture(uint nWidth,uint nHeight)	
	{
		return 0;
	}
	//////////////////////////////////////////////////////////////////////////
	ITexturePtr Graphics::CreateTexture(IStreamRead* pStream,uint32 nColorKey)	
	{
		return 0;
	}
}