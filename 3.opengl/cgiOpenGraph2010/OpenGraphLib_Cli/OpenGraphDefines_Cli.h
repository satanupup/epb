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

namespace NSOpenGraphLib_Cli {
    
    public enum class CDirection {X=0, Y, Z, OX, OY, OZ};

    public ref class CPointf_Cli
    {
    public:
        CPointf_Cli(){
            X = Y = Z = 0.0;
        }
        CPointf_Cli(double x, double y, double z) {
            X = x;
            Y = y;
            Z = z;
        }
        static void Copy(CPointf_Cli^ ptDest, CPointf_Cli^ ptOrg)
        {
            ptDest->X = ptOrg->X;
            ptDest->Y = ptOrg->Y;
            ptDest->Z = ptOrg->Z;
        }
        double X;
        double Y;
        double Z;
    };


    public ref class CStatus_Cli
    {
    public:
        static const int STATUS_UNSELECTED =          0x00000000L;
        static const int STATUS_SELECTED =      0x00000001L;
        static const int STATUS_FREEZED =      0x00000002L;
    };


    public ref class CTextAlignment_Cli
    {
    public:
        static const int ALIGN_LEFT =      0x00000001L;
        static const int ALIGN_CENTER =    0x00000002L;
        static const int ALIGN_RIGHT =     0x00000004L;
        static const int ALIGN_TOP	 =      0x00000008L;
        static const int ALIGN_BOTTOM =    0x00000010L;
        static const int ABOVE	=           0x00000020L;
        static const int BELOW	=           0x00000040L;
        static const int ALIGN_TOP2 =      0x00000080L;
        static const int BELOW2 =          0x00000100L;
        static const int BELOW3 =	        0x00000200L;
        static const int BELOW4 =		    0x00000400L;
    };


    public ref class CRect_Cli
    {
    public:
        CRect_Cli(){
            left = right = top = bottom = 0;
        }
        CRect_Cli(int l, int r, int t, int b) {
            left = l;
            right = r;
            top = t;
            bottom = b;
        }
        static void Copy(CRect_Cli^ rectDest, CRect_Cli^ rectOrg)
        {
            rectDest->left = rectOrg->left;
            rectDest->right = rectOrg->right;
            rectDest->top = rectOrg->top;
            rectDest->bottom = rectOrg->bottom;
        }
        int left;
        int right;
        int top;
        int bottom;
    };

    public ref class CPoint_Cli
    {
    public:
        CPoint_Cli(){
            X = Y = 0;
        }
        CPoint_Cli(int x, int y) {
            X = x;
            Y = y;
        }
        static void Copy(CPoint_Cli^ ptDest, CPoint_Cli^ ptOrg)
        {
            ptDest->X = ptOrg->X;
            ptDest->Y = ptOrg->Y;
        }
        int X;
        int Y;
    };

    public ref class CIdentity_Cli
    {
    public:
        CIdentity_Cli()
        {
            id = 0;
            uid = nullptr;
        }
        static void Copy(CIdentity_Cli^ idDest, CIdentity_Cli^ idOrg)
        {
            idDest->uid = idOrg->uid;
            idDest->id = idOrg->id;
        }

        String^ uid;
        int id;
    };

    public ref class CColor_Cli
    {
    public:
        CColor_Cli()
        {
            R = G = B = 0;
        }
        CColor_Cli(unsigned char r, unsigned char g, unsigned char b)
        {
            R = r;
            G = g;
            B = b;
        }
        static void Copy(CColor_Cli^ colorDest, CColor_Cli^ colorOrg)
        {
            colorOrg->R = colorOrg->R;
            colorOrg->G = colorOrg->G;
            colorOrg->B = colorOrg->B;
        }
        unsigned char R;
        unsigned char G;
        unsigned char B;
    };


}