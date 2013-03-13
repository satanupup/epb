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
#include <atlstr.h>
#include <vector>
using namespace std;
#include "OpenGraphLib.h"
#include "OpenGraphDefines.h"


namespace NSOpenGraphLib
{

struct CDrawable
{
    CDrawable();
    int nId;
    CString strUid;
    bool bScreenCoordinate;
    CString strTag;
    CString strUserData;
    COLORREF color;
    COLORREF colorSelected;
    int nStatus;    // selected, unselected etc
};

struct CText:public CDrawable
{
    CText();
    int nFontId;
    CPointf pt;
    CString strText;
    int nAlignment;
};

struct CNode:public CDrawable
{
    CNode();
    CPointf pt;
    int nSize;  // node size in pixels
};

struct CLine:public CDrawable
{
    CLine();
    CPointf pt[2];
    int nThickness;
    int nType; // stippled
};

struct CTriangle:public CDrawable
{
    CTriangle();
    CPointf pt[3];
    float fAlpha;
};

struct CQuad:public CDrawable
{
    CQuad();
    CPointf pt[4];
    float fAlpha;
};



struct CNodeBatch
{
    COLORREF color;
    COLORREF colorSelected;
    int nSize;  // node size in pixels
    vector<CNode> vDrawables;
};

struct CLineBatch
{
    COLORREF color;
    COLORREF colorSelected;
    int nThickness;
    vector<CLine> vDrawables;
};

struct CTriangleBatch
{
    COLORREF color;
    COLORREF colorSelected;
    float fAlpha;
    vector<CTriangle> vDrawables;

};

struct CQuadBatch
{
    COLORREF color;
    COLORREF colorSelected;
    float fAlpha;
    vector<CQuad> vDrawables;

};


}

