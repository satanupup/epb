////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2002-2013 Computations & Graphics, Inc. 
// 
// All rights reserved.
//
// Author: Junlin Xu
//
//////////////////////////////////////////////////////////////////////////

#pragma  once
#pragma warning(disable: 4996)


#include "OpenGraphLib.h"

namespace NSOpenGraphLib
{

enum {X=0, Y, Z, OX, OY, OZ};
enum {kSelect, kUnselect, kReverseSelect};

const int STATUS_UNSELECTED = 0x000000000L;
const int STATUS_SELECTED = 0x00000001L;
const int STATUS_FREEZED = 0x00000002L;

struct OPENGRAPHLIB_API CPointf
{
    CPointf(double x = 0, double y = 0, double z = 0) {
        xyz[X] = x;
        xyz[Y] = y;
        xyz[Z] = z;
    }
    double xyz[3];
};

OPENGRAPHLIB_API CPointf operator+(const CPointf& pt1, const CPointf& pt2);
OPENGRAPHLIB_API CPointf operator-(const CPointf& pt1, const CPointf& pt2);
OPENGRAPHLIB_API CPointf operator*(const CPointf& pt, double factor);
OPENGRAPHLIB_API CPointf operator/(const CPointf& pt, double factor);


const CPointf gOrigin(0, 0, 0);
const CPointf gGlobalX(1, 0, 0);
const CPointf gGlobalY(0, 1, 0);
const CPointf gGlobalZ(0, 0, 1);
const CPointf gGlobalAxes[3] = {gGlobalX, gGlobalY, gGlobalZ};

const TCHAR gstrSymbol[] = _T("symbol");
const TCHAR gstrX[] = _T("X");
const TCHAR gstrY[] = _T("Y");
const TCHAR gstrZ[] = _T("Z");
const TCHAR gstrArial[] = _T("Arial");

const int ALIGN_LEFT =      0x00000001L;
const int ALIGN_CENTER =    0x00000002L;
const int ALIGN_RIGHT =     0x00000004L;
const int ALIGN_TOP	 =      0x00000008L;
const int ALIGN_BOTTOM =    0x00000010L;
const int ABOVE	=           0x00000020L;
const int BELOW	=           0x00000040L;
const int ALIGN_TOP2 =      0x00000080L;
const int BELOW2 =          0x00000100L;
const int BELOW3 =	        0x00000200L;
const int BELOW4 =		    0x00000400L;


struct OPENGRAPHLIB_API CBoundingBox
{
    CBoundingBox()
    {
        ptMin.xyz[X] = ptMin.xyz[Y] = ptMin.xyz[Z] = 0.;
        ptMax.xyz[X] = ptMax.xyz[Y] = ptMax.xyz[Z] = 0.;
    }
    CPointf ptMin;
    CPointf ptMax;
};

const int MAX_UID_SIZE = 20;
struct OPENGRAPHLIB_API CIdentity
{
    CIdentity()
    {
        uid[0] = _T('\0');
        id = 0;
    }

    TCHAR uid[MAX_UID_SIZE];
    int id;
};

// jxu: the size of strDest should be (count+1)
void SaftStrncpy(TCHAR *szDest, const TCHAR *szSource, size_t count);
}