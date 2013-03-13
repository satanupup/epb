////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2002-2013 Computations & Graphics, Inc. 
// 
// All rights reserved.
//
// Author: Junlin Xu
//
//////////////////////////////////////////////////////////////////////////


#include <atlstr.h>
#include <vcclr.h>
#include "OpenGraph.h"

#include "OpenGraph_Cli.h"

using namespace NSOpenGraphLib;
using namespace NSOpenGraphLib_Cli;

CString cgiConvertString(const String^ s)
{
    CString sOut(s); 
    return sOut;
}

COpenGraph_Cli::COpenGraph_Cli(void)
{
    m_pOpenGraph = new COpenGraph();
}

bool COpenGraph_Cli::Initialize(IntPtr hWndPtr)
{
    HWND hWnd = (HWND)hWndPtr.ToInt32(); // jxu: for debugging, I have to to this
    bool bReturn = m_pOpenGraph->Initialize(hWnd);
    return true;
}

void COpenGraph_Cli::SetMode(Mode mode)
{
    m_pOpenGraph->SetMode((int)mode);
}

void COpenGraph_Cli::SetWindowSize(int cx, int cy)
{
    m_pOpenGraph->SetWindowSize(cx, cy);
}

void COpenGraph_Cli::Render()
{
    m_pOpenGraph->Render();
}

void COpenGraph_Cli::ForceRender()
{
    m_pOpenGraph->ForceRender();
}

void COpenGraph_Cli::ShowAxes(bool bShow)
{
    m_pOpenGraph->ShowAxes(bShow);
}

int COpenGraph_Cli::OnLButtonDown(CRect_Cli^% rect, UINT nFlags, CPoint_Cli^ point)
{
    RECT rectTemp;
    POINT pointTemp;
    pointTemp.x = point->X;
    pointTemp.y = point->Y;
    int iReturn = m_pOpenGraph->OnLButtonDown(rectTemp, nFlags, pointTemp) == TRUE;
    rect->left = rectTemp.left;
    rect->right = rectTemp.right;
    rect->top = rectTemp.top;
    rect->bottom = rectTemp.bottom;
    return iReturn;

}

void COpenGraph_Cli::OnMouseMove(UINT nFlags, CPoint_Cli^ point)
{
    POINT pointTemp;
    pointTemp.x = point->X;
    pointTemp.y = point->Y;
    m_pOpenGraph->OnMouseMove(nFlags, pointTemp);
}

IntPtr COpenGraph_Cli::GetModeCursor()
{
    HCURSOR hCursor = m_pOpenGraph->GetModeCursor();
    return (IntPtr)hCursor;
}

void COpenGraph_Cli::OnSetCursor()
{
    m_pOpenGraph->OnSetCursor();
}

void COpenGraph_Cli::Rotate(double fRx, double fRy, double fRz)
{
    m_pOpenGraph->Rotate(fRx, fRy, fRz);
}

bool COpenGraph_Cli::TrackRect(IntPtr hWndPtr, CPoint_Cli^ point)
{
    // TODO
    return true;
    //HWND hWnd = (HWND)hWndPtr.ToInt32(); // jxu: for debugging, I have to to this
    //return m_pOpenGraph->TrackRect(hWnd, point);
}

CRect_Cli^ COpenGraph_Cli::GetTrackRect()
{
    CRect_Cli^ rect = gcnew CRect_Cli();
    return rect;
    RECT rectTemp = m_pOpenGraph->GetTrackRect();
    rect->left = rectTemp.left;
    rect->right = rectTemp.right;
    rect->top = rectTemp.top;
    rect->bottom = rectTemp.bottom;
    return rect;
}

void COpenGraph_Cli::Clear()
{
    m_pOpenGraph->Clear();
}

void COpenGraph_Cli::SelectAll()
{
    m_pOpenGraph->SelectAll();
}

void COpenGraph_Cli::UnSelectAll()
{
    m_pOpenGraph->UnSelectAll();
}

void COpenGraph_Cli::ReverseSelectAll()
{
    m_pOpenGraph->ReverseSelectAll();
}

CIdentity_Cli^ COpenGraph_Cli::AddNode(int id,CPointf_Cli^ pt, int nSize, CColor_Cli^ color,CColor_Cli^ colorSelected, int nStatus, String^ tag, String^ userData)
{
    CPointf ptTemp(pt->X, pt->Y, pt->Z);
    COLORREF colorTemp = RGB(color->R, color->G, color->B);
    COLORREF colorSelectedTemp = RGB(colorSelected->R, colorSelected->G, colorSelected->B);
    CString strTag = cgiConvertString(tag);
    CString strUserData = cgiConvertString(userData);
    CIdentity identity = m_pOpenGraph->AddNode(id, ptTemp, nSize, colorTemp, colorSelectedTemp, nStatus, strTag, strUserData);
    CIdentity_Cli^ pIdentity = gcnew CIdentity_Cli();
    pIdentity->uid = gcnew String(identity.uid);
    pIdentity->id = identity.id;
    return pIdentity;
}

void COpenGraph_Cli::AddNodes(List<CIdentity_Cli^>^% listIdentity, List<int>^ listId, List<CPointf_Cli^>^ listPt, int nSize, CColor_Cli^ color,CColor_Cli^ colorSelected, int nStatus, String^ tag, String^ userData )
{
    if(listId->Count != listPt->Count)
    {
        throw gcnew Exception("The number of ids and points must be equal");
    }

    if(listId->Count == 0)
    {
        return;
    }
    
    int nNodes = listId->Count;
    CIdentity* pIdentity = new CIdentity[nNodes];
    int* pId = new int[nNodes];
    CPointf* pPt = new CPointf[nNodes];
    for(int i = 0; i < nNodes; i++)
    {
        pId[i] = listId[i];
        CPointf_Cli^ ptTemp = listPt[i];
        pPt[i] = CPointf(ptTemp->X, ptTemp->Y, ptTemp->Z);
    }
    COLORREF colorTemp = RGB(color->R, color->G, color->B);
    COLORREF colorSelectedTemp = RGB(colorSelected->R, colorSelected->G, colorSelected->B);
    CString strTag = cgiConvertString(tag);
    CString strUserData = cgiConvertString(userData);
    m_pOpenGraph->AddNodes(pIdentity, pId, pPt, nNodes,nSize, colorTemp, colorSelectedTemp, nStatus, strTag, strUserData );
    for(int i = 0; i < nNodes; i++)
    {
        const CIdentity& identity = pIdentity[i];
        CIdentity_Cli^ item = gcnew CIdentity_Cli();
        item->uid = gcnew String(identity.uid);
        item->id = identity.id;
        listIdentity->Add(item);
    }
    delete []pIdentity;
    delete []pId;
    delete []pPt;

}


CIdentity_Cli^ COpenGraph_Cli::AddLine(int id,CPointf_Cli^ pt1,CPointf_Cli^ pt2, int nThickness, CColor_Cli^ color,CColor_Cli^ colorSelected, int nStatus, String^ tag, String^ userData )
{
    CPointf pt1Temp(pt1->X, pt1->Y, pt1->Z);
    CPointf pt2Temp(pt2->X, pt2->Y, pt2->Z);
    COLORREF colorTemp = RGB(color->R, color->G, color->B);
    COLORREF colorSelectedTemp = RGB(colorSelected->R, colorSelected->G, colorSelected->B);
    CString strTag = cgiConvertString(tag);
    CString strUserData = cgiConvertString(userData);
    CIdentity identity = m_pOpenGraph->AddLine(id, pt1Temp,pt2Temp, nThickness, colorTemp, colorSelectedTemp, nStatus, strTag, strUserData);
    CIdentity_Cli^ pIdentity = gcnew CIdentity_Cli();
    pIdentity->uid = gcnew String(identity.uid);
    pIdentity->id = identity.id;
    return pIdentity;
}

void COpenGraph_Cli::AddLines(List<CIdentity_Cli^>^% listIdentity, List<int>^ listId, List<CPointf_Cli^>^ listPt1,List<CPointf_Cli^>^ listPt2, int nThickness, CColor_Cli^ color,CColor_Cli^ colorSelected, int nStatus, String^ tag, String^ userData )
{
    if(listId->Count != listPt1->Count || listId->Count != listPt2->Count)
    {
        throw gcnew Exception("The number of ids and points must be equal");
    }

    if(listId->Count == 0)
    {
        return;
    }

    int nLines = listId->Count;
    CIdentity* pIdentity = new CIdentity[nLines];
    int* pId = new int[nLines];
    CPointf* pPt1 = new CPointf[nLines];
    CPointf* pPt2 = new CPointf[nLines];
    for(int i = 0; i < nLines; i++)
    {
        pId[i] = listId[i];
        CPointf_Cli^ ptTemp1 = listPt1[i];
        pPt1[i] = CPointf(ptTemp1->X, ptTemp1->Y, ptTemp1->Z);
        CPointf_Cli^ ptTemp2 = listPt2[i];
        pPt2[i] = CPointf(ptTemp2->X, ptTemp2->Y, ptTemp2->Z);
    }
    COLORREF colorTemp = RGB(color->R, color->G, color->B);
    COLORREF colorSelectedTemp = RGB(colorSelected->R, colorSelected->G, colorSelected->B);
    CString strTag = cgiConvertString(tag);
    CString strUserData = cgiConvertString(userData);
    m_pOpenGraph->AddLines(pIdentity, pId, pPt1, pPt2, nLines, nThickness, colorTemp, colorSelectedTemp, nStatus, strTag, strUserData );
    for(int i = 0; i < nLines; i++)
    {
        const CIdentity& identity = pIdentity[i];
        CIdentity_Cli^ item = gcnew CIdentity_Cli();
        item->uid = gcnew String(identity.uid);
        item->id = identity.id;
        listIdentity->Add(item);
    }
    delete []pIdentity;
    delete []pId;
    delete []pPt1;
    delete []pPt2;
}

CIdentity_Cli^ COpenGraph_Cli::AddTriangle(int id,CPointf_Cli^ pt1,CPointf_Cli^ pt2,CPointf_Cli^ pt3, CColor_Cli^ color,CColor_Cli^ colorSelected, float alpha, int nStatus, String^ tag, String^ userData )
{
    CPointf pt1Temp(pt1->X, pt1->Y, pt1->Z);
    CPointf pt2Temp(pt2->X, pt2->Y, pt2->Z);
    CPointf pt3Temp(pt3->X, pt3->Y, pt3->Z);
    COLORREF colorTemp = RGB(color->R, color->G, color->B);
    COLORREF colorSelectedTemp = RGB(colorSelected->R, colorSelected->G, colorSelected->B);
    CString strTag = cgiConvertString(tag);
    CString strUserData = cgiConvertString(userData);
    CIdentity identity = m_pOpenGraph->AddTriangle(id, pt1Temp,pt2Temp,pt3Temp, colorTemp, colorSelectedTemp,alpha, nStatus, strTag, strUserData);
    CIdentity_Cli^ pIdentity = gcnew CIdentity_Cli();
    pIdentity->uid = gcnew String(identity.uid);
    pIdentity->id = identity.id;
    return pIdentity;
}

void COpenGraph_Cli::AddTriangles(List<CIdentity_Cli^>^% listIdentity,List<int>^ listId, List<CPointf_Cli^>^ listPt1,List<CPointf_Cli^>^ listPt2, List<CPointf_Cli^>^ listPt3, CColor_Cli^ color,CColor_Cli^ colorSelected,float alpha, int nStatus, String^ tag, String^ userData )
{
    if(listId->Count != listPt1->Count || listId->Count != listPt2->Count || listId->Count != listPt3->Count)
    {
        throw gcnew Exception("The number of ids and points must be equal");
    }

    if(listId->Count == 0)
    {
        return;
    }

    int nTriangles = listId->Count;
    CIdentity* pIdentity = new CIdentity[nTriangles];
    int* pId = new int[nTriangles];
    CPointf* pPt1 = new CPointf[nTriangles];
    CPointf* pPt2 = new CPointf[nTriangles];
    CPointf* pPt3 = new CPointf[nTriangles];
    for(int i = 0; i < nTriangles; i++)
    {
        pId[i] = listId[i];
        CPointf_Cli^ ptTemp1 = listPt1[i];
        pPt1[i] = CPointf(ptTemp1->X, ptTemp1->Y, ptTemp1->Z);
        CPointf_Cli^ ptTemp2 = listPt2[i];
        pPt2[i] = CPointf(ptTemp2->X, ptTemp2->Y, ptTemp2->Z);
        CPointf_Cli^ ptTemp3 = listPt3[i];
        pPt3[i] = CPointf(ptTemp3->X, ptTemp3->Y, ptTemp3->Z);
    }
    COLORREF colorTemp = RGB(color->R, color->G, color->B);
    COLORREF colorSelectedTemp = RGB(colorSelected->R, colorSelected->G, colorSelected->B);
    CString strTag = cgiConvertString(tag);
    CString strUserData = cgiConvertString(userData);
    m_pOpenGraph->AddTriangles(pIdentity, pId, pPt1, pPt2,pPt3, nTriangles, colorTemp, colorSelectedTemp, alpha, nStatus, strTag, strUserData );
    for(int i = 0; i < nTriangles; i++)
    {
        const CIdentity& identity = pIdentity[i];
        CIdentity_Cli^ item = gcnew CIdentity_Cli();
        item->uid = gcnew String(identity.uid);
        item->id = identity.id;
        listIdentity->Add(item);
    }
    delete []pIdentity;
    delete []pId;
    delete []pPt1;
    delete []pPt2;
    delete []pPt3;
}

CIdentity_Cli^ COpenGraph_Cli::AddQuad(int id,CPointf_Cli^ pt1,CPointf_Cli^ pt2,CPointf_Cli^ pt3,CPointf_Cli^ pt4, CColor_Cli^ color,CColor_Cli^ colorSelected, float alpha, int nStatus, String^ tag, String^ userData )
{
    CPointf pt1Temp(pt1->X, pt1->Y, pt1->Z);
    CPointf pt2Temp(pt2->X, pt2->Y, pt2->Z);
    CPointf pt3Temp(pt3->X, pt3->Y, pt3->Z);
    CPointf pt4Temp(pt4->X, pt4->Y, pt4->Z);
    COLORREF colorTemp = RGB(color->R, color->G, color->B);
    COLORREF colorSelectedTemp = RGB(colorSelected->R, colorSelected->G, colorSelected->B);
    CString strTag = cgiConvertString(tag);
    CString strUserData = cgiConvertString(userData);
    CIdentity identity = m_pOpenGraph->AddQuad(id, pt1Temp,pt2Temp, pt3Temp, pt4Temp, colorTemp, colorSelectedTemp,alpha, nStatus, strTag, strUserData);
    CIdentity_Cli^ pIdentity = gcnew CIdentity_Cli();
    pIdentity->uid = gcnew String(identity.uid);
    pIdentity->id = identity.id;
    return pIdentity;

}

void COpenGraph_Cli::AddQuads(List<CIdentity_Cli^>^% listIdentity,List<int>^ listId, List<CPointf_Cli^>^ listPt1,List<CPointf_Cli^>^ listPt2, List<CPointf_Cli^>^ listPt3,List<CPointf_Cli^>^ listPt4, CColor_Cli^ color,CColor_Cli^ colorSelected,float alpha, int nStatus, String^ tag, String^ userData )
{
    if(listId->Count != listPt1->Count || listId->Count != listPt2->Count || 
        listId->Count != listPt3->Count || listId->Count != listPt4->Count)
    {
        throw gcnew Exception("The number of ids and points must be equal");
    }

    if(listId->Count == 0)
    {
        return;
    }

    int nQuads = listId->Count;
    CIdentity* pIdentity = new CIdentity[nQuads];
    int* pId = new int[nQuads];
    CPointf* pPt1 = new CPointf[nQuads];
    CPointf* pPt2 = new CPointf[nQuads];
    CPointf* pPt3 = new CPointf[nQuads];
    CPointf* pPt4 = new CPointf[nQuads];
    for(int i = 0; i < nQuads; i++)
    {
        pId[i] = listId[i];
        CPointf_Cli^ ptTemp1 = listPt1[i];
        pPt1[i] = CPointf(ptTemp1->X, ptTemp1->Y, ptTemp1->Z);
        CPointf_Cli^ ptTemp2 = listPt2[i];
        pPt2[i] = CPointf(ptTemp2->X, ptTemp2->Y, ptTemp2->Z);
        CPointf_Cli^ ptTemp3 = listPt3[i];
        pPt3[i] = CPointf(ptTemp3->X, ptTemp3->Y, ptTemp3->Z);
        CPointf_Cli^ ptTemp4 = listPt4[i];
        pPt4[i] = CPointf(ptTemp4->X, ptTemp4->Y, ptTemp4->Z);
    }
    COLORREF colorTemp = RGB(color->R, color->G, color->B);
    COLORREF colorSelectedTemp = RGB(colorSelected->R, colorSelected->G, colorSelected->B);
    CString strTag = cgiConvertString(tag);
    CString strUserData = cgiConvertString(userData);
    m_pOpenGraph->AddQuads(pIdentity, pId, pPt1, pPt2,pPt3, pPt4, nQuads, colorTemp, colorSelectedTemp,alpha, nStatus, strTag, strUserData );
    for(int i = 0; i < nQuads; i++)
    {
        const CIdentity& identity = pIdentity[i];
        CIdentity_Cli^ item = gcnew CIdentity_Cli();
        item->uid = gcnew String(identity.uid);
        item->id = identity.id;
        listIdentity->Add(item);
    }
    delete []pIdentity;
    delete []pId;
    delete []pPt1;
    delete []pPt2;
    delete []pPt3;
    delete []pPt4;
}


int COpenGraph_Cli::AddFont(String^ typeface, int height, int weight, DWORD italic)
{
    CString strTypeface = cgiConvertString(typeface);
    return m_pOpenGraph->AddFont(strTypeface, height, weight, italic);
}

CIdentity_Cli^ COpenGraph_Cli::AddText(int id, int nFontId, CPointf_Cli^ pt, String^ text, CColor_Cli^ color,CColor_Cli^ colorSelected, int nAlignment, int nStatus)
{
    CPointf ptTemp;
    ptTemp.xyz[0] = pt->X;
    ptTemp.xyz[1] = pt->Y;
    ptTemp.xyz[2] = pt->Z;
    COLORREF colorTemp = RGB(color->R, color->G, color->B);
    COLORREF colorSelectedTemp = RGB(colorSelected->R, colorSelected->G, colorSelected->B);
    CString strText = cgiConvertString(text);
    CIdentity identity = m_pOpenGraph->AddText(id, nFontId, ptTemp, strText, colorTemp, colorSelectedTemp, nAlignment, nStatus);
    CIdentity_Cli^ pIdentity = gcnew CIdentity_Cli();
    pIdentity->uid = gcnew String(identity.uid);
    pIdentity->id = identity.id;
    return pIdentity;
}

