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

using namespace System;
using namespace System::Text;
using namespace System::Diagnostics;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;

class NSOpenGraphLib::COpenGraph;   // forward declaration

#include "OpenGraphDefines_Cli.h"

namespace NSOpenGraphLib_Cli {

    public ref class COpenGraph_Cli
    {
    public:
        enum class Mode {modeNONE = -1,modeTRACK, modeROTATE };
        enum class ButtonFlag {flagMK_LBUTTON = 0x0001, flagMK_RBUTTON = 0x0002,    // from WinUser.h
                                flagMK_SHIFT =  0x0004, flagMK_CONTROL = 0x0008, flagMK_MBUTTON = 0x0010};

    public:
        COpenGraph_Cli(void);
        bool Initialize(IntPtr hWndPtr);
        void SetMode(Mode mode);
        void SetWindowSize(int cx, int cy);
        void Render();
        void ForceRender();
        void ShowAxes(bool bShow);

        int OnLButtonDown(CRect_Cli^% rect, UINT nFlags, CPoint_Cli^ point);
        void OnMouseMove(UINT nFlags, CPoint_Cli^ point);
        IntPtr GetModeCursor();
        void OnSetCursor();

        void Rotate(double fRx, double fRy, double fRz);
 
        bool TrackRect(IntPtr hWndPtr, CPoint_Cli^ point);
        CRect_Cli^ GetTrackRect(); // un-normalized

        void Clear();

        void SelectAll();
        void UnSelectAll();
        void ReverseSelectAll();
        
        CIdentity_Cli^ AddNode(int id,CPointf_Cli^ pt, int nSize, CColor_Cli^ color,CColor_Cli^ colorSelected, int nStatus, String^ tag, String^ userData);
        void AddNodes(List<CIdentity_Cli^>^% listIdentity, List<int>^ listId, List<CPointf_Cli^>^ listPt, int nSize, CColor_Cli^ color,CColor_Cli^ colorSelected, int nStatus, String^ tag, String^ userData );

        CIdentity_Cli^ AddLine(int id,CPointf_Cli^ pt1,CPointf_Cli^ pt2, int nThickness, CColor_Cli^ color,CColor_Cli^ colorSelected, int nStatus, String^ tag, String^ userData );
        void AddLines(List<CIdentity_Cli^>^% listIdentity, List<int>^ listId, List<CPointf_Cli^>^ listPt1,List<CPointf_Cli^>^ listPt2, int nThickness, CColor_Cli^ color,CColor_Cli^ colorSelected, int nStatus, String^ tag, String^ userData );

        CIdentity_Cli^ AddTriangle(int id,CPointf_Cli^ pt1,CPointf_Cli^ pt2,CPointf_Cli^ pt3, CColor_Cli^ color,CColor_Cli^ colorSelected, float alpha, int nStatus, String^ tag, String^ userData );
        void AddTriangles(List<CIdentity_Cli^>^% listIdentity,List<int>^ listId, List<CPointf_Cli^>^ listPt1,List<CPointf_Cli^>^ listPt2, List<CPointf_Cli^>^ listPt3, CColor_Cli^ color,CColor_Cli^ colorSelected,float alpha, int nStatus, String^ tag, String^ userData );

        CIdentity_Cli^ AddQuad(int id,CPointf_Cli^ pt1,CPointf_Cli^ pt2,CPointf_Cli^ pt3,CPointf_Cli^ pt4, CColor_Cli^ color,CColor_Cli^ colorSelected, float alpha, int nStatus, String^ tag, String^ userData );
        void AddQuads(List<CIdentity_Cli^>^% listIdentity,List<int>^ listId, List<CPointf_Cli^>^ listPt1,List<CPointf_Cli^>^ listPt2, List<CPointf_Cli^>^ listPt3,List<CPointf_Cli^>^ listPt4, CColor_Cli^ color,CColor_Cli^ colorSelected,float alpha, int nStatus, String^ tag, String^ userData );

        int AddFont(String^ typeface, int height, int weight, DWORD italic);
        CIdentity_Cli^ AddText(int id, int nFontId, CPointf_Cli^ pt, String^ text, CColor_Cli^ color,CColor_Cli^ colorSelected, int nAlignment, int nStatus);
       
    private:
        NSOpenGraphLib::COpenGraph* m_pOpenGraph;
    };


}
