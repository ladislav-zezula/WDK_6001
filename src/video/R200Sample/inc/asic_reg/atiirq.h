

/*^^*
* File:		ATIIRQ.H
*
* Notes:	This file is provided under strict non-disclosure agreements
*			it is and remains the property of ATI Technologies Inc.
*			Any use of this file or the information it contains to
*			develop products commercial or otherwise must be with the
*			permission of ATI Technologies Inc.
*
* Copyright (C) 1998-2000, ATI Technologies Inc.
*^^*/

#ifndef _ATIIRQ_H_
#define _ATIIRQ_H_


#include "atiirqbm.h"


/***********************************************************************************************
 * Defines & Structures
 ***********************************************************************************************/


// IRQ Commands
enum {
	IRQ_COMMAND_ENABLE_IRQ_SOURCE = 1,
	IRQ_COMMAND_DISABLE_IRQ_SOURCE,
	IRQ_COMMAND_QUERY,			// Keep the QUERY commands together please
	IRQ_COMMAND_QUERY_SET1,
	IRQ_COMMAND_QUERY_SET2,
	IRQ_COMMAND_QUERY_SET3,
	IRQ_COMMAND_QUERY_SET4,
	IRQ_COMMAND_QUERY_SET5,
	IRQ_COMMAND_QUERY_SET6,
	IRQ_COMMAND_QUERY_SET7
};

// IRQ Flags
#define	IRQ_FLAG_CALLBACK_DIRECT			0x00000001
#define	IRQ_FLAG_CALLBACK_EVENT				0x00000002
#define IRQ_FLAG_CALLBACK_BOTH	            0x00000003	//fv-Apr02-additional OTM mode
#define IRQ_FLAG_CALLBACK_UNKNOWN           0x000000FF
#define NUM_CB_METHOD_TYPES			2	//the number of CallbackMethod types: Direct & Event


// PLEUNG 01NOV00 Please note that each set must be filled before we move on to the next because of how
// things are initially structured.  It maybe refacotred without affecting clients but it is non-trivial.
#define NUM_IRQ_SETS			2
#define NUM_IRQ_SOURCE_BITS		29
#define NUM_IRQ_SOURCES			50


typedef struct tag_IRQCallbackInfo
{
    DWORD       dwIRQSource;
    DWORD       dwIRQCounter;
    DWORD_PTR   dwIRQEnableId;
    
} IRQCALLBACKINFO, * PIRQCALLBACKINFO;

typedef void ( STDMETHODCALLTYPE * IRQCALLBACK)( DWORD_PTR dwClientContext, PIRQCALLBACKINFO pIRQCallbackInfo);


typedef DWORD * IRQSOURCE;

typedef struct tag_IRQControl
{
	DWORD		nCommand;
    DWORD_PTR   dwIRQEnableId;
	DWORD		dwStatus;
	union {
		DWORD		dwIRQSource;
		DWORD		nIRQIndex;
	};
	DWORD		dwFlags;
	IRQCALLBACK	pfnCallback;
	DWORD_PTR	dwClientContext;

} IRQControl, * PIRQControl;



#define IRQ_CAP_CAP0_SOURCES				( IRQ_MASK_CAP0_BUF0			|	\
											  IRQ_MASK_CAP0_BUF0_EVEN		|	\
                                              IRQ_MASK_CAP0_BUF1			|	\
                                              IRQ_MASK_CAP0_BUF1_EVEN		|	\
                                              IRQ_MASK_CAP0_VBI0			|	\
                                              IRQ_MASK_CAP0_VBI1			|	\
                                              IRQ_MASK_CAP0_ONESHOT			|	\
											  IRQ_MASK_CAP0_ANC0			|	\
											  IRQ_MASK_CAP0_ANC1)
#if !NO_HW_CAP1
#define IRQ_CAP_CAP1_SOURCES				( IRQ_MASK_CAP1_BUF0			|	\
											  IRQ_MASK_CAP1_BUF0_EVEN		|	\
                                              IRQ_MASK_CAP1_BUF1			|	\
                                              IRQ_MASK_CAP1_BUF1_EVEN		|	\
                                              IRQ_MASK_CAP1_VBI0			|	\
                                              IRQ_MASK_CAP1_VBI1			|	\
                                              IRQ_MASK_CAP1_ONESHOT			|	\
											  IRQ_MASK_CAP1_ANC0			|	\
											  IRQ_MASK_CAP1_ANC1)
#endif

// IRQ Status                           	
enum
{
	IRQ_STATUS_NOERROR = 0,
	IRQ_STATUS_ERROR,						// 1
	IRQ_STATUS_IRQ_NOT_ENABLED,				// 2
	IRQ_STATUS_IRQ_SOURCE_NOTSUPPORTED,		// 3
	IRQ_STATUS_IRQ_SOURCE_LIST_FULL,		// 4
	IRQ_STATUS_CALLBACK_NOTDEFINED,			// 5
	IRQ_STATUS_IRQ_SOURCE_INVALID,			// 6
	IRQ_STATUS_IRQ_SET_INVALID,				// 7
	IRQ_STATUS_SERVICE_DISABLED,			// 8
};

// Flags                           	
#define	IRQ_FLAG_FIELD_POLARITY			0x00000001

//fv-New Control structure for new IRQ support
typedef struct tag_IRQControl2
{
    //INPUT-members the client will set and then access the interface
	DWORD       dwSize;			//size of structure
	DWORD		dwIRQClient;	//the type of client
	DWORD		nCommand;		//indicate Query,Enable/Disable IRQ, Register/UnRegister client's callbacks
								//There can only be one command per client request
    
	union{
		DWORD	dwIRQSource;	//dwIRQSource: the requested IRQSoruce in bitmask form, is set by the client
		DWORD	nIRQIndex;		// NOTE: During some intermediate processing within IRQAccess2, nIRQIndex may
		};						// hold the IRQSource as an integer value; i.e from 0 to NUM_IRQ_SOURCES
								// Then the value will be refered at as nIRQIndex 
								// But it should have its original bitmask written back to dwIRQSource
								// Before returning control to the client								
	
	DWORD		dwServingStyle;	//when to call the callback when rec'v IRQ:OnEachIRQ, Serial, Single
	DWORD		dwInitialPriority;  //High,Med,Low priority indicates the order the callback fcns called for the same IRQ
	DWORD		dwCallbackMethod;	//Direct or Event (or both); Direct called in the ISR, Event are queue for DPC
	IRQCALLBACK	pfnCallbackDirect;	//ptr to the Direct Callback
	IRQCALLBACK	pfnCallbackEvent;	//ptr to the Event Callback

    DWORD_PTR   dwClientContext;	//data passed to the client on each callback

	//OUTPUT-members that the interface (IRQAccess2) will return to client
	DWORD       dwStatus;		//the result of the command
	DWORD		dwIRQEnableId;	//unique ID returned when callback registered
								// but if CallbackMethod is BOTH, the EnableID is the same
								// for both Direct and Event type callbacks
    
} IRQControl2, * PIRQControl2;

//Clients that can register using IRQAccess2
#define	IRQ_CLIENT_I2C_PROVIDER			0x00000001
#define	IRQ_CLIENT_GPIO_PROVIDER		0x00000002
#define	IRQ_CLIENT_BM_PROVIDER			0x00000004
#define	IRQ_CLIENT_MPP_PROVIDER			0x00000008
#define	IRQ_CLIENT_VIP_PROVIDER			0x00000010
#define	IRQ_CLIENT_WDM_DRIVER			0x00000020
#define	IRQ_CLIENT_NON_WDM_DRIVER		0x00000040
#define	IRQ_CLIENT_RING3_IRQ_MANAGER	0x00000080

//IRQ Serving Styles
#define	IRQ_SERVED_ON_EACH_INT          0x00000001	//callback each IRQ
#define	IRQ_SINGLE_SUBMIT               0x00000002	//callback on first IRQ only, and remove from callback list
#define	IRQ_SERIAL_SUBMIT               0x00000003	//callback on first IRQ only, and remove from callback list
#define	IRQ_UNKNOWN_SERVING_STYLE       0x000000FF	

//Client callback inital priorities
#define	IRQ_LOW		0x00000001
#define	IRQ_MED		0x00000002
#define	IRQ_HIGH	0x00000003
#define	IRQ_UNKOWN	0x000000FF


#endif	// _ATIIRQ_H_


