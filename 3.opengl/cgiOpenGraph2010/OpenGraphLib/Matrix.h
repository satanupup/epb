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

namespace NSOpenGraphLib
{
// jxu:  The following matrix routines are based on "Numerical Recipes"
#define ALLOC_END 1	// safety for compiler

template<class T>
T* vec_alloc(int nRowEnd, int nOffset)
{
	T* v;
	v = new T[nRowEnd + 1 - nOffset + ALLOC_END];
	return v - nOffset + ALLOC_END;
}

template<class T>
void vec_dealloc(T* v, int nOffset)
{
	if(v) {
		delete [] (v + nOffset - ALLOC_END);
	}
}

template<class T>
void vec_zero(T* v, int nRowEnd, int nOffset)
{
	for(int i = nOffset; i <= nRowEnd; i++)	{
		v[i] = 0;
	}
}


// contiguous allocation
// make a T matrix [nOffset ... nRowEnd][nOffset ... nColEnd]
// need to use mat_dealloc to free memory
template<class T>
T** mat_alloc(int nRowEnd, int nColEnd, int nOffset)
{
	int nRowStart = nOffset;
	int nColStart = nOffset;
	int nRows = nRowEnd - nRowStart + 1;
	int nCols = nColEnd - nColStart + 1;
	T** m;

	// allocate pointers to rows
	m = new T* [nRows + ALLOC_END];
	if(!m)	return NULL;
	m += ALLOC_END;
	m -= nRowStart;

	// allocate rows and set pointers to them
	m[nRowStart] = new T[nRows * nCols + ALLOC_END];
	if(!m[nRowStart]) return NULL;
	m[nRowStart] +=	ALLOC_END;
	m[nRowStart] -= nColStart;
	for(int i = nRowStart + 1; i <= nRowEnd; i++)
	{
		m[i] = m[i - 1] + nCols;
	}
	
	return m;	// return pointer to array of pointers to rows
}


// de-allocate T matrix
template<class T>
void mat_dealloc(T** m, int nOffset)
{
	if(m) {
		int nRowStart = nOffset;
		int nColStart = nOffset;
		delete [] (m[nRowStart] + nColStart - ALLOC_END);
		delete [] (m + nRowStart - ALLOC_END);
	}
}


template<class T>
void mat_zero(T* a,  int nRowEnd, int nColEnd, int nOffset)
{
	int nRows = nRowEnd + 1 - nOffset;
	int nCols = nColEnd + 1 - nOffset;
	memset(a, '\0', sizeof(T) * nRows * nCols);
	return;
}


// make every element of the matrix 0
template<class T>
void mat_zero(T** m, int nRowEnd, int nColEnd, int nOffset)
{
	mat_zero<T>(&m[nOffset][nOffset], nRowEnd, nColEnd, nOffset);
}


template<class T>
void mat_mul(T* c, const T* a,  const T* b, int nRowEnd, int nColEnd, int nColBEnd, int nOffset)
{
	int nRows = nRowEnd + 1 - nOffset;
	int nCols = nColEnd + 1 - nOffset;
	int nColBs = nColBEnd + 1 - nOffset;

	for(int i = nOffset; i < nRows; i++) {
		for(int j = nOffset; j < nColBs; j++) {
			c[i * nColBs + j] = 0;
			for(int k = nOffset; k < nCols; k++ ) {
				c[i * nColBs + j] += a[i * nCols + k] * b[k * nColBs + j];
			}
		}
	}
	return;
}


// matrix multiplication
// assuming c is allocated with size nRowEnd x nColBEnd 
template<class T>
void mat_mul(T** c, T** const a,  T** const b, 	int nRowEnd, int nColEnd, int nColBEnd, int nOffset )
{
	mat_mul<T>(&c[nOffset][nOffset], &a[0][0], &b[0][0], nRowEnd, nColEnd, nColBEnd, nOffset);
}


// transpose a matrix
template<class T>
void mat_trans(T* a,  const T* b, int nRowEnd, int nColEnd, int nOffset)
{
	int nRows = nRowEnd + 1 - nOffset;
	int nCols = nColEnd + 1 - nOffset;

	for(int i = nOffset; i < nRows; i++) {
		for(int j = nOffset; j < nCols; j++) {
			a[i * nCols + j] = b[j * nRows + i];
		}
	}
	return;
}


// m	=> in matrix
// m	<= out matrix (transposed), must be allocated
template<class T>
void mat_trans(T** m1,  T** const m, int nRowEnd, int nColEnd, int nOffset )
{
	mat_trans<T>(&m1[nOffset][nOffset], &m[0][0], nRowEnd, nColEnd, nOffset);
}


/*
Using the above LU decomposition and backsubstitution routines, it is com-pletely
straightforward to find the inverse of a matrix column by column. The matrix y will now 
contain the inverse of the original matrix a, which will have been destroyed. 
Note: a is decomposed, matrix is 1 (not 0) based
*/
template<class T>
void mat_inverse(T** y, T** a, int n)
{
	T d, *col;
	int i, j, *indx;

	col = vec_alloc<T>(n, 1);
	indx = vec_alloc<int>(n, 1);
	
	ludcmp(a, n, indx, &d); // Decompose the matrix just once.
	for (j = 1; j <= n; j++) 
	{ // Find inverse by columns.
		for (i = 1; i <= n; i++) 
		{
			col[i] = 0.0;
		}
		col[j] = 1.0;
		lubksb(a, n, indx, col);
		for (i = 1; i <= n; i++) 
		{
			y[i][j] = col[i];
		}
	}	// for (j = 1; j <= n; j++) 

	vec_dealloc<T>(col, 1);
	vec_dealloc<int>(indx, 1);

}	// void mat_inverse(T** y, T** a, int n)



// Note: same as above. y and a is 0 based
template<class T>
void mat_inverse(T* y, T* a, int n)
{
	T** y1 = mat_alloc<T>(n, n, 1);
	T** a1 = mat_alloc<T>(n, n, 1);
	
	for(int i = 0; i < n; i++)	// converse from 1-dimension array to matrix
	{
		for(int j = 0; j < n; j++)
		{
			a1[i + 1][j + 1] = a[i * n + j];
		}
	}

	mat_inverse<T>(y1, a1, n);	// inversion
	
	for(int i = 0; i < n; i++)	// converse from matrix  to 1-dimension array
	{
		for(int j = 0; j < n; j++)
		{
			y[i * n + j] = y1[i + 1][j + 1];
		}
	}

	mat_dealloc<T>(a1, 1);
	mat_dealloc<T>(y1, 1);

}


/*
Calculation of a determinant thus requires one call to ludcmp, with no subse-
quent backsubstitutions by lubksb. 

  For a matrix of any substantial size, it is quite likely that the determinant will
  overflow or underflow your computer's floating-point dynamic range. In this case
  you can modify the loop of the above fragment and (e.g.) divide by powers of ten,
  to keep track of the scale separately, or (e.g.) accumulate the sum of logarithms of
  the absolute values of the factors and the sign separately.

  Note:  a is decomposed
*/
template<class T>
T mat_det(T** a, int n)
{
	T d;
	int j, *indx;

	indx = vec_alloc<int>(n, 1);

	ludcmp(a, n, indx, &d); // This returns d as (+/-) 1.
	for (j = 1; j <= n; j++) d *= a[j][j];

	vec_dealloc<int>(indx, 1);

	return d;
	// The variable d now contains the determinant of the original matrix a, which will
	// have been destroyed.
}

}