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

#include "OpenGraphDefines.h"

namespace NSOpenGraphLib
{

const int CONVEX = 1;
const int CONCAVE = -1;
const int INCOMPUTABLE = 0;
const double gEpsilon = 0.0000005;
const double gDeg2Rad = 0.017453293;
const double gRad2Deg = 57.29577951;

class CMathHelper
{
public:
    static bool is_equal(double val1, double val2, double epsilon = gEpsilon);
    static double calc_angle(CPointf pt1, CPointf pt2);
    static double CalcSignedAngle2D(const CPointf& v1, const CPointf& v2);
    static double calc_distance(CPointf pt1, CPointf pt2);
    static double calc_distance(CPointf pt, CPointf pt1, CPointf pt2);
    static double calc_distance2(CPointf& ptInt, double& u, CPointf pt1, CPointf pt2, CPointf pt3);
    static bool calc_distance3( double& Distance, CPointf Point, CPointf LineStart, CPointf LineEnd);
    static void subtract_points(CPointf* pt, int nPts, CPointf pt0);
    static double  _area(CPointf a, CPointf b, CPointf c);
    static double area(CPointf* pts, int n);
    static int inpolygon(const CPointf *polygon, int N, CPointf p);
    static int onpolygon(const CPointf *polygon, int N, CPointf pt, double tol);
    static int test_convex(CPointf *p, int n);
    static void normalize(CPointf& v);
    static double dot(CPointf pt1, CPointf pt2);
    static void cross(CPointf& out, CPointf v1, CPointf v2);
    static double square_distance(CPointf pt1, CPointf pt2);
    static bool is_parallel(CPointf v1, CPointf v2);
    static bool is_parallel_two_ways(CPointf v1, CPointf v2);
    static bool is_rectangle(CPointf pt1,CPointf pt2,CPointf pt3,CPointf pt4);
    static void normal(CPointf& vNormal, CPointf pt1, CPointf pt2, CPointf pt3);
    static CPointf scalePoint(const CPointf& pt1, double f);
    static bool inward(CPointf pt1, CPointf pt2, CPointf pt3, CPointf pt);
    static bool inbox(CPointf w[8], CPointf pt);
    static bool inbox(CPointf w[8], CPointf pt[], int nNds);
    static bool incube(CPointf ptMin, CPointf ptMax, CPointf pt);
    static bool incube(CPointf ptMin, CPointf ptMax, CPointf pt[], int nNds);
    static void pt_interpolate(CPointf& pt, const CPointf& pt1, const CPointf& pt2, double fRatio);
    static void transform_point(CPointf* pt, double R[3][3]);
    static void extend_point(CPointf* ptOut, CPointf ptBase, CPointf ptDirection, double fLen);
    static void extend_point(CPointf* ptOut, CPointf ptBase, CPointf ptX, CPointf ptY, double fDeltaX, double fDeltaY);
    static bool perperdicularPtPointSegment(const CPointf& c, const CPointf& a, const CPointf& b, double &t, CPointf &d);
    static double clamp(double n, double min, double max) ;
    static double closestPtSegmentSegment(const CPointf& p1, const CPointf& q1, const CPointf& p2, const CPointf& q2,double &s, double &t, CPointf &c1, CPointf &c2);
    static void rotate(CPointf pt[], int nPts, double fAngle, int nDirection);
    static CPointf arbitrary_rotate(CPointf p, double theta, CPointf r);
    static int clipTest (double p, double q, double * u1, double * u2);
    static bool clipLine (POINT winMin, POINT winMax, CPointf p1, CPointf p2);
    static void calc_cos(double mRot[3][3], CPointf vAxis[3]);
    static void cos_matrix(double* mRot, double mRot1[3][3], int nSize);

    static void NormalizeRect( RECT &rectTrack );
    static int GetRectWidth(const RECT& rect);
    static int GetRectHeight(const RECT& rect);
    static POINT GetCenterPoint(const RECT& rect);
    static bool PtInRect(RECT rect, int x, int y);

};

}