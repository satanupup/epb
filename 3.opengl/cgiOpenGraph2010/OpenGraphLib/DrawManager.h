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
#include<map>
#include<vector>
#include "Drawable.h"
using namespace std;



namespace NSOpenGraphLib
{
struct CGLFont2d;   // forward declaration

class CDrawManager
{
public:
    CDrawManager(void);
    ~CDrawManager(void);

    void Clear();
    void SelectAll();
    void UnSelectAll();
    void ReverseSelectAll();

    // 3D ---------------
    CIdentity AddNode(int id,CPointf pt, int nSize, COLORREF color,COLORREF colorSelected, int nStatus, LPCTSTR tag, LPCTSTR userData );
    void AddNodes(CIdentity* pIdentity,int* pId, CPointf* pPt, int nNodes, int nSize, COLORREF color,COLORREF colorSelected, int nStatus, LPCTSTR tag, LPCTSTR userData );
    const vector<CNodeBatch>& GetNodeBatches();

    CIdentity AddLine(int id,CPointf pt1,CPointf pt2, int nThickness, COLORREF color,COLORREF colorSelected, int nStatus, LPCTSTR tag, LPCTSTR userData );
    void AddLines(CIdentity* pIdentity,int* pId, CPointf* pPt1,CPointf* pPt2, int nLines, int nThickness, COLORREF color,COLORREF colorSelected, int nStatus, LPCTSTR tag, LPCTSTR userData );
    const vector<CLineBatch>& GetLineBatches();

    CIdentity AddTriangle(int id,CPointf pt1,CPointf pt2, CPointf pt3,COLORREF color,COLORREF colorSelected, float alpha, int nStatus, LPCTSTR tag, LPCTSTR userData );
    void AddTriangles(CIdentity* pIdentity,int* pId, CPointf* pPt1,CPointf* pPt2, CPointf* pPt3, int nTriangles, COLORREF color,COLORREF colorSelected, float alpha, int nStatus, LPCTSTR tag, LPCTSTR userData );
    const vector<CTriangleBatch>& GetTriangleBatches();

    CIdentity AddQuad(int id,CPointf pt1,CPointf pt2, CPointf pt3,CPointf pt4, COLORREF color,COLORREF colorSelected, float alpha, int nStatus, LPCTSTR tag, LPCTSTR userData );
    void AddQuads(CIdentity* pIdentity,int* pId, CPointf* pPt1,CPointf* pPt2, CPointf* pPt3,CPointf* pPt4, int nQuads, COLORREF color,COLORREF colorSelected, float alpha, int nStatus, LPCTSTR tag, LPCTSTR userData );
    const vector<CQuadBatch>& GetQuadBatches();

    int AddFont(CGLFont2d*);
    CGLFont2d* GetFont(int fontId);
    CIdentity AddText(int id, int nFontId, CPointf pt, LPCTSTR text, COLORREF color,COLORREF colorSelected, int nAlignment, int nStatus);
    const vector<CText>& GetTexts();

private:
    vector<CNodeBatch> m_vNodeBatches;
    vector<CLineBatch> m_vLineBatches;
    vector<CTriangleBatch> m_vTriangleBatches;
    vector<CQuadBatch> m_vQuadBatches;
    vector<CText> m_vText;

    map<int, CGLFont2d*> m_mapFont;
};


}
