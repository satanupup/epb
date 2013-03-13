////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2002-2013 Computations & Graphics, Inc. 
// 
// All rights reserved.
//
// Author: Junlin Xu
//
//////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <cmath>
#include <vector>
using namespace std;
#include "matrix.h"
#include "OpenGraphDefines.h"
#include "MathHelper.h"


namespace NSOpenGraphLib
{
    bool CMathHelper::is_equal(double val1, double val2, double epsilon)
    {
        if(fabs(val1 - val2) <= fabs(val1 + val2) * epsilon)
        {
            return true;
        }
        return false;
    }

    // distance of two points (3-d)
    double CMathHelper::calc_distance(CPointf pt1, CPointf pt2)
    {
        double deltaX = pt2.xyz[X] - pt1.xyz[X];
        double deltaY = pt2.xyz[Y] - pt1.xyz[Y];
        double deltaZ = pt2.xyz[Z] - pt1.xyz[Z];
        return sqrt (deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ);
    }


    // distance between a point and a line
    double CMathHelper::calc_distance(CPointf pt, CPointf pt1, CPointf pt2)
    {
        double dist = 0;

        double a = calc_distance(pt, pt2);
        double b = calc_distance(pt, pt1);
        if(a == 0. || b == 0.) {
            return 0.;
        }
        double c = calc_distance(pt1, pt2);
        if(c == 0.)	{
            return a;
        }
        double cos_a = (b * b + c * c - a * a) / (2. * b * c);
        double sin_a = sqrt(1 - cos_a * cos_a);
        dist = b * sin_a;
        return dist;
    }


    // 2D
    // Minimum Distance between Point (pt3) and a Line (pt1 - pt2)
    // (P3 - P) dot (P2 - P1) = 0 
    // If the distance of the point to a line segment is required then it is only necessary to
    // test that u lies between 0 and 1. 
    double CMathHelper::calc_distance2(CPointf& ptInt, double& u, CPointf pt1, CPointf pt2, CPointf pt3)
    {
        u = (pt3.xyz[X] - pt1.xyz[X]) * (pt2.xyz[X] - pt1.xyz[X])  
            + (pt3.xyz[Y] - pt1.xyz[Y]) * (pt2.xyz[Y] - pt1.xyz[Y]);
        double denom = (pt2.xyz[X] - pt1.xyz[X]) * (pt2.xyz[X] - pt1.xyz[X])  
            + (pt2.xyz[Y] - pt1.xyz[Y]) * (pt2.xyz[Y] - pt1.xyz[Y]);
        if(denom ==  0)	{
            u = 0;	// p1 and p2 coincide
        }
        else {
            u /= denom;
        }

        ptInt.xyz[X] = pt1.xyz[X] + u * (pt2.xyz[X] - pt1.xyz[X]);
        ptInt.xyz[Y] = pt1.xyz[Y] + u * (pt2.xyz[Y] - pt1.xyz[Y]);

        return calc_distance(ptInt, pt3);

    }


    void CMathHelper::subtract_points(CPointf* pt, int nPts, CPointf pt0)
    {
        for(int i = 0; i < nPts; i++) {
            pt[i].xyz[X] -= pt0.xyz[X];
            pt[i].xyz[Y] -= pt0.xyz[Y];
            pt[i].xyz[Z] -= pt0.xyz[Z];
        }
    }

    void CMathHelper::normalize(CPointf& v)
    {
        double d = sqrt(v.xyz[X] * v.xyz[X] + v.xyz[Y] * v.xyz[Y] + v.xyz[Z] * v.xyz[Z]);
        v.xyz[X] /= d;
        v.xyz[Y] /= d;
        v.xyz[Z] /= d;
    }


    // dot product of two vectors
    double CMathHelper::dot(CPointf pt1, CPointf pt2)
    {
        return pt1.xyz[X] * pt2.xyz[X] + pt1.xyz[Y] * pt2.xyz[Y] + pt1.xyz[Z] * pt2.xyz[Z];
    }


    // cross product of two vectors
    void CMathHelper::cross(CPointf& out, CPointf v1, CPointf v2)
    {
        out.xyz[X] = v1.xyz[Y] * v2.xyz[Z] - v1.xyz[Z] * v2.xyz[Y];
        out.xyz[Y] = v1.xyz[Z] * v2.xyz[X] - v1.xyz[X] * v2.xyz[Z];
        out.xyz[Z] = v1.xyz[X] * v2.xyz[Y] - v1.xyz[Y] * v2.xyz[X];
    }


    // square of distance of two points (3-d) - jxu: for efficency only
    double CMathHelper::square_distance(CPointf pt1, CPointf pt2)
    {
        return (pt2.xyz[X] - pt1.xyz[X]) * (pt2.xyz[X] - pt1.xyz[X])  + 
            (pt2.xyz[Y] - pt1.xyz[Y]) * (pt2.xyz[Y] - pt1.xyz[Y]) +
            (pt2.xyz[Z] - pt1.xyz[Z]) * (pt2.xyz[Z] - pt1.xyz[Z]);
    }


    // check to see if two vectors are parallel
    bool CMathHelper::is_parallel(CPointf v1, CPointf v2)
    {
        normalize(v1);
        normalize(v2);
        return (is_equal(v1.xyz[X], v2.xyz[X]) &&
            is_equal(v1.xyz[Y], v2.xyz[Y]) &&
            is_equal(v1.xyz[Z], v2.xyz[Z]));
    }

    // check to see if two vectors are parallel
    bool CMathHelper::is_parallel_two_ways(CPointf v1, CPointf v2)
    {
        CPointf v3 = CPointf(0, 0, 0) - v2;
        return is_parallel(v1, v2) || is_parallel(v1, v3);
    }

    // pt1, pt2, pt3 should be in counter clockwise order
    void CMathHelper::normal(CPointf& vNormal, CPointf pt1, CPointf pt2, CPointf pt3)
    {
        CPointf v1, v2;
        v1 = pt3 - pt2;
        v2 = pt1 - pt2;
        cross(vNormal, v1, v2);
    }

    CPointf CMathHelper::scalePoint(const CPointf& pt1, double f)
    {
        CPointf pt;
        pt.xyz[X] = pt1.xyz[X] * f;
        pt.xyz[Y] = pt1.xyz[Y] * f;
        pt.xyz[Z] = pt1.xyz[Z] * f;
        return pt;
    }

    void CMathHelper::pt_interpolate(CPointf& pt, const CPointf& pt1, const CPointf& pt2, double fRatio)
    {
        pt.xyz[X] = pt1.xyz[X] + (pt2.xyz[X] - pt1.xyz[X]) * fRatio;
        pt.xyz[Y] = pt1.xyz[Y] + (pt2.xyz[Y] - pt1.xyz[Y]) * fRatio;
        pt.xyz[Z] = pt1.xyz[Z] + (pt2.xyz[Z] - pt1.xyz[Z]) * fRatio;
    }


    void CMathHelper::transform_point(CPointf* pt, double R[3][3])
    {
        CPointf pt0 = *pt;
        pt->xyz[X] = pt0.xyz[X] * R[X][X] + pt0.xyz[Y] * R[X][Y] + pt0.xyz[Z] * R[X][Z];
        pt->xyz[Y] = pt0.xyz[X] * R[Y][X] + pt0.xyz[Y] * R[Y][Y] + pt0.xyz[Z] * R[Y][Z];
        pt->xyz[Z] = pt0.xyz[X] * R[Z][X] + pt0.xyz[Y] * R[Z][Y] + pt0.xyz[Z] * R[Z][Z];
    }

    // rotate about X or Y or Z axis, fAngle is of radian
    void CMathHelper::rotate(CPointf pt[], int nPts, double fAngle, int nDirection)
    {
        if(fAngle == 0.) {return;}

        double rot[3][3];
        mat_zero(&rot[0][0], 2, 2, 0);
        double fcos = cos(fAngle);
        double fsin = sin(fAngle);
        if(fabs(fcos) < gEpsilon){
            fcos = 0;
        }
        if(fabs(fsin) < gEpsilon) {
            fsin = 0;
        }

        if(nDirection == X)	{
            rot[0][0] = 1.0;
            rot[1][1] = fcos;
            rot[1][2] = -fsin;
            rot[2][1] = fsin;
            rot[2][2] = fcos;
        }
        else if(nDirection == Y) {
            rot[0][0] = fcos;
            rot[0][2] = fsin;
            rot[1][1] = 1.0;
            rot[2][0] = -fsin;
            rot[2][2] = fcos;
        }
        else {	// default to Z
            rot[0][0] = fcos;
            rot[0][1] = -fsin;
            rot[1][0] = fsin;
            rot[1][1] = fcos;
            rot[2][2] = 1.0;
        }

        for (int i = 0; i < nPts; i++) {
            CPointf ptTemp = pt[i];
            mat_mul(pt[i].xyz, &rot[0][0], ptTemp.xyz, 2, 2, 0, 0);
        }

    }	// void rotate(CPointf pt[], int nPts, double fAngle, int nDirection)

    void CMathHelper::calc_cos(double mRot[3][3], CPointf vAxis[3])
    {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                mRot[i][j] = vAxis[i].xyz[j];
            }	// for(int j = 0; j < 3; j++)
        }	// for(int i = 0; i < 3; i++)

    }


    void CMathHelper::cos_matrix(double* mRot, double mRot1[3][3], int nSize)
    {
        for(int i = 0; i < nSize; i++) {
            for(int j = 0; j < nSize; j++) {
                int ij = i * nSize + j;
                bool bFlag = false;
                for(int k = 0; k < nSize / 3; k++) {
                    if(i >= k * 3 && i <= k * 3 + 2 && j >= k * 3 && j <= k * 3 + 2) {	///
                        bFlag = true;
                        break;
                    }
                }

                if(bFlag) {
                    mRot[ij] = mRot1[i%3][j%3];
                }
                else {
                    mRot[ij] = 0.;
                }
            }	// for(int j = 0; j < nSize; j++)
        }	// for(int i = 0; i < nSize; i++)
    }

    void CMathHelper::NormalizeRect( RECT &rectTrack )
    {
        if(rectTrack.left > rectTrack.right)
        {
            int temp = rectTrack.left;
            rectTrack.left = rectTrack.right;
            rectTrack.right = temp;
        }
        if(rectTrack.top > rectTrack.bottom)
        {
            int temp = rectTrack.top;
            rectTrack.top = rectTrack.bottom;
            rectTrack.bottom = temp;
        }
    }

    POINT CMathHelper::GetCenterPoint(const RECT& rect)
    {
        POINT point;
        point.x  = (rect.left + rect.right) / 2;
        point.y = (rect.top + rect.bottom) / 2;
        return point;
    }

    int CMathHelper::GetRectWidth(const RECT& rect)
    {
        return rect.right - rect.left;
    }

    int CMathHelper::GetRectHeight(const RECT& rect)
    {
        return rect.bottom - rect.top;
    }

    bool CMathHelper::PtInRect(RECT rect, int x, int y)
    {
        return rect.left <= x && x <= rect.right &&  rect.top <= y && y <= rect.bottom;
    }


}