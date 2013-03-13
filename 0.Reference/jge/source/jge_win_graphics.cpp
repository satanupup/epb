#include "jge_win_graphics.h"
#include "jge_debug.h"
#include "jge_win_texture.h"
#include <wingdi.h>
// Our custom FVF, which describes our custom vertex structure
#define DefD3DFVF (D3DFVF_XYZ|D3DFVF_DIFFUSE|D3DFVF_TEX2)
// A structure for our custom vertex type. We added texture coordinates

struct D3DTO2DVERTEX
{
	float x,y,z;//畫面位置
	DWORD color;
	float u,v;//材質座標
} ;
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////


_JGE_BEGIN

WinGraphics::WinGraphics() : mpDevice(0),mpD3d(0),mpVB(0),
mDeviceCreatedFunc(0)   ,
mDeviceResetFunc(0)     ,
mDeviceLostFunc(0)      ,
mDeviceDestroyedFunc(0) 
{

}
//////////////////////////////////////////////////////////////////////////
WinGraphics::~WinGraphics()
{

}
//////////////////////////////////////////////////////////////////////////
errcode	WinGraphics::Initialize(HWND hWnd,uint16 nScreenWidth,uint16 nScreenHeight,boole bFullScreen)
{
	if( NULL == ( mpD3d = Direct3DCreate9( D3D_SDK_VERSION ) ) )
		return DEF_JGE_D3D_CREATE_FAIL;

	//取得顯示模式 
	D3DDISPLAYMODE d3ddm;
	if( FAILED( mpD3d->GetAdapterDisplayMode( D3DADAPTER_DEFAULT, &d3ddm ) ) )
	{
		return DEF_JGE_D3D_GET_DISPLAY_MODE_FAIL;
	}
	
	ZeroMemory( &md3dpp, sizeof(md3dpp) );
	
	md3dpp.Windowed = (bFullScreen)?FALSE:TRUE;
	md3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	md3dpp.BackBufferFormat = d3ddm.Format;
// 	d3dpp.EnableAutoDepthStencil = TRUE;
// 	d3dpp.AutoDepthStencilFormat = D3DFMT_A8R8G8B8;
	if(bFullScreen)
	{
		md3dpp.BackBufferCount=1; //全螢幕時設	
		md3dpp.BackBufferWidth=nScreenWidth; //全螢幕時設 
		md3dpp.BackBufferHeight=nScreenHeight;//全螢幕時設
	}
	

	if( FAILED( mpD3d->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&md3dpp, &mpDevice ) ) )
		return DEF_JGE_D3D_DEVICE_CREATE_FAIL;

	if(_InitVertexBuffer() == false)
		return DEF_JGE_CREATE_D3D_VERTEX_BUFFER_FAIL;

	if(_InitMatrices(nScreenWidth,nScreenHeight) == false)
	{
		return DEF_JGE_INIT_D3D_MATRICES_FAIL;
	}	

	if( mDeviceCreatedFunc != NULL )
		mDeviceCreatedFunc( mpDevice );
	return DEF_JGE_OK;
}
//////////////////////////////////////////////////////////////////////////
void WinGraphics::Release()
{
	if( mDeviceLostFunc != NULL )
		mDeviceLostFunc();

	if(mDeviceDestroyedFunc != 0)
		mDeviceDestroyedFunc();

	if( mpDevice != NULL)
	{
		mpDevice->Release();
		mpDevice = 0;
	}
	if( mpD3d != NULL)
	{
		mpD3d->Release();
		mpD3d = 0;
	}
}
//////////////////////////////////////////////////////////////////////////
void WinGraphics::Render()
{
	mpDevice->Clear( 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0,0,0,0xff), 1.0f, 0 );

	// Begin the scene
	mpDevice->BeginScene();

	// render
	JGE::Graphics::Render();

	// End the scene
	mpDevice->EndScene();
	HRESULT hr;
	if( FAILED( hr = mpDevice->Present( NULL, NULL, NULL, NULL ) ))
	{
		Sleep( 500 );

		if( FAILED( hr = mpDevice->TestCooperativeLevel() ) )
		{
			//D3DERR_INVALIDCALL
			if( hr == D3DERR_DEVICELOST )
				return ;

			if( hr == D3DERR_DEVICENOTRESET )
			{
				if( mDeviceLostFunc != NULL )
					mDeviceLostFunc();

				hr = mpDevice->Reset( &md3dpp );

				if( FAILED( hr ) )
					return ;

				if(mDeviceResetFunc)
					mDeviceResetFunc(mpDevice);
			}

			return ;
		}
	}
	
}

//////////////////////////////////////////////////////////////////////////

ITexturePtr	WinGraphics::CreateTexture(uint nWidth,uint nHeight)	
{
	enum 
	{
		enMaxTextureWidthHeight= (4096),
		enMinTextureWidthHeight = 4,
		enMaxTextureCount=32,	
	};

	uint16 wRow=0;
	uint16 wWH=enMaxTextureWidthHeight;//長寬直
	uint16 wTxrCount=0;
	uint dwTxrArea=nWidth*nHeight;//原始面積
	uint dwTxrArea1=enMaxTextureWidthHeight*enMaxTextureWidthHeight;
	uint16 wWCount=nWidth/enMaxTextureWidthHeight+1;
	uint16 wHCount=nHeight/enMaxTextureWidthHeight+1;

	uint16 wNewHW=enMaxTextureWidthHeight;

	while((uint)(wWH*wWH)*(wHCount*wWCount)>=dwTxrArea
		&&(wHCount*wWCount)< enMaxTextureCount //切細張數大於32張就停止
		&&wWH>=enMinTextureWidthHeight	//4*4是最小
		)
	{
		//比較面積
		if(dwTxrArea1-dwTxrArea==(wWH*wWH)*(wHCount*wWCount)-dwTxrArea)
		{
			//如果面積相同比較張數
			if((nWidth/wWH+1)*(nHeight/wWH+1)
				<(nWidth/wNewHW+1)*(nHeight/wNewHW+1) )
			{
				wNewHW=wWH;
				dwTxrArea1=wNewHW*wNewHW*((nWidth/wNewHW+1)*nHeight/wNewHW+1);
			}
		}
		else if((sint)dwTxrArea1-dwTxrArea>(wWH*wWH)*(wHCount*wWCount)-dwTxrArea)
		{
			//現在大於,替換新的
			wNewHW=wWH;

			//新的比較面積
			dwTxrArea1=wNewHW*wNewHW*((nWidth/wNewHW+1)*(nHeight/wNewHW+1));
		}

		wWH/=2;
		wWCount=nWidth/wWH+1;
		wHCount=nHeight/wWH+1;

	}
	wWH=wNewHW;
	//判斷藥new多少個材質
	
	wRow=(nWidth/wWH)+1;

	wTxrCount = ((nHeight/wWH)+1)*wRow;

	WinTexture* pTxr = new WinTexture(mpDevice,wWH,wRow,wTxrCount);
	if(pTxr)
	{
		pTxr->SetWidth(nWidth);
		pTxr->SetHeight(nHeight);
	};
	
	return pTxr;
}	
//////////////////////////////////////////////////////////////////////////
ITexturePtr WinGraphics::CreateTexture(IStreamRead* pStream,uint32 nColorKey)	
{
	BITMAPFILEHEADER BMPFileHead;
	BITMAPINFOHEADER BMPInfoHead;	

	pStream->Read(&BMPFileHead,sizeof(BMPFileHead));
	pStream->Read(&BMPInfoHead,sizeof(BMPInfoHead));
	if(BMPInfoHead.biBitCount == 24 )
	{
		WinTexture* pTxr = (WinTexture*)CreateTexture(BMPInfoHead.biWidth,BMPInfoHead.biHeight);
		if(pTxr)
		{
			uint16 nTxrCount = pTxr->GetD3dTxrCount();
			D3DLOCKED_RECT *pd3dlr=NULL;
			pd3dlr=new D3DLOCKED_RECT[nTxrCount];
			uint16 i=0;

			for(i=0;i<nTxrCount;++i)
			{
				//鎖定
				D3dTexturePtr pD3dTxr =  pTxr->GetD3dTexturePtr(i);
				pD3dTxr->LockRect(0,&pd3dlr[i],0,0);
			}
			//複製

			DWORD *data;

			WORD wRowCount=0;
			WORD wColCount=0;
			WORD WCount=0;
			WORD wWH = pTxr->GetD3dTxrSize();
			WORD wRow = pTxr->GetD3dTxrRow();
			BYTE r,g,b;
			int x=0;
			for(int y=(int)BMPInfoHead.biHeight-1; y>=0; y--)
			{

				wRowCount=(y) / wWH;
				x=0;			
				data = (LPDWORD)((LPBYTE)pd3dlr[wRowCount*wRow+x/wWH].pBits + pd3dlr[wRowCount*wRow+x/wWH].Pitch * y);

				WCount=-1;
				for(x=0;x<BMPInfoHead.biWidth;x++,data++ )
				{

					if(x/(wWH)!=WCount)
					{

						WCount=x/wWH;
						data = (LPDWORD)((LPBYTE)pd3dlr[wRowCount*wRow+WCount].pBits 
							+ pd3dlr[wRowCount*wRow+WCount].Pitch 
							*(y%wWH));
					}

					pStream->Read(&b,sizeof(BYTE));
					pStream->Read(&g,sizeof(BYTE));
					pStream->Read(&r,sizeof(BYTE));

					*data=0xff000000 | ((DWORD)r << 16)|((DWORD)g << 8) |((DWORD)b);
					if( nColorKey==*data )
					{
						*data = *data & 0x00ffffff;
					}
				}
			}
			for(i=0;i<nTxrCount;++i)
			{
				//解除鎖定
				D3dTexturePtr pD3dTxr = pTxr->GetD3dTexturePtr(i);
				pD3dTxr->UnlockRect(0);
			}

			delete [] pd3dlr;
		}

		return pTxr;

	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////
void WinGraphics::DestoryTexture(ITexturePtr pTxr)		
{
	delete pTxr;
}
//////////////////////////////////////////////////////////////////////////
errcode WinGraphics::_D3dDraw(D3dTexturePtr pD3dTxr,sint16 x,sint16 y,sint16 w,sint16 h,uint32 nDiffColor ) 
{
	D3dViewPort dvp;

	mpDevice->GetViewport(&dvp);
	float nScreenWidth	= (float)dvp.Width;
	float nScreenHeight	= (float)dvp.Height;
	float nTxrWidth		= w;
	float nTxrHeight	= h;
	float fx			= x;
	float fy			= y;	
	//座標轉換
	fx-=(nScreenWidth/2.0f);
	fy=0.0f-fy;
	fy=(fy-(nScreenHeight/2.0f))+(nScreenHeight-nTxrHeight);

	//nTxrWidth-=nScreenWidth;
	//nTxrHeight+=nScreenHeight;
	//設定平面座標
	D3DTO2DVERTEX* pVertices;

	if( FAILED( mpVB->Lock( 0, 0, (void**)&pVertices, 0 ) ) )
	{
		return DEF_JGE_GRAPHICS_NO_DRAW;
	}
	pVertices[0].z = pVertices[1].z = pVertices[2].z = pVertices[3].z = 1.00f;
	pVertices[0].color = pVertices[1].color = pVertices[2].color = pVertices[3].color = nDiffColor;

	/*
	pVertices[0].x = pVertices[3].x = x;
	pVertices[1].x = pVertices[2].x = nTxrWidth;

	pVertices[0].y = pVertices[1].y = nTxrHeight;
	pVertices[2].y = pVertices[3].y = y;
	*/

	//指定圖形位置&長寬
	pVertices[3].x=fx;
	pVertices[3].y=fy;

	pVertices[2].x=fx+nTxrWidth;
	pVertices[2].y=fy;

	pVertices[1].x=fx+nTxrWidth;
	pVertices[1].y=fy+nTxrHeight;

	pVertices[0].x=fx;
	pVertices[0].y=fy+nTxrHeight;

	/*
	pVertices[0].u=0.0f;pVertices[0].v=1.0f;
	pVertices[1].u=1.0f;pVertices[1].v=1.0f;
	pVertices[2].u=1.0f;pVertices[2].v=0.0f;
	pVertices[3].u=0.0f;pVertices[3].v=0.0f;
	*/
	//綁上材質的範圍

	pVertices[1].u = pVertices[2].u = 1.0f;
	pVertices[0].u = pVertices[3].u = 0.0f;
	pVertices[0].v = pVertices[1].v = 0.0f;
	pVertices[2].v = pVertices[3].v = 1.0f;

	mpVB->Unlock();	

	mpDevice->SetFVF( DefD3DFVF );//設定頂點緩衝格式
	mpDevice->SetStreamSource( 0, mpVB,0, sizeof(D3DTO2DVERTEX) );//設定設定頂點緩衝
	mpDevice->SetTexture( 0, pD3dTxr );//設定材質
	{

		mpDevice->SetTextureStageState (0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
		mpDevice->SetTextureStageState (0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
		mpDevice->SetTextureStageState (0, D3DTSS_COLOROP, D3DTOP_MODULATE);
		mpDevice->SetTextureStageState (0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
		mpDevice->SetTextureStageState (0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);
		mpDevice->SetTextureStageState (0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);

		mpDevice->SetRenderState (D3DRS_BLENDOP, D3DBLENDOP_ADD);
		mpDevice->SetRenderState (D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		mpDevice->SetRenderState (D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
		mpDevice->SetRenderState (D3DRS_ALPHABLENDENABLE, TRUE);
	}

	mpDevice->SetTextureStageState (1, D3DTSS_COLOROP, D3DTOP_DISABLE);
	mpDevice->SetTextureStageState (1, D3DTSS_ALPHAOP, D3DTOP_DISABLE);

	mpDevice->DrawPrimitive( D3DPT_TRIANGLEFAN, 0, 2 );//繪製多少頂點 單位:1三角形
	return DEF_JGE_OK;
}
//////////////////////////////////////////////////////////////////////////
errcode WinGraphics::Draw(ITexturePtr pTxr,sint16 x,sint16 y,uint32 nDiffColor) 
{
	WinTexture* pWinTxr = static_cast<WinTexture*>(pTxr);
	uint16 xCount=0;
	uint16 yCount=0;
	float fW=100.0f;//(float)wWidth/pTxrInfo->m_info.Width;//w的倍數
	float fH=100.0f;//(float)wHeight/pTxrInfo->m_info.Height;//h的倍數
	uint nTxrSize = pWinTxr->GetD3dTxrSize();
	
	sint16 wOffsetW=(sint16)((0-nTxrSize)+nTxrSize*fW) ;
	sint16 wOffsetH=(sint16)((0-nTxrSize)+nTxrSize*fH) ;

	uint i ;
	for(i = 0 ; i < pWinTxr->GetD3dTxrCount() ; ++i)
	{
		if(_D3dDraw(pWinTxr->GetD3dTexturePtr(i)
			,x+(xCount*(nTxrSize+wOffsetW))
			,y+(yCount*(nTxrSize+wOffsetH))
			,nTxrSize+ wOffsetW
			,nTxrSize+ wOffsetH
			,nDiffColor
			//,(rand() %256 + rand() % 256 * 256 + rand() % 256 * 65536)| 0xff000000 // for debug
			) == DEF_JGE_OK)
		{
			++xCount;

			if(xCount>=pWinTxr->GetD3dTxrRow())
			{
				++yCount;
				xCount=0;
			}	

			continue;
		}
		return DEF_JGE_GRAPHICS_NO_DRAW;
	}
	
	return DEF_JGE_OK;
}
//////////////////////////////////////////////////////////////////////////

errcode WinGraphics::DrawToTexture(ITexturePtr pTarget,ITexturePtr pTxr,sint16 x,sint16 y,uint32 nDiffColor ) 
{
	return Graphics::DrawToTexture(pTarget,pTxr,x,y,nDiffColor );
}
//////////////////////////////////////////////////////////////////////////
boole WinGraphics::_InitVertexBuffer()
{
	//建立頂點緩衝區
	if( FAILED( mpDevice->CreateVertexBuffer( 4*sizeof(D3DTO2DVERTEX),
		D3DUSAGE_WRITEONLY , DefD3DFVF,
		D3DPOOL_MANAGED, &mpVB ,0) ) )
	{
		_JGE_DBGLOGLN(L"d3d device create vertex buffer fail.");
		return false;
	}
	return true;
}
//////////////////////////////////////////////////////////////////////////
boole WinGraphics::_InitMatrices(uint16 nScreenWidth,uint16 nScreenHeight)
{
 	mpDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
 	mpDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
 	mpDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
 	mpDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	mpDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_DISABLE);
	mpDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

	D3DXMATRIX Ortho2D;	
	D3DXMATRIX Identity;

	D3DXMatrixOrthoLH(&Ortho2D, nScreenWidth, nScreenHeight, 0.0f, 1.0f);
	D3DXMatrixIdentity(&Identity);

	mpDevice->SetTransform(D3DTS_PROJECTION, &Ortho2D);
	//mpDevice->SetTransform(D3DTS_WORLD, &Identity);
	//mpDevice->SetTransform(D3DTS_VIEW, &Identity);
	D3DVIEWPORT9 vp;
	vp.X      = 0;
	vp.Y      = 0;
	vp.Width  = nScreenWidth;
	vp.Height = nScreenHeight;
	vp.MinZ   = 0.0f;
	vp.MaxZ   = 1.0f;

	mpDevice->SetViewport(&vp);

	return true;
}
_JGE_END