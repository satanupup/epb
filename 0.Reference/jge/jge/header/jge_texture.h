#ifndef _jge_texture_20080208am1149_
#define _jge_texture_20080208am1149_
#include "jge_type.h"
 
_JGE_BEGIN
class ITexture
{
	uint	mnWidth;
	uint	mnHeight;

public:
					ITexture	();
	virtual			~ITexture	();
			uint	GetWidth	() const ;
			uint	GetHeight	() const ;
			

			void	SetWidth	(uint nWidth);
			void	SetHeight	(uint nHeight);

};

typedef ITexture* ITexturePtr;
_JGE_END
#endif