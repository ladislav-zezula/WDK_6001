

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for softusbloopback.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

/* verify that the <rpcsal.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCSAL_H_VERSION__
#define __REQUIRED_RPCSAL_H_VERSION__ 100
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __softusbloopback_h__
#define __softusbloopback_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILoopbackDevice_FWD_DEFINED__
#define __ILoopbackDevice_FWD_DEFINED__
typedef interface ILoopbackDevice ILoopbackDevice;
#endif 	/* __ILoopbackDevice_FWD_DEFINED__ */


#ifndef __ILoopbackDeviceEvents_FWD_DEFINED__
#define __ILoopbackDeviceEvents_FWD_DEFINED__
typedef interface ILoopbackDeviceEvents ILoopbackDeviceEvents;
#endif 	/* __ILoopbackDeviceEvents_FWD_DEFINED__ */


#ifndef __LoopbackDevice_FWD_DEFINED__
#define __LoopbackDevice_FWD_DEFINED__

#ifdef __cplusplus
typedef class LoopbackDevice LoopbackDevice;
#else
typedef struct LoopbackDevice LoopbackDevice;
#endif /* __cplusplus */

#endif 	/* __LoopbackDevice_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __SoftUSBLoopbackLib_LIBRARY_DEFINED__
#define __SoftUSBLoopbackLib_LIBRARY_DEFINED__

/* library SoftUSBLoopbackLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_SoftUSBLoopbackLib;

#ifndef __ILoopbackDevice_INTERFACE_DEFINED__
#define __ILoopbackDevice_INTERFACE_DEFINED__

/* interface ILoopbackDevice */
/* [unique][helpstring][nonextensible][dual][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_ILoopbackDevice;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("438CB71F-ED63-42A1-B839-1543ABDAC796")
    ILoopbackDevice : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DSFDevice( 
            /* [retval][out] */ __RPC__deref_out_opt /* external definition not present */ DSFDevice **ppDSFDEevice) = 0;
        
        virtual /* [helpstring][id] */ HRESULT __stdcall DoPolledLoopback( 
            /* [in] */ long LoopInterval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT __stdcall StartEventProcessing( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT __stdcall StartAsyncEventProcessing( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT __stdcall StopAsyncEventProcessing( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AreKeystrokesWaiting( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfvarKeysWaiting) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SerialNumber( 
            /* [in] */ __RPC__in BSTR bstrSerialNumber) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILoopbackDeviceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILoopbackDevice * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILoopbackDevice * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILoopbackDevice * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILoopbackDevice * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILoopbackDevice * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILoopbackDevice * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILoopbackDevice * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DSFDevice )( 
            ILoopbackDevice * This,
            /* [retval][out] */ __RPC__deref_out_opt /* external definition not present */ DSFDevice **ppDSFDEevice);
        
        /* [helpstring][id] */ HRESULT ( __stdcall *DoPolledLoopback )( 
            ILoopbackDevice * This,
            /* [in] */ long LoopInterval);
        
        /* [helpstring][id] */ HRESULT ( __stdcall *StartEventProcessing )( 
            ILoopbackDevice * This);
        
        /* [helpstring][id] */ HRESULT ( __stdcall *StartAsyncEventProcessing )( 
            ILoopbackDevice * This);
        
        /* [helpstring][id] */ HRESULT ( __stdcall *StopAsyncEventProcessing )( 
            ILoopbackDevice * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AreKeystrokesWaiting )( 
            ILoopbackDevice * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfvarKeysWaiting);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SerialNumber )( 
            ILoopbackDevice * This,
            /* [in] */ __RPC__in BSTR bstrSerialNumber);
        
        END_INTERFACE
    } ILoopbackDeviceVtbl;

    interface ILoopbackDevice
    {
        CONST_VTBL struct ILoopbackDeviceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILoopbackDevice_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILoopbackDevice_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILoopbackDevice_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILoopbackDevice_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILoopbackDevice_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILoopbackDevice_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILoopbackDevice_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILoopbackDevice_get_DSFDevice(This,ppDSFDEevice)	\
    ( (This)->lpVtbl -> get_DSFDevice(This,ppDSFDEevice) ) 

#define ILoopbackDevice_DoPolledLoopback(This,LoopInterval)	\
    ( (This)->lpVtbl -> DoPolledLoopback(This,LoopInterval) ) 

#define ILoopbackDevice_StartEventProcessing(This)	\
    ( (This)->lpVtbl -> StartEventProcessing(This) ) 

#define ILoopbackDevice_StartAsyncEventProcessing(This)	\
    ( (This)->lpVtbl -> StartAsyncEventProcessing(This) ) 

#define ILoopbackDevice_StopAsyncEventProcessing(This)	\
    ( (This)->lpVtbl -> StopAsyncEventProcessing(This) ) 

#define ILoopbackDevice_AreKeystrokesWaiting(This,pfvarKeysWaiting)	\
    ( (This)->lpVtbl -> AreKeystrokesWaiting(This,pfvarKeysWaiting) ) 

#define ILoopbackDevice_put_SerialNumber(This,bstrSerialNumber)	\
    ( (This)->lpVtbl -> put_SerialNumber(This,bstrSerialNumber) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILoopbackDevice_INTERFACE_DEFINED__ */


#ifndef __ILoopbackDeviceEvents_DISPINTERFACE_DEFINED__
#define __ILoopbackDeviceEvents_DISPINTERFACE_DEFINED__

/* dispinterface ILoopbackDeviceEvents */
/* [helpstring][nonextensible][uuid] */ 


EXTERN_C const IID DIID_ILoopbackDeviceEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("8EA6471E-4F30-4EA6-88AF-67703A99917C")
    ILoopbackDeviceEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ILoopbackDeviceEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILoopbackDeviceEvents * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILoopbackDeviceEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILoopbackDeviceEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILoopbackDeviceEvents * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILoopbackDeviceEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILoopbackDeviceEvents * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILoopbackDeviceEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } ILoopbackDeviceEventsVtbl;

    interface ILoopbackDeviceEvents
    {
        CONST_VTBL struct ILoopbackDeviceEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILoopbackDeviceEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILoopbackDeviceEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILoopbackDeviceEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILoopbackDeviceEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILoopbackDeviceEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILoopbackDeviceEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILoopbackDeviceEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ILoopbackDeviceEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LoopbackDevice;

#ifdef __cplusplus

class DECLSPEC_UUID("8419B5D4-9DE5-468E-8273-533D49A94C31")
LoopbackDevice;
#endif
#endif /* __SoftUSBLoopbackLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


