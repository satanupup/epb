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
#include <atlimage.h>
using namespace std;

#include "GLFont.h"
#include "Drawable.h"


namespace NSOpenGraphLib
{

// jxu: important, texture pixel color Cv = Lt * Cf, see glTexEnvi()
const double gfTexColorRatio = 0.9;

class CGLBeginHelper
{   // Resource Acquisition Is Initialization
public:
    CGLBeginHelper(GLenum mode) {
        glBegin(mode);
    }
    ~CGLBeginHelper() {
        glEnd();
    }
};


class CGLNewListHelper
{
public:
    CGLNewListHelper(int LIST) {
        glNewList(LIST, GL_COMPILE);
    }
    ~CGLNewListHelper() {
        glEndList();
    }
};

class CDrawHelper
{
public:
    static void BoxPts(CPointf pt[8], CPointf ptCenter, double fDeltaX, double fDeltaY, double fDeltaZ);

    static void DrawLine(CPointf pt1, CPointf pt2);
    static void DrawTriangle(CPointf pt1, CPointf pt2, CPointf pt3, CPointf* pNormal = 0);
    static void DrawQuad(CPointf pt1, CPointf pt2, CPointf pt3, CPointf pt4, CPointf* pNormal = 0);
    static void DrawBox(CPointf pt[8], GLfloat color[4], bool bHollow);

    static void DrawAxisCube(double fSize, CGLFont2d* pFont2d);
    static void DrawNodes(const vector<CNodeBatch>& vNodeBatches);
    static void DrawLines(const vector<CLineBatch>& vLineBatches);
    static void DrawTriangles(const vector<CTriangleBatch>& vTriangleBatches);
    static void DrawQuads(const vector<CQuadBatch>& vQuadBatches);

    static void ConvertColors( GLdouble color_gl[3], COLORREF color);
    static void ConvertColors( GLdouble color_gl[2][3], COLORREF color, COLORREF colorSelected );
    static void ConvertColors( GLfloat color_gl[2][4], COLORREF color, COLORREF colorSelected, float alpha );
};

}