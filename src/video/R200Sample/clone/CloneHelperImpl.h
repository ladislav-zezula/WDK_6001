//-----------------------------------------------------------------------
//
// <copyright file="CloneHelperImpl.h" company="Microsoft">
//    Copyright © 2005 Microsoft Corporation.  All rights reserved.
// </copyright>
//
// Module:
//        CloneHelperImpl.h
//
// Description:
//        Declaration of the ICloneViewHelper object
//
// Comments: Allows TMM to put view into clone and to get and restore
//               topologys that cannot be set via GDI.
//
//-----------------------------------------------------------------------
#pragma once

#include "CloneHelper.h"
#include <windows.h>
#include <ntintsafe.h>
#include <stdio.h>
#include <stdlib.h>
#include <d3dkmthk.h>
#include <cloneumkm.h>

// declarations for global object-counters
void ObjectCreated();
void ObjectDestroyed();
void ServerLock(BOOL fLock);

class CCloneHelperImpl : public IViewHelper
{
public:
    CCloneHelperImpl();
    ~CCloneHelperImpl();

    // Static methods for registering and unregisting this class
    static HRESULT RegisterServer();
    static HRESULT UnRegisterServer();

    // IUnknown methods
    __override STDMETHODIMP         QueryInterface(REFIID, LPVOID *);
    __override STDMETHODIMP_(ULONG) AddRef();
    __override STDMETHODIMP_(ULONG) Release();

    // ICloneViewHelper methods
    __override STDMETHODIMP GetConnectedIDs(LPCWSTR     wszAdaptorName, 
                                            ULONG *     pulCount, 
                                            ULONG *     pulID, 
                                            ULONG       ulFlags);
    __override STDMETHODIMP GetActiveTopology(LPCWSTR     wszAdaptorName, 
                                              ULONG       ulSourceID, 
                                              ULONG *     pulCount, 
                                              ULONG *     pulTargetID);
    __override STDMETHODIMP SetActiveTopology(LPCWSTR     wszAdaptorName, 
                                              ULONG       ulSourceID, 
                                              ULONG       ulCount, 
                                              ULONG *     pulTargetID);
    __override STDMETHODIMP Commit();

    __override STDMETHODIMP Commit(BOOL fFinalCall);
    
    __override STDMETHODIMP SetConfiguration(IStream *   pIStream,
                                             ULONG *     pulStatus);
    __override STDMETHODIMP GetProceedOnNewConfiguration();

private:

    LONG _cRef;
    D3DKMT_INVALIDATEACTIVEVIDPN m_InvalidateActiveVidPn;
    R200_SetTopologyData m_SetTopologyData;
    BOOL m_fSATCalled;

};

