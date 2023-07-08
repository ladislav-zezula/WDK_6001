!INCLUDE ..\..\SOURCES.INC

TARGETTYPE=DYNLINK

LINKER_FLAGS=-map

SYNCHRONIZE_DRAIN = 1

C_DEFINES=$(C_DEFINES) \
    -DWIN2K                     \
    -DDX8                       \
    -DDIRECT3D_VERSION=0x0900   \
    -DDIRECTDRAW_VERSION=0x0900 \
    -DWHISTLER_DDK              \
    -DDECLSPEC_DEPRECATED_DDK=  \
    -DUSE_ATI_STATS             \
    -DRADEONDLL                 \
    -DR200                      \
    -DUMD                       \
    -DDDIDX10_XP                \
    -DLHVIDMM                   \
    -DDXGKERNEL                 \
    -DVBRENAMING                \


# Include R200 specific headers
INCLUDES=\
    $(INCLUDES);                   \
    ..\..\dx\r6\inc\emu;              \
    ..\..\dx\r6\inc\common;           \
    ..\..\dx\r6\direct3d\inc;         \
    ..\..\dx\r6\inc\radeon;           \
    ..\..\dx\r6\inc\pm4;              \
    ..\..\dx\r6\directdraw\inc;       \
    ..\..\inc\asic_reg;               \
    ..\..\cmmqs\inc;                  \
    ..\..\dx\r6\inc\radeon\radeon2;   \

# Export the interface functions

DLLDEF=..\r2d3dum.def

#
# The _DllMainCRTStartup() for MSVCRT.DLL doesn't set FP state
#
USE_MSVCRT=1

SOURCES=$(SOURCES)  \
    ..\ati3ddll.rc     \
    ..\contextthk.c    \
    ..\d3dddithk.c     \
    ..\d3dumode.cpp    \
    ..\dxva.cpp        \

TARGETLIBS=$(TARGETLIBS) \
    $(SDK_LIB_PATH)\kernel32.lib                         \
    $(SDK_LIB_PATH)\gdi32.lib                            \
    $(SDK_LIB_PATH)\advapi32.lib                         \
    $(SDK_LIB_PATH)\dxguid.lib

DLLENTRY=_DllMainCRTStartup


TARGET_DESTINATION=retail
