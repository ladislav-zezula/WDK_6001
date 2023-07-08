// The version of the D3D DLLs loaded through EngLoadImage must always
// be consistent with the version that the display driver expects so
// that we can never leave the system in an unstable state due to 
// mismatched DLLs.  The worst acceptable state is that D3D/DirectDraw
// is disabled.  

// ************** IMPORTANT **************
// THE FOLLOWING DEFINE MUST BE UPDATED IF ANY CHANGE IS DONE IN THIS FILE
// UNLESS THAT CHANGE DOES NOT STOP THE LOADING OF PREVIOUS DLL VERSIONS
// WE EXPOSE THE D3D LOADER API VERSION VIA "PrivateBuild" IN THE VERSION
// INFO SECTION. D3D_LOADER_API_VERION_STR is used inside the ati3ddll.rc 
// file. MAKE SURE TO UPDATE BOTH #defines WHEN UPDATING THE VERSIONS.

#define D3D_LOADER_API_VERSION 4
#define D3D_LOADER_API_VERSION_STR "4 \0"


// ************** END IMPORTANT **************

typedef LPVOID (APIENTRY *PPDISP4DDGETDXOBJ) (LPVOID pDevObj);

typedef DWORD (APIENTRY *PDDISP4DDESCAPE) (LPVOID pDevInfo, DWORD dwEscape,
                                           DWORD dwInputSize, LPVOID pInput,
                                           DWORD dwOutputSize, LPVOID pOutput);

typedef void (APIENTRY *PVDISP4DDENABLEEXCLUSIVEMODE) (LPVOID pDevObj);

typedef void (APIENTRY *PVDISP4DDDISABLEEXCLUSIVEMODE) (LPVOID pDevObj);


#ifdef RADEONDLL
typedef int (APIENTRY *LPQSINIT) (void* pFunctions, DWORD QS_VERSION);
typedef int (APIENTRY *LPQSINIT2) (DWORD_PTR hDevice, void* pFunctions, DWORD QS_VERSION);
#else
typedef QS_RETURNCODE (__stdcall *LPQSINIT) (QS_FUNC *pFunctions, DWORD QS_VERSION);
typedef QS_RETURNCODE (__stdcall *LPQSINIT2) (QS_HDEVICE hDevice, QS_FUNC2 *pFunctions, DWORD QS_VERSION);
#endif

typedef LPVOID (APIENTRY *PPDISP4DDGETPRIMARYSURFACESTART) (LPVOID pDevObj);

#ifdef RADEONDLL

typedef void (APIENTRY *PVDISP4DDGETMEMINFO) (LPVOID pDevPtr, 
                                              int eHeapType,
                                              LPVOID lpMemInfo);

typedef void (APIENTRY *PVDISP4DDALLOCVIDMEM) (LPVOID pDevObj, 
                                               int eHeapType,
                                               DWORD dwCaps,
                                               DWORD dwFlags,
                                               DWORD dwAlignedPitch, 
                                               DWORD dwMemoryNeeded, 
                                               DWORD dwOffsetAlign,
                                               LPVOID *pVidMemData); 

typedef void (APIENTRY *PVDISP4DDFREEVIDMEM) (LPVOID pDevObj, 
                                              int eHeapType, 
                                              LPVOID *pVidMemData);
#else

typedef void (APIENTRY *PVDISP4DDGETMEMINFO) (LPVOID pDevPtr, 
                                              enum EDDHSLVIDMEMHEAP eHeapType,
                                              LPDISP4DD_MEMINFO lpMemInfo);

typedef void (APIENTRY *PVDISP4DDALLOCVIDMEM) (LPVOID pDevObj, 
                                               enum EDDHSLVIDMEMHEAP eHeapType,
                                               DWORD dwCaps,
                                               DWORD dwFlags,
                                               DWORD dwAlignedPitch, 
                                               DWORD dwMemoryNeeded, 
                                               DWORD dwOffsetAlign,
                                               DISP4DDVIDMEMDATA *pVidMemData); 

typedef void (APIENTRY *PVDISP4DDFREEVIDMEM) (LPVOID pDevObj, 
                                              enum EDDHSLVIDMEMHEAP eHeapType, 
                                              DISP4DDVIDMEMDATA *pVidMemData);
#endif

typedef PVOID (APIENTRY *PENGALLOCMEM) (IN ULONG  Flags,IN ULONG  MemSize,IN ULONG  Tag);
typedef VOID (APIENTRY *PENGFREEMEM) (IN PVOID Mem);
typedef VOID (APIENTRY *PENGDEBUGPRINT) (IN PCHAR StandardPrefix,IN PCHAR DebugMessage,IN va_list ap);

typedef PVOID (APIENTRY *PPDISP4DDALLOCPAGEABLEMEM) (PVOID pDev, IN ULONG  MemSize);
typedef BOOL (APIENTRY *PBDISP4DDFREEPAGEABLEMEM) (PVOID pDev, IN PVOID Mem);

//DVD
//this is needed for old DVD API M2AM
typedef LPVOID (APIENTRY *PDDHILMAPSHAREMEMORY) (LPVOID pDevInfo, LPVOID pLocation, DWORD dwSize);
typedef QS_RETURNCODE (__stdcall *LPQSINITDVD) (QS_FUNC *pFunctions, DWORD QS_VERSION);
//end of DVD

typedef LPVOID (APIENTRY *PPDDHSLQUERYDEVICEOBJECT) (LPVOID pDevObj, int eDevType);
typedef BOOL (*PBDDHSLQUERYCIINFO) (LPVOID lpDXObj, int eCIInfoType, LPVOID pCIInfo);

//Function implemented in display driver and used by overlay
typedef DWORD (_stdcall *PDISP4DDGETPDEVFLAGS) (LPVOID pDevObj);

//VPE
typedef DWORD_PTR (__stdcall *PDWPVPEHSLGETDRIVERHANDLEFROMPDEV)( LPVOID ppDev );
typedef PVOID (__stdcall *PPVVPEHSLGETVIDEOPORTHANDLEFROMPDEV)( LPVOID ppDev );
typedef VOID (__stdcall *PVVPEHSLSETVIDEOPORTHANDLETOPDEV)( LPVOID ppDev , PVOID pCVideoPort);
typedef DWORD_PTR (__stdcall *PDWPVPEHSLGETAPERTUREBASEFROMPDEV)( LPVOID ppDev );

typedef ULONG (_stdcall *PULDRVESCAPE)(LPVOID pso, ULONG iEsc, ULONG cjIn, PVOID pvIn, ULONG cjOut, PVOID pvOut);

// BEGIN TEMP DX UDA CHANGE until QS2 interface is implemented.
typedef CMM_RETURNCODE (__stdcall *PCMMREGISTERCLIENT)(CMM_HDEVICE hDevice,
        CMM_CLIENT_DESCRIPTOR *pInput, CMM_CLIENT_INFO *pOutput);

typedef CMM_RETURNCODE (__stdcall *PCMMUNREGISTERCLIENT)(CMM_HDEVICE hDevice,
        CMM_CLIENT_INFO *pInput);

typedef CMM_RETURNCODE (__stdcall *PCMMALLOCSURFACE)(CMM_HDEVICE hDevice,
        CMM_SURF_DESCRIPTOR *pInput, CMM_SURF_INFO *pOutput);

typedef CMM_RETURNCODE (__stdcall *PCMMFREESURFACE)(CMM_HDEVICE hDevice,
        CMM_FREESURF_INPUT *pInput);

typedef CMM_RETURNCODE (__stdcall *PCMMQUERYSURFACEINFO)(CMM_HDEVICE hDevice,
        CMM_SURF_REQUEST *pInput, CMM_SURF_INFO *pOutput);

typedef CMM_RETURNCODE (__stdcall *PCMMALLOCCACHE)(CMM_HDEVICE hDevice,
        CMM_SURF_REQUEST *pInput, CMM_SURF_INFO *pOutput);

typedef CMM_RETURNCODE (__stdcall *PCMMFREECACHE)(CMM_HDEVICE hDevice,
        CMM_SURF_REQUEST *pInput);

typedef CMM_RETURNCODE (__stdcall *PCMMRECOVERSURFACE)(CMM_HDEVICE hDevice,
        CMM_SURF_REQUEST *pInput, CMM_SURF_INFO *pOutput);

typedef CMM_RETURNCODE (__stdcall *PCMMSETAPERTURE)(CMM_HDEVICE hDevice,
        CMM_APERTURE_DESCRIPTOR *pInput);

typedef CMM_RETURNCODE (__stdcall *PCMMFREEAPERTURE)(CMM_HDEVICE hDevice,
        CMM_APERTURE_DESCRIPTOR *pInput);

typedef CMM_RETURNCODE (__stdcall *PCMMGETGENERALINFO)(CMM_HDEVICE hDevice,
        CMM_GENERAL_INFO *pOutput);

// END TEMP DX UDA CHANGE until QS2 interface is implemented.

typedef VOID (APIENTRY *PDISP4DDDRIVERENTRY) (LPVOID pDevObj);
typedef VOID (APIENTRY *PDISP4DDDRIVEREXIT) (LPVOID pDevObj);


typedef struct
{
/*----------- Attention! All new functions are to be added to the end of the structure ------------------------*/    
    PPDISP4DDGETDXOBJ ppDISP4DDGetDXObj;                                     //[0]
    PDDISP4DDESCAPE pdDISP4DDEscape;                                         //[1]
    PVDISP4DDENABLEEXCLUSIVEMODE pvDISP4DDEnableExclusiveMode;               //[2]
    PVDISP4DDDISABLEEXCLUSIVEMODE pvDISP4DDDisableExclusiveMode;             //[3]
    LPQSINIT pQSInit;                                                        //[4] 
    LPQSINIT2 pQSInit2;                                                      //[5]
    PENGALLOCMEM pEngAllocMem;                                               //[5]
    PENGFREEMEM pEngFreeMem;                                                 //[6]
    PENGDEBUGPRINT pEngDebugPrint;                                           //[7]
    PPDISP4DDGETPRIMARYSURFACESTART ppDISP4DDGetPrimarySurfaceStart;         //[8]
    PVDISP4DDGETMEMINFO pvDISP4DDGetMemInfo;                                 //[9]
    PVDISP4DDALLOCVIDMEM pvDISP4DDAllocVidMem;                               //[10]
    PVDISP4DDFREEVIDMEM pvDISP4DDFreeVidMem;                                 //[12]
    PDISP4DDGETPDEVFLAGS pdDISP4DDGetPdevFlags;                              //[13]
    PPDISP4DDALLOCPAGEABLEMEM ppDISP4DDAllocPageableMem;                     //[14]
    PBDISP4DDFREEPAGEABLEMEM pbDISP4DDFreePageableMem;                       //[15]
    PDWPVPEHSLGETDRIVERHANDLEFROMPDEV pdwpVPEHSLGetDriverHandleFromPDEV;     //[16]
    PPVVPEHSLGETVIDEOPORTHANDLEFROMPDEV ppvVPEHSLGetVideoPortHandleFromPDEV; //[17]
    PVVPEHSLSETVIDEOPORTHANDLETOPDEV pvVPEHSLSetVideoPortHandleToPDEV;       //[18]
    PDWPVPEHSLGETAPERTUREBASEFROMPDEV pdwpVPEHSLGetApertureBaseFromPDEV;     //[19]
    PULDRVESCAPE pulDrvEscape;                                               //[20]
    PDDHILMAPSHAREMEMORY pDdHILMapShareMemory;                               //[21]
    LPQSINITDVD pQSInitDVD;                                                  //[22]
// BEGIN TEMP DX UDA CHANGE until QS2 interface is implemented.
    PCMMREGISTERCLIENT pCMMRegisterClient;
    PCMMUNREGISTERCLIENT pCMMUnregisterClient;
    PCMMALLOCSURFACE pCMMAllocSurface;
    PCMMFREESURFACE pCMMFreeSurface;
    PCMMQUERYSURFACEINFO pCMMQuerySurfaceInfo;
    PCMMALLOCCACHE pCMMAllocCache;
    PCMMFREECACHE pCMMFreeCache;
    PCMMRECOVERSURFACE pCMMRecoverSurface;
    PCMMSETAPERTURE pCMMSetAperture;
    PCMMFREEAPERTURE pCMMFreeAperture;
    PCMMGETGENERALINFO pCMMGetGeneralInfo;
// END TEMP DX UDA CHANGE until QS2 interface is implemented.
    PDISP4DDDRIVERENTRY pvDISP4DDDriverEntry;
    PDISP4DDDRIVEREXIT pvDISP4DDDriverExit;

/*----------- Attention! All new functions are to be added to the end of the structure ------------------------*/
} DRIVERCALLS;

typedef struct
{
    DWORD dwDCSize;
    DRIVERCALLS DriverCalls;
} DRIVERCALLS_EX;



