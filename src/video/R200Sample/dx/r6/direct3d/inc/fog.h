

//
//  Workfile: fog.h
//
//  Description:
//      Central area for all fog processing code.
//
//  Trade secret of ATI Technologies, Inc.
//  Copyright 2002, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//

#ifndef _FOG_H_
#define _FOG_H_


#include "d3ddevice.h"
#include "d3dcntx.h"
#include "vertexshader.h"
#include "hwvertexshader.h"


////////////////////////////////////////////////////////////////////////////////
// Data Types
////////////////////////////////////////////////////////////////////////////////

typedef enum
{
    E_FOG_TABLE_INDEX_NONE     = 0,
    E_FOG_TABLE_INDEX_Z        = 1,
    E_FOG_TABLE_INDEX_W        = 2,

    E_FOG_TABLE_INDEX_DISCRETE = 3,

} E_FOG_TABLE_INDEX;


////////////////////////////////////////////////////////////////////////////////
// Constants
////////////////////////////////////////////////////////////////////////////////

// General Fog Constants:
#define FOG_TABLE_NUM_ENTRIES         256
#define FOG_TABLE_ENTRY_SIZE          sizeof( DWORD )
#define FOG_TABLE_FIRST_INDEX         0
#define FOG_TABLE_LAST_INDEX          ( FOG_TABLE_NUM_ENTRIES - 1 )

#define FOG_FACTOR_NO_FOG             ( 0xFFFFFFFF & FOG_TABLE_LAST_INDEX )
#define FOG_FACTOR_FULL_FOG           ( 0x00000000 & FOG_TABLE_LAST_INDEX )

#define FOG_FACTOR_MIN                FOG_FACTOR_FULL_FOG
#define FOG_FACTOR_MAX                FOG_FACTOR_NO_FOG

#define FOG_INTENSITY_MIN             0.0f
#define FOG_INTENSITY_MAX             1.0f

#define FOG_INTENSITY_TO_FACTOR_SCALE ( (float)FOG_TABLE_LAST_INDEX )

#define FOG_Z_DISCRETE_MIN            0.0f
#define FOG_Z_DISCRETE_MAX            1.0f

// Fog Table Calculation Constants:

#define FOG_TABLE_EXPONENT_MAX        10.0f

#define FOG_DENSITY_LOW_THRESHOLD     0.001f

#define FOG_MIN_W_RANGE               0.000001f

#define ONE_OVER_255                  ( 1.0f / 255.0f )

#define ONE_OVER_2BANG                0.5000000000000000000000f
#define ONE_OVER_3BANG                0.1666666666666666666667f
#define ONE_OVER_4BANG                0.0416666666666666666667f
#define ONE_OVER_5BANG                0.0083333333333333333333f
#define ONE_OVER_6BANG                0.0013888888888888888889f
#define ONE_OVER_7BANG                0.0001984126984126984127f
#define ONE_OVER_8BANG                0.0000248015873015873016f
#define ONE_OVER_9BANG                0.0000027557319223985891f
#define ONE_OVER_10BANG               0.0000002755731922398589f
#define ONE_OVER_11BANG               0.0000000250521083854417f
#define ONE_OVER_12BANG               0.0000000020876756987868f
#define ONE_OVER_13BANG               0.0000000001605904383682f

// Hardware Constants
#define PP_FOG_COLOR__FOG_INDEX_SEL__Z          0
#define PP_FOG_COLOR__FOG_INDEX_SEL__W          1
#define PP_FOG_COLOR__FOG_INDEX_SEL__DIFF_A     2
#define PP_FOG_COLOR__FOG_INDEX_SEL__SPEC_A     3

#define PP_FOG_COLOR__FOG_INDEX_SEL__DISCRETE   4


////////////////////////////////////////////////////////////////////////////////
// Macros
////////////////////////////////////////////////////////////////////////////////

//
// CLAMP_TO_RANGE:
//
// - Evaluates the result of clamping _VAL above _LOW_CLAMP and below
//   _HIGH_CLAMP.
//
#define CLAMP_TO_RANGE( _VAL, _LOW_CLAMP, _HIGH_CLAMP ) ( ( ( _VAL ) < ( _LOW_CLAMP ) ) ?       \
                                                            ( _LOW_CLAMP ) :                    \
                                                            ( ( ( _VAL ) > ( _HIGH_CLAMP ) ) ?  \
                                                                ( _HIGH_CLAMP ) :               \
                                                                ( _VAL ) ) );
//
// ATI_EXP:
//
// - Estimates e^x with 14 terms of the Taylor Series approximation:
//     ( 1 ) + ( x ) + ( x^2 / 2! ) + ( x^3 / 3! ) + ...
//   It should be quicker than using exp().
//
#define ATI_EXP( x )            ( 1.0f            +   \
                      ( ( x ) * ( 1.0f            +   \
                      ( ( x ) * ( ONE_OVER_2BANG  +   \
                      ( ( x ) * ( ONE_OVER_3BANG  +   \
                      ( ( x ) * ( ONE_OVER_4BANG  +   \
                      ( ( x ) * ( ONE_OVER_5BANG  +   \
                      ( ( x ) * ( ONE_OVER_6BANG  +   \
                      ( ( x ) * ( ONE_OVER_7BANG  +   \
                      ( ( x ) * ( ONE_OVER_8BANG  +   \
                      ( ( x ) * ( ONE_OVER_9BANG  +   \
                      ( ( x ) * ( ONE_OVER_10BANG +   \
                      ( ( x ) * ( ONE_OVER_11BANG +   \
                      ( ( x ) * ( ONE_OVER_12BANG +   \
                      ( ( x ) * ( ONE_OVER_13BANG ) ) )))))))))))))))))))))))))


////////////////////////////////////////////////////////////////////////////////
// Function Prototypes
////////////////////////////////////////////////////////////////////////////////

void FOG_FillTable( LPATID3DCNTX pContext );
void FOG_FillTable_Linear( LPATID3DCNTX pContext, DWORD *pTable, E_FOG_TABLE_INDEX eTableIndex );
void FOG_FillTable_Exponential( LPATID3DCNTX pContext, DWORD *pTable, E_FOG_TABLE_INDEX eTableIndex );

DWORD FOG_ComputeFactor_Linear( float fDistance, float fStart, float fEnd );
DWORD FOG_ComputeFactor_Exponential( float fDistance, float fDensity, BOOL bIsExpSquared );

BOOL FOG_SetWParameters( LPATID3DCNTX pContext, E_FOG_TABLE_INDEX eTableIndex );
BOOL FOG_SetTableIndex( LPATID3DCNTX pContext, E_FOG_TABLE_INDEX eTableIndex );

E_FOG_TABLE_INDEX FOG_GetTableIndex( LPATID3DCNTX pContext );


#endif

