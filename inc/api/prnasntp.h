/*++

Copyright (c) 1990  Microsoft Corporation

Module Name:

    prnasntp.hxx

Abstract:

    Internal Header file for Print APIs

Author:

Revision History:

--*/

#ifndef _PRINTASYNCNOTIFYP_H_
#define _PRINTASYNCNOTIFYP_H_

#undef EQUALNULL

#ifdef __cplusplus
#define EQUALNULL   = NULL
#else
#define EQUALNULL
#endif


#ifdef __cplusplus
extern "C" {
namespace NPrintAsyncNotifyProvider {
#endif

    DEFINE_GUID(IID_IPrintAsyncNotify,                      0x532818f7, 0x921b, 0x4fb2, 0xbf, 0xf8, 0x2f, 0x4f, 0xd5, 0x2e, 0xbe, 0xbf);
    DEFINE_GUID(IID_IBidiAsyncNotifyChannel,                0x532818f7, 0x921b, 0x4fb2, 0xbf, 0xf8, 0x2f, 0x4f, 0xd5, 0x2e, 0xbe, 0xbf);
    DEFINE_GUID(IID_IUnidiAsyncNotifyChannel,               0x20aa39c2, 0xb631, 0x4aec, 0xbd, 0x78, 0xfb, 0xaf, 0xe7, 0x9d, 0x7b, 0x9c);    
    DEFINE_GUID(IID_IPrintAsyncNotifyRegistration,          0x0f6f27b6, 0x6f86, 0x4591, 0x92, 0x03, 0x64, 0xc3, 0xbf, 0xad, 0xed, 0xfe);
    DEFINE_GUID(IID_IBidiAsyncNotifyRegistration,           0xa8fe383c, 0xc22f, 0x4790, 0x88, 0xcd, 0xd9, 0xfe, 0x0f, 0x0a, 0xdd, 0xf9);
    DEFINE_GUID(IID_IUnidiAsyncNotifyRegistration,          0x5eecac03, 0xf33d, 0x453c, 0x8d, 0xd7, 0x72, 0x57, 0x1c, 0x03, 0x43, 0x1a);
    DEFINE_GUID(IID_IAsyncNotifyServerReferral,             0x87be5d60, 0x2ab8, 0x4340, 0xa4, 0x75, 0x8c, 0xe1, 0x54, 0x1d, 0x63, 0xf9);

    typedef interface IBidiAsyncNotifyChannel IBidiAsyncNotifyChannel;

    #undef  INTERFACE
    #define INTERFACE IPrintAsyncNotifyRegistration
    DECLARE_INTERFACE_(IPrintAsyncNotifyRegistration, IUnknown)
    {
        STDMETHOD(QueryInterface)(
            THIS_ 
            REFIID riid, 
            void** ppvObj
            ) PURE;

        STDMETHOD_(ULONG, AddRef)(
            THIS
            ) PURE;

        STDMETHOD_(ULONG, Release)(
            THIS
            ) PURE;

        STDMETHOD(RegisterForNotifications)(            
            THIS
            ) PURE;

        STDMETHOD(UnregisterForNotifications)(            
            THIS
            ) PURE;   
    };


    #undef  INTERFACE
    #define INTERFACE IPrintAsyncNotify
    DECLARE_INTERFACE_(IPrintAsyncNotify, IUnknown)
    {
        STDMETHOD(QueryInterface)(
            THIS_ 
            REFIID riid, 
            void** ppvObj
            ) PURE;

        STDMETHOD_(ULONG, AddRef)(
            THIS
            ) PURE;

        STDMETHOD_(ULONG, Release)(
            THIS
            ) PURE;

        STDMETHOD(CreatePrintAsyncNotifyChannel)(            
            THIS_
            IN  ULONG,
            IN  PrintAsyncNotificationType*,
            IN  PrintAsyncNotifyUserFilter,
            IN  PrintAsyncNotifyConversationStyle,
            IN  IPrintAsyncNotifyCallback*,
            OUT IPrintAsyncNotifyChannel** 
            ) PURE;

        STDMETHOD(CreatePrintAsyncNotifyRegistration)(            
            THIS_
            IN  PrintAsyncNotificationType*,
            IN  PrintAsyncNotifyUserFilter,
            IN  PrintAsyncNotifyConversationStyle,
            IN  IPrintAsyncNotifyCallback*,
            OUT IPrintAsyncNotifyRegistration**
            ) PURE;

    };

    //
    // Async Cookie interfaces.
    //
    #undef  INTERFACE
    #define INTERFACE IPrintAsyncCookie
    DECLARE_INTERFACE_(IPrintAsyncCookie, IUnknown)
    {
        //
        // IUnknown methods
        //
        STDMETHOD(QueryInterface)(
            THIS_ 
            IN  REFIID riid, 
            IN  void** ppvObj
            ) PURE;

        STDMETHOD_(ULONG, AddRef)(
            THIS
            ) PURE;

        STDMETHOD_(ULONG, Release)(
            THIS
            ) PURE;

        STDMETHOD(FinishAsyncCall)(            
             THIS_
             IN  HRESULT
             ) PURE;

        STDMETHOD(CancelAsyncCall)(            
             THIS_
             IN  HRESULT
             ) PURE;        
    };

    #undef  INTERFACE
    #define INTERFACE IPrintAsyncNewChannelCookie
    DECLARE_INTERFACE_(IPrintAsyncNewChannelCookie, IPrintAsyncCookie)
    {
        //
        // IUnknown methods
        //
        STDMETHOD(QueryInterface)(
            THIS_ 
            IN  REFIID riid, 
            IN  void** ppvObj
            ) PURE;

        STDMETHOD_(ULONG, AddRef)(
            THIS
            ) PURE;

        STDMETHOD_(ULONG, Release)(
            THIS
            ) PURE;

        STDMETHOD(FinishAsyncCall)(            
             THIS_
             IN  HRESULT
             ) PURE;

        STDMETHOD(CancelAsyncCall)(            
             THIS_
             IN  HRESULT
             ) PURE;

        STDMETHOD(FinishAsyncCallWithData)(
             THIS_
             IN  IPrintAsyncNotifyChannel**,
             IN  ULONG
             ) PURE;
    };    


    #undef  INTERFACE
    #define INTERFACE IAsyncGetSendNotificationCookie
    DECLARE_INTERFACE_(IAsyncGetSendNotificationCookie, IPrintAsyncCookie)
    {
        //
        // IUnknown methods
        //
        STDMETHOD(QueryInterface)(
            THIS_ 
            IN  REFIID riid, 
            IN  void** ppvObj
            ) PURE;

        STDMETHOD_(ULONG, AddRef)(
            THIS
            ) PURE;

        STDMETHOD_(ULONG, Release)(
            THIS
            ) PURE;

        STDMETHOD(FinishAsyncCall)(            
             THIS_
             IN  HRESULT
             ) PURE;

        STDMETHOD(CancelAsyncCall)(            
             THIS_
             IN  HRESULT
             ) PURE;

        STDMETHOD(FinishAsyncCallWithData)(            
             THIS_
             IN  IPrintAsyncNotifyDataObject*,
             IN  BOOL
             ) PURE;
    };

    #undef  INTERFACE
    #define INTERFACE IAsyncGetSrvReferralCookie
    DECLARE_INTERFACE_(IAsyncGetSrvReferralCookie, IUnknown)
    {
        //
        // IUnknown methods
        //
        STDMETHOD(QueryInterface)(
            THIS_ 
            IN  REFIID riid, 
            IN  void** ppvObj
            ) PURE;

        STDMETHOD_(ULONG, AddRef)(
            THIS
            ) PURE;

        STDMETHOD_(ULONG, Release)(
            THIS
            ) PURE;

        STDMETHOD(FinishAsyncCall)(            
             THIS_
             IN  HRESULT
             ) PURE;

        STDMETHOD(CancelAsyncCall)(            
             THIS_
             IN  HRESULT
             ) PURE;
        
        STDMETHOD(FinishAsyncCallWithData)(            
             IN  PCWSTR
             ) PURE;
    };

    //                                                                                         
    //  A print provider must implement these interfaces if it implements async notifications. 
    //       
                                                                                  
    
    #undef  INTERFACE
    #define INTERFACE IPrintBidiAsyncNotifyRegistration
    DECLARE_INTERFACE_(IPrintBidiAsyncNotifyRegistration, IPrintAsyncNotifyRegistration)
    {
        //
        // IUnknown methods
        //
        STDMETHOD(QueryInterface)(
            THIS_ 
            REFIID riid, 
            void** ppvObj
            ) PURE;

        STDMETHOD_(ULONG, AddRef)(
            THIS
            ) PURE;

        STDMETHOD_(ULONG, Release)(
            THIS
            ) PURE;

        //
        // IPrintAsyncNotifyRegistration methods
        //
        STDMETHOD(RegisterForNotifications)(            
             THIS_
             ) PURE;

        STDMETHOD(UnregisterForNotifications)(            
             THIS
             ) PURE;

        //
        // IPrintBidiAsyncNotifyRegistration methods
        //
        STDMETHOD(AsyncGetNewChannel)(                
             THIS_
             IN  IPrintAsyncNewChannelCookie* EQUALNULL
             ) PURE;

    };


    #undef  INTERFACE
    #define INTERFACE IPrintUnidiAsyncNotifyRegistration
    DECLARE_INTERFACE_(IPrintUnidiAsyncNotifyRegistration, IPrintAsyncNotifyRegistration)
    {
        //
        // IUnknown methods
        //
        STDMETHOD(QueryInterface)(
            THIS_ 
            REFIID riid, 
            void** ppvObj
            ) PURE;

        STDMETHOD_(ULONG, AddRef)(
            THIS
            ) PURE;

        STDMETHOD_(ULONG, Release)(
            THIS
            ) PURE;

        //
        // IPrintAsyncNotifyRegistration methods
        //
        STDMETHOD(RegisterForNotifications)(            
             THIS_
             ) PURE;

        STDMETHOD(UnregisterForNotifications)(            
             THIS
             ) PURE;

        //
        // IPrintUnidiAsyncNotifyRegistration methods
        //
        STDMETHOD(AsyncGetNotification)(              
             THIS_
             IN  IAsyncGetSendNotificationCookie* EQUALNULL
             ) PURE;

    };

    //                                                                                        
    // To be implemented only if the print provider a server referral (ex: CSR/DPS providers)          
    //  
    #undef  INTERFACE
    #define INTERFACE IPrintAsyncNotifyServerReferral
    DECLARE_INTERFACE_(IPrintAsyncNotifyServerReferral, IUnknown)
    {
        //
        // IUnknown methods
        //
        STDMETHOD(QueryInterface)(
            THIS_ 
            REFIID riid, 
            void** ppvObj
            ) PURE;

        STDMETHOD_(ULONG, AddRef)(
            THIS
            ) PURE;

        STDMETHOD_(ULONG, Release)(
            THIS
            ) PURE;

        //
        // IPrintAsyncNotifyServerReferral methods
        //
        STDMETHOD(GetServerReferral)(            
             THIS_
             OUT PWSTR*            
             ) PURE;

        STDMETHOD(AsyncGetServerReferral)(            
             THIS_
             IN  IAsyncGetSrvReferralCookie* EQUALNULL
             ) PURE;

        STDMETHOD(SetServerReferral)(            
             THIS_
             IN  PCWSTR pRmtServerReferral
             ) PURE;

    };

    
    #undef  INTERFACE
    #define INTERFACE IBidiAsyncNotifyChannel
    DECLARE_INTERFACE_(IBidiAsyncNotifyChannel, IPrintAsyncNotifyChannel)
    {
        //
        // IUnknown methods
        //
        STDMETHOD(QueryInterface)(
            THIS_ 
            REFIID riid, 
            void** ppvObj
            ) PURE;

        STDMETHOD_(ULONG, AddRef)(
            THIS
            ) PURE;

        STDMETHOD_(ULONG, Release)(
            THIS
            ) PURE;

        //
        // IPrintAsyncNotifyChannel methods
        //
        STDMETHOD(CreateNotificationChannel)(            
             THIS_
             ) PURE;

        STDMETHOD(SendNotification)(            
             THIS_
             IN IPrintAsyncNotifyDataObject*
             ) PURE;

        STDMETHOD(CloseChannel)(            
             THIS_
             IN IPrintAsyncNotifyDataObject*
             ) PURE;

        STDMETHOD(GetPrintName)(            
             THIS_
             IN IPrintAsyncNotifyDataObject**
             ) PURE;

        STDMETHOD(GetChannelNotificationType)(            
             THIS_
             IN IPrintAsyncNotifyDataObject**
             ) PURE;

        STDMETHOD(AsyncGetNotificationSendResponse)(  
             THIS_
             IN IPrintAsyncNotifyDataObject*,
             IN IAsyncGetSendNotificationCookie* EQUALNULL
             ) PURE;

        STDMETHOD(AsyncCloseChannel)(                 
             THIS_
             IN IPrintAsyncNotifyDataObject*,
             IN IPrintAsyncCookie* EQUALNULL
             ) PURE;
    };

    #undef INTERFACE
    

#ifdef __cplusplus
    }
}
#endif

HRESULT
WINAPI
RouterRegisterForPrintAsyncNotifications(
        IN  PCWSTR                                  pName,
__in    IN  PrintAsyncNotificationType*             pNotificationType,
        IN  PrintAsyncNotifyUserFilter              eNotifyFilter,
        IN  PrintAsyncNotifyConversationStyle       eConversationStyle,
__in    IN  IPrintAsyncNotifyCallback*              pCallback,
__out_bcount(sizeof(HANDLE)) OUT HANDLE*            phNotify
    );



HRESULT
WINAPI
RouterUnregisterForPrintAsyncNotifications(
    IN  HANDLE  hNotify                   
 );

HRESULT
WINAPI
RouterCreatePrintAsyncNotificationChannel(
IN          PCWSTR                              pName,
__in IN     PrintAsyncNotificationType*         pNotificationType,
IN          PrintAsyncNotifyUserFilter          eNotifyFilter,
IN          PrintAsyncNotifyConversationStyle   eConversationStyle,
__in IN     IPrintAsyncNotifyCallback*          pCallback,
__out OUT   IPrintAsyncNotifyChannel**          ppIAsynchNotification
    );

HRESULT
WINAPI
RouterGetPrintClassObject(
    IN  PCWSTR                  pPrinter,
    IN  REFIID                  riid,
    __out OUT VOID**            ppv
    );

#endif      // _WINSPLP_HXX_

