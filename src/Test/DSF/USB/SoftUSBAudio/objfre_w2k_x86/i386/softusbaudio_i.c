

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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

MIDL_DEFINE_GUID(IID, LIBID_SoftUSBAudioLib,0x1EA32BAB,0x633B,0x4A9A,0xA5,0x53,0x04,0x1E,0xD9,0x69,0xF2,0x69);


MIDL_DEFINE_GUID(IID, IID_IAudioDevice,0xC45544C0,0xAFA8,0x4544,0x94,0x8C,0x5D,0x79,0x1A,0x51,0x77,0x67);


MIDL_DEFINE_GUID(IID, DIID_IAudioDeviceEvents,0xDF6DD301,0x4359,0x4798,0x91,0x33,0x82,0xA5,0x3D,0xB8,0x4E,0x6C);


MIDL_DEFINE_GUID(CLSID, CLSID_AudioDevice,0x532E9231,0x5814,0x4DCD,0xA7,0x08,0x93,0x8D,0x8D,0xC0,0xE1,0xE1);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



