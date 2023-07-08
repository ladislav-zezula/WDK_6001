

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for softusbaudio.idl:
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


#ifndef __softusbaudio_h__
#define __softusbaudio_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAudioDevice_FWD_DEFINED__
#define __IAudioDevice_FWD_DEFINED__
typedef interface IAudioDevice IAudioDevice;
#endif 	/* __IAudioDevice_FWD_DEFINED__ */


#ifndef __IAudioDeviceEvents_FWD_DEFINED__
#define __IAudioDeviceEvents_FWD_DEFINED__
typedef interface IAudioDeviceEvents IAudioDeviceEvents;
#endif 	/* __IAudioDeviceEvents_FWD_DEFINED__ */


#ifndef __AudioDevice_FWD_DEFINED__
#define __AudioDevice_FWD_DEFINED__

#ifdef __cplusplus
typedef class AudioDevice AudioDevice;
#else
typedef struct AudioDevice AudioDevice;
#endif /* __cplusplus */

#endif 	/* __AudioDevice_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __SoftUSBAudioLib_LIBRARY_DEFINED__
#define __SoftUSBAudioLib_LIBRARY_DEFINED__

/* library SoftUSBAudioLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_SoftUSBAudioLib;

#ifndef __IAudioDevice_INTERFACE_DEFINED__
#define __IAudioDevice_INTERFACE_DEFINED__

/* interface IAudioDevice */
/* [unique][helpstring][nonextensible][dual][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IAudioDevice;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C45544C0-AFA8-4544-948C-5D791A517767")
    IAudioDevice : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DSFDevice( 
            /* [retval][out] */ __RPC__deref_out_opt /* external definition not present */ DSFDevice **ppDSFDEevice) = 0;
        
        virtual /* [helpstring][id] */ HRESULT __stdcall DisplayDeviceRequests( 
            /* [in] */ VARIANT_BOOL fvarDisplay) = 0;
        
        virtual /* [helpstring][id] */ HRESULT __stdcall StartSimulation( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AreKeystrokesWaiting( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfvarKeysWaiting) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PacketsReceived( 
            /* [retval][out] */ __RPC__out LONG *plPacketCount) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAudioDeviceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAudioDevice * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAudioDevice * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAudioDevice * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAudioDevice * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAudioDevice * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAudioDevice * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAudioDevice * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DSFDevice )( 
            IAudioDevice * This,
            /* [retval][out] */ __RPC__deref_out_opt /* external definition not present */ DSFDevice **ppDSFDEevice);
        
        /* [helpstring][id] */ HRESULT ( __stdcall *DisplayDeviceRequests )( 
            IAudioDevice * This,
            /* [in] */ VARIANT_BOOL fvarDisplay);
        
        /* [helpstring][id] */ HRESULT ( __stdcall *StartSimulation )( 
            IAudioDevice * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AreKeystrokesWaiting )( 
            IAudioDevice * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfvarKeysWaiting);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PacketsReceived )( 
            IAudioDevice * This,
            /* [retval][out] */ __RPC__out LONG *plPacketCount);
        
        END_INTERFACE
    } IAudioDeviceVtbl;

    interface IAudioDevice
    {
        CONST_VTBL struct IAudioDeviceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAudioDevice_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAudioDevice_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAudioDevice_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAudioDevice_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAudioDevice_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAudioDevice_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAudioDevice_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAudioDevice_get_DSFDevice(This,ppDSFDEevice)	\
    ( (This)->lpVtbl -> get_DSFDevice(This,ppDSFDEevice) ) 

#define IAudioDevice_DisplayDeviceRequests(This,fvarDisplay)	\
    ( (This)->lpVtbl -> DisplayDeviceRequests(This,fvarDisplay) ) 

#define IAudioDevice_StartSimulation(This)	\
    ( (This)->lpVtbl -> StartSimulation(This) ) 

#define IAudioDevice_AreKeystrokesWaiting(This,pfvarKeysWaiting)	\
    ( (This)->lpVtbl -> AreKeystrokesWaiting(This,pfvarKeysWaiting) ) 

#define IAudioDevice_get_PacketsReceived(This,plPacketCount)	\
    ( (This)->lpVtbl -> get_PacketsReceived(This,plPacketCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAudioDevice_INTERFACE_DEFINED__ */


#ifndef __IAudioDeviceEvents_DISPINTERFACE_DEFINED__
#define __IAudioDeviceEvents_DISPINTERFACE_DEFINED__

/* dispinterface IAudioDeviceEvents */
/* [helpstring][nonextensible][uuid] */ 


EXTERN_C const IID DIID_IAudioDeviceEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("DF6DD301-4359-4798-9133-82A53DB84E6C")
    IAudioDeviceEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IAudioDeviceEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAudioDeviceEvents * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAudioDeviceEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAudioDeviceEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAudioDeviceEvents * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAudioDeviceEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAudioDeviceEvents * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAudioDeviceEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IAudioDeviceEventsVtbl;

    interface IAudioDeviceEvents
    {
        CONST_VTBL struct IAudioDeviceEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAudioDeviceEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAudioDeviceEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAudioDeviceEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAudioDeviceEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAudioDeviceEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAudioDeviceEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAudioDeviceEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IAudioDeviceEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_AudioDevice;

#ifdef __cplusplus

class DECLSPEC_UUID("532E9231-5814-4DCD-A708-938D8DC0E1E1")
AudioDevice;
#endif
#endif /* __SoftUSBAudioLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


