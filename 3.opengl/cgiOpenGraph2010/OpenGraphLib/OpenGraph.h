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
#include "OpenGraphDefines.h"


namespace NSOpenGraphLib
{
// forward declaration
struct CGLFont2d;
class CRubberBandTracker;
class CDrawManager;


class OPENGRAPHLIB_API COpenGraph
{
public:
    COpenGraph(void);
    virtual ~COpenGraph(void);


public:
    enum {modeNONE = -1,modeTRACK, modeROTATE };

private:
    enum {GRID_LIST = 0, NODE_LIST, LINE_LIST, TRIANGLE_LIST, QUAD_LIST, TEXT_LIST,
          END_LIST};

public:
    bool Initialize(HWND hWnd);
    void SetMode(int mode);
    void SetWindowSize(int cx, int cy);
    void Render();
    void ForceRender();
    void ShowAxes(bool bShow);

    BOOL OnLButtonDown(RECT& rect, UINT nFlags, POINT point);
    void OnMouseMove(UINT nFlags, POINT point);
    HCURSOR GetModeCursor();
    void OnSetCursor();

    void Rotate(double fRx, double fRy, double fRz);

    bool TrackRect(HWND hWnd, POINT point);
    RECT GetTrackRect()const; // un-normalized

    void Clear();

    void SelectAll();
    void UnSelectAll();
    void ReverseSelectAll();

    void FreeMemory(void * p);
    void FreeMemoryArray(void * p);

    CIdentity AddNode(int id,CPointf pt, int nSize, COLORREF color,COLORREF colorSelected, int nStatus = STATUS_UNSELECTED, LPCTSTR tag = 0, LPCTSTR userData = 0);
    void AddNodes(CIdentity* pIdentity, int* pId, CPointf* pPt, int nNodes, int nSize, COLORREF color,COLORREF colorSelected, int nStatus = STATUS_UNSELECTED, LPCTSTR tag = 0, LPCTSTR userData = 0 );
    
    CIdentity AddLine(int id,CPointf pt1,CPointf pt2, int nThickness, COLORREF color,COLORREF colorSelected, int nStatus = STATUS_UNSELECTED, LPCTSTR tag = 0, LPCTSTR userData = 0 );
    void AddLines(CIdentity* pIdentity, int* pId, CPointf* pPt1,CPointf* pPt2, int nLines, int nThickness, COLORREF color,COLORREF colorSelected, int nStatus = STATUS_UNSELECTED, LPCTSTR tag = 0, LPCTSTR userData = 0 );
    
    CIdentity AddTriangle(int id,CPointf pt1,CPointf pt2,CPointf pt3, COLORREF color,COLORREF colorSelected, float alpha=1.0f, int nStatus = STATUS_UNSELECTED, LPCTSTR tag = 0, LPCTSTR userData = 0 );
    void AddTriangles(CIdentity* pIdentity,int* pId, CPointf* pPt1,CPointf* pPt2, CPointf* pPt3, int nTriangles, COLORREF color,COLORREF colorSelected,float alpha = 1.0f, int nStatus = STATUS_UNSELECTED, LPCTSTR tag = 0, LPCTSTR userData = 0 );
    
    CIdentity AddQuad(int id,CPointf pt1,CPointf pt2,CPointf pt3,CPointf pt4, COLORREF color,COLORREF colorSelected, float alpha=1.0f, int nStatus = STATUS_UNSELECTED, LPCTSTR tag = 0, LPCTSTR userData = 0 );
    void AddQuads(CIdentity* pIdentity,int* pId, CPointf* pPt1,CPointf* pPt2, CPointf* pPt3,CPointf* pPt4, int nQuads, COLORREF color,COLORREF colorSelected,float alpha = 1.0f, int nStatus = STATUS_UNSELECTED, LPCTSTR tag = 0, LPCTSTR userData = 0 );

    int AddFont(const TCHAR *typeface, int height, int weight = 0, DWORD italic = 0);
    CIdentity AddText(int id, int nFontId, CPointf pt, LPCTSTR text, COLORREF color,COLORREF colorSelected, int nAlignment = ALIGN_BOTTOM|ALIGN_LEFT, int nStatus = STATUS_UNSELECTED);

protected:
    bool InitializePixelFormat(HDC hDC);
    bool CreateRC(HGLRC& hRC, HDC hDC);
    void DestroyRC(HGLRC& hRC);
    void StartModel(HDC hDC);
    void SetupMatrix();
    void SetupWindowMatrix();
    void CheckGLError();

    void CreateLists();
    void DrawAxisCube();

    void DrawNodes();
    void DrawLines();
    void DrawTriangles();
    void DrawQuads();
    void DrawTexts();

    void DebugDraw();

    void GetTransformParameters(double& fTx, double& fTy, double& fRx, double& fRy, double& fRz, double& fZoom);
private:
    // opengl stuff
    int m_nCx;
    int m_nCy;
    HWND m_hGLWnd;
    HGLRC m_hRC ; 			//OpenGL Rendering Context
    int m_viewport[4];
    double m_mvmatrix[16];
    double m_projmatrix[16];
    bool m_bDirty;
    int m_nDisplayList[END_LIST];
    bool m_bShowAxes;

    // mode
    int  m_nMode;
    POINT m_ptOld;
    CRubberBandTracker* m_pRubberBandTracker;

    // cursors
    HCURSOR   m_hSelectCursor;
    HCURSOR   m_hZoomCursor;
    HCURSOR   m_hPanCursor;
    HCURSOR   m_hRotateCursor;
    HCURSOR   m_hQueryCursor;

    // for setting
    double m_fTx;
    double m_fTy;
    double m_fRx;
    double m_fRy;
    double m_fRz;
    double m_fZoom;
    double m_fMax;
    double m_fPixel2Log;

private:
    CDrawManager* m_pDrawManager;

};

}