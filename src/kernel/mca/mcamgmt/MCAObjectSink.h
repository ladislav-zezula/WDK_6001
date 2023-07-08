/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:

    MCAObjectSink.h

Abstract:

    (See module header of MCAObjectSink.cpp)

[Notes:]

    Header file for MCAObjectSink.cpp
     
--*/

#ifndef MCAOBJECTSINK_H
#define MCAOBJECTSINK_H

#include "mca.h"
#include <dontuse.h>

class MCATestEngine;

class MCAObjectSink : public IWbemObjectSink
{ 

public:

    //
    // Public function prototypes
    //
    MCAObjectSink();
    ~MCAObjectSink(){}; 

    //
    // IUnknown functions
    //
    virtual ULONG STDMETHODCALLTYPE AddRef();
    virtual ULONG STDMETHODCALLTYPE Release();
    
    virtual HRESULT STDMETHODCALLTYPE QueryInterface(IN REFIID riid,
                                                     OUT VOID** ppv);

    // IWbemObjectSink methods
    virtual HRESULT STDMETHODCALLTYPE Indicate(IN LONG lObjectCount,
                                               IN IWbemClassObject __RPC_FAR *__RPC_FAR *apObjArray
                                               );
    
    virtual HRESULT STDMETHODCALLTYPE SetStatus(IN LONG lFlags,
                                                IN HRESULT hResult,
                                                IN BSTR strParam,
                                                IN IWbemClassObject __RPC_FAR *pObjParam
                                                );
private:
      
    //
    // Private variable declarations
    //    
    __volatile LONG referenceCount;      
};

#endif

