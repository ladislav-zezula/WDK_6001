TARGETNAME=i8042prt
TARGETTYPE=DRIVER

#Disable deprecated function usage warnings
C_DEFINES=$(C_DEFINES) /wd4996

INCLUDES=..\inc;..\..\inc

W32_SB=1

SOURCES=..\i8042log.mc \
        ..\i8042prt.rc \
        ..\i8042cmn.c  \
        ..\i8042dep.c  \
        ..\i8042str.c  \
        ..\kbdcmn.c    \
        ..\kbddep.c    \
        ..\kbdpnp.c    \
        ..\moucmn.c    \
        ..\moudep.c    \
        ..\moupnp.c    \
        ..\pnp.c       \
        ..\sysbtn.c    \
        ..\wmi.c       \
        ..\hook.c

