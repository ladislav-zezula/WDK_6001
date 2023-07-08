#ifndef DX95TYPE2_H_
#define DX95TYPE2_H_

#ifndef NODX95TYPES
#ifdef WINNT

// Win2K uses DDSCAPS_VERTEXBUFFER and DDSCAPS_COMMANDBUFFER. 
// But here we use the Win9x defines for those two caps because
// 1) DDSCAPS_VERTEXBUFFER is defined as DDSCAPS_RESERVED4 and DDSCAPS_RESERVED4 is undefined;
// 2) it's unclear whether we should check DDSCAPS for those flags under Win2K.
#ifdef DDSCAPS2_VERTEXBUFFER
#undef DDSCAPS2_VERTEXBUFFER
#endif

#ifdef DDSCAPS2_COMMANDBUFFER
#undef DDSCAPS2_COMMANDBUFFER
#endif

#ifdef DDSCAPS2_INDEXBUFFER
#undef DDSCAPS2_INDEXBUFFER
#endif

#define DDSCAPS2_VERTEXBUFFER                   DDSCAPS2_RESERVED1
#define DDSCAPS2_COMMANDBUFFER                  DDSCAPS2_RESERVED2
#define DDSCAPS2_INDEXBUFFER                    DDSCAPS2_RESERVED3

typedef DD_SURFACE_LOCAL                DDRAWI_DDRAWSURFACE_LCL;
typedef DD_SURFACE_MORE                 DDRAWI_DDRAWSURFACE_MORE;
typedef DD_SURFACE_GLOBAL               DDRAWI_DDRAWSURFACE_GBL;
typedef DD_DIRECTDRAW_GLOBAL            DDRAWI_DIRECTDRAW_GBL;
typedef DD_ATTACHLIST                   ATTACHLIST;
typedef PDD_DIRECTDRAW_LOCAL            LPDDRAWI_DIRECTDRAW_LCL;
typedef DD_DIRECTDRAW_LOCAL             DDRAWI_DIRECTDRAW_LCL;

typedef DD_MORESURFACECAPS              DDMORESURFACECAPS;
typedef DD_VIDEOPORT_LOCAL              DDRAWI_DDVIDEOPORT_LCL;
typedef PDD_VIDEOPORT_LOCAL             LPDDRAWI_DDVIDEOPORT_LCL;

typedef DD_SURFACE_INT                  DDRAWI_DDRAWSURFACE_INT;
typedef PDD_SURFACE_INT                 LPDDRAWI_DDRAWSURFACE_INT;

typedef DD_MISCELLANEOUSCALLBACKS       DDHAL_DDMISCELLANEOUSCALLBACKS;
typedef PDD_MISCELLANEOUSCALLBACKS      LPDDHAL_DDMISCELLANEOUSCALLBACKS;
typedef DD_NONLOCALVIDMEMCAPS           DDNONLOCALVIDMEMCAPS;
typedef PDD_NONLOCALVIDMEMCAPS          LPDDNONLOCALVIDMEMCAPS;

//#if(DIRECT3D_VERSION >= 0x0800)

// DDSCAPS2_VERTEXBUFFER and  D3DFORMAT_OP_XXX stuff is defined in
// ddrawi.h but not ddrawint.h.
/*
 * This DDPF flag is used to indicate a DX8+ format capability entry in
 * the texture format list. It is not visible to applications.
 */
#define DDPF_D3DFORMAT                                          0x00200000l

/*
 * List of operations supported on formats in DX8+ texture list.
 * See the DX8 DDK for a complete description of these flags.
 */
#define D3DFORMAT_OP_TEXTURE                    0x00000001L
#define D3DFORMAT_OP_VOLUMETEXTURE              0x00000002L
#define D3DFORMAT_OP_CUBETEXTURE                0x00000004L
#define D3DFORMAT_OP_OFFSCREEN_RENDERTARGET     0x00000008L
#define D3DFORMAT_OP_SAME_FORMAT_RENDERTARGET   0x00000010L
#define D3DFORMAT_OP_BACKBUFFER                 0x00000020L
#define D3DFORMAT_OP_ZSTENCIL                   0x00000040L

#define MAX_DRIVER_NAME     CCHDEVICENAME

#define D3D_MAXRENDERSTATES 171
/*#else

#ifdef D3DHAL_TSS_MAXSTAGES
#undef D3DHAL_TSS_MAXSTAGES
#endif
#define D3DHAL_TSS_MAXSTAGES D3DNTHAL_TSS_MAXSTAGES 

typedef D3DNTHAL_DP2TEXTURESTAGESTATE   *LPD3DHAL_DP2TEXTURESTAGESTATE;
typedef D3DNTHAL_D3DEXTENDEDCAPS        D3DHAL_D3DEXTENDEDCAPS;

typedef LPD3DNTHAL_DP2VIEWPORTINFO      LPD3DHAL_DP2VIEWPORTINFO;
typedef LPD3DNTHAL_DP2WINFO             LPD3DHAL_DP2WINFO;
typedef LPD3DNTHAL_DP2ZRANGE            LPD3DHAL_DP2ZRANGE;
typedef LPD3DNTHAL_DP2SETTRANSFORM      LPD3DHAL_DP2SETTRANSFORM;
typedef LPD3DNTHAL_DP2SETMATERIAL       LPD3DHAL_DP2SETMATERIAL;
typedef LPD3DNTHAL_DP2CREATELIGHT       LPD3DHAL_DP2CREATELIGHT;
typedef LPD3DNTHAL_DP2SETLIGHT          LPD3DHAL_DP2SETLIGHT;
typedef LPD3DNTHAL_DP2SETCLIPPLANE      LPD3DHAL_DP2SETCLIPPLANE;
typedef LPD3DNTHAL_DP2TEXBLT            LPD3DHAL_DP2TEXBLT;
typedef LPD3DNTHAL_DP2STATESET          LPD3DHAL_DP2STATESET;
typedef LPD3DNTHAL_DP2SETPRIORITY       LPD3DHAL_DP2SETPRIORITY;
typedef LPD3DNTHAL_DP2SETRENDERTARGET   LPD3DHAL_DP2SETRENDERTARGET;
typedef LPD3DNTHAL_DP2CLEAR             LPD3DHAL_DP2CLEAR;

#define D3DHAL_SETLIGHT_ENABLE   0
#define D3DHAL_SETLIGHT_DISABLE  1
#define D3DHAL_SETLIGHT_DATA     2

typedef D3DNTHAL_DP2RENDERSTATE         *LPD3DHAL_DP2RENDERSTATE;

#define D3DTSS_TCI_PASSTHRU                             0x00000000
#define D3DTSS_TCI_CAMERASPACEREFLECTIONVECTOR          0x00030000

#endif // DIRECT3D_VERSION < 0x0800*/

#define DDHAL_EXEBUFCB32_CANCREATEEXEBUF    0x00000001l
#define DDHAL_EXEBUFCB32_CREATEEXEBUF       0x00000002l
#define DDHAL_EXEBUFCB32_DESTROYEXEBUF      0x00000004l
#define DDHAL_EXEBUFCB32_LOCKEXEBUF         0x00000008l
#define DDHAL_EXEBUFCB32_UNLOCKEXEBUF       0x00000010l

#define BORG_EXEBUFFER_CAPS     ( DDHAL_EXEBUFCB32_CANCREATEEXEBUF | \
                                  DDHAL_EXEBUFCB32_CREATEEXEBUF    | \
                                  DDHAL_EXEBUFCB32_DESTROYEXEBUF   | \
                                  DDHAL_EXEBUFCB32_LOCKEXEBUF      | \
                                  DDHAL_EXEBUFCB32_UNLOCKEXEBUF \
                                )

#endif //WINNT
#endif //NODX95TYPES

#endif //DX95TYPE2_H
