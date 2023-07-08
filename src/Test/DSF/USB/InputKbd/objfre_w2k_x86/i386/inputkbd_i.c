

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for inputkbd.idl:
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

MIDL_DEFINE_GUID(IID, LIBID_INPUTKBD,0x3441EC5D,0x6A58,0x4358,0x9E,0x1B,0x32,0x35,0x87,0x42,0x90,0x66);


MIDL_DEFINE_GUID(IID, IID_ISoftKeyboard,0x5F228A9D,0x7678,0x4283,0xBE,0x25,0xDE,0xD1,0x5E,0x28,0x67,0xAE);


MIDL_DEFINE_GUID(IID, IID_ISoftKeyboardEvents,0x0A3D4EB4,0x2A36,0x412D,0x9C,0xE6,0x43,0x49,0xD5,0x2C,0xE1,0xAB);


MIDL_DEFINE_GUID(IID, IID_ISoftKbdTranslator,0xB9CAF9E3,0xE9E5,0x41D4,0x84,0x2F,0x3D,0x4A,0x76,0x4F,0xDA,0xBE);


MIDL_DEFINE_GUID(IID, IID_ISoftInputKbdDevice,0x93971D66,0xA828,0x4CCA,0x9D,0xEC,0x01,0xB8,0xEE,0x42,0x06,0xA5);


MIDL_DEFINE_GUID(IID, IID_ISoftInputKbdDeviceEvents,0x61C0F31A,0x2A8B,0x4DD4,0xA0,0x87,0x96,0x95,0xF6,0x4C,0x08,0x9D);


MIDL_DEFINE_GUID(CLSID, CLSID_SoftKeyboard,0x90049CFF,0x04C3,0x4FC0,0xB4,0x1E,0x32,0x5F,0xCC,0x78,0x09,0xAA);


MIDL_DEFINE_GUID(CLSID, CLSID_SoftKbdTranslator,0x95CA8166,0xE427,0x4DC4,0xB4,0x1A,0x40,0x8C,0x6D,0x66,0x28,0xBE);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



