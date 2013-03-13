////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2002-2013 Computations & Graphics, Inc. 
// 
// All rights reserved.
//
// Author: Junlin Xu
//
//////////////////////////////////////////////////////////////////////////

#include "DrawManager.h"
#include "MathHelper.h"
#include <gl\glu.h>
#include "GLFont.h"

namespace NSOpenGraphLib
{
    // some handy template functions to save typing
    template<class T1, class T2> void SelectAllTemplate(vector<T1>& vBatches)
    {
        for(int iBatch = 0; iBatch < (int)vBatches.size(); iBatch++)
        {
            T1& batch = vBatches[iBatch];
            for(int i = 0; i < (int)batch.vDrawables.size(); i++)
            {
                T2& drawable = batch.vDrawables[i];
                drawable.nStatus |= STATUS_SELECTED;
            }
        }	
    }

    template<class T1, class T2> void UnSelectAllTemplate(vector<T1>& vBatches)
    {
        for(int iBatch = 0; iBatch < (int)vBatches.size(); iBatch++)
        {
            T1& batch = vBatches[iBatch];
            for(int i = 0; i < (int)batch.vDrawables.size(); i++)
            {
                T2& drawable = batch.vDrawables[i];
                drawable.nStatus &= ~STATUS_SELECTED;
            }
        }
    }

    template<class T1, class T2> void ReverseSelectAllTemplate(vector<T1>& vBatches)
    {
        for(int iBatch = 0; iBatch < (int)vBatches.size(); iBatch++)
        {
            T1& batch = vBatches[iBatch];
            for(int i = 0; i < (int)batch.vDrawables.size(); i++)
            {
                T2& drawable = batch.vDrawables[i];
                drawable.nStatus ^= STATUS_SELECTED;
            }
        }	
    }

    template<class T1> int GetDrawableCountTemplate(vector<T1>& vBatches)
    {
        int count = 0;
        for(int iBatch = 0; iBatch < (int)vBatches.size(); iBatch++)
        {
            const T1& batch = vBatches[iBatch];
            count += (int)batch.vDrawables.size();
        }
        return count;
    }

    template<class T1, class T2> void GetSelectedTemplate(CIdentity*& pIdentity, int& nDrawables, vector<T1>& vBatches)
    {
        pIdentity = 0;
        vector<CString> vUniqueId;
        vector<int> vId;
        for(int iBatch = 0; iBatch < (int)vBatches.size(); iBatch++)
        {
            const T1& batch = vBatches[iBatch];
            for(int i = 0; i < (int)batch.vDrawables.size(); i++)
            {
                const T2& drawable = batch.vDrawables[i];
                if(drawable.nStatus & STATUS_SELECTED)
                {
                    vUniqueId.push_back(drawable.strUid);
                    vId.push_back(drawable.nId);
                }
            }
        }	
        nDrawables = (int)vUniqueId.size();
        if(nDrawables != 0)
        {
            pIdentity = new CIdentity[nDrawables];
            for(int i = 0; i < (int)vUniqueId.size(); i++)
            {
                SaftStrncpy(pIdentity[i].uid, vUniqueId[i], MAX_UID_SIZE - 1);
                pIdentity[i].id = vId[i];
            }
        }
    }


CDrawManager::CDrawManager(void)
{
}


CDrawManager::~CDrawManager(void)
{
    for(map<int, CGLFont2d*>::iterator iter = m_mapFont.begin(); iter != m_mapFont.end(); iter++)
    {
        Font2dDelete(iter->second);
    }
}

void CDrawManager::Clear()
{
    m_vNodeBatches.clear();
    m_vLineBatches.clear();
    m_vTriangleBatches.clear();
    m_vQuadBatches.clear();
    m_vText.clear();
}



void CDrawManager::SelectAll()
{
    SelectAllTemplate<CNodeBatch, CNode>(m_vNodeBatches);
    SelectAllTemplate<CLineBatch, CLine>(m_vLineBatches);
    SelectAllTemplate<CTriangleBatch, CTriangle>(m_vTriangleBatches);
    SelectAllTemplate<CQuadBatch, CQuad>(m_vQuadBatches);
}

void CDrawManager::UnSelectAll()
{
    UnSelectAllTemplate<CNodeBatch, CNode>(m_vNodeBatches);
    UnSelectAllTemplate<CLineBatch, CLine>(m_vLineBatches);
    UnSelectAllTemplate<CTriangleBatch, CTriangle>(m_vTriangleBatches);
    UnSelectAllTemplate<CQuadBatch, CQuad>(m_vQuadBatches);
}

void CDrawManager::ReverseSelectAll()
{
    ReverseSelectAllTemplate<CNodeBatch, CNode>(m_vNodeBatches);
    ReverseSelectAllTemplate<CLineBatch, CLine>(m_vLineBatches);
    ReverseSelectAllTemplate<CTriangleBatch, CTriangle>(m_vTriangleBatches);
    ReverseSelectAllTemplate<CQuadBatch, CQuad>(m_vQuadBatches);
}

///////////////////////////////////////////////////////
// NODES
CIdentity AddNodeHelper(vector<CNodeBatch>& vNodeBatch, CString strPrefix, int id,CPointf pt, int nSize, COLORREF color,COLORREF colorSelected, int nStatus, LPCTSTR tag, LPCTSTR userData )
{
    int count = GetDrawableCountTemplate<CNodeBatch>(vNodeBatch);

    CNodeBatch batch;
    vNodeBatch.push_back(batch);
    CNodeBatch& batchRef = vNodeBatch.back();// this is for efficiency only

    CNode nd;
    nd.nId = id;
    nd.pt = pt;
    nd.nSize = nSize;
    nd.color = color;
    nd.colorSelected = colorSelected;
    nd.strTag = tag;
    nd.nStatus = nStatus;
    nd.strUserData = userData;

    count++;
    nd.strUid.Format(_T("%s_%d"), strPrefix, count);

    batchRef.color = color;
    batchRef.colorSelected = colorSelected;
    batchRef.nSize = nSize;
    batchRef.vDrawables.push_back(nd);

    CIdentity identity;
    identity.id = id;
    SaftStrncpy(identity.uid, nd.strUid, MAX_UID_SIZE - 1);
    return identity;
}

CIdentity CDrawManager::AddNode(int id,CPointf pt, int nSize, COLORREF color,COLORREF colorSelected, int nStatus, LPCTSTR tag, LPCTSTR userData )
{
    return AddNodeHelper(m_vNodeBatches, _T("N"), id, pt,  nSize,  color, colorSelected,  nStatus,  tag,  userData);
}

void AddNodesHelper(vector<CNodeBatch>& vNodeBatch, CString strPrefix, CIdentity* pIdentity,int* pId,CPointf* pPt, int nNodes, int nSize, COLORREF color,COLORREF colorSelected, int nStatus, LPCTSTR tag, LPCTSTR userData )
{
    int count = GetDrawableCountTemplate<CNodeBatch>(vNodeBatch);

    CNodeBatch batch;
    vNodeBatch.push_back(batch);
    CNodeBatch& batchRef = vNodeBatch.back();   // this is for efficiency only

    batchRef.color = color;
    batchRef.colorSelected = colorSelected;
    batchRef.nSize = nSize;
    batchRef.vDrawables.reserve(nNodes); // for efficiency

    for(int i = 0; i < nNodes; i++)
    {
        CNode nd;
        nd.nId = pId[i];
        nd.pt = pPt[i];
        nd.nSize = nSize;
        nd.color = color;
        nd.colorSelected = colorSelected;
        nd.strTag = tag;
        nd.nStatus = nStatus;
        if(userData != NULL)
        {
            nd.strUserData = userData[i];
        }

        count++;
        nd.strUid.Format(_T("%s_%d"), strPrefix, count);
        pIdentity[i].id = nd.nId;
        SaftStrncpy(pIdentity[i].uid, nd.strUid, MAX_UID_SIZE - 1);

        batchRef.vDrawables.push_back(nd);
    }
}


void CDrawManager::AddNodes(CIdentity* pIdentity,int* pId,CPointf* pPt, int nNodes, int nSize, COLORREF color,COLORREF colorSelected, int nStatus, LPCTSTR tag, LPCTSTR userData )
{
    AddNodesHelper(m_vNodeBatches, _T("N"), pIdentity, pId, pPt, nNodes, nSize, color,colorSelected, nStatus, tag, userData);
}


const vector<CNodeBatch>& CDrawManager::GetNodeBatches()
{
    return m_vNodeBatches;
}


CIdentity AddLineHelper(vector<CLineBatch>& vLineBatche, CString strPrefix, int id,CPointf pt1,CPointf pt2, int nThickness, COLORREF color,COLORREF colorSelected, int nStatus, LPCTSTR tag, LPCTSTR userData )
{
    int count = GetDrawableCountTemplate<CLineBatch>(vLineBatche);

    CLineBatch batch;
    vLineBatche.push_back(batch);
    CLineBatch& batchRef = vLineBatche.back();// this is for efficiency only

    CLine line;
    line.nId = id;
    line.pt[0] = pt1;
    line.pt[1] = pt2;
    line.nThickness = nThickness;
    line.color = color;
    line.colorSelected = colorSelected;
    line.strTag = tag;
    line.nStatus = nStatus;
    line.strUserData = userData;

    count++;
    line.strUid.Format(_T("%s_%d"), strPrefix, count);

    batchRef.color = color;
    batchRef.colorSelected = colorSelected;
    batchRef.nThickness = nThickness;
    batchRef.vDrawables.push_back(line);

    CIdentity identity;
    identity.id = id;
    SaftStrncpy(identity.uid, line.strUid, MAX_UID_SIZE - 1);
    return identity;

}



//////////////////////////////////////////////////////////////////////////////////////////
// LINES
CIdentity CDrawManager::AddLine(int id,CPointf pt1,CPointf pt2, int nThickness, COLORREF color,COLORREF colorSelected, int nStatus, LPCTSTR tag, LPCTSTR userData )
{
    return AddLineHelper(m_vLineBatches, _T("L"), id,pt1,pt2, nThickness, color,colorSelected, nStatus, tag, userData);
}


void AddLinesHelper(vector<CLineBatch>& vLineBatche, CString strPrefix, CIdentity* pIdentity, int* pId,CPointf* pPt1,CPointf* pPt2, int nLines, int nThickness, COLORREF color,COLORREF colorSelected, int nStatus, LPCTSTR tag, LPCTSTR userData )
{
    int count = GetDrawableCountTemplate<CLineBatch>(vLineBatche);

    CLineBatch batch;
    vLineBatche.push_back(batch);
    CLineBatch& batchRef = vLineBatche.back();   // this is for efficiency only

    batchRef.color = color;
    batchRef.colorSelected = colorSelected;
    batchRef.nThickness = nThickness;
    batchRef.vDrawables.reserve(nLines); // for efficiency

    for(int i = 0; i < nLines; i++)
    {
        CLine line;
        line.nId = pId[i];
        line.pt[0] = pPt1[i];
        line.pt[1] = pPt2[i];
        line.nThickness = nThickness;
        line.color = color;
        line.colorSelected = colorSelected;
        line.strTag = tag;
        line.nStatus = nStatus;
        if(userData != NULL)
        {
            line.strUserData = userData[i];
        }

        count++;
        line.strUid.Format(_T("%s_%d"), strPrefix, count);
        pIdentity[i].id = line.nId;
        SaftStrncpy(pIdentity[i].uid, line.strUid, MAX_UID_SIZE - 1);

        batchRef.vDrawables.push_back(line);
    }
}

void CDrawManager::AddLines(CIdentity* pIdentity, int* pId,CPointf* pPt1,CPointf* pPt2, int nLines, int nThickness, COLORREF color,COLORREF colorSelected, int nStatus, LPCTSTR tag, LPCTSTR userData )
{
    AddLinesHelper(m_vLineBatches, _T("L"), pIdentity, pId, pPt1, pPt2, nLines, nThickness, color,colorSelected, nStatus, tag, userData);
}


const vector<CLineBatch>& CDrawManager::GetLineBatches()
{
    return m_vLineBatches;
}


//////////////////////////////////////////////////////////////////////////////////////////
// TRIANGLE
CIdentity AddTriangleHelper(vector<CTriangleBatch>& vTriangleBatches, CString strPrefix, int id,CPointf pt1,CPointf pt2, CPointf pt3, COLORREF color,COLORREF colorSelected,float alpha, int nStatus, LPCTSTR tag, LPCTSTR userData )
{
    int count = GetDrawableCountTemplate<CTriangleBatch>(vTriangleBatches);

    CTriangleBatch batch;
    vTriangleBatches.push_back(batch);
    CTriangleBatch& batchRef = vTriangleBatches.back();// this is for efficiency only

    CTriangle triangle;
    triangle.nId = id;
    triangle.pt[0] = pt1;
    triangle.pt[1] = pt2;
    triangle.pt[2] = pt3;
    triangle.color = color;
    triangle.colorSelected = colorSelected;
    triangle.strTag = tag;
    triangle.nStatus = nStatus;
    triangle.strUserData = userData;

    count++;
    triangle.strUid.Format(_T("%s_%d"),strPrefix, count);;

    batchRef.color = color;
    batchRef.colorSelected = colorSelected;
    batchRef.fAlpha = alpha;
    batchRef.vDrawables.push_back(triangle);

    CIdentity identity;
    identity.id = id;
    SaftStrncpy(identity.uid, triangle.strUid, MAX_UID_SIZE - 1);
    return identity;
}


CIdentity CDrawManager::AddTriangle(int id,CPointf pt1,CPointf pt2, CPointf pt3, COLORREF color,COLORREF colorSelected,float alpha, int nStatus, LPCTSTR tag, LPCTSTR userData )
{
    return AddTriangleHelper(m_vTriangleBatches, _T("TRI"), id,pt1,pt2, pt3, color,colorSelected, alpha,  nStatus, tag, userData);
}

void AddTrianglesHelper(vector<CTriangleBatch>& vTriangleBatches, CString strPrefix, CIdentity* pIdentity, int* pId,CPointf* pPt1,CPointf* pPt2, CPointf* pPt3, int nTriangles, COLORREF color,COLORREF colorSelected, float alpha, int nStatus, LPCTSTR tag, LPCTSTR userData )
{
    int count = GetDrawableCountTemplate<CTriangleBatch>(vTriangleBatches);

    CTriangleBatch batch;
    vTriangleBatches.push_back(batch);
    CTriangleBatch& batchRef = vTriangleBatches.back();   // this is for efficiency only

    batchRef.color = color;
    batchRef.colorSelected = colorSelected;
    batchRef.fAlpha = alpha;
    batchRef.vDrawables.reserve(nTriangles); // for efficiency

    for(int i = 0; i < nTriangles; i++)
    {
        CTriangle triangle;
        triangle.nId = pId[i];
        triangle.pt[0] = pPt1[i];
        triangle.pt[1] = pPt2[i];
        triangle.pt[2] = pPt3[i];
        triangle.color = color;
        triangle.colorSelected = colorSelected;
        triangle.strTag = tag;
        triangle.nStatus = nStatus;
        if(userData != NULL)
        {
            triangle.strUserData = userData[i];
        }

        count++;
        triangle.strUid.Format(_T("%s_%d"), strPrefix, count);
        pIdentity[i].id = triangle.nId;
        SaftStrncpy(pIdentity[i].uid, triangle.strUid, MAX_UID_SIZE - 1);

        batchRef.vDrawables.push_back(triangle);
    }
}


void CDrawManager::AddTriangles(CIdentity* pIdentity, int* pId,CPointf* pPt1,CPointf* pPt2, CPointf* pPt3, int nTriangles, COLORREF color,COLORREF colorSelected, float alpha, int nStatus, LPCTSTR tag, LPCTSTR userData )
{
    AddTrianglesHelper(m_vTriangleBatches, _T("TRI"), pIdentity, pId, pPt1, pPt2, pPt3, nTriangles, color,colorSelected, alpha, nStatus, tag, userData);
}


const vector<CTriangleBatch>& CDrawManager::GetTriangleBatches()
{
    return m_vTriangleBatches;
}

//////////////////////////////////////////////////////////////////////////////////////////
// QUAD
CIdentity AddQuadHelper(vector<CQuadBatch>& vQuadBatches, CString strPrefix, int id,CPointf pt1,CPointf pt2, CPointf pt3,CPointf pt4, COLORREF color,COLORREF colorSelected,float alpha, int nStatus, LPCTSTR tag, LPCTSTR userData )
{
    int count = GetDrawableCountTemplate<CQuadBatch>(vQuadBatches);

    CQuadBatch batch;
    vQuadBatches.push_back(batch);
    CQuadBatch& batchRef = vQuadBatches.back();// this is for efficiency only

    CQuad quad;
    quad.nId = id;
    quad.pt[0] = pt1;
    quad.pt[1] = pt2;
    quad.pt[2] = pt3;
    quad.pt[3] = pt4;
    quad.color = color;
    quad.colorSelected = colorSelected;
    quad.strTag = tag;
    quad.nStatus = nStatus;
    quad.strUserData = userData;

    count++;
    quad.strUid.Format(_T("%s_%d"), strPrefix, count);

    batchRef.color = color;
    batchRef.colorSelected = colorSelected;
    batchRef.fAlpha = alpha;
    batchRef.vDrawables.push_back(quad);

    CIdentity identity;
    identity.id = id;
    SaftStrncpy(identity.uid, quad.strUid, MAX_UID_SIZE - 1);
    return identity;
}

CIdentity CDrawManager::AddQuad(int id,CPointf pt1,CPointf pt2, CPointf pt3,CPointf pt4, COLORREF color,COLORREF colorSelected,float alpha, int nStatus, LPCTSTR tag, LPCTSTR userData )
{
    return AddQuadHelper(m_vQuadBatches, _T("QUAD"), id, pt1, pt2,  pt3, pt4,  color, colorSelected, alpha,  nStatus,  tag, userData );
}


void AddQuadsHelper(vector<CQuadBatch>& vQuadBatches, CString strPrefix, CIdentity* pIdentity, int* pId,CPointf* pPt1,CPointf* pPt2, CPointf* pPt3,CPointf* pPt4, int nQuads, COLORREF color,COLORREF colorSelected, float alpha, int nStatus, LPCTSTR tag, LPCTSTR userData )
{
    int count = GetDrawableCountTemplate<CQuadBatch>(vQuadBatches);

    CQuadBatch batch;
    vQuadBatches.push_back(batch);
    CQuadBatch& batchRef = vQuadBatches.back();   // this is for efficiency only

    batchRef.color = color;
    batchRef.colorSelected = colorSelected;
    batchRef.fAlpha = alpha;
    batchRef.vDrawables.reserve(nQuads); // for efficiency

    for(int i = 0; i < nQuads; i++)
    {
        CQuad quad;
        quad.nId = pId[i];
        quad.pt[0] = pPt1[i];
        quad.pt[1] = pPt2[i];
        quad.pt[2] = pPt3[i];
        quad.pt[3] = pPt4[i];
        quad.color = color;
        quad.colorSelected = colorSelected;
        quad.strTag = tag;
        quad.nStatus = nStatus;
        if(userData != NULL)
        {
            quad.strUserData = userData[i];
        }

        count++;
        quad.strUid.Format(_T("%s_%d"), strPrefix, count);
        pIdentity[i].id = quad.nId;
        SaftStrncpy(pIdentity[i].uid, quad.strUid, MAX_UID_SIZE - 1);

        batchRef.vDrawables.push_back(quad);
    }
}

void CDrawManager::AddQuads(CIdentity* pIdentity, int* pId,CPointf* pPt1,CPointf* pPt2, CPointf* pPt3,CPointf* pPt4, int nQuads, COLORREF color,COLORREF colorSelected, float alpha, int nStatus, LPCTSTR tag, LPCTSTR userData )
{
    AddQuadsHelper(m_vQuadBatches, _T("QUAD"), pIdentity, pId, pPt1, pPt2,  pPt3, pPt4,  nQuads,  color, colorSelected, alpha,  nStatus, tag, userData);
}


const vector<CQuadBatch>& CDrawManager::GetQuadBatches()
{
    return m_vQuadBatches;
}

int CDrawManager::AddFont(CGLFont2d* pFont2d)
{
    int nFontCount = (int)m_mapFont.size();
    m_mapFont[nFontCount] = pFont2d;
    return nFontCount;
}

CGLFont2d* CDrawManager::GetFont(int fontId)
{
    map<int, CGLFont2d*>::iterator iter = m_mapFont.find(fontId) ;
    if(iter != m_mapFont.end())
    {
        return iter->second;
    }
    else
    {
        return m_mapFont[0];    // use the default font if we do not find the requested font
    }
}

CIdentity AddTextHelper(vector<CText>& vText, CString strPrefix, int id, int nFontId, CPointf pt, LPCTSTR text, COLORREF color,COLORREF colorSelected, int nAlignment, int nStatus)
{
    int count = (int)vText.size();

    CText txt;
    txt.nId = id;
    txt.nFontId = nFontId;
    txt.pt = pt;
    txt.strText = text;
    txt.color = color;
    txt.colorSelected = colorSelected;
    txt.nAlignment = nAlignment;
    txt.nStatus = nStatus;
    count++;
    txt.strUid.Format(_T("%s_%d"), strPrefix, count);
    vText.push_back(txt);

    CIdentity identity;
    identity.id = id;
    SaftStrncpy(identity.uid, txt.strUid, MAX_UID_SIZE - 1);
    return identity;
}

CIdentity CDrawManager::AddText(int id, int nFontId, CPointf pt, LPCTSTR text, COLORREF color,COLORREF colorSelected, int nAlignment, int nStatus)
{
    return AddTextHelper(m_vText, _T("TXT"), id, nFontId, pt, text, color,colorSelected, nAlignment, nStatus);
}

const vector<CText>& CDrawManager::GetTexts()
{
    return m_vText;
}


}