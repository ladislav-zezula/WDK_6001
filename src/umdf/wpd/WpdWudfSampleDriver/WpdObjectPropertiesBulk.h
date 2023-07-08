#pragma once

// This class is used to store the context for a specific enumeration.
// Currently, this is done by storing the object index.
class BulkPropertiesContext : public IUnknown
{
public:
    BulkPropertiesContext() :
        NextObject(0),
        m_cRef(1)
    {

    }

    ~BulkPropertiesContext()
    {

    }

    CComPtr<IPortableDevicePropVariantCollection> ObjectIDs;
    DWORD                                         NextObject;
    CComPtr<IPortableDeviceKeyCollection>         Properties;
    CComPtr<IPortableDeviceValuesCollection>      ValuesCollection;

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

private:
    DWORD m_cRef;
};

class WpdObjectPropertiesBulk
{
public:
    WpdObjectPropertiesBulk();
    ~WpdObjectPropertiesBulk();

    HRESULT Initialize(FakeDevice *pFakeDevice);

    HRESULT DispatchWpdMessage(const PROPERTYKEY&   Command,
                               IPortableDeviceValues*      pParams,
                               IPortableDeviceValues*      pResults);

    HRESULT OnGetValuesByObjectListStart(IPortableDeviceValues*  pParams,
                                         IPortableDeviceValues*  pResults);

    HRESULT OnGetValuesByObjectListNext(IPortableDeviceValues*  pParams,
                                        IPortableDeviceValues*  pResults);

    HRESULT OnGetValuesByObjectListEnd(IPortableDeviceValues*  pParams,
                                       IPortableDeviceValues*  pResults);

    HRESULT OnGetValuesByObjectFormatStart(IPortableDeviceValues*  pParams,
                                           IPortableDeviceValues*  pResults);

    HRESULT OnGetValuesByObjectFormatNext(IPortableDeviceValues*  pParams,
                                          IPortableDeviceValues*  pResults);

    HRESULT OnGetValuesByObjectFormatEnd(IPortableDeviceValues*  pParams,
                                         IPortableDeviceValues*  pResults);

    HRESULT OnSetValuesByObjectListStart(IPortableDeviceValues*  pParams,
                                         IPortableDeviceValues*  pResults);

    HRESULT OnSetValuesByObjectListNext(IPortableDeviceValues*  pParams,
                                        IPortableDeviceValues*  pResults);

    HRESULT OnSetValuesByObjectListEnd(IPortableDeviceValues*  pParams,
                                       IPortableDeviceValues*  pResults);

private:

    HRESULT CreateBulkPropertiesContext(ContextMap*                           pContextMap,
                                        IPortableDevicePropVariantCollection* pObjectIDs,
                                        IPortableDeviceKeyCollection*         pProperties,
                                        __out LPWSTR*                         ppszBulkPropertiesContext);

    HRESULT CreateBulkPropertiesContext(ContextMap*                           pContextMap,
                                        REFGUID                               guidObjectFormat,
                                        LPCWSTR                               pszParentObjectID,
                                        DWORD                                 dwDepth,
                                        IPortableDeviceKeyCollection*         pProperties,
                                        __out LPWSTR*                         ppszBulkPropertiesContext);

    HRESULT CreateBulkPropertiesContext(ContextMap*                           pContextMap,
                                        IPortableDeviceValuesCollection*      pValuesCollection,
                                        __out LPWSTR*                         ppszBulkPropertiesContext);

    HRESULT DestroyBulkPropertiesContext(ContextMap* pContextMap, LPCWSTR pszBulkPropertiesContext);

    FakeDevice*                     m_pFakeDevice;
};
