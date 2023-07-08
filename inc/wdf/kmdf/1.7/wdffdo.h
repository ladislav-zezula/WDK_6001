/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

_WdfVersionBuild_

Module Name:

    WdfFdo.h

Abstract:

    This is the interface to the FDO functionality in the framework.  This also
    covers filters.

Environment:

    kernel mode only

Revision History:

--*/

#ifndef _WDFFDO_H_
#define _WDFFDO_H_



#if (NTDDI_VERSION >= NTDDI_WIN2K)



typedef
NTSTATUS
(EVT_WDF_DEVICE_FILTER_RESOURCE_REQUIREMENTS)(
    IN WDFDEVICE Device,
    IN WDFIORESREQLIST IoResourceRequirementsList
    );

typedef EVT_WDF_DEVICE_FILTER_RESOURCE_REQUIREMENTS *PFN_WDF_DEVICE_FILTER_RESOURCE_REQUIREMENTS;

typedef
NTSTATUS
(EVT_WDF_DEVICE_REMOVE_ADDED_RESOURCES)(
    IN WDFDEVICE Device,
    IN  WDFCMRESLIST ResourcesRaw,
    IN  WDFCMRESLIST ResourcesTranslated
    );

typedef EVT_WDF_DEVICE_REMOVE_ADDED_RESOURCES *PFN_WDF_DEVICE_REMOVE_ADDED_RESOURCES;

typedef struct _WDF_FDO_EVENT_CALLBACKS {
    //
    // Size of this structure in bytes
    //
    ULONG Size;

    PFN_WDF_DEVICE_FILTER_RESOURCE_REQUIREMENTS EvtDeviceFilterAddResourceRequirements;

    PFN_WDF_DEVICE_FILTER_RESOURCE_REQUIREMENTS EvtDeviceFilterRemoveResourceRequirements;

    PFN_WDF_DEVICE_REMOVE_ADDED_RESOURCES EvtDeviceRemoveAddedResources;

} WDF_FDO_EVENT_CALLBACKS, *PWDF_FDO_EVENT_CALLBACKS;

VOID
FORCEINLINE
WDF_FDO_EVENT_CALLBACKS_INIT(
    OUT PWDF_FDO_EVENT_CALLBACKS Callbacks
    )
{
    RtlZeroMemory(Callbacks, sizeof(WDF_FDO_EVENT_CALLBACKS));
    Callbacks->Size = sizeof(WDF_FDO_EVENT_CALLBACKS);
}

//
// WDF Function: WdfFdoInitWdmGetPhysicalDevice
//
typedef
__drv_maxIRQL(DISPATCH_LEVEL)
WDFAPI
PDEVICE_OBJECT
(*PFN_WDFFDOINITWDMGETPHYSICALDEVICE)(
    __in
    PWDF_DRIVER_GLOBALS DriverGlobals,
    __in
    PWDFDEVICE_INIT DeviceInit
    );

__drv_maxIRQL(DISPATCH_LEVEL)
PDEVICE_OBJECT
FORCEINLINE
WdfFdoInitWdmGetPhysicalDevice(
    __in
    PWDFDEVICE_INIT DeviceInit
    )
{
    return ((PFN_WDFFDOINITWDMGETPHYSICALDEVICE) WdfFunctions[WdfFdoInitWdmGetPhysicalDeviceTableIndex])(WdfDriverGlobals, DeviceInit);
}

//
// WDF Function: WdfFdoInitOpenRegistryKey
//
typedef
__checkReturn
__drv_maxIRQL(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(*PFN_WDFFDOINITOPENREGISTRYKEY)(
    __in
    PWDF_DRIVER_GLOBALS DriverGlobals,
    __in
    PWDFDEVICE_INIT DeviceInit,
    ULONG DeviceInstanceKeyType,
    ACCESS_MASK DesiredAccess,
    __in_opt
    PWDF_OBJECT_ATTRIBUTES KeyAttributes,
    __out
    WDFKEY* Key
    );

__checkReturn
__drv_maxIRQL(PASSIVE_LEVEL)
NTSTATUS
FORCEINLINE
WdfFdoInitOpenRegistryKey(
    __in
    PWDFDEVICE_INIT DeviceInit,
    ULONG DeviceInstanceKeyType,
    ACCESS_MASK DesiredAccess,
    __in_opt
    PWDF_OBJECT_ATTRIBUTES KeyAttributes,
    __out
    WDFKEY* Key
    )
{
    return ((PFN_WDFFDOINITOPENREGISTRYKEY) WdfFunctions[WdfFdoInitOpenRegistryKeyTableIndex])(WdfDriverGlobals, DeviceInit, DeviceInstanceKeyType, DesiredAccess, KeyAttributes, Key);
}

//
// WDF Function: WdfFdoInitQueryProperty
//
typedef
__checkReturn
__drv_maxIRQL(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(*PFN_WDFFDOINITQUERYPROPERTY)(
    __in
    PWDF_DRIVER_GLOBALS DriverGlobals,
    __in
    PWDFDEVICE_INIT DeviceInit,
    DEVICE_REGISTRY_PROPERTY DeviceProperty,
    ULONG BufferLength,
    __out_bcount_full(BufferLength)
    PVOID PropertyBuffer,
    __out
    PULONG ResultLength
    );

__checkReturn
__drv_maxIRQL(PASSIVE_LEVEL)
NTSTATUS
FORCEINLINE
WdfFdoInitQueryProperty(
    __in
    PWDFDEVICE_INIT DeviceInit,
    DEVICE_REGISTRY_PROPERTY DeviceProperty,
    ULONG BufferLength,
    __out_bcount_full(BufferLength)
    PVOID PropertyBuffer,
    __out
    PULONG ResultLength
    )
{
    return ((PFN_WDFFDOINITQUERYPROPERTY) WdfFunctions[WdfFdoInitQueryPropertyTableIndex])(WdfDriverGlobals, DeviceInit, DeviceProperty, BufferLength, PropertyBuffer, ResultLength);
}

//
// WDF Function: WdfFdoInitAllocAndQueryProperty
//
typedef
__checkReturn
__drv_maxIRQL(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(*PFN_WDFFDOINITALLOCANDQUERYPROPERTY)(
    __in
    PWDF_DRIVER_GLOBALS DriverGlobals,
    __in
    PWDFDEVICE_INIT DeviceInit,
    DEVICE_REGISTRY_PROPERTY DeviceProperty,
    __drv_strictTypeMatch(1)
    POOL_TYPE PoolType,
    __in_opt
    PWDF_OBJECT_ATTRIBUTES PropertyMemoryAttributes,
    __out
    WDFMEMORY* PropertyMemory
    );

__checkReturn
__drv_maxIRQL(PASSIVE_LEVEL)
NTSTATUS
FORCEINLINE
WdfFdoInitAllocAndQueryProperty(
    __in
    PWDFDEVICE_INIT DeviceInit,
    DEVICE_REGISTRY_PROPERTY DeviceProperty,
    __drv_strictTypeMatch(1)
    POOL_TYPE PoolType,
    __in_opt
    PWDF_OBJECT_ATTRIBUTES PropertyMemoryAttributes,
    __out
    WDFMEMORY* PropertyMemory
    )
{
    return ((PFN_WDFFDOINITALLOCANDQUERYPROPERTY) WdfFunctions[WdfFdoInitAllocAndQueryPropertyTableIndex])(WdfDriverGlobals, DeviceInit, DeviceProperty, PoolType, PropertyMemoryAttributes, PropertyMemory);
}

//
// WDF Function: WdfFdoInitSetEventCallbacks
//
typedef
__drv_maxIRQL(PASSIVE_LEVEL)
WDFAPI
VOID
(*PFN_WDFFDOINITSETEVENTCALLBACKS)(
    __in
    PWDF_DRIVER_GLOBALS DriverGlobals,
    __in
    PWDFDEVICE_INIT DeviceInit,
    __in
    PWDF_FDO_EVENT_CALLBACKS FdoEventCallbacks
    );

__drv_maxIRQL(PASSIVE_LEVEL)
VOID
FORCEINLINE
WdfFdoInitSetEventCallbacks(
    __in
    PWDFDEVICE_INIT DeviceInit,
    __in
    PWDF_FDO_EVENT_CALLBACKS FdoEventCallbacks
    )
{
    ((PFN_WDFFDOINITSETEVENTCALLBACKS) WdfFunctions[WdfFdoInitSetEventCallbacksTableIndex])(WdfDriverGlobals, DeviceInit, FdoEventCallbacks);
}

//
// WDF Function: WdfFdoInitSetFilter
//
typedef
__drv_maxIRQL(PASSIVE_LEVEL)
WDFAPI
VOID
(*PFN_WDFFDOINITSETFILTER)(
    __in
    PWDF_DRIVER_GLOBALS DriverGlobals,
    __in
    PWDFDEVICE_INIT DeviceInit
    );

__drv_maxIRQL(PASSIVE_LEVEL)
VOID
FORCEINLINE
WdfFdoInitSetFilter(
    __in
    PWDFDEVICE_INIT DeviceInit
    )
{
    ((PFN_WDFFDOINITSETFILTER) WdfFunctions[WdfFdoInitSetFilterTableIndex])(WdfDriverGlobals, DeviceInit);
}

//
// WDF Function: WdfFdoInitSetDefaultChildListConfig
//
typedef
__drv_maxIRQL(PASSIVE_LEVEL)
WDFAPI
VOID
(*PFN_WDFFDOINITSETDEFAULTCHILDLISTCONFIG)(
    __in
    PWDF_DRIVER_GLOBALS DriverGlobals,
    __inout
    PWDFDEVICE_INIT DeviceInit,
    __in
    PWDF_CHILD_LIST_CONFIG Config,
    __in_opt
    PWDF_OBJECT_ATTRIBUTES DefaultChildListAttributes
    );

__drv_maxIRQL(PASSIVE_LEVEL)
VOID
FORCEINLINE
WdfFdoInitSetDefaultChildListConfig(
    __inout
    PWDFDEVICE_INIT DeviceInit,
    __in
    PWDF_CHILD_LIST_CONFIG Config,
    __in_opt
    PWDF_OBJECT_ATTRIBUTES DefaultChildListAttributes
    )
{
    ((PFN_WDFFDOINITSETDEFAULTCHILDLISTCONFIG) WdfFunctions[WdfFdoInitSetDefaultChildListConfigTableIndex])(WdfDriverGlobals, DeviceInit, Config, DefaultChildListAttributes);
}

//
// WDF Function: WdfFdoQueryForInterface
//
typedef
__checkReturn
__drv_maxIRQL(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(*PFN_WDFFDOQUERYFORINTERFACE)(
    __in
    PWDF_DRIVER_GLOBALS DriverGlobals,
    __in
    WDFDEVICE Fdo,
    __in
    LPCGUID InterfaceType,
    __out
    PINTERFACE Interface,
    USHORT Size,
    USHORT Version,
    __in_opt
    PVOID InterfaceSpecificData
    );

__checkReturn
__drv_maxIRQL(PASSIVE_LEVEL)
NTSTATUS
FORCEINLINE
WdfFdoQueryForInterface(
    __in
    WDFDEVICE Fdo,
    __in
    LPCGUID InterfaceType,
    __out
    PINTERFACE Interface,
    USHORT Size,
    USHORT Version,
    __in_opt
    PVOID InterfaceSpecificData
    )
{
    return ((PFN_WDFFDOQUERYFORINTERFACE) WdfFunctions[WdfFdoQueryForInterfaceTableIndex])(WdfDriverGlobals, Fdo, InterfaceType, Interface, Size, Version, InterfaceSpecificData);
}

//
// WDF Function: WdfFdoGetDefaultChildList
//
typedef
__drv_maxIRQL(DISPATCH_LEVEL)
WDFAPI
WDFCHILDLIST
(*PFN_WDFFDOGETDEFAULTCHILDLIST)(
    __in
    PWDF_DRIVER_GLOBALS DriverGlobals,
    __in
    WDFDEVICE Fdo
    );

__drv_maxIRQL(DISPATCH_LEVEL)
WDFCHILDLIST
FORCEINLINE
WdfFdoGetDefaultChildList(
    __in
    WDFDEVICE Fdo
    )
{
    return ((PFN_WDFFDOGETDEFAULTCHILDLIST) WdfFunctions[WdfFdoGetDefaultChildListTableIndex])(WdfDriverGlobals, Fdo);
}

//
// WDF Function: WdfFdoAddStaticChild
//
typedef
__checkReturn
__drv_maxIRQL(DISPATCH_LEVEL)
WDFAPI
NTSTATUS
(*PFN_WDFFDOADDSTATICCHILD)(
    __in
    PWDF_DRIVER_GLOBALS DriverGlobals,
    __in
    WDFDEVICE Fdo,
    __in
    WDFDEVICE Child
    );

__checkReturn
__drv_maxIRQL(DISPATCH_LEVEL)
NTSTATUS
FORCEINLINE
WdfFdoAddStaticChild(
    __in
    WDFDEVICE Fdo,
    __in
    WDFDEVICE Child
    )
{
    return ((PFN_WDFFDOADDSTATICCHILD) WdfFunctions[WdfFdoAddStaticChildTableIndex])(WdfDriverGlobals, Fdo, Child);
}

//
// WDF Function: WdfFdoLockStaticChildListForIteration
//
typedef
__drv_maxIRQL(DISPATCH_LEVEL)
WDFAPI
VOID
(*PFN_WDFFDOLOCKSTATICCHILDLISTFORITERATION)(
    __in
    PWDF_DRIVER_GLOBALS DriverGlobals,
    __in
    WDFDEVICE Fdo
    );

__drv_maxIRQL(DISPATCH_LEVEL)
VOID
FORCEINLINE
WdfFdoLockStaticChildListForIteration(
    __in
    WDFDEVICE Fdo
    )
{
    ((PFN_WDFFDOLOCKSTATICCHILDLISTFORITERATION) WdfFunctions[WdfFdoLockStaticChildListForIterationTableIndex])(WdfDriverGlobals, Fdo);
}

//
// WDF Function: WdfFdoRetrieveNextStaticChild
//
typedef
__drv_maxIRQL(DISPATCH_LEVEL)
WDFAPI
WDFDEVICE
(*PFN_WDFFDORETRIEVENEXTSTATICCHILD)(
    __in
    PWDF_DRIVER_GLOBALS DriverGlobals,
    __in
    WDFDEVICE Fdo,
    __in_opt
    WDFDEVICE PreviousChild,
    ULONG Flags
    );

__drv_maxIRQL(DISPATCH_LEVEL)
WDFDEVICE
FORCEINLINE
WdfFdoRetrieveNextStaticChild(
    __in
    WDFDEVICE Fdo,
    __in_opt
    WDFDEVICE PreviousChild,
    ULONG Flags
    )
{
    return ((PFN_WDFFDORETRIEVENEXTSTATICCHILD) WdfFunctions[WdfFdoRetrieveNextStaticChildTableIndex])(WdfDriverGlobals, Fdo, PreviousChild, Flags);
}

//
// WDF Function: WdfFdoUnlockStaticChildListFromIteration
//
typedef
__drv_maxIRQL(DISPATCH_LEVEL)
WDFAPI
VOID
(*PFN_WDFFDOUNLOCKSTATICCHILDLISTFROMITERATION)(
    __in
    PWDF_DRIVER_GLOBALS DriverGlobals,
    __in
    WDFDEVICE Fdo
    );

__drv_maxIRQL(DISPATCH_LEVEL)
VOID
FORCEINLINE
WdfFdoUnlockStaticChildListFromIteration(
    __in
    WDFDEVICE Fdo
    )
{
    ((PFN_WDFFDOUNLOCKSTATICCHILDLISTFROMITERATION) WdfFunctions[WdfFdoUnlockStaticChildListFromIterationTableIndex])(WdfDriverGlobals, Fdo);
}



#endif // (NTDDI_VERSION >= NTDDI_WIN2K)


#endif // _WDFFDO_H_

