

//    
//  $Workfile: tcl_math.h $
//  $Revision: $
//
//  Description:
//
//  Last modification: 
//     $Author: $ 
//     $Date: $
//  
//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//

#ifndef _TCL_MATH_H__
#define _TCL_MATH_H__

#include <math.h>

typedef struct _ATIFLOATCOLOR
{
  float r;
  float g;
  float b;
  float a;
} ATIFLOATCOLOR, *LPATIFLOATCOLOR;



// TODO: May be able to replace some of these with faster alternatives
#ifndef _WIN64
#define ATI_TCL_FAST_FTOI
#define ATI_TCL_FAST_SQRT
#define ATI_TCL_FAST_POW
#define ATI_TCL_FAST_INV
#endif

// FTOI
#ifdef ATI_TCL_FAST_FTOI
/* FROM THE ICD
#define FLT32_23_0 (float)((1<<23) + (1<<22))
// Convert float32 to int
// Float range (0.0 --> 2^22-1)
__inline INT
ATI_TCL_FTOI(_f)
{
	float f32;
	f32 = _f + FLT32_23_0;
	return ((*(int *)&f32) & 0x3fffff);
}
*/

// Requires chop rounding.
__inline INT
ATI_TCL_FTOI(FLOAT f)
{
    LARGE_INTEGER i;

    __asm
    {
        fld f
        fistp i
    }

    return i.LowPart;
}
#else // #ifdef ATI_TCL_FAST_FTOI

#define ATI_TCL_FTOI(fVal)   (INT)(fVal)

#endif // #ifdef ATI_TCL_FAST_FTOI


// SQRT
#ifdef ATI_TCL_FAST_SQRT
__inline float ATI_TCL_SQRT(FLOAT x)
{
  float retval;
  if ((x) <= 0.0f)
  {
    retval = 0.0f;
  }
  else if ((x) != 1.0f)
  {
    union 
    {
        unsigned int i;
        float f;
    } seed;
    float subexp, _retval_;

    seed.f = (x);
    seed.i = 0x5f375a00u - (seed.i >> 1);
    _retval_ = (x) * seed.f * seed.f;
    subexp = 3.f - _retval_;
    retval = .0625f * seed.f * subexp * (12.f - _retval_ * subexp * subexp);
    retval *= (x);
  }
  else
  {
    retval = (x);
  }
  return retval;
}
#else // #ifdef ATI_TCL_FAST_SQRT
#define ATI_TCL_SQRT(x)  (float)sqrt((double)(x))
#endif // #ifdef ATI_TCL_FAST_SQRT

// POW
#ifdef ATI_TCL_FAST_POW
__inline FLOAT ATI_TCL_POW(FLOAT x,FLOAT y)
{
//
// [pfx_parse] - workaround for PREfix parse problems with redefinition
//
#if (!defined(_PREFIX_)) && (!defined(_PREFAST_))
  extern double pow( double, double );
#endif

  return (float)pow(x, y);
}
#else // #ifdef ATI_TCL_FAST_POW
__inline FLOAT ATI_TCL_POW(FLOAT x,FLOAT y)
{
  extern double pow( double, double );

  return (float)pow(x, y);
}
#endif // #ifdef ATI_TCL_FAST_POW


#ifdef ATI_TCL_FAST_INV // TODO: Need a fast inverse
__inline FLOAT ATI_TCL_INV(FLOAT x)
{
  float retval;
  if (x <= 0.0f)
  {
    retval = 0.0f;
  }
  else if (x != 1.0f)
  {
    union
    {
      unsigned int i;
      float f;
    } seed;
    float subexp, _retval_;

    seed.f = x;
    seed.i = 0x5f375a00u - (seed.i >> 1);
    _retval_ = x * seed.f * seed.f;
    subexp = 3.f - _retval_;
    retval = .0625f * seed.f * subexp * (12.f - _retval_ * subexp * subexp);
    retval *= retval;
  }
  else
  {
    retval = x;
  }
  return retval;
}

#else // #ifdef ATI_TCL_FAST_INV
#define ATI_TCL_INV(x)   (1.0f / (x))
#endif // #ifdef ATI_TCL_FAST_INV





// Multiply two colors into the result
__inline void AtiColorMult( LPATIFLOATCOLOR pDest, LPATIFLOATCOLOR pA, LPATIFLOATCOLOR pB )
{
  pDest->r = pA->r * pB->r;
  pDest->g = pA->g * pB->g;
  pDest->b = pA->b * pB->b;
// Since we do not do alpha lighting, we do not need this (see comments in AtiProcessDirtyTclState)
//  pDest->a = pA->a * pB->a;
}

// Multiply two colors into the result
__inline void AtiColorMultScalar( LPATIFLOATCOLOR pDest, LPATIFLOATCOLOR pA, float scalar )
{
  pDest->r = pA->r * scalar;
  pDest->g = pA->g * scalar;
  pDest->b = pA->b * scalar;
// Since we do not do alpha lighting, we do not need this (see comments in AtiProcessDirtyTclState)
//  pDest->a = pA->a * scalar;
}

// Add two colors into the result
__inline void AtiColorAdd( LPATIFLOATCOLOR pDest, LPATIFLOATCOLOR pA, LPATIFLOATCOLOR pB )
{
  pDest->r = pA->r + pB->r;
  pDest->g = pA->g + pB->g;
  pDest->b = pA->b + pB->b;
// Since we do not do alpha lighting, we do not need this (see comments in AtiProcessDirtyTclState)
//  pDest->a = pA->a + pB->a;
}

// TCL_TODO_019:
// Take a floating point color and convert it to a packed color
// with clamping.
// This is not at all optimized -
// should be able to do a better job in D3DColorValueToD3DColor
// but it is not run time entensive.
__inline D3DCOLOR D3DColorValueToD3DColor( LPD3DCOLORVALUE pColorValue )
{
  DWORD dwRed, dwGrn, dwBlu, dwAlp;

  if( pColorValue->r > 1.0 )
  { dwRed = 255ul; }
  else if( pColorValue->r < 0.0 )
  { dwRed = 0ul; }
  else
  { dwRed = (DWORD)(pColorValue->r * 255.f + 0.5f); }

  if( pColorValue->g > 1.0 )
  { dwGrn = 255ul; }
  else if( pColorValue->g < 0.0 )
  { dwGrn = 0ul; }
  else
  { dwGrn = (DWORD)(pColorValue->g * 255.f + 0.5f); }

  if( pColorValue->b > 1.0 )
  { dwBlu = 255ul; }
  else if( pColorValue->b < 0.0 )
  { dwBlu = 0ul; }
  else
  { dwBlu = (DWORD)(pColorValue->b * 255.f + 0.5f); }

  if( pColorValue->a > 1.0 )
  { dwAlp = 255ul; }
  else if( pColorValue->a < 0.0 )
  { dwAlp = 0ul; }
  else
  { dwAlp = (DWORD)(pColorValue->a * 255.f + 0.5f); }

  return RGBA_MAKE( dwRed, dwGrn, dwBlu, dwAlp );
}

// ATI HW matricies are the transpose of the D3D matricies. If we declare them
// differently, and always use the structure definition to access the members,
// then we don't have to modify any code that we reuse from the D3D rasterizer.
typedef struct _ATIMATRIX
{
  /* The D3D way
  float _11, _12, _13, _14;
  float _21, _22, _23, _24; 
  float _31, _32, _33, _34;
  float _41, _42, _43, _44;
  */
  //The Rage6 way
  float _11, _21, _31, _41;
  float _12, _22, _32, _42;
  float _13, _23, _33, _43;
  float _14, _24, _34, _44;

  DWORD dwFlags;
} ATIMATRIX, *LPATIMATRIX;

// These flags are set during certain operations.
// If those operations are not performed, then
// these flags will not be set, independant of
// whether the matrix actually has that attribute.
#define ATIMATRIX_IDENTITY            0x00000001
// Identity is set in CopyAndClassifyD3dToAtiMatrix, but not CopyD3dToAtiMatrix.
// So texture matrices don't get classified at all.
#define ATIMATRIX_SCALING             0x00000002
#define ATIMATRIX_NONUNIFORM_SCALING  0x00000004
// SCALING and NONUNIFORM_SCALING are set in SetScalingAttibutes.

// A few different types of vector matrix arithmatic for different purposes.
__inline void Ati3Vector4MatrixProduct( LPATIVECTOR pvecDest, LPATIVECTOR pvecSrc, ATIMATRIX *pMat)
{
    pvecDest->x = pvecSrc->x*pMat->_11 + pvecSrc->y*pMat->_21 + pvecSrc->z*pMat->_31 + pMat->_41;
    pvecDest->y = pvecSrc->x*pMat->_12 + pvecSrc->y*pMat->_22 + pvecSrc->z*pMat->_32 + pMat->_42;
    pvecDest->z = pvecSrc->x*pMat->_13 + pvecSrc->y*pMat->_23 + pvecSrc->z*pMat->_33 + pMat->_43;
    pvecDest->w = pvecSrc->x*pMat->_14 + pvecSrc->y*pMat->_24 + pvecSrc->z*pMat->_34 + pMat->_44;
}

__inline void Ati3Vector4MatrixProduct3Vec( LPATIVECTOR pvecDest, LPATIVECTOR pvecSrc, ATIMATRIX *pMat)
{
    pvecDest->x = pvecSrc->x*pMat->_11 + pvecSrc->y*pMat->_21 + pvecSrc->z*pMat->_31 + pMat->_41;
    pvecDest->y = pvecSrc->x*pMat->_12 + pvecSrc->y*pMat->_22 + pvecSrc->z*pMat->_32 + pMat->_42;
    pvecDest->z = pvecSrc->x*pMat->_13 + pvecSrc->y*pMat->_23 + pvecSrc->z*pMat->_33 + pMat->_43;
    // Don't do the w component
    // pvecDest->w = pvecSrc->x*pMat->_14 + pvecSrc->y*pMat->_24 + pvecSrc->z*pMat->_34 + pMat->_44;
}

__inline void Ati4Vector4MatrixProduct( LPATIVECTOR pvecDest, LPATIVECTOR pvecSrc, ATIMATRIX *pMat)
{
    pvecDest->x = pvecSrc->x*pMat->_11 + pvecSrc->y*pMat->_21 + pvecSrc->z*pMat->_31 + pvecSrc->w*pMat->_41;
    pvecDest->y = pvecSrc->x*pMat->_12 + pvecSrc->y*pMat->_22 + pvecSrc->z*pMat->_32 + pvecSrc->w*pMat->_42;
    pvecDest->z = pvecSrc->x*pMat->_13 + pvecSrc->y*pMat->_23 + pvecSrc->z*pMat->_33 + pvecSrc->w*pMat->_43;
    pvecDest->w = pvecSrc->x*pMat->_14 + pvecSrc->y*pMat->_24 + pvecSrc->z*pMat->_34 + pvecSrc->w*pMat->_44;
}

__inline void Ati3Vector3MatrixProduct( LPATIVECTOR pvecDest, LPATIVECTOR pvecSrc, ATIMATRIX *pMat)
{
    pvecDest->x = pvecSrc->x*pMat->_11 + pvecSrc->y*pMat->_21 + pvecSrc->z*pMat->_31;
    pvecDest->y = pvecSrc->x*pMat->_12 + pvecSrc->y*pMat->_22 + pvecSrc->z*pMat->_32;
    pvecDest->z = pvecSrc->x*pMat->_13 + pvecSrc->y*pMat->_23 + pvecSrc->z*pMat->_33;
}

__inline void Ati3Vector3MatrixTransposeProduct( LPATIVECTOR pvecDest, LPATIVECTOR pvecSrc, ATIMATRIX *pMat)
{
    pvecDest->x = pvecSrc->x*pMat->_11 + pvecSrc->y*pMat->_12 + pvecSrc->z*pMat->_13;
    pvecDest->y = pvecSrc->x*pMat->_21 + pvecSrc->y*pMat->_22 + pvecSrc->z*pMat->_23;
    pvecDest->z = pvecSrc->x*pMat->_31 + pvecSrc->y*pMat->_32 + pvecSrc->z*pMat->_33;
}

// Return the length of a vector (ignore the W compoenent).
// This is almost exclusively used to compute the inverse
// square root. There is a quicker cheaper method (nicely
// written in OpenGL ), that we should one day use instead
// of effectively 1.f / sqrt()
__inline float AtiVectorLength3d( LPATIVECTOR pVec )
{
  return ATI_TCL_SQRT( pVec->x*pVec->x + pVec->y*pVec->y + pVec->z*pVec->z );
}

__inline void AtiVectorNormalize3d(LPATIVECTOR pVec)
{
  float fOneOverLen = ATI_TCL_INV( AtiVectorLength3d(pVec));

  pVec->x *= fOneOverLen;
  pVec->y *= fOneOverLen;
  pVec->z *= fOneOverLen;
}

__inline float AtiVectorDot3d( LPATIVECTOR pA, LPATIVECTOR pB)
{
  return (pA->x * pB->x) + (pA->y * pB->y) + (pA->z * pB->z);
}


// Multiply a vector by -1 (reversing it's direction) by toggling the sign bit.
__inline void AtiVectorNegate( LPATIVECTOR pVec )
{
  *((LPDWORD)&pVec->x) ^= 0x80000000;
  *((LPDWORD)&pVec->y) ^= 0x80000000;
  *((LPDWORD)&pVec->z) ^= 0x80000000;
  *((LPDWORD)&pVec->w) ^= 0x80000000;
}

// Subtract two vectors and place in result
__inline void AtiVectorSub3d( LPATIVECTOR pDest, LPATIVECTOR pA, LPATIVECTOR pB)
{
  pDest->x = pA->x - pB->x;
  pDest->y = pA->y - pB->y;
  pDest->z = pA->z - pB->z;
}

__inline void AtiVectorMultScalar3d(LPATIVECTOR pDest, LPATIVECTOR pV, float scalar)
{
  pDest->x = pV->x * scalar;
  pDest->y = pV->y * scalar;
  pDest->z = pV->z * scalar;
}

// The DWORD version of the matrices are only used when classifying the
// matrices (bitwise operations are used).
typedef struct _ATIDWMATRIX
{
  DWORD _11, _21, _31, _41;
  DWORD _12, _22, _32, _42;
  DWORD _13, _23, _33, _43;
  DWORD _14, _24, _34, _44;

  DWORD dwFlags;
} ATIDWMATRIX, *LPATIDWMATRIX;

typedef struct _D3DDWMATRIX
{
  DWORD _11, _12, _13, _14;
  DWORD _21, _22, _23, _24; 
  DWORD _31, _32, _33, _34;
  DWORD _41, _42, _43, _44;
} D3DDWMATRIX, *LPD3DDWMATRIX;

#define COPYANDCLASS( goesout, goesin, iden )   \
  dwIsNotEqual    |=  goesout ^ goesin; \
  dwIsNotIdentity |=   iden   ^ goesin; \
  goesout = goesin;


__inline void SetScalingAttibutes( ATIMATRIX *pAti )
{
  if( ( ((LPATIDWMATRIX)pAti)->_14 ^ 0x00000000) |
      ( ((LPATIDWMATRIX)pAti)->_24 ^ 0x00000000) |
      ( ((LPATIDWMATRIX)pAti)->_34 ^ 0x00000000) |
      ( ((LPATIDWMATRIX)pAti)->_44 ^ 0x3f800000)  )
  {
    if( ( ((LPATIDWMATRIX)pAti)->_14 ^ ((LPATIDWMATRIX)pAti)->_24 ) |
        ( ((LPATIDWMATRIX)pAti)->_14 ^ ((LPATIDWMATRIX)pAti)->_34 ) )
    { pAti->dwFlags |= ATIMATRIX_SCALING | ATIMATRIX_NONUNIFORM_SCALING; }
    else
    { pAti->dwFlags |= ATIMATRIX_SCALING; }
  }
}

__inline DWORD CopyAndClassifyD3dToAtiMatrix( ATIMATRIX *pAti, D3DMATRIX *pD3d )
{
  LPATIDWMATRIX pDwAti = (LPATIDWMATRIX)pAti;
  LPD3DDWMATRIX pDwD3d = (LPD3DDWMATRIX)pD3d;
  DWORD dwIsNotEqual = 0ul;
  DWORD dwIsNotIdentity = 0ul;

  COPYANDCLASS( pDwAti->_11, pDwD3d->_11, 0x3f800000 );
  COPYANDCLASS( pDwAti->_12, pDwD3d->_12, 0x00000000 );
  COPYANDCLASS( pDwAti->_13, pDwD3d->_13, 0x00000000 );
  COPYANDCLASS( pDwAti->_14, pDwD3d->_14, 0x00000000 );
  COPYANDCLASS( pDwAti->_21, pDwD3d->_21, 0x00000000 );
  COPYANDCLASS( pDwAti->_22, pDwD3d->_22, 0x3f800000 );
  COPYANDCLASS( pDwAti->_23, pDwD3d->_23, 0x00000000 );
  COPYANDCLASS( pDwAti->_24, pDwD3d->_24, 0x00000000 );
  COPYANDCLASS( pDwAti->_31, pDwD3d->_31, 0x00000000 );
  COPYANDCLASS( pDwAti->_32, pDwD3d->_32, 0x00000000 );
  COPYANDCLASS( pDwAti->_33, pDwD3d->_33, 0x3f800000 );
  COPYANDCLASS( pDwAti->_34, pDwD3d->_34, 0x00000000 );
  COPYANDCLASS( pDwAti->_41, pDwD3d->_41, 0x00000000 );
  COPYANDCLASS( pDwAti->_42, pDwD3d->_42, 0x00000000 );
  COPYANDCLASS( pDwAti->_43, pDwD3d->_43, 0x00000000 );
  COPYANDCLASS( pDwAti->_44, pDwD3d->_44, 0x3f800000 );

  pDwAti->dwFlags = dwIsNotIdentity ? 0ul : ATIMATRIX_IDENTITY;

  return dwIsNotEqual;
}

// Sure CopyD3dToAtiMatrix looks deceptively like a memcpy, but it isn't.
// The structure definitions are transposed, and the compiler does
// the magic for us.
__inline void CopyD3dToAtiMatrix( ATIMATRIX *pAti, D3DMATRIX *pD3d )
{ 
  pAti->_11 = pD3d->_11;  pAti->_12 = pD3d->_12;  pAti->_13 = pD3d->_13;  pAti->_14 = pD3d->_14;
  pAti->_21 = pD3d->_21;  pAti->_22 = pD3d->_22;  pAti->_23 = pD3d->_23;  pAti->_24 = pD3d->_24;
  pAti->_31 = pD3d->_31;  pAti->_32 = pD3d->_32;  pAti->_33 = pD3d->_33;  pAti->_34 = pD3d->_34;
  pAti->_41 = pD3d->_41;  pAti->_42 = pD3d->_42;  pAti->_43 = pD3d->_43;  pAti->_44 = pD3d->_44;
}

__inline void CopyAtiToD3dMatrix( D3DMATRIX *pD3d, ATIMATRIX *pAti )
{ 
  pD3d->_11 = pAti->_11;  pD3d->_12 = pAti->_12;  pD3d->_13 = pAti->_13;  pD3d->_14 = pAti->_14;
  pD3d->_21 = pAti->_21;  pD3d->_22 = pAti->_22;  pD3d->_23 = pAti->_23;  pD3d->_24 = pAti->_24;
  pD3d->_31 = pAti->_31;  pD3d->_32 = pAti->_32;  pD3d->_33 = pAti->_33;  pD3d->_34 = pAti->_34;
  pD3d->_41 = pAti->_41;  pD3d->_42 = pAti->_42;  pD3d->_43 = pAti->_43;  pD3d->_44 = pAti->_44;
}

__inline void SaveD3dMatrix( D3DMATRIX *pAti, D3DMATRIX *pD3d )
{ 
  pAti->_11 = pD3d->_11;  pAti->_12 = pD3d->_12;  pAti->_13 = pD3d->_13;  pAti->_14 = pD3d->_14;
  pAti->_21 = pD3d->_21;  pAti->_22 = pD3d->_22;  pAti->_23 = pD3d->_23;  pAti->_24 = pD3d->_24;
  pAti->_31 = pD3d->_31;  pAti->_32 = pD3d->_32;  pAti->_33 = pD3d->_33;  pAti->_34 = pD3d->_34;
  pAti->_41 = pD3d->_41;  pAti->_42 = pD3d->_42;  pAti->_43 = pD3d->_43;  pAti->_44 = pD3d->_44;
}

__inline void AtiMatrixIdentity( ATIMATRIX *pmResult )
{
  pmResult->_11 = 1.f; pmResult->_12 = 0.f; pmResult->_13 = 0.f; pmResult->_14 = 0.f;
  pmResult->_21 = 0.f; pmResult->_22 = 1.f; pmResult->_23 = 0.f; pmResult->_24 = 0.f;
  pmResult->_31 = 0.f; pmResult->_32 = 0.f; pmResult->_33 = 1.f; pmResult->_34 = 0.f;
  pmResult->_41 = 0.f; pmResult->_42 = 0.f; pmResult->_43 = 0.f; pmResult->_44 = 1.f;
  pmResult->dwFlags = ATIMATRIX_IDENTITY;
}

__inline void D3dMatrixIdentity( D3DMATRIX *pmResult )
{
  pmResult->_11 = 1.f; pmResult->_12 = 0.f; pmResult->_13 = 0.f; pmResult->_14 = 0.f;
  pmResult->_21 = 0.f; pmResult->_22 = 1.f; pmResult->_23 = 0.f; pmResult->_24 = 0.f;
  pmResult->_31 = 0.f; pmResult->_32 = 0.f; pmResult->_33 = 1.f; pmResult->_34 = 0.f;
  pmResult->_41 = 0.f; pmResult->_42 = 0.f; pmResult->_43 = 0.f; pmResult->_44 = 1.f;
}


// result = a*b
// Note:  only use MATRIX_PRODUCT( a, b, c)
//        do not use MATRIX_PRODUCT( a, a, b ) - instead use MatrixProductSafe( a, a, b );
__inline void MatrixProduct(ATIMATRIX *pmResult, ATIMATRIX *pmA, ATIMATRIX *pmB)
{
  if( pmA->dwFlags & ATIMATRIX_IDENTITY )
  { *pmResult = *pmB; }
  else if( pmB->dwFlags & ATIMATRIX_IDENTITY )
  { *pmResult = *pmA; }
  else
  {
    pmResult->_11 = pmA->_11*pmB->_11 + pmA->_12*pmB->_21 + pmA->_13*pmB->_31 + pmA->_14*pmB->_41;
    pmResult->_12 = pmA->_11*pmB->_12 + pmA->_12*pmB->_22 + pmA->_13*pmB->_32 + pmA->_14*pmB->_42;
    pmResult->_13 = pmA->_11*pmB->_13 + pmA->_12*pmB->_23 + pmA->_13*pmB->_33 + pmA->_14*pmB->_43;
    pmResult->_14 = pmA->_11*pmB->_14 + pmA->_12*pmB->_24 + pmA->_13*pmB->_34 + pmA->_14*pmB->_44;
  
    pmResult->_21 = pmA->_21*pmB->_11 + pmA->_22*pmB->_21 + pmA->_23*pmB->_31 + pmA->_24*pmB->_41;
    pmResult->_22 = pmA->_21*pmB->_12 + pmA->_22*pmB->_22 + pmA->_23*pmB->_32 + pmA->_24*pmB->_42;
    pmResult->_23 = pmA->_21*pmB->_13 + pmA->_22*pmB->_23 + pmA->_23*pmB->_33 + pmA->_24*pmB->_43;
    pmResult->_24 = pmA->_21*pmB->_14 + pmA->_22*pmB->_24 + pmA->_23*pmB->_34 + pmA->_24*pmB->_44;
  
    pmResult->_31 = pmA->_31*pmB->_11 + pmA->_32*pmB->_21 + pmA->_33*pmB->_31 + pmA->_34*pmB->_41;
    pmResult->_32 = pmA->_31*pmB->_12 + pmA->_32*pmB->_22 + pmA->_33*pmB->_32 + pmA->_34*pmB->_42;
    pmResult->_33 = pmA->_31*pmB->_13 + pmA->_32*pmB->_23 + pmA->_33*pmB->_33 + pmA->_34*pmB->_43;
    pmResult->_34 = pmA->_31*pmB->_14 + pmA->_32*pmB->_24 + pmA->_33*pmB->_34 + pmA->_34*pmB->_44;
  
    pmResult->_41 = pmA->_41*pmB->_11 + pmA->_42*pmB->_21 + pmA->_43*pmB->_31 + pmA->_44*pmB->_41;
    pmResult->_42 = pmA->_41*pmB->_12 + pmA->_42*pmB->_22 + pmA->_43*pmB->_32 + pmA->_44*pmB->_42;
    pmResult->_43 = pmA->_41*pmB->_13 + pmA->_42*pmB->_23 + pmA->_43*pmB->_33 + pmA->_44*pmB->_43;
    pmResult->_44 = pmA->_41*pmB->_14 + pmA->_42*pmB->_24 + pmA->_43*pmB->_34 + pmA->_44*pmB->_44;

    // Reset and compute flags
    pmResult->dwFlags = 0ul;
    SetScalingAttibutes( pmResult );
  }
}

__inline void MatrixProductSafe(ATIMATRIX *pmResult, ATIMATRIX *pmA, ATIMATRIX *pmB)
{
  if (pmResult == pmA || pmResult == pmB)
  {
    ATIMATRIX mRes;
    MatrixProduct((&mRes), pmA, pmB);
    *(ATIMATRIX*)pmResult = mRes;
    return;
  }
  
  MatrixProduct(pmResult, pmA, pmB);
}


//---------------------------------------------------------------------
// Stolen from (and used in that same instances as) the D3D reference device
// (which apparently stole it from so_math.c).
// Modified to do an inverse transpose as opposed to just an inverse.
// This function uses Cramer's Rule to calculate the matrix inverse.
// See nt\private\windows\opengl\serever\soft\so_math.c
//
// Returns:
//    0 - if success
//   -1 - if input matrix is singular
//

__inline int MatrixInverseTranspose( ATIMATRIX *inverse, ATIMATRIX *src )
{
  double x00, x01, x02;
  double x10, x11, x12;
  double x20, x21, x22;
  double rcp;

  if( src->dwFlags & ATIMATRIX_IDENTITY )
  { AtiMatrixIdentity( inverse ); return 0; }

  /* propagate matrix type & branch if general */
  if ( !(src->dwFlags & ATIMATRIX_SCALING) )
  {
    double z00, z01, z02;
    double z10, z11, z12;
    double z20, z21, z22;

    /* read 3x3 matrix into registers */
    x00 = src->_11;
    x01 = src->_12;
    x02 = src->_13;
    x10 = src->_21;
    x11 = src->_22;
    x12 = src->_23;
    x20 = src->_31;
    x21 = src->_32;
    x22 = src->_33;

    /* compute first three 2x2 cofactors */
    z20 = x01*x12 - x11*x02;
    z10 = x21*x02 - x01*x22;
    z00 = x11*x22 - x12*x21;

    /* compute 3x3 determinant & its reciprocal */
    rcp = x20*z20 + x10*z10 + x00*z00;
    if (rcp == (float)0)
    { return -1; }
    rcp = (float)1/rcp;

    /* compute other six 2x2 cofactors */
    z01 = x20*x12 - x10*x22;
    z02 = x10*x21 - x20*x11;
    z11 = x00*x22 - x20*x02;
    z12 = x20*x01 - x00*x21;
    z21 = x10*x02 - x00*x12;
    z22 = x00*x11 - x10*x01;

    /* multiply all cofactors by reciprocal */
    inverse->_11 = (float)(z00*rcp);
    inverse->_12 = (float)(z01*rcp);
    inverse->_13 = (float)(z02*rcp);
    inverse->_21 = (float)(z10*rcp);
    inverse->_22 = (float)(z11*rcp);
    inverse->_23 = (float)(z12*rcp);
    inverse->_31 = (float)(z20*rcp);
    inverse->_32 = (float)(z21*rcp);
    inverse->_33 = (float)(z22*rcp);

    /* read translation vector & negate */
    x00 = -src->_41;
    x01 = -src->_42;
    x02 = -src->_43;

    /* store bottom row of inverse transpose */
    inverse->_41 = 0;
    inverse->_42 = 0;
    inverse->_43 = 0;
    inverse->_44 = 1;

    /* finish by tranforming translation vector */
    inverse->_14 = inverse->_11*(float)x00 + inverse->_12*(float)x01 + inverse->_13*(float)x02;
    inverse->_24 = inverse->_21*(float)x00 + inverse->_22*(float)x01 + inverse->_23*(float)x02;
    inverse->_34 = inverse->_31*(float)x00 + inverse->_32*(float)x01 + inverse->_33*(float)x02;
  }
  else
  {
    double x30, x31, x32;
    double y01, y02, y03, y12, y13, y23;
    double z02, z03, z12, z13, z22, z23, z32, z33;

#define x03 x01
#define x13 x11
#define x23 x21
#define x33 x31
#define z00 x02
#define z10 x12
#define z20 x22
#define z30 x32
#define z01 x03
#define z11 x13
#define z21 x23
#define z31 x33

    /* read 1st two columns of matrix into registers */
    x00 = src->_11;
    x01 = src->_12;
    x10 = src->_21;
    x11 = src->_22;
    x20 = src->_31;
    x21 = src->_32;
    x30 = src->_41;
    x31 = src->_42;

    /* compute all six 2x2 determinants of 1st two columns */
    y01 = x00*x11 - x10*x01;
    y02 = x00*x21 - x20*x01;
    y03 = x00*x31 - x30*x01;
    y12 = x10*x21 - x20*x11;
    y13 = x10*x31 - x30*x11;
    y23 = x20*x31 - x30*x21;

    /* read 2nd two columns of matrix into registers */
    x02 = src->_13;
    x03 = src->_14;
    x12 = src->_23;
    x13 = src->_24;
    x22 = src->_33;
    x23 = src->_34;
    x32 = src->_43;
    x33 = src->_44;

    /* compute all 3x3 cofactors for 2nd two columns */
    z33 = x02*y12 - x12*y02 + x22*y01;
    z23 = x12*y03 - x32*y01 - x02*y13;
    z13 = x02*y23 - x22*y03 + x32*y02;
    z03 = x22*y13 - x32*y12 - x12*y23;
    z32 = x13*y02 - x23*y01 - x03*y12;
    z22 = x03*y13 - x13*y03 + x33*y01;
    z12 = x23*y03 - x33*y02 - x03*y23;
    z02 = x13*y23 - x23*y13 + x33*y12;

    /* compute all six 2x2 determinants of 2nd two columns */
    y01 = x02*x13 - x12*x03;
    y02 = x02*x23 - x22*x03;
    y03 = x02*x33 - x32*x03;
    y12 = x12*x23 - x22*x13;
    y13 = x12*x33 - x32*x13;
    y23 = x22*x33 - x32*x23;

    /* read 1st two columns of matrix into registers */
    x00 = src->_11;
    x01 = src->_12;
    x10 = src->_21;
    x11 = src->_22;
    x20 = src->_31;
    x21 = src->_32;
    x30 = src->_41;
    x31 = src->_42;

    /* compute all 3x3 cofactors for 1st column */
    z30 = x11*y02 - x21*y01 - x01*y12;
    z20 = x01*y13 - x11*y03 + x31*y01;
    z10 = x21*y03 - x31*y02 - x01*y23;
    z00 = x11*y23 - x21*y13 + x31*y12;

    /* compute 4x4 determinant & its reciprocal */
    rcp = x30*z30 + x20*z20 + x10*z10 + x00*z00;
    if (rcp == (float)0)
    { return -1; }
    rcp = (float)1/rcp;

    /* compute all 3x3 cofactors for 2nd column */
    z31 = x00*y12 - x10*y02 + x20*y01;
    z21 = x10*y03 - x30*y01 - x00*y13;
    z11 = x00*y23 - x20*y03 + x30*y02;
    z01 = x20*y13 - x30*y12 - x10*y23;

    /* multiply all 3x3 cofactors by reciprocal */
    inverse->_11 = (float)(z00*rcp);
    inverse->_12 = (float)(z01*rcp);
    inverse->_21 = (float)(z10*rcp);
    inverse->_13 = (float)(z02*rcp);
    inverse->_31 = (float)(z20*rcp);
    inverse->_14 = (float)(z03*rcp);
    inverse->_41 = (float)(z30*rcp);
    inverse->_22 = (float)(z11*rcp);
    inverse->_23 = (float)(z12*rcp);
    inverse->_32 = (float)(z21*rcp);
    inverse->_24 = (float)(z13*rcp);
    inverse->_42 = (float)(z31*rcp);
    inverse->_33 = (float)(z22*rcp);
    inverse->_34 = (float)(z23*rcp);
    inverse->_43 = (float)(z32*rcp);
    inverse->_44 = (float)(z33*rcp);
  }

  return 0;
}


// Generates an Inverse Matrix and does a proper transpose
// Check MatrixInverseTranspose(), it doesn't seem to do a
// transpose
__inline int MatrixInverse( ATIMATRIX *inverse, ATIMATRIX *src )
{
  double x00, x01, x02;
  double x10, x11, x12;
  double x20, x21, x22;
  double rcp;


/*  if( src->dwFlags & ATIMATRIX_IDENTITY )
  { 
	  AtiMatrixIdentity( inverse ); 
	  return 0; 
  }*/


  double x30, x31, x32;
  double y01, y02, y03, y12, y13, y23;
  double z02, z03, z12, z13, z22, z23, z32, z33;

#define x03 x01
#define x13 x11
#define x23 x21
#define x33 x31
#define z00 x02
#define z10 x12
#define z20 x22
#define z30 x32
#define z01 x03
#define z11 x13
#define z21 x23
#define z31 x33

  /* read 1st two columns of matrix into registers */
  x00 = src->_11;
  x01 = src->_12;
  x10 = src->_21;
  x11 = src->_22;
  x20 = src->_31;
  x21 = src->_32;
  x30 = src->_41;
  x31 = src->_42;

  /* compute all six 2x2 determinants of 1st two columns */
  y01 = x00*x11 - x10*x01;
  y02 = x00*x21 - x20*x01;
  y03 = x00*x31 - x30*x01;
  y12 = x10*x21 - x20*x11;
  y13 = x10*x31 - x30*x11;
  y23 = x20*x31 - x30*x21;

  /* read 2nd two columns of matrix into registers */
  
  x02 = src->_13;
  x03 = src->_14;
  x12 = src->_23;
  x13 = src->_24;
  x22 = src->_33;
  x23 = src->_34;
  x32 = src->_43;
  x33 = src->_44;

  /* compute all 3x3 cofactors for 2nd two columns */
  z33 = x02*y12 - x12*y02 + x22*y01;
  z23 = x12*y03 - x32*y01 - x02*y13;
  z13 = x02*y23 - x22*y03 + x32*y02;
  z03 = x22*y13 - x32*y12 - x12*y23;
  z32 = x13*y02 - x23*y01 - x03*y12;
  z22 = x03*y13 - x13*y03 + x33*y01;
  z12 = x23*y03 - x33*y02 - x03*y23;
  z02 = x13*y23 - x23*y13 + x33*y12;

  /* compute all six 2x2 determinants of 2nd two columns */
  y01 = x02*x13 - x12*x03;
  y02 = x02*x23 - x22*x03;
  y03 = x02*x33 - x32*x03;
  y12 = x12*x23 - x22*x13;
  y13 = x12*x33 - x32*x13;
  y23 = x22*x33 - x32*x23;

  /* read 1st two columns of matrix into registers */
  x00 = src->_11;
  x01 = src->_12;
  x10 = src->_21;
  x11 = src->_22;
  x20 = src->_31;
  x21 = src->_32;
  x30 = src->_41;
  x31 = src->_42;

  /* compute all 3x3 cofactors for 1st column */
  z30 = x11*y02 - x21*y01 - x01*y12;
  z20 = x01*y13 - x11*y03 + x31*y01;
  z10 = x21*y03 - x31*y02 - x01*y23;
  z00 = x11*y23 - x21*y13 + x31*y12;

  /* compute 4x4 determinant & its reciprocal */
  rcp = x30*z30 + x20*z20 + x10*z10 + x00*z00;
  if (rcp == (float)0)
  { return -1; }
  rcp = (float)1/rcp;

  /* compute all 3x3 cofactors for 2nd column */
  z31 = x00*y12 - x10*y02 + x20*y01;
  z21 = x10*y03 - x30*y01 - x00*y13;
  z11 = x00*y23 - x20*y03 + x30*y02;
  z01 = x20*y13 - x30*y12 - x10*y23;

  /* multiply all 3x3 cofactors by reciprocal */
  inverse->_11 = (float)(z00*rcp);
  inverse->_21 = (float)(z01*rcp);
  inverse->_12 = (float)(z10*rcp);
  inverse->_31 = (float)(z02*rcp);
  inverse->_13 = (float)(z20*rcp);
  inverse->_41 = (float)(z03*rcp);
  inverse->_14 = (float)(z30*rcp);
  inverse->_22 = (float)(z11*rcp);
  inverse->_32 = (float)(z12*rcp);
  inverse->_23 = (float)(z21*rcp);
  inverse->_42 = (float)(z13*rcp);
  inverse->_24 = (float)(z31*rcp);
  inverse->_33 = (float)(z22*rcp);
  inverse->_43 = (float)(z23*rcp);
  inverse->_34 = (float)(z32*rcp);
  inverse->_44 = (float)(z33*rcp);

  return 0;
}



#define ATI_MATH_RSHIFT 16
#define ATI_MATH_GSHIFT  8
#define ATI_MATH_BSHIFT  0
#define ATI_MATH_ASHIFT 24
#define ATI_MATH_RMASK  0x00ff0000
#define ATI_MATH_GMASK  0x0000ff00
#define ATI_MATH_BMASK  0x000000ff
#define ATI_MATH_AMASK  0xff000000

__inline void
AtiDwordColorToFloat(LPATIFLOATCOLOR pfDestColor, DWORD dwSrcColor)
{
  pfDestColor->r = ((dwSrcColor & ATI_MATH_RMASK) >> ATI_MATH_RSHIFT) * (1.0f/255.0f);
  pfDestColor->g = ((dwSrcColor & ATI_MATH_GMASK) >> ATI_MATH_GSHIFT) * (1.0f/255.0f);
  pfDestColor->b = ((dwSrcColor & ATI_MATH_BMASK) >> ATI_MATH_BSHIFT) * (1.0f/255.0f);
  pfDestColor->a = ((dwSrcColor & ATI_MATH_AMASK) >> ATI_MATH_ASHIFT) * (1.0f/255.0f);
}

__inline DWORD
AtiFloatColorToDword(ATIFLOATCOLOR fColor)
{
  LONG red, grn, blu, alp;
  DWORD dwColor;

  red = ATI_TCL_FTOI(fColor.r * 255.0f);
  grn = ATI_TCL_FTOI(fColor.g * 255.0f);
  blu = ATI_TCL_FTOI(fColor.b * 255.0f);
  alp = ATI_TCL_FTOI(fColor.a * 255.0f);

  if (red < 0) red = 0; else if (red > 255) red = 255;
  if (grn < 0) grn = 0; else if (grn > 255) grn = 255;
  if (blu < 0) blu = 0; else if (blu > 255) blu = 255;
  if (alp < 0) alp = 0; else if (alp > 255) alp = 255;
  HSLASSERT(alp >= 0);
  HSLASSERT(alp <= 255);

  dwColor = (DWORD) ((alp << ATI_MATH_ASHIFT) | 
                     (red << ATI_MATH_RSHIFT) | 
                     (grn << ATI_MATH_GSHIFT) | 
                     (blu << ATI_MATH_BSHIFT) );

  return dwColor;
}


#ifndef _WIN64
__inline DWORD InterpolateColor(DWORD dwARGBDst, DWORD dwARGBSrc, float fU)
{
    DWORD dwU;
    DWORD dwRet;

    if (dwARGBDst == dwARGBSrc)
        return dwARGBDst;

    dwU = (DWORD)(fU * 32768.f);

    // Use four-way integer ops
    _asm
    {
        emms
        movd        mm3, dword ptr dwU
        pxor        mm2, mm2
        movd        mm0, dword ptr dwARGBSrc    // mm0 = --------|a0r0g0b0
        movd        mm1, dword ptr dwARGBDst    // mm1 = --------|a1r1g1b1
        pshufw      mm3, mm3, 0x00              // mm3 = u | u | u | u
        punpcklbw   mm0, mm2                    // mm0 = 00a0|00r0|00g0|00b0
        punpcklbw   mm1, mm2                    // mm1 = 00a1|00r1|00g1|00b1
        psubw       mm0, mm1
        movq        mm4, mm0
        pmullw      mm0, mm3
        pmulhw      mm4, mm3
        movq        mm5, mm0
        punpcklwd   mm0, mm4
        punpckhwd   mm5, mm4
        psrad       mm0, 15
        psrad       mm5, 15
        packssdw    mm0, mm5
        paddw       mm0, mm1
        packuswb    mm0, mm0
        movd        dword ptr dwRet, mm0
        emms
    }

    return dwRet;
}
#endif//#ifndef _WIN64


#endif

