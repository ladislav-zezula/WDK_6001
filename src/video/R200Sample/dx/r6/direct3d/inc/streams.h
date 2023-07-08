

//    
//  Workfile: Streams.h
//
//  Description:
//      Vertex Streams declarations and definitions.
//
//  Trade secret of ATI Technologies, Inc.
//  Copyright 2000, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//

#ifndef _STREAMS_H_
#define _STREAMS_H_


#include "vertexshader.h"

///////////////////////////////////////////////////////////////////////////////
// Definitions

 
// Flags


///////////////////////////////////////////////////////////////////////////////
//  External Vertex Stream functions

HRESULT ST_ForceStreamZeroForShader( struct _ATID3DCNTX *pContext);

HRESULT AtiSetStreamSource(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND *lppCmd);

VOID ST_AttachSourceToD3DStream( struct _ATID3DCNTX *pContext, 
                                 DWORD dwStream, 
                                 DWORD dwVBHandle, 
                                 DWORD dwOffset, // stream offset 
                                 DWORD dwStride );
VOID ST_AttachSourceToD3DStreamUM( struct _ATID3DCNTX *pContext,
                                   struct _ATIVERTEXBUFFER *lpUMVB,
                                   DWORD dwStride,
                                   LPBYTE lpVertices,
                                   DWORD dwVertexLength );


#endif // _STREAMS_H_


