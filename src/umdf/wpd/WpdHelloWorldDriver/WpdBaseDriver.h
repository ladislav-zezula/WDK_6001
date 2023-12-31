#pragma once

class WpdBaseDriver :
    public IUnknown
{
public:
    WpdBaseDriver();
    virtual ~WpdBaseDriver();

    HRESULT Initialize();
    VOID    Uninitialize();

    HRESULT DispatchWpdMessage(IPortableDeviceValues* pParams,
                               IPortableDeviceValues* pResults);

private:
    HRESULT OnGetObjectIDsFromPersistentUniqueIDs(IPortableDeviceValues* pParams,
                                                  IPortableDeviceValues* pResults);

public: // IUnknown
    ULONG __stdcall AddRef();
    ULONG __stdcall Release();
    HRESULT __stdcall QueryInterface(REFIID riid, void** ppv);

public:
    WpdObjectEnumerator m_ObjectEnum;
    WpdObjectProperties m_ObjectProperties;
    WpdObjectResources  m_ObjectResources;
    WpdCapabilities     m_Capabilities;

private:
    ULONG m_cRef;
};

