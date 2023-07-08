

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_INetCfgPnpReconfigCallback,0x8d84bd35,0xe227,0x11d2,0xb7,0x00,0x00,0xa0,0xc9,0x8a,0x6a,0x85);


MIDL_DEFINE_GUID(IID, IID_INetCfgComponentControl,0x932238df,0xbea1,0x11d0,0x92,0x98,0x00,0xc0,0x4f,0xc9,0x9d,0xcf);


MIDL_DEFINE_GUID(IID, IID_INetCfgComponentSetup,0x932238e3,0xbea1,0x11d0,0x92,0x98,0x00,0xc0,0x4f,0xc9,0x9d,0xcf);


MIDL_DEFINE_GUID(IID, IID_INetCfgComponentPropertyUi,0x932238e0,0xbea1,0x11d0,0x92,0x98,0x00,0xc0,0x4f,0xc9,0x9d,0xcf);


MIDL_DEFINE_GUID(IID, IID_INetCfgComponentNotifyBinding,0x932238e1,0xbea1,0x11d0,0x92,0x98,0x00,0xc0,0x4f,0xc9,0x9d,0xcf);


MIDL_DEFINE_GUID(IID, IID_INetCfgComponentNotifyGlobal,0x932238e2,0xbea1,0x11d0,0x92,0x98,0x00,0xc0,0x4f,0xc9,0x9d,0xcf);


MIDL_DEFINE_GUID(IID, IID_INetCfgComponentUpperEdge,0x932238e4,0xbea1,0x11d0,0x92,0x98,0x00,0xc0,0x4f,0xc9,0x9d,0xcf);


MIDL_DEFINE_GUID(IID, IID_INetLanConnectionUiInfo,0xC08956A6,0x1CD3,0x11D1,0xB1,0xC5,0x00,0x80,0x5F,0xC1,0x27,0x0E);


MIDL_DEFINE_GUID(IID, IID_INetRasConnectionIpUiInfo,0xFAEDCF58,0x31FE,0x11D1,0xAA,0xD2,0x00,0x80,0x5F,0xC1,0x27,0x0E);


MIDL_DEFINE_GUID(IID, IID_INetCfgComponentSysPrep,0xC0E8AE9A,0x306E,0x11D1,0xAA,0xCF,0x00,0x80,0x5F,0xC1,0x27,0x0E);


MIDL_DEFINE_GUID(IID, LIBID_NotifyLib,0xd5a293af,0x371a,0x4694,0xa9,0xb7,0xfc,0x9d,0x40,0x9d,0xef,0x3b);


MIDL_DEFINE_GUID(CLSID, CLSID_CProtNotify,0x21e7e731,0xf286,0x4116,0xb3,0xc2,0xd4,0x3c,0xcb,0xa2,0x9f,0x07);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



