

/****************************************************************************\
*
*  Module Name    cwddeqc.h
*  Project        CWDDE QC (Queue Server & Central Memory Manager)
*
*
*  Important Notice
*
*  This header file is part of the Continuus project "asic_reg"
*  in the "wdal" database and is DCM'ed to other receiving databases.
*  Any modifications to this file must be made at the source project,
*  namely "asic_reg" in the "wdal", and must be accompanied with proper
*  documentation revision with "QS.DOC" and "CMM.DOC" in the same project.
*  Any such modifications are subject to the usual review process.
*
*
*  Description    ExtEscape function support is based on ATI's unique
*                 control code 0x7306 with a unified input parameter
*                 structure CWDDECMD as defined in this header file.
*                 The Escape32 defines a number of sub functions, which
*                 are grouped based on the following feature sets:
*
*                 Feature Group                  Sub Function Code
*                 CWDDE 32 - Configuration       0x0001XXXX
*                 CWDDE 32 - Rom Query           0x0002XXXX
*                 CWDDE 32 - Deskscan            0x0003XXXX
*                 CWDDE 32 - DPMS                0x0004XXXX
*                 CWDDE 32 - Gamma               0x0005XXXX
*                 CWDDE 32 - Display Mode        0x0006XXXX
*                 CWDDE 32 - Switches            0x0007XXXX
*                 CWDDE 32 - Screen Ajustment    0x0008XXXX
*                 CWDDE 32 - DCI                 0x0009XXXX
*                 CWDDE 32 - TV Out              0x000AXXXX
*                 CWDDE 32 - LCD                 0x000BXXXX
*                 CWDDE 32 - DDGamma             0x000CXXXX
*                 CWDDE DI - Adapter Routines    0x0011XXXX
*                 CWDDE DI - Controller Routines 0x0012XXXX
*                 CWDDE DI - Display Routines    0x0013XXXX
*                 CWDDE MM - Multimedia Routines 0x0014XXXX
*                 CWDDE HK - Hot Key Routines    0x0020XXXX
*                 CWDDE CI - Component Routines  0x0040XXXX
*                 CWDDE QC - Queue Server & Central
*                            Memory Manager      0x0060XXXX
*
*
*  Copyright (c) 1997-2001 ATI Technologies Inc. (unpublished)
*
*  All rights reserved.
*  The year included in the foregoing notice is the year of creation of the work.
*
*
*  LOG OF CHANGES
*  Version: 1.0   14/03/01 [randre]
*
*
\****************************************************************************/

#ifndef _CWDDEQC_H_
#define _CWDDEQC_H_

#pragma pack(1)

#ifdef _H2INC
#ifndef ULONG 
typedef unsigned long ULONG;
#endif

#ifndef PVOID 
typedef void * PVOID;
#endif

#ifndef CHAR
typedef char CHAR;
#endif

#ifndef USHORT 
typedef unsigned short USHORT;
#endif
#endif

/****************************************************************************\
* CWDDE defines
\****************************************************************************/

#ifndef Control_Config_CWDDE32
#define Control_Config_CWDDE32                  0x07306
#endif

#define CWDDEQC_VERSION_MAJOR                   0x00000001
#define CWDDEQC_VERSION_MINOR                   0x00000000

#define CWDDEQC_VERSION (((ULONG)CWDDEQC_VERSION_MAJOR<<16) | CWDDEQC_VERSION_MINOR)


/****************************************************************************\
* CWDDE Sub Functions
\****************************************************************************/

#define CWDDEQC_SUPPORTED                       0x00600001
#define CWDDEQC_GETVERSION                      0x00600002

#define CWDDEQC_QSINIT                          0x00600300
#define CWDDEQC_QSALLOCLIST                     0x00600301
#define CWDDEQC_QSFREELIST                      0x00600302
#define CWDDEQC_QSSUBMITLIST                    0x00600303
#define CWDDEQC_QSTSELAPSED                     0x00600304
#define CWDDEQC_QSTSCONSUMED                    0x00600305
#define CWDDEQC_QSTSRETIRED                     0x00600306
#define CWDDEQC_QSQUERYCAPS                     0x00600307
#define CWDDEQC_QSREGISTERCLIENT                0x00600308
#define CWDDEQC_QSUNREGISTERCLIENT              0x00600309
#define CWDDEQC_QSEXIT                          0x0060030A
#define CWDDEQC_QSSYNCHRONIZE                   0x0060030B
#define CWDDEQC_QSREGISTERHWND                  0x0060030C
#define CWDDEQC_QSUNREGISTERHWD                 0x0060030D
#define CWDDEQC_QSDEBUG                         0x0060030E
#define CWDDEQC_QSGETSCRATCHREGISTERS           0x0060030F
#define CWDDEQC_QSQUERYANDSETSTATE              0x00600310

#define CWDDEQC_CMMREGISTERCLIENT               0x00600400
#define CWDDEQC_CMMUNREGISTERCLIENT             0x00600401
#define CWDDEQC_CMMALLOCSURFACE                 0x00600402
#define CWDDEQC_CMMFREESURFACE                  0x00600403
#define CWDDEQC_CMMQUERYSURFACEINFO             0x00600404
#define CWDDEQC_CMMALLOCCACHE                   0x00600405
#define CWDDEQC_CMMRECOVERSURFACE               0x00600406
#define CWDDEQC_CMMSETAPERTURE                  0x00600407
#define CWDDEQC_CMMFREEAPERTURE                 0x00600408
#define CWDDEQC_CMMGETGENERALINFO               0x00600409
#define CWDDEQC_CMMDEBUG                        0x0060040A
#define CWDDEQC_CMMLOCKMEMORY                   0x0060040B
#define CWDDEQC_CMMUNLOCKMEMORY                 0x0060040C
#define CWDDEQC_CMMFREECACHE                    0x0060040D
#define CWDDEQC_CMMGETPOOLINFO                  0x0060040E
#define CWDDEQC_CMMASSIGNRESOURCE               0x0060040F
#define CWDDEQC_CMMRELEASERESOURCE              0x00600410

/****************************************************************************\
* CWDDEQC Return Codes
\****************************************************************************/

#define CWDDEQC_OK                                0x00000000
#define CWDDEQC_ERROR                             0x00000001
#define CWDDEQC_NOTSUPPORTED                      0x00000002
#define CWDDEQC_ERR_BADINPUTSIZE                  0x00000003
#define CWDDEQC_ERR_BADOUTPUTSIZE                 0x00000004
#define CWDDEQC_ERR_BADINPUT                      0x00000005
#define CWDDEQC_ERR_BADOUTPUT                     0x00000006
#define CWDDEQC_NOTFOUND                          0x00000007

/****************************************************************************\
* CWDDE Structures
\****************************************************************************/

#ifndef _CWDDECMD_
#define _CWDDECMD_
typedef struct tagCWDDECMD
{
    // CWDDECMD structure.
    ULONG ulSize;// size of CWDDECMD
    ULONG ulEscape32;// 32 bit escape code
    ULONG ulIndex;// index
    ULONG ulDriverReserved;
}CWDDECMD;
#endif  /* _CWDDECMD_ */

/* The defines for the escapes used in OGL */
#define OPENGL_CMD      4352        /* for OpenGL ExtEscape */
#define OPENGL_GETINFO  4353        /* for OpenGL ExtEscape */
#define WNDOBJ_SETUP    4354        /* for live video ExtEscape */

#pragma pack()

#endif /*_CWDDEQC_H_ */

