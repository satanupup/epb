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

#include <windows.h>
#include "OpenGraphLib.h"

namespace NSOpenGraphLib
{

class OPENGRAPHLIB_API CRubberBandTracker
{
public:
    CRubberBandTracker(void);
    ~CRubberBandTracker(void);
    void SetContext(HDC hdc, HGLRC hglrc);
    RECT GetTrackRect()const; // un-normalized
    BOOL TrackRubberBand(HWND hWnd, POINT point, BOOL bMakeCurrent);

private:
    void DrawTrackRect(int x1, int y1, int x2, int y2);
    void DrawTrackRect(const RECT& rect);
    int GetRectWidth(const RECT& rect)const;
    int GetRectHeight(const RECT& rect)const;

    BOOL m_bErased;
    HWND m_hWnd;
    RECT m_rect;

    HDC m_hdc;
    HGLRC m_hglrc;
};

}