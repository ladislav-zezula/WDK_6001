#pragma once

// This class is used to store the context for a specific enumeration.
// Currrently, this is done by storing the object index.
class EnumContext : public IUnknown
{
public:
    EnumContext() :
        m_cRef(1),
        SearchIndex(0)
    {

    }

    ~EnumContext()
    {

    }

public: // IUnknown
    ULONG __stdcall AddRef()
    {
        InterlockedIncrement((long*) &m_cRef);
        return m_cRef;
    }

    ULONG __stdcall Release()
    {
        ULONG ulRefCount = m_cRef - 1;

        if (InterlockedDecrement((long*) &m_cRef) == 0)
        {
            delete this;
            return 0;
        }
        return ulRefCount;
    }

    HRESULT __stdcall QueryInterface(
        REFIID riid,
        void** ppv)
    {
        HRESULT hr = S_OK;

        if(riid == IID_IUnknown)
        {
            *ppv = static_cast<IUnknown*>(this);
            AddRef();
        }
        else
        {
            *ppv = NULL;
            hr = E_NOINTERFACE;
        }

        return hr;
    }

public:
    DWORD       SearchIndex;
    CAtlStringW ParentID;
private:
    DWORD       m_cRef;
};

class WpdObjectEnumerator
{
public:
    WpdObjectEnumerator();
    ~WpdObjectEnumerator();

    HRESULT Initialize(FakeDevice *pFakeDevice);

    HRESULT DispatchWpdMessage(const PROPERTYKEY&   Command,
                               IPortableDeviceValues*      pParams,
                               IPortableDeviceValues*      pResults);

    HRESULT OnStartFind(IPortableDeviceValues*  pParams,
                        IPortableDeviceValues*  pResults);

    HRESULT OnFindNext(IPortableDeviceValues*  pParams,
                       IPortableDeviceValues*  pResults);

    HRESULT OnEndFind(IPortableDeviceValues*  pParams,
                      IPortableDeviceValues*  pResults);

private:
    HRESULT CreateEnumContext(ContextMap* pContextMap,  LPCWSTR pszParentID, __out LPWSTR* ppszEnumContext);
    HRESULT DestroyEnumContext(ContextMap* pContextMap, LPCWSTR pszEnumContext);

    HRESULT GetObjectIDs(ContextMap* pContextMap, const DWORD dwNumObjects, LPCWSTR pszEnumContext, IPortableDevicePropVariantCollection** ppCollection);

    FakeDevice* m_pFakeDevice;
};
