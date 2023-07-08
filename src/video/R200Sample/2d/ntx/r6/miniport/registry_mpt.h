/*!*********************************************************************
*
*	C Header:		registry_mpt.h
*	Description:	
*
**********************************************************************/
#ifndef _twntr42d_1_registry_mpt_h_H
#define _twntr42d_1_registry_mpt_h_H

/*! DESCRIPTION
Used for disabling DMA for the Camino board
or if FixChipsetBugs fails
or if PM4 can't be enabled
or if Forcing Busmastering Fails
*/
/*! TYPE
DWORD
*/
/*! COMMENTS
Free-form comments - optional
*/
#define PDEV_DISABLE_DMA_STR                              L"DisableDMA"
#define PDEV_DISABLE_DMA_VALUE                        PDEV_DISABLE_DMA
#define PDEV_DISABLE_DMA_DEFAULT                      0

/*! DESCRIPTION
This flag is used to disable Video SWC
*/
/*! TYPE
DWORD
*/
/*! COMMENTS
Free-form comments - optional
*/
#define PDEV_DISABLE2_VIDEOUSWC_STR                       L"DisableVideoUSWC"
#define PDEV_DISABLE2_VIDEOUSWC_VALUE                 PDEV_DISABLE2_VIDEOUSWC
#define PDEV_DISABLE2_VIDEOUSWC_DEFAULT               0

/*! DESCRIPTION
This flag is used to Disable Crt Display
*/
/*! TYPE
DWORD
*/
/*! COMMENTS
Free-form comments - optional
*/
#define PDEV_DISABLE2_CRT_STR                             L"DisableCRT"
#define PDEV_DISABLE2_CRT_VALUE                       PDEV_DISABLE2_CRT
#define PDEV_DISABLE2_CRT_DEFAULT                     0

/*! DESCRIPTION
This flag is used to Disable TV out
*/
/*! TYPE
DWORD
*/
/*! COMMENTS
Free-form comments - optional
*/
#define PDEV_DISABLE2_TV_STR                             L"DisableTV"
#define PDEV_DISABLE2_TV_VALUE                        PDEV_DISABLE2_TV
#define PDEV_DISABLE2_TV_DEFAULT                      0

/*! DESCRIPTION
This flag is used to Disable LCD display
*/
/*! TYPE
DWORD
*/
/*! COMMENTS
Free-form comments - optional
*/
#define PDEV_DISABLE2_LCD_STR                             L"DisableLCD"
#define PDEV_DISABLE2_LCD_VALUE                       PDEV_DISABLE2_LCD
#define PDEV_DISABLE2_LCD_DEFAULT                     0

/*! DESCRIPTION
This flag is used to Disable Flat panel display
*/
/*! TYPE
DWORD
*/
/*! COMMENTS
Free-form comments - optional
*/
#define PDEV_DISABLE2_DFP_STR                             L"DisableDFP"
#define PDEV_DISABLE2_DFP_VALUE                       PDEV_DISABLE2_DFP
#define PDEV_DISABLE2_DFP_DEFAULT                     0

/*! DESCRIPTION
Hot Plug DVI-I Support Feature is not available for the R128 chipset, therefore explicitly disabled
The flag disables the Hot Plug DVI-I feature of the board
*/
/*! TYPE
DWORD
*/
/*! COMMENTS
Free-form comments - optional
*/
#define PDEV_DISABLE3_HOTPLUGDFP_STR                      L"DisableHotPlugDFP"
#define PDEV_DISABLE3_HOTPLUGDFP_VALUE                PDEV_DISABLE3_HOTPLUGDFP
#define PDEV_DISABLE3_HOTPLUGDFP_DEFAULT              0

/*! DESCRIPTION
This flag is used to disable Multi Monitor Enumeration
*/
/*! TYPE
DWORD
*/
/*! COMMENTS
Free-form comments - optional
*/
#define PDEV_DISABLE3_MULTIMONENUM_STR                    L"DisableMultiMonEnum"
#define PDEV_DISABLE3_MULTIMONENUM_VALUE              PDEV_DISABLE3_MULTIMONENUM
#define PDEV_DISABLE3_MULTIMONENUM_DEFAULT            0

/*! DESCRIPTION
This flag is used to disable Enumeration of all children
*/
/*! TYPE
DWORD
*/
/*! COMMENTS
[cperez 10/18/01] EnumAllChilds was being DISABLED for all affected ASICS.  Default changed to DISABLED.
*/
#define PDEV_DISABLE3_ENUMALLCHILDS_STR                   L"DisableEnumAllChilds"
#define PDEV_DISABLE3_ENUMALLCHILDS_VALUE             PDEV_DISABLE3_ENUMALLCHILDS
#define PDEV_DISABLE3_ENUMALLCHILDS_DEFAULT           0

/*! DESCRIPTION
This flag is used to disable USWC AGP
*/
/*! TYPE
DWORD
*/
/*! COMMENTS
Free-form comments - optional
*/
#define PDEV_DISABLE4_USWCAGP_STR                         L"DisableUswcAgp"
#define PDEV_DISABLE4_USWCAGP_VALUE                   PDEV_DISABLE4_USWCAGP
#define PDEV_DISABLE4_USWCAGP_DEFAULT                 0

/*! DESCRIPTION
This feature disbales Memory Manager: This is used on NT4 since MM is not suported under winnt4
*/
/*! TYPE
DWORD
*/
/*! COMMENTS
Free-form comments - optional
*/
#define PDEV_DISABLE4_MMLIB_STR                           L"DisableMMLIB"
#define PDEV_DISABLE4_MMLIB_VALUE                     PDEV_DISABLE4_MMLIB
#define PDEV_DISABLE4_MMLIB_DEFAULT                   PDEV_DISABLE4_MMLIB

/*! DESCRIPTION
This flag is used to disable  DAL Validate Child 
*/
/*! TYPE
DWORD
*/
/*! COMMENTS
Free-form comments - optional
*/
#define PDEV_DISABLE4_DALVALIDATECHILD_STR                L"DisableDalValidateChild"
#define PDEV_DISABLE4_DALVALIDATECHILD_VALUE          PDEV_DISABLE4_DALVALIDATECHILD
#define PDEV_DISABLE4_DALVALIDATECHILD_DEFAULT        0

/*! DESCRIPTION
This flag is used to Disable PM4 TS support in the miniport.
ATTENTION! This registry key is shared with CMM. Do not change the string.
*/
/*! TYPE
DWORD
*/
/*! COMMENTS
Free-form comments - optional
*/
#define PDEV_DISABLE4_PM4TSINTERRUPT_STR      L"DisablePM4TSInterrupt"
#define PDEV_DISABLE4_PM4TSINTERRUPT_VALUE    PDEV_DISABLE4_PM4TSINTERRUPT
#define PDEV_DISABLE4_PM4TSINTERRUPT_DEFAULT  0

/*! DESCRIPTION
This is defined! But This Flag is not used anywhere in Miniport or DD
*/
/*! TYPE
DWORD
*/
/*! COMMENTS
Free-form comments - optional
*/
#define DisableMMSnifferCode_STR                          L"DisableMMSnifferCode"
#define DisableMMSnifferCode_VALUE                    DisableMMSnifferCode
#define DisableMMSnifferCode_DEFAULT                  0

/*! DESCRIPTION
This is defined! But This Flag is not used anywhere in Miniport or DD
*/
/*! TYPE
DWORD
*/
/*! COMMENTS
Free-form comments - optional
*/
#define DisableMMKernelVPE_STR                            L"DisableMMKernelVPE"
#define DisableMMKernelVPE_VALUE                      DisableMMKernelVPE
#define DisableMMKernelVPE_DEFAULT                    0

/*! DESCRIPTION
This is defined! But This Flag is not used anywhere in Miniport or DD
*/
/*! TYPE
DWORD
*/
/*! COMMENTS
Free-form comments - optional
*/
#define AgpLevel_STR                                      L"AgpLevel"
#define AgpLevel_VALUE                                0
#define AgpLevel_DEFAULT                              CONTROL_AGP_LEVEL_8X

/*! DESCRIPTION
define PM4TSInterruptSource string in registry
*/
/*! TYPE
DWORD
*/
/*! COMMENTS
Which IRQ source to use for PM4 Time Stamp Interrupt
*/
#define PM4TSINTERRUPTSOURCE_STR                         L"PM4TSInterruptSource"
#define PM4TSINTERRUPTSOURCE_VALUE                       0
#define PM4TSINTERRUPTSOURCE_DEFAULT                     IRQ_SOURCE1_GUIDMA

#endif
//! @}

