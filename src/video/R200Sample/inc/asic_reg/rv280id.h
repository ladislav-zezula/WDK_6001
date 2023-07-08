

/*****************************************************************************\
* 
*  Module Name    RV280ID.H
*  Project        Argus Windows
*  Device         argus
*
*  Description    Identifier file for Argus driver
*  
*
*  (c) 1999 - 2002 ATI Technologies Inc. (unpublished)
*
*	 All rights reserved.
*	 The year included in the foregoing notice is the year of creation of the work.
*
*  LOG OF CHANGES
*
*  1.0    08/09/2002  - initial revision
*
\*****************************************************************************/

#ifndef _RV280ID_H
#define _RV280ID_H

enum
{
    ARGUS_A11     = 1,
    ARGUS_A12     = 2,
	ARGUS_UNKNOWN = 0xFF
};

//
// Define Chip ID's for the Argus.
//
#define DEVICE_ID_ARGUS_5960     0x5960  // RV280 8X 1st Function
#define DEVICE_ID_ARGUS_5961     0x5961  // RV280LE 8X 1st Function
#define DEVICE_ID_ARGUS_5962     0x5962  // RV280LE 4X 1st Function
#define DEVICE_ID_ARGUS_5963     0x5963  // Unassigned
#define DEVICE_ID_ARGUS_5964     0x5964  // 9200SE 1st Function
#define DEVICE_ID_ARGUS_5968     0x5968  // Unassigned
#define DEVICE_ID_ARGUS_5969     0x5969  // Unassigned
#define DEVICE_ID_ARGUS_596A     0x596A  // Unassigned
#define DEVICE_ID_ARGUS_596B     0x596B  // Unassigned
#define DEVICE_ID_ARGUS_5940     0x5940  // RV280 8X 2nd Function
#define DEVICE_ID_ARGUS_5941     0x5941  // RV280LE 8X 2nd Function
#define DEVICE_ID_ARGUS_5942     0x5942  // RV280LE 4X 2nd Function

#define DEVICE_ID_ARGUS_5964     0x5964  // Unassigned
#define DEVICE_ID_ARGUS_5967     0x5967  // Unassigned
#define DEVICE_ID_ARGUS_596C     0x596C  // Unassigned
#define DEVICE_ID_ARGUS_596F     0x596F  // Unassigned

#define DEVICE_ID_ARGUS_5C60     0x5C60  // Unassigned
#define DEVICE_ID_ARGUS_5C68     0x5C68  // Unassigned

#define DEVICE_ID_ARGUS_5C61     0x5C61  // D9+, 8X 1st Function
#define DEVICE_ID_ARGUS_5C63     0x5C63  // M9+, 4X 1st Function (P, CSP32, CSP64)
#define DEVICE_ID_ARGUS_5C67     0x5C67  // M9+, 4X GL 1st Function (GL, CSP64GL)
#define DEVICE_ID_ARGUS_5C69     0x5C69  // Unassigned
#define DEVICE_ID_ARGUS_5C6B     0x5C6B  // Unassigned
#define DEVICE_ID_ARGUS_5C6F     0x5C6F  // Unassigned
#define DEVICE_ID_ARGUS_5C41     0x5C41  // D9+, 8X 2nd Function
#define DEVICE_ID_ARGUS_5C43     0x5C43  // M9+, 4X 2nd Function (P, CSP32, CSP64)
#define DEVICE_ID_ARGUS_5C47     0x5C47  // M9+, 4X GL 2nd Function (GL, CSP64GL)

#define DEVICE_ID_ARGUS_5D44     0x5D64  // 9200SE Secondary

//
// Define ATI's internal revision numbers.
//
#define INTERNAL_REV_ARGUS_A11   0x00    // Not used for ARGUS

//
// Define ATI's external revision numbers.
//
#define EXTERNAL_REV_ARGUS       0x00
#define EXTERNAL_REV_ARGUS_A12   0x01

//
// Define packaging options for RV280
//
//#define CONFIG_XSTRAP__PKGTYPE_LE                      0x0C
//#define CONFIG_XSTRAP__PKGTYPE_STD                     0x0E

#endif  // _RV280ID_H

