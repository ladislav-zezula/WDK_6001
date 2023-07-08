

//
//  $Workfile: d3dcntx.h $
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


#ifndef         D3DCNTX_H_

#define         D3DCNTX_H_

// external includes

#include "atidxinc.h"

// CHAPLIN: The #ifdef DEFAULT_PITCH logic that was here
// CHAPLIN: in Rage 6, has been moved to inside of radeon.h
#include "radeon.h"
#include "radeonBFFunc.h"

// private D3D includes

#include "atid3ddefs.h"
#include "d3dtext.h"
#include "pm4func.h"
#include "atidxhsl.h"
#include "atidispdd.h"
#include "blt.h"

#include "tcl_commands.h"
#include "pixelshader.h"

#include "atilist.h"
#include "atidxutils.h"
#include "writetexture.h"  // used for TxBlendRec structure

// Definitions
#define TX_NOTASSIGNED 0xFFFFFFFF
#define ZFUNC_DONT_CARE 0

//This is for (0,0) texture coodinates filtering problem.
#define TEXCOORDSDELTA   0.0001f

////////////////////  Microsoft code //////////////////////////////////////////
//
//
#define IS_OVERRIDE(type)       ((DWORD)(type) > D3DSTATE_OVERRIDE_BIAS)
#define GET_OVERRIDE(type)      ((DWORD)(type) - D3DSTATE_OVERRIDE_BIAS)

#define STATESET_MASK(set, state)       \
        (set).bits[((state) - 1) >> DWORD_SHIFT]

#define STATESET_BIT(state)     (1 << (((state) - 1) & (DWORD_BITS - 1)))

#define STATESET_ISSET(set, state) \
        STATESET_MASK(set, state) & STATESET_BIT(state)

#define STATESET_SET(set, state) \
        STATESET_MASK(set, state) |= STATESET_BIT(state)

#define STATESET_CLEAR(set, state) \
        STATESET_MASK(set, state) &= ~STATESET_BIT(state)

#define STATESET_INIT(set)      memset(&(set), 0, sizeof(set))
//////////////////// End of Microsoft code ////////////////////////////////////

typedef        struct
{
    DWORD               bits[MAX_STATE >> DWORD_SHIFT];
} RG4D3DSTATESET;

// Structure to handle unsupported hardware texture filters.
typedef struct _D3DTXFILTER
{
    DWORD dwMinFilter;
    DWORD dwMipFilter;
    DWORD dwMaxAnisotropy;
} D3DTXFILTER;


typedef regPP_TXFILTER_0 regPP_TXFILTER;

typedef LPD3DHAL_DP2COMMAND(*PRENDTRI)(struct _ATID3DCNTX *pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                                       struct _D3DTLVERTEX* lpVertices, DWORD dwFVFSize,
                                       DWORD dwFVFType, DWORD dwStampCount,
                                       DWORD dwVertexNum );

typedef BOOL(*PVALIDATETRI)(LPD3DHAL_DP2COMMAND lpIns, DWORD dwVertexLength);

typedef HRESULT (*PFN_DP2SETRENDERSTATE)(struct _ATID3DCNTX *pCtxt, LPD3DHAL_DP2COMMAND lpRenderStates,
                                         LPDWORD lpStateMirror);

typedef HRESULT (*PFN_DP2SETSTATES)(struct _ATID3DCNTX *pCtxt, LPD3DHAL_DP2COMMAND *lppCmd);

typedef struct STATESETFUNCTIONTABLE
{
    DWORD                       dwSize;                 // size of struct
    PFN_DP2SETRENDERSTATE pfnDp2SetRenderStates;
    PFN_DP2SETSTATES pfnDp2TextureStageState;
    PFN_DP2SETSTATES pfnDp2SetViewport;
    PFN_DP2SETSTATES pfnDp2SetWRange;
    PFN_DP2SETSTATES pfnDp2SetMaterial;
    PFN_DP2SETSTATES pfnDp2SetZRange;
    PFN_DP2SETSTATES pfnDp2SetLight;
    PFN_DP2SETSTATES pfnDp2CreateLight;
    PFN_DP2SETSTATES pfnDp2SetTransform;
    PFN_DP2SETSTATES pfnDp2SetClipPlane;
    PFN_DP2SETSTATES pfnDp2SetVertexShader;
    PFN_DP2SETSTATES pfnDp2SetVertexShaderConst;
#if (DIRECT3D_VERSION >= 0x0900)
    PFN_DP2SETSTATES pfnDp2SetVertexShaderDecl;
    PFN_DP2SETSTATES pfnDp2SetVertexShaderFunc;
    PFN_DP2SETSTATES pfnDp2SetVertexShaderConstB;
    PFN_DP2SETSTATES pfnDp2SetVertexShaderConstI;
    PFN_DP2SETSTATES pfnDp2SetScissorRect;
#endif
    PFN_DP2SETSTATES pfnDp2SetStreamSource;
    PFN_DP2SETSTATES pfnDp2SetIndices;
    PFN_DP2SETSTATES pfnDp2SetPixelShader;
    PFN_DP2SETSTATES pfnDp2SetPixelShaderConst;

    PFN_DP2SETSTATES pfnDp2MultiplyTransform;

} STATESETFUNCTIONTABLE, *LPSTATESETFUNCTIONTABLE;

typedef VOID (*PDX8RENDTRI)(struct _ATID3DCNTX *pCtxt,
                            DWORD dwPrimCount, D3DPRIMITIVETYPE ePrimType,
                            DWORD dwStampCount);

typedef VOID (*PDX8RENDIDXTRI)(struct _ATID3DCNTX *pCtxt,
                               DWORD dwIndexByteOffset, DWORD dwPrimCount,
                               D3DPRIMITIVETYPE ePrimType, DWORD dwStampCount);

typedef VOID (*PDX8RENDPS)(struct _ATID3DCNTX *pCtxt, DWORD dwNumPrimitives,
                           DWORD dwStampCount);

typedef VOID (*PDX8RENDIDXPS)(struct _ATID3DCNTX *pCtxt, DWORD dwNumPrimitives,
                              DWORD dwIndexByteOffset, DWORD dwStampCount);


//Defines used in the handeling of Pixel Shader Constants.
#define PS_MAX_CONSTANTS  8
#define PS_NO_CONSTANT    0xFFFFFFFF //Shader Stage is not using a Const. Reg

//Indicate which ATID3DCNTX pixelShaderInfo array index stores the data for the
//legacy texture stages.
#define PS_LEGACY_INDEX 0

//Enhanced Texture Arguments to support pixel shaders.  The purpose of these
//arguments is to allow the HW Blenders to read from and write to any Texture
//Line.  The assigned values were chosen so they wouldn't conflict with any of
//the Microsoft Dx8 Texture Argument constants (including the Replicate Alpha
//and Compliment modifers).
#define D3DTA_ATI_MASK      0x80000000
#define D3DTA_ATI_ARGMASK   0x8000f000
#define D3DTA_ATI_T0        0x80001000
#define D3DTA_ATI_T1        0x80002000
#define D3DTA_ATI_T2        0x80003000
#define D3DTA_ATI_NOOUTPUT  0x80004000
#define D3DTA_ATI_BLACK     0x80005000

//Special Pixel Shader Operations
typedef enum _PSOPS {NO_PSOP, MAD_SIGNED, MULTIPLY_SUBTRACT} PSOPS;

//Special Pixel Shader Scale Values
typedef enum _PSSCALES {X1, X2, X4} PSSCALES;

//
//All the texture stage info needed to describe a processed pixel shader.
//
typedef struct _PIXELSHADERSTATES
{
    //Color Args
    DWORD dwColorOp;
    DWORD dwColorArg0;
    DWORD dwColorArg1;
    DWORD dwColorArg2;

    PSOPS dwSpecialColorOp;
    PSSCALES dwSpecialColorScale;

    //Alpha Args
    DWORD dwAlphaOp;
    DWORD dwAlphaArg0;
    DWORD dwAlphaArg1;
    DWORD dwAlphaArg2;

    PSOPS dwSpecialAlphaOp;
    PSSCALES dwSpecialAlphaScale;

    //Result Arg
    DWORD dwResultArg;

    //Constant register used by stage.
    DWORD dwConstIndex;

}PIXELSHADERSTATES, *LPPIXELSHADERSTATES;

typedef struct _PIXELSHADERINFO
{
    PIXELSHADERSTATES states[MAX_TEXSTAGE];

    //Store constants Def'ed by shader program
    PSRGBACONSTANT PSHWConstRegs[PS_MAX_CONSTANTS];
    BOOL  bIsConstRegValid[PS_MAX_CONSTANTS];

    DWORD dwSpecularEnable;
    DWORD bumpping_d3dstage;
    DWORD bumpped_d3dstage;

    DWORD dwShaderBumppedStage;

    BOOL  bPixelShaderIsValid;

}PIXELSHADERINFO, *LPPIXELSHADERINFO;

typedef struct _TEXSTAGE
{
//  DWORD       dwStatus;
    DWORD       dwTexUnit;   // texture unit used in current stage, it's initialized to ATI_MAX_NUM_TEX_UNITS(3).

    //Need to make sure we initialize this to the right size....
    DWORD       dwState[MAX_TSS];

} TEXSTAGE, *PTEXSTAGE, FAR *LPTEXSTAGE;

typedef struct _TSS
{
//  DWORD       dwMaxTexStages;         // # of supported texture stages
//  DWORD       dwActiveStages;         // # of currently active stages
//  DWORD       dwCurrentStage;         // current stage
    TEXSTAGE    TexStageList[MAX_TEXSTAGE];     // states per stage

  DWORD     dwWrap[MAX_TEXSTAGE];   // wrap flags

#if(DIRECT3D_VERSION >= 0x0900)
    BOOL  bLineAAEnabled;
#endif


}TEXTURESTAGEINFO, *LPTEXTURESTAGEINFO;

#ifndef FSAA_OPTIONS

#define MULTISAMPLE_1_SAMPLE        1
#define MULTISAMPLE_BIT(NumSamples) (1 << (NumSamples - 1))

#define FSAA_OPTIONS

    typedef union _ANTIALIAS_REGISTRY_ENTRY
    {
        struct
        {
            unsigned int EnableState          : 3;
            unsigned int MSMaskEnabled        : 1;
            unsigned int JTDisabled           : 1;
            unsigned int EnableFCC            : 1;
            unsigned int EnableBlendFiltering : 1;
            unsigned int DisableFallBackMode  : 1;
            unsigned int UseJTRegValues       : 1;
   //the registry key is added for multisample quality level.
   //when EnablePerfMode = 1, the performance AA mode is counted
   //for quality level, otherwise only quality mode is counted.
#if(DIRECT3D_VERSION >= 0x0900)
            unsigned int EnablePerfMode       : 1;
#endif //#if(DIRECT3D_VERSION >= 0x0900)

        } bf;

        unsigned int u32All;

    } ANTIALIAS_REGISTRY_ENTRY;

    enum FSAA_OPTIONS
    {
        FSAA_DISABLE        = 0,
        FSAA_APPCONTROLLED  = 1,
        FSAA_FORCEON        = 2
    };

#endif

#define NUM_SUPPORTED_AAMODES 7

typedef struct _ANTIALIAS_SETTINGS
{
    float xRatio;
    float yRatio;
    float PSScale;
    DWORD dwJitterReg1;
    DWORD dwJitterReg2;
} ANTIALIAS_SETTINGS;

#define JITTERTBL_WIDTH                 4
#define JITTERTBL_HEIGHT                4
#define JITTERTBL_WRITESAMPLE           9
#define JITTERTBL_DONOT_WRITESAMPLE     8
#define JITTERTBL_WRITEALLSAMPLES       0x99999999
#define AAMEMORY_BANKING_LIMIT          ((1 << 20) * 12)

typedef union _ANTIALIAS_FLAGS
{
    struct
    {
        unsigned int EnableState       : 3; //0-2
        unsigned int MSMaskEnabled     : 1; //3
        unsigned int JTEnabled         : 1; //4
        unsigned int DisableFCC        : 1; //5
        unsigned int Enabled           : 1; //6
        unsigned int BltToAASurface    : 1; //7
        unsigned int FullZClear        : 1; //8
        unsigned int MSMaskUsed        : 1; //9
        unsigned int BlendFiltering    : 1; //10
        unsigned int FallBackMode      : 1; //11
        unsigned int AARTSurfDirty     : 1; //12
        unsigned int Cleared1xZBuf     : 1; //13
        unsigned int Full1xRTClr       : 1; //14
        unsigned int                   : 9; //15-23 for flag additions
//AA Halt Conditions, if these bit offsets change then the #define of AAHLT_CONDITIONS_MASK has to change as well.
        unsigned int Modified1xRTCnd   : 1; //24
        unsigned int LockedZBufCnd     : 1; //25
        unsigned int RepeatedBltCnd    : 1; //26
    } bf;

    unsigned int u32All;

} ANTIALIAS_FLAGS;

#define AAHLT_CONDITIONS_MASK 0xFF000000

typedef struct _ANTIALIASINFO
{
    ANTIALIAS_FLAGS AAFlags;
    float xRatio;
    float yRatio;
    DWORD dwMSType;
    RECTL rRect;
    DWORD dwBytesPerPixel;
    DWORD dwBytePitch;
    DWORD dwPixelPitch;
    DWORD dwZBytePitch;
    DWORD dwZPixelPitch;
    DWORD dwRenderSize;
    DWORD dwZBufferSize;
    DWORD dwFCCDepthOffset;  
    DWORD dwFCCHeight;       
    regRE_JITTER_TABLE0 ReJitterTable_Reg0;
    regRE_JITTER_TABLE1 ReJitterTable_Reg1;
    DWORD_PTR    dwRTSurfOffset;
    DWORD_PTR    dwZBSurfOffset;
    FLATPTR      lpAlignedRTPtr;
    FLATPTR      lpAlignedZBPtr;
    DDHSLVIDMEMDATA   RTVidMemData;
    DDHSLVIDMEMDATA   ZBVidMemData;
    //Data from last ATIClear
    D3DVALUE dvZClearValue;
    DWORD    dwSClearValue;
    DWORD    dwZSClearFlags;
    DWORD    dwFillColor;
#if (DIRECT3D_VERSION >= 0x0900)
    DWORD    hRendertarget;
#endif //(DIRECT3D_VERSION)
} ANTIALIASINFO, *LPANTIALIASINFO;

typedef enum _ANTIALIAS_CONVERT_FLAGS
{
    AACF_FREEMEMORY          = 1,
    AACF_BLT                 = 2,
    AACF_LEAVE_EXCLUSIVEMODE = 4,
    AACF_IGNORE_ZSTATE       = 8,
} ANTIALIAS_CONVERT_FLAGS;

/*Below is the definition of a Rage5 context.
 *A pointer to this structure is returned by
 *the D3D HAL at when ContextCreate32 callback
 *is invoked!
 */
/*
 *ATID3DContext
 */

typedef struct _STATESET_DATA
{
    LPBYTE  lpDp2Cmd;               //Recorded state commands and their values.
    DWORD   dwDp2CmdSizeTotal;      //Total size of memory allocated for lpDp2Cmd.
    DWORD   dwDp2CmdSizeCurr;       //Size of Current used memory in lpDp2Cmd.
    BOOL    bInBeginBlock;          //True if this block is currently being recorded.
} STATESET_DATA, *LPSTATESET_DATA;

typedef struct _ATISTATESETRECORD
{
    LPSTATESET_DATA lpStateSetList;
    DWORD           dwNumStateSetBlocks;
    DWORD           dwCurrStateSetHandle;
} ATISTATESETRECORD;


//For use with dwDXInterfaceVersion
#define ATI_DX9_INTERFACE   5
#define ATI_DX8_INTERFACE   4
#define ATI_DX7_INTERFACE   3
#define ATI_DX6_INTERFACE   2
#define ATI_DX5_INTERFACE   1
#define ATI_DX3_INTERFACE   0

#define ATI_MAX_NUM_AOS 12

typedef struct _ATIVTXARRAYATTRIBUTES
{
  BYTE count;
  BYTE stride;
} ATIVTXARRAYATTRIBUTES, *LPATIVTXARRAYATTRIBUTES;


typedef struct _ATIVTXARRAY
{
    INT	       dwBaseOffset;	  // Base address of the Array of Structures.
    DWORD      dwStride;         // Number of dwords from one array element to the next.
    DWORD      dwCount;          // Number of dwords in this structure.

    DWORD      dwFlags;             // Used to hold specific info about vertex array
    struct _ATIVERTEXBUFFER *pVb;   // Attached Vertex Buffer.

    LPINT	  pdwBaseVirtual;

    LPINT	  pAddressRegister;
    LPATIVTXARRAYATTRIBUTES pAttributeRegister;

  // scratch variables used in DrawPrim routines for user/sys mem VBs.
    LPDWORD    lpdwCurrent;
    LPDWORD    lpdwStart;

} ATIVTXARRAY, *LPATIVTXARRAY;



#define VS_NUM_PSC_ENTRIES          16
#define VS_MAX_NUM_STREAM_ELEMENTS  17
#define VS_MAX_NUM_STREAMS          ATI_MAX_NUM_AOS
#define VS_MAX_NUM_ARRAYS           ATI_MAX_NUM_AOS
/*
 * ATID3DSTREAM structure contains all the ATi specific data
 * that is relevant to each D3D vertex stream.
*/

typedef struct _ATID3DSTREAM
{
  //DWORD      dwFlags;                 // Used to hold specific info about D3D stream.
    DWORD      dwStride;                // Vertex stride.
#if (DIRECT3D_VERSION >= 0x0900)
    DWORD      dwOffsetInBytes;         // Stream Offset - the first vertex size in bytes
#endif // (DIRECT3D_VERSION >= 0x0900)
    struct _ATIVERTEXBUFFER *pVb;       // Attached Vertex Buffer.

} ATID3DSTREAM, *LPATID3DSTREAM;


// DXCONSTSTORE flags
#define VS_MAX_NUM_PARTIAL_CONST_UPDATES    10

#define VS_CONST_STORE_DIRTY_0          0x00000001
#define VS_CONST_STORE_DIRTY_1          0x00000002
#define VS_CONST_STORE_DIRTY_2          0x00000004
#define VS_CONST_STORE_DIRTY_3          0x00000008
#define VS_CONST_STORE_DIRTY_4          0x00000010
#define VS_CONST_STORE_DIRTY_5          0x00000020
#define VS_CONST_STORE_DIRTY_6          0x00000040
#define VS_CONST_STORE_DIRTY_7          0x00000080
#define VS_CONST_STORE_DIRTY_8          0x00000100
#define VS_CONST_STORE_DIRTY_9          0x00000200
#define VS_CONST_STORE_DIRTY_MASK       0x000003ff

typedef struct _ATIVTXSHADERMEMALLOC
{
    DWORD           dwAllocFlags;
    DDHSLVIDMEMDATA pCodeData;
    ULONG_PTR       QS_HInList;       // Handle returned by QS
    DWORD           QS_ListSize;      // Size of list as allocated
    ULONG_PTR       QS_ListOffset;    // Offset from the base of the GART
    LPVOID          pData;            // Copy of the virtual address

    // dwPVSPendingCB_ID means that this code/const is used (being loaded)
    // by a CB with ID = dwPVSPendingCB_ID. This CB is either not submitted
    // or it is submitted but we don't know if its time is elasped.
    DWORD           dwPVSPendingCB_ID;
    DWORD           dwhContextID;

} ATIVTXSHADERMEMALLOC, *LPATIVTXSHADERMEMALLOC;

// dirty information for VS const data
typedef struct _DXCONSTSTORE
{
  DWORD        dwFlags;               // Contain dirty bit info.
  DWORD        dwRegister;            // Const register to start copying
  DWORD        dwMaxConstUsed;        // This is to limit the number of vectors we send for
                                      // shaders that use the address register
  DWORD        dwMinRegWritePending[10];  // used to determine the range to update
  DWORD        dwMaxRegWritePending[10];  //

  LPATIVECTOR lpVtxShaderConstStore;
  ATIVTXSHADERMEMALLOC pvsGlobalMemAlloc; // Structure to hold state memory info

} DXCONSTSTORE, *LPDXCONSTSTORE;

typedef enum _ARRANGEVTXELEMENT_FLAGS
{
    ARRANGE_NO          = 0,
    ARRANGE_ONLY        = 1,
    ARRANGE_CHANGESIZE  = 2,
    ARRANGE_SKIP_PSIZE  = 4,
} ARRANGEVTXELEMENT_FLAGS;

// Asynchronous Query Operations
#if (DIRECT3D_VERSION >= 0x0900)
typedef struct _ATIQUERY
{
    BOOL                    bResultReady;
    BOOL                    bQueryIssued;
    DWORD                   dwResultSize;
    D3DHAL_DP2CREATEQUERY   dp2Query;
    DDHSLVIDMEMDATA         occQueryVidMem;
    union                                  // Union for query processing
    {
        DWORD               dwRenderID;    // D3DQUERYTYPE_EVENT
    };
    union                                  // Union for result of query
    {
        DWORD               dwResult;      // Place holder for each type
        BOOL                bRenderIDDone; // D3DQUERYTYPE_EVENT
        volatile DWORD      dwOcclusion;   // D3DQUERYTYPE_OCCLUSION
    };

}ATIQUERY, *LPATIQUERY;
#endif // (DIRECT3D_VERSION >= 0x0900)

#define ATID3DCNTX_FLAG_DRAWBEGIN        0x00000001
#define ATID3DCNTX_FLAG_DRAWENABLE       0x00000002
#define ATID3DCNTX_FLAG_INTVBINUSE       0x00000004
#define ATID3DCNTX_FLAG_NUMVTXARRCHANGED 0x00000008
#define ATID3DCNTX_FLAG_1ST_RT_SET       0x00000010

#if defined(KMD) || defined(UMD)
#include "r2d3dddi.h"
#endif

typedef struct _DP2HISTORYBUF
{
    PVOID   pvBase;
    DWORD   dwSize;
    DWORD   dwCurOffset;
    DWORD   dwWrapCo;
    DWORD   dwWrapOffset;           //Offset last time we wrapped, so you know what is valid data
}DP2HISTORYBUF, *PDP2HISTORYBUF;

typedef struct _ATI_VXT_STATE
{
    regSE_VTX_NUM_ARRAYS     SeVtxNumArrays_reg;    // 0x830
    regSE_VTX_AOS_ATTR01     SeVtxAOSAttr01_reg;    // 0x831
    regSE_VTX_AOS_ADDR0      SeVtxAOSAddr0_reg;     // 0x832
    regSE_VTX_AOS_ADDR1      SeVtxAOSAddr1_reg;     // 0x833
    regSE_VTX_AOS_ATTR23     SeVtxAOSAttr23_reg;    // 0x834
    regSE_VTX_AOS_ADDR2      SeVtxAOSAddr2_reg;     // 0x835
    regSE_VTX_AOS_ADDR3      SeVtxAOSAddr3_reg;     // 0x836
    regSE_VTX_AOS_ATTR45     SeVtxAOSAttr45_reg;    // 0x837
    regSE_VTX_AOS_ADDR4      SeVtxAOSAddr4_reg;     // 0x838
    regSE_VTX_AOS_ADDR5      SeVtxAOSAddr5_reg;     // 0x839
    regSE_VTX_AOS_ATTR67     SeVtxAOSAttr67_reg;    // 0x83A
    regSE_VTX_AOS_ADDR6      SeVtxAOSAddr6_reg;     // 0x83B
    regSE_VTX_AOS_ADDR7      SeVtxAOSAddr7_reg;     // 0x83C
    regSE_VTX_AOS_ATTR89     SeVtxAOSAttr89_reg;    // 0x83D
    regSE_VTX_AOS_ADDR8      SeVtxAOSAddr8_reg;     // 0x83E
    regSE_VTX_AOS_ADDR9      SeVtxAOSAddr9_reg;     // 0x83F
    regSE_VTX_AOS_ATTR1011   SeVtxAOSAttr1011_reg;  // 0x840
    regSE_VTX_AOS_ADDR10     SeVtxAOSAddr10_reg;    // 0x841
    regSE_VTX_AOS_ADDR11     SeVtxAOSAddr11_reg;    // 0x842

    LPATIVERTEXBUFFER        pStreams[VS_MAX_NUM_STREAMS];
}ATI_VXT_STATE, *PATI_VXT_STATE;

typedef     struct _ATID3DCNTX
{
    DWORD                    dwSize;
    DWORD                    dwPID;                  //Process ID;
    ULONG_PTR                dwDXInterfaceVersion;   // stores copy of cntx, this is always set to DX9 as driver alwasy get called with DX9 data streams.  Will be removed Bug 991052
    DWORD                    dwDxAppVersion;        // This lets the driver know which Dx runtime the app is using 
    DWORD                    dwCntxFlags;

#ifdef DEBUG
    DP2HISTORYBUF            sDP2HistoryBuf;
#endif /* #ifdef DEBUG */

    ATI_VXT_STATE            sVxtPrevState;          //Used to optimise Vtx reg updates

    BOOL bForRuntimeBugPreIsUSERMEMVERTICES;

    //Pixel Shader Data
    ATILIST alPixelShaderInfo;
    DWORD   dwPixelShaderActive; // handle of the active shader
    PSRGBACONSTANT  PSHWConsts[PS_MAX_CONSTANTS];  // Global pixel shader constant value

    TEXTURE_CHARACTERISTICS textureChars;

    BOOL bR200TxZeroWorkaroundNeeded;  
    DWORD dwRecalcTexStages;            // enum for dirty D3D TSS

    RG4D3DSTATESET           overrides;
    TEXTURESTAGEINFO         texStageInfo;
    DWORD                    ATIStateList[MAX_RENDER_STATES];

    //Render Context
    DWORD                    dwCntxDirtyMask;
    DWORD                    dwTexDirtyBits;
    BOOL                     bTamDebug3Bit;  // Flag to determine if PP_TAM_DEBUG3Bit need to be reset
                                             // Specific to R200
    BOOL                     bCntxHasLeftExclusiveMode;

    // is TCL or HAL responsible for programming Texture coord routing ?
    ETXROUTING_MODE          eTexRouteMode;

    // All register variables must be added between dwRegStart and dwRegEnd.
    DWORD                    dwRegStart;

    regPP_MISC               PpMisc_reg;            //0x0705
    regPP_FOG_COLOR          PpFogColor_reg;        //0x0706
    regRE_SOLID_COLOR        ReSolidColor_reg;      //0x0707

    regRB3D_BLENDCNTL        BlendCntl_reg;         //0x0708
    regRB3D_BLENDCOLOR       BlendColor_reg;        //0x0C86
    regRB3D_ABLENDCNTL       ABlendCntl_reg;        //0x0C87

    // regRB3D_DEPTHCLEARVALUE is loaded to HW in Clear232 after waiting for HW to be
    // idle or in the begining of a 3D indirect buffer. Since Z offset, pitch, Zmask offset,
    // ZStencil clear values don't change often, we may want a flag to load ZStencilCntl_reg.
    regRB3D_DEPTHOFFSET      DepthOffset_reg;       //0x0709
    regRB3D_DEPTHPITCH       DepthPitch_reg;        //0x070A
    regRB3D_ZSTENCILCNTL     ZStencilCntl_reg;      //0x070B
    regRB3D_DEPTHCLEARVALUE  ZStencilClearValue_reg;//0x070C
    regRB3D_ZMASKOFFSET      ZMaskOffset_reg;       //0x070D

    regPP_CNTL               PpCntl_reg;            //0x070E
    regRB3D_CNTL             Cntl_reg;              //0x070F

    regRB3D_COLOROFFSET      ColorOffset_reg;       //0x0710
    regRE_WIDTH_HEIGHT       ReWidthHeight_reg;     //0x0711
    regRB3D_COLORPITCH       ColorPitch_reg;        //0x0712

    regSE_CNTL               SeCntl_reg;            //0x0713

    // CHAPLIN_TODO: Need to make certain that sequential register
    // CHAPLIN_TODO: writes that writes SeCoordFmt for Rage 6
    // CHAPLIN_TODO: doesn't write this same offset for Chaplin
    regRE_CNTL               ReCntl_reg;            //0x0714

    regPP_TXFILTER_0         PpTxFilter0_reg;       //0x0715
    regPP_TXFORMAT_0         PpTxFormat0_reg;       //0x0716
    regPP_TXOFFSET_0         PpTxOffset0_reg;       //0x0717
    // CHAPLIN_TODO: These can be removed once all sequential register
    // CHAPLIN_TODO: writes that wrote these locations have been modified
    // CHAPLIN_TODO: for Chaplin
    DWORD                    dwDummy0x718_reg;      //0x0718
    DWORD                    dwDummy0x719_reg;      //0x0719

    regPP_TFACTOR_0          PpTFactor0_reg;        //0x071A

    regPP_TXFILTER_1         PpTxFilter1_reg;       //0x071B
    regPP_TXFORMAT_1         PpTxFormat1_reg;       //0x071C
    regPP_TXOFFSET_1         PpTxOffset1_reg;       //0x071D
    // CHAPLIN_TODO: These can be removed once all sequential register
    // CHAPLIN_TODO: writes that wrote these locations have been modified
    // CHAPLIN_TODO: for Chaplin
    DWORD                    dwDummy0x71E_reg;      //0x071E
    DWORD                    dwDummy0x71F_reg;      //0x071F

    regPP_TFACTOR_1          PpTFactor1_reg;        //0x0720

    regPP_TXFILTER_2         PpTxFilter2_reg;       //0x0721
    regPP_TXFORMAT_2         PpTxFormat2_reg;       //0x0722
    regPP_TXOFFSET_2         PpTxOffset2_reg;       //0x0723
    DWORD                    dwDummy0x724_reg;      //0x0724
    DWORD                    dwDummy0x725_reg;      //0x0725

    regPP_TFACTOR_2          PpTFactor2_reg;        //0x0726

    regRE_STIPPLE_ADDR       ReStippleAddr_reg;     //0x0732
    regRE_STIPPLE_DATA       ReStippleData_reg;     //0x0733
    regRE_LINE_PATTERN       ReLinePattern_reg;     //0x0734
    regRE_LINE_STATE         ReLineState_reg;       //0x0735

    regRE_SCISSOR_TL_0       ReScissorTL0_reg;      //0x0736
    regRE_SCISSOR_BR_0       ReScissorBR0_reg;      //0x0737
    regRE_SCISSOR_TL_1       ReScissorTL1_reg;      //0x0738
    regRE_SCISSOR_BR_1       ReScissorBR1_reg;      //0x0739
    regRE_SCISSOR_TL_2       ReScissorTL2_reg;      //0x073A
    regRE_SCISSOR_BR_2       ReScissorBR2_reg;      //0x073B

    regPP_TEX_SIZE_0         PpTexSize0_reg;        //0x0741
    union
    {
        regPP_TXPITCH_0          PpTxPitch0_reg;        //0x0742
        regrv250PP_TXPITCH_0     PpTxPitch0_reg_rv250;  //0x0742
    };

    regPP_TEX_SIZE_1         PpTexSize1_reg;        //0x0743
    union
    {
        regPP_TXPITCH_1          PpTxPitch1_reg;        //0x0744
        regrv250PP_TXPITCH_1     PpTxPitch1_reg_rv250;  //0x0744
    };

    regPP_TEX_SIZE_2         PpTexSize2_reg;        //0x0745
    union
    {
        regPP_TXPITCH_2          PpTxPitch2_reg;        //0x0746
        regrv250PP_TXPITCH_2     PpTxPitch2_reg_rv250;  //0x0746
    };

    regPP_CUBIC_FACES_0      PpCubicFaces0_reg;     //0x0749
    regPP_CUBIC_FACES_1      PpCubicFaces1_reg;     //0x074A
    regPP_CUBIC_FACES_2      PpCubicFaces2_reg;     //0x074B

    regRE_HIZOFFSET          HIZOffset_reg;         //0x0998

    regRE_AUX_SCISSOR_CNTL   ReAuxScissorCntl_reg;  //0x09BC //(DIRECT3D_VERSION >= 0x0900) impact

    regRE_JITTER_TABLE0      ReJitterTable_Reg0;    //0x09C0
    regRE_JITTER_TABLE1      ReJitterTable_Reg1;    //0x09C1

    regPP_CUBIC_FACES_3      PpCubicFaces3_reg;     //0x0B1E
    regPP_CUBIC_FACES_4      PpCubicFaces4_reg;     //0x0B26
    regPP_CUBIC_FACES_5      PpCubicFaces5_reg;     //0x0B2E

    regPP_TXFORMAT_X_0       PpTxFormatX0_reg;      //0x0B02
    regPP_TXFORMAT_X_1       PpTxFormatX1_reg;      //0x0B0A
    regPP_TXFORMAT_X_2       PpTxFormatX2_reg;      //0x0B12

    regPP_TXFILTER_3         PpTxFilter3_reg;       //0x0B18
    regPP_TXFORMAT_3         PpTxFormat3_reg;       //0x0B19
    regPP_TXFORMAT_X_3       PpTxFormatX3_reg;      //0x0B1A
    regPP_TEX_SIZE_3         PpTexSize3_reg;        //0x0B1B
    union
    {
        regPP_TXPITCH_3          PpTxPitch3_reg;        //0x0B1C
        regrv250PP_TXPITCH_3     PpTxPitch3_reg_rv250;  //0x0B1C
    };
    regPP_BORDER_COLOR_3     PpBorderColor3_reg;    //0x0B1D

    regPP_TXFILTER_4         PpTxFilter4_reg;       //0x0B20
    regPP_TXFORMAT_4         PpTxFormat4_reg;       //0x0B21
    regPP_TXFORMAT_X_4       PpTxFormatX4_reg;      //0x0B22
    regPP_TEX_SIZE_4         PpTexSize4_reg;        //0x0B23
    union
    {
        regPP_TXPITCH_4          PpTxPitch4_reg;        //0x0B24
        regrv250PP_TXPITCH_4     PpTxPitch4_reg_rv250;  //0x0B24
    };
    regPP_BORDER_COLOR_4     PpBorderColor4_reg;    //0x0B25

    regPP_TXFILTER_5         PpTxFilter5_reg;       //0x0B28
    regPP_TXFORMAT_5         PpTxFormat5_reg;       //0x0B29
    regPP_TXFORMAT_X_5       PpTxFormatX5_reg;      //0x0B2A
    regPP_TEX_SIZE_5         PpTexSize5_reg;        //0x0B2B
    union
    {
        regPP_TXPITCH_5          PpTxPitch5_reg;        //0x0B2C
        regrv250PP_TXPITCH_5     PpTxPitch5_reg_rv250;  //0x0B2C
    };
    regPP_BORDER_COLOR_5     PpBorderColor5_reg;    //0x0B2D

    regPP_TXOFFSET_3         PpTxOffset3_reg;       //0x0B52
    regPP_TXOFFSET_4         PpTxOffset4_reg;       //0x0B58
    regPP_TXOFFSET_5         PpTxOffset5_reg;       //0x0B5E

    regPP_TFACTOR_SIGN       PpTFactorSign_reg;     //0x0BB7

    regPP_TFACTOR_3          PpTFactor3_reg;        //0x0BBB
    regPP_TFACTOR_4          PpTFactor4_reg;        //0x0BBC
    regPP_TFACTOR_5          PpTFactor5_reg;        //0x0BBD
    regPP_TFACTOR_6          PpTFactor6_reg;        //0x0BBE
    regPP_TFACTOR_7          PpTFactor7_reg;        //0x0BBF

    regPP_CUBIC_OFFSET_F1_0  PpCubicOffsetF10_reg;  //0x0B41
    regPP_CUBIC_OFFSET_F2_0  PpCubicOffsetF20_reg;  //0x0B42
    regPP_CUBIC_OFFSET_F3_0  PpCubicOffsetF30_reg;  //0x0B43
    regPP_CUBIC_OFFSET_F4_0  PpCubicOffsetF40_reg;  //0x0B44
    regPP_CUBIC_OFFSET_F5_0  PpCubicOffsetF50_reg;  //0x0B45

    regPP_CUBIC_OFFSET_F1_1  PpCubicOffsetF11_reg;  //0x0B47
    regPP_CUBIC_OFFSET_F2_1  PpCubicOffsetF21_reg;  //0x0B48
    regPP_CUBIC_OFFSET_F3_1  PpCubicOffsetF31_reg;  //0x0B49
    regPP_CUBIC_OFFSET_F4_1  PpCubicOffsetF41_reg;  //0x0B4A
    regPP_CUBIC_OFFSET_F5_1  PpCubicOffsetF51_reg;  //0x0B4B

    regPP_CUBIC_OFFSET_F1_2  PpCubicOffsetF12_reg;  //0x0B4D
    regPP_CUBIC_OFFSET_F2_2  PpCubicOffsetF22_reg;  //0x0B4E
    regPP_CUBIC_OFFSET_F3_2  PpCubicOffsetF32_reg;  //0x0B4F
    regPP_CUBIC_OFFSET_F4_2  PpCubicOffsetF42_reg;  //0x0B50
    regPP_CUBIC_OFFSET_F5_2  PpCubicOffsetF52_reg;  //0x0B51

    regPP_CUBIC_OFFSET_F1_3  PpCubicOffsetF13_reg;  //0x0B53
    regPP_CUBIC_OFFSET_F2_3  PpCubicOffsetF23_reg;  //0x0B54
    regPP_CUBIC_OFFSET_F3_3  PpCubicOffsetF33_reg;  //0x0B55
    regPP_CUBIC_OFFSET_F4_3  PpCubicOffsetF43_reg;  //0x0B56
    regPP_CUBIC_OFFSET_F5_3  PpCubicOffsetF53_reg;  //0x0B57

    regPP_CUBIC_OFFSET_F1_4  PpCubicOffsetF14_reg;  //0x0B59
    regPP_CUBIC_OFFSET_F2_4  PpCubicOffsetF24_reg;  //0x0B5A
    regPP_CUBIC_OFFSET_F3_4  PpCubicOffsetF34_reg;  //0x0B5B
    regPP_CUBIC_OFFSET_F4_4  PpCubicOffsetF44_reg;  //0x0B5C
    regPP_CUBIC_OFFSET_F5_4  PpCubicOffsetF54_reg;  //0x0B5D

    regPP_CUBIC_OFFSET_F1_5  PpCubicOffsetF15_reg;  //0x0B5F
    regPP_CUBIC_OFFSET_F2_5  PpCubicOffsetF25_reg;  //0x0B60
    regPP_CUBIC_OFFSET_F3_5  PpCubicOffsetF35_reg;  //0x0B61
    regPP_CUBIC_OFFSET_F4_5  PpCubicOffsetF45_reg;  //0x0B62
    regPP_CUBIC_OFFSET_F5_5  PpCubicOffsetF55_reg;  //0x0B62

    regPP_CHROMA_COLOR       PpChromaColor_reg;     //0x074E
    regPP_CHROMA_MASK        PpChromaMask_reg;      //0x074F

    regPP_BORDER_COLOR_0     PpBorderColor0_reg;    //0x0750
    regPP_BORDER_COLOR_1     PpBorderColor1_reg;    //0x0751
    regPP_BORDER_COLOR_2     PpBorderColor2_reg;    //0x0752

    regPP_FOG_TABLE_INDEX    PpFogTableIndex_reg;   //0x0754
    regPP_FOG_TABLE_DATA     PpFogTableData_reg;    //0x0755

    regRB3D_DEPTHXY_OFFSET   DepthXYOffset_reg;     //0x0758
    regRB3D_CLRCMP_FLIPE     ClrCmpFlipe_reg;       //0x0759
    regRB3D_CLRCMP_CLR       ClrCmpClr_reg;         //0x075A
    regRB3D_CLRCMP_MSK       ClrCmpMsk_reg;         //0x075B

    regRB3D_ZMASK_WRINDEX    ZMaskWrindex_reg;      //0x075C
    regRB3D_ZMASK_DWORD      ZMaskDword_reg;        //0x075D
    regRB3D_ZMASK_RDINDEX    ZMaskRdindex_reg;      //0x075E
    regRB3D_STENCILREFMASK   StencilRefMask_reg;    //0x075F

    //MISC_BLOCK2 Registers
    regRB3D_ROPCNTL          RopCntl_reg;           //0x0760
    regRB3D_PLANEMASK        PlaneMask_reg;         //0x0761

    regRB3D_DSTCACHE_MODE    DstCacheMode_reg;      //

    regSE_VPORT_XSCALE       SeVportXScale_reg;     //0x0766
    regSE_VPORT_XOFFSET      SeVportXOffset_reg;    //0x0767
    regSE_VPORT_YSCALE       SeVportYScale_reg;     //0x0768
    regSE_VPORT_YOFFSET      SeVportYOffset_reg;    //0x0769
    regSE_VPORT_ZSCALE       SeVportZScale_reg;     //0x076A
    regSE_VPORT_ZOFFSET      SeVportZOffset_reg;    //0x076B
    regSE_ZBIAS_FACTOR       SeZBiasFactor_reg;     //0x076C
    regSE_ZBIAS_CONSTANT     SeZBiasConstant_reg;   //0x076D
    regSE_LINE_WIDTH         SeLineWidth_reg;       //0x076E
    regSE_W0_RANGE           SeW0Range_reg;         //0x076F

    regRE_W_BIAS             ReWBias_reg;           //0x0770

    regSE_VTX_NUM_ARRAYS     SeVtxNumArrays_reg;    // 0x830
    regSE_VTX_AOS_ATTR01     SeVtxAOSAttr01_reg;    // 0x831
    regSE_VTX_AOS_ADDR0      SeVtxAOSAddr0_reg;     // 0x832
    regSE_VTX_AOS_ADDR1      SeVtxAOSAddr1_reg;     // 0x833
    regSE_VTX_AOS_ATTR23     SeVtxAOSAttr23_reg;    // 0x834
    regSE_VTX_AOS_ADDR2      SeVtxAOSAddr2_reg;     // 0x835
    regSE_VTX_AOS_ADDR3      SeVtxAOSAddr3_reg;     // 0x836
    regSE_VTX_AOS_ATTR45     SeVtxAOSAttr45_reg;    // 0x837
    regSE_VTX_AOS_ADDR4      SeVtxAOSAddr4_reg;     // 0x838
    regSE_VTX_AOS_ADDR5      SeVtxAOSAddr5_reg;     // 0x839
    regSE_VTX_AOS_ATTR67     SeVtxAOSAttr67_reg;    // 0x83A
    regSE_VTX_AOS_ADDR6      SeVtxAOSAddr6_reg;     // 0x83B
    regSE_VTX_AOS_ADDR7      SeVtxAOSAddr7_reg;     // 0x83C
    regSE_VTX_AOS_ATTR89     SeVtxAOSAttr89_reg;    // 0x83D
    regSE_VTX_AOS_ADDR8      SeVtxAOSAddr8_reg;     // 0x83E
    regSE_VTX_AOS_ADDR9      SeVtxAOSAddr9_reg;     // 0x83F
    regSE_VTX_AOS_ATTR1011   SeVtxAOSAttr1011_reg;  // 0x840
    regSE_VTX_AOS_ADDR10     SeVtxAOSAddr10_reg;    // 0x841
    regSE_VTX_AOS_ADDR11     SeVtxAOSAddr11_reg;    // 0x842

    // Bump map registers
    regPP_LUMI_MATRIX       PpLumiMatrix_reg;       //0x2cec
    regPP_ROT_MATRIX0       PpRotMatrix0_reg;       //0x2cf0
    regPP_ROT_MATRIX1       PpRotMatrix1_reg;       //0x2cf4

    regRE_TOP_LEFT          ReTopLeft_reg;          //0x09B0

    regSE_VAP_CNTL           SeVapCntl_reg;         //0x0820

    regSE_VTX_FMT_0          SeVtxFmt0_reg;         //0x0822
    regSE_VTX_FMT_1          SeVtxFmt1_reg;         //0x0823

    regSE_VTE_CNTL           SeVteCntl_reg;         //0x082C

    regPP_CNTL_X             PpCntlX_reg;           //0x0B31

    regSE_PVS_CNTL           SePvsCntl_reg;         //0x08B4
    regSE_PVS_CONST_CNTL     SePvsConstCntl_reg;    //0x08B5

    regRE_POINTSIZE          RePointSize_reg;       // 0x0992

    regPP_PERF_CNTL         PpPerfCntl_reg;          //For hw profiling and perf stat collection only.
    regRE_PERF_CNTL         RePerfCntl_reg;

    INT   dwOrigMaxIndex; // use for SW index validation

    DWORD dwMaxIndex;  // Corresponds to mmSE_VF_MIN_VTX_INDX on R200, not used on R100
    DWORD dwMinIndex;  // Corresponds to mmSE_VF_MAX_VTX_INDX on R200, not used on R100.

    // All register variables must be added between dwRegStart and dwRegEnd.
    DWORD                   dwRegEnd;

    // Flags for the 3 texture units.
    DWORD                    dwTextureMapEn[ATI_MAX_NUM_TEX_UNITS];

    // The following 3 arrays are needed to properly support D3DTA_TEMP.
    // dwTextureAvailForTemp will track the Texture units available for use by
    // a blender for its Temp or Current output.
    DWORD                    dwTextureAvailForColorTemp[ATI_MAX_NUM_TEX_UNITS];
    DWORD                    dwTextureAvailForAlphaTemp[ATI_MAX_NUM_TEX_UNITS];

    DWORD                    dwNumTexCBlendEn;          // Number of TexCblend being enabled.
    DWORD                    dwNumTexABlendEn;          // Number of TexAblend being enabled.
    DWORD                    dwReloadTexReg[ATI_MAX_NUM_TEX_UNITS];
    DWORD                    dwD3DStage[ATI_MAX_NUM_TEX_UNITS];  // indicates the stages (any one of them) that uses
    D3DTXFILTER              d3dMinFilterState[ATI_MAX_NUM_TEX_UNITS];

    DWORD                    bumpping_d3dstage;
    DWORD                    bumpped_d3dstage;

    DWORD                    dwVolumeTxUnit;  //Volume Texture Unit, 0/2
    DWORD                    dwVolumeTxStage; //Volume Texture Stage
                                                               // the cooresponding texture units, init to 0xffff.
    BOOL                     bTexStateChanged[MAX_TEXSTAGE];     // keep track of changes related to txFilter & txFormat registers
    BOOL                     bBorderChanged[MAX_TEXSTAGE];    // keep track of changes in TexBorder color.

    DWORD                    dwSupportedTexStages;     // number of stages we have programmed.

    BOOL                     bColorKeyEn;
    DWORD                    IsWindowApp;              // Windowed App?

    DWORD                    dwRenderSurfaceHandle;
    DWORD                    dwZBufferHandle;

    BOOL                 bTclInUse;
    DWORD                *pFog3DTable;

    // The following timestamp array is to store surface pointers
    // that have to be timestamped, so when the SUBMITPM4ENTRIES function
    // calls TimeStampSurfaces with the number of surfaces as a parameter, we
    // will then walk this array and timestamp the appropriate surfaces.
    LPATISURFCNTX TimeStampArray[MAX_SURF_PER_TRI];

    D3DCMDBUFF           CmdBuff;                      // Command Buffer for this context
    LPD3DCMDBUFF         lpCmdBuff;

    // Context Index to find context pointer in lpD3DDevice. Used by D3D HSL surfINfo to
    // make sure that context is valid.
    DWORD                dwhContextID;        // Context Index to find context pointer.
    DWORD                dwhContext;          // Global context handle
    DWORD                dwContextIndex;      // Global context index

    //The following fields are used by Anti-Aliasing
    ANTIALIASINFO        AAInfo;

    LPDDRAWI_DIRECTDRAW_GBL lpDDGbl;
    //
    // This is the set of viewport parameters for this context.
    // It holds the offset and scale for each direction, X and Y.
    //
    D3DVIEWPORT7 d3dViewport; // The viewport as recieved from D3D
    D3DVIEWPORT7 atiViewport; // The viewport as used on chip (may be adjusted for AA)

#if(DIRECT3D_VERSION >= 0x0900)
    RECTL                atiScissorRect;
#endif//(DIRECT3D_VERSION >= 0x0900)

    // For direct 7
    LPVOID               lpDDLcl;             // Local surface pointer used as a ID
    LPATISURFHANDLE      pSurfHandle;

    struct _D3DDEVICE *  pD3DDevice;

    // Begin function pointer table
    DWORD (*ProcessFVF)( struct _ATID3DCNTX *,unsigned long ,unsigned long *,unsigned long *,unsigned long * );
    void (*SetRenderStateToHw)(struct _ATID3DCNTX * pCtxt);
    HRESULT (*Dp2CreatePixelShader)   ( struct _ATID3DCNTX *pCtxt, LPD3DHAL_DP2CREATEPIXELSHADER pCPS, LPDWORD pCode );
    HRESULT (*Dp2DeletePixelShader)   ( struct _ATID3DCNTX *pCtxt, LPD3DHAL_DP2COMMAND pCmd );
    HRESULT (*Dp2SetPixelShader)      ( struct _ATID3DCNTX *pCtxt, LPD3DHAL_DP2COMMAND pCmd);
    HRESULT (*Dp2SetPixelShaderConsts)( struct _ATID3DCNTX *pCtxt, DWORD StartReg, DWORD dwCount, LPDWORD pData );
    DWORD   (*RecalcTexStages)        ( struct _ATID3DCNTX *pCtxt, DWORD dwMaxStage );
    LPDWORD (*HwVS_UpdateShader)      ( struct _ATID3DCNTX *pCtxt, LPDWORD pdwOut);
    VOID    (*HwVS_Assemble)          ( struct _ATID3DCNTX *pCtxt, struct _ATIVTXSHADER *pVtxShader);
    VOID  (*HwTCL_SetVtxProcMode)   ( struct _ATID3DCNTX *pCtxt);
    HRESULT (*HwVS_ParseDeclBody)     ( struct _ATID3DCNTX *pCtxt, struct _ATIVTXSHADER  *pAtiVertexShader, LPVOID lpDeclBody,
                                        DWORD dwDeclSizeDW, LPDWORD pdwFVFType, DWORD dwShaderFlags);
    void (*Rad2ConvertRGBAToHW)(float* pfData, DWORD dwScale, struct _PSRGBACONSTANT * lpHWConst );

#if (DIRECT3D_VERSION >= 0x0900)
    HRESULT (*HwVS_VSDeclInit)     ( struct _ATID3DCNTX *pCtxt,
                                     struct _ATIVTXSHADER  *pAtiVSDecl, // should be struct _ATIVSDECL  *pAtiVSDecl,
                                     D3DVERTEXELEMENT9  *pDecl,
                                     DWORD               dwNumElements );
#endif // (DIRECT3D_VERSION >= 0x0900)

    //
    // Begin TCL State
    ATIMATRIX mWorld[ATI_NUM_BLEND_MATRICES];
    ATIMATRIX mView, mVP, mInvVP;
    D3DCOLORVALUE gblAmbient;
    LPD3DLIGHT7 pd3dLight;
    PULONGLONG pllLightNotReady;
    ULONGLONG llLightNotReadyCount;
    DWORD dwNumAllocatedLights;
    DWORD dwNumLocalLights;
    DWORD dwNumLights;
    ATIVECTOR d3dUcp[ATI_NUM_CLIP_PLANES];

    // According to the Dx7 spec, it is possible for an app to send down an FVF with
    // more texture coordinates than we specify in our caps (dwFVFCaps).  We must accept
    // the larger vertex and discard any sets of coordinates over what we specify in dwFVFCaps.
    //
    // dwDxVtxSize is the amount of bytes in each FVF vertex sent down from the app.
    // dwDxVtxHwSize is the amount of bytes from each FVF vertex that the HW will use.
    //
    // These sizes will be used to set up the VB pointers and to place the proper data
    // into the CB on Imm drawing routines.
    DWORD dwDxFvfType, dwDxVtxSize, dwDxVtxHwSize;
    DWORD dwAtiInputVtxFmt, dwAtiInputVtxFmtMask, dwAtiOutputVtxFmt;
    DWORD dwAtiTclSeVfCtrlFlags;
    DWORD dwDxFvfDirtyFlags;     //Keep track of ATI_REEVALUTE_FVF flag.
    D3DHAL_DP2OPERATION dpLastPrimitiveType;

    EVTXPROCMODE eVtxProcMode; // vertex processing mode
    EVTXPROCMODE eLastVtxProcMode; // vertex processing mode

    DWORD dwTclFlags;
    DWORD dwRasterizerCullFlags;
    DWORD dwTclCullFlags;
    DWORD dwTclLMCFlags;

    TclMaterialSrc tclMaterialSrc;

    // TCL Vector memory registers
    ATIMATRIX_cmd mWVCmd[ATI_NUM_BLEND_MATRICES];
    ATIMATRIX_cmd mInverseWVCmd[ATI_NUM_BLEND_MATRICES];
    ATIMATRIX_cmd mWVPCmd[ATI_NUM_BLEND_MATRICES];
    ATIMATRIX_cmd mTextureCmd[ATI_NUM_TEX_MATRICES];
    ATIMATRIX_cmd mProjCmd;
    ATIUSERCLIPPLANE_cmd atiUcpCmd[ATI_NUM_CLIP_PLANES];
    ATIGBLAMBIENT_cmd atiGlbAmbientCmd;
    ATITCLFOGEYESCALENRML_cmd atiFogEyeCmd;
    ATIHOSCONSTANT_cmd atiHosConstantCmd;
    ATIPNTSPRVPSCALE_cmd        atiPntSprVpScaleCmd;
    ATIPNTSPRATTCONST_cmd       atiPntSprAttConstCmd;
    ATIPNTSPREYEVECINMODEL_cmd  atiPntSprEyeVecInModelCmd;
    ATIPNTSPRCLAMP_cmd          atiPntSprClampCmd;
    LPATILIGHT_cmd patiLightCmd;
    DWORD pdwEnabledLightIndex[ATI_NUM_LIGHTS];

    // TCL Scalar memory registers
    ATITCLGRDBND_cmd atiGuardBandCmd;


    ATIMATERIAL_cmd atiMaterialCmd;


    // TCL flat registers
    ATITCLRAD2GLOBALSTATE_cmd        tclR2GlobalStateCmd;
    ATITCLRAD2OUTPUTVTXCONTROL_cmd   tclR2OutputVtxControlCmd;
    ATITCLRAD2MISCCONTROL_cmd        tclR2MiscControlCmd;
    ATITCLRAD2TEXTURECONTROL_cmd     tclR2TextureControlCmd;
    ATITCLRAD2LIGHTCONTROL_cmd       tclR2LightControlCmd;
    ATITCLRAD2INPUTVTXVECTORADDR_cmd tclR2InputVtxVectorAddrCmd;
    ATITCLRAD2INDXLIMIT_cmd          tclIndxLimitCmd;
    ATITCLRAD2HOSCNTL_cmd            tclHosCntlCmd;
    ATITCLRAD2HOSVECINTERP_cmd       tclHosVecInterpCmd;
    ATITCLRAD2PROGSTREAMCNTL_cmd     tclProgStreamCntlCmd;
    ATITCLRAD2POINTSPRITECNTL_cmd    tclR2PntSprCntlCmd;

    ATITCLFLUSH_cmd tclFlushCmd;

    BOOL bTclFlush;

    // dwTclDirtyFlags uses the ATI_TCL_DIRTY_XXX flags
    DWORD dwTclDirtyFlags;

    // dwTclNotReadyFlags uses the ATI_TCL_NOT_READY_XXX flags
    DWORD dwTclNotReadyFlags;

    // dwTclLightScalarNotReadyFlags uses the ATI_TCL_LIGHT_SCA_NOT_READY_XXX flags
    // This is an optimization to eliminate computing the scalar light data (spot light
    // cone angles, attenuation, etc) when it does not need to be computed.
    DWORD dwTclLightScalarNotReadyFlags;

    // dwTclLightColorDirtyFlags uses the ATI_TCL_LIGHT_COLOR_DIRTY_XXX flags
    DWORD dwTclLightColorDirtyFlags;

    // dwTclLightStatus uses the ATI_TCL_ENABLED_LIGHTXXX flags.
    // This member is a bitfield that indicates which of the
    // 8 lights are currently enabled
    DWORD dwTclLightStatus;

    // dwTclUcpStatus uses the ATI_TCL_ENABLED_UCPXXX flags.
    // This member is a bitfield that indicates which of the
    // 6 UCPs are enabled.
    DWORD dwTclUcpStatus;

    // dwTclOutputVtxFmtNeeded uses the ATI_TCL_OUTFVF_XXX flags
    // This member is a bitfield that indicates what vertex components are
    // needed post-TCL but pre-triangle setup. In order to optimize the number of
    // vertex components passed from TCL to setup, only those components
    // that are needed (as determined by renderstate and texturestate) are passed
    // via the TCL register SE_TCL_OUTPUT_VTX_FMT
    DWORD dwTclOutputVtxFmtNeeded;

    // Load balancing uses the following to store the original values
    // so they can be restored properly
    DWORD dwLoBalOutVtxSel;
    DWORD dwLoBalFVFSize;
    DWORD dwLobalFlags;

    D3DMATRIX mD3dProjMatrix;
    D3DMATRIX d3dTxMatrix[D3DHAL_TSS_MAXSTAGES];

    DWORD dwTCLTexCoordGenSpace; // count of # of texture units that use texture coordinate generation

    // Fog Settings
    float fFogStart;
    float fFogEnd;
    float fFogDensity;
    float fWNear;  //Saved WInfo for StateCapture.
    float fWFar;   //Saved WInfo for StateCapture.

    // Disable specular add.
    BOOL bSpecularAddDisable;

    // Vertex Blending Settings
    DWORD dwVertexBlendWeightCnt;

    // End TCL State
    ATISTATESETRECORD StateSetRecord;

    PRENDTRI* pDrawTable;
    STATESETFUNCTIONTABLE *pDrawPrimStateFunctionTable;

    struct _ATIVERTEXBUFFER *lpCurrentVtxBuff;

    //Current info set by dx8 D3DDP2OP_SETINDICES
    DWORD dwIndexStride;
    DWORD dwIndexHandle;       //used by StateCapture.

    D3DHAL_DP2SETSTREAMSOURCE sCurrStreamSource;  //used by StateCapture.

#if (DIRECT3D_VERSION >= 0x0900)
    D3DHAL_DP2SETSTREAMSOURCE2 sCurrStreamSource2; // Stream Offset
    DWORD dwDxVtxOffsetInDW; // Converted from stream offset in bytes >> 2. Now it's in DWORDs!!!
#endif // (DIRECT3D_VERSION >= 0x0900)

    //Current Index buffer, set by dx8 D3DDP2OP_SETINDICES.
    struct _ATIVERTEXBUFFER *lpCurrentIdxBuff;

    // Stores info for user memory vertex data. Only lpVtxList field is valid and
    // is used. The rest of the structure is there so that we don't need to pass
    // another parameter about the vertex data location to our draw routines.
    struct _ATIVERTEXBUFFER *lpUserMemVtxBuff;

    enum _EATI_VTX_LOC_DX8 eDx8VBInUse;
    enum _EATI_IDX_LOC_DX8 eDx8IBInUse;

    // This is the virtual address corresponding to the Rage 6 device
    // address currently stored in SeVtxAOSAddr0_reg
    DWORD dwSeVtxAOSAddr0Linear;

    DWORD dwCurrVtxShaderHandle;
    ATILIST alVertexShaderList;
    struct _ATID3DSTREAM AtiD3DStream[VS_MAX_NUM_STREAMS];

#if (DIRECT3D_VERSION >= 0x0900)
    ATILIST alVSDeclList;
    ATILIST alVSFuncList;
    DWORD   dwCurrVSDeclHandle;
    DWORD   dwCurrVSFuncHandle;
    BOOL    bDX9VSDECLFUNC_dirty;
#endif

    // Pointer to dynamically allocated Vertex Shader Constant Store
    // This memory is not allocated unless the current ASIC supports
    // programmable vertex shaders.
    DXCONSTSTORE dxVtxShaderConstStore;
    DWORD dwConstSegsToUpdate;

    // Temporary vertex shader code storage for assembly and optimization
    ATIVECTOR TempOrigCode[ATI_VS_CODE_SIZE];

    // PVS Management structure
    // This is set up to be used as a device dependent context component
    // once the driver migrates to this architecture
    ATIPVSMGMT pvsMgmt;

    DWORD dwBaseVtxIndex;
    struct _ATIVTXARRAY lpVtxArray[ATI_MAX_NUM_AOS];

    BOOL bUsedT2;

    QS_FUNC2 QS_TempFunc;

    struct _ATIVERTEXBUFFER *lpIntVtxBuff;

    // Need to record if stencil has ever been enabled for this context
    // so that we can do fast clears on 24 bit Z if stencil is not at risk.
    BOOL bStencilEverEnabled;

    // Track FVF fields that are needed by the driver, but not provided by the app
    DWORD dwBadFVFFlags;

    BOOL bTclEnable;

    // Restore state of color/alpha blenders
    BOOL bColorBlendersSaved;
    BOOL bAlphaBlendersSaved;
    BOOL bBlendersChangedForMissingDiffuse;
    BOOL bBlendersChangedForMissingSpecular;
    BOOL bValidateBlendersWithFVF;

    // Flag for tracking tweeneng state
    DWORD dwTweeningFlags;
    DWORD dwTweenFactor;

    // Number of times to tesselate a triangle with HOS
    float fPatchSegments;

    // Continuous or discrete tesselation.  We only support discrete.
    DWORD dwPatchEdgeStyle;

    // Position tessellation type
    DWORD dwPositionTessType;

    // Normal tessellation type
    DWORD dwNormalTessType;

    // Flag for tracking indexed vertex blending state
    DWORD   dwIdxVtxBlndFlags;
    DWORD   dwMaxWorldMatrixIndex;
    DWORD   dwPvmsMtxDirtyFlagsLo; // for matrix  0 to 31
    DWORD   dwPvmsMtxDirtyFlagsHi; // for matrix 32 to 63

    ATILIST alWorld_MatrixList;
    ATILIST alMV_MatrixList;
    ATILIST alITMV_MatrixList;
    ATILIST alM2C_MatrixList;

    // For Point Sprite Sizes
    DWORD   dwPointSpriteFlags;
    BOOL    bPointSpriteEnable;
    float   fPointSize;
    DWORD   dwFlt2FixPointSize;
    float   fPointSizeMin;
    DWORD   dwFlt2FixPointSizeMin;
    float   fPointSizeMax;
    DWORD   dwFlt2FixPointSizeMax;
    LPDWORD lpdwPSBuffer;
    LPDWORD lpdwROPSBuffer;

    BOOL    bPointScaleEnable;
    float   fPointScaleA;
    float   fPointScaleB;
    float   fPointScaleC;

    // Pointer to TCL/SW PointSprite Render functions
    void  (*RenderOnePointSprite)(struct _ATID3DCNTX *pCtxt, LPDWORD lpVertices, LPDWORD lpVerticesFlatShading, DWORD dwStampCount);

    // For keeping track of RTPatch handles
    ATILIST   alRTPatchHandleList;

    DWORD dwTexCoordOffset;
    DWORD dwTexCoordSetOffset[MAX_TEXSTAGE];
    DWORD dwHWSizeofTexCoordSet[ATI_MAX_NUM_TEX_UNITS];


    // Flag for texture coords whis is used but not included in the vertex
    DWORD           dwTexCoordsNotIncluded;
    float           fTexCoordsDelta;

    //This is for re_arrange vertex element.
    DWORD           dwReArrangeVtxElement; //0: no arrange, 1: arrange,
                                           //2: arrange and change HW vertex size.
                                           //4: skip PSIZE.
    DWORD           dwPSizeOffset;

    D3DHAL_DP2CLEAR dp2DepthClearInfo;
    DWORD           dwDepthClearRectCount;
    DWORD           dwDepthTypeAtClear;
    DWORD           dwCurrentDepthType;
    BOOL            bIsDepthDirty;

    BOOL bWBufferDisable;

    BOOL    bBeingDestroyed;

    DWORD (__fastcall *pfnDrawPrimitives2)(LPD3DHAL_DRAWPRIMITIVES2DATA lpdp2d, struct _ATID3DCNTX *pCtxt);

//#if VB_LAZY_FREE_INTVB
    DWORD dwLazyFreeVB_IntVBSize;       //current size of Int VBs
    DWORD dwLazyFreeVB_NumIVBsInLFL;    //Number of IntVBs from this d3d context in LFL
    BOOL  bAreWeSwappingIntVB;
//#endif//VB_LAZY_FREE_INTVB

#if (DIRECT3D_VERSION >= 0x0900)
    //Asynchronous Query Operations
    DWORD   dwQueryCount;
    ATILIST queryList;

#endif //(DIRECT3D_VERSION >= 0x0900)

#if defined(KMD) || defined(UMD)
    // For surfaces we store ATISURFCNTX ptr and for VB's & IB's we store ATIVERTEXBUFFER ptrs
    union
    {
        R2ResourceSurfTable     resSurfTable;       
        PVOID                   resSurfArray[D3D_RES_ALL];        
    };
    HANDLE  hKMDevice;
#endif // defined(KMD) || defined(UMD)
}ATID3DCNTX,    *LPATID3DCNTX;

#define GlobalContextLimit ContextPerBlock

LPATID3DCNTX gapContext[GlobalContextLimit];

#define ATI_FORCE_SLOWZCLEAR 0x80000000

#define ATI3DCNTX_LOBALFLAGS_ACTIVE     0x00000001L
#define ATI3DCNTX_LOBALFLAGS_CHANGED    0x00000002L

enum FINDSURFACE_CONTEXT_TYPE
{
    FIND_ZBUFFER      = 0,
    FIND_RENDERTARGET = 1,
};

__inline LPATID3DCNTX GetD3DContextFromHandle(DWORD_PTR dwhContext)
{
    if(dwhContext > 0 && dwhContext < GlobalContextLimit)
        return gapContext[dwhContext];
    else
        return NULL;
}

__inline DWORD AssignHandleToD3DContext(LPATID3DCNTX pContext)
{
    DWORD dwIndex;

    for(dwIndex = 1; dwIndex < GlobalContextLimit; dwIndex++)
    {
        if(gapContext[dwIndex] == NULL)
        {
            gapContext[dwIndex] = pContext;
            return dwIndex;
        }
    }
    return 0;
}

__inline VOID FreeHandleToD3DContext(DWORD dwhContext)
{
    HSLASSERT(dwhContext > 0 && dwhContext < GlobalContextLimit);
    gapContext[dwhContext] = NULL;
}

#define GetD3DDevice(pContext)  (pContext->pD3DDevice)
#define GetD3DContextPointer(pD3DDevice, ContextID)  (pD3DDevice)->ATID3DCntxList[ContextID]
void NotifyD3DCntxOfLeavingExclusiveMode( struct _D3DDEVICE *lpD3DDev );
LPATID3DCNTX FindSurfaceZRTContext( struct _D3DDEVICE *pD3DDev, LPDDRAWI_DDRAWSURFACE_LCL lpSLCL, DWORD dwSurfType );

__inline DWORD GetReArrangedHWInputVtxFmt(LPATID3DCNTX pCtxt)
{
    return (pCtxt->dwAtiInputVtxFmt & pCtxt->dwAtiInputVtxFmtMask);
}

// Use struct to sustain order of DW in memory
typedef struct
{
    DWORD               dwPrimTexCntl_Dirty;
    DWORD               dwSecTexCntl_Dirty;

    DWORD               dwPrimTexComb_Dirty;
    DWORD               dwSecTexComb_Dirty;
}MULTIREG;


////////////////////////////////////////////////////////////////////////////////
// Find the texture associated to a given texture handle value (which is to
// say , to a surface handle )
// Note:
// For DX6:
// For DX7:
////////////////////////////////////////////////////////////////////////////////
_inline LPVOID SurfaceHandleToCntx(DWORD dwHandle, LPATID3DCNTX lpContext)
{
    // We assume the context pointer is good.
    HSLASSERT(lpContext);

    // Check to make sure the pSurfHandle pointer is still good.  If the DDLCL
    // associated with this context has been deleted already, then we have also
    // lost this pointer.
    if ( lpContext->pSurfHandle )
    {
        return( ((lpContext->pSurfHandle->dwNumATITexCntxAllocated > dwHandle )&&(dwHandle != 0) )
            ?lpContext->pSurfHandle->lpATITexCntxList[dwHandle]:NULL);
    }
    else
    {
        // If pSurfHandle is NULL then the DDLcl better be as well, since it is
        // the deleation of the DDLCL that would cause us to clear pSurfHandle.
        HSLASSERT(lpContext->lpDDLcl == NULL);
        return NULL;
    }

}

//Checks both DX7 & DX8 AA render states and AA forced on state to determines whether
//AA should be enabled or disabled.
__inline BOOL CheckAAStates(LPATID3DCNTX pCtxt, LPATISURFCNTX lpRenderContext)
{
    DWORD dwAntiAlias;
    DWORD dwQualityLevel = 0;

    dwAntiAlias = ((pCtxt->ATIStateList[D3DRS_MULTISAMPLEANTIALIAS]) &&
                  GetSurfCntxMSType(lpRenderContext) != D3DMULTISAMPLE_NONE);

    dwAntiAlias |= pCtxt->AAInfo.AAFlags.bf.Enabled |
                   pCtxt->ATIStateList[D3DRENDERSTATE_ANTIALIAS] |
                  (pCtxt->AAInfo.AAFlags.bf.EnableState == FSAA_FORCEON);

    return dwAntiAlias;
}

extern void WriteRenderStateToContext(LPATID3DCNTX lpATiContext,
                                      LPATISURFCNTX lpSurfaceCntx);

extern void WriteZBufferStateToContext(LPATID3DCNTX lpATiContext,
                                       LPATISURFCNTX lpZBufferCntx);

extern DWORD FindMatchContextID(LPATID3DCNTX lpATIContext);

extern HRESULT SetRenderAndZToCntx(LPATID3DCNTX lpATiContext,
                                   DWORD dwRenderSurfaceHandle,
                                   DWORD dwZBufferHandle);

#if (DIRECT3D_VERSION >= 0x0900)
extern HRESULT SetRenderTargetToCntx(LPATID3DCNTX lpATiContext, DWORD dwRenderSurfaceHandle);
extern HRESULT SetDepthStencilToCntx(LPATID3DCNTX lpATiContext, DWORD dwZBufferHandle);
#endif // (DIRECT3D_VERSION >= 0x0900)

extern DWORD GetZEnable( LPATID3DCNTX pContext );

DWORD __stdcall ContextCreate32(LPD3DHAL_CONTEXTCREATEDATA pccd);
DWORD __stdcall ContextDestroy32(LPD3DHAL_CONTEXTDESTROYDATA pcdd);
BOOL __stdcall SetCtxtRT(LPATID3DCNTX pContext, DD_DIRECTDRAW_LOCAL *pDDLcl, DD_SURFACE_LOCAL *pDDSLclRT);
void __stdcall SetCtxHandleList(LPATID3DCNTX pContext, DD_DIRECTDRAW_LOCAL *pDDLcl);
//void CleanUpContext(LPVOID pD3DDevice, DWORD indexContext);

// Forward declaration for vertex buffer functions in D3DHSL.C
HRESULT CreateInternalVertexBuffer( LPATID3DCNTX pContext );
void DestroyInternalVertexBuffer( LPATID3DCNTX pContext );

// Extern functions in D3DCLEAR.C
extern DWORD __stdcall Clear232( LPD3DHAL_CLEAR2DATA lpcd2);

extern DWORD __stdcall SetViewport232( LPVOID lpsvd2);
extern HRESULT  ATIClear( LPATID3DCNTX  pContext, DWORD   dwFlags,        // in:  surfaces to clear
                                        DWORD   dwFillColor,    // in:  Color value for rtarget
                                        D3DVALUE dvFillDepth,   // in:  Depth value for //      Z-buffer (0.0-1.0)
                                        DWORD   dwFillStencil,  // in:  value used to clear stencil buffer
                                        LPRECTL lpRects,      // in:  Rectangles to clear
                                        DWORD   dwNumRects);    // in:  Number of rectangles


// Extern functions in initialize.c for DX7 support
extern DWORD __stdcall CreateSurfaceEx32( LPDDHAL_CREATESURFACEEXDATA lpcsxd );
extern DWORD __stdcall DestroyDDLocal32( LPDDHAL_DESTROYDDLOCALDATA lpdddd );
extern DWORD __stdcall GetDriverState32( LPDDHAL_GETDRIVERSTATEDATA lpgdsd );
extern void RestoreTextureSurface(struct _D3DDEVICE *lpD3DDev,
                                  LPDDRAWI_DIRECTDRAW_LCL lpDDLcl,
                                  LPDDRAWI_DDRAWSURFACE_LCL lpDDSLcl);

extern void CSExDisassociateSurfCntx( LPDDRAWI_DIRECTDRAW_LCL lpDDLcl,
                                      LPATISURFHANDLE lpSurfHandleList,
                                      DWORD dwSurfaceHandle,
                                      LPATISURFCNTX lpSurfCntxSrc );

// Extern functions in D3DCB3.C
extern DWORD __stdcall DrawPrimitives232(LPD3DHAL_DRAWPRIMITIVES2DATA lpdp2d);

// Extern functions in D3DTXSTAGE.C
extern HRESULT AtiSetTextureStageStates(LPATID3DCNTX lpCntx, LPD3DHAL_DP2COMMAND *lppCmd);

//Extern Data in RAGED3D.C
extern HRESULT AtiSetRenderStates(LPATID3DCNTX lpD3DCntx, LPD3DHAL_DP2COMMAND lpCmd, LPDWORD lpStateMirror);

// In antialias.c

UINT CalcAARTSize(struct _D3DDEVICE *lpD3DDev, DWORD dwRTWidth, DWORD dwRTHeight, DWORD dwBytesPP, DWORD dwNumSamples);

DWORD SetAAXYRatios(LPATID3DCNTX pContext, DWORD dwNumSamples);

void AAJitterTableControl(LPATID3DCNTX pContext);

void SetUpAABlendScaleBltInfo(LPATID3DCNTX lpContext,
                              LPATISURFCNTX lpSurfCntx,
                              BLENDED_SCALEBLT_INFO *BlendInfo,
                              RECTL *SrcRect, RECTL *DstRect, BOOL bScaleSrcRect);

void ATISceneCaptureStart(LPATID3DCNTX pContext);

HRESULT ATISceneCaptureEnd(LPATID3DCNTX pContext);

void FreeAASurfaces(LPATID3DCNTX lpATID3DCntx);

void AASurfaceLock(struct _D3DDEVICE *pD3DDevice,
                          LPDDRAWI_DDRAWSURFACE_LCL lpDDS_RenderTarget);

void AASurfaceUnlock(struct _D3DDEVICE *pD3DDevice,
                            LPDDRAWI_DDRAWSURFACE_LCL lpDDS_RenderTarget);

BOOL EnableAntiAliasing(LPATID3DCNTX lpATID3DCntx,
                        LPATISURFCNTX lpRenderContext,
                        LPATISURFCNTX lpZBufferCntx);

void EnableAARendering(LPATID3DCNTX pContext,
                       LPATISURFCNTX lpRenderSurfCntx,
                       LPATISURFCNTX lpZBufferCntx);

HRESULT DisableAARendering(LPATID3DCNTX pContext,
                        LPATISURFCNTX lpBltSurfCntx,
                        DWORD dwFlags);

BOOL AAChangeRenderTarget(LPATID3DCNTX pContext,
                          LPATISURFCNTX lpNewRenderSurfCntx,
                          LPATISURFCNTX lpNewZBufferCntx);

BOOL CanReuseAASurfaces(LPATID3DCNTX pContext,
                        LPATISURFCNTX lpRenderSurfCntx,
                        LPATISURFCNTX pZBufferCntx);

HRESULT BltFromAASurface(LPATID3DCNTX lpContext,
                      LPATISURFCNTX lpSurfCntx);

BOOL BltToAASurface(LPATID3DCNTX lpContext,
                    LPATISURFCNTX lpSurfCntx,
                    LPRECTL lpRect);

_inline DisableHiZState( LPATID3DCNTX lpContext )
{
    set_RB3D_ZSTENCILCNTL_hierarchyenable( &lpContext->ZStencilCntl_reg, 0 );
    lpContext->dwCntxDirtyMask |= ( DEPTH_SURFACE_DIRTY | DEPTH_CACHE_DIRTY );
}

///////////////////////////////////////////////////////////////////////////////
// Dirty Bit Management Routines
///////////////////////////////////////////////////////////////////////////////
_inline void SetTexDirtyBit( LPATID3DCNTX lpContext, DWORD dwFlag )
{
    lpContext->dwTexDirtyBits |= dwFlag;
    lpContext->dwCntxDirtyMask |= TEXTURES_DIRTY;
}

_inline void ClearTexDirtyBit( LPATID3DCNTX lpContext, DWORD dwFlag )
{
    lpContext->dwTexDirtyBits &= ~dwFlag;
    if ( !lpContext->dwTexDirtyBits )
    {
        lpContext->dwCntxDirtyMask &= ~TEXTURES_DIRTY;
    }
}

_inline BOOL IsTexBitDirty( LPATID3DCNTX lpContext, DWORD dwFlag )
{
    // Check master bit first before checking texture bits.  This might be
    // useful when one wants to easily turn off all textures.
    return ( lpContext->dwCntxDirtyMask & TEXTURES_DIRTY ) ?
        ( lpContext->dwTexDirtyBits & dwFlag ) : FALSE;
}

_inline void ClearAllDirtyBits( LPATID3DCNTX lpContext )
{
    lpContext->dwCntxDirtyMask = 0;
    lpContext->dwTexDirtyBits = 0;
}

_inline void SetAllDirtyBits( LPATID3DCNTX lpContext )
{
    lpContext->dwCntxDirtyMask = ATI_CNTX_DIRTY_ALL;
    lpContext->dwTexDirtyBits = ATI_CNTX_DIRTY_ALL;
}


// Extern in clear.c
extern void WriteOneRegister(LPATID3DCNTX lpATID3DCntx, DWORD dwRegAddr, DWORD* pRegVal);

extern VOIDFUNC Rend2RegFunc[];
extern void Rend2Reg_TEXTUREHANDLE( LPATID3DCNTX pContext );
extern void Rend2Reg_ANTIALIAS( LPATID3DCNTX pContext );
extern void Rend2Reg_TEXTUREADDRESS( LPATID3DCNTX pContext );
extern void Rend2Reg_TEXTUREPERSPECTIVE( LPATID3DCNTX pContext );
extern void Rend2Reg_WRAPU( LPATID3DCNTX pContext );
extern void Rend2Reg_WRAPV( LPATID3DCNTX pContext );
extern void Rend2Reg_ZENABLE( LPATID3DCNTX pContext );
extern void Rend2Reg_FILLMODE( LPATID3DCNTX pContext );
extern void Rend2Reg_SHADEMODE( LPATID3DCNTX pContext );
extern void Rend2Reg_LINEPATTERN( LPATID3DCNTX pContext );
extern void Rend2Reg_MONOENABLE( LPATID3DCNTX pContext );
extern void Rend2Reg_ROP2( LPATID3DCNTX pContext );
extern void Rend2Reg_PLANEMASK( LPATID3DCNTX pContext );
extern void Rend2Reg_ZWRITEENABLE( LPATID3DCNTX pContext );
extern void Rend2Reg_ALPHATESTENABLE( LPATID3DCNTX pContext );
extern void Rend2Reg_LASTPIXEL( LPATID3DCNTX pContext );
extern void Rend2Reg_TEXTUREMAG( LPATID3DCNTX pContext );
extern void Rend2Reg_TEXTUREMIN( LPATID3DCNTX pContext );
extern void Rend2Reg_SRCBLEND( LPATID3DCNTX pContext );
extern void Rend2Reg_DESTBLEND( LPATID3DCNTX pContext );
extern void Rend2Reg_TEXTUREMAPBLEND( LPATID3DCNTX pContext );
extern void Rend2Reg_CULLMODE( LPATID3DCNTX pContext );
extern void Rend2Reg_ZFUNC( LPATID3DCNTX pContext );
extern void Rend2Reg_ALPHAREF( LPATID3DCNTX pContext );
extern void Rend2Reg_ALPHAFUNC( LPATID3DCNTX pContext );
extern void Rend2Reg_DITHERENABLE( LPATID3DCNTX pContext );
extern void Rend2Reg_ALPHABLENDENABLE( LPATID3DCNTX pContext );
extern void Rend2Reg_FOGENABLE( LPATID3DCNTX pContext );
extern void Rend2Reg_SPECULARENABLE( LPATID3DCNTX pContext );
extern void Rend2Reg_ZVISIBLE( LPATID3DCNTX pContext );
extern void Rend2Reg_SUBPIXEL( LPATID3DCNTX pContext );
extern void Rend2Reg_SUBPIXELX( LPATID3DCNTX pContext );
extern void Rend2Reg_STIPPLEDALPHA( LPATID3DCNTX pContext );
extern void Rend2Reg_FOGCOLOR( LPATID3DCNTX pContext );
extern void Rend2Reg_FOGTABLEMODE( LPATID3DCNTX pContext );
extern void Rend2Reg_FOGSTART( LPATID3DCNTX pContext );
extern void Rend2Reg_FOGEND( LPATID3DCNTX pContext );
extern void Rend2Reg_FOGDENSITY( LPATID3DCNTX pContext );
extern void Rend2Reg_STIPPLEENABLE( LPATID3DCNTX pContext );
extern void Rend2Reg_EDGEANTIALIAS( LPATID3DCNTX pContext );
extern void Rend2Reg_COLORKEYENABLE( LPATID3DCNTX pContext );
extern void Rend2Reg_BORDERCOLOR( LPATID3DCNTX pContext );
extern void Rend2Reg_TEXTUREADDRESSU( LPATID3DCNTX pContext );
extern void Rend2Reg_TEXTUREADDRESSV( LPATID3DCNTX pContext );
extern void Rend2Reg_MIPMAPLODBIAS( LPATID3DCNTX pContext );
#if(DIRECT3D_VERSION < 0x0900)
extern void Rend2Reg_ZBIAS( LPATID3DCNTX pContext );
#endif
extern void Rend2Reg_RANGEFOGENABLE( LPATID3DCNTX pContext );
extern void Rend2Reg_ANISOTROPY( LPATID3DCNTX pContext );
extern void Rend2Reg_FLUSHBATCH( LPATID3DCNTX pContext );
extern void Rend2Reg_TRANSLUCENTSORTINDEPENDENT( LPATID3DCNTX pContext );
extern void Rend2Reg_STENCILENABLE( LPATID3DCNTX pContext );
extern void Rend2Reg_STENCILFAIL( LPATID3DCNTX pContext );
extern void Rend2Reg_STENCILZFAIL( LPATID3DCNTX pContext );
extern void Rend2Reg_STENCILPASS( LPATID3DCNTX pContext );
extern void Rend2Reg_STENCILFUNC( LPATID3DCNTX pContext );
extern void Rend2Reg_STENCILREF( LPATID3DCNTX pContext );
extern void Rend2Reg_STENCILMASK( LPATID3DCNTX pContext );
extern void Rend2Reg_STENCILWRITEMASK( LPATID3DCNTX pContext );
extern void Rend2Reg_TEXTUREFACTOR( LPATID3DCNTX pContext );
extern void Rend2Reg_SCENECAPTURE( LPATID3DCNTX pContext );
extern void Rend2Reg_STIPPLEPATTERN00( LPATID3DCNTX pContext );
extern void Rend2Reg_STIPPLEPATTERN01( LPATID3DCNTX pContext );
extern void Rend2Reg_STIPPLEPATTERN02( LPATID3DCNTX pContext );
extern void Rend2Reg_STIPPLEPATTERN03( LPATID3DCNTX pContext );
extern void Rend2Reg_STIPPLEPATTERN04( LPATID3DCNTX pContext );
extern void Rend2Reg_STIPPLEPATTERN05( LPATID3DCNTX pContext );
extern void Rend2Reg_STIPPLEPATTERN06( LPATID3DCNTX pContext );
extern void Rend2Reg_STIPPLEPATTERN07( LPATID3DCNTX pContext );
extern void Rend2Reg_STIPPLEPATTERN08( LPATID3DCNTX pContext );
extern void Rend2Reg_STIPPLEPATTERN09( LPATID3DCNTX pContext );
extern void Rend2Reg_STIPPLEPATTERN10( LPATID3DCNTX pContext );
extern void Rend2Reg_STIPPLEPATTERN11( LPATID3DCNTX pContext );
extern void Rend2Reg_STIPPLEPATTERN12( LPATID3DCNTX pContext );
extern void Rend2Reg_STIPPLEPATTERN13( LPATID3DCNTX pContext );
extern void Rend2Reg_STIPPLEPATTERN14( LPATID3DCNTX pContext );
extern void Rend2Reg_STIPPLEPATTERN15( LPATID3DCNTX pContext );
extern void Rend2Reg_STIPPLEPATTERN16( LPATID3DCNTX pContext );
extern void Rend2Reg_STIPPLEPATTERN17( LPATID3DCNTX pContext );
extern void Rend2Reg_STIPPLEPATTERN18( LPATID3DCNTX pContext );
extern void Rend2Reg_STIPPLEPATTERN19( LPATID3DCNTX pContext );
extern void Rend2Reg_STIPPLEPATTERN20( LPATID3DCNTX pContext );
extern void Rend2Reg_STIPPLEPATTERN21( LPATID3DCNTX pContext );
extern void Rend2Reg_STIPPLEPATTERN22( LPATID3DCNTX pContext );
extern void Rend2Reg_STIPPLEPATTERN23( LPATID3DCNTX pContext );
extern void Rend2Reg_STIPPLEPATTERN24( LPATID3DCNTX pContext );
extern void Rend2Reg_STIPPLEPATTERN25( LPATID3DCNTX pContext );
extern void Rend2Reg_STIPPLEPATTERN26( LPATID3DCNTX pContext );
extern void Rend2Reg_STIPPLEPATTERN27( LPATID3DCNTX pContext );
extern void Rend2Reg_STIPPLEPATTERN28( LPATID3DCNTX pContext );
extern void Rend2Reg_STIPPLEPATTERN29( LPATID3DCNTX pContext );
extern void Rend2Reg_STIPPLEPATTERN30( LPATID3DCNTX pContext );
extern void Rend2Reg_STIPPLEPATTERN31( LPATID3DCNTX pContext );
extern void Rend2Reg_WRAP0( LPATID3DCNTX pContext );
extern void Rend2Reg_WRAP1( LPATID3DCNTX pContext );
extern void Rend2Reg_WRAP2( LPATID3DCNTX pContext );
extern void Rend2Reg_WRAP3( LPATID3DCNTX pContext );
extern void Rend2Reg_WRAP4( LPATID3DCNTX pContext );
extern void Rend2Reg_WRAP5( LPATID3DCNTX pContext );
extern void Rend2Reg_WRAP6( LPATID3DCNTX pContext );
extern void Rend2Reg_WRAP7( LPATID3DCNTX pContext );
extern void Rend2Reg_LIGHTING( LPATID3DCNTX pContext );
extern void Rend2Reg_EXTENTS( LPATID3DCNTX pContext );
extern void Rend2Reg_AMBIENT( LPATID3DCNTX pContext );
extern void Rend2Reg_FOGVERTEXMODE( LPATID3DCNTX pContext );
extern void Rend2Reg_COLORVERTEX( LPATID3DCNTX pContext );
extern void Rend2Reg_LOCALVIEWER( LPATID3DCNTX pContext );
extern void Rend2Reg_NORMALIZENORMALS( LPATID3DCNTX pContext );
extern void Rend2Reg_COLORKEYBLENDENABLE( LPATID3DCNTX pContext );
extern void Rend2Reg_DIFFUSEMATERIALSOURCE( LPATID3DCNTX pContext );
extern void Rend2Reg_SPECULARMATERIALSOURCE( LPATID3DCNTX pContext );
extern void Rend2Reg_AMBIENTMATERIALSOURCE( LPATID3DCNTX pContext );
extern void Rend2Reg_EMISSIVEMATERIALSOURCE( LPATID3DCNTX pContext );
extern void Rend2Reg_VERTEXBLEND( LPATID3DCNTX pContext );
extern void Rend2Reg_CLIPPLANEENABLE( LPATID3DCNTX pContext );
extern void Rend2Reg_CLIPPING( LPATID3DCNTX pContext );

extern void Rend2Reg_SOFTWAREVERTEXPROCESSING( LPATID3DCNTX pContext );
extern void Rend2Reg_POINTSIZE( LPATID3DCNTX pContext );
extern void Rend2Reg_POINTSIZE_MIN( LPATID3DCNTX pContext );
extern void Rend2Reg_POINTSPRITEENABLE( LPATID3DCNTX pContext );
extern void Rend2Reg_POINTSCALEENABLE( LPATID3DCNTX pContext );
extern void Rend2Reg_POINTSCALE_A( LPATID3DCNTX pContext );
extern void Rend2Reg_POINTSCALE_B( LPATID3DCNTX pContext );
extern void Rend2Reg_POINTSCALE_C( LPATID3DCNTX pContext );
extern void Rend2Reg_MULTISAMPLEANTIALIAS( LPATID3DCNTX pContext );
extern void Rend2Reg_MULTISAMPLEMASK( LPATID3DCNTX pContext );
extern void Rend2Reg_PATCHEDGESTYLE( LPATID3DCNTX pContext );
extern void Rend2Reg_PATCHSEGMENTS( LPATID3DCNTX pContext );
extern void Rend2Reg_POINTSIZE_MAX( LPATID3DCNTX pContext );
extern void Rend2Reg_COLORWRITEENABLE( LPATID3DCNTX pContext );
extern void Rend2Reg_INDEXEDVERTEXBLENDENABLE( LPATID3DCNTX pContext );
extern void Rend2Reg_DELETERTPATCH( LPATID3DCNTX pContext );
extern void Rend2Reg_TWEENFACTOR( LPATID3DCNTX pContext );
extern void Rend2Reg_BLENDOP( LPATID3DCNTX pContext );
extern void Rend2Reg_POSITIONORDER( LPATID3DCNTX pContext );
extern void Rend2Reg_NORMALORDER( LPATID3DCNTX pContext );
#if(DIRECT3D_VERSION >= 0x0900)
extern void Rend2Reg_SCISSORTESTENABLE( LPATID3DCNTX pContext );
extern void Rend2Reg_SLOPESCALEDEPTHBIAS( LPATID3DCNTX pContext );
extern void Rend2Reg_ANTIALIASEDLINEENABLE( LPATID3DCNTX pContext );
extern void Rend2Reg_ANTIALIASEDLINEWIDTH( LPATID3DCNTX pContext );
extern void Rend2Reg_ANTIALIASEDLINEWIDTH( LPATID3DCNTX pContext );
extern void Rend2Reg_BLENDFACTOR( LPATID3DCNTX pContext );
extern void Rend2Reg_DEPTHBIAS( LPATID3DCNTX pContext );

extern void Rend2Reg_SEPARATEALPHABLENDENABLE( LPATID3DCNTX pContext );
extern void Rend2Reg_SRCBLENDALPHA( LPATID3DCNTX pContext );
extern void Rend2Reg_DESTBLENDALPHA( LPATID3DCNTX pContext );
extern void Rend2Reg_BLENDOPALPHA( LPATID3DCNTX pContext );
extern DWORD GetNumSampleForDX9( LPATISURFCNTX lpRTSurfCntx, LPATID3DCNTX pContext );
#endif//(DIRECT3D_VERSION >= 0x0900)

extern void SpecularEnableUpdate( LPATID3DCNTX pContext,
                                  DWORD dwSpecularEnable );

void TextureFactorUpdate(LPATID3DCNTX pContext, DWORD dwTexFactorNum,
                         DWORD dwTexFactorValue);

extern VOIDFUNC SetTexFilter[];

extern VOIDFUNC SetTexFilter_WrapUVW[];

extern HRESULT ClearRenderTarget( LPATID3DCNTX pContext, DWORD dwFlags, DWORD dwFillColor,
                               DWORD dwNumRects, LPRECTL lpRects );

extern void ProcColorWriteEnable(LPATID3DCNTX pContext, LPATISURFCNTX lpRenderContext);

#endif   // D3DCNTX_H_


