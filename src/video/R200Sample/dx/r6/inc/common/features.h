

//    
//  $Workfile: features.h $
//
//  Description:
//  
//  Trade secret of ATI Technologies, Inc.
//  Copyright 2001, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//

#ifndef _FEATURES_H
#define _FEATURES_H


////////////////////////////////////////////////////////////////////////////////////
//  Asic Feature Flags                                                             // 
////////////////////////////////////////////////////////////////////////////////////
#define FEATURE_TCL                      0x00000001L
#define FEATURE_DUALCRTC                 0x00000008L
#define FEATURE_NPATCHES                 0x00000010L
#define FEATURE_RTPATCHES                0x00000020L
#define FEATURE_QUINTICRTPATCHES         0x00000040L
#define FEATURE_CLIPDISABLE              0x00000140L

#define FEATURE_HWPOINTSPRITES           0x00001000L

////////////////////////////////////////////////////////////////////////////////////
//  R200 Family Asic Feature Flags                                                             // 
////////////////////////////////////////////////////////////////////////////////////
#define FEATURE_3D2_RV250TxPitchRegs                                0x00010000L 	//RV250 pp_txpitch_x register is different.
#define FEATURE_3D2_A2W10V10U10andA2B10G10R10Support				0x00020000L    //RV250 and RV280 supports both D3DFMT_A2W10V10U10 and D3DFMT_A2B10G10R10.
#define FEATURE_3D2_WriteTFactorSignReg				                0x00040000L    //RV250 and RV280 need write extra registry mmPP_TFACTOR_SIGN.
#define FEATURE_3D2_HWSignedTFactor									0x00080000L	   //RV250 support HW signed TFactor
#define FEATURE_3D2_HWTessellation									0x00100000L		
#define FEATURE_3D2_SinglePipe									    0x00200000L		//RV250 has one pipe.
#endif // _FEATURES_H

