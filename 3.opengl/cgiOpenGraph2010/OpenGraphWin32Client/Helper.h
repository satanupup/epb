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


void BoxPts(CPointf pt[8], CPointf ptCenter, double fDeltaX, double fDeltaY, double fDeltaZ);
void OnViewSelectall();
void OnViewUnselectall();
void OnViewReverseselect();
void OnDrawDrawnodes();
void OnDrawDrawlines();
void OnDrawDrawtriangles();
void OnDrawDrawquads();
void OnDrawClear();
void OnModeDefault();
void OnModeTrack();
void OnModeRotate();
