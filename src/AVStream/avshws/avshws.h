/**************************************************************************

    AVStream Simulated Hardware Sample

    Copyright (c) 2001, Microsoft Corporation.

    File:

        avshws.h

    Abstract:

        AVStream Simulated Hardware Sample header file.  This is the 
        main header.

    History:

        created 3/12/2001

**************************************************************************/

/*************************************************

    Standard Includes

*************************************************/

#ifndef _avshws_h_
#define _avshws_h_

extern "C" {
#include <wdm.h>
}

#include <windef.h>
#include <stdio.h>
#include <ntstrsafe.h>
#include <stdlib.h>
#include <windef.h>
#define NOBITMAP
#include <mmreg.h>
#undef NOBITMAP
#include <unknown.h>
#include <ks.h>
#include <ksmedia.h>
#include <kcom.h>

/*************************************************

    Misc Definitions

*************************************************/
#define STR_MODULENAME "avshws: "
#define DEBUGLVL_VERBOSE 2
#define DEBUGLVL_TERSE 1
#define DEBUGLVL_ERROR 0

const DebugLevel = DEBUGLVL_TERSE;

#if (DBG)
#define _DbgPrintF(lvl, strings) \
{ \
    if (lvl <= DebugLevel) {\
        DbgPrint(STR_MODULENAME);\
        DbgPrint##strings;\
        DbgPrint("\n");\
        if ((lvl) == DEBUGLVL_ERROR) {\
            DbgBreakPoint();\
        } \
    }\
}
#else // !DBG
   #define _DbgPrintF(lvl, strings)
#endif // !DBG

#define ABS(x) ((x) < 0 ? (-(x)) : (x))

#ifndef mmioFOURCC    
#define mmioFOURCC( ch0, ch1, ch2, ch3 )                \
        ( (DWORD)(BYTE)(ch0) | ( (DWORD)(BYTE)(ch1) << 8 ) |    \
        ( (DWORD)(BYTE)(ch2) << 16 ) | ( (DWORD)(BYTE)(ch3) << 24 ) )
#endif

#define FOURCC_YUY2         mmioFOURCC('Y', 'U', 'Y', '2')
//
// CAPTURE_PIN_DATA_RANGE_COUNT:
//
// The number of ranges supported on the capture pin.
//
#define CAPTURE_PIN_DATA_RANGE_COUNT 2

//
// CAPTURE_FILTER_PIN_COUNT:
//
// The number of pins on the capture filter.
//
#define CAPTURE_FILTER_PIN_COUNT 1

//
// CAPTURE_FILTER_CATEGORIES_COUNT:
//
// The number of categories for the capture filter.
//
#define CAPTURE_FILTER_CATEGORIES_COUNT 2

#define AVSHWS_POOLTAG 'hSVA'

/*************************************************

    Externed information

*************************************************/
//
// filter.cpp externs:
//
extern
const
KSFILTER_DISPATCH
CaptureFilterDispatch;

extern
const
KSFILTER_DESCRIPTOR
CaptureFilterDescriptor;

extern
const
KSPIN_DESCRIPTOR_EX
CaptureFilterPinDescriptors [CAPTURE_FILTER_PIN_COUNT];

extern
const
GUID
CaptureFilterCategories [CAPTURE_FILTER_CATEGORIES_COUNT];

//
// capture.cpp externs:
//
extern 
const
KSALLOCATOR_FRAMING_EX
CapturePinAllocatorFraming;

extern 
const
KSPIN_DISPATCH
CapturePinDispatch;

extern
const
PKSDATARANGE
CapturePinDataRanges [CAPTURE_PIN_DATA_RANGE_COUNT];

/*************************************************

    Enums / Typedefs

*************************************************/

typedef enum _HARDWARE_STATE {

    HardwareStopped = 0,
    HardwarePaused,
    HardwareRunning

} HARDWARE_STATE, *PHARDWARE_STATE;

/*************************************************

    Class Definitions

*************************************************/

//
// IHardwareSink:
//
// This interface is used by the hardware simulation to fake interrupt
// service routines.  The Interrupt method is called at DPC as a fake
// interrupt.
//
class IHardwareSink {

public:

    virtual
    void
    Interrupt (
        ) = 0;

};

//
// ICaptureSink:
//
// This is a capture sink interface.  The device level calls back the
// CompleteMappings method passing the number of completed mappings for
// the capture pin.  This method is called during the device DPC.
//
class ICaptureSink {

public:

    virtual
    void
    CompleteMappings (
        IN ULONG NumMappings
        ) = 0;

};



/*************************************************

    Global Functions

*************************************************/

/*************************************************

    Internal Includes

*************************************************/

#include "image.h"
#include "hwsim.h"
#include "device.h"
#include "filter.h"
#include "capture.h"
#include <uuids.h>
#endif //_avshws_h_
