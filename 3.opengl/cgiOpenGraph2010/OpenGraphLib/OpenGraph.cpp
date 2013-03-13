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

#include "gl/gl.h"
#include "gl/glu.h"
#include "gl/glaux.h"
#include "OpenGraph.h"
#include "Drawable.h"

#include <tchar.h>
#include <cmath>
#include <climits>
#include <algorithm>
#include <iterator>
#include <limits>
#include "DrawHelper.h"
#include "resource.h"
#include <atlimage.h>
#include "RubberBandTracker.h"
#include "DrawManager.h"
#include "MathHelper.h"

using namespace std;

extern HMODULE ghModule;
#define USE_DISPLAY_LIST 1;


namespace NSOpenGraphLib
{
const double gfZoomLimit = FLT_MAX;
const double gInitialZoom = 1.8;
const int gCursorSize = 10 / 2;


COpenGraph::COpenGraph(void)
{
    m_nCx = 0;
    m_nCy = 0;

    m_fTx = 0;
    m_fTy = 0;
    m_fRx = 0;
    m_fRy = 0;
    m_fRz = 0;
    m_fZoom = 1.0;
    m_fMax = 0.0;
    m_nMode = modeNONE;
    m_bShowAxes = true;

    m_hSelectCursor = ::LoadCursor(ghModule, MAKEINTRESOURCE(IDC_CURSOR_SELECT));
    m_hZoomCursor = ::LoadCursor(ghModule, MAKEINTRESOURCE(IDC_CURSOR_ZOOM));
    m_hPanCursor = ::LoadCursor(ghModule, MAKEINTRESOURCE(IDC_CURSOR_PAN));
    m_hRotateCursor = ::LoadCursor(ghModule, MAKEINTRESOURCE(IDC_CURSOR_ROTATE));
    m_hQueryCursor = ::LoadCursor(ghModule, MAKEINTRESOURCE(IDC_CURSOR_QUERY));

    m_pRubberBandTracker = new CRubberBandTracker();

    m_pDrawManager = new CDrawManager();
    m_bDirty = false;
}


COpenGraph::~COpenGraph(void)
{
    delete m_pRubberBandTracker;
    delete m_pDrawManager;
    ::DeleteObject(m_hSelectCursor);
    ::DeleteObject(m_hZoomCursor);
    ::DeleteObject(m_hPanCursor);
    ::DeleteObject(m_hRotateCursor);
    ::DeleteObject(m_hQueryCursor);

    DeleteObject(m_hSelectCursor);

    HDC hDC = GetDC(m_hGLWnd);
    wglMakeCurrent(hDC, m_hRC);

    DestroyRC(m_hRC);

}

void COpenGraph::ShowAxes(bool bShow)
{
    m_bShowAxes = bShow;
}

CIdentity COpenGraph::AddText(int id, int nFontId, CPointf pt, LPCTSTR text, COLORREF color,COLORREF colorSelected, int nAlignment, int nStatus)
{
    m_bDirty = true;
    return m_pDrawManager->AddText(id, nFontId, pt, text, color, colorSelected,nAlignment, nStatus);
}

int COpenGraph::AddFont(const TCHAR *typeface, int height, int weight, DWORD italic)
{
    // jxu: when adding font, we must have the opengl context ready
    HDC hDC = GetDC(m_hGLWnd);
    wglMakeCurrent(hDC, m_hRC);
    CGLFont2d* pFont2d = Font2dCreate(wglGetCurrentDC(), typeface, height, weight, italic);
    return m_pDrawManager->AddFont(pFont2d);
}

bool COpenGraph::Initialize(HWND hWnd)
{
    m_hGLWnd = hWnd;
    HDC hDC = GetDC(hWnd);

    if ( InitializePixelFormat(hDC) == false || CreateRC(m_hRC, hDC) == false )
    {
        return false;
    }
    AddFont(gstrArial, 16, 0, 0);   // built-in font
    

#ifdef USE_DISPLAY_LIST
    int nBase = glGenLists(END_LIST);	// generate display lists
    for(int i = nBase; i < nBase + END_LIST; i++)
    {
        m_nDisplayList[i-nBase] = i;
    }
#endif

    return true;
}

bool COpenGraph::InitializePixelFormat(HDC hDC)
{
    
    // define default desired video mode (pixel format)
    PIXELFORMATDESCRIPTOR pixelDesc;

    pixelDesc.nSize				= sizeof(PIXELFORMATDESCRIPTOR);
    pixelDesc.nVersion			= 1;
    pixelDesc.dwFlags	=		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER | PFD_STEREO_DONTCARE;  
    pixelDesc.iPixelType		= PFD_TYPE_RGBA;
    pixelDesc.cColorBits		= 32;	// with transparency support
    //pixelDesc.cColorBits		= 24;	// without transparency support
    pixelDesc.cRedBits			= 8;
    pixelDesc.cRedShift			= 16;
    pixelDesc.cGreenBits		= 8;
    pixelDesc.cGreenShift		= 8;
    pixelDesc.cBlueBits			= 8;
    pixelDesc.cBlueShift		= 0;
    pixelDesc.cAlphaBits		= 0;
    pixelDesc.cAlphaShift		= 0;
    pixelDesc.cAccumBits		= 64;	
    pixelDesc.cAccumRedBits		= 16;
    pixelDesc.cAccumGreenBits	= 16;
    pixelDesc.cAccumBlueBits	= 16;
    pixelDesc.cAccumAlphaBits	= 0;
    pixelDesc.cDepthBits		= 32;
    pixelDesc.cStencilBits		= 8;
    pixelDesc.cAuxBuffers		= 0;
    pixelDesc.iLayerType		= PFD_MAIN_PLANE;
    pixelDesc.bReserved			= 0;
    pixelDesc.dwLayerMask		= 0;
    pixelDesc.dwVisibleMask		= 0;
    pixelDesc.dwDamageMask		= 0;

    int nPixelIndex = ChoosePixelFormat( hDC, &pixelDesc);

    //nPixelIndex = 8;	// jxu: force the program to use ICD implementation
    //nPixelIndex = 22;	// jxu: force the program to use generic implementation
    ::DescribePixelFormat(hDC, nPixelIndex, pixelDesc.nSize, &pixelDesc);

    if (SetPixelFormat( hDC, nPixelIndex, &pixelDesc)==FALSE)
    {
        return false;
    }

    return true;
}

bool COpenGraph::CreateRC(HGLRC& hRC, HDC hDC)
{
    if ( (hRC = wglCreateContext(hDC)) == NULL ||
        wglMakeCurrent(hDC, hRC) == FALSE)
    {
        return false;
    }

    return true;
}

void COpenGraph::DestroyRC(HGLRC& hRC) 
{
    wglMakeCurrent(NULL, NULL) ; 
    if (hRC) 
    {
        wglDeleteContext(hRC) ;
        hRC = NULL ;
    }		

}

void COpenGraph::SetWindowSize(int cx, int cy) 
{
    if(m_nCx != cx || m_nCy != cy) {
        m_nCx = cx;
        m_nCy = cy;
        Render();
    }
}

void COpenGraph::ForceRender()
{
    m_bDirty = false;
    Render();
}

void COpenGraph::Render()
{
    try
    {
        OutputDebugString(_T("... COpenGraph::Render() .... "));

#ifdef USE_DISPLAY_LIST
        if(m_bDirty)
        {
            CreateLists();
        }
#endif

        HDC hDC = GetDC(m_hGLWnd);
        StartModel(hDC);
        CheckGLError();		// error checking
      

        GLfloat color_gl[3] = {0, 0, 0};
        glClearColor(color_gl[0], color_gl[1], color_gl[2], 0);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        if(m_bShowAxes)
        {
            DrawAxisCube();
        }

        SetupMatrix();  // 3D coordinates
        glDisable(GL_LIGHTING);
        DrawNodes();
        DrawLines();

        glEnable(GL_LIGHTING);
        DrawTriangles();
        DrawQuads();

        glDisable(GL_DEPTH_TEST);	
        glDisable(GL_LIGHTING);
        DrawTexts();

        SetupWindowMatrix();
        DebugDraw();
        glEnable(GL_DEPTH_TEST);	

        CheckGLError();		// error checking
        SwapBuffers(hDC);
        wglMakeCurrent(NULL, NULL) ;
        ::ReleaseDC (m_hGLWnd, hDC) ; 

    }	// end of: try
    catch(...){
        OutputDebugString(_T("Exception in COpenGraph::render"));
    }

}


void COpenGraph::StartModel(HDC hDC)
{
    wglMakeCurrent(hDC, m_hRC);

    // Anti-alias
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glLineWidth(1.);

    glDepthFunc(GL_LEQUAL);
    glEnable(GL_DEPTH_TEST);	// hidden line removal

    // light setup
    GLfloat lmodel_ambient[] = {1.0, 1.0, 1.0, 1.0};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);	// global ambient
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);	// two side model

    glCullFace( GL_BACK );
}	


void COpenGraph::SetupMatrix()
{
    // projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    double fSize = 2.0;
    if(m_fMax > 0) {
        fSize = m_fMax;
    }
    double fAspect = (double)m_nCy / (double)m_nCx;
    double fDepth = fSize * m_fZoom * 100.0;
    double fMaxZ = 2.0;
    fDepth = max(fDepth,  fMaxZ * m_fZoom * 2);

    m_fPixel2Log = 1.0;
    // orthogonal projection
    if(m_nCx <= m_nCy) {	
        glOrtho(-fSize, fSize, -fSize * fAspect, fSize * fAspect, -fDepth, fDepth);
        m_fPixel2Log = fSize / (m_nCx + 2);
    }
    else {
        glOrtho(-fSize / fAspect, fSize / fAspect, -fSize, fSize, -fDepth, fDepth);
        m_fPixel2Log = fSize / (m_nCy + 2);
    } 
    glViewport(-1, -1, m_nCx + 2, m_nCy + 2);	// m_viewport transformation


    // model view matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    glTranslated(m_fTx * fSize, m_fTy * fSize, 0);
    glScaled( m_fZoom, m_fZoom, m_fZoom );
    glRotated( m_fRx, 1.0, 0.0, 0.0 );
    glRotated( m_fRy, 0.0, 1.0, 0.0 );
    glRotated( m_fRz, 0.0, 0.0, 1.0 );

    glGetIntegerv(GL_VIEWPORT, m_viewport);
    glGetDoublev(GL_MODELVIEW_MATRIX, m_mvmatrix);
    glGetDoublev(GL_PROJECTION_MATRIX, m_projmatrix);


}	


void COpenGraph::CheckGLError()
{
    int nError = glGetError();
    switch (nError)
    {
    case GL_NO_ERROR:
        
        break;
    case GL_INVALID_ENUM:
        OutputDebugString(_T("GL_INVALID_ENUM"));
        break;
    case GL_INVALID_VALUE:
        OutputDebugString(_T("GL_INVALID_VALUE"));
        break;
    case GL_INVALID_OPERATION:
        OutputDebugString(_T("GL_INVALID_OPERATION"));
        break;
    case GL_STACK_OVERFLOW:
        OutputDebugString(_T("GL_STACK_OVERFLOW"));
        break;
    case GL_STACK_UNDERFLOW:
        OutputDebugString(_T("GL_STACK_UNDERFLOW"));
        break;
    case GL_OUT_OF_MEMORY:
        OutputDebugString(_T("GL_OUT_OF_MEMORY"));
        break;
    }

}


bool COpenGraph::TrackRect(HWND hWnd, POINT point)
{
    HDC hDC = GetDC(hWnd);
    m_pRubberBandTracker->SetContext(hDC, m_hRC);	// make sure we are not drawing rubber-band here
    return m_pRubberBandTracker->TrackRubberBand(m_hGLWnd, point, TRUE) == TRUE;
}

RECT COpenGraph::GetTrackRect()const
{
    return m_pRubberBandTracker->GetTrackRect();
}

BOOL COpenGraph::OnLButtonDown(RECT& rect, UINT nFlags, POINT point)
{
    HDC hDC = GetDC(m_hGLWnd);
    RECT rectClient;
    ::GetClientRect(m_hGLWnd, &rectClient);

    BOOL bReturn = FALSE;
    if(m_nMode == modeTRACK)
    {
        m_pRubberBandTracker->SetContext(hDC, m_hRC);	// make sure we are not drawing rubber-band here
        bReturn = m_pRubberBandTracker->TrackRubberBand(m_hGLWnd, point, TRUE);
        if(bReturn)
        {
            rect = GetTrackRect();
        }
    }
    else if(m_nMode == modeROTATE)	
    {
        m_ptOld = point;
    }	

    return bReturn;
}

void COpenGraph::OnMouseMove(UINT nFlags, POINT point) 
{
    if( nFlags & MK_LBUTTON)
    {
        if(m_nMode == modeROTATE)
        {
            m_fRy += 0.5f * (point.x-m_ptOld.x);
            m_fRx += 0.5f * (point.y-m_ptOld.y);
            m_ptOld = point;
            Render();
        }
    }

}


void COpenGraph::SetMode(int mode)
{
    m_nMode = mode;
    OnSetCursor();
}

HCURSOR COpenGraph::GetModeCursor()
{
    if(m_nMode == modeTRACK)
    {
        return (m_hSelectCursor);
    }
    else if(m_nMode == modeROTATE)
    {
        return (m_hRotateCursor);
    }
    else
    {   
        return (LoadCursor(0, IDC_ARROW));
    }
}

void COpenGraph::OnSetCursor()
{
    SetCursor(GetModeCursor());
}

void COpenGraph::DrawAxisCube()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glPushMatrix();
    double fSize = 1.0;
    double fAspect = (double)m_nCy / (double)m_nCx;
    // orthographic projection
    if(m_nCx <= m_nCy) {
        glOrtho(0, fSize, 0, fSize * fAspect, -fSize, fSize);
    }
    else {
        glOrtho(0, fSize / fAspect, 0, fSize, -fSize, fSize);
    } 
    glViewport(-1, -1, m_nCx + 2, m_nCy + 2);

    // MODELVIEW matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    double fTemp = min(m_nCx, m_nCy);
    glPushMatrix();
    // model view transformation
    //glTranslated(50. / fTemp , 50. / fTemp, 0);
    glTranslated(60. / fTemp , 60. / fTemp, 0);
    glRotated( m_fRx, 1.0, 0.0, 0.0 );
    glRotated( m_fRy, 0.0, 1.0, 0.0 );
    glRotated( m_fRz, 0.0, 0.0, 1.0 );
    CGLFont2d* pFont2d = m_pDrawManager->GetFont(0);    // built-in font
    CDrawHelper::DrawAxisCube(12. / fTemp, pFont2d);
    glPopMatrix();

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();

}

void COpenGraph::DrawNodes()
{
#ifdef USE_DISPLAY_LIST
     glCallList(m_nDisplayList[NODE_LIST]);   
#else
    const vector<CNodeBatch>& vBatchNodes = m_pDrawManager->GetNodeBatches();
    CDrawHelper::DrawNodes(vBatchNodes);
#endif
}

void COpenGraph::DrawLines()
{
#ifdef USE_DISPLAY_LIST
    glCallList(m_nDisplayList[LINE_LIST]);   
#else
    const vector<CLineBatch>& vBatchLines = m_pDrawManager->GetLineBatches();
    CDrawHelper::DrawLines(vBatchLines);
#endif
}

void COpenGraph::DrawTriangles()
{
#ifdef USE_DISPLAY_LIST
    glCallList(m_nDisplayList[TRIANGLE_LIST]);   
#else
    const vector<CTriangleBatch>& vBatchTriangles = m_pDrawManager->GetTriangleBatches();
    CDrawHelper::DrawTriangles(vBatchTriangles);
#endif
}

void COpenGraph::DrawQuads()
{
#ifdef USE_DISPLAY_LIST
    glCallList(m_nDisplayList[QUAD_LIST]);   
#else
    const vector<CQuadBatch>& vBatchQuads = m_pDrawManager->GetQuadBatches();
    CDrawHelper::DrawQuads(vBatchQuads);
#endif
}

void DrawTextsHelper(CDrawManager* pDrawManager, const vector<CText>& vText)
{
    for(int i = 0; i < (int)vText.size(); i++)
    {
        const CText& text = vText[i];
        CGLFont2d* pFont2d = pDrawManager->GetFont(text.nFontId);
        GLdouble color[3];
        if(text.nStatus & STATUS_SELECTED)
        {
            CDrawHelper::ConvertColors(color, text.colorSelected);
        }
        else
        {
            CDrawHelper::ConvertColors(color, text.color);
        }
        glColor3dv(color);
        Font2dPrintf(pFont2d, text.nAlignment, text.pt, text.strText);
    }
}

void COpenGraph::DrawTexts()
{
#ifdef USE_DISPLAY_LIST
    glCallList(m_nDisplayList[TEXT_LIST]);   
#else
    const vector<CText>& vText = m_pDrawManager->GetTexts();
    DrawTextsHelper(m_pDrawManager, vText);
#endif
}

void COpenGraph::DebugDraw()
{
    TCHAR szMsg[1234];
    _stprintf(szMsg, _T("Rx = %.2f, Ry = %.2f, Rz = %.2f"), m_fRx, m_fRy, m_fRz);
    CPointf ptBase(m_nCx - 10, m_nCy - 10, 0);
    const GLdouble color_x[3] = {1., 1.0, .0};
    glColor3dv(color_x);
    CGLFont2d* pFont2d = m_pDrawManager->GetFont(0);    // built-in font
    Font2dPrintf(pFont2d, ALIGN_TOP|ALIGN_RIGHT, ptBase, szMsg);

    CPointf ptBase1(10, m_nCy - 10, 0);
    CPointf ptBase2(10, m_nCy - 25, 0);
    Font2dPrintf(pFont2d, ALIGN_TOP|ALIGN_LEFT, ptBase1, _T("OpenGraph Library by Junlin Xu, Jan 2013"));
    Font2dPrintf(pFont2d, ALIGN_TOP|ALIGN_LEFT, ptBase2, _T("Computations & Graphics, Inc. (www.cg-inc.com)"));

}

void COpenGraph::Rotate(double fRx, double fRy, double fRz)
{
    m_fRx = fRx;
    m_fRy = fRy;
    m_fRz = fRz;
    Render();
}

void COpenGraph::GetTransformParameters(double& fTx, double& fTy, double& fRx, double& fRy, double& fRz, double& fZoom)
{
    fTx = m_fTx;
    fTy = m_fTy;
    fRx = m_fRx;
    fRy = m_fRy;
    fRz = m_fRz;
    fZoom = m_fZoom;
}

void COpenGraph::Clear()
{
    m_pDrawManager->Clear();
    m_bDirty = true;
}

CIdentity COpenGraph::AddNode(int id,CPointf pt, int nSize, COLORREF color,COLORREF colorSelected, int nStatus, LPCTSTR tag, LPCTSTR userData )
{
    m_bDirty = true;
    return m_pDrawManager->AddNode(id,pt, nSize, color,colorSelected, nStatus, tag, userData );
}

void COpenGraph::AddNodes(CIdentity* pIdentity,int* pId,CPointf* pPt, int nNodes, int nSize, COLORREF color,COLORREF colorSelected, int nStatus, LPCTSTR tag, LPCTSTR userData)
{
    m_bDirty = true;
    return m_pDrawManager->AddNodes(pIdentity, pId, pPt, nNodes, nSize, color, colorSelected, nStatus, tag, userData);
}

CIdentity COpenGraph::AddLine(int id,CPointf pt1,CPointf pt2, int nThickness, COLORREF color,COLORREF colorSelected, int nStatus, LPCTSTR tag, LPCTSTR userData )
{
    m_bDirty = true;
    return m_pDrawManager->AddLine(id, pt1, pt2, nThickness, color, colorSelected, nStatus, tag, userData);

}

void COpenGraph::AddLines(CIdentity* pIdentity, int* pId,CPointf* pPt1,CPointf* pPt2, int nLines, int nThickness, COLORREF color,COLORREF colorSelected, int nStatus, LPCTSTR tag, LPCTSTR userData )
{
    m_bDirty = true;
    return m_pDrawManager->AddLines(pIdentity, pId, pPt1, pPt2, nLines, nThickness, color, colorSelected, nStatus, tag, userData);
}

CIdentity COpenGraph::AddTriangle(int id,CPointf pt1,CPointf pt2,CPointf pt3, COLORREF color,COLORREF colorSelected, float alpha, int nStatus, LPCTSTR tag, LPCTSTR userData )
{
    m_bDirty = true;
    return m_pDrawManager->AddTriangle(id, pt1, pt2, pt3, color, colorSelected, alpha, nStatus, tag, userData);
}

void COpenGraph::AddTriangles(CIdentity* pIdentity, int* pId,CPointf* pPt1,CPointf* pPt2, CPointf* pPt3, int nTriangles, COLORREF color,COLORREF colorSelected,float alpha, int nStatus, LPCTSTR tag, LPCTSTR userData )
{
    m_bDirty = true;
    m_pDrawManager->AddTriangles(pIdentity, pId, pPt1, pPt2, pPt3, nTriangles, color, colorSelected, alpha, nStatus, tag, userData);
}

CIdentity COpenGraph::AddQuad(int id,CPointf pt1,CPointf pt2,CPointf pt3,CPointf pt4, COLORREF color,COLORREF colorSelected, float alpha, int nStatus, LPCTSTR tag, LPCTSTR userData )
{
    m_bDirty = true;
    return m_pDrawManager->AddQuad(id, pt1, pt2, pt3, pt4, color, colorSelected, alpha, nStatus, tag, userData);
}

void COpenGraph::AddQuads(CIdentity* pIdentity, int* pId,CPointf* pPt1,CPointf* pPt2, CPointf* pPt3,CPointf* pPt4, int nQuads, COLORREF color,COLORREF colorSelected,float alpha, int nStatus, LPCTSTR tag, LPCTSTR userData )
{
    m_bDirty = true;
    m_pDrawManager->AddQuads(pIdentity, pId, pPt1, pPt2, pPt3, pPt4, nQuads, color, colorSelected, alpha, nStatus, tag, userData);
}

void COpenGraph::FreeMemory(void * p)
{
    delete p;
}

void COpenGraph::FreeMemoryArray(void * p)
{
    delete []p;
}

void COpenGraph::CreateLists()
{
    OutputDebugString(_T("CreateLists()"));
    HDC hDC = GetDC(m_hGLWnd);
    wglMakeCurrent(hDC, m_hRC);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    {
        CGLNewListHelper helper(m_nDisplayList[NODE_LIST]);
        const vector<CNodeBatch>& vBatchNodes = m_pDrawManager->GetNodeBatches();
        CDrawHelper::DrawNodes(vBatchNodes);
    }

    {
        CGLNewListHelper helper(m_nDisplayList[LINE_LIST]);
        const vector<CLineBatch>& vBatchLines = m_pDrawManager->GetLineBatches();
        CDrawHelper::DrawLines(vBatchLines);
    }

    {
        CGLNewListHelper helper(m_nDisplayList[TRIANGLE_LIST]);
        const vector<CTriangleBatch>& vBatchTriangles = m_pDrawManager->GetTriangleBatches();
        CDrawHelper::DrawTriangles(vBatchTriangles);
    }

    {
        CGLNewListHelper helper(m_nDisplayList[QUAD_LIST]);
        const vector<CQuadBatch>& vBatchQuads = m_pDrawManager->GetQuadBatches();
        CDrawHelper::DrawQuads(vBatchQuads);
    }

    {
        CGLNewListHelper helper(m_nDisplayList[TEXT_LIST]);
        DrawTextsHelper(m_pDrawManager, m_pDrawManager->GetTexts());
    }

    m_bDirty = false;
    wglMakeCurrent(NULL, NULL) ;
}

void COpenGraph::SelectAll()
{
    m_pDrawManager->SelectAll();
    m_bDirty = true;
}

void COpenGraph::UnSelectAll()
{
    m_pDrawManager->UnSelectAll();
    m_bDirty = true;
}

void COpenGraph::ReverseSelectAll()
{
    m_pDrawManager->ReverseSelectAll();
    m_bDirty = true;
}

void COpenGraph::SetupWindowMatrix()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    double fSize = min(m_nCx, m_nCy);
    double fAspect = (double)m_nCy / (double)m_nCx;
    // orthographic projection
    if(m_nCx <= m_nCy) {
        glOrtho(0, fSize, 0, fSize * fAspect, -fSize, fSize);
    }
    else {
        glOrtho(0, fSize / fAspect, 0, fSize, -fSize, fSize);
    } 
    glViewport(-1, -1, m_nCx + 2, m_nCy + 2);

    // MODELVIEW matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}	

}