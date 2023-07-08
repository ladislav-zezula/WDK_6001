

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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


#ifndef __inputkbd_h__
#define __inputkbd_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISoftKeyboard_FWD_DEFINED__
#define __ISoftKeyboard_FWD_DEFINED__
typedef interface ISoftKeyboard ISoftKeyboard;
#endif 	/* __ISoftKeyboard_FWD_DEFINED__ */


#ifndef __ISoftKeyboardEvents_FWD_DEFINED__
#define __ISoftKeyboardEvents_FWD_DEFINED__
typedef interface ISoftKeyboardEvents ISoftKeyboardEvents;
#endif 	/* __ISoftKeyboardEvents_FWD_DEFINED__ */


#ifndef __ISoftKbdTranslator_FWD_DEFINED__
#define __ISoftKbdTranslator_FWD_DEFINED__
typedef interface ISoftKbdTranslator ISoftKbdTranslator;
#endif 	/* __ISoftKbdTranslator_FWD_DEFINED__ */


#ifndef __ISoftInputKbdDevice_FWD_DEFINED__
#define __ISoftInputKbdDevice_FWD_DEFINED__
typedef interface ISoftInputKbdDevice ISoftInputKbdDevice;
#endif 	/* __ISoftInputKbdDevice_FWD_DEFINED__ */


#ifndef __ISoftInputKbdDeviceEvents_FWD_DEFINED__
#define __ISoftInputKbdDeviceEvents_FWD_DEFINED__
typedef interface ISoftInputKbdDeviceEvents ISoftInputKbdDeviceEvents;
#endif 	/* __ISoftInputKbdDeviceEvents_FWD_DEFINED__ */


#ifndef __SoftKeyboard_FWD_DEFINED__
#define __SoftKeyboard_FWD_DEFINED__

#ifdef __cplusplus
typedef class SoftKeyboard SoftKeyboard;
#else
typedef struct SoftKeyboard SoftKeyboard;
#endif /* __cplusplus */

#endif 	/* __SoftKeyboard_FWD_DEFINED__ */


#ifndef __SoftKbdTranslator_FWD_DEFINED__
#define __SoftKbdTranslator_FWD_DEFINED__

#ifdef __cplusplus
typedef class SoftKbdTranslator SoftKbdTranslator;
#else
typedef struct SoftKbdTranslator SoftKbdTranslator;
#endif /* __cplusplus */

#endif 	/* __SoftKbdTranslator_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __INPUTKBD_LIBRARY_DEFINED__
#define __INPUTKBD_LIBRARY_DEFINED__

/* library INPUTKBD */
/* [helpstring][version][uuid] */ 








typedef /* [helpstring][uuid] */  DECLSPEC_UUID("3758FD41-3BF7-49A0-A9FE-32DF6AD7796F") 
enum INDICATOR_KEY
    {	IND_NUM	= 0x1,
	IND_CAPS	= 0x2,
	IND_SCROLL	= 0x4,
	IND_COMPOSE	= 0x8,
	IND_KANA	= 0x10
    } 	INDICATOR_KEY;

typedef /* [helpstring][uuid] */  DECLSPEC_UUID("02B81820-14F4-47F9-A10D-DCA9B596BFFC") 
enum KBD_KEYS
    {	KEY_NONE	= 0,
	KEY_BACK_QUOTE	= 1,
	KEY_1	= 2,
	KEY_2	= 3,
	KEY_3	= 4,
	KEY_4	= 5,
	KEY_5	= 6,
	KEY_6	= 7,
	KEY_7	= 8,
	KEY_8	= 9,
	KEY_9	= 10,
	KEY_0	= 11,
	KEY_MINUS	= 12,
	KEY_EQUAL	= 13,
	KEY_BCKSP	= 15,
	KEY_TAB	= 16,
	KEY_Q	= 17,
	KEY_W	= 18,
	KEY_E	= 19,
	KEY_R	= 20,
	KEY_T	= 21,
	KEY_Y	= 22,
	KEY_U	= 23,
	KEY_I	= 24,
	KEY_O	= 25,
	KEY_P	= 26,
	KEY_L_SQUARE	= 27,
	KEY_R_SQUARE	= 28,
	KEY_BACK_SLASH	= 29,
	KEY_CAPS	= 30,
	KEY_A	= 31,
	KEY_S	= 32,
	KEY_D	= 33,
	KEY_F	= 34,
	KEY_G	= 35,
	KEY_H	= 36,
	KEY_J	= 37,
	KEY_K	= 38,
	KEY_L	= 39,
	KEY_SEMICOLON	= 40,
	KEY_QUOTE	= 41,
	KEY_ENTER	= 43,
	KEY_L_SHIFT	= 44,
	KEY_Z	= 46,
	KEY_X	= 47,
	KEY_C	= 48,
	KEY_V	= 49,
	KEY_B	= 50,
	KEY_N	= 51,
	KEY_M	= 52,
	KEY_COMMA	= 53,
	KEY_DOT	= 54,
	KEY_SLASH	= 55,
	KEY_R_SHIFT	= 57,
	KEY_L_CTRL	= 58,
	KEY_L_WIN	= 59,
	KEY_L_ALT	= 60,
	KEY_SPACE	= 61,
	KEY_R_ALT	= 62,
	KEY_R_WIN	= 63,
	KEY_R_CTRL	= 64,
	KEY_APPS	= 65,
	KEY_INSERT	= 75,
	KEY_DELETE	= 76,
	KEY_LEFT	= 79,
	KEY_HOME	= 80,
	KEY_END	= 81,
	KEY_UP	= 83,
	KEY_DOWN	= 84,
	KEY_PGUP	= 85,
	KEY_PGDOWN	= 86,
	KEY_RIGHT	= 89,
	KEY_NUM	= 90,
	KEY_NUM_7	= 91,
	KEY_NUM_4	= 92,
	KEY_NUM_1	= 93,
	KEY_NUM_SLASH	= 95,
	KEY_NUM_8	= 96,
	KEY_NUM_5	= 97,
	KEY_NUM_2	= 98,
	KEY_NUM_INS	= 99,
	KEY_NUM_ASTERISK	= 100,
	KEY_NUM_9	= 101,
	KEY_NUM_6	= 102,
	KEY_NUM_3	= 103,
	KEY_NUM_DEL	= 104,
	KEY_NUM_MINUS	= 105,
	KEY_NUM_PLUS	= 106,
	KEY_NUM_ENTER	= 108,
	KEY_ESC	= 110,
	KEY_F1	= 112,
	KEY_F2	= 113,
	KEY_F3	= 114,
	KEY_F4	= 115,
	KEY_F5	= 116,
	KEY_F6	= 117,
	KEY_F7	= 118,
	KEY_F8	= 119,
	KEY_F9	= 120,
	KEY_F10	= 121,
	KEY_F11	= 122,
	KEY_F12	= 123,
	KEY_PRTSCR	= 124,
	KEY_SCROLL	= 125,
	KEY_PAUSE	= 126
    } 	KBD_KEYS;

typedef /* [helpstring][uuid] */  DECLSPEC_UUID("3a3f140c-70a5-40c9-8d49-72ce1d407706") 
enum KBD_FLAGS
    {	KEY_MAKE	= 1,
	KEY_BREAK	= 2,
	KEY_E0	= 4,
	KEY_E1	= 8
    } 	KBD_FLAGS;

typedef /* [helpstring][uuid] */  DECLSPEC_UUID("17ff9f12-a99c-4f8c-9639-e05af05bf16b") 
enum KEYBOARD_TYPEMATIC
    {	KEYBOARD_TYPEMATIC_RATE_MINIMUM	= 2,
	KEYBOARD_TYPEMATIC_RATE_MAXIMUM	= 30,
	KEYBOARD_TYPEMATIC_RATE_DEFAULT	= 30,
	KEYBOARD_TYPEMATIC_DELAY_MINIMUM	= 250,
	KEYBOARD_TYPEMATIC_DELAY_MAXIMUM	= 1000,
	KEYBOARD_TYPEMATIC_DELAY_DEFAULT	= 250,
	KEYBOARD_TYPEMATIC_DELAY_INFINITE	= 0x7fffffff
    } 	KEYBOARD_TYPEMATIC;

typedef /* [helpstring][uuid] */  DECLSPEC_UUID("b4953232-674c-44ab-a538-3507b109bfd9") 
enum KEYBOARD_SCANCODESET
    {	KEYBOARD_SCAN_CODE_SET1	= 1,
	KEYBOARD_SCAN_CODE_SET2	= 2,
	KEYBOARD_HID_USAGE	= 4
    } 	KEYBOARD_SCANCODESET;

typedef /* [helpstring][uuid] */  DECLSPEC_UUID("5B2349BC-4723-48AB-821B-F4C200EC279F") struct KBD_KEYCODE
    {
    KBD_KEYS KeyCode;
    unsigned char ucFlag;
    } 	KBD_KEYCODE;

typedef /* [helpstring][uuid] */  DECLSPEC_UUID("4F574495-58BF-4DDF-AC2C-C9165469C5F8") struct KEYBOARD_ID
    {
    unsigned char ucType;
    unsigned char ucSubType;
    } 	KEYBOARD_ID;

typedef /* [helpstring][uuid] */  DECLSPEC_UUID("4213DD68-BB75-4BC9-A93C-25AB06559436") struct INDICATOR_LIST
    {
    unsigned short usMakeCode;
    unsigned short usIndicatorFlags;
    } 	INDICATOR_LIST;

typedef /* [helpstring][uuid] */  DECLSPEC_UUID("50CDCB64-1C84-46E3-A5C0-DE42A1A38DCC") struct KEYBOARD_INDICATOR_TRANSLATION
    {
    unsigned short usNumberOfIndicatorKeys;
    INDICATOR_LIST IndicatorList[ 1 ];
    } 	KEYBOARD_INDICATOR_TRANSLATION;

typedef /* [helpstring][uuid] */  DECLSPEC_UUID("DF4BB604-0DBD-486D-8932-442E88364E7D") struct KEYBOARD_TYPEMATIC_PARAMETERS
    {
    unsigned short usUnitId;
    unsigned long ulRate;
    unsigned long ulDelay;
    } 	KEYBOARD_TYPEMATIC_PARAMETERS;

typedef /* [helpstring][uuid] */  DECLSPEC_UUID("0D8BF528-11E1-485A-BCBC-F7033816B4D9") struct KEYBOARD_INDICATOR_PARAMETERS
    {
    unsigned short usUnitId;
    unsigned short usLedFlags;
    } 	KEYBOARD_INDICATOR_PARAMETERS;

typedef /* [helpstring][uuid] */  DECLSPEC_UUID("A5DD3C76-CA39-448F-973B-90700147EAEA") struct KEYBOARD_ATTRIBUTES
    {
    KEYBOARD_ID KeyboardIdentifier;
    unsigned short usKeyboardMode;
    unsigned short usNumberOfFuctionKeys;
    unsigned short usNumberOfIndicators;
    unsigned short usNumberOfKeysTotal;
    unsigned long ulInoutDataQueueLength;
    KEYBOARD_TYPEMATIC_PARAMETERS KeyRepeatMinimum;
    KEYBOARD_TYPEMATIC_PARAMETERS KeyRepeatMaximum;
    } 	KEYBOARD_ATTRIBUTES;

typedef /* [helpstring][uuid] */  DECLSPEC_UUID("A3179795-DF27-41D3-A820-A2A1D3D5FEBE") struct KEYBOARD_INPUT_DATA
    {
    unsigned short usUnitId;
    unsigned long ulMakeCode;
    unsigned short usFlags;
    unsigned short usReserved;
    unsigned long ulExtraInformation;
    } 	KEYBOARD_INPUT_DATA;


EXTERN_C const IID LIBID_INPUTKBD;

#ifndef __ISoftKeyboard_INTERFACE_DEFINED__
#define __ISoftKeyboard_INTERFACE_DEFINED__

/* interface ISoftKeyboard */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ISoftKeyboard;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5F228A9D-7678-4283-BE25-DED15E2867AE")
    ISoftKeyboard : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RepeatDelay( 
            /* [retval][out] */ __RPC__out ULONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RepeatRate( 
            /* [retval][out] */ __RPC__out ULONG *pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT __stdcall get_IndicatorStatus( 
            /* [in] */ INDICATOR_KEY LedKey,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pStatus) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT __stdcall get_BufferSize( 
            /* [retval][out] */ __RPC__out SHORT *pNumberOfEvents) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT __stdcall get_Translator( 
            /* [retval][out] */ __RPC__deref_out_opt SoftKbdTranslator	**ppTranslator) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT __stdcall put_Translator( 
            /* [in] */ __RPC__in SoftKbdTranslator	*pTranslator) = 0;
        
        virtual /* [helpstring][propputref][id] */ HRESULT __stdcall putref_Translator( 
            /* [in] */ __RPC__in SoftKbdTranslator	*pTranslator) = 0;
        
        virtual /* [helpstring][id] */ HRESULT __stdcall HitKeyOnce( 
            /* [in] */ KBD_KEYS KeyCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT __stdcall PressKey( 
            /* [in] */ KBD_KEYS KeyCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT __stdcall ReleaseKey( 
            /* [in] */ KBD_KEYS KeyCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT __stdcall PressAndReleaseKeys( 
            /* [in] */ __RPC__in BSTR KeyStrokes) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISoftKeyboardVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISoftKeyboard * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISoftKeyboard * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISoftKeyboard * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISoftKeyboard * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISoftKeyboard * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISoftKeyboard * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISoftKeyboard * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RepeatDelay )( 
            ISoftKeyboard * This,
            /* [retval][out] */ __RPC__out ULONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RepeatRate )( 
            ISoftKeyboard * This,
            /* [retval][out] */ __RPC__out ULONG *pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( __stdcall *get_IndicatorStatus )( 
            ISoftKeyboard * This,
            /* [in] */ INDICATOR_KEY LedKey,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pStatus);
        
        /* [helpstring][propget][id] */ HRESULT ( __stdcall *get_BufferSize )( 
            ISoftKeyboard * This,
            /* [retval][out] */ __RPC__out SHORT *pNumberOfEvents);
        
        /* [helpstring][propget][id] */ HRESULT ( __stdcall *get_Translator )( 
            ISoftKeyboard * This,
            /* [retval][out] */ __RPC__deref_out_opt SoftKbdTranslator	**ppTranslator);
        
        /* [helpstring][propput][id] */ HRESULT ( __stdcall *put_Translator )( 
            ISoftKeyboard * This,
            /* [in] */ __RPC__in SoftKbdTranslator	*pTranslator);
        
        /* [helpstring][propputref][id] */ HRESULT ( __stdcall *putref_Translator )( 
            ISoftKeyboard * This,
            /* [in] */ __RPC__in SoftKbdTranslator	*pTranslator);
        
        /* [helpstring][id] */ HRESULT ( __stdcall *HitKeyOnce )( 
            ISoftKeyboard * This,
            /* [in] */ KBD_KEYS KeyCode);
        
        /* [helpstring][id] */ HRESULT ( __stdcall *PressKey )( 
            ISoftKeyboard * This,
            /* [in] */ KBD_KEYS KeyCode);
        
        /* [helpstring][id] */ HRESULT ( __stdcall *ReleaseKey )( 
            ISoftKeyboard * This,
            /* [in] */ KBD_KEYS KeyCode);
        
        /* [helpstring][id] */ HRESULT ( __stdcall *PressAndReleaseKeys )( 
            ISoftKeyboard * This,
            /* [in] */ __RPC__in BSTR KeyStrokes);
        
        END_INTERFACE
    } ISoftKeyboardVtbl;

    interface ISoftKeyboard
    {
        CONST_VTBL struct ISoftKeyboardVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISoftKeyboard_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISoftKeyboard_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISoftKeyboard_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISoftKeyboard_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISoftKeyboard_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISoftKeyboard_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISoftKeyboard_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISoftKeyboard_get_RepeatDelay(This,pVal)	\
    ( (This)->lpVtbl -> get_RepeatDelay(This,pVal) ) 

#define ISoftKeyboard_get_RepeatRate(This,pVal)	\
    ( (This)->lpVtbl -> get_RepeatRate(This,pVal) ) 

#define ISoftKeyboard_get_IndicatorStatus(This,LedKey,pStatus)	\
    ( (This)->lpVtbl -> get_IndicatorStatus(This,LedKey,pStatus) ) 

#define ISoftKeyboard_get_BufferSize(This,pNumberOfEvents)	\
    ( (This)->lpVtbl -> get_BufferSize(This,pNumberOfEvents) ) 

#define ISoftKeyboard_get_Translator(This,ppTranslator)	\
    ( (This)->lpVtbl -> get_Translator(This,ppTranslator) ) 

#define ISoftKeyboard_put_Translator(This,pTranslator)	\
    ( (This)->lpVtbl -> put_Translator(This,pTranslator) ) 

#define ISoftKeyboard_putref_Translator(This,pTranslator)	\
    ( (This)->lpVtbl -> putref_Translator(This,pTranslator) ) 

#define ISoftKeyboard_HitKeyOnce(This,KeyCode)	\
    ( (This)->lpVtbl -> HitKeyOnce(This,KeyCode) ) 

#define ISoftKeyboard_PressKey(This,KeyCode)	\
    ( (This)->lpVtbl -> PressKey(This,KeyCode) ) 

#define ISoftKeyboard_ReleaseKey(This,KeyCode)	\
    ( (This)->lpVtbl -> ReleaseKey(This,KeyCode) ) 

#define ISoftKeyboard_PressAndReleaseKeys(This,KeyStrokes)	\
    ( (This)->lpVtbl -> PressAndReleaseKeys(This,KeyStrokes) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISoftKeyboard_INTERFACE_DEFINED__ */


#ifndef __ISoftKeyboardEvents_INTERFACE_DEFINED__
#define __ISoftKeyboardEvents_INTERFACE_DEFINED__

/* interface ISoftKeyboardEvents */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_ISoftKeyboardEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0A3D4EB4-2A36-412D-9CE6-4349D52CE1AB")
    ISoftKeyboardEvents : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT __stdcall IndicatorOn( 
            /* [in] */ INDICATOR_KEY LedKey) = 0;
        
        virtual /* [helpstring][id] */ HRESULT __stdcall IndicatorOff( 
            /* [in] */ INDICATOR_KEY LedKey) = 0;
        
        virtual /* [helpstring][id] */ HRESULT __stdcall BufferOverflow( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISoftKeyboardEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISoftKeyboardEvents * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISoftKeyboardEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISoftKeyboardEvents * This);
        
        /* [helpstring][id] */ HRESULT ( __stdcall *IndicatorOn )( 
            ISoftKeyboardEvents * This,
            /* [in] */ INDICATOR_KEY LedKey);
        
        /* [helpstring][id] */ HRESULT ( __stdcall *IndicatorOff )( 
            ISoftKeyboardEvents * This,
            /* [in] */ INDICATOR_KEY LedKey);
        
        /* [helpstring][id] */ HRESULT ( __stdcall *BufferOverflow )( 
            ISoftKeyboardEvents * This);
        
        END_INTERFACE
    } ISoftKeyboardEventsVtbl;

    interface ISoftKeyboardEvents
    {
        CONST_VTBL struct ISoftKeyboardEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISoftKeyboardEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISoftKeyboardEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISoftKeyboardEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISoftKeyboardEvents_IndicatorOn(This,LedKey)	\
    ( (This)->lpVtbl -> IndicatorOn(This,LedKey) ) 

#define ISoftKeyboardEvents_IndicatorOff(This,LedKey)	\
    ( (This)->lpVtbl -> IndicatorOff(This,LedKey) ) 

#define ISoftKeyboardEvents_BufferOverflow(This)	\
    ( (This)->lpVtbl -> BufferOverflow(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISoftKeyboardEvents_INTERFACE_DEFINED__ */


#ifndef __ISoftKbdTranslator_INTERFACE_DEFINED__
#define __ISoftKbdTranslator_INTERFACE_DEFINED__

/* interface ISoftKbdTranslator */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ISoftKbdTranslator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B9CAF9E3-E9E5-41D4-842F-3D4A764FDABE")
    ISoftKbdTranslator : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT __stdcall get_Language( 
            /* [retval][out] */ __RPC__out ULONG *pLCID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT __stdcall TranslateString2Keycodes( 
            /* [in] */ UINT nSize,
            /* [in] */ __RPC__in WCHAR *szStrW,
            /* [out] */ __RPC__out UINT *pnUnits,
            /* [retval][out] */ __RPC__deref_out_opt KBD_KEYCODE **ppKeyCodes) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISoftKbdTranslatorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISoftKbdTranslator * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISoftKbdTranslator * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISoftKbdTranslator * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISoftKbdTranslator * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISoftKbdTranslator * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISoftKbdTranslator * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISoftKbdTranslator * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( __stdcall *get_Language )( 
            ISoftKbdTranslator * This,
            /* [retval][out] */ __RPC__out ULONG *pLCID);
        
        /* [helpstring][id] */ HRESULT ( __stdcall *TranslateString2Keycodes )( 
            ISoftKbdTranslator * This,
            /* [in] */ UINT nSize,
            /* [in] */ __RPC__in WCHAR *szStrW,
            /* [out] */ __RPC__out UINT *pnUnits,
            /* [retval][out] */ __RPC__deref_out_opt KBD_KEYCODE **ppKeyCodes);
        
        END_INTERFACE
    } ISoftKbdTranslatorVtbl;

    interface ISoftKbdTranslator
    {
        CONST_VTBL struct ISoftKbdTranslatorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISoftKbdTranslator_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISoftKbdTranslator_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISoftKbdTranslator_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISoftKbdTranslator_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISoftKbdTranslator_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISoftKbdTranslator_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISoftKbdTranslator_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISoftKbdTranslator_get_Language(This,pLCID)	\
    ( (This)->lpVtbl -> get_Language(This,pLCID) ) 

#define ISoftKbdTranslator_TranslateString2Keycodes(This,nSize,szStrW,pnUnits,ppKeyCodes)	\
    ( (This)->lpVtbl -> TranslateString2Keycodes(This,nSize,szStrW,pnUnits,ppKeyCodes) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISoftKbdTranslator_INTERFACE_DEFINED__ */


#ifndef __ISoftInputKbdDevice_INTERFACE_DEFINED__
#define __ISoftInputKbdDevice_INTERFACE_DEFINED__

/* interface ISoftInputKbdDevice */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ISoftInputKbdDevice;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("93971D66-A828-4CCA-9DEC-01B8EE4206A5")
    ISoftInputKbdDevice : public IUnknown
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT __stdcall get_Attributes( 
            /* [retval][out] */ __RPC__deref_out_opt KEYBOARD_ATTRIBUTES **ppAttributes) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT __stdcall put_Attributes( 
            /* [in] */ __RPC__in KEYBOARD_ATTRIBUTES *pAttributes) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT __stdcall get_IndicatorTranslation( 
            /* [retval][out] */ __RPC__deref_out_opt KEYBOARD_INDICATOR_TRANSLATION **ppIndicatorTrans) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT __stdcall put_IndicatorTranslation( 
            /* [in] */ __RPC__in KEYBOARD_INDICATOR_TRANSLATION *pIndicatorTrans) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT __stdcall get_Typematic( 
            /* [retval][out] */ __RPC__deref_out_opt KEYBOARD_TYPEMATIC_PARAMETERS **ppTypematic) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT __stdcall put_Typematic( 
            /* [in] */ __RPC__in KEYBOARD_TYPEMATIC_PARAMETERS *pTypematic) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT __stdcall get_Indicators( 
            /* [retval][out] */ __RPC__deref_out_opt KEYBOARD_INDICATOR_PARAMETERS **ppIndicator) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT __stdcall put_Indicators( 
            /* [in] */ __RPC__in KEYBOARD_INDICATOR_PARAMETERS *pIndicator) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall Read( 
            /* [out] */ __RPC__out USHORT *pUnits,
            /* [retval][out] */ __RPC__deref_out_opt KEYBOARD_INPUT_DATA **ppKbdData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISoftInputKbdDeviceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISoftInputKbdDevice * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISoftInputKbdDevice * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISoftInputKbdDevice * This);
        
        /* [helpstring][propget][id] */ HRESULT ( __stdcall *get_Attributes )( 
            ISoftInputKbdDevice * This,
            /* [retval][out] */ __RPC__deref_out_opt KEYBOARD_ATTRIBUTES **ppAttributes);
        
        /* [helpstring][propput][id] */ HRESULT ( __stdcall *put_Attributes )( 
            ISoftInputKbdDevice * This,
            /* [in] */ __RPC__in KEYBOARD_ATTRIBUTES *pAttributes);
        
        /* [helpstring][propget][id] */ HRESULT ( __stdcall *get_IndicatorTranslation )( 
            ISoftInputKbdDevice * This,
            /* [retval][out] */ __RPC__deref_out_opt KEYBOARD_INDICATOR_TRANSLATION **ppIndicatorTrans);
        
        /* [helpstring][propput][id] */ HRESULT ( __stdcall *put_IndicatorTranslation )( 
            ISoftInputKbdDevice * This,
            /* [in] */ __RPC__in KEYBOARD_INDICATOR_TRANSLATION *pIndicatorTrans);
        
        /* [helpstring][propget][id] */ HRESULT ( __stdcall *get_Typematic )( 
            ISoftInputKbdDevice * This,
            /* [retval][out] */ __RPC__deref_out_opt KEYBOARD_TYPEMATIC_PARAMETERS **ppTypematic);
        
        /* [helpstring][propput][id] */ HRESULT ( __stdcall *put_Typematic )( 
            ISoftInputKbdDevice * This,
            /* [in] */ __RPC__in KEYBOARD_TYPEMATIC_PARAMETERS *pTypematic);
        
        /* [helpstring][propget][id] */ HRESULT ( __stdcall *get_Indicators )( 
            ISoftInputKbdDevice * This,
            /* [retval][out] */ __RPC__deref_out_opt KEYBOARD_INDICATOR_PARAMETERS **ppIndicator);
        
        /* [helpstring][propput][id] */ HRESULT ( __stdcall *put_Indicators )( 
            ISoftInputKbdDevice * This,
            /* [in] */ __RPC__in KEYBOARD_INDICATOR_PARAMETERS *pIndicator);
        
        /* [helpstring] */ HRESULT ( __stdcall *Read )( 
            ISoftInputKbdDevice * This,
            /* [out] */ __RPC__out USHORT *pUnits,
            /* [retval][out] */ __RPC__deref_out_opt KEYBOARD_INPUT_DATA **ppKbdData);
        
        END_INTERFACE
    } ISoftInputKbdDeviceVtbl;

    interface ISoftInputKbdDevice
    {
        CONST_VTBL struct ISoftInputKbdDeviceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISoftInputKbdDevice_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISoftInputKbdDevice_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISoftInputKbdDevice_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISoftInputKbdDevice_get_Attributes(This,ppAttributes)	\
    ( (This)->lpVtbl -> get_Attributes(This,ppAttributes) ) 

#define ISoftInputKbdDevice_put_Attributes(This,pAttributes)	\
    ( (This)->lpVtbl -> put_Attributes(This,pAttributes) ) 

#define ISoftInputKbdDevice_get_IndicatorTranslation(This,ppIndicatorTrans)	\
    ( (This)->lpVtbl -> get_IndicatorTranslation(This,ppIndicatorTrans) ) 

#define ISoftInputKbdDevice_put_IndicatorTranslation(This,pIndicatorTrans)	\
    ( (This)->lpVtbl -> put_IndicatorTranslation(This,pIndicatorTrans) ) 

#define ISoftInputKbdDevice_get_Typematic(This,ppTypematic)	\
    ( (This)->lpVtbl -> get_Typematic(This,ppTypematic) ) 

#define ISoftInputKbdDevice_put_Typematic(This,pTypematic)	\
    ( (This)->lpVtbl -> put_Typematic(This,pTypematic) ) 

#define ISoftInputKbdDevice_get_Indicators(This,ppIndicator)	\
    ( (This)->lpVtbl -> get_Indicators(This,ppIndicator) ) 

#define ISoftInputKbdDevice_put_Indicators(This,pIndicator)	\
    ( (This)->lpVtbl -> put_Indicators(This,pIndicator) ) 

#define ISoftInputKbdDevice_Read(This,pUnits,ppKbdData)	\
    ( (This)->lpVtbl -> Read(This,pUnits,ppKbdData) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISoftInputKbdDevice_INTERFACE_DEFINED__ */


#ifndef __ISoftInputKbdDeviceEvents_INTERFACE_DEFINED__
#define __ISoftInputKbdDeviceEvents_INTERFACE_DEFINED__

/* interface ISoftInputKbdDeviceEvents */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_ISoftInputKbdDeviceEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("61C0F31A-2A8B-4DD4-A087-9695F64C089D")
    ISoftInputKbdDeviceEvents : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT __stdcall KeyTouched( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISoftInputKbdDeviceEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISoftInputKbdDeviceEvents * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISoftInputKbdDeviceEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISoftInputKbdDeviceEvents * This);
        
        /* [helpstring][id] */ HRESULT ( __stdcall *KeyTouched )( 
            ISoftInputKbdDeviceEvents * This);
        
        END_INTERFACE
    } ISoftInputKbdDeviceEventsVtbl;

    interface ISoftInputKbdDeviceEvents
    {
        CONST_VTBL struct ISoftInputKbdDeviceEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISoftInputKbdDeviceEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISoftInputKbdDeviceEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISoftInputKbdDeviceEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISoftInputKbdDeviceEvents_KeyTouched(This)	\
    ( (This)->lpVtbl -> KeyTouched(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISoftInputKbdDeviceEvents_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SoftKeyboard;

#ifdef __cplusplus

class DECLSPEC_UUID("90049CFF-04C3-4FC0-B41E-325FCC7809AA")
SoftKeyboard;
#endif

EXTERN_C const CLSID CLSID_SoftKbdTranslator;

#ifdef __cplusplus

class DECLSPEC_UUID("95CA8166-E427-4DC4-B41A-408C6D6628BE")
SoftKbdTranslator;
#endif
#endif /* __INPUTKBD_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


