

/*****************************************************************************\
* 
*  Module Name    rv200f.h
*  Project        Rage5 WindowsNT
*  Device         Rage
*
*  Description    header file for Rage driver
*  
*
*  (c) 1998-2001 ATI Technologies Inc. (unpublished)
*
*	 All rights reserved.
*	 The year included in the foregoing notice is the year of creation of the work.
*
\*****************************************************************************/

#ifndef _RV200F_H
#define _RV200F_H
 

// Fields for TV_DAC_CNTL register. Needed for 2nd CRT support
#define TV_DAC_CNTL__RV200_BGADJ_DACADJ_DEFAULT__HDTV             0x00580000
#define TV_DAC_CNTL__RV200_BGADJ_DACADJ_DEFAULT__NTSC             0x00680000
#define TV_DAC_CNTL__RV200_BGADJ_DACADJ_DEFAULT__PAL              0x00680000
#define TV_DAC_CNTL__RV200_BGADJ_DACADJ_DEFAULT__PS2              0x00880000

#endif /* end _RV200F_H */

