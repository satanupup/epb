////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2002-2013 Computations & Graphics, Inc. 
// 
// All rights reserved.
//
// Author: Junlin Xu
//
//////////////////////////////////////////////////////////////////////////

// jxu notes 12-07-2012
// This class is modified from Real3D to adapt to non-MFC project

#include "stdafx.h"
#include <gl/gl.h>
#include <cmath>
#include <cassert>
#include "RubberBandTracker.h"

using namespace std;
namespace NSOpenGraphLib
{

CRubberBandTracker::CRubberBandTracker(void)
{
    m_bErased = FALSE;
    m_hdc = 0;
    m_hglrc = 0;
}

CRubberBandTracker::~CRubberBandTracker(void)
{
}

void CRubberBandTracker::SetContext(HDC hdc, HGLRC hglrc)
{
    m_hdc = hdc;
    m_hglrc = hglrc;
}

RECT CRubberBandTracker::GetTrackRect()const
{   // m_rect is not normalized
    // meaning left coordinate may be greater than right coordinate
    return m_rect;
}


void CRubberBandTracker::DrawTrackRect(int x1, int y1, int x2, int y2)
{    
    wglMakeCurrent(m_hdc, m_hglrc);
    // drawing different rubber-banding rectangle depending on the mouse movement x-direction
    if(x1 < x2)
    {
        glColor4f(1.0f, 0.2f, 0.0f, 0.0f);
    }
    else
    {
        glColor4f(0.0f, 0.2f, 1.0f, 0.0f);
    }

    // OpenGL window coordinates are different from GDI's
    RECT rectClient;
    ::GetClientRect(m_hWnd, &rectClient);
    glRecti(x1, GetRectHeight(rectClient) - y1, x2, GetRectHeight(rectClient) - y2);

    glFlush();  // must flush here
} 

void CRubberBandTracker::DrawTrackRect(const RECT& rect)
{
    DrawTrackRect(rect.left, rect.top, rect.right, rect.bottom);
}

BOOL CRubberBandTracker::TrackRubberBand(HWND hWnd, POINT point, BOOL bMakeCurrent)
{
    m_hWnd = hWnd;
    RECT rectClient;
    ::GetClientRect(m_hWnd, &rectClient);
    
    // set mouse capture because we are going to work on this window
    ::SetCapture(m_hWnd);
    assert(m_hWnd == ::GetCapture());

    // save the old contexts
    HDC hDC = wglGetCurrentDC();
    HGLRC hglRC = wglGetCurrentContext();
    wglMakeCurrent(m_hdc, m_hglrc);

    // set drawing mode to front-buffer, etc
    glDrawBuffer(GL_FRONT);

    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_LOGIC_OP);
    glLogicOp(GL_XOR);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // save the current projection matrix and set up a new convenient projection matrix
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, GetRectWidth(rectClient), 0, GetRectHeight(rectClient), -1, 1);

    glViewport(-1, -1, GetRectWidth(rectClient) + 2, GetRectHeight(rectClient) + 2);

    // save the current model view matrix
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    BOOL bMoved = FALSE;
    POINT ptOld = point;
    RECT rectOld;
    rectOld.left = rectOld.right = ptOld.x;
    rectOld.top = rectOld.bottom = ptOld.y;
    POINT ptNew;

    BOOL bStop = FALSE;
    for (;;)
    {  // loop forever until LButtonUp, RButtonDown or ESC keyDown
        MSG msg;
        ::GetMessage(&msg, NULL, 0, 0);

        if (::GetCapture() != m_hWnd)
        {
            break;
        }

        if(msg.message == WM_LBUTTONUP || msg.message == WM_MOUSEMOVE)
        {
            ptNew.x = (int)(short)LOWORD(msg.lParam);
            ptNew.y = (int)(short)HIWORD(msg.lParam);
            m_rect.left = ptOld.x;
            m_rect.right = ptNew.x;
            m_rect.top = ptOld.y;
            m_rect.bottom = ptNew.y;

            if (bMoved)
            {
                m_bErased = TRUE;
                DrawTrackRect(rectOld);
            }
            rectOld = m_rect;
            if (msg.message != WM_LBUTTONUP)
            {
                bMoved = TRUE;
            }

            if (msg.message == WM_MOUSEMOVE)
            {
                m_bErased = FALSE;
                DrawTrackRect(m_rect);
            }
            else
            {
                bStop = TRUE;
                assert(msg.message == WM_LBUTTONUP);
            }
        }
        else if(msg.message == WM_KEYDOWN)
        {
            if (msg.wParam == VK_ESCAPE)
            {
                bStop = TRUE;
            }
        }
        else if(msg.message == WM_RBUTTONDOWN)
        { 
            bStop = TRUE;
        }
        else
        {
            DispatchMessage(&msg);
        }

        if(bStop)
        {
            break;
        }

    }  // for (;;)

    // release mouse capture
    ReleaseCapture();

    if(!m_bErased)
    {  // do a final erase if needed
        DrawTrackRect(m_rect);
    }

    // restore the old modelview and projection matrices
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();

    // restore all the drawing modes
    glPopAttrib();
    glDrawBuffer(GL_BACK);

    wglMakeCurrent(hDC, hglRC);

    // note: m_rect's Width and Height may be negative
    return (abs(GetRectWidth(m_rect)) >= 1 && abs(GetRectHeight(m_rect)) >= 1);
}

int CRubberBandTracker::GetRectWidth(const RECT& rect)const
{
    return rect.right - rect.left;
}

int CRubberBandTracker::GetRectHeight(const RECT& rect)const
{
    return rect.bottom - rect.top;
}

}