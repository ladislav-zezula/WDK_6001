//-----------------------------------------------------------------------
// <copyright file="ClassFactory.h" company="Microsoft">
//      Copyright (c) 2005 Microsoft Corporation.  All rights reserved. 
// </copyright>
//
// Module:       
//        ClassFactory.h
//
// Description:
//  Template implementation of IClassFactory, used for inproc COM servers.
//
//-----------------------------------------------------------------------

// Externally defined functions
extern void ObjectCreated();
extern void ObjectDestroyed();
extern void ServerLock(BOOL fLock);

template<class T>
class CFactory : public IClassFactory
{
    LONG m_cRef;

public:
    CFactory(): m_cRef(0)
    {
        ObjectCreated();
    }

    ~CFactory()
    {
        ObjectDestroyed();
    }

    //-------------------------------------------------------------------------
    // Implementation of IUnknown
    //-------------------------------------------------------------------------
    STDMETHODIMP QueryInterface(REFIID riid, LPVOID * ppv)
    {
        HRESULT hr = E_NOINTERFACE;

        *ppv = 0;

        if (IID_IUnknown == riid || IID_IClassFactory == riid)
        {
            *ppv = this;
            AddRef();
            hr = S_OK;
        }

        return hr;
    }

    STDMETHODIMP_(ULONG) AddRef(void)
    {
        return static_cast<ULONG>(InterlockedIncrement(&m_cRef));
    }

    STDMETHODIMP_(ULONG) Release(void)
    {
        LONG nNewCount = InterlockedDecrement(&m_cRef);

        if (0L == nNewCount)
        {
            delete this;
        }

        return static_cast<ULONG>(nNewCount);
    }

    //-------------------------------------------------------------------------
    // IClassFactory members
    //-------------------------------------------------------------------------
    STDMETHODIMP CreateInstance(LPUNKNOWN pUnkOuter, REFIID riid, LPVOID * ppvObj)
    {
        *ppvObj = NULL;

        // We aren't supporting aggregation.
        if (NULL != pUnkOuter)
        {
            return CLASS_E_NOAGGREGATION;
        }

        IUnknown* pObj = dynamic_cast<IUnknown *>(new T());
        if (NULL == pObj)
        {
            return E_OUTOFMEMORY;
        }

        // Query the object for the requested interface
        HRESULT hr = pObj->QueryInterface(riid, ppvObj);
        if (FAILED(hr))
        {
            delete pObj;
        }

        return hr;
    }

    STDMETHODIMP LockServer(BOOL fLock)
    {
        ServerLock(fLock);

        return S_OK;
    }
};

