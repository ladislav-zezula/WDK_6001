

//
//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//


//
// This macro converts the Pixel Width of the ZBuffer to the
// HW format.
//
// Note that here we take advantage of a trick in the hardware.  The
// format enumeral value for k bit W buffers is 7 more than the
// format enumeral value for k bit Z buffers.  That is, the format
// number for 16-bit Floating point W buffers is seven more than the
// format for 16-bit integer Z buffers.  Since we only use integer
// Z buffers and floating point W buffers, this is all we need to
// know.  If this layout changes, we will have to rethink this code.
//

#include "atidxinc.h"
#include "d3d_hw_enum.h"
#include "d3ddevice.h"

__inline DWORD GetZPixFormat(D3DDEVICE *pD3DDev, LPATISURFCNTX lpZBufferCntx, BOOL bUseWBuffer)
{
    DWORD dwWBufferOffset = bUseWBuffer ? 7 : 0;

    switch(GetSurfCntxBPP(lpZBufferCntx))
    {
        case 32:
          {
            if(lpZBufferCntx->ddpfSurface.dwZBitMask == 0xFFFFFFFF)
                return ZSTENCILCNTL_DEPTH_FORMAT_32_FIXED + dwWBufferOffset;       // No Stencil / 32bit ZBuffer
            else
                return ZSTENCILCNTL_DEPTH_FORMAT_24_FIXED + dwWBufferOffset;      // 8 Bit Stencil / 24 Bit ZBuffer
          }
            break;
        case 24:
            return ZSTENCILCNTL_DEPTH_FORMAT_24_FIXED + dwWBufferOffset;       // No Stencil / 24 bit ZBuffer
            break;

        default:
            if ( bUseWBuffer )
            {
                return ZSTENCILCNTL_DEPTH_FORMAT_24_WFLOAT;
            }
            else
            {
                return ZSTENCILCNTL_DEPTH_FORMAT_16_FIXED;
            }
    }
}

