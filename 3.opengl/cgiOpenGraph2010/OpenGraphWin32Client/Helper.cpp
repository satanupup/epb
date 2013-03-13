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
#include <time.h>

#include <atlstr.h>
#include "OpenGraph.h"


using namespace NSOpenGraphLib;
extern COpenGraph m_openGraph;
extern int m_nCx;
extern int m_nCy;

#include "Helper.h"


//////////////////////////////////////////////////////////////////////
void BoxPts(CPointf pt[8], CPointf ptCenter, double fDeltaX, double fDeltaY, double fDeltaZ)
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


void OnViewSelectall()
{
    m_openGraph.SelectAll();
    m_openGraph.Render();
}   

void OnViewUnselectall()
{
    m_openGraph.UnSelectAll();
    m_openGraph.Render();
}   

void OnViewReverseselect()
{
    m_openGraph.ReverseSelectAll();
    m_openGraph.Render();
}

void OnDrawDrawnodes()
{
    int fontId = m_openGraph.AddFont(_T("Times New Roman"), 30, 0, 0);

    srand((unsigned)time(NULL));
    const int nNodes = 400;
    const int nBatches = 10;
    const int nNodesPerBatch = nNodes / nBatches;
    for(int j = 0; j < nBatches; j++)
    {
        COLORREF color = RGB(rand() % 256, rand() % 256, rand() % 256);
        COLORREF colorSelected = RGB(255, 0, 0);
        CPointf* pPt = new CPointf[nNodesPerBatch];
        int* pId = new int[nNodesPerBatch];
        int nSize = (rand() % 8);
        CString strTag;
        strTag.Format(_T("Tag_%d"), j);
        for(int i = 0; i < nNodesPerBatch; i++)
        {
            double x = ((double) rand() / RAND_MAX - 0.5) * 4;
            double y = ((double) rand() / RAND_MAX - 0.5) * 4;
            double z = ((double) rand() / RAND_MAX - 0.5) * 4;
            CString strText;
            int id = j * nNodesPerBatch + i + 1;
            strText.Format(_T("%d"), id);
            if(i%2 == 0)
            {
                m_openGraph.AddText(id, 0, CPointf(x, y, z), strText, RGB(125, 123, 0), colorSelected);
            }else
            {
                m_openGraph.AddText(id, fontId, CPointf(x, y, z), strText, RGB(0, 123, 123), colorSelected);
            }
            pId[i] = id;
            pPt[i] = CPointf(x, y, z);
        }
        CIdentity* pIdentity = new CIdentity[nNodesPerBatch];
        // for performance reason, you should send in your data in batches
        m_openGraph.AddNodes(pIdentity, pId, pPt, nNodesPerBatch, nSize, color, colorSelected, 0, strTag, NULL);
        delete []pIdentity;
        delete []pId;
        delete []pPt;
    }

    m_openGraph.AddNode(99999, CPointf(), 15, RGB(255, 255, 0), RGB(0, 255, 255), 0, NULL, NULL);
    m_openGraph.AddText(99999, 0, CPointf(), _T("99999"), RGB(125, 123, 0), RGB(0, 255, 255));


    m_openGraph.Render();
}

void OnDrawDrawlines()
{
    srand((unsigned)time(NULL));
    const int nNodes = 300;
    const int nBatches = 30;
    const int nLinesPerBatch = nNodes / nBatches;
    for(int j = 0; j < nBatches; j++)
    {
        COLORREF color = RGB(rand() % 256, rand() % 256, rand() % 256);
        COLORREF colorSelected = RGB(255, 0, 0);
        CPointf* pPt1 = new CPointf[nLinesPerBatch];
        CPointf* pPt2 = new CPointf[nLinesPerBatch];
        int* pId = new int[nLinesPerBatch];
        int nSize = (rand() % 8);
        CString strTag;
        strTag.Format(_T("Tag_%d"), j);
        for(int i = 0; i < nLinesPerBatch; i++)
        {
            double x1 = ((double) rand() / RAND_MAX - 0.5) * 4;
            double y1 = ((double) rand() / RAND_MAX - 0.5) * 4;
            double z1 = ((double) rand() / RAND_MAX - 0.5) * 4;
            double x2 = ((double) rand() / RAND_MAX - 0.3) * 4;
            double y2 = ((double) rand() / RAND_MAX - 0.2) * 4;
            double z2 = ((double) rand() / RAND_MAX - 0.4) * 4;
            int id = j * nLinesPerBatch + i + 1;
            pId[i] = id;
            pPt1[i] = CPointf(x1, y1, z1);
            pPt2[i] = CPointf(x2, y2, z2);

            CString strText;
            strText.Format(_T("%d"), id);
            m_openGraph.AddText(id, 0, (pPt1[i] + pPt2[i]) / 2.0, strText, RGB(255, 0, 0), colorSelected);
        }
        CIdentity* pIdentity = new CIdentity[nLinesPerBatch];
        // for performance reason, you should send in your data in batches
        m_openGraph.AddLines(pIdentity, pId, pPt1, pPt2, nLinesPerBatch, nSize, color, colorSelected, 0, strTag, NULL);
        delete []pIdentity;
        delete []pId;
        delete []pPt1;
        delete []pPt2;
    }

    m_openGraph.AddLine(99999, CPointf(-2, 0, 0), CPointf(2, 0, 0), 15, RGB(255, 255, 0), RGB(0, 255, 255), 0, NULL, 0);
    m_openGraph.AddText(99999, 0, (CPointf(-2, 0, 0) + CPointf(2, 0, 0)) / 2.0, _T("99999"), RGB(125, 123, 0), RGB(0, 123, 0));

    m_openGraph.Render();
}

void OnDrawDrawtriangles()
{
    CPointf pt[4] = {CPointf(0.5, 0, -0.5), CPointf(0.5, 0, 0.5), CPointf(-0.5, 0, 0.5), CPointf(0, 2, 0)};
    COLORREF colorSelected = RGB(255, 255, 0);
    CString strTag;

    m_openGraph.AddTriangle(1, pt[0], pt[1], pt[2], RGB(123, 0, 123), colorSelected,1, 0, strTag, NULL);
    m_openGraph.AddTriangle(2, pt[0], pt[1], pt[3], RGB(65, 0, 0), colorSelected,1, 0, strTag, NULL);
    m_openGraph.AddTriangle(3, pt[0], pt[3], pt[2], RGB(123, 0, 0), colorSelected,1, 0, strTag, NULL);
    m_openGraph.AddTriangle(4, pt[2], pt[3], pt[1], RGB(225, 0, 0), colorSelected,1, 0, strTag, NULL);

    // two transparent triangle
    CPointf pt1[2] = {CPointf(-1.5, -1.5, 1), CPointf(-1.5, -1.5, 1)};
    CPointf pt2[2] = {CPointf(1.2, 1.5, 1), CPointf(1.2, 1.5, 1)};
    CPointf pt3[2] = {CPointf(-2, 2.2, 1), CPointf(2, 0.2, 1)};
    int ids[2] = {5, 6};
    CIdentity identity[2];
    m_openGraph.AddTriangles(identity, ids, pt1, pt2, pt3, 2, RGB(0, 0, 255), colorSelected,0.5f, 0, strTag, NULL);
    m_openGraph.AddText(5, 0, CPointf((-1.5 + 1.2 + -2), (-1.5 + 1.5 + 2.2), (1 + 1 + 1)) / 3.0, _T("5"), RGB(125, 123, 0), colorSelected);
    m_openGraph.AddText(6, 0, CPointf((-1.5 + 1.2 + 2), (-1.5 + 1.5 + 0.2), (1 + 1 + 1)) / 3.0, _T("6"), RGB(125, 123, 0), colorSelected);

    m_openGraph.Render();
}

void OnDrawDrawquads()
{
    COLORREF colorSelected = RGB(123, 0, 255);
    CString strTag;
    CPointf pt[8];
    COLORREF color = RGB(int(0.8 * 255), 0, 0);
    BoxPts(pt, CPointf(0, 0, 0), 0.5, 2, 1);
    m_openGraph.AddQuad(1, pt[1], pt[0], pt[4], pt[5], RGB(65, 0, 0), colorSelected,1, 0, strTag, NULL);
    m_openGraph.AddQuad(2, pt[3], pt[2], pt[6], pt[7], RGB(65, 0, 0), colorSelected,1, 0, strTag, NULL);
    m_openGraph.AddQuad(3, pt[2], pt[1], pt[5], pt[6], RGB(123, 0, 0), colorSelected,1, 0, strTag, NULL);
    m_openGraph.AddQuad(4, pt[0], pt[3], pt[7], pt[4], RGB(123, 0, 0), colorSelected,1, 0, strTag, NULL);
    m_openGraph.AddQuad(5, pt[0], pt[1], pt[2], pt[3], RGB(225, 0, 0), colorSelected,1, 0, strTag, NULL);
    m_openGraph.AddQuad(6, pt[7], pt[6], pt[5], pt[4], RGB(225, 0, 0), colorSelected,1, 0, strTag, NULL);

    CPointf pt1[2] = {CPointf(-1.5, -1.5, 10), CPointf(0, -1.5, 10)};
    CPointf pt2[2] = {CPointf(0, -1.5, 10), CPointf(1.5, -1.5, 10)};
    CPointf pt3[2] = {CPointf(0, 1.5, 10), CPointf(1.5, 1.5, 10)};
    CPointf pt4[2] = {CPointf(-1.5, 1.5, 10), CPointf(0, 1.5, 10)};
    int ids[2] = {7, 8};
    CIdentity identity[2];
    m_openGraph.AddQuads(identity, ids, pt1, pt2, pt3, pt4, 2, RGB(0, 0, 255), colorSelected,0.5f, 0, strTag, NULL);
    m_openGraph.AddText(5, 0, CPointf(-0.75, 0, 10), _T("7"), RGB(125, 123, 0), colorSelected);
    m_openGraph.AddText(5, 0, CPointf(0.75, 0, 10), _T("8"), RGB(125, 123, 0), colorSelected);

    m_openGraph.Render();
}

void OnDrawClear()
{
    m_openGraph.Clear();
    m_openGraph.Render();
}

void OnModeDefault()
{
    m_openGraph.SetMode(COpenGraph::modeNONE);
}

void OnModeTrack()
{
    m_openGraph.SetMode(COpenGraph::modeTRACK);
}

void OnModeRotate()
{
    m_openGraph.SetMode(COpenGraph::modeROTATE);
}

