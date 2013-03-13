////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2002-2013 Computations & Graphics, Inc. 
// 
// All rights reserved.
//
// Author: Junlin Xu
//
//////////////////////////////////////////////////////////////////////////

#include "stdafx.h" 

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "OpenGraphDefines.h"
#include "GLFont.h"

namespace NSOpenGraphLib
{

const int MAX_STRING = 1024;


    
// 'FontCreate()' - Load Windows font bitmaps into OpenGL display lists.
CGLFont2d* Font2dCreate(HDC hdc, const TCHAR *typeface, int height, int weight, DWORD italic)
{
   CGLFont2d *font;
   HFONT  fontid;
   int    charset;

   font = new CGLFont2d;
   font->base = glGenLists(256);	// Allocate display lists
   if (	_tcsicmp(typeface, gstrSymbol) == 0)	// Select a character set
      charset = SYMBOL_CHARSET;
   else
      charset = ANSI_CHARSET;

   fontid = CreateFont(height, 0, 0, 0, weight, italic, FALSE, FALSE,
      charset, OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS,
      DRAFT_QUALITY, DEFAULT_PITCH, typeface);
   SelectObject(hdc, fontid);

   // Create bitmaps for each character
   wglUseFontBitmaps(hdc, 0, 256, font->base);

   // Get the width and height information for each character
   GetCharWidth(hdc, 0, 255, font->widths);
   font->height = height;
   font->fontid = fontid;

   return (font);
}

void Font2dDelete(CGLFont2d *font)
{
   if (font) {
      glDeleteLists(font->base, 256);
      delete font;
   }
}


void Font2dPuts(CGLFont2d *font, const TCHAR *s)
{
   if (font == 0 || s == NULL) {
      return;
   }

   // Vista
   glPushAttrib(GL_CURRENT_BIT);
   //glPushAttrib(GL_LIST_BIT);
   glListBase(font->base);
#ifdef _UNICODE
   glCallLists((GLsizei)_tcsclen(s), GL_UNSIGNED_SHORT, s);
#else
   glCallLists((GLsizei)_tcsclen(s), GL_UNSIGNED_BYTE, s);
#endif
   glPopAttrib();
}


void Font2dPrintf(CGLFont2d *font, int align, CPointf ptBase, const TCHAR* szText)
{
   TCHAR s[MAX_STRING];     // Output string
   TCHAR *ptr;        // Pointer into string
   int  width;       /* Width of string in pixels */

   if (font == 0 || szText == 0) {
      return;
   }
   SaftStrncpy(s, szText, MAX_STRING - 1 );

   // Figure out the width of the string in pixels...
   bool bUseUnicodePrintf = false;
   for (ptr = s, width = 0; *ptr; ptr ++) {
      if(*ptr > 255)
      {
         bUseUnicodePrintf = true;
         break;
      }
      width += font->widths[*ptr];
   }

   if(bUseUnicodePrintf)
   { // for unicode characters
      UnicodeFont2dPrintf(font, align, ptBase, szText);
      return;
   }

   glRasterPos3d(ptBase.xyz[X], ptBase.xyz[Y], ptBase.xyz[Z]);
   // Adjust the bitmap position as needed to justify the text
   int iY = -font->height / 2;	// vertical middle
   if(align & ALIGN_TOP) {
      iY = -font->height;	
   }
   else if(align & ALIGN_BOTTOM){
      iY = font->height / 4;
   }
   else if(align & ABOVE)	{	// vertical upper
      iY = font->height * 5 / 4;
   }
   else if(align & BELOW) {	// vertical below
      iY = -font->height * 5 / 4;
   }
   else if(align & BELOW2) {	// vertical below more
      iY = -font->height * 9 / 4;
   }
   else if(align & BELOW3) {	// vertical below more...
      iY = -font->height * 13 / 4;
   }
   else if(align & BELOW4) {	// vertical below more......
      iY = -font->height * 17 / 4;
   }


   int iX = -width / 2;
   if(align & ALIGN_LEFT) {
      iX = font->height / 4;	// jxu: move right a little bit
   }
   else if(align & ALIGN_RIGHT) {
      iX = -width;
   }

   glBitmap(0, 0, 0.0f, 0.0f, float(iX), float(iY), NULL);
   Font2dPuts(font, s);	// Draw the string
}


void UnicodeFont2dPrintf(CGLFont2d* font, int align, CPointf ptBase, const TCHAR* szText)
{
    HBITMAP hBitmap;
    BITMAP bm;
    SIZE size;
    UCHAR* pBmpBits;
    HFONT hOldFont;
    HDC hdc = wglGetCurrentDC();

    HFONT hFont = 0;
    if(font == 0) // use default system font
    {
        hFont = (HFONT)::GetStockObject(SYSTEM_FONT);
    }
    else
    {
        hFont = font->fontid;
    }

    hOldFont = (HFONT)SelectObject(hdc, hFont);
    int n = (int)_tcslen(szText);
    ::GetTextExtentPoint32(hdc, szText, (int)_tcslen(szText), &size);
    hBitmap = CreateBitmap(size.cx, size.cy, 1, 1, NULL);

    HDC hMemDC = ::CreateCompatibleDC(hdc);
    if(hMemDC)
    {
        HBITMAP hPrevBmp = (HBITMAP)SelectObject(hMemDC, hBitmap);
        HFONT hPrevFont = (HFONT)SelectObject(hMemDC, hFont);

        SetBkColor(hMemDC, RGB(0, 0, 0));
        SetTextColor(hMemDC, RGB(255, 255, 255));
        SetBkMode(hMemDC, OPAQUE);
        TextOut(hMemDC, 0, 0, szText, (int)_tcslen(szText));

        // copy GDI bitmap to DIB
        //bitmap.GetBitmap(&bm);
        GetObject(hBitmap, sizeof(BITMAP), &bm);

        size.cx = (bm.bmWidth + 31) & (~31);
        size.cy = bm.bmHeight;
        int bufsize = size.cy * (((bm.bmWidth + 31) & (~31)) / 8);
        pBmpBits = new UCHAR[bufsize];
        memset(pBmpBits, 0, sizeof(UCHAR)*bufsize);

        struct {
            BITMAPINFOHEADER bih;
            RGBQUAD col[2];
        }bic;
        BITMAPINFO *binf = (BITMAPINFO *)&bic;

        binf->bmiHeader.biSize = sizeof(binf->bmiHeader);
        binf->bmiHeader.biWidth = bm.bmWidth;
        binf->bmiHeader.biHeight = bm.bmHeight;
        binf->bmiHeader.biPlanes = 1;
        binf->bmiHeader.biBitCount = 1;
        binf->bmiHeader.biCompression = BI_RGB;
        binf->bmiHeader.biSizeImage = bufsize;
        binf->bmiHeader.biXPelsPerMeter = 1;
        binf->bmiHeader.biYPelsPerMeter = 1;
        binf->bmiHeader.biClrUsed = 0;
        binf->bmiHeader.biClrImportant = 0;

        ::GetDIBits(hdc, hBitmap, 0, bm.bmHeight, pBmpBits, binf, DIB_RGB_COLORS);

        SelectObject(hMemDC, hPrevBmp);
    }
    ::DeleteDC(hMemDC);

    // delete font from DC
    SelectObject(hdc, hOldFont);

    // display text
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);


    int width = size.cx;
    int height = size.cy;
    // Adjust the bitmap position as needed to justify the text
    int iY = -height / 2;	// vertical middle
    if(align & ALIGN_TOP) {
        iY = -height;	
    }
    else if(align & ALIGN_BOTTOM){
        iY = height / 4;
    }
    else if(align & ABOVE)	{	// vertical upper
        iY = height * 5 / 4;
    }
    else if(align & BELOW) {	// vertical below
        iY = -height * 5 / 4;
    }
    else if(align & BELOW2) {	// vertical below more
        iY = -height * 9 / 4;
    }
    else if(align & BELOW3) {	// vertical below more...
        iY = -height * 13 / 4;
    }
    else if(align & BELOW4) {	// vertical below more......
        iY = -height * 17 / 4;
    }


    int iX = -width / 2;
    if(align & ALIGN_LEFT) {
        iX = height / 4;	// jxu: move right a little bit
    }
    else if(align & ALIGN_RIGHT) {
        iX = -width;
    }

    glRasterPos3d(ptBase.xyz[X], ptBase.xyz[Y], ptBase.xyz[Z]);
    // void glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap);
    // A bitmap is a binary image. When drawn, the bitmap is positioned relative to the current raster position, 
    // and frame buffer pixels corresponding to 1s in the bitmap are written using the current raster color or index. 
    // Frame-buffer pixels corresponding to zeros in the bitmap are not modified.
    glBitmap(0, 0, (float)0, (float)0, (float)iX, (float)iY, NULL);
    glBitmap(size.cx, size.cy, 0.0, 0, 0, 0, pBmpBits);

    DeleteObject(hBitmap);

    delete []pBmpBits;
}

}