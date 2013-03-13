#ifndef _jge_graphics_20080126pm0635_
#define _jge_graphics_20080126pm0635_

#include "jge_type.h"
#include "jge_singleton.h"
#include "jge_texture.h"
#include "jge_graphics_render.h"
#include "jge_stream_def.h"
#define DEF_JGE_RENDER_LEVEL_STAGE	0
namespace JGE
{

	class Graphics : public TSingleton<Graphics>
	{
		IRenderSet			mIRenderSet;
	public:		
							Graphics		();
		virtual				~Graphics		();

		virtual	ITexturePtr	CreateTexture	(IStreamRead* pStream,uint32 nColorKey)	;
		virtual	ITexturePtr	CreateTexture	(uint nWidth,uint nHeight)	;
		

		virtual	void		DestoryTexture	(ITexturePtr pTxr)		= 0;
		virtual	errcode		Draw			(ITexturePtr pTxr,sint16 x,sint16 y,uint32 nDiffColor = 0xffffffff) ;
		virtual	errcode		DrawToTexture	(ITexturePtr pTarget,ITexturePtr pTxr,sint16 x,sint16 y,uint32 nDiffColor = 0xffffffff) ;

		virtual	void		Render			();

				boole		Register		(uint nLevel,IRenderPtr pRender);
				void		Unregister		(IRenderPtr pRender);
	};
};

#define JgeGraphics		JGE::Graphics::fnGetInstance()
#define JgeGraphicsPtr	JGE::Graphics::fnGetInstancePtr()
#endif