/******************************Module*Header**********************************\
*
*                           *******************
*                           * D3D SAMPLE CODE *
*                           *******************
*
* Copyright (c) 2003 Microsoft Corporation.  All rights reserved.
\*****************************************************************************/

#include "d3dcntx.h"

typedef struct _R2UMSurfaceHandle
{
    D3DKMT_HANDLE   hAllocation;
    ULONG_PTR       hR2QSSurface;
    LPBYTE          pSurfaceUM;
} R2UMSurfaceHandle, *PR2UMSurfaceHandle;

PR2UMSurfaceHandle
GetUMSurfaceHandle(
    LPATISURFCNTX   pD3DSurf);


