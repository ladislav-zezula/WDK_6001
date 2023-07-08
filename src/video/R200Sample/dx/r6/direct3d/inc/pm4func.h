#ifndef PM4FUNC_H
#define PM4FUNC_H

#include "qs.h"

typedef struct _D3DCMDBUFF
{
    DWORD            dwFlags;                        // Flags keep track of Qs status.
    ULONG_PTR        hCB;                            // QS Handle given to this buffer
    ULONG_PTR        lpCBOffset;                     // pointer to free entry in CURRENT CB
    DWORD            dwCBLeftDW;                     // DWORDS left in current CB

    void             *pList;                         // original indirect buffer poitner
    ULONG_PTR        hOutList;
    //DWORD          dwRefCount;                     // Number of 3D contexts this CB is shared by
    DWORD_PTR        dwCBOwner;                      // Context that houses this CB

    // # of DWORD always stored at the begining of each CB. If a CB only contains these DWORD,
    // no need to do submit.
    DWORD            dwPreambleSize;

    // QS info.
    QS_FUNC2   *pQS_APIFunc;
    QS_CAPS    *pQSCaps;
    QS_PARAM   *pQSParam;
    QS_HCLIENT QSHClient;
    QS_HDEVICE QSHDevice;

    // We need this to call QS functions for Win2K
    struct _ATIDXOBJECT* pAtiObj;

    // For each CB created by D3D,we give it a uniqe ID in GetNewCB. This ID
    // is saved in lpD3DDevice. dwPendingCB_ID represents the ID this CB has (or
    // this context has since there is one to one correspondence between
    // D3DCMDBUFF and D3D context. Note CB_ID starts from 1.
    DWORD  dwPendingCB_ID;

    // Sometimes we need know the status of last submitted command buffer after
    // calling FlushCmdBuff, but the dwPendingCB_ID is increased after GetNewCmdBuff
    // in FlushCmdBuff. Therefore, for convenience, we use this variable to check the
    // time stamp status of submitted command buffer.
    DWORD  dwSubmittedCB_ID;

    // Number of draw prims in this packet.  Many draw prim ops could fit in
    // in the same packet if they are use HW IBs and VBs.  This causes
    // the app to stall when it tries to lock a VB until the entire command
    // packet has be parsed.  This value is keyed off of to flush the commmand
    // buffer and avoid this scenerio.
    DWORD  dwPrims;

    // Keeps track whether some registers should be written at the beginning of CB
    BOOL    bWrite3DContext;

} D3DCMDBUFF, *LPD3DCMDBUFF;

#ifdef NULL_D3DHW
void GetNewCmdBuffInit(LPD3DCMDBUFF lpATiCB);
#endif

BOOL CheckTimeStampConsumed(struct _D3DDEVICE *pD3DDev, DWORD dwFlags, QS_TIMESTAMP ts);
BOOL CheckTimeStampRetired(struct _D3DDEVICE *pD3DDev, DWORD dwFlags, QS_TIMESTAMP ts);

void GetNewCmdBuff(LPD3DCMDBUFF lpATiCB, BOOL bWrite3DContex, BOOL bVMST);
HRESULT SubmitCmdBuff(LPD3DCMDBUFF lpATiCB, DWORD dwFlags);
void FreeCmbBuff(LPD3DCMDBUFF lpATiCB);
HRESULT FlushCmdBuff(LPD3DCMDBUFF lpATiCB);
LPDWORD GetPM4Entries(DWORD NumEntriesNeeded, LPD3DCMDBUFF lpCmdB);
LPDWORD GetEmptyPM4Entries(DWORD NumEntriesNeeded, LPD3DCMDBUFF lpCmdB);
void SubmitPM4EntriesToHw (DWORD NumEntriesUsed, DWORD dwNumSurfacesUsed, LPD3DCMDBUFF lpCmdB);
HRESULT SubmitAndWaitIdle( struct _ATID3DCNTX  *pContext );
void Write3DContext( LPD3DCMDBUFF lpATiCB );

BOOL CheckSurfTimeStampRetired (struct _D3DDEVICE *pD3DDev, struct HSLSurfInfo* lpSurfInfo,
                                DWORD dwSurfaceHandle, DWORD dwFlags);

BOOL CheckBuffTimeStampRetired (struct _D3DDEVICE *pD3DDev, DWORD *pdwhContextID, DWORD *pdwPendingCB_ID, DWORD dwFlags);
BOOL CheckVbuffTimeStampRetired (struct _D3DDEVICE *pD3DDev, struct _ATIVERTEXBUFFER *lpVtxBuffInfo, DWORD dwFlags);
BOOL CheckPVSTimeStampRetired(struct _D3DDEVICE *pD3DDev, struct _ATIVTXSHADERMEMALLOC *pVSMemAlloc, DWORD dwFlags);
BOOL CheckVbuffTimeStampConsumed (struct _D3DDEVICE *pD3DDev, struct _ATIVERTEXBUFFER *lpVtxBuffInfo, DWORD dwFlags);
BOOL CheckPVSTimeStampConsumed(struct _D3DDEVICE *pD3DDev, struct _ATIVTXSHADERMEMALLOC *pVSMemAlloc, DWORD dwFlags);

#endif // PM4FUNC_H

