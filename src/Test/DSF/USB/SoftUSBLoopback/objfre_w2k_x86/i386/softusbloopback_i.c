

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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

MIDL_DEFINE_GUID(IID, LIBID_SoftUSBLoopbackLib,0xE2A2A936,0x5E15,0x43BF,0xAA,0xE8,0x10,0x93,0x40,0xCC,0xD6,0x8F);


MIDL_DEFINE_GUID(IID, IID_ILoopbackDevice,0x438CB71F,0xED63,0x42A1,0xB8,0x39,0x15,0x43,0xAB,0xDA,0xC7,0x96);


MIDL_DEFINE_GUID(IID, DIID_ILoopbackDeviceEvents,0x8EA6471E,0x4F30,0x4EA6,0x88,0xAF,0x67,0x70,0x3A,0x99,0x91,0x7C);


MIDL_DEFINE_GUID(CLSID, CLSID_LoopbackDevice,0x8419B5D4,0x9DE5,0x468E,0x82,0x73,0x53,0x3D,0x49,0xA9,0x4C,0x31);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



