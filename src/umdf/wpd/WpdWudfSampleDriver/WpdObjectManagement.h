#pragma once

// This class is used to store the context for a specific enumeration.
// Currently, this is done by storing the object index.
class ObjectManagementContext  : public IUnknown
{
public:
    ObjectManagementContext() :
        m_cRef(1)
    {

    }

    ~ObjectManagementContext()
    {

    }

public:
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
    CAtlStringW                     Name;
    CComPtr<IPortableDeviceValues>  ObjectProperties;
private:
    DWORD       m_cRef;
};

class WpdObjectManagement
{
public:
    WpdObjectManagement();
    ~WpdObjectManagement();

    HRESULT Initialize(FakeDevice *pFakeDevice);

    HRESULT DispatchWpdMessage(const PROPERTYKEY&   Command,
                               IPortableDeviceValues*      pParams,
                               IPortableDeviceValues*      pResults);

    HRESULT OnDelete(IPortableDeviceValues*  pParams,
                     IPortableDeviceValues*  pResults);

    HRESULT OnCreateObjectWithPropertiesOnly(IPortableDeviceValues*  pParams,
                                             IPortableDeviceValues*  pResults);

    HRESULT OnCreateObjectWithPropertiesAndData(IPortableDeviceValues*  pParams,
                                                IPortableDeviceValues*  pResults);

    HRESULT OnWriteObjectData(IPortableDeviceValues*  pParams,
                              IPortableDeviceValues*  pResults);

    HRESULT OnRevert(IPortableDeviceValues*  pParams,
                     IPortableDeviceValues*  pResults);

    HRESULT OnCommit(IPortableDeviceValues*  pParams,
                     IPortableDeviceValues*  pResults);

    HRESULT OnMove(IPortableDeviceValues*  pParams,
                   IPortableDeviceValues*  pResults);

    HRESULT OnCopy(IPortableDeviceValues*  pParams,
                   IPortableDeviceValues*  pResults);

private:
    HRESULT CreateObjectManagementContext(
        ContextMap*             pContextMap,
        LPCWSTR                 pszObjectName,
        IPortableDeviceValues*  pObjectProperties,
        __out LPWSTR*           ppszObjectManagementContext);
    HRESULT DestroyObjectManagementContext(
        ContextMap* pContextMap,
        LPCWSTR     pszObjectManagementContext);

    FakeDevice*                                   m_pFakeDevice;
};
