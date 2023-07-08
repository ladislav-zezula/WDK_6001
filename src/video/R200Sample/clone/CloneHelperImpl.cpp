//-----------------------------------------------------------------------
//
// <copyright file="CloneHelperImpl.cpp" company="Microsoft">
//    Copyright © 2005 Microsoft Corporation.  All rights reserved.
// </copyright>
//
// Module:
//        CloneHelperImpl.cpp
//
// Description:
//        Implements COM object for setting display into clone view
//
//-----------------------------------------------------------------------
#include <windows.h>
#include <cfgmgr32.h>
#include <strsafe.h>
#include "CloneHelperImpl.h"
#include "ClassFactory.h"
#include "StreamHelper.h"

#include "CloneHelper.h"
#include "CloneHelper_i.c"

__encoded_pointer PFND3DKMT_OPENADAPTERFROMHDC g_OpenAdapterFromHdcThunk = NULL;
__encoded_pointer PFND3DKMT_INVALIDATEACTIVEVIDPN g_InvalidateActiveVidPnThunk = NULL;
__encoded_pointer PFND3DKMT_ESCAPE  g_EscapeThunk = NULL;


#define GETID_TARGET GETCONNECTEDIDS_TARGET
#define GETID_SOURCE GETCONNECTEDIDS_SOURCE

#define SET_TOPOLOGY 1

#define SET_CLONE 1
#define SET_SINGLEVIEW 2
  
HMODULE g_hModule = NULL;

static const int MAX_PATH_LENGTH = 1024;
static const int s_RegKeyLength = MAX_GUID_STRING_LEN + 6;

HINSTANCE g_hInstance = NULL;

//-----------------------------------------------------------------------------
// Utility functions
//-----------------------------------------------------------------------------

inline DWORD RegValueLen(const CHAR* val)
{
    return static_cast<DWORD>((strlen(val) + 1) * sizeof(CHAR));
}

HRESULT ConvertUnicodeToAnsi(__deref_out LPSTR* ppszDst, __in LPCWSTR pwszSrc)
{
    int nLength =0;
    nLength = wcslen(pwszSrc)+1; //1 for NULL terminator
      
    //Determine the bytes to be allocated for ansi string
    int nAnsiBytes = nLength * sizeof(CHAR);     

    *ppszDst = new CHAR[nAnsiBytes];
    if(NULL == *ppszDst)
    {
        return E_OUTOFMEMORY;
    }
    
    if (0 ==WideCharToMultiByte(CP_ACP, 0, pwszSrc,nLength,*ppszDst, nAnsiBytes,NULL,NULL ))
    {
       delete [] *ppszDst; 
       return E_FAIL;
    }

    return S_OK;
}

CHAR* GetRegKeyPath(__out_ecount(len) CHAR* szKeyPath, long len)
{
    WCHAR wszGUID[MAX_GUID_STRING_LEN];
    CHAR* szGUID = NULL;
    
    StringFromGUID2(CLSID_CloneViewHelper, wszGUID, MAX_GUID_STRING_LEN);

     //This sample is UNICODE independent hence convert UNICODE string to ANSI.  
    if(FAILED(ConvertUnicodeToAnsi(&szGUID, wszGUID)))
        return NULL;

    StringCchPrintfA(szKeyPath, len, "CLSID\\%s", szGUID);    
    delete [] szGUID; 
    return szKeyPath;
}


HRESULT LoadThunks()
{
        g_hModule = LoadLibraryA("gdi32.dll");
        if (g_hModule == NULL)
        {
            printf("ThunkTest - Unable to load gdi32.dll.\n");
            return E_FAIL;
        }

        g_OpenAdapterFromHdcThunk = (PFND3DKMT_OPENADAPTERFROMHDC)EncodePointer(GetProcAddress(g_hModule, "D3DKMTOpenAdapterFromHdc"));
        g_InvalidateActiveVidPnThunk = (PFND3DKMT_INVALIDATEACTIVEVIDPN)EncodePointer(GetProcAddress(g_hModule, "D3DKMTInvalidateActiveVidPn"));
        g_EscapeThunk = (PFND3DKMT_ESCAPE)EncodePointer(GetProcAddress(g_hModule, "D3DKMTEscape"));

        PFND3DKMT_OPENADAPTERFROMHDC pFunctionOpen = (PFND3DKMT_OPENADAPTERFROMHDC)DecodePointer(g_OpenAdapterFromHdcThunk);
        PFND3DKMT_INVALIDATEACTIVEVIDPN pFunctionInvalidateVidPn = (PFND3DKMT_INVALIDATEACTIVEVIDPN)DecodePointer(g_InvalidateActiveVidPnThunk);
        PFND3DKMT_ESCAPE pFunctionEscape = (PFND3DKMT_ESCAPE)DecodePointer(g_EscapeThunk);

        if ((pFunctionOpen == NULL) ||
            (pFunctionInvalidateVidPn == NULL) ||
            (pFunctionEscape == NULL))
        {
            printf("Unable to locate thunk addresses.\n");
            return E_FAIL;
        }

        return S_OK;
}


HRESULT GetAdapterHandle(__in LPCWSTR wszAdapterKey, __out D3DKMT_HANDLE * pKMHandle)
{
    DISPLAY_DEVICEA AdapterInfo = {0};
    AdapterInfo.cb = sizeof(AdapterInfo);

    DISPLAY_DEVICEA DeviceInfo = {0};
    DeviceInfo.cb = sizeof(DeviceInfo);

    LPSTR szAdapterName =NULL;
    LPSTR szDeviceName = NULL;
    HDC hdc = NULL;  
    HRESULT hr;
    LPSTR szAdapterKey;

    D3DKMT_OPENADAPTERFROMHDC OpenAdapterFromHdcArg; 
    ZeroMemory(&OpenAdapterFromHdcArg,sizeof(OpenAdapterFromHdcArg));

     //This sample is UNICODE independent hence convert UNICODE string to ANSI.   
    if(FAILED(hr = ConvertUnicodeToAnsi(&szAdapterKey, wszAdapterKey)))
        return hr;

    //Enumerate all adapters and get the device name
    for(DWORD dwAdapter = 0;
        ::EnumDisplayDevicesA(NULL, dwAdapter, &AdapterInfo, 0);
        dwAdapter++)
    {
        //Only take the active adapters        
        if (AdapterInfo.StateFlags & (DISPLAY_DEVICE_MIRRORING_DRIVER | DISPLAY_DEVICE_REMOTE | DISPLAY_DEVICE_DISCONNECT))
        {
            continue;
        }
       
        if(DISPLAY_DEVICE_ATTACHED_TO_DESKTOP == (AdapterInfo.StateFlags & DISPLAY_DEVICE_ATTACHED_TO_DESKTOP))
        {
            if(CSTR_EQUAL == CompareStringA(LOCALE_USER_DEFAULT, 0, AdapterInfo.DeviceKey, -1, szAdapterKey, -1))
            {
                        szAdapterName = AdapterInfo.DeviceName;   
                        break;
            }
            else
            {
                continue;
            }
        }
    }

    if(NULL == szAdapterName)
    {
        OutputDebugStringA("Could not find the adapter");
        delete [] szAdapterKey;
        return ERROR_GRAPHICS_INVALID_DISPLAY_ADAPTER;
    }
        
    //load thunks
    hr = LoadThunks();
    if(FAILED(hr))
    {
        delete [] szAdapterKey;
        return E_FAIL;
    }
        
    //Open a handle to device       
    hdc = CreateDCA(NULL,szAdapterName,NULL,NULL);
    if(NULL == hdc)
    {
        OutputDebugStringA("Unable to create DC ");
        delete [] szAdapterKey;
        return E_FAIL;
    }
    
    //Open adapter
    OpenAdapterFromHdcArg.hDc = hdc;

    PFND3DKMT_OPENADAPTERFROMHDC pFunctionOpen = (PFND3DKMT_OPENADAPTERFROMHDC)DecodePointer(g_OpenAdapterFromHdcThunk);

    if (pFunctionOpen && NT_SUCCESS(pFunctionOpen(&OpenAdapterFromHdcArg)))
    {
        *pKMHandle = OpenAdapterFromHdcArg.hAdapter;
        delete [] szAdapterKey;
        return S_OK;
    }
    else
    {
        OutputDebugStringA("Failed to open adapter from hdc");
        delete [] szAdapterKey;
        return E_FAIL;
    }
}

HRESULT WriteGUIDToRegistry()
{
    CHAR * pszDeviceKey = NULL;
    DISPLAY_DEVICEA dd;
    dd.cb = sizeof(dd);
    CHAR* szGUID = NULL;
     HKEY hGUIDKey = NULL;
     CHAR* szKeyValue = "UserModeDriverGUID";
     HRESULT hr;
     LONG lRet;
     
    //Write GUID value to the registry       
    WCHAR wszGUID[MAX_GUID_STRING_LEN];
    StringFromGUID2(CLSID_CloneViewHelper, wszGUID, MAX_GUID_STRING_LEN);   

    //This sample is UNICODE independent hence convert UNICODE string to ANSI.               
    if(FAILED(hr = ConvertUnicodeToAnsi(&szGUID, wszGUID)))
    {
        return hr;
    }

       //Enumerate all devices
    for(DWORD DeviceIndex=0; EnumDisplayDevicesA(NULL,DeviceIndex,&dd,0);++DeviceIndex)
    {
            if (dd.StateFlags & (DISPLAY_DEVICE_MIRRORING_DRIVER | DISPLAY_DEVICE_REMOTE | DISPLAY_DEVICE_DISCONNECT))
            {
                continue;
            }
            
            //
            //Device key is of the form \Registry\Machine\System\CurrentControlSet\Control\Video\{CA0D2C66-819E-45A3-A8FD-794898CDB4AC}\0000
            //Skip \\Registry\\Machine\\
            //
            pszDeviceKey = dd.DeviceKey + strlen("\\Registry\\Machine\\");          
            
            //Now write the GUID of your COM object as a string value under the device key          
            if (ERROR_SUCCESS != (lRet = RegOpenKeyExA(HKEY_LOCAL_MACHINE, pszDeviceKey, 0, 
            KEY_SET_VALUE, &hGUIDKey)))
            {
                printf("OpenKey Failed");
                return E_FAIL;
            }else if(ERROR_SUCCESS != (RegSetValueExA(hGUIDKey, szKeyValue, 0, REG_SZ, (const BYTE *) szGUID, (DWORD)(MAX_GUID_STRING_LEN*sizeof(CHAR)))))
            {
                printf("SetKeyFailed");
                RegCloseKey(hGUIDKey);
                return E_FAIL;
            }
            RegCloseKey(hGUIDKey);
    }

    delete [] szGUID;    
    return S_OK;    
}

//-----------------------------------------------------------------------------
// Methods for registering and unregistering the COM objects
//-----------------------------------------------------------------------------


//***************************************************************************
// Count number of objects and number of locks on this DLL.
//***************************************************************************

static LONG s_cObj  = 0;
static LONG s_cLock = 0;

/////////////////////////////////////////////////////////////////////////
//                                          
// DllGetClassObject
// 
// Used to create COM objects, this function returns the IClassFactory
//
// Parameters:
//        rclsid : [in] The handle to the instance of this Dll
//        riid : [in] The reason that the DllMain was called.
//        ppv: [in] 
//
// Return Values:
//        TRUE if successful, FALSE otherwise.
/////////////////////////////////////////////////////////////////////////
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID * ppv)
{
    //  Verify the caller is asking for our type of object.
    if (CLSID_CloneViewHelper != rclsid)
    {
        return E_FAIL;
    }

    // Create a new class factory.
    CFactory<CCloneHelperImpl>* pFactory = new CFactory<CCloneHelperImpl>();
    if (pFactory == NULL)
    {
        return E_OUTOFMEMORY;
    }

    // Verify we can get an instance.
    HRESULT hr = pFactory->QueryInterface(riid, ppv);
    if (FAILED(hr))
    {
        delete pFactory;
    }

    return hr;
}

/////////////////////////////////////////////////////////////////////////
//                                          
// DllCanUnloadNow
// 
// Determines whether the Dll can be unloaded based on the number of objects
// that are still active and if the server has been locked.
//
// Parameters:
//        None
//
// Return Values:
//        S_OK if there are no active objects or locks, S_FALSE otherwise.
/////////////////////////////////////////////////////////////////////////
STDAPI DllCanUnloadNow()
{
     return (s_cObj == 0 && s_cLock == 0) ? S_OK : S_FALSE;
}

/////////////////////////////////////////////////////////////////////////
//                                          
// ObjectCreated
// 
// Increments the object counter for this Dll.
//
// Parameters:
//      None
//
// Return Values:
//        None
/////////////////////////////////////////////////////////////////////////
void ObjectCreated()
{
    InterlockedIncrement(&s_cObj);
}

/////////////////////////////////////////////////////////////////////////
//                                          
// ObjectDestroyed
// 
// Decremtents the object counter for this dll.
//
// Parameters:
//      None
//
// Return Values:
//      None
/////////////////////////////////////////////////////////////////////////
void ObjectDestroyed()
{
    InterlockedDecrement(&s_cObj);
}

/////////////////////////////////////////////////////////////////////////
//                                          
// ServerLock
// 
// Increments or decrements the global lock count on this Dll.
//
// Parameters:
//        fLock : [in] TRUE to increment, FALSE to decrement
//
// Return Values:
//        None
/////////////////////////////////////////////////////////////////////////
void ServerLock(BOOL fLock)
{
    if (fLock)
    {
        InterlockedIncrement(&s_cLock);
    }
    else
    {
        InterlockedDecrement(&s_cLock);
    }
}

/////////////////////////////////////////////////////////////////////////
//                                          
// DllRegisterServer
// 
//  Standard OLE entry point for registering the server.
//
// Parameters:
//        None
//
// Return Values:
//      S_OK        Registration was successful
//      E_FAIL      Registration failed.
//
/////////////////////////////////////////////////////////////////////////
__declspec(dllexport) HRESULT DllRegisterServer()
{
    return CCloneHelperImpl::RegisterServer();
}

/////////////////////////////////////////////////////////////////////////
//                                          
// DllUnregisterServer
// 
// Standard OLE entry point for unregistering the server.
//
// Parameters:
//      None
//
// Return Values:
//      S_OK        Unregistration was successful
//      E_FAIL      Unregistration failed.
//
/////////////////////////////////////////////////////////////////////////
__declspec(dllexport) HRESULT DllUnregisterServer(void)
{
    return CCloneHelperImpl::UnRegisterServer();
}

///////////////////////////////////////////////////////////////////////////////
//                                          
// CCloneHelperImpl::RegisterServer
// 
//  Registers the server by adding the regkeys that are associated
//  with it.
//
// Parameters:
//   None
//
// Return Values:
//      S_OK        Registration was successful
//      E_FAIL      Registration failed.
//
// Comments:
///////////////////////////////////////////////////////////////////////////////
HRESULT CCloneHelperImpl::RegisterServer()
{
    HKEY hKey    = NULL;
    HKEY hSubkey = NULL;
    HRESULT hr   = E_FAIL;
    LONG lRes    = 0;
    CHAR* szAgentName = "CloneViewHelper";
    CHAR* szIPSKey    = "InprocServer32";
    CHAR* szTMValue   ="Both";
    CHAR* szTM        = "ThreadingModel";
    CHAR szPath[MAX_PATH_LENGTH] = {0};
    
    // Build the path to the regkey
    CHAR szKeyPath[s_RegKeyLength];
    GetRegKeyPath(szKeyPath, s_RegKeyLength);

    if (ERROR_SUCCESS != (lRes = RegCreateKeyExA(HKEY_CLASSES_ROOT, szKeyPath, 0, NULL, 
                            REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hKey, NULL)))
    {
        // LOG_ERROR(L"RegCreateKeyEx failed", lRes);
    }

    else if (ERROR_SUCCESS != (lRes = RegSetValueExA(hKey, 0, 0, REG_SZ, (const BYTE *) szAgentName, RegValueLen(szAgentName))))
    {
        // LOG_ERROR(L"RegSetValueEx failed", lRes);
    }

    else if (ERROR_SUCCESS != (lRes = RegCreateKeyExA(hKey, szIPSKey, 0, NULL, 
                            REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hSubkey, NULL)))
    {
        // LOG_ERROR(L"RegCreateKeyEx failed", lRes);
    }

    // Get the module path
    else if (GetModuleFileNameA(g_hInstance, szPath, MAX_PATH_LENGTH) == 0)
    {
        // lRes = GetLastError();
        // LOG_ERROR(L"GetModuleFileNameW failed", lRes);
    }

    else if (ERROR_SUCCESS != (lRes = RegSetValueExA(hSubkey, 0, 0, REG_SZ, (const BYTE *) szPath, RegValueLen(szPath))))
    {
        // LOG_ERROR(L"RegSetValueEx failed", lRes);
    }

    else if (ERROR_SUCCESS != (lRes = RegSetValueExA(hSubkey, szTM, 0, REG_SZ, (const BYTE *) szTMValue, RegValueLen(szTMValue))))
    {
        // LOG_ERROR(L"RegSetValueEx failed", lRes);
    }
    else
    {
        hr = S_OK;
    }   

    if (SUCCEEDED(hr))
    {     
        //Write the GUID value under all device keys names
        hr = WriteGUIDToRegistry();
    }        
    
    if (NULL != hSubkey)
    {
        RegCloseKey(hSubkey);
    }
    
    if (NULL != hKey)
    {
        RegCloseKey(hKey);
    }
   
    return hr;
}
    
inline LONG RecurseDeleteKey(HKEY hKeyRoot, LPCTSTR lpszKey)
{
    HKEY hkey = NULL;
    
    LONG lRes = ::RegOpenKeyEx(hKeyRoot, lpszKey, 0, KEY_ALL_ACCESS, &hkey);
    
    if (lRes == ERROR_SUCCESS)
    {
        FILETIME time;
        DWORD dwSize = 256;
        TCHAR szBuffer[256];
        while (::RegEnumKeyEx(hkey, 0, szBuffer, &dwSize, NULL, NULL, NULL,
            &time) == ERROR_SUCCESS)
        {
            lRes = RecurseDeleteKey(hkey, szBuffer);
            
            if (lRes != ERROR_SUCCESS)
            {
                break;
            }

            dwSize = 256;
        }
        
        ::RegCloseKey(hkey);

        if (lRes == ERROR_SUCCESS)
        {
            lRes = ::RegDeleteKey(hKeyRoot, lpszKey);
        }
    }

    return lRes;
}

///////////////////////////////////////////////////////////////////////////////
//                                          
// CCloneHelperImpl::UnRegisterServer
// 
//  Unregisters the server by deleting the regkeys that are associated
//  with it.
//
// Parameters:
//   None
//
// Return Values:
//      Always returns S_OK
//
// Comments:
///////////////////////////////////////////////////////////////////////////////
HRESULT CCloneHelperImpl::UnRegisterServer()
{
    // Get the path to the COM Server's key  
    CHAR szKeyPath[s_RegKeyLength];
    GetRegKeyPath(szKeyPath, s_RegKeyLength);
    
    // Recursively delete the COM Server's key from the registry
    (void)RecurseDeleteKey(HKEY_CLASSES_ROOT, szKeyPath);

    return S_OK;
}

//-----------------------------------------------------------------------------
// Constructor/Destructor
//-----------------------------------------------------------------------------
CCloneHelperImpl::CCloneHelperImpl() :
    _cRef(0)
{
    ObjectCreated();
    ZeroMemory(&m_InvalidateActiveVidPn,sizeof(m_InvalidateActiveVidPn));
    ZeroMemory(&m_SetTopologyData,sizeof(m_SetTopologyData));
    m_fSATCalled = FALSE;
}

CCloneHelperImpl::~CCloneHelperImpl()
{    
    ObjectDestroyed();
    if(NULL != m_SetTopologyData.pulTargetID)
    {
        delete [] m_SetTopologyData.pulTargetID;
       m_SetTopologyData.pulTargetID = NULL;
    }
}

//-----------------------------------------------------------------------------
// Implementation of IUnknown
//-----------------------------------------------------------------------------

STDMETHODIMP CCloneHelperImpl::QueryInterface(REFIID riid, LPVOID * ppv)
{
    HRESULT hr = E_NOINTERFACE;

    *ppv = 0;

    if (IID_IUnknown == riid || __uuidof(IViewHelper) == riid)
    {
        *ppv = (IViewHelper *) this;
        AddRef();
        hr = S_OK;
    }

    return hr;
}

ULONG CCloneHelperImpl::AddRef()
{
    return static_cast<ULONG>(InterlockedIncrement(&_cRef));
}

ULONG CCloneHelperImpl::Release()
{
    LONG nNewCount = InterlockedDecrement(&_cRef);

    if (0L == nNewCount)
    {
        delete this;
    }

    return static_cast<ULONG>(nNewCount);
}

//-----------------------------------------------------------------------------
// Implementation of IViewHelper
//-----------------------------------------------------------------------------


///////////////////////////////////////////////////////////////////////////////
//                                          
// CCloneHelperImpl::GetConnectedIDs
// 
// Retrieves an array of identifiers for sources or targets on an adapter.
//
// Parameters:
//     wszAdaptorName [in]     - name of adapter to get identifiers from.
//     pulCount       [out]    - count of number of elements in 
//                               the array of identifiers.
//     pulID          [in,out] - array of identifiers to be filled in.
//     ulFlags        [in]     - flag indicating if identifiers should 
//                                   be sources or targets.
//
// Return Values:
//     HRESULT
//
///////////////////////////////////////////////////////////////////////////////
HRESULT CCloneHelperImpl::GetConnectedIDs(LPCWSTR     wszAdaptorName, 
                                          ULONG *     pulCount, 
                                          ULONG *     pulID, 
                                          ULONG       ulFlags)
{
    HRESULT hr = S_OK;
    D3DKMT_HANDLE hAdapter= NULL;

    D3DKMT_ESCAPE Escape;
    ZeroMemory(&Escape,sizeof(Escape));
    
    R200_EscData sR2EscData;    
    ZeroMemory(&sR2EscData,sizeof(sR2EscData));    
    
    if(NULL == wszAdaptorName)
    {
        return E_POINTER;
    }

    if((ulFlags != GETID_SOURCE) &&(ulFlags != GETID_TARGET))
    {
        return E_INVALIDARG;
    }

    if((pulCount == NULL) && (pulID == NULL))
    {
        return E_INVALIDARG;
    }

    hr = GetAdapterHandle(wszAdaptorName, &hAdapter);
    if(FAILED(hr))
    {
        return hr;
    }

        //Use Escape thunk to get the ID's        
    Escape.hAdapter = hAdapter;
    Escape.hDevice= (D3DKMT_HANDLE)NULL;
    Escape.pPrivateDriverData = &sR2EscData;
    Escape.PrivateDriverDataSize= sizeof(sR2EscData);
    Escape.Type = D3DKMT_ESCAPE_DRIVERPRIVATE ;


    sR2EscData.dwEscapeCode = R200_GETID;
    sR2EscData.sGetIDData.pulCount = pulCount;              
    sR2EscData.sGetIDData.pulID = pulID;
    sR2EscData.sGetIDData.ulFlags= ulFlags;
    
    PFND3DKMT_ESCAPE pFunctionEscape = (PFND3DKMT_ESCAPE)DecodePointer(g_EscapeThunk);

    if((NULL == pFunctionEscape) || !NT_SUCCESS(pFunctionEscape(&Escape)))
    {
        OutputDebugStringA("Escape thunk failed when trying to get source count\n");
        hr = E_FAIL;
    }   

    if(NULL != g_hModule)
    {
        FreeLibrary(g_hModule);
        g_hModule = NULL;
    }

    return hr;
}

///////////////////////////////////////////////////////////////////////////////
//                                          
// CCloneHelperImpl::GetActiveTopology
// 
// Retrieves an array of active targets mapped to a source on an adapter.
//
// Parameters:
//     wszAdaptorName [in]     - name of adapter to get topology of
//     ulSourceID     [in]     - source identifier that array 
//                               of targets are mapped to.
//     pulCount       [out]    - count of number of elements in 
//                               the array of targets.
//     pulTargetID    [in,out] - array of target identifiers to be filled in.
//
// Return Values:
//      HRESULT
//
///////////////////////////////////////////////////////////////////////////////
HRESULT CCloneHelperImpl::GetActiveTopology(LPCWSTR     wszAdaptorName, 
                                            ULONG       ulSourceID, 
                                            ULONG *     pulCount, 
                                            ULONG *     pulTargetID)
{
    HRESULT hr  = S_OK;
    D3DKMT_HANDLE hAdapter= NULL;

    D3DKMT_ESCAPE Escape;
    ZeroMemory(&Escape,sizeof(Escape));
    
    R200_EscData sR2EscData;    
    ZeroMemory(&sR2EscData,sizeof(sR2EscData));
    
    if(NULL == wszAdaptorName)
    {
        return E_POINTER;
    }

    if((pulCount == NULL) && (pulTargetID == NULL))
    {
        return E_INVALIDARG;
    }

    hr = GetAdapterHandle(wszAdaptorName, &hAdapter);
    if(FAILED(hr))
    {
        return hr;
    }

        //Use Escape thunk to get the active topology        
    Escape.hAdapter = hAdapter;
    Escape.hDevice= (D3DKMT_HANDLE)NULL;
    Escape.pPrivateDriverData = &sR2EscData;
    Escape.PrivateDriverDataSize= sizeof(sR2EscData);
    Escape.Type = D3DKMT_ESCAPE_DRIVERPRIVATE ;

    sR2EscData.dwEscapeCode = R200_GETTOPOLOGY;
    sR2EscData.sTopologyData.ulSourceID = ulSourceID;
    sR2EscData.sTopologyData.pulCount = pulCount;
    sR2EscData.sTopologyData.pulTargetID = pulTargetID;
    
    PFND3DKMT_ESCAPE pFunctionEscape = (PFND3DKMT_ESCAPE)DecodePointer(g_EscapeThunk);

    if((NULL == pFunctionEscape) || !NT_SUCCESS(pFunctionEscape(&Escape)))
    {
        OutputDebugStringA("Escape thunk failed when trying to get source count\n");
        hr = E_FAIL;
    }

    if(NULL != g_hModule)
    {
        FreeLibrary(g_hModule);
        g_hModule = NULL;
    }

    return hr;
}

///////////////////////////////////////////////////////////////////////////////
//                                          
// CCloneHelperImpl::SetActiveTopology
// 
// Maps an array of targets to a source on an adapter.
//
// Parameters:
//     wszAdaptorName [in] - name of adapter to set topology on
//     ulSourceID     [in] - source identifier that array 
//                               of targets are to be mapped to.
//     ulCount        [in] - count of number of elements in 
//                               the array passed in.
//     pulTargetID    [in] - array of target identifiers.
//
// Return Values:
//      until this is filled out return E_NOTIMPL
//
///////////////////////////////////////////////////////////////////////////////
HRESULT CCloneHelperImpl::SetActiveTopology(LPCWSTR     wszAdaptorName, 
                                            ULONG       ulSourceID, 
                                            ULONG       ulCount, 
                                            ULONG *     pulTargetID)
{
    HRESULT hr ;
    D3DKMT_HANDLE hAdapter= NULL;

    D3DKMT_ESCAPE Escape;
    ZeroMemory(&Escape,sizeof(Escape));
    
    R200_EscData sR2EscData;    
    ZeroMemory(&sR2EscData,sizeof(sR2EscData));
    ZeroMemory(&m_InvalidateActiveVidPn,sizeof(m_InvalidateActiveVidPn));

    if(NULL != m_SetTopologyData.pulTargetID)
    {
        delete [] m_SetTopologyData.pulTargetID;
        m_SetTopologyData.pulTargetID = NULL;
    }

    ZeroMemory(&m_SetTopologyData,sizeof(m_SetTopologyData));
    
    if(NULL == wszAdaptorName)
    {
        return E_POINTER;
    }

    if((ulCount == NULL) || (pulTargetID == NULL))
    {
        return E_INVALIDARG;
    }

    hr = GetAdapterHandle(wszAdaptorName, &hAdapter);
    if(!SUCCEEDED(hr))
    {
        return hr;
    }

    m_SetTopologyData.pulTargetID = new ULONG[ulCount];
    if(NULL == m_SetTopologyData.pulTargetID)
    {
        if(NULL != g_hModule)
        {
            FreeLibrary(g_hModule);
            g_hModule = NULL;
        }

        return E_OUTOFMEMORY;
    }
    memcpy(m_SetTopologyData.pulTargetID, pulTargetID, ulCount * sizeof(ULONG));

    //Save the topology data    
    m_SetTopologyData.dwCode = SET_TOPOLOGY;    
    m_SetTopologyData.ulCloneSourceID = ulSourceID;
    m_SetTopologyData.ulCount = ulCount;

    //If ulCount >1, cloning needs to be done
    if(ulCount > 1)
    {
        m_SetTopologyData.dwMode = SET_CLONE;
        
    }else
    {
        //turn off cloning i.e. get back to single view
        m_SetTopologyData.dwMode = SET_SINGLEVIEW;
    }

    
    m_InvalidateActiveVidPn.hAdapter =hAdapter;

    m_InvalidateActiveVidPn.pPrivateDriverData = &m_SetTopologyData;
    m_InvalidateActiveVidPn.PrivateDriverDataSize = sizeof(m_SetTopologyData);

    if(NULL != g_hModule)
    {
        FreeLibrary(g_hModule);
        g_hModule = NULL;
    }

    m_fSATCalled = TRUE;

    return S_OK;
}

///////////////////////////////////////////////////////////////////////////////
//                                          
// CCloneHelperImpl::Commit
// 
// Method invalidates the VidPN and calls CDS(NULL, NULL, ...)
//
// Parameters:
//        None
//
// Return Values:
//      HRESULT
//
///////////////////////////////////////////////////////////////////////////////
HRESULT CCloneHelperImpl::Commit()
{
    //Actually set the topology by commiting the saved changes
    HRESULT hr = S_OK;

    if (TRUE == m_fSATCalled)
    {
        hr = LoadThunks();
        if(FAILED(hr))
        {
            return hr;
        }    
        
        PFND3DKMT_INVALIDATEACTIVEVIDPN pFunctionInvalidateVidPn = (PFND3DKMT_INVALIDATEACTIVEVIDPN)DecodePointer(g_InvalidateActiveVidPnThunk);

        if((NULL == pFunctionInvalidateVidPn) || !NT_SUCCESS(pFunctionInvalidateVidPn(&m_InvalidateActiveVidPn)))
        {
            printf("Failed to invalidate the active VidPn. ");
            hr = E_FAIL;
        }

        if(g_hModule != NULL)
        {
            FreeLibrary(g_hModule);
            g_hModule = NULL;
        }

        m_fSATCalled = FALSE;
    }
    else
    {
        // if m_fSATCalled is FALSE TMM has called CDSEx(null) so here is 
        // a chance for the IHV to apply any other GDI operation
        //
    }

    return hr;
}

///////////////////////////////////////////////////////////////////////////////
//                                          
// CCloneHelperImpl::Commit
// 
// Method invalidates the VidPN and calls CDS(NULL, NULL, ...)
//
// Parameters:
//     fFinalCall [in] - flag indicating that this is the final Commit()
//                       in a chain of commands
//
// Return Values:
//      HRESULT
//
///////////////////////////////////////////////////////////////////////////////
HRESULT CCloneHelperImpl::Commit(BOOL fFinalCall)
{
    UNREFERENCED_PARAMETER(fFinalCall);

    return Commit();
}

///////////////////////////////////////////////////////////////////////////////
//                                          
// CCloneHelperImpl::SetConfiguration
// 
// Method send view data via an IStream interface for IHV to apply view data
//
// Parameters:
//     pIStream  [in] - pointer to an IStream interface
//     pulStatus [out] - pointer to ULONG that will receive status of how
//                       view data was handled
//
// Return Values:
//      HRESULT
//
///////////////////////////////////////////////////////////////////////////////
HRESULT CCloneHelperImpl::SetConfiguration(IStream *   pIStream,
                                           ULONG *     pulStatus)
{
    HRESULT hr = E_NOTIMPL;

    if (pulStatus)
    {
        *pulStatus = SETCONFIGURATION_STATUS_APPLIED;
    }

    if (pIStream)
    {
        // Don't release IStream since error will be returned
        // in this sample.

        // unpack the IStream
        CStreamHelper streamHelper;

        HRESULT hrLocal = streamHelper.Unpack(pIStream);

        UNREFERENCED_PARAMETER(hrLocal);
    }
    else
    {
        hr = E_POINTER;
    }

    return hr;
}

///////////////////////////////////////////////////////////////////////////////
//                                          
// CCloneHelperImpl::GetProceedOnNewConfiguration
// 
// Called on a new configuration asking IHV how to handle new configuration
//
// Parameters:
//        None
//
// Return Values:
//      HRESULT
//
///////////////////////////////////////////////////////////////////////////////
HRESULT CCloneHelperImpl::GetProceedOnNewConfiguration()
{
    // return values can be S_OK, S_FALSE or S_INIT
    return S_OK;
}

BOOL WINAPI
DllMain(HINSTANCE hmod, DWORD dwReason, LPVOID lpvReserved)
{
    switch (dwReason)
    {
    case DLL_PROCESS_ATTACH:

    g_hInstance = hmod;

        // OPTIMIZATION:
        // have no need to respond to 
        // DLL_THREAD_ATTACH or DLL_THREAD_DETACH
        // so in order to remove the overhead of
        // a call into this dll when a thread is
        // created or destroyed the following call
        // will keep those two messages from being
        // sent to this dll.
        (void)::DisableThreadLibraryCalls((HMODULE)hmod);

        break;

    case DLL_PROCESS_DETACH:
        break;

    default:
        break;
    }

    return TRUE;
}

