/*++

Copyright (c) 2003 Microsoft Corporation

Module Name:

    miniport.c

Abstract:

    This is main entry module into the display miniport.


Environment:

    Kernel mode only

Notes:

    Contains all the Displdr related code.

Revision History:

    Genesis - 2-Jun-2004.

--*/

// NOTE: Production quality driver shouldn't use any DlXxx functions which are used in the sample.
//           It should use functions provided by DxgkInterface or its own equivalents.

#include <ntddk.h>
#include <StrSafe.h>
#include <dispmprt.h>
#include <stdio.h>
#include <stdlib.h>
#include "dderror.h"
#include "cwddedi.h"
#include "rage.h"
#include "debug.h"
#include "global.h"


VP_STATUS
AtiFindAdapter(
    __in      PHW_DEVICE_EXTENSION pHwDeviceExtension,
    __in_opt  PVOID pvHwContext,
    __in_opt  PWSTR pwszArgumentString,
    __in      PVIDEO_PORT_CONFIG_INFO pConfigInfo,
    __in      PUCHAR pucAgain
    );

BOOLEAN
AtiInitialize(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

BOOLEAN
AtiStartIO(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVIDEO_REQUEST_PACKET pVideoRequestPacket
    );

VP_STATUS
AtipSetPowerState(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    ULONG ulHwId,
    PVIDEO_POWER_MANAGEMENT pVideoPowerMgmt
    );

VP_STATUS
AtiGetVideoChildDescriptor(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVIDEO_CHILD_ENUM_INFO pChildEnumInfo,
    PVIDEO_CHILD_TYPE pChildType,
    PVOID pvChildDescriptor,
    PULONG pulHwDeviceId,
    PULONG pulUnused
    );

// MP_VPE
BOOLEAN
AtiInterrupt(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

VOID
Ati_PM4Interrupt_DPC(
    PVOID MiniportDeviceContext,
    PVOID Context);

VOID
FreeResources(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

VP_STATUS
IoctlVideoResetDevice(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVIDEO_REQUEST_PACKET pVideoRequestPacket
    );

VOID
vTriggerEnumeration(
   PHW_DEVICE_EXTENSION pHwDeviceExtension
   );

VP_STATUS
vpsEnableView(
   PHW_DEVICE_EXTENSION pHwDeviceExtension
   );

VP_STATUS
GetConnectedDisplays(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

NTSTATUS
AtiQueryInterfaceEx(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PQUERY_INTERFACE pQueryInterface
    );



#define ATI_TAG '_ITA'
#define MAX_VIEWS 2
#define EDID_BUFFER_SIZE 256
#define ACPI_NON_VIDEO_OUTPUT_DEVICE 0x20000
#define ACPI_HARDWARE_ID 0xFFFF

typedef struct __VIDEO_CHILD_DESCRIPTOR {
    VIDEO_CHILD_TYPE    Type;
    ULONG               UId;
    BOOLEAN             bACPIDevice;
    UCHAR               ACPIDDCFlag;
    BOOLEAN             ValidEDID;
    BOOLEAN             bInvalidate;
    UCHAR               Buffer[EDID_BUFFER_SIZE];
} VIDEO_CHILD_DESCRIPTOR, *PVIDEO_CHILD_DESCRIPTOR;


//
// Per adapter DDI entry points
//


NTSTATUS
D3DDDICreateAllocation_LegacyDmm(
    VOID                       *InterfaceContext,
    DXGKARG_CREATEALLOCATION   *pDDICAData);

















//
// Per device DDI entry points
//

BOOLEAN
AtiResetHw(
    IN PHW_DEVICE_EXTENSION pHwDeviceExtension,
    IN ULONG ulColumns,
    IN ULONG ulRows
    );

NTSTATUS
SetVidPnSourceStatus(
    IN PVOID MiniportDeviceContext,
    IN D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId,
    IN BOOLEAN Enable
    );

//
//     DDI Function declarations
//
//  The DDI functions declared here use the function name definitions
//  specified in \inc\ddk\dispmprt.h in the WDK.  This approach makes it
//  easy and accurate to declare the DDI function names for the driver,
//  and also includes the SAL annotations for the function parameters.
//  The SAL annotations enable PREfast for Drivers (included in the WDK)
//  to check for buffer overruns and other coding errors.
//  
DXGKDDI_ADD_DEVICE              AtiAddDevice;
DXGKDDI_START_DEVICE            AtiStartDevice;
DXGKDDI_STOP_DEVICE             AtiStopDevice;
DXGKDDI_REMOVE_DEVICE           AtiRemoveDevice;
DXGKDDI_DISPATCH_IO_REQUEST     AtiDispatchIoRequest;
DXGKDDI_INTERRUPT_ROUTINE       AtiInterruptRoutine;
DXGKDDI_DPC_ROUTINE             AtiDpcRoutine;
DXGKDDI_QUERY_CHILD_RELATIONS   AtiQueryChildRelations;
DXGKDDI_QUERY_CHILD_STATUS      AtiQueryChildStatus;
DXGKDDI_QUERY_DEVICE_DESCRIPTOR AtiQueryDeviceDescriptor;
DXGKDDI_SET_POWER_STATE         AtiSetPowerState;
DXGKDDI_NOTIFY_ACPI_EVENT       AtiNotifyAcpiEvent;
DXGKDDI_RESET_DEVICE            AtiResetDevice;
DXGKDDI_UNLOAD                  AtiUnload;
DXGKDDI_QUERY_INTERFACE         AtiQueryInterface;
DXGKDDI_CONTROL_ETW_LOGGING     D3DDDIControlEtwLogging;
DXGKDDI_QUERYADAPTERINFO                D3DDDIQueryAdapterInfo;
DXGKDDI_CREATEDEVICE                    D3DDDICreateDevice;
DXGKDDI_CREATEALLOCATION                D3DDDICreateAllocation;
DXGKDDI_DESTROYALLOCATION               D3DDDIDestroyAllocation;
DXGKDDI_DESCRIBEALLOCATION              D3DDDIDescribeAllocation;
DXGKDDI_GETSTANDARDALLOCATIONDRIVERDATA D3DDDIGetStandardAllocationDriverData;
DXGKDDI_ACQUIRESWIZZLINGRANGE           D3DDDIAcquireSwizzlingRange;
DXGKDDI_RELEASESWIZZLINGRANGE           D3DDDIReleaseSwizzlingRange;
DXGKDDI_PATCH                           D3DDDIPatchDmaBuffer;
DXGKDDI_SUBMITCOMMAND                   D3DDDISubmitCommand;
DXGKDDI_PREEMPTCOMMAND                  D3DDDIPreemptCommand;
DXGKDDI_BUILDPAGINGBUFFER               D3DDDIBuildPagingBuffer;
DXGKDDI_SETPALETTE                      D3DDDISetPalette;
DXGKDDI_SETPOINTERPOSITION              D3DDDISetPointerPosition;
DXGKDDI_SETPOINTERSHAPE                 D3DDDISetPointerShape;
DXGKDDI_RESETFROMTIMEOUT                D3DDDIResetFromTimeout;
DXGKDDI_RESTARTFROMTIMEOUT              D3DDDIRestartFromTimeout;
DXGKDDI_ESCAPE                          D3DDDIEscape;
DXGKDDI_COLLECTDBGINFO                  D3DDDICollectDbgInfo;
DXGKDDI_QUERYCURRENTFENCE               D3DDDIQueryCurrentFence;
DXGKDDI_ISSUPPORTEDVIDPN                D3DDDIIsSupportedVidPn_XddmParity;
DXGKDDI_ISSUPPORTEDVIDPN                D3DDDIIsSupportedVidPn_Test;
DXGKDDI_RECOMMENDFUNCTIONALVIDPN        D3DDDIRecommendFunctionalVidPn_XddmParity;
DXGKDDI_RECOMMENDFUNCTIONALVIDPN        D3DDDIRecommendFunctionalVidPn_Test;
DXGKDDI_ENUMVIDPNCOFUNCMODALITY         D3DDDIEnumVidPnCofuncModality_XddmParity;
DXGKDDI_ENUMVIDPNCOFUNCMODALITY         D3DDDIEnumVidPnCofuncModality_Test;
DXGKDDI_SETVIDPNSOURCEADDRESS           D3DDDISetVidPnSourceAddress;
DXGKDDI_SETVIDPNSOURCEVISIBILITY        D3DDDISetVidPnSourceVisibility;
DXGKDDI_COMMITVIDPN                     D3DDDICommitVidPn;
DXGKDDI_UPDATEACTIVEVIDPNPRESENTPATH    D3DDDIUpdateActiveVidPnPresentPath;
DXGKDDI_RECOMMENDMONITORMODES           D3DDDIRecommendMonitorModes;
DXGKDDI_RECOMMENDVIDPNTOPOLOGY          D3DDDIRecommendVidPnTopology;
DXGKDDI_GETSCANLINE                     D3DDDIGetScanLine;
DXGKDDI_CONTROLINTERRUPT                D3DDDIControlInterrupt;

//
// Device functions
//

DXGKDDI_DESTROYDEVICE                   D3DDDIDestroyDevice;
DXGKDDI_OPENALLOCATIONINFO              D3DDDIOpenAllocation;
DXGKDDI_CLOSEALLOCATION                 D3DDDICloseAllocation;
DXGKDDI_RENDER                          D3DDDIRender;
DXGKDDI_PRESENT                         D3DDDIPresent;

//
// Context functions
//

DXGKDDI_CREATECONTEXT                   D3DDDICreateContext;
DXGKDDI_DESTROYCONTEXT                  D3DDDIDestroyContext;

//
// Overlay functions
//


NTSTATUS
AtiGetChildCount(
    __in   PVOID pvMiniportDeviceContext,
    __out  PULONG ulChildCount
    );

NTSTATUS
DriverEntry(
    IN PDRIVER_OBJECT DriverObject,
    IN PUNICODE_STRING RegistryPath
    );

void ReadDebugRegistrySettings(void);

//
// *** Support Routines *******************************************************
//

ULONG
GetExtensionSize(
    VOID
    );

#ifdef ALLOC_PRAGMA
#pragma alloc_text(PAGE,AtiAddDevice)
#pragma alloc_text(PAGE,AtiStartDevice)
#pragma alloc_text(PAGE,AtiStopDevice)
#pragma alloc_text(PAGE,AtiRemoveDevice)
#pragma alloc_text(PAGE,AtiDispatchIoRequest)
#pragma alloc_text(PAGE,AtiQueryInterface)
#pragma alloc_text(PAGE,SetVidPnSourceStatus)
#pragma alloc_text(PAGE,AtiGetChildCount)
#pragma alloc_text(PAGE,AtiQueryChildRelations)
#pragma alloc_text(PAGE,AtiQueryChildStatus)
#pragma alloc_text(PAGE,AtiQueryDeviceDescriptor)
#pragma alloc_text(PAGE,AtiUnload)
#pragma alloc_text(INIT,DriverEntry)
#endif

NTSTATUS
AtiAddDevice(
    IN_CONST_PDEVICE_OBJECT PhysicalDeviceObject,
    OUT PVOID *MiniportDeviceContext
    )
{
    PHW_DEVICE_EXTENSION   *ExtensionArray = NULL;
    ULONG                   DeviceAddress = 0;
    ULONG                   ResultLength = 0;
    ULONG                   NumberOfVideoPresentSources = 2;

    PAGED_CODE();          

    if (! ARGUMENT_PRESENT(PhysicalDeviceObject) ||
        ! ARGUMENT_PRESENT(MiniportDeviceContext))
    {
        return STATUS_INVALID_PARAMETER;
    }
  
    //
    // Get the device address from our PDO
    //

    IoGetDeviceProperty(PhysicalDeviceObject,
                        DevicePropertyAddress,
                        sizeof(DeviceAddress),
                        &DeviceAddress,
                        &ResultLength);

    //
    // If this is a second function on a card just don't enumerate it. The device
    // number is in the top 16 bits and the function number is in the lower 16 bits.
    // If the function number is not zero, just get out.
    //

    if ((DeviceAddress << 16) != 0)
    {
        *MiniportDeviceContext = NULL;
        return STATUS_SUCCESS;
    }

    //
    // Allocate memory for our device extensions. We can have at most 2 so allocate
    // enough to store any possible ones we discover later.
    //

    ExtensionArray = (PHW_DEVICE_EXTENSION*)ExAllocatePoolWithTag(NonPagedPool,
                                                                  NumberOfVideoPresentSources * sizeof(PHW_DEVICE_EXTENSION),
                                                                  ATI_TAG);

    if (ExtensionArray == NULL)
    {
        return STATUS_INSUFFICIENT_RESOURCES;
    }

    //
    // Clear the array.
    //

    ExtensionArray[0] = NULL;
    ExtensionArray[1] = NULL;

    *MiniportDeviceContext = ExtensionArray;

    return STATUS_SUCCESS;
}

//
// Translate common VP_STATUS code to NT_STATUS code
//
NTSTATUS
VpStatusToNtStatus(
    VP_STATUS   vpStatus)
{
    switch (vpStatus)
    {
    case ERROR_INVALID_FUNCTION:
        return STATUS_NOT_IMPLEMENTED;

    case ERROR_NOT_ENOUGH_MEMORY:
        return STATUS_INSUFFICIENT_RESOURCES;

    case ERROR_INVALID_PARAMETER:
        return STATUS_INVALID_PARAMETER;

    case ERROR_INSUFFICIENT_BUFFER:
        return STATUS_BUFFER_TOO_SMALL;

    case ERROR_MORE_DATA:
        return STATUS_BUFFER_OVERFLOW;

    case ERROR_DEV_NOT_EXIST:
        return STATUS_DEVICE_DOES_NOT_EXIST;

    case ERROR_IO_PENDING:
        return STATUS_PENDING;

    case NO_ERROR:
        return STATUS_SUCCESS;

    default:
        return STATUS_UNSUCCESSFUL;
    }
}

NTSTATUS
AtiStartDevice(
    IN PVOID MiniportDeviceContext,
    IN PDXGK_START_INFO DxgkStartInfo,
    IN PDXGKRNL_INTERFACE DxgkInterface,
    OUT PULONG NumberOfViews,
    OUT PULONG NumberOfChildren
    )
{
    DXGK_DEVICE_INFO DeviceInfo;
    PHW_DEVICE_EXTENSION DeviceContext;
    PHW_DEVICE_EXTENSION *ExtensionArray = MiniportDeviceContext;
    NTSTATUS Status = STATUS_SUCCESS;
    UCHAR Again;
    ULONG ExtensionSize = GetExtensionSize();
    VIDEO_PORT_CONFIG_INFO LegacyConfigInfo = {'\0'};
    VP_STATUS vpStatus;

    PAGED_CODE();

    if (! ARGUMENT_PRESENT(MiniportDeviceContext) ||
        ! ARGUMENT_PRESENT(DxgkInterface) ||
        ! ARGUMENT_PRESENT(NumberOfViews))
    {
        return STATUS_INVALID_PARAMETER;
    }

    //
    // First get our device info
    //

    DlGetDeviceInformation(DxgkInterface->DeviceHandle, &DeviceInfo);

    //
    // Allocate memory for the first view
    //

    DeviceContext = (PHW_DEVICE_EXTENSION)ExAllocatePoolWithTag(NonPagedPool,
                                                                ExtensionSize,
                                                                ATI_TAG);

    if (DeviceContext == NULL)
    {
        return STATUS_INSUFFICIENT_RESOURCES;
    }

    RtlZeroMemory(DeviceContext, ExtensionSize);

    DeviceContext->DeviceHandle = DxgkInterface->DeviceHandle;

    *NumberOfViews = 1;

    //
    // Store the AGP aperture size in the HwDeviceExtension since we will need
    // it later.
    //

    DeviceContext->SystemAgpApertureSize = DeviceInfo.AgpApertureSize;
    DeviceContext->SystemAgpApertureBase = DeviceInfo.AgpApertureBase;

    //
    // Save the DXG interface specific data
    //

    DeviceContext->ddiCallback = *DxgkInterface;
    DeviceContext->pVidSchINTCB = DxgkInterface->DxgkCbNotifyInterrupt;
    DeviceContext->pVidSchDPCCB = DxgkInterface->DxgkCbNotifyDpc;

    //
    // Save number of entry requred in dma queue.
    //
    DeviceContext->ulRequiredDmaQueueEntry = DxgkStartInfo->RequiredDmaQueueEntry;

    //
    // Enable interrupts.
    //

    DeviceContext->InterruptsEnabled = TRUE;


    LegacyConfigInfo.Length = sizeof(VIDEO_PORT_CONFIG_INFO);
    LegacyConfigInfo.SystemIoBusNumber = DeviceInfo.TranslatedResourceList->List[0].BusNumber;
    LegacyConfigInfo.AdapterInterfaceType = DeviceInfo.TranslatedResourceList->List[0].InterfaceType;
    LegacyConfigInfo.SystemMemorySize = DeviceInfo.SystemMemorySize.QuadPart;
    LegacyConfigInfo.DriverRegistryPath = DeviceInfo.DeviceRegistryPath.Buffer;


    //
    // Initialize device extension
    //
    vpStatus = AtiFindAdapter(DeviceContext, NULL, NULL, &LegacyConfigInfo, &Again);
    Status = VpStatusToNtStatus(vpStatus);

    if (! NT_SUCCESS(Status))
    {
        //
        // Free the memory we allocated
        //

        ExFreePool(DeviceContext);
        return Status;
    }

    if (DeviceContext->pvHwOtherDevExt != NULL)
    {
        *NumberOfViews = 2;
    }

    //
    // Store the views. This should have been done in AtiAddDevice but to minimize
    // code changes we will leave it here. This has to be done before AtiInitialize
    // because we will enable interrupts.
    //

    ExtensionArray[0] = DeviceContext;
    ExtensionArray[1] = DeviceContext->pvHwOtherDevExt;

    Status = AtiInitialize(DeviceContext) ? STATUS_SUCCESS : STATUS_UNSUCCESSFUL;

    if (! NT_SUCCESS(Status))
    {
       ExFreePool(DeviceContext);


       return Status;
    }

    //
    // Finally, get the total number of children we have.
    //

    Status = AtiGetChildCount(MiniportDeviceContext, NumberOfChildren);


    return Status;
}



NTSTATUS
AtiStopDevice(
    IN PVOID MiniportDeviceContext
    )
{
    PHW_DEVICE_EXTENSION *ExtensionArray = MiniportDeviceContext;
    ULONG Count;
    NTSTATUS Status = STATUS_SUCCESS;
    PHW_DEVICE_EXTENSION    psHwExt;
    VP_STATUS vpStatus;

    PAGED_CODE();


    //
    // For now we'll just make this disable all the views to the point they
    // were set at boot time.
    //
    for (Count=0; Count < MAX_VIEWS; Count++)
    {
        psHwExt=(PHW_DEVICE_EXTENSION)ExtensionArray[Count];

        vpStatus = IoctlVideoResetDevice(psHwExt, NULL);
        Status = VpStatusToNtStatus(vpStatus);
        if (! NT_SUCCESS(Status))
        {
            break;
        }
    }

    // FreeResources will clear up for both hwexts
    psHwExt=(PHW_DEVICE_EXTENSION)ExtensionArray[0];
    FreeResources(psHwExt);


    if(psHwExt->ulFeatureFlags & FEATURE_AGPENABLE)
    {
        RtlZeroMemory(&gAgpServices, sizeof(gAgpServices));
    }

    if (gTimedOpServices.InterfaceDereference)
    {
        gTimedOpServices.InterfaceDereference(gTimedOpServices.Context);
    }
    RtlZeroMemory(&gTimedOpServices, sizeof(gTimedOpServices));

    // Now free exts
    if (ExtensionArray[1] != NULL)
    {
        psHwExt = InterlockedExchangePointer(&ExtensionArray[1], NULL);
        ExFreePool(psHwExt);
    }

    psHwExt = InterlockedExchangePointer(&ExtensionArray[0], NULL);
    ExFreePool(psHwExt);

    return Status;
}


NTSTATUS
AtiRemoveDevice(
    IN PVOID MiniportDeviceContext
    )
{
    PAGED_CODE();

    //Free miniport context
    ExFreePool(MiniportDeviceContext);

    return STATUS_SUCCESS;
}


NTSTATUS
AtiDispatchIoRequest(
    IN PVOID MiniportDeviceContext,
    IN ULONG ViewIndex,
    IN PVIDEO_REQUEST_PACKET VideoRequestPacket
    )
{
    PHW_DEVICE_EXTENSION *ExtensionArray = MiniportDeviceContext;
    PHW_DEVICE_EXTENSION HwDeviceExtension;

    PAGED_CODE();

    if (!ARGUMENT_PRESENT(MiniportDeviceContext) ||
        !ARGUMENT_PRESENT(VideoRequestPacket) ||
        ViewIndex > MAX_VIEWS)
    {
        return STATUS_INVALID_PARAMETER;
    }

    HwDeviceExtension = (PHW_DEVICE_EXTENSION)ExtensionArray[ViewIndex];

    if (AtiStartIO(HwDeviceExtension, VideoRequestPacket) != TRUE)
    {
        return STATUS_UNSUCCESSFUL;
    }

    return STATUS_SUCCESS;
}


BOOLEAN
AtiInterruptRoutine(
    PVOID MiniportDeviceContext,
    ULONG MessageNumber
    )
{
    PHW_DEVICE_EXTENSION *ExtensionArray = MiniportDeviceContext;
    PHW_DEVICE_EXTENSION HwDeviceExtension;

    UNREFERENCED_PARAMETER(MessageNumber);

    if (! ARGUMENT_PRESENT(MiniportDeviceContext))
    {
        return FALSE;
    }

    //
    // Just use the first device extension in the array. Note that this extension
    // might be NULL because we could be sharing an interrupt and get called here
    // before we initialize the array in AtiStartDevice.
    //

    HwDeviceExtension = (PHW_DEVICE_EXTENSION)ExtensionArray[0];


    if ((HwDeviceExtension == NULL) ||
        (HwDeviceExtension->InterruptsEnabled == FALSE))
    {
        return FALSE;
    }

    return AtiInterrupt(HwDeviceExtension);
}

VOID
AtiDpcRoutine(
    PVOID MiniportDeviceContext
    )
{
    //
    // This is the only type of DPC we can call for now.
    //
    Ati_PM4Interrupt_DPC(MiniportDeviceContext, NULL); 
    // Ati_PM4Interrupt_DPC just calls D3DDDINotifyDPC(HwDeviceExtension);
}


NTSTATUS
SetVidPnSourceStatus(
    IN PVOID MiniportDeviceContext,
    IN D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId,
    IN BOOLEAN Enable
    )
{
    PHW_DEVICE_EXTENSION *ExtensionArray = MiniportDeviceContext;
    PHW_DEVICE_EXTENSION HwDeviceExtension;
    NTSTATUS Status = STATUS_SUCCESS;
    VP_STATUS vpStatus;

    PAGED_CODE();

    DlDebugPrintEx((DEBUG_NORMAL, "SetVidPnSourceStatus: Enter\n"));

    if (! ARGUMENT_PRESENT(MiniportDeviceContext))
    {
        return STATUS_INVALID_PARAMETER;
    }

    //
    // Get the right extension for the index we want to Enable/Disable
    // NOTE: VidPN source IDs are assumed to be from a 0-based dense index set.
    //

    HwDeviceExtension = (PHW_DEVICE_EXTENSION)ExtensionArray[VidPnSourceId];

    if (Enable == TRUE)
    {
        DlDebugPrintEx((DEBUG_NORMAL, "SetVidPnSourceStatus: VidPN source %d is about to be attached to extended desktop.\n", VidPnSourceId));

        //
        // Switch on DualView support
        //

        //
        // Clear the flag on every call to NotifyVidPnSourceStatus
        //

        HwDeviceExtension->bFailExtendingDesktop = FALSE;

        if (! (HwDeviceExtension->ulMultiCrtcFlags & HW_MCRTC_VIEW_ENABLED))
        {
            vpStatus = vpsEnableView(HwDeviceExtension);
            Status = VpStatusToNtStatus(vpStatus);

            if (NT_SUCCESS(Status))
            {
                vTriggerEnumeration(HwDeviceExtension);
            }

            if (! (HwDeviceExtension->ulMultiCrtcFlags & HW_MCRTC_VIEW_ENABLED))
            {
                //
                // This could happen if we don't detect a monitor attached to the
                // second head. Just print an error message.
                //

                DlDebugPrintEx((DEBUG_ERROR, "SetVidPnSourceStatus: Failed to extend desktop since second monitor is not attached.\n"));
            }
        }
    }
    else
    {
        DlDebugPrintEx((DEBUG_NORMAL, "SetVidPnSourceStatus: VidPN source %d is about to be dettached from extended desktop.\n", VidPnSourceId));

        if (HwDeviceExtension->ulMultiCrtcFlags & HW_MCRTC_VIEW_ENABLED)
        {
            //
            // Switch off the view on this HDE. Force a call to ResetDevice
            // so that we can disable the view.
            //

            HwDeviceExtension->ulMultiCrtcFlags |= HW_MCRTC_DISABLE_VIEW;
            IoctlVideoResetDevice(HwDeviceExtension, NULL);
        }
    }

    return Status;
}


NTSTATUS
AtiGetChildCount(
    __in   PVOID pvMiniportDeviceContext,
    __out  PULONG ulChildCount
    )
{
    PHW_DEVICE_EXTENSION           *ppExtensionArray = pvMiniportDeviceContext;
    PHW_DEVICE_EXTENSION            pHwDeviceExtension;
    NTSTATUS                        Status = STATUS_SUCCESS;
    ACPI_EVAL_INPUT_BUFFER_COMPLEX  AcpiInputBuffer = {'\0'};
    UCHAR                           AcpiOutputBuffer[sizeof(ACPI_EVAL_OUTPUT_BUFFER) + 128] = {0};

    PAGED_CODE();

    if (!ARGUMENT_PRESENT(pvMiniportDeviceContext) ||
        !ARGUMENT_PRESENT(ulChildCount))
    {
        return STATUS_INVALID_PARAMETER;
    }

    *ulChildCount = 0;

    //
    // Always use the first extension for a query child relations
    //

    pHwDeviceExtension = (PHW_DEVICE_EXTENSION)ppExtensionArray[0];

    //
    // First, let's try enumerating any ACPI children, if this call fails, that
    // means we don't have any.
    //

    AcpiInputBuffer.Signature = ACPI_EVAL_INPUT_BUFFER_COMPLEX_SIGNATURE;
    AcpiInputBuffer.MethodNameAsUlong = ACPI_METHOD_DISPLAY_DOD;

    Status = DlEvalAcpiMethod(pHwDeviceExtension->DeviceHandle,
                              DISPLAY_ADAPTER_HW_ID,
                              &AcpiInputBuffer,
                              sizeof(ACPI_EVAL_INPUT_BUFFER_COMPLEX),
                              (PACPI_EVAL_OUTPUT_BUFFER)AcpiOutputBuffer,
                              sizeof(AcpiOutputBuffer));

    pHwDeviceExtension->AcpiChildren = NULL;

    if (NT_SUCCESS(Status))
    {
        //
        // Turn on hotkey switching notification mode.
        //

        AcpiInputBuffer.Signature = ACPI_EVAL_INPUT_BUFFER_COMPLEX_SIGNATURE;
        AcpiInputBuffer.MethodNameAsUlong = (ULONG)('SOD_');
        AcpiInputBuffer.Size = sizeof(ACPI_METHOD_ARGUMENT);
        AcpiInputBuffer.ArgumentCount = 1;
        AcpiInputBuffer.Argument[0].Type = ACPI_METHOD_ARGUMENT_INTEGER;
        AcpiInputBuffer.Argument[0].DataLength = sizeof(ULONG);
        AcpiInputBuffer.Argument[0].Argument = ACPI_ARG_ENABLE_SWITCH_EVENT;

        Status = DlEvalAcpiMethod(pHwDeviceExtension->DeviceHandle,
                                  DISPLAY_ADAPTER_HW_ID,
                                  &AcpiInputBuffer,
                                  sizeof(AcpiInputBuffer),
                                  NULL,
                                  0);

        if (!NT_SUCCESS(Status))
        {
            return Status;
        }

        *ulChildCount = ((PACPI_EVAL_OUTPUT_BUFFER)AcpiOutputBuffer)->Count;

        //
        // Store a pointer to our ACPI children in the device extension
        //

        pHwDeviceExtension->AcpiChildren = ExAllocatePoolWithTag(PagedPool,
                                                                 sizeof(AcpiOutputBuffer),
                                                                 ATI_TAG);

        if (pHwDeviceExtension->AcpiChildren == NULL)
        {
            return STATUS_INSUFFICIENT_RESOURCES;
        }

        RtlCopyMemory(pHwDeviceExtension->AcpiChildren, AcpiOutputBuffer, sizeof(AcpiOutputBuffer));
    }
    else
    {
        VP_STATUS VpStatus = 0;
        VIDEO_CHILD_ENUM_INFO ChildEnumInfo = {'\0'};
        PVIDEO_CHILD_DESCRIPTOR pVideoChildDescriptor;
        ULONG ulUnused = 0;

        //
        // We know we have ulNumberDisplays of possible displays but we don't know
        // about any other children (like codecs, etc). Let's start querying all
        // children above ulNumberDisplays to see how many we have.
        //

        ChildEnumInfo.Size = sizeof(VIDEO_CHILD_ENUM_INFO);
        ChildEnumInfo.ChildDescriptorSize = EDID_BUFFER_SIZE;

        *ulChildCount = pHwDeviceExtension->ulNumberDisplays;


        pVideoChildDescriptor = (PVIDEO_CHILD_DESCRIPTOR)ExAllocatePoolWithTag(PagedPool,
                                                                                   sizeof(VIDEO_CHILD_DESCRIPTOR),
                                                                                   ATI_TAG);

        if (pVideoChildDescriptor == NULL)
        {
                return STATUS_INSUFFICIENT_RESOURCES;
        }

        while (VpStatus != VIDEO_ENUM_NO_MORE_DEVICES)
        {
            ChildEnumInfo.ChildIndex = *ulChildCount+1;

            //  Enumerate all devices controlled by the ATI graphics chip.
            //  This includes DDC monitors attached to the board, as well as other devices
            //  which may be connected to a proprietary bus.

            VpStatus = AtiGetVideoChildDescriptor(pHwDeviceExtension,
                                                  &ChildEnumInfo,
                                                  &(pVideoChildDescriptor->Type),
                                                  (PUCHAR)pVideoChildDescriptor->Buffer,
                                                  &(pVideoChildDescriptor->UId),
                                                  &ulUnused);

            if (VpStatus != VIDEO_ENUM_NO_MORE_DEVICES)
            {
                (*ulChildCount)++;
            }

            //
            // We don't need this anymore.
            //

        }

        ExFreePoolWithTag(pVideoChildDescriptor, ATI_TAG);

    }

    //
    // Store the total number of children
    //

    pHwDeviceExtension->ChildCount = *ulChildCount;
    return STATUS_SUCCESS;
}


NTSTATUS
AtiQueryChildRelations(
    IN PVOID pvMiniportDeviceContext,
    IN OUT PDXGK_CHILD_DESCRIPTOR pChildRelations,
    IN ULONG ChildRelationsSize
    )
{
    PHW_DEVICE_EXTENSION *ppExtensionArray = pvMiniportDeviceContext;
    PHW_DEVICE_EXTENSION pHwDeviceExtension;
    ULONG RequiredSize;
    PACPI_METHOD_ARGUMENT AcpiArguments = NULL;
    ULONG ulChildIndex;


    PAGED_CODE();

    if (! ARGUMENT_PRESENT(pvMiniportDeviceContext) ||
        ! ARGUMENT_PRESENT(pChildRelations))
    {
        return STATUS_INVALID_PARAMETER;
    }

    //
    // Always use the first extension for a query child relations
    //

    pHwDeviceExtension = (PHW_DEVICE_EXTENSION)ppExtensionArray[0];

    //
    // Verify the passed in array size.
    //

    RequiredSize = pHwDeviceExtension->ChildCount * sizeof(DXGK_CHILD_DESCRIPTOR);

    if (RequiredSize > ChildRelationsSize)
    {
        return STATUS_BUFFER_TOO_SMALL;
    }


    if (pHwDeviceExtension->AcpiChildren != NULL)
    {
        AcpiArguments = &(((PACPI_EVAL_OUTPUT_BUFFER)pHwDeviceExtension->AcpiChildren)->Argument[0]);

    }

    //
    // If we have ACPI children, enumerate those, otherwise enumerate what we find.
    //

    if (AcpiArguments != NULL)
    {
        //
        // Make the first child always the LCD to indicate our preference for it.
        // NOTE: This is hardcoded in the R200 but is not production quality code.
        //

        pChildRelations[0].AcpiUid = 0x110;
        pChildRelations[0].ChildUid = pChildRelations[0].AcpiUid | HW_ID_DISPLAY_CHILD;
        pChildRelations[0].ChildDeviceType = TypeVideoOutput;
        pChildRelations[0].ChildCapabilities.HpdAwareness = HpdAwarenessAlwaysConnected;
        pChildRelations[0].ChildCapabilities.Type.VideoOutput.InterfaceTechnology = D3DKMDT_VOT_HD15;
        pChildRelations[0].ChildCapabilities.Type.VideoOutput.MonitorOrientationAwareness = D3DKMDT_MOA_NONE;
        pChildRelations[0].ChildCapabilities.Type.VideoOutput.SupportsSdtvModes = FALSE;

        //
        // Now fill in the rest.
        //

        for (ulChildIndex = 1; ulChildIndex < pHwDeviceExtension->ChildCount; ulChildIndex++, AcpiArguments++)
        {
            ASSERT(AcpiArguments->Type == ACPI_METHOD_ARGUMENT_INTEGER);
            ASSERT(AcpiArguments->DataLength == sizeof(ULONG));

            if ((AcpiArguments->Argument & ACPI_HARDWARE_ID) == 0x110)
            {
                //
                // This is the LCD which we already enumerated first. Skip it now.
                //

                ulChildIndex--;
                continue;
            }

            pChildRelations[ulChildIndex].AcpiUid = AcpiArguments->Argument & ACPI_HARDWARE_ID;
            pChildRelations[ulChildIndex].ChildUid = pChildRelations[ulChildIndex].AcpiUid | HW_ID_DISPLAY_CHILD;

            if (AcpiArguments->Argument & ACPI_NON_VIDEO_OUTPUT_DEVICE)
            {
               pChildRelations[ulChildIndex].ChildDeviceType = TypeOther;
               pChildRelations[ulChildIndex].ChildCapabilities.HpdAwareness = HpdAwarenessAlwaysConnected;
               pChildRelations[ulChildIndex].ChildCapabilities.Type.Other.MustBeZero = 0;
            }
            else
            {
                pChildRelations[ulChildIndex].ChildDeviceType = TypeVideoOutput;
                pChildRelations[ulChildIndex].ChildCapabilities.HpdAwareness = HpdAwarenessPolled;
                pChildRelations[ulChildIndex].ChildCapabilities.Type.VideoOutput.InterfaceTechnology = D3DKMDT_VOT_HD15;
                pChildRelations[ulChildIndex].ChildCapabilities.Type.VideoOutput.MonitorOrientationAwareness = D3DKMDT_MOA_NONE;
            }

            pChildRelations[ulChildIndex].ChildCapabilities.Type.VideoOutput.SupportsSdtvModes = FALSE;
        }
    }
    else
    {
        VIDEO_CHILD_ENUM_INFO ChildEnumInfo = {'\0'};
        PVIDEO_CHILD_DESCRIPTOR pVideoChildDescriptor;
        VP_STATUS VpStatus = 0;
        ULONG ulUnused = 0;
        DXGK_CHILD_DEVICE_TYPE ChildDeviceType;
        DXGK_CHILD_CAPABILITIES ChildCapabilities;

        //
        // Fill in the pChildRelations with our children.
        //

        pVideoChildDescriptor = (PVIDEO_CHILD_DESCRIPTOR)ExAllocatePoolWithTag(PagedPool,
                                                                                   sizeof(VIDEO_CHILD_DESCRIPTOR),
                                                                                   ATI_TAG);

        if (pVideoChildDescriptor == NULL)
        {
            return STATUS_INSUFFICIENT_RESOURCES;
        }


        for (ulChildIndex = 0; ulChildIndex < pHwDeviceExtension->ChildCount; ulChildIndex++)
        {
            //
            // Try to see what kind of device this is
            //

            ChildEnumInfo.ChildIndex = ulChildIndex + 1;

            VpStatus = AtiGetVideoChildDescriptor(pHwDeviceExtension,
                                                  &ChildEnumInfo,
                                                  &(pVideoChildDescriptor->Type),
                                                  (PUCHAR)pVideoChildDescriptor->Buffer,
                                                  &(pVideoChildDescriptor->UId),
                                                  &ulUnused);

            //
            // If this is any of our video outputs, report it to the OS
            //

            if (ulChildIndex < pHwDeviceExtension->ulNumberDisplays)
            {

                ChildDeviceType = TypeVideoOutput;

                // Determine video output technology
                {

                    // Assign video output types based on the R200 child indices (which are hopefully hardcoded for all R200 display adapters).
                    switch ( ulChildIndex )
                    {
                        case 0:
                        {
                            ChildCapabilities.Type.VideoOutput.InterfaceTechnology = D3DKMDT_VOT_HD15;
                            break;
                        }

                        case 1:
                        {
                            ChildCapabilities.Type.VideoOutput.InterfaceTechnology = D3DKMDT_VOT_DVI;
                            break;
                        }

                        case 2:
                        {
                            ChildCapabilities.Type.VideoOutput.InterfaceTechnology = D3DKMDT_VOT_SVIDEO_4PIN;
                            break;
                        }

                        // NOTE: This video output is accessible via dongle connected to DVI video interface.
                        case 3:
                        {
                            ChildCapabilities.Type.VideoOutput.InterfaceTechnology = D3DKMDT_VOT_RCA_3COMPONENT;
                            break;
                        }

                        // NOTE: This video output is accessible via dongle connected to DVI video interface.
                        case 4:
                        {
                            ChildCapabilities.Type.VideoOutput.InterfaceTechnology = D3DKMDT_VOT_HD15;
                            break;
                        }

                        default:
                        {
                            ChildCapabilities.Type.VideoOutput.InterfaceTechnology = D3DKMDT_VOT_OTHER;
                            break;
                        }
                    }
                }

                //
                // R200 supports interruptible HPD only on DVI video outputs.
                //

                switch ( ChildCapabilities.Type.VideoOutput.InterfaceTechnology )
                {
                    case D3DKMDT_VOT_DVI:
                    {
                        ChildCapabilities.HpdAwareness = HpdAwarenessInterruptible;
                    }
                    break;

                    case D3DKMDT_VOT_HD15:
                    case D3DKMDT_VOT_SVIDEO_4PIN:
                    case D3DKMDT_VOT_RCA_3COMPONENT:
                    {
                        ChildCapabilities.HpdAwareness = HpdAwarenessPolled;
                    }
                    break;

                    default:
                    {
                        ChildCapabilities.HpdAwareness = HpdAwarenessNone;
                    }
                    break;
                }

                ChildCapabilities.Type.VideoOutput.MonitorOrientationAwareness = D3DKMDT_MOA_NONE;  // R200 doesn't support monitor orientation awareness.

                ChildCapabilities.Type.VideoOutput.SupportsSdtvModes = FALSE;
            }
            else
            {
                ChildDeviceType                              = TypeOther;
                ChildCapabilities.HpdAwareness               = HpdAwarenessAlwaysConnected;
                ChildCapabilities.Type.Other.MustBeZero      = 0;
            }

            pChildRelations[ulChildIndex].ChildDeviceType      = ChildDeviceType;
            pChildRelations[ulChildIndex].ChildCapabilities    = ChildCapabilities;
            pChildRelations[ulChildIndex].AcpiUid              = 0;
            pChildRelations[ulChildIndex].ChildUid             = HW_ID_DISPLAY_CHILD | ulChildIndex;

        }

        ExFreePoolWithTag(pVideoChildDescriptor, ATI_TAG);

    }

    return STATUS_SUCCESS;
}


NTSTATUS
AtiQueryChildStatus(
    IN PVOID MiniportDeviceContext,
    IN PDXGK_CHILD_STATUS ChildStatus,
    IN BOOLEAN NonDestructiveOnly
    )
{
    PHW_DEVICE_EXTENSION *ExtensionArray = MiniportDeviceContext;
    PHW_DEVICE_EXTENSION pHwDeviceExtension;

    PAGED_CODE();


    if (!ARGUMENT_PRESENT(MiniportDeviceContext) ||
        !ARGUMENT_PRESENT(ChildStatus))
    {
        return STATUS_INVALID_PARAMETER;
    }

    //
    // Always use the first extension for a query child status
    //

    pHwDeviceExtension = (PHW_DEVICE_EXTENSION)ExtensionArray[0];

    if (ChildStatus->Type == StatusConnection)
    {
        ULONG ulChildIndex;

        //
        // Initialize connected to FALSE;
        //

        ChildStatus->HotPlug.Connected = FALSE;

        ulChildIndex = ChildStatus->ChildUid & ~HW_ID_DISPLAY_CHILD;

        // If we can do this destructively, then call DAL to determine which
        // display devices are physically connected

        if (NonDestructiveOnly == FALSE)
        {
            if (GetConnectedDisplays(pHwDeviceExtension) != NO_ERROR)
            {
                ASSERT(FALSE);
                return ERROR_INVALID_PARAMETER;
            }

            switch (ulChildIndex)
            {
                case HW_ID_ACPI_MONITOR:
                    if ((pHwDeviceExtension->ulConnectedDisplays) &
                        (pHwDeviceExtension->ulaDisplayTypeVector[DISPLAY_MONITOR]))
                    {
                        ChildStatus->HotPlug.Connected = TRUE;
                    }
                    break;

                case HW_ID_ACPI_TV:
                    if ((pHwDeviceExtension->ulConnectedDisplays) &
                        (pHwDeviceExtension->ulaDisplayTypeVector[DISPLAY_TELEVISION]))
                    {
                        ChildStatus->HotPlug.Connected = TRUE;
                    }
                    break;

                case HW_ID_ACPI_FLAT_PANEL:
                    if ((pHwDeviceExtension->ulConnectedDisplays) &
                        (pHwDeviceExtension->ulaDisplayTypeVector[DISPLAY_LCDPANEL]))
                    {
                        ChildStatus->HotPlug.Connected = TRUE;
                    }
                    break;

                case HW_ID_ACPI_DIGITAL_FLAT_PANEL:
                    if ((pHwDeviceExtension->ulConnectedDisplays) &
                        (pHwDeviceExtension->ulaDisplayTypeVector[DISPLAY_DIGITALFLATPANEL]))
                    {
                        ChildStatus->HotPlug.Connected = TRUE;
                    }
                    break;

                default:
                    // Non-ACPI child displays
                    if (ChildStatus->ChildUid & HW_ID_DISPLAY_CHILD)
                    {
                        if (pHwDeviceExtension->ulConnectedDisplays &
                            (1 << EXTRACT_DISPLAY_INDEX(ChildStatus->ChildUid)))
                        {
                            ChildStatus->HotPlug.Connected = TRUE;
                        }
                    }
                    else
                    {
                        DlDebugPrintEx((DEBUG_ERROR, "Querying status for unknown child: HdId = 0x%08X\n", ChildStatus->ChildUid));
                        ASSERT(FALSE);
                        return ERROR_INVALID_PARAMETER;
                    }

                    break;
            }
        }
        else
        {
            VIDEO_CHILD_ENUM_INFO ChildEnumInfo = {'\0'};
            PVIDEO_CHILD_DESCRIPTOR VideoChildDescriptor;
            VP_STATUS VpStatus;
            ULONG Unused = 0;

            //
            // This must be a non-destructive poll. If this is an HD15 or DVI
            // video output then try to get the EDID, otherwise return FALSE
            // since we don't know.
            //

            ChildEnumInfo.Size = sizeof(VIDEO_CHILD_ENUM_INFO);
            ChildEnumInfo.ChildDescriptorSize = EDID_BUFFER_SIZE;

            if (pHwDeviceExtension->AcpiChildren == NULL)
            {
                //
                // This is not an ACPI device.
                //
                switch (ulChildIndex)
                {
                    // DVI and HD-15 support I2C based monitor descriptor acquisition.
                    case 0: // HD15
                    case 1: // DVI
                    case 4: // HD15 on DVI dongle
                        //
                        // Query the descriptor for this child
                        //
                        ChildEnumInfo.ChildIndex = ulChildIndex+1;
                        break;

                    // Assume all other video output interface types don't support monitor descriptor acquisition.
                    // The status code lets DxgKrnl know that there is no point in retrying
                    case 2: // SVIDEO
                    case 3: // RCA on DVI dongle
                    default:
                        //
                        // Report false since we don't know.
                        //
                        ChildStatus->HotPlug.Connected = FALSE;
                        return STATUS_SUCCESS;
                }
            }
            else
            {
                //
                // ACPI monitors
                //
                switch (ulChildIndex)
                {
                    case HW_ID_ACPI_MONITOR:
                    case HW_ID_ACPI_TV:
                    case HW_ID_ACPI_FLAT_PANEL:
                    case HW_ID_ACPI_DIGITAL_FLAT_PANEL:
                        ChildEnumInfo.ChildIndex = 0;
                        ChildEnumInfo.ACPIHwId = ulChildIndex;
                        break;
                    default:
                        //
                        // Report false since we don't know.
                        //
                        ChildStatus->HotPlug.Connected = FALSE;
                        return STATUS_SUCCESS;
                }
            }

            VideoChildDescriptor = ExAllocatePoolWithTag(PagedPool,
                                                         sizeof(VIDEO_CHILD_DESCRIPTOR),
                                                         ATI_TAG);

            if (VideoChildDescriptor == NULL)
            {
                return STATUS_INSUFFICIENT_RESOURCES;
            }

            RtlZeroMemory(VideoChildDescriptor, sizeof(VIDEO_CHILD_DESCRIPTOR));

            VpStatus = AtiGetVideoChildDescriptor(pHwDeviceExtension,
                                                  &ChildEnumInfo,
                                                  &(VideoChildDescriptor->Type),
                                                  (PUCHAR)VideoChildDescriptor->Buffer,
                                                  &(VideoChildDescriptor->UId),
                                                  &Unused);

            if ((((UNALIGNED ULONG*)VideoChildDescriptor->Buffer)[0] == 0xFFFFFF00) &&
                (((UNALIGNED ULONG*)VideoChildDescriptor->Buffer)[1] == 0x00FFFFFF))
            {
                ChildStatus->HotPlug.Connected = TRUE;
            }

            ExFreePoolWithTag(VideoChildDescriptor, ATI_TAG);
        }
    }


    return STATUS_SUCCESS;
}


NTSTATUS
AtiQueryDeviceDescriptor(
    IN_CONST_PVOID MiniportDeviceContext,
    IN_ULONG ChildUid,
    INOUT_PDXGK_DEVICE_DESCRIPTOR DeviceDescriptor
    )
{
    PHW_DEVICE_EXTENSION   *ExtensionArray = MiniportDeviceContext;
    PHW_DEVICE_EXTENSION    HwDeviceExtension = NULL;
    VIDEO_CHILD_ENUM_INFO   ChildEnumInfo = {'\0'};
    PVIDEO_CHILD_DESCRIPTOR VideoChildDescriptor = NULL;
    VP_STATUS               VpStatus;
    ULONG                   Unused = 0;
    ULONG                   ulChildIndex;
    NTSTATUS                Status = STATUS_SUCCESS;
    int                     nLen = 0;


    PAGED_CODE();


    if (! ARGUMENT_PRESENT(MiniportDeviceContext) ||
        ! ARGUMENT_PRESENT(DeviceDescriptor))
    {
        Status = STATUS_INVALID_PARAMETER;
        goto cleanup;
    }


    //
    // Always use the first extension for this function
    //

    HwDeviceExtension = (PHW_DEVICE_EXTENSION)ExtensionArray[0];


    //
    // If this is a video output child device and does not support an EDID we
    // want to fail out early
    //
    ulChildIndex = ChildUid & ~HW_ID_DISPLAY_CHILD;

    ChildEnumInfo.Size = sizeof(VIDEO_CHILD_ENUM_INFO);
    ChildEnumInfo.ChildDescriptorSize = EDID_BUFFER_SIZE;

    if(ulChildIndex < HwDeviceExtension->ulNumberDisplays)
    {
        switch (ulChildIndex)
        {
        // DVI and HD-15 support I2C based monitor descriptor acquisition.
        case 0: // HD15
        case 1: // DVI
        case 4: // HD15 on DVI dongle
            break;

        // Assume all other video output interface types don't support monitor descriptor acquisition.
        // The status code lets DxgKrnl know that there is no point in retrying
        case 2: // SVIDEO
        case 3: // RCA on DVI dongle
        default:
            Status = STATUS_GRAPHICS_CHILD_DESCRIPTOR_NOT_SUPPORTED;
            goto cleanup;
        }

        //
        // Query the descriptor for this child
        //

        ChildEnumInfo.ChildIndex = ulChildIndex+1;
        if(DeviceDescriptor->DescriptorOffset != 0)
        {
            //For these child devices we do not support extension blocks
            Status = STATUS_MONITOR_NO_MORE_DESCRIPTOR_DATA;
            goto cleanup;
        }
    }
    else
    {
        //
        // ACPI monitors
        //
        switch (ulChildIndex)
        {
        case HW_ID_ACPI_MONITOR:
        case HW_ID_ACPI_TV:
        case HW_ID_ACPI_FLAT_PANEL:
        case HW_ID_ACPI_DIGITAL_FLAT_PANEL:
            ChildEnumInfo.ChildIndex = 0;
            ChildEnumInfo.ACPIHwId = ulChildIndex;
            break;
        default:
            {
            // non video output device have to return _DXGK_GENERIC_DESCRIPTOR structure
            // The R200 sample driver provides bogus strings. Production driver should supply appropriate information
			// to allow PnP Mngr locate appropriate INF and load FDO. PDO for the device has been created by DxgPort.

            static WCHAR wcHardwareId[]  = L"Your Hardware ID\0";
            static WCHAR wcInstanceId[]  = L"Your Instance_ID\0";
            static WCHAR wcCompatibleId[]= L"Your Comp_ID1\0 Your CompID2\0";
            static WCHAR wcDeviceText[]  = L"Your Device Text\0";	//	the string will be displayed if no INF found

            PDXGK_GENERIC_DESCRIPTOR pGenDesc = (PDXGK_GENERIC_DESCRIPTOR) DeviceDescriptor;
            RtlZeroMemory(pGenDesc, sizeof(DXGK_GENERIC_DESCRIPTOR));
            RtlCopyMemory( pGenDesc->HardwareId,wcHardwareId,sizeof(wcHardwareId));
            RtlCopyMemory( pGenDesc->InstanceId,wcInstanceId,sizeof(wcInstanceId));
            RtlCopyMemory( pGenDesc->CompatibleId,wcCompatibleId,sizeof(wcCompatibleId));
            RtlCopyMemory( pGenDesc->DeviceText,wcDeviceText,sizeof(wcDeviceText));

            return Status;
            }
        }
    }


    VideoChildDescriptor = ExAllocatePoolWithTag(PagedPool,
                                                 sizeof(VIDEO_CHILD_DESCRIPTOR),
                                                 ATI_TAG);

    if (VideoChildDescriptor == NULL)
    {
        Status = STATUS_INSUFFICIENT_RESOURCES;
        goto cleanup;
    }

    RtlZeroMemory(VideoChildDescriptor, sizeof(VIDEO_CHILD_DESCRIPTOR));
    VpStatus = AtiGetVideoChildDescriptor(HwDeviceExtension,
                                          &ChildEnumInfo,
                                          &(VideoChildDescriptor->Type),
                                          (PUCHAR)VideoChildDescriptor->Buffer,
                                          &(VideoChildDescriptor->UId),
                                          &Unused);

    if (VpStatus == VIDEO_ENUM_INVALID_DEVICE)
    {
        Status = STATUS_INVALID_PARAMETER;
        goto cleanup;
    }

    else if(VpStatus == STATUS_MONITOR_NO_MORE_DESCRIPTOR_DATA)
    {
        Status = VpStatus;
        goto cleanup;
    }

    //
    // Save the buffer pointer
    //

    ASSERT(DeviceDescriptor->DescriptorBuffer != NULL);

    //
    // Fill in the appropriate form of descriptor based on the child type
    //
    if (ChildEnumInfo.ChildIndex <= HwDeviceExtension->ulNumberDisplays)
    {
        nLen = ( sizeof(VideoChildDescriptor->Buffer) < DeviceDescriptor->DescriptorLength ?
                 sizeof(VideoChildDescriptor->Buffer) : DeviceDescriptor->DescriptorLength );
        RtlCopyMemory( DeviceDescriptor->DescriptorBuffer,
                       VideoChildDescriptor->Buffer,
                       nLen );
    }
    else
    {
        UNICODE_STRING  HardwareIdString;
        PDXGK_GENERIC_DESCRIPTOR GenericDescriptor;

        RtlInitUnicodeString(&HardwareIdString, (PCWSTR)VideoChildDescriptor->Buffer);

        GenericDescriptor = (PDXGK_GENERIC_DESCRIPTOR)DeviceDescriptor->DescriptorBuffer;
        ASSERT(DeviceDescriptor->DescriptorLength >= sizeof(DXGK_GENERIC_DESCRIPTOR));

        nLen = ( HardwareIdString.Length < sizeof(GenericDescriptor->HardwareId) ?
                 HardwareIdString.Length : sizeof(GenericDescriptor->HardwareId) );
        RtlCopyMemory( GenericDescriptor->HardwareId, HardwareIdString.Buffer, nLen );

        if ( FAILED(StringCchPrintfW( GenericDescriptor->InstanceId,
                                      sizeof(GenericDescriptor->InstanceId)/sizeof(WCHAR),
                                      L"%x",
                                      ChildUid )))
        {
            GenericDescriptor->InstanceId[0] = 0;
        }

        RtlCopyMemory(GenericDescriptor->DeviceText, L"Display Child Device", 20*sizeof(WCHAR));
    }

cleanup:

    if (VideoChildDescriptor != NULL)
    {
        //
        // We don't need this anymore.
        //

        ExFreePoolWithTag(VideoChildDescriptor, ATI_TAG);
    }

    return Status;
}


NTSTATUS
AtiSetPowerState(
    IN PVOID MiniportDeviceContext,
    IN ULONG HardwareUid,
    IN DEVICE_POWER_STATE DevicePowerState,
    IN POWER_ACTION ActionType
    )
{
    PHW_DEVICE_EXTENSION *ExtensionArray = MiniportDeviceContext;
    NTSTATUS Status;
    PHW_DEVICE_EXTENSION HwDeviceExtension;
    VIDEO_POWER_MANAGEMENT VideoPowerManagement;
    VP_STATUS VpStatus;

    if (!ARGUMENT_PRESENT(MiniportDeviceContext))
    {
        Status = STATUS_INVALID_PARAMETER;
        goto cleanup;
    }

    //
    // Always use the first extension for this function
    //

    HwDeviceExtension = (PHW_DEVICE_EXTENSION)ExtensionArray[0];

    //
    // If this is a power-down, mask off all interrupts.
    // NON_PRODUCTION_CODE: This is to work around a bug in the R200 that
    // doesn't handle shared interrupts very well. Production code should not
    // have this.
    //

    if (HardwareUid == DISPLAY_ADAPTER_HW_ID)
    {
        if (DevicePowerState > PowerDeviceD0)
        {

            HwDeviceExtension->InterruptsEnabled = FALSE;
        }
        else
        {

            HwDeviceExtension->InterruptsEnabled = TRUE;
        }
    }

    //
    // Production code is expected to re-implement this function properly here.
    // For now we'll just use the XP-style function.
    //

    VideoPowerManagement.Length = sizeof(VIDEO_POWER_MANAGEMENT);
    VideoPowerManagement.Length = 0;
    VideoPowerManagement.PowerState = DevicePowerState;

    if ((ActionType == PowerActionHibernate) &&
        (DevicePowerState > PowerDeviceD0))
    {
        VideoPowerManagement.PowerState = VideoPowerHibernate;
    }
    else if ((ActionType >= PowerActionShutdown) &&
             (ActionType < PowerActionWarmEject) &&
             (DevicePowerState > PowerDeviceD0))
    {
        VideoPowerManagement.PowerState = VideoPowerShutdown;
    }

    VpStatus = AtipSetPowerState(HwDeviceExtension, HardwareUid, &VideoPowerManagement);
    Status = VpStatusToNtStatus(VpStatus);

    cleanup:

    //
    // This function should NEVER fail according to the LDDM specs.
    // AtipSetPowerState() can only fail on an invalid parameter.
    //

    if (!NT_SUCCESS(Status))
    {
        ASSERTMSG("Invalid parameter passed in to AtiSetPowerState.", FALSE);
    }

    return STATUS_SUCCESS;
}

//
// Forward declaration here for simplicity. This function is not used by any other function
// other than AtiNotifyAcpiEventCallback.
//
NTSTATUS
InvalidateVidPnForHotKey
(
    PHW_DEVICE_EXTENSION CONST i_pvInterfaceContext,
    VOID* CONST i_pvChildrenContext
);

NTSTATUS
AtiNotifyAcpiEvent(
    IN PVOID MiniportDeviceContext,
    IN DXGK_EVENT_TYPE EventType,
    IN ULONG Event,
    IN PVOID Argument,
    OUT PULONG AcpiFlags
    )
{
    PHW_DEVICE_EXTENSION *ExtensionArray = MiniportDeviceContext;
    NTSTATUS Status = STATUS_SUCCESS;
    PHW_DEVICE_EXTENSION HwDeviceExtension;
    ACPI_EVAL_INPUT_BUFFER_COMPLEX AcpiInputBuffer = {'\0'};

    if (!ARGUMENT_PRESENT(MiniportDeviceContext))
    {
        Status = STATUS_INVALID_PARAMETER;
        goto cleanup;
    }

    //
    // Always use the first extension for this function
    //

    HwDeviceExtension = (PHW_DEVICE_EXTENSION)ExtensionArray[0];

    if ((EventType == DxgkAcpiEvent) && (Event == ACPI_NOTIFY_PANEL_SWITCH))
    {
        //
        // The OS is telling us there might be a hotkey event going in. Confirm
        // this is true by querying the system BIOS and ask the OS to poll
        // for new children and change the display mode.
        //

        *AcpiFlags |= (DXGK_ACPI_POLL_DISPLAY_CHILDREN | DXGK_ACPI_CHANGE_DISPLAY_MODE);
    }

cleanup:

    return Status;
}


VOID
AtiResetDevice(
    IN PVOID MiniportDeviceContext
    )
{
    PHW_DEVICE_EXTENSION *ExtensionArray = MiniportDeviceContext;
    PHW_DEVICE_EXTENSION HwDeviceExtension;

    //
    // Always use the first extension for this function
    //

    HwDeviceExtension = (PHW_DEVICE_EXTENSION)ExtensionArray[0];
    
//  Put the graphics card into a text mode (80,50)

    AtiResetHw(HwDeviceExtension, 80, 50);

    return;
}


VOID
AtiUnload(
    VOID
    )
{
    PAGED_CODE();

    //
    // This function just undoes whatever DriverEntry did.
    //
    //
    return;
}

NTSTATUS
AtiQueryInterface(
    IN PVOID MiniportDeviceContext,
    IN PQUERY_INTERFACE QueryInterface
    )
{
    PHW_DEVICE_EXTENSION *ExtensionArray = MiniportDeviceContext;
    PHW_DEVICE_EXTENSION HwDeviceExtension;

    PAGED_CODE();

    //
    // Always use the first extension for this function
    //

    HwDeviceExtension = (PHW_DEVICE_EXTENSION)ExtensionArray[0];

    return AtiQueryInterfaceEx(HwDeviceExtension,
                               QueryInterface);
}


NTSTATUS
DriverEntry(
    IN PDRIVER_OBJECT DriverObject,
    IN PUNICODE_STRING RegistryPath
    )
{
    DRIVER_INITIALIZATION_DATA DriverInitializationData = {'\0'};

    if (! ARGUMENT_PRESENT(DriverObject) ||
        ! ARGUMENT_PRESENT(RegistryPath))
    {
        return STATUS_INVALID_PARAMETER;
    }

    //
    // Fill in the DriverInitializationData structure and call DlInitialize()
    //

    DriverInitializationData.Version                        = DXGKDDI_INTERFACE_VERSION;

    
    DriverInitializationData.DxgkDdiAddDevice               = AtiAddDevice;
    DriverInitializationData.DxgkDdiStartDevice             = AtiStartDevice;
    DriverInitializationData.DxgkDdiStopDevice              = AtiStopDevice;
    DriverInitializationData.DxgkDdiRemoveDevice            = AtiRemoveDevice;
    DriverInitializationData.DxgkDdiDispatchIoRequest       = AtiDispatchIoRequest;
    DriverInitializationData.DxgkDdiInterruptRoutine        = AtiInterruptRoutine;
    DriverInitializationData.DxgkDdiDpcRoutine              = AtiDpcRoutine;
    DriverInitializationData.DxgkDdiQueryChildRelations     = AtiQueryChildRelations;
    DriverInitializationData.DxgkDdiQueryChildStatus        = AtiQueryChildStatus;
    DriverInitializationData.DxgkDdiQueryDeviceDescriptor   = AtiQueryDeviceDescriptor;
    DriverInitializationData.DxgkDdiSetPowerState           = AtiSetPowerState;
    DriverInitializationData.DxgkDdiNotifyAcpiEvent         = AtiNotifyAcpiEvent;
    DriverInitializationData.DxgkDdiResetDevice             = AtiResetDevice;
    DriverInitializationData.DxgkDdiUnload                  = AtiUnload;
    DriverInitializationData.DxgkDdiQueryInterface          = AtiQueryInterface;
    DriverInitializationData.DxgkDdiControlEtwLogging       = D3DDDIControlEtwLogging;

    DriverInitializationData.DxgkDdiQueryAdapterInfo        = D3DDDIQueryAdapterInfo;
    DriverInitializationData.DxgkDdiCreateDevice            = D3DDDICreateDevice;
    DriverInitializationData.DxgkDdiCreateAllocation        = D3DDDICreateAllocation;
    DriverInitializationData.DxgkDdiDestroyAllocation       = D3DDDIDestroyAllocation;


    DriverInitializationData.DxgkDdiDescribeAllocation      = D3DDDIDescribeAllocation;
    DriverInitializationData.DxgkDdiGetStandardAllocationDriverData = D3DDDIGetStandardAllocationDriverData;

    DriverInitializationData.DxgkDdiAcquireSwizzlingRange   = D3DDDIAcquireSwizzlingRange;
    DriverInitializationData.DxgkDdiReleaseSwizzlingRange   = D3DDDIReleaseSwizzlingRange;

    DriverInitializationData.DxgkDdiOpenAllocation          = D3DDDIOpenAllocation;
    DriverInitializationData.DxgkDdiCloseAllocation          = D3DDDICloseAllocation;

    DriverInitializationData.DxgkDdiPatch                   = D3DDDIPatchDmaBuffer;
    DriverInitializationData.DxgkDdiSubmitCommand           = D3DDDISubmitCommand;
    DriverInitializationData.DxgkDdiBuildPagingBuffer       = D3DDDIBuildPagingBuffer;
    DriverInitializationData.DxgkDdiSetPalette              = D3DDDISetPalette;
    DriverInitializationData.DxgkDdiSetPointerShape         = D3DDDISetPointerShape;
    DriverInitializationData.DxgkDdiSetPointerPosition      = D3DDDISetPointerPosition;
    DriverInitializationData.DxgkDdiPreemptCommand          = D3DDDIPreemptCommand;

    DriverInitializationData.DxgkDdiDestroyDevice           = D3DDDIDestroyDevice;
    // DriverInitializationData.DxgkDdiCloseAllocation;
    // DriverInitializationData.DxgkDdiOpenAllocation;
    DriverInitializationData.DxgkDdiRender                  = D3DDDIRender;
    DriverInitializationData.DxgkDdiPresent                 = D3DDDIPresent;
    DriverInitializationData.DxgkDdiResetFromTimeout        = D3DDDIResetFromTimeout;
    DriverInitializationData.DxgkDdiRestartFromTimeout      = D3DDDIRestartFromTimeout;
    DriverInitializationData.DxgkDdiEscape                  = D3DDDIEscape;
    DriverInitializationData.DxgkDdiCollectDbgInfo          = D3DDDICollectDbgInfo;
    DriverInitializationData.DxgkDdiQueryCurrentFence       = D3DDDIQueryCurrentFence;
    DriverInitializationData.DxgkDdiControlInterrupt        = D3DDDIControlInterrupt;
    DriverInitializationData.DxgkDdiGetScanLine             = D3DDDIGetScanLine;

    DriverInitializationData.DxgkDdiSetVidPnSourceAddress        = D3DDDISetVidPnSourceAddress;
    DriverInitializationData.DxgkDdiSetVidPnSourceVisibility     = D3DDDISetVidPnSourceVisibility;
    DriverInitializationData.DxgkDdiUpdateActiveVidPnPresentPath = D3DDDIUpdateActiveVidPnPresentPath;
    DriverInitializationData.DxgkDdiCommitVidPn                  = D3DDDICommitVidPn;
    DriverInitializationData.DxgkDdiRecommendMonitorModes        = D3DDDIRecommendMonitorModes;
    DriverInitializationData.DxgkDdiRecommendVidPnTopology       = D3DDDIRecommendVidPnTopology;

    DriverInitializationData.DxgkDdiCreateContext              = D3DDDICreateContext;
    DriverInitializationData.DxgkDdiDestroyContext             = D3DDDIDestroyContext;


    {
        enum
        {
            MMDMM_SUPPORT_DISABLED    = 0,
            MMDMM_SUPPORT_XDDM_PARITY = 1,
            MMDMM_SUPPORT_TEST        = 2
        };

        // Default MMDMM support in the sample miniport is Xddm parity.
        DWORD dwMMDMMSupportType = MMDMM_SUPPORT_XDDM_PARITY;

        RTL_QUERY_REGISTRY_TABLE QueryTable[2];

        RtlZeroMemory(&QueryTable[0], sizeof(QueryTable));

        QueryTable[0].QueryRoutine  = NULL;
        QueryTable[0].Flags         = RTL_QUERY_REGISTRY_DIRECT;
        QueryTable[0].Name          = L"MMDMMSupportType";
        QueryTable[0].EntryContext  = &dwMMDMMSupportType;
        QueryTable[0].DefaultType   = REG_NONE;
        QueryTable[0].DefaultData   = NULL;
        QueryTable[0].DefaultLength = sizeof(DWORD);

        RtlQueryRegistryValues(RTL_REGISTRY_SERVICES,
                               L"R200",
                               QueryTable,
                               NULL,
                               NULL);

        switch ( dwMMDMMSupportType )
        {
            case MMDMM_SUPPORT_XDDM_PARITY:
            {
                DriverInitializationData.DxgkDdiRecommendFunctionalVidPn = D3DDDIRecommendFunctionalVidPn_XddmParity;
                DriverInitializationData.DxgkDdiEnumVidPnCofuncModality  = D3DDDIEnumVidPnCofuncModality_XddmParity;
                DriverInitializationData.DxgkDdiIsSupportedVidPn         = D3DDDIIsSupportedVidPn_XddmParity;
                break;
            }

            case MMDMM_SUPPORT_TEST:
            {
                //
                // These are test functions maintained by test.
                //
                DriverInitializationData.DxgkDdiRecommendFunctionalVidPn = D3DDDIRecommendFunctionalVidPn_Test;
                DriverInitializationData.DxgkDdiEnumVidPnCofuncModality  = D3DDDIEnumVidPnCofuncModality_Test;
                DriverInitializationData.DxgkDdiIsSupportedVidPn         = D3DDDIIsSupportedVidPn_Test;
                break;
            }

            default:
                ASSERT(dwMMDMMSupportType <= MMDMM_SUPPORT_TEST);
        }
    }

    #if DEBUG
    ReadDebugRegistrySettings();
    #endif

    return DxgkInitialize(DriverObject,
                          RegistryPath,
                          &DriverInitializationData);
}

#if DEBUG
void ReadDebugRegistrySettings(void)
{
    DWORD dwKMDebugPrintLevel = 0;
    DWORD dwKMDisableAssertsAndDbgBreaks = 0;
    DWORD dwDefaultKMDebugPrintLevel = DBG_ERROR;
    DWORD dwDefaultKMDisableAssertsAndDbgBreaks = 0;
    RTL_QUERY_REGISTRY_TABLE QueryTable[3] = {0};


    QueryTable[0].QueryRoutine  = NULL;
    QueryTable[0].Flags         = RTL_QUERY_REGISTRY_DIRECT;
    QueryTable[0].Name          = L"KMDebugPrintLevel";
    QueryTable[0].EntryContext  = &dwKMDebugPrintLevel;
    QueryTable[0].DefaultType   = REG_DWORD;
    QueryTable[0].DefaultData   = &dwDefaultKMDebugPrintLevel;
    QueryTable[0].DefaultLength = sizeof(DWORD);

    QueryTable[1].QueryRoutine  = NULL;
    QueryTable[1].Flags         = RTL_QUERY_REGISTRY_DIRECT;
    QueryTable[1].Name          = L"KMDisableAssertsAndDbgBreaks";
    QueryTable[1].EntryContext  = &dwKMDisableAssertsAndDbgBreaks;
    QueryTable[1].DefaultType   = REG_DWORD;
    QueryTable[1].DefaultData   = &dwDefaultKMDisableAssertsAndDbgBreaks;
    QueryTable[1].DefaultLength = sizeof(DWORD);

    RtlQueryRegistryValues(RTL_REGISTRY_SERVICES,
                           L"R200",
                           QueryTable,
                           NULL,
                           NULL);

    // Now action the settings
    R200SetDebugPrintLevel(dwKMDebugPrintLevel);

    if (dwKMDisableAssertsAndDbgBreaks == 1)
    {
        BreakOnAssert=FALSE;
    }

    return;
}

#endif


