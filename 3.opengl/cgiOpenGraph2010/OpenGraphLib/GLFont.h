////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2002-2013 Computations & Graphics, Inc. 
// 
// All rights reserved.
//
// Author: Junlin Xu
//
//////////////////////////////////////////////////////////////////////////

#pragma once

#include "OpenGraphDefines.h"

namespace NSOpenGraphLib
{
struct  CGLFont2d
{
    GLuint base;        // Display list number of first character
    int    widths[256]; // Width of each character in pixels
    int    height;			// Height of characters
    HFONT fontid;
} ;

struct CGLFont3d
{
	GLuint base;        // Display list number of first character
	double fScale;
	GLYPHMETRICSFLOAT gmf[256];	// Storage For Information About Our Outline Font Characters
};

CGLFont2d *Font2dCreate(HDC hdc, const TCHAR *typeface, int height, int weight, DWORD italic);
void	Font2dDelete(CGLFont2d *font);
void	Font2dPuts(CGLFont2d *font, const TCHAR *s);
void	Font2dPrintf(CGLFont2d *font, int align, CPointf ptBase, const TCHAR *szText);
void UnicodeFont2dPrintf(CGLFont2d* font, int align, CPointf ptBase, const TCHAR* szText);
}

