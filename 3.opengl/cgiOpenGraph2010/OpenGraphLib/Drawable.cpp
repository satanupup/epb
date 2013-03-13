////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2002-2013 Computations & Graphics, Inc. 
// 
// All rights reserved.
//
// Author: Junlin Xu
//
//////////////////////////////////////////////////////////////////////////

#include "StdAfx.h"

#include "Drawable.h"
//#include "OpenGraphDefines.h"

namespace NSOpenGraphLib
{
    CDrawable::CDrawable()
    {
        color = RGB(0, 0, 0);
        nStatus = 0;
    }

    CNode::CNode()
    {
        nSize = 1;
    }

    CLine::CLine()
    {
        nThickness = 1;
    }

    CTriangle::CTriangle()
    {
        fAlpha = 1.0f;
    }

    CQuad::CQuad()
    {
        fAlpha = 1.0f;
    }

    CText::CText()
    {
        nAlignment = ALIGN_LEFT;
        nFontId = 0;
    }

}