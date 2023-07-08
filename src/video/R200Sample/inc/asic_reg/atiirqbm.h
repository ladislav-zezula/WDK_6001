

/*^^*
* File:		ATIIRQBM.H
*
* Notes:	This file is provided under strict non-disclosure agreements
*			it is and remains the property of ATI Technologies Inc.
*			Any use of this file or the information it contains to
*			develop products commercial or otherwise must be with the
*			permission of ATI Technologies Inc.
*
* Copyright (C) 1998-2001, ATI Technologies Inc.
*^^*/

#ifndef _ATIIRQBM_H_
#define _ATIIRQBM_H_

/***********************************************************************************************
 * Defines & Structures
 ***********************************************************************************************/


// IRQ Sources:
//
//   31  29 28                                     0
//	+------+----------------------------------------+
//  | IRQ  |       IRQ Source bit Mask              |
//  | Set# |                                        |
//  +------+----------------------------------------+
//

#define IRQ_SET0		0x00000000	// 0000
#define IRQ_SET1		0x20000000	// 0010
#define IRQ_SET2		0x40000000	// 0100
#define IRQ_SET3		0x60000000	// 0110
#define IRQ_SET4		0x80000000	// 1000
#define IRQ_SET5		0xA0000000	// 1010
#define IRQ_SET6		0xC0000000  // 1100
#define IRQ_SET7		0xE0000000  // 1110


#define	IRQ_SOURCE_CRTC_VBLANK			0x00000001	// 0
#define	IRQ_SOURCE_CRTC_VLINE			0x00000002	// 1
#define	IRQ_SOURCE_SNAPSHOT				0x00000004	// 2
#define	IRQ_SOURCE_BUSMASTER_EOL		0x00000008	// 3
#define	IRQ_SOURCE_VIDDMA				IRQ_SOURCE_BUSMASTER_EOL
#define	IRQ_SOURCE_I2C					0x00000010	// 4
#define	IRQ_SOURCE_MPP_GP				0x00000020	// 5
#define	IRQ_SOURCE_GUI_IDLE				0x00000040	// 6
#define	IRQ_SOURCE_VIPH					0x00000080	// 7

#define	IRQ_SOURCE_CAP0_BUF0 			0x00000100	// 8
#define	IRQ_SOURCE_CAP0_BUF0_EVEN		0x00000200	// 9
#define	IRQ_SOURCE_CAP0_BUF1			0x00000400	// 10
#define	IRQ_SOURCE_CAP0_BUF1_EVEN		0x00000800	// 11
#define	IRQ_SOURCE_CAP0_VBI0		  	0x00001000	// 12
#define	IRQ_SOURCE_CAP0_VBI1		  	0x00002000	// 13
#define	IRQ_SOURCE_CAP0_ONESHOT		  	0x00004000	// 14
#define	IRQ_SOURCE_CAP0_ANC0		  	0x00008000	// 15

#define	IRQ_SOURCE_CAP0_ANC1	 	  	0x00010000	// 16
#define	IRQ_SOURCE_CAP1_BUF0 			0x00020000	// 17
#define	IRQ_SOURCE_CAP1_BUF0_EVEN		0x00040000	// 18
#define	IRQ_SOURCE_CAP1_BUF1			0x00080000	// 19
#define	IRQ_SOURCE_CAP1_BUF1_EVEN		0x00100000	// 20
#define	IRQ_SOURCE_CAP1_VBI0		  	0x00200000	// 21
#define	IRQ_SOURCE_CAP1_VBI1		  	0x00400000	// 22
#define	IRQ_SOURCE_CAP1_ONESHOT		  	0x00800000	// 23

#define	IRQ_SOURCE_CAP1_ANC0		  	0x01000000	// 24
#define	IRQ_SOURCE_CAP1_ANC1	 	  	0x02000000	// 25
#define	IRQ_SOURCE_OVERLAY_EOF	 	  	0x04000000	// 26
#define	IRQ_SOURCE_CRTC_VSYNC	 	  	0x08000000	// 27
#define	IRQ_SOURCE_FP_DETECT		 	0x10000000	// 28

#define	IRQ_SOURCE1_DMA_VIPH0               (IRQ_SET1 | 0x00000001)	// 0
#define	IRQ_SOURCE1_DMA_VIPH1               (IRQ_SET1 | 0x00000002)	// 1
#define	IRQ_SOURCE1_DMA_VIPH2               (IRQ_SET1 | 0x00000004)	// 2
#define	IRQ_SOURCE1_DMA_VIPH3               (IRQ_SET1 | 0x00000008)	// 3
#define	IRQ_SOURCE1_CAP0_VBI2               (IRQ_SET1 | 0x00000010)	// 4
#define	IRQ_SOURCE1_CAP0_VBI3               (IRQ_SET1 | 0x00000020)	// 5
#define	IRQ_SOURCE1_CAP0_ANC2               (IRQ_SET1 | 0x00000040)	// 6
#define	IRQ_SOURCE1_CAP0_ANC3               (IRQ_SET1 | 0x00000080)	// 7

#define IRQ_SOURCE1_CAP0_INT_ACTIVE         (IRQ_SET1 | 0x00000100)	// 8
#define IRQ_SOURCE1_GUIDMA                  (IRQ_SET1 | 0x00000200)	// 9
#define IRQ_SOURCE1_SW_INT                  (IRQ_SET1 | 0x00000400)	// 10

// PLEUNG 01NOV00 Let's put in all the CRTC2 and FP2 & Piglet interrupt sources
#define	IRQ_SOURCE1_CRTC2_VLINE             (IRQ_SET1 | 0x00000800)	// 11
#define	IRQ_SOURCE1_CRTC2_VSYNC             (IRQ_SET1 | 0x00001000)	// 12
#define	IRQ_SOURCE1_SNAPSHOT2               (IRQ_SET1 | 0x00002000)	// 13
#define	IRQ_SOURCE1_CRTC2_VBLANK            (IRQ_SET1 | 0x00004000)	// 14
#define	IRQ_SOURCE1_FP2_DETECT              (IRQ_SET1 | 0x00008000)	// 15
#define IRQ_SOURCE1_VSYNC_DIFF_OVER_LIMIT   (IRQ_SET1 | 0x00010000) // 16 PLEUNG don't know what this does
#define IRQ_SOURCE1_GEYSERVILLE             (IRQ_SET1 | 0x00020000) // 17 PLEUNG don't know what this does
#define IRQ_SOURCE1_HDCP_AUTHORIZED_INT     (IRQ_SET1 | 0x00040000) // 18 PLEUNG don't know what this does
#define IRQ_SOURCE1_DVI_I2C_INT             (IRQ_SET1 | 0x00080000) // 19 PLEUNG don't know what this does
// End of CRTC2 and FP2 interrupt sources

#define IRQ_SOURCE1_TIMER_INT               (IRQ_SET1 | 0x00100000) // 20

// IRQ_SOURCE1_CP_INT is used by R400. It's not in current irq source list
#define IRQ_SOURCE1_CP_INT                  (IRQ_SET1 | 0x00200000)	// 21

#define IRQ_SOURCE_MASK					0x1FFFFFFF
#define IRQ_SOURCE_SET_MASK				(^IRQ_SOURCE_MASK)  //0xE0000000
#define IRQ_SOURCE_SET_SHIFT				29  

#endif	// _ATIIRQBM_H_


