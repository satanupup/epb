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
#include <algorithm>
#include "DrawHelper.h"
#include "MathHelper.h"
#include "Drawable.h"


using namespace std;
namespace NSOpenGraphLib
{



void CDrawHelper::DrawLine(CPointf pt1, CPointf pt2)
{
    CGLBeginHelper helper(GL_LINES);
    glVertex3d(pt1.xyz[X], pt1.xyz[Y], pt1.xyz[Z]);
    glVertex3d(pt2.xyz[X], pt2.xyz[Y], pt2.xyz[Z]);
}

// pt1, pt2 ... should be in counter clockwise order
void CDrawHelper::DrawTriangle(CPointf pt1, CPointf pt2, CPointf pt3, CPointf* pNormal)
{
    CPointf vNormal;
    if(pNormal)
    {
        vNormal = *pNormal;
    }
    else
    {
        CMathHelper::normal(vNormal, pt1, pt2, pt3);
    }
    glNormal3d(vNormal.xyz[X], vNormal.xyz[Y], vNormal.xyz[Z]);
    CGLBeginHelper helper(GL_TRIANGLES);
    glVertex3d(pt1.xyz[X], pt1.xyz[Y], pt1.xyz[Z]);
    glVertex3d(pt2.xyz[X], pt2.xyz[Y], pt2.xyz[Z]);
    glVertex3d(pt3.xyz[X], pt3.xyz[Y], pt3.xyz[Z]);
}

// pt1, pt2 ... should be in counter clockwise order
void CDrawHelper::DrawQuad(CPointf pt1, CPointf pt2, CPointf pt3, CPointf pt4, CPointf* pNormal)
{
    CPointf vNormal;
    if(pNormal)
    {
        vNormal = *pNormal;
    }
    else
    {
        CMathHelper::normal(vNormal, pt1, pt2, pt3);
    }
    glNormal3d(vNormal.xyz[X], vNormal.xyz[Y], vNormal.xyz[Z]);
    CGLBeginHelper helper(GL_QUADS);
    glVertex3d(pt1.xyz[X], pt1.xyz[Y], pt1.xyz[Z]);
    glVertex3d(pt2.xyz[X], pt2.xyz[Y], pt2.xyz[Z]);
    glVertex3d(pt3.xyz[X], pt3.xyz[Y], pt3.xyz[Z]);
    glVertex3d(pt4.xyz[X], pt4.xyz[Y], pt4.xyz[Z]);
}

void CDrawHelper::BoxPts(CPointf pt[8], CPointf ptCenter, double fDeltaX, double fDeltaY, double fDeltaZ)
{
    pt[0].xyz[X] = ptCenter.xyz[X] + fDeltaX / 2.;
    pt[0].xyz[Y] = ptCenter.xyz[Y] + fDeltaY / 2.;
    pt[0].xyz[Z] = ptCenter.xyz[Z] + fDeltaZ / 2.;
    pt[1] = pt[0];
    pt[1].xyz[X] = ptCenter.xyz[X] - fDeltaX / 2.;
    pt[2] = pt[1];
    pt[2].xyz[Y] = ptCenter.xyz[Y] - fDeltaY / 2.;
    pt[3] = pt[2];
    pt[3].xyz[X] = pt[0].xyz[X];

    for(int i = 0; i < 4; i++)
    {
        pt[i + 4] = pt[i];
        pt[i + 4].xyz[Z] = ptCenter.xyz[Z] - fDeltaZ / 2.;
    }

}

void CDrawHelper::DrawBox(CPointf pt[8], GLfloat color[4], bool bHollow)
{
    //glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color[0]);
    //glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, color[3]);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
    DrawQuad(pt[1], pt[0], pt[4], pt[5]);
    DrawQuad(pt[3], pt[2], pt[6], pt[7]);

    //glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color[1]);
    //glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, color[4]);
    DrawQuad(pt[2], pt[1], pt[5], pt[6]);
    DrawQuad(pt[0], pt[3], pt[7], pt[4]);

    if(!bHollow){
        //glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color[2]);
        DrawQuad(pt[0], pt[1], pt[2], pt[3]);
        DrawQuad(pt[7], pt[6], pt[5], pt[4]);
    }

}

void CDrawHelper::DrawAxisCube(double fSize, CGLFont2d* pFont2d)
{
    const GLdouble color_x[3] = {1.0, .0, .0};
    const GLdouble color_y[3] = {0., 1.0, .0};
    const GLdouble color_z[3] = {0., .0, 1.0};

    CPointf ptBase[3];
    ptBase[X].xyz[X] = 4 * fSize;
    ptBase[X].xyz[Y] = -fSize;
    ptBase[X].xyz[Z] = -fSize;

    ptBase[Y].xyz[X] = -fSize;
    ptBase[Y].xyz[Y] = 4 * fSize;
    ptBase[Y].xyz[Z] = -fSize;

    ptBase[Z].xyz[X] = -fSize;
    ptBase[Z].xyz[Y] = -fSize;
    ptBase[Z].xyz[Z] = 4 * fSize;

    //jxu: disable lighting so we can display colored lines
    glDisable(GL_LIGHTING);
    glColor3dv(color_x);
    DrawLine(CPointf(-fSize, -fSize, -fSize), CPointf(3 * fSize, -fSize, -fSize));
    Font2dPrintf(pFont2d, ALIGN_CENTER, ptBase[X], gstrX);

    glColor3dv(color_y);
    DrawLine(CPointf(-fSize, -fSize, -fSize), CPointf(-fSize, 3 * fSize, -fSize));
    Font2dPrintf(pFont2d, ALIGN_CENTER, ptBase[Y], gstrY);

    glColor3dv(color_z);
    DrawLine(CPointf(-fSize, -fSize, -fSize), CPointf(-fSize, -fSize, 3 * fSize));
    Font2dPrintf(pFont2d, ALIGN_CENTER, ptBase[Z], gstrZ);

    //jxu: enalbe lighting so we can display colored boxes
    glEnable(GL_LIGHTING);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    const GLfloat RedSurface[]   = { 1.0f, 0.0f, 0.0f, 1.0f};
    const GLfloat GreenSurface[] = { 0.0f, 1.0f, 0.0f, 1.0f};
    const GLfloat BlueSurface[]  = { 0.0f, 0.0f, 1.0f, 1.0f};

    CPointf pt1 = CPointf(  fSize,  fSize,  fSize);
    CPointf pt2 = CPointf(  fSize, -fSize,  fSize);
    CPointf pt3 = CPointf(  fSize, -fSize, -fSize);
    CPointf pt4 = CPointf(  fSize,  fSize, -fSize);
    CPointf pt5 = CPointf( -fSize, -fSize,  fSize);
    CPointf pt6 = CPointf( -fSize,  fSize,  fSize);
    CPointf pt7 = CPointf( -fSize,  fSize, -fSize);
    CPointf pt8 = CPointf( -fSize, -fSize, -fSize);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, RedSurface);
    DrawQuad(pt1, pt2, pt3, pt4, &(CPointf(  1.0,  0.0,  0.0)));
    DrawQuad(pt5, pt6, pt7,  pt8, &(CPointf( -1.0,  0.0,  0.0)));

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, GreenSurface);
    DrawQuad(pt1,  pt4, pt7,  pt6, &(CPointf(  0.0,  1.0,  0.0)));
    DrawQuad(pt2, pt5, pt8, pt3, &(CPointf(  0.0, -1.0,  0.0)));

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, BlueSurface);
    DrawQuad(pt1, pt6, pt5, pt2, &(CPointf(  0.0,  0.0,  1.0)));
    DrawQuad(pt7, pt4, pt3, pt8, &(CPointf(  0.0,  0.0, -1.0)));

}

void CDrawHelper::DrawNodes(const vector<CNodeBatch>& vNodeBatches)
{
    float fPointSizeOrg;
    glGetFloatv( GL_POINT_SIZE, &fPointSizeOrg);

    for(vector<CNodeBatch>::const_iterator iterBatch = vNodeBatches.begin(); iterBatch != vNodeBatches.end(); iterBatch++)
    {
        const CNodeBatch& nodeBatch = *iterBatch;
        GLdouble color_gl[2][3] = {0};
        ConvertColors(color_gl, nodeBatch.color, nodeBatch.colorSelected);

        glPointSize((float)nodeBatch.nSize);	// pixels to represent a nd
        for(int k = 0; k < 2; k++)	// k == 0 for not selected, k == 1 for selected
        {
            glColor3dv(color_gl[k]);
            CGLBeginHelper helper(GL_POINTS);
            for(vector<CNode>::const_iterator iter = nodeBatch.vDrawables.begin(); iter != nodeBatch.vDrawables.end(); iter++) 
            {
                const CNode& nd = *iter;
                if( k == 0 && !(nd.nStatus & STATUS_SELECTED) || k == 1 && (nd.nStatus & STATUS_SELECTED) )
                {
                    glVertex3d(nd.pt.xyz[X], nd.pt.xyz[Y], nd.pt.xyz[Z]);
                }
            }
        }	// for(int k = 0; k < 2; k++)	// k == 0 for not selected, k == 1 for selected
    }

    glPointSize(fPointSizeOrg);

}	

void CDrawHelper::DrawLines(const vector<CLineBatch>& vLineBatches)
{
    float fLineWidthOrg;
    glGetFloatv( GL_LINE_WIDTH, &fLineWidthOrg);

    for(vector<CLineBatch>::const_iterator iterBatch = vLineBatches.begin(); iterBatch != vLineBatches.end(); iterBatch++)
    {
        const CLineBatch& lineBatch = *iterBatch;
        GLdouble color_gl[2][3] = {0};
        ConvertColors(color_gl, lineBatch.color, lineBatch.colorSelected);

        glLineWidth((float)lineBatch.nThickness);	// pixels to represent a nd
        for(int k = 0; k < 2; k++)	// k == 0 for not selected, k == 1 for selected
        {
            glColor3dv(color_gl[k]);
            CGLBeginHelper helper(GL_LINES);
            for(vector<CLine>::const_iterator iter = lineBatch.vDrawables.begin(); iter != lineBatch.vDrawables.end(); iter++) 
            {
                const CLine& line = *iter;
                if( k == 0 && !(line.nStatus & STATUS_SELECTED) || k == 1 && (line.nStatus & STATUS_SELECTED) )
                {
                    glVertex3d(line.pt[0].xyz[X], line.pt[0].xyz[Y], line.pt[0].xyz[Z]);
                    glVertex3d(line.pt[1].xyz[X], line.pt[1].xyz[Y], line.pt[1].xyz[Z]);
                }
            }
        }	// for(int k = 0; k < 2; k++)	// k == 0 for not selected, k == 1 for selected
    }

    glLineWidth(fLineWidthOrg);
}	

void CDrawHelper::DrawTriangles(const vector<CTriangleBatch>& vTriangleBatches)
{
    for(vector<CTriangleBatch>::const_iterator iterBatch = vTriangleBatches.begin(); iterBatch != vTriangleBatches.end(); iterBatch++)
    {
        const CTriangleBatch& triangleBatch = *iterBatch;
        GLfloat color_gl[2][4] = {0};
        ConvertColors(color_gl, triangleBatch.color, triangleBatch.colorSelected, triangleBatch.fAlpha);

        for(int k = 0; k < 2; k++)	// k == 0 for not selected, k == 1 for selected
        {
            glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color_gl[k]);
            glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, color_gl[k]);
            CGLBeginHelper helper(GL_TRIANGLES);
            for(vector<CTriangle>::const_iterator iter = triangleBatch.vDrawables.begin(); iter != triangleBatch.vDrawables.end(); iter++) 
            {
                const CTriangle& triangle = *iter;
                if( k == 0 && !(triangle.nStatus & STATUS_SELECTED) || k == 1 && (triangle.nStatus & STATUS_SELECTED) )
                {
                    CPointf vNormal;
                    CMathHelper::normal(vNormal, triangle.pt[0], triangle.pt[1], triangle.pt[2]);
                    glNormal3d(vNormal.xyz[X], vNormal.xyz[Y], vNormal.xyz[Z]);
                    glVertex3d(triangle.pt[0].xyz[X], triangle.pt[0].xyz[Y], triangle.pt[0].xyz[Z]);
                    glVertex3d(triangle.pt[1].xyz[X], triangle.pt[1].xyz[Y], triangle.pt[1].xyz[Z]);
                    glVertex3d(triangle.pt[2].xyz[X], triangle.pt[2].xyz[Y], triangle.pt[2].xyz[Z]);
                }
            }
        }	// for(int k = 0; k < 2; k++)	// k == 0 for not selected, k == 1 for selected
    }
}

void CDrawHelper::DrawQuads(const vector<CQuadBatch>& vQuadBatches)
{
    for(vector<CQuadBatch>::const_iterator iterBatch = vQuadBatches.begin(); iterBatch != vQuadBatches.end(); iterBatch++)
    {
        const CQuadBatch& quadBatch = *iterBatch;
        GLfloat color_gl[2][4] = {0};
        ConvertColors(color_gl, quadBatch.color, quadBatch.colorSelected, quadBatch.fAlpha);

        for(int k = 0; k < 2; k++)	// k == 0 for not selected, k == 1 for selected
        {
            glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color_gl[k]);
            glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, color_gl[k]);
            CGLBeginHelper helper(GL_QUADS);
            for(vector<CQuad>::const_iterator iter = quadBatch.vDrawables.begin(); iter != quadBatch.vDrawables.end(); iter++) 
            {
                const CQuad& quad = *iter;
                if( k == 0 && !(quad.nStatus & STATUS_SELECTED) || k == 1 && (quad.nStatus & STATUS_SELECTED) )
                {
                    CPointf vNormal;
                    CMathHelper::normal(vNormal, quad.pt[0], quad.pt[1], quad.pt[2]);
                    glNormal3d(vNormal.xyz[X], vNormal.xyz[Y], vNormal.xyz[Z]);

                    glVertex3d(quad.pt[0].xyz[X], quad.pt[0].xyz[Y], quad.pt[0].xyz[Z]);
                    glVertex3d(quad.pt[1].xyz[X], quad.pt[1].xyz[Y], quad.pt[1].xyz[Z]);
                    glVertex3d(quad.pt[2].xyz[X], quad.pt[2].xyz[Y], quad.pt[2].xyz[Z]);
                    glVertex3d(quad.pt[3].xyz[X], quad.pt[3].xyz[Y], quad.pt[3].xyz[Z]);
                }
            }
        }	// for(int k = 0; k < 2; k++)	// k == 0 for not selected, k == 1 for selected
    }

}	

void CDrawHelper::ConvertColors( GLdouble color_gl[3], COLORREF color)
{
    color_gl[0] = GetRValue(color) / 255.0;
    color_gl[1] = GetGValue(color) / 255.0;
    color_gl[2] = GetBValue(color) / 255.0;
}

void CDrawHelper::ConvertColors( GLdouble color_gl[2][3], COLORREF color, COLORREF colorSelected )
{
    color_gl[0][0] = GetRValue(color) / 255.0;
    color_gl[0][1] = GetGValue(color) / 255.0;
    color_gl[0][2] = GetBValue(color) / 255.0;
    color_gl[1][0] = GetRValue(colorSelected) / 255.0;
    color_gl[1][1] = GetGValue(colorSelected) / 255.0;
    color_gl[1][2] = GetBValue(colorSelected) / 255.0;
}

void CDrawHelper::ConvertColors( GLfloat color_gl[2][4], COLORREF color, COLORREF colorSelected, float alpha )
{
    color_gl[0][0] = GetRValue(color) / 255.0f;
    color_gl[0][1] = GetGValue(color) / 255.0f;
    color_gl[0][2] = GetBValue(color) / 255.0f;
    color_gl[0][3] = alpha;
    color_gl[1][0] = GetRValue(colorSelected) / 255.0f;
    color_gl[1][1] = GetGValue(colorSelected) / 255.0f;
    color_gl[1][2] = GetBValue(colorSelected) / 255.0f;
    color_gl[1][3] = alpha;
}

}