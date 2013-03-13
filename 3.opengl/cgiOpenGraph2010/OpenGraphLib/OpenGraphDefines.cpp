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
#include "OpenGraphDefines.h"

namespace NSOpenGraphLib
{

CPointf operator+(const CPointf& pt1, const CPointf& pt2)
{
    CPointf pt;
    pt.xyz[X] = pt1.xyz[X] + pt2.xyz[X];
    pt.xyz[Y] = pt1.xyz[Y] + pt2.xyz[Y];
    pt.xyz[Z] = pt1.xyz[Z] + pt2.xyz[Z];
    return pt;
}

CPointf operator-(const CPointf& pt1, const CPointf& pt2)
{
    CPointf pt;
    pt.xyz[X] = pt1.xyz[X] - pt2.xyz[X];
    pt.xyz[Y] = pt1.xyz[Y] - pt2.xyz[Y];
    pt.xyz[Z] = pt1.xyz[Z] - pt2.xyz[Z];
    return pt;
}

CPointf operator*(const CPointf& pt, double factor)
{
    return CPointf (pt.xyz[X] * factor, pt.xyz[Y] * factor, pt.xyz[Z] * factor);
}

CPointf operator/(const CPointf& pt, double factor)
{
    return CPointf (pt.xyz[X] / factor, pt.xyz[Y] / factor, pt.xyz[Z] / factor);
}

void SaftStrncpy(TCHAR *szDest, const TCHAR *szSource, size_t count)
{
    _tcsnccpy(szDest, szSource, count);
    if(_tcslen(szSource) >= count) {
        szDest[count] = _T('\0');
    }
}


}