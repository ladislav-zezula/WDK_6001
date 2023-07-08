//-----------------------------------------------------------------------
// <copyright file="BasicDDI.h" company="Microsoft">
//      Copyright (c) 2006 Microsoft Corporation. All rights reserved.
// </copyright>
//
// Module:
//      BasicDDI.h
//
// Description:
//      This module implements the ISideShowDriver DDI which is used
//      by the Windows SideShow class extension.
//
//-----------------------------------------------------------------------

#pragma once

#include <WindowsSideShowClassExtension.h>

class CWssBasicDDI :
    public CComObjectRoot,
    public ISideShowDriver
{
public:
    CWssBasicDDI();
    virtual ~CWssBasicDDI();

    HRESULT Initialize(IWDFNamedPropertyStore* pStore);

    HRESULT Deinitialize(void);

    DECLARE_NOT_AGGREGATABLE(CWssBasicDDI)

    BEGIN_COM_MAP(CWssBasicDDI)
        COM_INTERFACE_ENTRY(ISideShowDriver)
    END_COM_MAP()

    //
    // Overriden DDI methods
    //
public:
    __override STDMETHOD(OnSetCurrentUser)(const SID* pUser);

    __override STDMETHOD(OnGetCurrentUser)(SID** ppUser);

    __override STDMETHOD(OnSetUserState)(const SID* pUser,
                                         const USER_STATE state);

    __override STDMETHOD(OnSetTime)(const FILETIME time);

    __override STDMETHOD(OnSetTimeZone)(const SIDESHOW_TIME_ZONE_INFORMATION* pTimeZoneInformation);

    __override STDMETHOD(OnSetShortDateFormat)(const SID* user,
                                               LPCWSTR    wszDateFormat);

    __override STDMETHOD(OnSetLongDateFormat)(const SID* user,
                                              LPCWSTR    wszDateFormat);

    __override STDMETHOD(OnSetShortTimeFormat)(const SID* user,
                                               LPCWSTR    wszTimeFormat);

    __override STDMETHOD(OnSetLongTimeFormat)(const SID* user,
                                              LPCWSTR    wszTimeFormat);

    __override STDMETHOD(OnSetTheme)(LPCWSTR wszTheme);

    __override STDMETHOD(OnGetTheme)(__deref_out LPWSTR* pwszTheme);

    __override STDMETHOD(OnGetDeviceFirmwareVersion)(__deref_out LPWSTR* pwszVersion);

    __override STDMETHOD(OnGetDeviceManufacturer)(__deref_out LPWSTR* pwszManufacturer);

    __override STDMETHOD(OnGetDeviceName)(__deref_out LPWSTR* pwszName);

    __override STDMETHOD(OnGetDeviceEndpoints)(ENDPOINT_ID** rgEndpoints,
                                               DWORD*        pcEndpoints);

    __override STDMETHOD(OnGetDeviceCapabilities)(const PROPERTYKEY* pKey,
                                                  PROPVARIANT*       pvValue);

    __override STDMETHOD(OnGetPreEnabledApplications)(APPLICATION_ID** ppguidApps,
                                                      ENDPOINT_ID**    ppEndpoints,
                                                      DWORD*           pcApplications);

    __override STDMETHOD(OnGetApplicationOrder)(APPLICATION_ID** ppAppIds,
                                                DWORD*           pcAppIds);

    __override STDMETHOD(OnSetApplicationOrder)(const APPLICATION_ID* pApps,
                                                const DWORD           cApps);

    __override STDMETHOD(OnAddApplication)(const SID*           user,
                                           REFAPPLICATION_ID    rAppId,
                                           REFENDPOINT_ID       rEndPoint,
                                           LPCWSTR              wszName,
                                           const DWORD          cachePolicy,
                                           const DWORD          dwOnlineOnly,
                                           const unsigned char* pbLargeIcon,
                                           const DWORD          cbLargeIcon,
                                           const unsigned char* pbSmallIcon,
                                           const DWORD          cbSmallIcon,
                                           const unsigned char* pbMiniIcon,
                                           const DWORD          cbMiniIcon);

    __override STDMETHOD(OnRemoveApplication)(const SID*        user,
                                              REFAPPLICATION_ID rAppId);

    __override STDMETHOD(OnRemoveAllApplications)(const SID* user);

    __override STDMETHOD(OnSetNotificationsEnabled)(const SID* pUserSid,
                                                    const BOOL fIsEnabled);

    __override STDMETHOD(OnAddNotification)(const SID*            user,
                                            REFAPPLICATION_ID     rAppId,
                                            const NOTIFICATION_ID notificationId,
                                            const FILETIME        ftExpiration,
                                            LPCWSTR               wszTitle,
                                            LPCWSTR               wszMessage,
                                            const unsigned char*  pbImage,
                                            const DWORD           cbImage);

    __override STDMETHOD(OnRemoveNotification)(const SID*            user,
                                               REFAPPLICATION_ID     rAppId,
                                               const NOTIFICATION_ID notificationId);

    __override STDMETHOD(OnRemoveAllNotifications)(const SID*        user,
                                                   REFAPPLICATION_ID rAppId);

    __override STDMETHOD(OnAddContent)(const SID*           user,
                                       REFAPPLICATION_ID    rAppId,
                                       REFENDPOINT_ID       rRendererId,
                                       const CONTENT_ID     contentId,
                                       const unsigned char* pData,
                                       const DWORD          cbData);

    __override STDMETHOD(OnRemoveContent)(const SID*        user,
                                          REFAPPLICATION_ID rAppId,
                                          REFENDPOINT_ID    rRenderId,
                                          const CONTENT_ID  contentId);

    __override STDMETHOD(OnRemoveAllContent)(const SID*        user,
                                             REFAPPLICATION_ID rAppId,
                                             REFENDPOINT_ID    rRenderId);

    __override STDMETHOD(OnProcessWpdMessage)(IUnknown* pinValues,
                                              IUnknown* poutValues);

    __override STDMETHOD(OnSetLanguage)(const SID* user,
                                        LPCWSTR    wszLang);

protected:
    STDMETHOD(GetApplicationOrderString)(__deref_out LPWSTR* ppwszKey);

    STDMETHOD(GetStoredApplicationOrder)(APPLICATION_ID** ppAppIds,
                                         DWORD*           pcAppIds);

    STDMETHOD(SetStoredApplicationOrder)(const APPLICATION_ID* pApps,
                                         const DWORD           cApps);

protected:
    SID* m_pUserSID;
    size_t m_cbUserSID; // This is the maximum size of a SID, not the actual size of the current m_pUserSID

    CComPtr<IWDFNamedPropertyStore> m_pPropertyStore;
};

