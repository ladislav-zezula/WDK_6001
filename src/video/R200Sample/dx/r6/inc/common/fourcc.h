

//    
//  $Workfile: fourcc.h $
//
//  Description:
//
//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999-2002, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//

#ifndef _FOURCC_H
#define _FOURCC_H


#ifndef MAKE_FOURCC 
#define MAKE_FOURCC( ch0, ch1, ch2, ch3 )                       \
        ( (DWORD)(BYTE)(ch0) | ( (DWORD)(BYTE)(ch1) << 8 ) |    \
        ( (DWORD)(BYTE)(ch2) << 16 ) | ( (DWORD)(BYTE)(ch3) << 24 ) )
#endif

#define FOURCC_YUY2  MAKE_FOURCC('Y','U','Y','2')
#define FOURCC_UYVY  MAKE_FOURCC('U','Y','V','Y')
#define FOURCC_YV12  MAKE_FOURCC('Y','V','1','2')
#define FOURCC_YUV12 FOURCC_YV12
#define FOURCC_YVU9  MAKE_FOURCC('Y','V','U','9')
#define FOURCC_IF09  MAKE_FOURCC('I','F','0','9')
#define FOURCC_IMC4  MAKE_FOURCC('I','M','C','4')
#define FOURCC_IYUV  MAKE_FOURCC('I','Y','U','V')
#define FOURCC_M2IA  MAKE_FOURCC('M','2','I','A')
#define FOURCC_M2AM  MAKE_FOURCC('M','2','A','M')
#define FOURCC_AYUV  MAKE_FOURCC('A','Y','U','V')
#define FOURCC_XENC  MAKE_FOURCC('X','E','N','C')
//Microsoft specific format for WebTV
#define FOURCC_VBID  MAKE_FOURCC('V','B','I','D')
#define FOURCC_MCAM  MAKE_FOURCC('M','C','A','M')
#define FOURCC_MC12  MAKE_FOURCC('M','C','1','2')
#define FOURCC_MCR4  MAKE_FOURCC('M','C','R','4')

#endif // _FOURCC_H


