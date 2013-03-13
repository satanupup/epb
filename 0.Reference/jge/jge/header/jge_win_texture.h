#ifndef _jge_win_texture_20080208am1159_
#define _jge_win_texture_20080208am1159_
#include "jge_texture.h"
#include "jge_win_type.h"

_JGE_BEGIN

class WinTexture : public ITexture
{

	D3dTexturePtr*	mpTxrs;
	uint16			mTxrSize;//產生的圖形寬高
	uint16			mRow;			//一列的數量
	uint			mTxrCount;
public:
					WinTexture		(D3dDevicePtr pDevice,uint16 nTxrSize,uint16 nRow,uint nTxrCount);
					~WinTexture		();	
	D3dTexturePtr	GetD3dTexturePtr	(uint iIdx);
	uint			GetD3dTxrCount	()	const;
	uint16			GetD3dTxrRow	()	const;
	uint16			GetD3dTxrSize	()	const;
};


_JGE_END
#endif