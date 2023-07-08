

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for softhiddevice.idl:
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


#ifndef __softhiddevice_h__
#define __softhiddevice_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISoftHIDInputKbdMapper_FWD_DEFINED__
#define __ISoftHIDInputKbdMapper_FWD_DEFINED__
typedef interface ISoftHIDInputKbdMapper ISoftHIDInputKbdMapper;
#endif 	/* __ISoftHIDInputKbdMapper_FWD_DEFINED__ */


#ifndef __SoftHIDInputKbdMapper_FWD_DEFINED__
#define __SoftHIDInputKbdMapper_FWD_DEFINED__

#ifdef __cplusplus
typedef class SoftHIDInputKbdMapper SoftHIDInputKbdMapper;
#else
typedef struct SoftHIDInputKbdMapper SoftHIDInputKbdMapper;
#endif /* __cplusplus */

#endif 	/* __SoftHIDInputKbdMapper_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __SOFTHID_LIBRARY_DEFINED__
#define __SOFTHID_LIBRARY_DEFINED__

/* library SOFTHID */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_SOFTHID;

#ifndef __ISoftHIDInputKbdMapper_INTERFACE_DEFINED__
#define __ISoftHIDInputKbdMapper_INTERFACE_DEFINED__

/* interface ISoftHIDInputKbdMapper */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ISoftHIDInputKbdMapper;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("925D14EB-7485-4FEE-8EB2-7B5C813BC39D")
    ISoftHIDInputKbdMapper : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InputReportMask( 
            /* [retval][out] */ __RPC__out SHORT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_InputReportMask( 
            /* [in] */ SHORT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutputReportMask( 
            /* [retval][out] */ __RPC__out BYTE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OutputReportMask( 
            /* [in] */ BYTE newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AttachKbd( 
            /* [in] */ __RPC__in /* external definition not present */ SoftKeyboard *pSoftKbd) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AttachProtocolXlator( 
            /* [in] */ __RPC__in /* external definition not present */ SoftHIDProtocolXlator *pSoftProtXlator) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISoftHIDInputKbdMapperVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISoftHIDInputKbdMapper * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISoftHIDInputKbdMapper * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISoftHIDInputKbdMapper * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISoftHIDInputKbdMapper * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISoftHIDInputKbdMapper * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISoftHIDInputKbdMapper * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISoftHIDInputKbdMapper * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InputReportMask )( 
            ISoftHIDInputKbdMapper * This,
            /* [retval][out] */ __RPC__out SHORT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_InputReportMask )( 
            ISoftHIDInputKbdMapper * This,
            /* [in] */ SHORT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputReportMask )( 
            ISoftHIDInputKbdMapper * This,
            /* [retval][out] */ __RPC__out BYTE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutputReportMask )( 
            ISoftHIDInputKbdMapper * This,
            /* [in] */ BYTE newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AttachKbd )( 
            ISoftHIDInputKbdMapper * This,
            /* [in] */ __RPC__in /* external definition not present */ SoftKeyboard *pSoftKbd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AttachProtocolXlator )( 
            ISoftHIDInputKbdMapper * This,
            /* [in] */ __RPC__in /* external definition not present */ SoftHIDProtocolXlator *pSoftProtXlator);
        
        END_INTERFACE
    } ISoftHIDInputKbdMapperVtbl;

    interface ISoftHIDInputKbdMapper
    {
        CONST_VTBL struct ISoftHIDInputKbdMapperVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISoftHIDInputKbdMapper_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISoftHIDInputKbdMapper_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISoftHIDInputKbdMapper_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISoftHIDInputKbdMapper_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISoftHIDInputKbdMapper_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISoftHIDInputKbdMapper_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISoftHIDInputKbdMapper_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISoftHIDInputKbdMapper_get_InputReportMask(This,pVal)	\
    ( (This)->lpVtbl -> get_InputReportMask(This,pVal) ) 

#define ISoftHIDInputKbdMapper_put_InputReportMask(This,newVal)	\
    ( (This)->lpVtbl -> put_InputReportMask(This,newVal) ) 

#define ISoftHIDInputKbdMapper_get_OutputReportMask(This,pVal)	\
    ( (This)->lpVtbl -> get_OutputReportMask(This,pVal) ) 

#define ISoftHIDInputKbdMapper_put_OutputReportMask(This,newVal)	\
    ( (This)->lpVtbl -> put_OutputReportMask(This,newVal) ) 

#define ISoftHIDInputKbdMapper_AttachKbd(This,pSoftKbd)	\
    ( (This)->lpVtbl -> AttachKbd(This,pSoftKbd) ) 

#define ISoftHIDInputKbdMapper_AttachProtocolXlator(This,pSoftProtXlator)	\
    ( (This)->lpVtbl -> AttachProtocolXlator(This,pSoftProtXlator) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISoftHIDInputKbdMapper_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SoftHIDInputKbdMapper;

#ifdef __cplusplus

class DECLSPEC_UUID("6853488F-9478-4290-84A1-83BFF8BBE48F")
SoftHIDInputKbdMapper;
#endif
#endif /* __SOFTHID_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


