

//    
//  $Workfile: atiddhsl.h $
//
//  Description:
//
//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999-2001, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//
 
#ifndef _ATIDDHSL_H
#define _ATIDDHSL_H
#include <d3dumddi.h>

// Shared memory allocation is done on a 4K PAGE basis.
// All such memory is cleared during allocation.
// Hsl clients should allocate several pages during init
// and then suballocate space for shared structs from them.
// - Implemented with VirtualAlloc on Win9x
// - Implemented with EngAllocMem on Win2K.
extern LPVOID APIENTRY pDdHslSharedMemCallocEx(LPVOID lpATIDXObj, DWORD dwBytes);
extern BOOL   APIENTRY bDdHslSharedMemFreeEx(LPVOID lpATIDXObj, PVOID pvMem);
extern LPVOID APIENTRY pDdHslSharedMemCalloc(DWORD dwBytes);
extern BOOL   APIENTRY bDdHslSharedMemFree(LPVOID pvMem);

// Allocate dwBytes bytes of video memory.  The return value is the memory
// location, or else 0 if the function fails.
typedef enum _EDDHSLVIDMEMHEAP
{
    E_VIDMEM_HEAP_FRAMEBUFFER    = 0,   // Matches DDraw mem manager routines
    E_VIDMEM_HEAP_AGP            = 1,   // dwHeap.
    E_VIDMEM_HEAP_TOO_BIG        = 2
} EDDHSLVIDMEMHEAP;

typedef struct _DDHSLVIDMEMDATA
{
    LPVOID      lpVideoMemory;  // 32bit linear address
    ULONG_PTR   hSurface;       // CMM surface handle.
    DWORD       dwOffset;       // For rage6, this is the MC offset.
                                // For rage128, this is just the offset.
    LPVOID      lpRing3Addr;    // linear address in Ring3 space.
#ifdef UMD
    D3DKMT_HANDLE   hAllocation;
#endif // UMD
} DDHSLVIDMEMDATA;


extern HRESULT APIENTRY
vDdHslVideoMemoryAlloc(LPVOID lpDXObj,
                       LPDDRAWI_DIRECTDRAW_GBL lpGbl,
                       DWORD dwBytes,
                       DDHSLVIDMEMDATA  *pDdHslVidMemData,
                       EDDHSLVIDMEMHEAP eSpace,
                       PVOID pSysMem);

// Free the video memory whose location is pLocation.  The return value is 0
// iff the function fails.
extern BOOL APIENTRY bDdHslVideoMemoryFree(LPVOID lpDXObj,
                                           LPDDRAWI_DIRECTDRAW_GBL lpGbl,
                                           DDHSLVIDMEMDATA *pLocation,
                                           EDDHSLVIDMEMHEAP eSpace);


typedef enum _EDDHSLDEVICETYPE
{
    E_OVERLAY = 0,
    E_DVD     = 1,
    E_VPE     = 2,
    E_DEVICETYPE_TOO_BIG = 3
} EDDHSLDEVICETYPE;

// Retrieve specific device object. 
// pDevInfo is pointer to ddraw device object on win9x, pDev on win2k.
// The function returns pointer to device object specified by eDevType if successful,
// it returns null otherwise.
extern LPVOID APIENTRY pDdHslQueryDeviceObject(LPVOID pDevObj, EDDHSLDEVICETYPE eDevType);

typedef enum _EDDHSLCIINFOTYPE
{
    E_CIINFO_CIASICID             = 1,
    E_CIINFO_CIASICRANGES         = 2,
    E_CIINFO_CICHIPSETID          = 3,
    E_CIINFO_DCIDATA              = 4,
    E_CIINFO_ENUM_TOO_BIG         = 5,
    E_CIINFO_DCIDATA2             = 6
} EDDHSLCIINFOTYPE;

// Retrieve CI info specified by eCIInfoType and store it in pCIInfo which points
// to memory allocated by caller. Return TRUE if successful, FALSE otherwise.
extern BOOL __cdecl bDdHslQueryCIInfo(LPVOID lpDXObj, 
                              EDDHSLCIINFOTYPE eCIInfoType,
                              LPVOID pCIInfo);

///////////////////////////////////////////////////////////////////////////////////////////
// SHAREDD_TO_DO: Everything below this line is going to be removed from DDHSL interface
// after mm libs implemented the HSL interface defined in dxdriver_interface_layer.doc.
///////////////////////////////////////////////////////////////////////////////////////////
//
// This function requests pointers to individual components of the
// surfinfo struct maintained by the DDHAL. Each of these components
// must be maintained as separate entities in the surfinfo struct.
// The client to this interface can keep the pointer and test the
// value of the entity at any time. It is the responsibility of the client
// not to dereference the pointer after the surface is destroyed.
//
// dwFlag is an op code, which determines which entity in the surfinfo
// is pointed at by the returned pointer.
// - E_SURF_MC_OFFSET       : 32 bit offset of the surface in gfx chip space
// - E_SURF_TX_OFFSET       : offset used for the chip's TXOFFSET register
// - E_SURF_FLAGS           : 32 bit dword of surf specific flags set by ddhal
//
typedef enum _EDDHSLQUERY 
{
    E_SURF_MC_OFFSET                = 1,
    E_SURF_TX_OFFSET                = 2,
    E_SURF_FLAGS                    = 3,
    E_SURF_ZMASK_HANDLE             = 4,
    E_SURF_MIP_OFFSETS              = 5,
    E_SURF_ATISURF_HANDLE           = 6,
    E_SURF_ATISURF_VIDMEM           = 7,
    E_SURF_ATISURF_HEAP             = 8,
#if (DIRECT3D_VERSION >= 0x0900)
    E_SURF_MIP_LWFPVIDMEM           = 9,
    E_SURF_FCC_OFFSET               = 10,
    E_SURF_FCC_HEIGHT               = 11,
    E_SURF_ENUM_TOO_BIG             = 12,  // keep this one higher than valid
#else
    E_SURF_FCC_OFFSET               = 9,
    E_SURF_FCC_HEIGHT               = 10,
    E_SURF_ENUM_TOO_BIG             = 11,  // keep this one higher than valid
#endif //(DIRECT3D_VERSION >= 0x0900)

} EDDHSLQUERY;

extern LPDWORD APIENTRY
    pDdHslQueryATISurfInfo( LPVOID pDevInfo,
                            LPDDRAWI_DDRAWSURFACE_LCL lpSLcl,
                            EDDHSLQUERY eFlag ); //SHAREDD_TO_DO: to be removed.

extern DWORD APIENTRY dDdHslEscape(LPVOID pDevInfo, DWORD dwEscape,
                                   DWORD dwInputSize, LPVOID pInput,
                                   DWORD dwOutputSize, LPVOID pOutput);

typedef enum _EDDHSLREGVALTYPE
{
    E_REGISTRY_INT     = 1,
    E_REGISTRY_FLOAT   = 2,
    E_REGISTRY_BOOL    = 3,
    E_REGISTRY_STRING  = 4,
    E_REGISTRY_HEX     = 5,
    E_REGISTRY_TOO_BIG = 6
} EDDHSLREGVALTYPE;


// This function reads a registry value named "valname". The registry value data
// is returned in "value".
// valname: Input parameter. A registry value needs to be queried.
// type: Input parameter. It represents the data type of the value for the string valname.
// value: Output parameter. It is the value of the string pRegValue assigned to.
// HSL_REGISTRYVALUEDATA_SIZE_BYTES represents the size of "value" in bytes.

#define HSL_REGISTRYVALUEDATA_BYTE_SIZE  32

extern
BOOL
APIENTRY
bDdHslQueryRegistryValue(
    __in  LPVOID            pDevInfo,
    __in  CHAR             *pszValName,
    __in  EDDHSLREGVALTYPE  eType,
    __out VOID             *pValue
    );


//This function is used by overlay to get win2k large desktop info
extern DWORD _stdcall dDdHslGetPdevFlags(LPVOID pDevObj) ;

typedef LPDWORD (FAR PASCAL *LPDDHSLQUERYATISURFINFO) (LPVOID pDevInfo, LPDDRAWI_DDRAWSURFACE_LCL lpSLCL,
                                                       EDDHSLQUERY eFlag);

typedef LPVOID (FAR PASCAL *LPDDHSLSHAREDMEMCALLOC) (DWORD dwBytes);

typedef BOOL (FAR PASCAL *LPDDHSLSHAREDMEMFREE) (LPVOID pvMem);

typedef DWORD (FAR PASCAL *LPDDHSLESCAPE) (LPVOID pDevInfo, DWORD dwEscape,
                                   DWORD dwInputSize, LPVOID pInput,
                                   DWORD dwOutputSize, LPVOID pOutput);

typedef VOID (FAR PASCAL *LPDDHSLVIDEOMEMORYALLOC) (LPVOID pDevInfo,
                       LPDDRAWI_DIRECTDRAW_GBL lpGbl,
                       DWORD dwBytes,
                       DDHSLVIDMEMDATA  *pDdHslVidMemData,
                       EDDHSLVIDMEMHEAP eSpace
                       );

typedef BOOL (FAR PASCAL *LPDDHSLVIDEOMEMORYFREE) (LPVOID pDevInfo,
                                           LPDDRAWI_DIRECTDRAW_GBL lpGbl,
                                           DDHSLVIDMEMDATA *pLocation,
                                           EDDHSLVIDMEMHEAP eSpace);

typedef BOOL (FAR PASCAL *LPDDHSLQUERYREGISTRYVALUE) (LPVOID pDevInfo, char * valname,
                                          EDDHSLREGVALTYPE type,
                                          void *value);


typedef VOID (FAR PASCAL *LPDDHSLOVFLIP) ( LPVOID pDevInfo,
                                           DWORD dwOVBaseAdrsY,
                                           DWORD dwOVBaseAdrsU,
                                           DWORD dwOVBaseAdrsV,
                                           DWORD dwYPitch,
                                           DWORD dwUVPitch,
                                           DWORD dwMC12Flags);

//This structure holds the overlay physical destination rectangle
typedef struct _DDHSLPHYSSRCRW
{
    double PhysicalSrcLeft;
    double PhysicalSrcRight;
    double PhysicalSrcTop;
    double PhysicalSrcBottom;

} DDHSLPHYSSRCRW;

typedef BOOL (FAR PASCAL *LPDDHSLPHYSSRCREADWRITE) (LPVOID pDevInfo, DDHSLPHYSSRCRW *pDdHslPhysSrcRW, char chRW);

//Define the ddhsl function table size for version 2.2
//This is the byte size which will be used by DVD Hal to
//validate the function table.

#ifdef _WIN64
    #define DDHSLFUNCTABLESIZE_VER2_2      164
    #define DDHSLFUNCTABLESIZE_VER3_0      188
#else
    #define DDHSLFUNCTABLESIZE_VER2_2      84
    #define DDHSLFUNCTABLESIZE_VER3_0      96
#endif

//When adding the function, please put it at the end of
//the  table.
typedef struct _DDHSLFUNCTABLE
{
   DWORD  dwSize;
   LPDDHSLQUERYATISURFINFO pDdHslQueryATISurfInfo;
   LPDDHSLSHAREDMEMCALLOC pDdHslSharedMemCalloc;
   LPDDHSLSHAREDMEMFREE bDdHslSharedMemFree;
   LPDDHSLESCAPE dDdHslEscape;
   LPDDHSLVIDEOMEMORYALLOC vDdHslVideoMemoryAlloc;
   LPDDHSLVIDEOMEMORYFREE bDdHslVideoMemoryFree;
   LPVOID lpReserved1;
   LPVOID lpReserved2;
   LPVOID lpReserved3;
   LPVOID lpReserved4;
   LPVOID lpReserved5;
   LPVOID lpReserved6;
   LPVOID lpReserved7;
   LPVOID lpReserved8;
   LPVOID lpReserved9;
   LPDDHSLQUERYREGISTRYVALUE bDdHslQueryRegistryValue;
   LPDDHSLPHYSSRCREADWRITE bDdHslPhysSrcReadWrite;
   LPVOID lpReserved10;
   LPVOID lpReserved11;

   // End of Version 2.2. You can add new functions below.
   LPVOID lpReserved12;
   LPVOID lpReserved13;
   LPVOID lpReserved14;
} DDHSLFUNCTABLE;

typedef DDHSLFUNCTABLE *LPDDHSLFUNCTABLE;


typedef BOOL (FAR PASCAL *LPDDHSLQUERYFUNCTIONS) ( DDHSLFUNCTABLE  *ddHslFuncTable);


//********************************** HSLDPF and HSLASSERT *********************
//How to use:
//  HSLDPF( DWORD level, char* pDbgMsg, ...);
//  There are ten debug message settings which control the output of HSLDPF.
//  The debug message output is enabled by registry settings.  During driver
//  initalization the registry settings are read from HKEY_LOCAL_MACHINE,
//  "SOFTWARE\ATI Technologies\Driver\Debug"
//  Here are the levels and corresponding registry settings:
//
//  Level                     Resistry String                  Value
//
//  E_ASSERTION,            *No string Value*,      Always print Assertions
//                                              ( Causes int 3 debug interupt )
//  E_HAL_ENTRY_EXIT,       "HalEntryExit",         1 Enable, 0 Disable/Default
//  E_GENERAL_ENTRY_EXIT,   "GeneralEntryExit",     1 Enable, 0 Disable/Default
//  E_INFO_MESSAGE,         "InfoMessage",          1 Enable, 0 Disable/Default
//  E_ERROR_MESSAGE,        "ErrorMessage",         1 Enable, 0 Disable/Default
//  E_DATA_DUMP,            "DataDump",             1 Enable, 0 Disable/Default
//  E_DEBUG1,               "Debug1",               1 Enable, 0 Disable/Default
//  E_DEBUG2,               "Debug2",               1 Enable, 0 Disable/Default
//  E_BLT_DATA,             "BltData",              1 Enable, 0 Disable/Default
//  E_SURFACE_DATA,         "SurfaceData",          1 Enable, 0 Disable/Default
//  E_STATE_DATA,           "StateData",            1 Enable, 0 Disable/Default
//  E_PIXELSHADER_DATA      "PixelShaderData"       1 Enable, 0 Disable/Default
//  E_VERTEXSHADER_DATA     "VertexShaderData"      1 Enable, 0 Disable/Default
//  E_SHADER_DUMP           "ShaderDump"            1 Enable, 0 Disable/Default
//  E_VIDMEM_DATA           "VidMemData"            1 Enable, 0 Disable/Default
//  E_PIXELSHADER_DUMP      "PixelShaderDump"       1 Enable, 0 Disable/Default
//
//Usage - Debug Level, Message / format string and Varible argument list
//Example:
//  HSLDPF( E_INFO_MESSAGE, "We are being asked to fill a ZBuffer" );
//  HSLDPF( E_DATA_DUMP, "Fill value = %08x", dvFillDepth );
//
//  HSLASSERT( int Expression ); Use in the place of the assert standard run
//  time library function. Evaluates an expression and when the result is
//  FALSE, prints the file and line number of the failed asseration.
//
//Example:
//  HSLASSERT( ( lpD3DDev->SurfHandleList[i].dwNumATITexCntxAllocated == 0 ) );
//  See also: Direct Draw and D3D HAL InterfaceRev 0.4

typedef enum
{
    E_ASSERTION             = 0,
    E_HAL_ENTRY_EXIT        = 1,
    E_GENERAL_ENTRY_EXIT    = 2,
    E_INFO_MESSAGE          = 3,
    E_ERROR_MESSAGE         = 4,
    E_DATA_DUMP             = 5,
    E_DEBUG1                = 6,
    E_DEBUG2                = 7,
    E_BLT_DATA              = 8,
    E_SURFACE_DATA          = 9,
    E_STATE_DATA            = 10,
    E_PIXELSHADER_DATA      = 11,
    E_VERTEXSHADER_DATA     = 12,
    E_SHADER_DUMP           = 13,
    E_VIDMEM_DATA           = 14,
    E_PIXELSHADER_DUMP      = 15,
    E_LDDM_CREATE_RES       = 16,
    E_LDDM_LOCK             = 17,
    E_DEBUGLEVEL_TOO_BIG    = 18
} EDDHSLDEBUGLEVEL;


#ifndef   _X86_
#if defined (i386) || defined (_i386_)
#define _X86_
#endif /* i386 || _i386_ */
#endif /* _X86_ */


#if defined  (_X86_) && !defined (_WIN64)
#define HSL_STOP_IN_DEBUGGER { __asm int 3 }
#define HSL_NOP              { __asm nop   }
#else  /* _X86_ */
#if DEBUG
#define HSL_STOP_IN_DEBUGGER    DebugBreak()
#else
#define HSL_STOP_IN_DEBUGGER
#endif
#define HSL_NOP
#endif /* _X86_ */

VOID
APIENTRY
vDdHslDebugPrint(
    __in  EDDHSLDEBUGLEVEL eDbgLevel,
    __in  char* pDbgMsg,
    ...
    );

#ifdef DEBUG

    // Master control for HSL Debug output.  If set to false, then no HSL Output
    // will occur even if the corresponding status flag is set in HSLDebugTable.
    // It defaults to TRUE since a function will have to explicitly request it to
    // be disabled.
    extern BOOL bHSLDebugOutputOn;

    #define HSLDPF vDdHslDebugPrint

    #define HSLDPF_ENABLE()  bHSLDebugOutputOn = TRUE;
    #define HSLDPF_DISABLE() bHSLDebugOutputOn = FALSE;

    #if defined(_PREFAST_) || defined(_PREFIX_)
        __declspec(noreturn) void  die(__in  char* pDbgMsg);  // noreturn function

        #define HSLASSERT( exp )  ( void ) ( ( exp ) || \
                ( vDdHslDebugPrint( E_ASSERTION, "Assertion failed: %s (%s:%u)", \
                                    #exp, __FILE__, __LINE__ ), 0 ), die("no return") )
    #else
        #define HSLASSERT( exp )  ( void ) ( ( exp ) || \
                ( vDdHslDebugPrint( E_ASSERTION, "Assertion failed: %s (%s:%u)", \
                                    #exp, __FILE__, __LINE__ ), 0 ) )
    #endif
#else
    #define HSLDPF 1 ? ( void )0 : ( void )

    #define HSLDPF_ENABLE()
    #define HSLDPF_DISABLE()

    #define HSLASSERT( exp ) ( ( void ) 0 )
#endif

#endif //_ATIDDHSL_H

