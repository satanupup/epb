#include "jge_win_texture.h"
_JGE_BEGIN
//////////////////////////////////////////////////////////////////////////
WinTexture::WinTexture(D3dDevicePtr pDevice,uint16 nTxrSize,uint16 nRow,uint nTxrCount)
:mTxrSize(nTxrSize) , mRow(nRow) , mTxrCount(nTxrCount)
, mpTxrs(new D3dTexturePtr[nTxrCount])
{
	D3dTexturePtr*	ppTxrs= NULL;
	
	uint16 i=0;	
	for(i=0;i<mTxrCount;++i)
	{
		//產生材質		
		//建立		
		D3DXCreateTexture(pDevice,mTxrSize,mTxrSize, 0, 0, D3DFMT_A8R8G8B8,D3DPOOL_MANAGED, &mpTxrs[i]);
	}

}
//////////////////////////////////////////////////////////////////////////
WinTexture::~WinTexture()
{
	uint16 i=0;	
	for(i=0;i<mTxrCount;++i)
	{
		if (mpTxrs[i] != NULL)
		{
			mpTxrs[i]->Release();
			mpTxrs[i] = NULL;
		}
	}
	delete mpTxrs;
	mpTxrs = 0;
	mTxrCount = 0;
	mRow = 0;
	mTxrSize = 0;
}
//////////////////////////////////////////////////////////////////////////
D3dTexturePtr WinTexture::GetD3dTexturePtr(uint iIdx)
{
	if(iIdx < mTxrCount)
		return mpTxrs[iIdx];
	return 0;
}
//////////////////////////////////////////////////////////////////////////
uint WinTexture::GetD3dTxrCount	()	const
{
	return mTxrCount;
}
//////////////////////////////////////////////////////////////////////////
uint16 WinTexture::GetD3dTxrRow	()	const
{
	return mRow;
}
//////////////////////////////////////////////////////////////////////////
uint16 WinTexture::GetD3dTxrSize	()	const
{
	return mTxrSize;
}

_JGE_END
