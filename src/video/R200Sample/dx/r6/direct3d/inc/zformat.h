

#ifndef	ZFORMAT_H
#define	ZFORMAT_H
//    
//  $Workfile$
//  $Revision$
//
//  Description:
//
//  Last modification: 
//     $Author$ 
//     $Date$
//  
//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//

//
// This file contains macros and functions used to convert between
// IEEE floating point and the smaller floating point values used in the
// Rage6.
//
typedef unsigned int zf_uint;
typedef signed int   zf_int;

//
// The floating point datatypes.
//
typedef union
{
    unsigned long int i;
    float f;
    struct
    {
        zf_uint mantissa:23;
        zf_int  exponent:8;
        zf_uint sign:1;
    };
} Float32;

typedef union 
{
    unsigned long int i;
    struct
    {
        zf_uint mantissa:15;
        zf_int exponent:8;
        zf_uint sign:1;
        zf_uint :8;
    };
} Float24;

typedef union 
{
    unsigned long int i;
    struct
    {
        zf_uint mantissa:12;
        zf_int  exponent:4;
		zf_uint         :16;
    };
} Float16;

//
// Functions to convert between data formats.
//
__inline float
Float16ToFloat(Float16 f16)
{
    return((float)(((f16.mantissa) * (1.0/((float)(1<<12)))
                    + ((f16.exponent == 0) ? 0.0 : 1.0))
                   * (float)((__int64)1 << (f16.exponent ? f16.exponent-7 : -6))));
}


__inline DWORD
FloatToFloat16(float fp)
{
    UINT m;
	 Float32 f32;
    Float16 f16;

	 f16.i = 0;
    f32.f = fp;
	 f32.exponent -= 127;
    
	 if( f32.sign || f32.exponent < -18 )
		return(0);
    
	 if( f32.exponent > 8 )
		return 0xFFFF;
    
	 m = f32.mantissa;
	 if(f32.exponent <= -7)
    {
        
		 m >>= ( ( -f32.exponent ) - 7 + 12 );
		 return m;
    }
    
	 m >>= 11;
	 f16.exponent = f32.exponent + 7;
    f16.mantissa = m;
    return f16.i;
}

__inline float
Float24ToFloat(Float24 f24)
{
    UINT m;
	 Float32 f32;

    f32.sign = f24.sign;
    m = f24.mantissa;
	 m <<= 8;
	 f32.mantissa = m;
    f32.exponent = (f24.exponent);
    return(f32.f);
}


__inline DWORD
FloatToFloat24(float fp)
{
	 UINT m;
	 Float32 *lpvF32 = (Float32 *)(&fp);
    Float24 f24;
    
	 f24.sign = lpvF32->sign;
    m = lpvF32->mantissa;
	 m >>= 8;
	 f24.mantissa = m;
    f24.exponent = lpvF32->exponent;
    return(f24.i);
}

//
// Constants for different sized mins and maxs.  These
// are ieee floating point values.  Not all possible
// minimum and maximum values are here, only the ones we
// need.
//
#define MIN_FLT16  0.000003181f
#define MAX_FLT16  256.0f
#endif	/* defined(ZFORMAT_H) */
//
// $Archive$
// $Author$
// $Revision$
// $Date$
// $Modtime$
// $History$
//

