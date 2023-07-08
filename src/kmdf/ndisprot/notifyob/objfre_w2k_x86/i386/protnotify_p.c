

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for protnotify.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "protnotify.h"

#define TYPE_FORMAT_STRING_SIZE   93                                
#define PROC_FORMAT_STRING_SIZE   73                                
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _protnotify_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } protnotify_MIDL_TYPE_FORMAT_STRING;

typedef struct _protnotify_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } protnotify_MIDL_PROC_FORMAT_STRING;

typedef struct _protnotify_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } protnotify_MIDL_EXPR_FORMAT_STRING;


static RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const protnotify_MIDL_TYPE_FORMAT_STRING protnotify__MIDL_TypeFormatString;
extern const protnotify_MIDL_PROC_FORMAT_STRING protnotify__MIDL_ProcFormatString;
extern const protnotify_MIDL_EXPR_FORMAT_STRING protnotify__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO INetLanConnectionUiInfo_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO INetLanConnectionUiInfo_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO INetRasConnectionIpUiInfo_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO INetRasConnectionIpUiInfo_ProxyInfo;



#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need a Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const protnotify_MIDL_PROC_FORMAT_STRING protnotify__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure GetDeviceGuid */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x3 ),	/* 3 */
/*  8 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x4c ),	/* 76 */
/* 14 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 16 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pguid */

/* 24 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 30 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 32 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 34 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUiInfo */

/* 36 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 38 */	NdrFcLong( 0x0 ),	/* 0 */
/* 42 */	NdrFcShort( 0x3 ),	/* 3 */
/* 44 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 46 */	NdrFcShort( 0x0 ),	/* 0 */
/* 48 */	NdrFcShort( 0x494 ),	/* 1172 */
/* 50 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 52 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 54 */	NdrFcShort( 0x0 ),	/* 0 */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pInfo */

/* 60 */	NdrFcShort( 0x112 ),	/* Flags:  must free, out, simple ref, */
/* 62 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 64 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Return value */

/* 66 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 68 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 70 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const protnotify_MIDL_TYPE_FORMAT_STRING protnotify__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/*  4 */	NdrFcShort( 0x8 ),	/* Offset= 8 (12) */
/*  6 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/*  8 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 12 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 14 */	NdrFcShort( 0x10 ),	/* 16 */
/* 16 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 18 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 20 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (6) */
			0x5b,		/* FC_END */
/* 24 */	
			0x11, 0x0,	/* FC_RP */
/* 26 */	NdrFcShort( 0x14 ),	/* Offset= 20 (46) */
/* 28 */	
			0x1d,		/* FC_SMFARRAY */
			0x1,		/* 1 */
/* 30 */	NdrFcShort( 0x20 ),	/* 32 */
/* 32 */	0x5,		/* FC_WCHAR */
			0x5b,		/* FC_END */
/* 34 */	
			0x1d,		/* FC_SMFARRAY */
			0x1,		/* 1 */
/* 36 */	NdrFcShort( 0x200 ),	/* 512 */
/* 38 */	0x5,		/* FC_WCHAR */
			0x5b,		/* FC_END */
/* 40 */	
			0x1d,		/* FC_SMFARRAY */
			0x1,		/* 1 */
/* 42 */	NdrFcShort( 0x82 ),	/* 130 */
/* 44 */	0x5,		/* FC_WCHAR */
			0x5b,		/* FC_END */
/* 46 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 48 */	NdrFcShort( 0x3c8 ),	/* 968 */
/* 50 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 52 */	NdrFcShort( 0xffd8 ),	/* Offset= -40 (12) */
/* 54 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 56 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 58 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (28) */
/* 60 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 62 */	NdrFcShort( 0xffde ),	/* Offset= -34 (28) */
/* 64 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 66 */	NdrFcShort( 0xffda ),	/* Offset= -38 (28) */
/* 68 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 70 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (28) */
/* 72 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 74 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (28) */
/* 76 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 78 */	0x0,		/* 0 */
			NdrFcShort( 0xffd3 ),	/* Offset= -45 (34) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 82 */	0x0,		/* 0 */
			NdrFcShort( 0xffd5 ),	/* Offset= -43 (40) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 86 */	0x0,		/* 0 */
			NdrFcShort( 0xffd1 ),	/* Offset= -47 (40) */
			0x8,		/* FC_LONG */
/* 90 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */

			0x0
        }
    };


/* Standard interface: __MIDL_itf_protnotify_0000_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: INetCfgPnpReconfigCallback, ver. 0.0,
   GUID={0x8d84bd35,0xe227,0x11d2,{0xb7,0x00,0x00,0xa0,0xc9,0x8a,0x6a,0x85}} */


/* Object interface: INetCfgComponentControl, ver. 0.0,
   GUID={0x932238df,0xbea1,0x11d0,{0x92,0x98,0x00,0xc0,0x4f,0xc9,0x9d,0xcf}} */


/* Object interface: INetCfgComponentSetup, ver. 0.0,
   GUID={0x932238e3,0xbea1,0x11d0,{0x92,0x98,0x00,0xc0,0x4f,0xc9,0x9d,0xcf}} */


/* Object interface: INetCfgComponentPropertyUi, ver. 0.0,
   GUID={0x932238e0,0xbea1,0x11d0,{0x92,0x98,0x00,0xc0,0x4f,0xc9,0x9d,0xcf}} */


/* Object interface: INetCfgComponentNotifyBinding, ver. 0.0,
   GUID={0x932238e1,0xbea1,0x11d0,{0x92,0x98,0x00,0xc0,0x4f,0xc9,0x9d,0xcf}} */


/* Object interface: INetCfgComponentNotifyGlobal, ver. 0.0,
   GUID={0x932238e2,0xbea1,0x11d0,{0x92,0x98,0x00,0xc0,0x4f,0xc9,0x9d,0xcf}} */


/* Object interface: INetCfgComponentUpperEdge, ver. 0.0,
   GUID={0x932238e4,0xbea1,0x11d0,{0x92,0x98,0x00,0xc0,0x4f,0xc9,0x9d,0xcf}} */


/* Object interface: INetLanConnectionUiInfo, ver. 0.0,
   GUID={0xC08956A6,0x1CD3,0x11D1,{0xB1,0xC5,0x00,0x80,0x5F,0xC1,0x27,0x0E}} */

#pragma code_seg(".orpc")
static const unsigned short INetLanConnectionUiInfo_FormatStringOffsetTable[] =
    {
    0
    };

static const MIDL_STUBLESS_PROXY_INFO INetLanConnectionUiInfo_ProxyInfo =
    {
    &Object_StubDesc,
    protnotify__MIDL_ProcFormatString.Format,
    &INetLanConnectionUiInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO INetLanConnectionUiInfo_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    protnotify__MIDL_ProcFormatString.Format,
    &INetLanConnectionUiInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _INetLanConnectionUiInfoProxyVtbl = 
{
    &INetLanConnectionUiInfo_ProxyInfo,
    &IID_INetLanConnectionUiInfo,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* INetLanConnectionUiInfo::GetDeviceGuid */
};

const CInterfaceStubVtbl _INetLanConnectionUiInfoStubVtbl =
{
    &IID_INetLanConnectionUiInfo,
    &INetLanConnectionUiInfo_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: INetRasConnectionIpUiInfo, ver. 0.0,
   GUID={0xFAEDCF58,0x31FE,0x11D1,{0xAA,0xD2,0x00,0x80,0x5F,0xC1,0x27,0x0E}} */

#pragma code_seg(".orpc")
static const unsigned short INetRasConnectionIpUiInfo_FormatStringOffsetTable[] =
    {
    36
    };

static const MIDL_STUBLESS_PROXY_INFO INetRasConnectionIpUiInfo_ProxyInfo =
    {
    &Object_StubDesc,
    protnotify__MIDL_ProcFormatString.Format,
    &INetRasConnectionIpUiInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO INetRasConnectionIpUiInfo_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    protnotify__MIDL_ProcFormatString.Format,
    &INetRasConnectionIpUiInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _INetRasConnectionIpUiInfoProxyVtbl = 
{
    &INetRasConnectionIpUiInfo_ProxyInfo,
    &IID_INetRasConnectionIpUiInfo,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* INetRasConnectionIpUiInfo::GetUiInfo */
};

const CInterfaceStubVtbl _INetRasConnectionIpUiInfoStubVtbl =
{
    &IID_INetRasConnectionIpUiInfo,
    &INetRasConnectionIpUiInfo_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: INetCfgComponentSysPrep, ver. 0.0,
   GUID={0xC0E8AE9A,0x306E,0x11D1,{0xAA,0xCF,0x00,0x80,0x5F,0xC1,0x27,0x0E}} */

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    protnotify__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x70001f3, /* MIDL Version 7.0.499 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * _protnotify_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_INetRasConnectionIpUiInfoProxyVtbl,
    ( CInterfaceProxyVtbl *) &_INetLanConnectionUiInfoProxyVtbl,
    0
};

const CInterfaceStubVtbl * _protnotify_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_INetRasConnectionIpUiInfoStubVtbl,
    ( CInterfaceStubVtbl *) &_INetLanConnectionUiInfoStubVtbl,
    0
};

PCInterfaceName const _protnotify_InterfaceNamesList[] = 
{
    "INetRasConnectionIpUiInfo",
    "INetLanConnectionUiInfo",
    0
};


#define _protnotify_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _protnotify, pIID, n)

int __stdcall _protnotify_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _protnotify, 2, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _protnotify, 2, *pIndex )
    
}

const ExtendedProxyFileInfo protnotify_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _protnotify_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _protnotify_StubVtblList,
    (const PCInterfaceName * ) & _protnotify_InterfaceNamesList,
    0, // no delegation
    & _protnotify_IID_Lookup, 
    2,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

