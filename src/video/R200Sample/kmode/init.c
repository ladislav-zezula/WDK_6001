/*****************************************************************************\
* 
*  Module Name    INIT.C
*  Project        Longhorn
*  Device         R200
*
*  Description    Contains functions necessary for initializing the card
*                 after it has been detected.
*
*  Copyright (c) 2004 ATI Technologies Inc. (unpublished)
*
*  All rights reserved.
*  The year included in the foregoing notice is the year of creation of the work.
*
*  LOG OF CHANGES
*
*
\*****************************************************************************/

#include "common.h"
#include "rage.h"
#include "debug.h"
#include "global.h"
#include "init.h"
#include "proto.h"

//
// Allow swapping.
//
#if defined (ALLOC_PRAGMA)

#pragma alloc_text(PAGE_INIT, DefineMemoryTag)
#pragma alloc_text(PAGE_INIT, GetRegistryAdapterInfo)
#pragma alloc_text(PAGE_INIT, SetRegistryAdapterInfo)
#pragma alloc_text(PAGE_INIT, GetRegistryCallback)
#pragma alloc_text(PAGE_INIT, GetRegistryUlongCallback)
#pragma alloc_text(PAGE_INIT, GetDeviceDescription)
#pragma alloc_text(PAGE_INIT, FindStringInRomImage)
#pragma alloc_text(PAGE_INIT, StoreDALDefaultMode)

#endif  // ALLOC_PRAGMA

VOID
DefineMemoryTag(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    )
//
// DESCRIPTION:
//  Sets adapter specific Pool Tag.
//
// PARAMETERS:
//  pHwDeviceExtension  Points to per-adapter device extension.
//
{

    PAGED_CODE();
    ASSERT(NULL != pHwDeviceExtension);
	
    pHwDeviceExtension->ulAtiMemoryPoolID = R200_MEMORY_TAG;
}

VOID
GetRegistryAdapterInfo(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PADAPTER_INFO pAdapterInfo
    )
//
// DESCRIPTION:
//  Reads adapter identification data from the registry database.
//  This data is written to the registry by the miniport through the SetRegistryAdapterInfo() call.
//
// PARAMETERS:
//  pHwDeviceExtension  Points to per-adapter device extension.
//  pAdapterInfo        Pointer to buffer to be filled up.
//  
// RETURN VALUE:
//  Adapter data from the registry in pAdapterInfo.
//
{
    BUFFER_INFO bufferInfo;             // Stores information about the buffer where data is to be written

    PAGED_CODE();
    ASSERT(NULL != pHwDeviceExtension);
    ASSERT(NULL != pAdapterInfo);

    RtlZeroMemory(pAdapterInfo, sizeof(ADAPTER_INFO));


    bufferInfo.dwLength = ADAPTER_CHIP_TYPE_SIZE - sizeof(WCHAR);
    bufferInfo.pvBuffer = pAdapterInfo->ucaChipType;
    DlGetRegistryParameters(pHwDeviceExtension->DeviceHandle, L"HardwareInformation.ChipType",
        FALSE, GetRegistryCallback, &bufferInfo);

    bufferInfo.dwLength = ADAPTER_DAC_TYPE_SIZE - sizeof(WCHAR);
    bufferInfo.pvBuffer = pAdapterInfo->ucaDacType;
    DlGetRegistryParameters(pHwDeviceExtension->DeviceHandle, L"HardwareInformation.DacType",
        FALSE, GetRegistryCallback, &bufferInfo);

    bufferInfo.dwLength = ADAPTER_ADAPTER_STRING_SIZE - sizeof(WCHAR);
    bufferInfo.pvBuffer = pAdapterInfo->ucaAdapterString;
    DlGetRegistryParameters(pHwDeviceExtension->DeviceHandle, L"HardwareInformation.AdapterString",
        FALSE, GetRegistryCallback, &bufferInfo);

    bufferInfo.dwLength = ADAPTER_BIOS_STRING_SIZE - sizeof(WCHAR);
    bufferInfo.pvBuffer = pAdapterInfo->ucaBiosString;
    DlGetRegistryParameters(pHwDeviceExtension->DeviceHandle, L"HardwareInformation.BiosString",
        FALSE, GetRegistryCallback, &bufferInfo);

    DlGetRegistryParameters(pHwDeviceExtension->DeviceHandle, L"HardwareInformation.MemorySize",
        FALSE, GetRegistryUlongCallback, &(pAdapterInfo->ulMemorySize));

    DlDebugPrintEx((DEBUG_DETAIL, ATI_MINIPORT_STR " GetRegistryAdapterInfo: ChipType = \"%S\"\n", pAdapterInfo->ucaChipType));
    DlDebugPrintEx((DEBUG_DETAIL, ATI_MINIPORT_STR " GetRegistryAdapterInfo: DacType = \"%S\"\n", pAdapterInfo->ucaDacType));
    DlDebugPrintEx((DEBUG_DETAIL, ATI_MINIPORT_STR " GetRegistryAdapterInfo: AdapterString = \"%S\"\n", pAdapterInfo->ucaAdapterString));
    DlDebugPrintEx((DEBUG_DETAIL, ATI_MINIPORT_STR " GetRegistryAdapterInfo: BiosString = \"%S\"\n", pAdapterInfo->ucaBiosString));
    DlDebugPrintEx((DEBUG_DETAIL, ATI_MINIPORT_STR " GetRegistryAdapterInfo: MemorySize = %lu bytes\n", pAdapterInfo->ulMemorySize));
}   // GetRegistryAdapterInfo()

VOID
SetRegistryAdapterInfo(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    )
//
// DESCRIPTION:
//  Fills in the Chip Type, DAC Type, Memory Size, Adapter String, and Bios String fields in the registry.
//
// PARAMETERS:
//  pHwDeviceExtension  Points to per-adapter device extension.
//
{
    PWSTR pwszString;                                       // String to write
    ULONG ulLength;                                         // Length of above
    WCHAR wszDacAtiInternal[]     = L"Internal DAC(   MHz)";

    WCHAR wszDacUnknown[]         = L"Unknown DAC Type";
    WCHAR wszUnknownDevice[]      = L"Unknown ATI Accelerator";
    WCHAR wszDefaultAdapterString[]= L"ATI Display Adapter";
    WCHAR wszAdapterString[ADAPTER_STRING_LENGTH + 1];      // Adapter ID
    BUFFER_INFO bufferInfo;                               // Stores information about the buffer where data is to be written

    ROM_PLL_BLOCK PllBlock;
    ROM_HEADER    RomHeader;
    UCHAR         ucScratch;

    WCHAR wcaBiosString[BIOS_STRING_LENGTH + 1];            // Stores the BIOS version string in Unicode
    PUCHAR pucBiosString;                                   // Points to the BIOS version string in ROM
    UCHAR ucCurrentChar;                                    // Current character of the version string
    ULONG ulCharCount;                                      // Current position in the verson string
    WCHAR wszDefaultBiosString[]  = L"Unknown Video BIOS";
    ULONG ulStringChangeFlags = 0;
    WCHAR wszProChipType[ADAPTER_STRING_LENGTH + 1];
    PWCHAR pwszProChipType;
    int     i;

    PAGED_CODE();
    ASSERT(NULL != pHwDeviceExtension);

    //
    // Write Chip Type to the registry.
    //
    pwszString = GetDeviceDescription(pHwDeviceExtension, &ulLength, &ulStringChangeFlags);

    if (ulStringChangeFlags)
    {
        ASSERT (ulLength <= ADAPTER_STRING_LENGTH);

        for (pwszProChipType = &wszProChipType[0], i = 0;
             *pwszString && i < (ADAPTER_STRING_LENGTH + 1);
             pwszString++, i++)
        {
            {
                *pwszProChipType++ = *pwszString;
            }
        }
        //update the string with the one that we have modified.
        pwszString = &wszProChipType[0];

    }
    
    if (NULL == pwszString)
    {
        ASSERT(FALSE);
        pwszString = wszUnknownDevice;
        ulLength = sizeof(wszUnknownDevice);
    }
    
    DlSetRegistryParameters(pHwDeviceExtension->DeviceHandle, L"HardwareInformation.ChipType", pwszString, ulLength);
    if (pHwDeviceExtension->pvHwOtherDevExt)
        DlSetRegistryParameters(pHwDeviceExtension->DeviceHandle, L"HardwareInformation.ChipType", pwszString, ulLength);    // Add adapter info to registry for secondary display.  -sr-

    //
    // Write DAC Type to the registry.
    //
    switch (pHwDeviceExtension->ulDacType)
    {
    case DAC_ATI_INTERNAL:

        PllBlock.ulDotClockMaxFreq = 0;
        if (TRUE == IS_ROM_READABLE(pHwDeviceExtension))
        {
            if (NO_ERROR != ReadRomImage(pHwDeviceExtension,
                                         &RomHeader,
                                         pHwDeviceExtension->ulRomHeaderOffset,
                                         sizeof(ROM_HEADER)))
            {
                ASSERT(FALSE);
            }
            if (NO_ERROR != ReadRomImage(pHwDeviceExtension,
                                         &PllBlock,
                                         (ULONG)RomHeader.usPointerToPllInfoBlock,
                                         sizeof(ROM_PLL_BLOCK)))
            {
                ASSERT(FALSE);
            }
        }
        PllBlock.ulDotClockMaxFreq /= 100; // in 10 KHz units, convert it into to MHz
        if( PllBlock.ulDotClockMaxFreq )
        {
            pwszString = wszDacAtiInternal;
            ulLength = sizeof(wszDacAtiInternal);
            ucScratch = (UCHAR)(PllBlock.ulDotClockMaxFreq/100);
            wszDacAtiInternal[13] = (WCHAR)(ucScratch + '0');
            ucScratch = (UCHAR)( (PllBlock.ulDotClockMaxFreq - (LONG)(ucScratch*100))/10);
            wszDacAtiInternal[14] = (WCHAR)(ucScratch + '0');
            ucScratch = (UCHAR)( PllBlock.ulDotClockMaxFreq - (LONG)(PllBlock.ulDotClockMaxFreq/10)*10 );
            wszDacAtiInternal[15] = (WCHAR)(ucScratch + '0');
        }
        else
        {
            wszDacAtiInternal[12] = (WCHAR)('\0');
            pwszString = wszDacAtiInternal;
            ulLength = sizeof(wszDacAtiInternal);
        }
        break;

    default:

        ASSERT(FALSE);
        pwszString = wszDacUnknown;
        ulLength = sizeof(wszDacUnknown);
        break;
    }

    DlSetRegistryParameters(pHwDeviceExtension->DeviceHandle, L"HardwareInformation.DacType", pwszString, ulLength);
    if (pHwDeviceExtension->pvHwOtherDevExt)
        DlSetRegistryParameters(pHwDeviceExtension->DeviceHandle, L"HardwareInformation.DacType", pwszString, ulLength);    // Add adapter info to registry for secondary display.  -sr-

    
    
    //
    // Write Memory Size to the registry.
    //
    DlSetRegistryParameters(pHwDeviceExtension->DeviceHandle, L"HardwareInformation.MemorySize",
                                   &(pHwDeviceExtension->ulVRamSizeInstalled), sizeof(ULONG));
    if (pHwDeviceExtension->pvHwOtherDevExt)
        DlSetRegistryParameters(pHwDeviceExtension->DeviceHandle, L"HardwareInformation.MemorySize",
                                       &(pHwDeviceExtension->ulVRamSizeInstalled), sizeof(ULONG));    // Add adapter info to registry for secondary display.  -sr-
    
    //
    // Write Adapter String to the registry.
    //
    memset(&wszAdapterString[0], (WCHAR)'\0', (ADAPTER_STRING_LENGTH+1)*sizeof(WCHAR) );
    bufferInfo.dwLength = ADAPTER_STRING_LENGTH*sizeof(WCHAR);
    bufferInfo.pvBuffer = (PVOID*)&wszAdapterString[0];
    DlGetRegistryParameters(pHwDeviceExtension->DeviceHandle, L"Device Description",
                                   FALSE, GetRegistryCallback, &bufferInfo);

    if( wszAdapterString[0] == (WCHAR)'\0' )
    {// set it to ATI display adapter when the registry is empty
        memcpy( &wszAdapterString[0], &wszDefaultAdapterString[0], sizeof(wszDefaultAdapterString) );
    }


    ulLength = 0;
    for (ulLength = 0; *(wszAdapterString + ulLength); ulLength++);
    while(ulLength>0 && wszAdapterString[ulLength-1] == 0x20 ) 
    {
        wszAdapterString[ulLength-1] = (WCHAR)'\0'; //remove extra spaces
        ulLength--;
    }
    ulLength *= sizeof(WCHAR);

    DlSetRegistryParameters(pHwDeviceExtension->DeviceHandle, L"HardwareInformation.AdapterString",
                                   wszAdapterString, ulLength);
    if (pHwDeviceExtension->pvHwOtherDevExt)
        DlSetRegistryParameters(pHwDeviceExtension->DeviceHandle, L"HardwareInformation.AdapterString",
                                       wszAdapterString, ulLength);         // Add adapter info to registry for secondary display.  -sr-

    //
    // Write Bios Information string to the registry.
    //
    // Bios Information entry in the display applet was added
    //  The part number in the BIOS image will be in the first kilobyte but not the first 3 bytes.
    //
    if (IS_ROM_READABLE(pHwDeviceExtension) == TRUE)
    {
        //
        // Try to find the production BIOS string first.
        //
        pucBiosString = FindStringInRomImage(pHwDeviceExtension, BIOS_PN_PREFIX, 3, 1024);

        if (NULL == pucBiosString)
        {
            //
            // Try to find the pre-production BIOS string.
            //
            pucBiosString = FindStringInRomImage(pHwDeviceExtension, BIOS_RAGE128_PREFIX, 3, 1024);

            if (NULL != pucBiosString)
                pucBiosString += sizeof(BIOS_RAGE128_PREFIX) - 1;   // Skip over the prefix
        }
        else
        {
            pucBiosString += sizeof(BIOS_PN_PREFIX) - 1;            // Skip over the prefix
        }
    }
    else
    {
        pucBiosString = NULL;
    }

    if (NULL == pucBiosString)
    {
        DlSetRegistryParameters(pHwDeviceExtension->DeviceHandle, L"HardwareInformation.BiosString",
                                       wszDefaultBiosString, sizeof(wszDefaultBiosString));
        if (pHwDeviceExtension->pvHwOtherDevExt)
            DlSetRegistryParameters(pHwDeviceExtension->DeviceHandle, L"HardwareInformation.BiosString",
                                           wszDefaultBiosString, sizeof(wszDefaultBiosString));       // Add adapter info to registry for secondary display.  -sr-
    }
    else
    {
        // Extract the BIOS version string.
        ulCharCount = 0;
        ucCurrentChar = READ_REGISTER_UCHAR(pucBiosString);

        while ((ulCharCount < BIOS_STRING_LENGTH) && (ucCurrentChar >= ' ') && (ucCurrentChar <= 'z'))
        {
            wcaBiosString[ulCharCount] = (WCHAR)ucCurrentChar;
            ulCharCount++;
            pucBiosString++;
            ucCurrentChar = READ_REGISTER_UCHAR(pucBiosString);
        }
        wcaBiosString[ulCharCount] = (WCHAR)'\0';
        DlDebugPrintEx((DEBUG_NORMAL, ATI_MINIPORT_STR " SetRegistryAdapterInfo: BIOS P/N = \"%S\"\n", wcaBiosString));

        DlSetRegistryParameters(pHwDeviceExtension->DeviceHandle, L"HardwareInformation.BiosString",
                                       wcaBiosString, (ulCharCount + 1) * sizeof(WCHAR));
        if (pHwDeviceExtension->pvHwOtherDevExt)
            DlSetRegistryParameters(pHwDeviceExtension->DeviceHandle, L"HardwareInformation.BiosString",
                                           wcaBiosString, (ulCharCount + 1) * sizeof(WCHAR));            // Add adapter info to registry for secondary display.  -sr-
    }

}   // SetRegistryAdapterInfo()

VP_STATUS
GetRegistryCallback(
    __in     PHW_DEVICE_EXTENSION pHwDeviceExtension,
    __inout  PVOID pvContext,
    __in     PWSTR pwszName,
    __in_bcount(ulLength)  PVOID pvData,
    __in     ULONG ulLength
    )
//
// DESCRIPTION:
//  DlGetRegistryParameters() callback function for any type of data.
//
// PARAMETERS:
//  pHwDeviceExtension  Points to per-adapter device extension.
//  pvContext           Points to driver-determined contex (our PBUFFER_INFO).
//  pwszName            Points to a zero-terminated Unicode entry name.
//  pvData              Points to the registry data associated with wszName.
//  ulLength            Size in bytes of the buffer at pvData.
//
// RETURN VALUE:
//  NO_ERROR    OK.
//  Error code  Error.
//
{
    PBUFFER_INFO    pBufferInfo = NULL;               // Pointer into BUFFER_INFO

    PAGED_CODE();
    ASSERT(NULL != pHwDeviceExtension);
    ASSERT(NULL != pvContext);

    if (pvData == NULL || ulLength == 0 || pvContext == NULL)
        return ERROR_INVALID_PARAMETER;

    pBufferInfo = (PBUFFER_INFO)pvContext;  // Set formatted pointer

    ASSERT(NULL != pBufferInfo->pvBuffer);

    RtlMoveMemory(pBufferInfo->pvBuffer,
                  pvData,
                  min(ulLength, pBufferInfo->dwLength));

    if (ulLength > pBufferInfo->dwLength)
        return ERROR_INSUFFICIENT_BUFFER;

    //
    // Return the size of the buffer read from the registry to the caller.
    //
    pBufferInfo->dwLength = ulLength;

    return NO_ERROR;
}   // GetRegistryCallback()


VP_STATUS
GetRegistryUlongCallback(
    __in  PHW_DEVICE_EXTENSION pHwDeviceExtension,
    __inout  PVOID pvContext,
    __in PWSTR pwszName,
    __in_bcount(ulLength)  PVOID pvData,
    __in  ULONG ulLength
    )
//
// DESCRIPTION:
//  DlGetRegistryParameters() callback function for ULONG values.
//
// PARAMETERS:
//  pHwDeviceExtension  Points to per-adapter device extension.
//  pvContext           Points to driver-determined contex (our PULONG).
//  pwszName            Points to a zero-terminated Unicode entry name.
//  pvData              Points to the registry data associated with wszName.
//  ulLength            Size in bytes of the buffer at pvData.
//
// RETURN VALUE:
//  NO_ERROR    OK.
//  Error code  Error.
//
{
    PAGED_CODE();
    ASSERT(NULL != pHwDeviceExtension);
    ASSERT(NULL != pvContext);

    if ((NULL == pvData) || (sizeof(ULONG) != ulLength))
        return ERROR_INVALID_PARAMETER;

    RtlMoveMemory(pvContext, pvData, sizeof(ULONG));

    return NO_ERROR;
}   // GetRegistryUlongCallback()

PWSTR
GetDeviceDescription(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PULONG pulSize,
    PULONG pulStringChangeFlags
    )
//
// DESCRIPTION:
//  Gets device's description from the supported devices table.
//
// PARAMETERS:
//  pHwDeviceExtension  Points to per-adapter device extension.
//  pulSize             Points for storage for description size (in bytes).
//
// RETURN VALUE:
//  Pointer to the device description, description size in *pulSize (bytes).
//  NULL if error.
//
{
    PSUPPORTED_REVISION pSupportedRevision;
    PWCHAR pwcDescription = NULL;
    PWCHAR pwcTempDescription = NULL;

    PAGED_CODE();
    ASSERT(NULL != pHwDeviceExtension);
    ASSERT(pHwDeviceExtension->usDeviceId);

    pSupportedRevision = ex_aSupportedRevisions;
 
    for (; pSupportedRevision->usDeviceId; pSupportedRevision++)
    {
        if ((pSupportedRevision->usDeviceId == pHwDeviceExtension->usDeviceId) &&
            (pSupportedRevision->ucRevision == pHwDeviceExtension->ucAtiExternalRev))
        {
            pwcDescription = pSupportedRevision->pwszDescription;
            break;
        }
    }

    //
    // If we are unable to match device id and revision we should check for device id only, we can have new
    // revision of the chip not included in this driver. If difference is in the revision only we want to
    // support such a device in this driver. Driver should be updated ASAP to include the new revision.
    //

    if (NULL == pwcDescription)                         // Checked all -- didn't find
    {
        for (pSupportedRevision = ex_aSupportedRevisions; pSupportedRevision->usDeviceId; pSupportedRevision++)
        {
            if (pSupportedRevision->usDeviceId == pHwDeviceExtension->usDeviceId)
            {
                pwcDescription = pSupportedRevision->pwszDescription;
                break;
            }
        }

        if (NULL == pwcDescription)                     // Checked all -- didn't find
        {
            ASSERT(FALSE);                              // This is wrong, it MUST match
            return NULL;
        }

        DlDebugPrintEx((DEBUG_NORMAL, ATI_MINIPORT_STR " GetDeviceDescription: WARNING - unknown (new) device revision\n"));
    }

    //
    // Get size in bytes of the device description string.
    //

    if (NULL != pwcDescription)                        // Double check
    {
        for (*pulSize = 0; *(pwcDescription + *pulSize); (*pulSize)++);
        (*pulSize)++;
        (*pulSize) *= sizeof(WCHAR);
    }

    return pwcDescription;
}   // GetDeviceDescription()

PUCHAR
FindStringInRomImage(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PUCHAR pszString,
    ULONG ulStartOffset,
    ULONG ulEndOffset
    )
//
// DESCRIPTION:
//  Searches for a specified string in the video ROM image.
//
// PARAMETERS:
//  pHwDeviceExtension  Points to per-adapter device extension.
//  pszString           String we are looking for.
//  ulStartOffset       Offset into ROM image where we should start looking.
//  ulEndOffset         Offset into ROM image where we should stop looking.
//
// RETURN VALUE:
//  Pointer to the start of the first occurrence of pszString in the specified section of the BIOS.
//  NULL if not found.
//
{
    ULONG ulStringOffset;               // Counter to check for match
    UCHAR ucTemp;                       // Temporary variable to store ROM data
    BOOL bFound;                        // Whether or not the target string was found

    PAGED_CODE();
    ASSERT(NULL != pHwDeviceExtension);
    ASSERT(NULL != pszString);
    ASSERT(0 != pszString[0]);          // This would mess up the internal loop

    DlDebugPrintEx((DEBUG_DETAIL, ATI_MINIPORT_STR " FindStringInRomImage: Searching for \"%s\"\n", pszString));

    if (IS_ROM_READABLE(pHwDeviceExtension) == FALSE)
    {
        DlDebugPrintEx((DEBUG_DETAIL, ATI_MINIPORT_STR " FindStringInRomImage: ROM unreadable - string not found\n"));
        return NULL;
    }

    for (; ulStartOffset <= ulEndOffset; ulStartOffset++)
    {
        ASSERT(ulStartOffset < pHwDeviceExtension->ulRomLength);

        if (READ_REGISTER_UCHAR((PUCHAR)(pHwDeviceExtension->pvRomBaseAddress) + ulStartOffset) != pszString[0])
            continue;

        bFound = TRUE;

        for (ulStringOffset = 1; pszString[ulStringOffset]; ulStringOffset++)
        {
            ASSERT(ulStartOffset + ulStringOffset < pHwDeviceExtension->ulRomLength);

            if (READ_REGISTER_UCHAR(
                (PUCHAR)(pHwDeviceExtension->pvRomBaseAddress) + ulStartOffset + ulStringOffset) !=
                pszString[ulStringOffset])
            {
                bFound = FALSE;
                break;
            }
        }

        if (TRUE == bFound)
        {
            DlDebugPrintEx((DEBUG_DETAIL, ATI_MINIPORT_STR " FindStringInRomImage: String found at offset %lu\n", ulStartOffset));
            return (PUCHAR)(pHwDeviceExtension->pvRomBaseAddress) + ulStartOffset;
        }
    }

    DlDebugPrintEx((DEBUG_DETAIL, ATI_MINIPORT_STR " FindStringInRomImage: String not found\n"));
    return NULL;
}   // FindStringInRomImage()


VOID
StoreDALDefaultMode(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    )
//
// DESCRIPTION:
//  Store the default mode, as returned by DAL, in the registry.
//
// PARAMETERS:
//  pHwDeviceExtension  Points to per-adapter device extension.
//
{
    HDAL hDal;
    DEVMODE_INFO dmDefault;

    PAGED_CODE();

    hDal = (HDAL)pHwDeviceExtension->pvhDal;

    if ((DALGetDefaultMode(hDal, pHwDeviceExtension->ulDriverID, (LPDEVMODE_INFO)&dmDefault)) &&
        (0 != (dmDefault.ulPelsWidth    | dmDefault.ulPelsHeight |
               dmDefault.ulBitsPerPixel | dmDefault.ulDisplayFrequency)))
    {
        DlSetRegistryParameters(pHwDeviceExtension->DeviceHandle, L"DefaultMode",
            &(dmDefault), sizeof (DEVMODE_INFO));
    }
} // StoreDALDefaultMode()

