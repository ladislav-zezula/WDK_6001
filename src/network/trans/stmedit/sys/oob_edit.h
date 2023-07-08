/*++

Copyright (c) Microsoft Corporation. All rights reserved

Abstract:

    Stream Edit Callout Driver Sample.
    
    This sample demonstrates Out-of-band (OOB) stream inspection/editing 
    via the WFP stream API.

Environment:

    Kernel mode

--*/

#ifndef _OOB_EDIT_H
#define _OOB_EDIT_H

typedef enum OOB_EDIT_STATE_
{
   OOB_EDIT_IDLE,
   OOB_EDIT_PROCESSING,
   OOB_EDIT_BUSY,
   OOB_EDIT_SHUT_DOWN,
   OOB_EDIT_ERROR
} OOB_EDIT_STATE;

typedef struct OUTGOING_STREAM_DATA_ 
{
   LIST_ENTRY listEntry;

   NET_BUFFER_LIST* netBufferList;
   BOOLEAN isClone;
   SIZE_T dataLength;
   DWORD streamFlags;
   PMDL mdl;
} OUTGOING_STREAM_DATA;

typedef struct STREAM_EDITOR_ STREAM_EDITOR;

NTSTATUS
OobEditInit(
   OUT STREAM_EDITOR*
   );

void
OobEditShutdown(
   OUT STREAM_EDITOR* streamEditor
   );

void 
NTAPI
StreamOobEditClassify(
   IN const FWPS_INCOMING_VALUES0* inFixedValues,
   IN const FWPS_INCOMING_METADATA_VALUES0* inMetaValues,
   IN OUT void* layerData,
   IN const FWPS_FILTER0* filter,
   IN UINT64 flowContext,
   OUT FWPS_CLASSIFY_OUT0* classifyOut
   );


#endif // _OOB_EDIT_H

