/*++

Copyright (c) Microsoft Corporation

Module Name:

    ioctl.c

Abstract

--*/

#include "pch.h"

VOID
t1394_EvtIoDeviceControl(
    IN WDFQUEUE     Queue,
    IN WDFREQUEST Request,
    IN size_t      OutputBufferLength,
    IN size_t      InputBufferLength,
    IN ULONG      IoControlCode
    )
{
    NTSTATUS            ntStatus = STATUS_SUCCESS;
    PDEVICE_EXTENSION   deviceExtension;
    PVOID               ioBuffer = NULL;
    WDFDEVICE           device;
    size_t              bufLength;

    ENTER("t1394_EvtIoDeviceControl");
    TRACE(TL_TRACE, ("Request = 0x%p\n", Request));

    device = WdfIoQueueGetDevice(Queue);
    deviceExtension = GetDeviceContext(device);

    //
    // Since all the IOCTLs handled here are buffered, WdfRequestRetrieveOutputBuffer &
    // WdfRequestRetrieveInputBuffer return the same buffer pointer.
    // So make sure you read all the information you need from
    // the buffer before you write to it. Also requiredLength of the buffer vary from
    // ioctl to ioctl, so we will pretend that we need zero length buffer and do the lenght
    // check later in the specific ioct case.
    //
    ntStatus = WdfRequestRetrieveInputBuffer(Request, 0, &ioBuffer, &bufLength);
    if( !NT_SUCCESS(ntStatus) || ioBuffer == NULL) {
        TRACE(TL_ERROR, ("WdfRequestRetrieveInputBuffer failed 0x%x\n", ntStatus));
        WdfRequestComplete(Request, ntStatus);
        return;
    }


    switch (IoControlCode) {

        case IOCTL_ALLOCATE_ADDRESS_RANGE:
            {
                PALLOCATE_ADDRESS_RANGE     AllocateAddressRange;

                TRACE(TL_TRACE, ("IOCTL_ALLOCATE_ADDRESS_RANGE\n"));

                if ((InputBufferLength < sizeof(ALLOCATE_ADDRESS_RANGE)) ||
                    (OutputBufferLength < sizeof(ALLOCATE_ADDRESS_RANGE))) {

                    ntStatus = STATUS_BUFFER_TOO_SMALL;
                }
                else {

                    AllocateAddressRange = (PALLOCATE_ADDRESS_RANGE)ioBuffer;

                    ntStatus = t1394_AllocateAddressRange( device,
                                                           Request,
                                                           AllocateAddressRange->fulAllocateFlags,
                                                           AllocateAddressRange->fulFlags,
                                                           AllocateAddressRange->nLength,
                                                           AllocateAddressRange->MaxSegmentSize,
                                                           AllocateAddressRange->fulAccessType,
                                                           AllocateAddressRange->fulNotificationOptions,
                                                           &AllocateAddressRange->Required1394Offset,
                                                           &AllocateAddressRange->hAddressRange,
                                                           (PULONG)&AllocateAddressRange->Data
                                                           );

                    if (NT_SUCCESS(ntStatus)) {
                        WdfRequestSetInformation(Request, OutputBufferLength);
                     }
                }
            }
            break; // IOCTL_ALLOCATE_ADDRESS_RANGE

        case IOCTL_FREE_ADDRESS_RANGE:
            TRACE(TL_TRACE, ("IOCTL_FREE_ADDRESS_RANGE\n"));

            if (InputBufferLength < sizeof(HANDLE)) {

                ntStatus = STATUS_BUFFER_TOO_SMALL;
            }
            else {

                ntStatus = t1394_FreeAddressRange( device,
                                                   Request,
                                                   *(PHANDLE)ioBuffer
                                                   );
            }
            break; // IOCTL_FREE_ADDRESS_RANGE

        case IOCTL_ASYNC_READ:
            {
                PASYNC_READ     AsyncRead;

                TRACE(TL_TRACE, ("IOCTL_ASYNC_READ\n"));

                if (InputBufferLength < sizeof(ASYNC_READ)) {

                    ntStatus = STATUS_BUFFER_TOO_SMALL;
                }
                else {

                    AsyncRead = (PASYNC_READ)ioBuffer;

                    if ((OutputBufferLength < sizeof(ASYNC_READ)) ||
                        (OutputBufferLength-sizeof(ASYNC_READ) < AsyncRead->nNumberOfBytesToRead)) {

                        ntStatus = STATUS_BUFFER_TOO_SMALL;
                    }
                    else {

                        ntStatus = t1394_AsyncRead( device,
                                                    Request,
                                                    AsyncRead->bRawMode,
                                                    AsyncRead->bGetGeneration,
                                                    AsyncRead->DestinationAddress,
                                                    AsyncRead->nNumberOfBytesToRead,
                                                    AsyncRead->nBlockSize,
                                                    AsyncRead->fulFlags,
                                                    AsyncRead->ulGeneration,
                                                    (PULONG)&AsyncRead->Data
                                                    );

                        if (NT_SUCCESS(ntStatus)) {
                            WdfRequestSetInformation(Request, OutputBufferLength);
                        }
                    }
                }
            }
            break; // IOCTL_ASYNC_READ

        case IOCTL_ASYNC_WRITE:
            {
                PASYNC_WRITE    AsyncWrite;

                TRACE(TL_TRACE, ("IOCTL_ASYNC_WRITE\n"));

                if (InputBufferLength < sizeof(ASYNC_WRITE)) {

                    ntStatus = STATUS_BUFFER_TOO_SMALL;
                }
                else {

                    AsyncWrite = (PASYNC_WRITE)ioBuffer;

                    if (InputBufferLength-sizeof(ASYNC_WRITE) < AsyncWrite->nNumberOfBytesToWrite) {

                        ntStatus = STATUS_BUFFER_TOO_SMALL;
                    }
                    else {

                        ntStatus = t1394_AsyncWrite( device,
                                                     Request,
                                                     AsyncWrite->bRawMode,
                                                     AsyncWrite->bGetGeneration,
                                                     AsyncWrite->DestinationAddress,
                                                     AsyncWrite->nNumberOfBytesToWrite,
                                                     AsyncWrite->nBlockSize,
                                                     AsyncWrite->fulFlags,
                                                     AsyncWrite->ulGeneration,
                                                     (PULONG)&AsyncWrite->Data
                                                     );
                    }
                }
            }
            break; // IOCTL_ASYNC_WRITE

        case IOCTL_ASYNC_LOCK:
            {
                PASYNC_LOCK     AsyncLock;

                TRACE(TL_TRACE, ("IOCTL_ASYNC_LOCK\n"));

                if ((InputBufferLength < sizeof(ASYNC_LOCK)) ||
                    (OutputBufferLength < sizeof(ASYNC_LOCK))) {

                    ntStatus = STATUS_BUFFER_TOO_SMALL;
                }
                else {

                    AsyncLock = (PASYNC_LOCK)ioBuffer;

                    ntStatus = t1394_AsyncLock( device,
                                                Request,
                                                AsyncLock->bRawMode,
                                                AsyncLock->bGetGeneration,
                                                AsyncLock->DestinationAddress,
                                                AsyncLock->nNumberOfArgBytes,
                                                AsyncLock->nNumberOfDataBytes,
                                                AsyncLock->fulTransactionType,
                                                AsyncLock->fulFlags,
                                                AsyncLock->Arguments,
                                                AsyncLock->DataValues,
                                                AsyncLock->ulGeneration,
                                                (PVOID)&AsyncLock->Buffer
                                                );

                    if (NT_SUCCESS(ntStatus)){
                        WdfRequestSetInformation(Request, OutputBufferLength);
                    }
                }
            }
            break; // IOCTL_ASYNC_LOCK

        case IOCTL_ASYNC_STREAM:
            {
                PASYNC_STREAM   AsyncStream;

                TRACE(TL_TRACE, ("IOCTL_ASYNC_STREAM\n"));

                if (InputBufferLength < sizeof(ASYNC_STREAM)) {

                    ntStatus = STATUS_BUFFER_TOO_SMALL;
                }
                else {

                    AsyncStream = (PASYNC_STREAM)ioBuffer;

                    if (OutputBufferLength-sizeof(ASYNC_STREAM) < AsyncStream->nNumberOfBytesToStream) {

                        ntStatus = STATUS_BUFFER_TOO_SMALL;
                    }
                    else {

                        ntStatus = t1394_AsyncStream( device,
                                                      Request,
                                                      AsyncStream->nNumberOfBytesToStream,
                                                      AsyncStream->fulFlags,
                                                      AsyncStream->ulTag,
                                                      AsyncStream->nChannel,
                                                      AsyncStream->ulSynch,
                                                      (UCHAR)AsyncStream->nSpeed,
                                                      (PULONG)&AsyncStream->Data
                                                      );

                        if (NT_SUCCESS(ntStatus)){
                            WdfRequestSetInformation(Request, OutputBufferLength);
                        }
                    }
                }
            }
            break; // IOCTL_ASYNC_STREAM

        case IOCTL_ISOCH_ALLOCATE_BANDWIDTH:
            {
                PISOCH_ALLOCATE_BANDWIDTH   IsochAllocateBandwidth;

                TRACE(TL_TRACE, ("IOCTL_ISOCH_ALLOCATE_BANDWIDTH\n"));

                if ((InputBufferLength < sizeof(ISOCH_ALLOCATE_BANDWIDTH)) ||
                    (OutputBufferLength < sizeof(ISOCH_ALLOCATE_BANDWIDTH))) {

                    ntStatus = STATUS_BUFFER_TOO_SMALL;
                }
                else {

                    IsochAllocateBandwidth = (PISOCH_ALLOCATE_BANDWIDTH)ioBuffer;

                    ntStatus = t1394_IsochAllocateBandwidth( device,
                                                             Request,
                                                             IsochAllocateBandwidth->nMaxBytesPerFrameRequested,
                                                             IsochAllocateBandwidth->fulSpeed,
                                                             &IsochAllocateBandwidth->hBandwidth,
                                                             &IsochAllocateBandwidth->BytesPerFrameAvailable,
                                                             &IsochAllocateBandwidth->SpeedSelected
                                                             );

                    if (NT_SUCCESS(ntStatus)){
                        WdfRequestSetInformation(Request, OutputBufferLength);
                    }
                }
            }
            break; // IOCTL_ISOCH_ALLOCATE_BANDWIDTH

        case IOCTL_ISOCH_ALLOCATE_CHANNEL:
            {
                PISOCH_ALLOCATE_CHANNEL     IsochAllocateChannel;

                TRACE(TL_TRACE, ("IOCTL_ISOCH_ALLOCATE_CHANNEL\n"));

                if ((InputBufferLength < sizeof(ISOCH_ALLOCATE_CHANNEL)) ||
                    (OutputBufferLength < sizeof(ISOCH_ALLOCATE_CHANNEL))) {

                    ntStatus = STATUS_BUFFER_TOO_SMALL;
                }
                else {

                    IsochAllocateChannel = (PISOCH_ALLOCATE_CHANNEL)ioBuffer;

                    ntStatus = t1394_IsochAllocateChannel( device,
                                                           Request,
                                                           IsochAllocateChannel->nRequestedChannel,
                                                           &IsochAllocateChannel->Channel,
                                                           &IsochAllocateChannel->ChannelsAvailable
                                                           );

                if (NT_SUCCESS(ntStatus))
                    WdfRequestSetInformation(Request, OutputBufferLength);
                }
            }
            break; // IOCTL_ISOCH_ALLOCATE_CHANNEL

        case IOCTL_ISOCH_ALLOCATE_RESOURCES:
            {
                PISOCH_ALLOCATE_RESOURCES   IsochAllocateResources;

                TRACE(TL_TRACE, ("IOCTL_ISOCH_ALLOCATE_RESOURCES\n"));

                if ((InputBufferLength < sizeof(ISOCH_ALLOCATE_RESOURCES)) ||
                    (OutputBufferLength < sizeof(ISOCH_ALLOCATE_RESOURCES))) {

                    ntStatus = STATUS_BUFFER_TOO_SMALL;
                }
                else {

                    IsochAllocateResources = (PISOCH_ALLOCATE_RESOURCES)ioBuffer;

                    ntStatus = t1394_IsochAllocateResources( device,
                                                             Request,
                                                             IsochAllocateResources->fulSpeed,
                                                             IsochAllocateResources->fulFlags,
                                                             IsochAllocateResources->nChannel,
                                                             IsochAllocateResources->nMaxBytesPerFrame,
                                                             IsochAllocateResources->nNumberOfBuffers,
                                                             IsochAllocateResources->nMaxBufferSize,
                                                             IsochAllocateResources->nQuadletsToStrip,
                                                             &IsochAllocateResources->hResource
                                                             );

                    if (NT_SUCCESS(ntStatus)) {
                        WdfRequestSetInformation(Request, OutputBufferLength);
                    }
                }
            }
            break; // IOCTL_ISOCH_ALLOCATE_RESOURCES

        case IOCTL_ISOCH_ATTACH_BUFFERS:
            {

                TRACE(TL_TRACE, ("IOCTL_ISOCH_ATTACH_BUFFERS - Not implemented\n"));
                //
                // TODO: There are tons of race conditions in the routines that
                // send AttachBuffer request. There is no synchronization between
                // TimerDpc to cancel the attach buffer request and completion routines. They
                // all stomp on each others memory, free buffers currently being used by
                // another routine, Detach routine is using IRP (newIrp) that is used by
                // attach buffer routine.
                // Removing code related to this because the 1394 team is rewriting
                // all these routines.
                //
                //
                STATUS_SUCCESS;
            }
            break; // IOCTL_ISOCH_ATTACH_BUFFERS

        case IOCTL_ISOCH_DETACH_BUFFERS:
            {
                PISOCH_DETACH_BUFFERS       IsochDetachBuffers;

                TRACE(TL_TRACE, ("IOCTL_ISOCH_DETACH_BUFFERS\n"));

                if (InputBufferLength < sizeof(ISOCH_DETACH_BUFFERS)) {

                    ntStatus = STATUS_BUFFER_TOO_SMALL;
                }
                else {

                    IsochDetachBuffers = (PISOCH_DETACH_BUFFERS)ioBuffer;

                    ntStatus = t1394_IsochDetachBuffers( device,
                                                         Request,
                                                         IsochDetachBuffers->hResource,
                                                         IsochDetachBuffers->nNumberOfDescriptors,
                                                         (PISOCH_DESCRIPTOR)IsochDetachBuffers->pIsochDescriptor
                                                         );
                }
            }

            break; // IOCTL_ISOCH_DETACH_BUFFERS

        case IOCTL_ISOCH_FREE_BANDWIDTH:
            {
                TRACE(TL_TRACE, ("IOCTL_ISOCH_FREE_BANDWIDTH\n"));

                if (InputBufferLength < sizeof(HANDLE)) {

                    ntStatus = STATUS_BUFFER_TOO_SMALL;
                }
                else {

                    ntStatus = t1394_IsochFreeBandwidth( device,
                                                         Request,
                                                         *(PHANDLE)ioBuffer
                                                         );
                }
            }
            break; // IOCTL_ISOCH_FREE_BANDWIDTH

        case IOCTL_ISOCH_FREE_CHANNEL:
            {
                TRACE(TL_TRACE, ("IOCTL_ISOCH_FREE_CHANNEL\n"));

                if (InputBufferLength < sizeof(ULONG)) {

                    ntStatus = STATUS_BUFFER_TOO_SMALL;
                }
                else {

                    ntStatus = t1394_IsochFreeChannel( device,
                                                       Request,
                                                       *(PULONG)ioBuffer
                                                       );
                }
            }
            break; // IOCTL_ISOCH_FREE_CHANNEL

        case IOCTL_ISOCH_FREE_RESOURCES:
            {
                TRACE(TL_TRACE, ("IOCTL_ISOCH_FREE_RESOURCES\n"));

                if (InputBufferLength < sizeof(HANDLE)) {

                    ntStatus = STATUS_BUFFER_TOO_SMALL;
                }
                else {

                    ntStatus = t1394_IsochFreeResources( device,
                                                         Request,
                                                         *(PHANDLE)ioBuffer
                                                         );
                }
            }
            break; // IOCTL_ISOCH_FREE_RESOURCES

        case IOCTL_ISOCH_LISTEN:
            {
                PISOCH_LISTEN       IsochListen;

                TRACE(TL_TRACE, ("IOCTL_ISOCH_LISTEN\n"));

                if (InputBufferLength < sizeof(ISOCH_LISTEN)) {

                    ntStatus = STATUS_BUFFER_TOO_SMALL;
                }
                else {

                    IsochListen = (PISOCH_LISTEN)ioBuffer;

                    ntStatus = t1394_IsochListen( device,
                                                  Request,
                                                  IsochListen->hResource,
                                                  IsochListen->fulFlags,
                                                  IsochListen->StartTime
                                                  );
                }
            }
            break; // IOCTL_ISOCH_LISTEN

        case IOCTL_ISOCH_QUERY_CURRENT_CYCLE_TIME:
            {
                TRACE(TL_TRACE, ("IOCTL_ISOCH_QUERY_CURRENT_CYCLE_TIME\n"));

                if (OutputBufferLength < sizeof(CYCLE_TIME)) {

                    ntStatus = STATUS_BUFFER_TOO_SMALL;
                }
                else {

                    ntStatus = t1394_IsochQueryCurrentCycleTime( device,
                                                                 Request,
                                                                 (PCYCLE_TIME)ioBuffer
                                                                 );

                    if (NT_SUCCESS(ntStatus)) {
                        WdfRequestSetInformation(Request, OutputBufferLength);
                    }
                }
            }
            break; // IOCTL_ISOCH_QUERY_CURRENT_CYCLE_TIME

        case IOCTL_ISOCH_QUERY_RESOURCES:
            {
                PISOCH_QUERY_RESOURCES      IsochQueryResources;

                TRACE(TL_TRACE, ("IOCTL_ISOCH_QUERY_RESOURCES\n"));

                if ((InputBufferLength < sizeof(ISOCH_QUERY_RESOURCES)) ||
                    (OutputBufferLength < sizeof(ISOCH_QUERY_RESOURCES))) {

                    ntStatus = STATUS_BUFFER_TOO_SMALL;
                }
                else {

                    IsochQueryResources = (PISOCH_QUERY_RESOURCES)ioBuffer;

                    ntStatus = t1394_IsochQueryResources( device,
                                                          Request,
                                                          IsochQueryResources->fulSpeed,
                                                          &IsochQueryResources->BytesPerFrameAvailable,
                                                          &IsochQueryResources->ChannelsAvailable
                                                          );

                    if (NT_SUCCESS(ntStatus)) {
                        WdfRequestSetInformation(Request, OutputBufferLength);
                    }
                }
            }
            break; // IOCTL_ISOCH_QUERY_RESOURCES

        case IOCTL_ISOCH_SET_CHANNEL_BANDWIDTH:
            {
                PISOCH_SET_CHANNEL_BANDWIDTH    IsochSetChannelBandwidth;

                TRACE(TL_TRACE, ("IOCTL_ISOCH_SET_CHANNEL_BANDWIDTH\n"));

                if (InputBufferLength < sizeof(ISOCH_SET_CHANNEL_BANDWIDTH)) {

                    ntStatus = STATUS_BUFFER_TOO_SMALL;
                }
                else {

                    IsochSetChannelBandwidth = (PISOCH_SET_CHANNEL_BANDWIDTH)ioBuffer;

                    ntStatus = t1394_IsochSetChannelBandwidth( device,
                                                               Request,
                                                               IsochSetChannelBandwidth->hBandwidth,
                                                               IsochSetChannelBandwidth->nMaxBytesPerFrame
                                                               );
                }
            }
            break; // IOCTL_ISOCH_SET_CHANNEL_BANDWIDTH


        case IOCTL_ISOCH_MODIFY_STREAM_PROPERTIES:
            {
                PISOCH_MODIFY_STREAM_PROPERTIES     IsochModifyStreamProperties;

                TRACE(TL_TRACE, ("IOCTL_ISOCH_MODIFY_STREAM_PROPERTIES\n"));

                if (InputBufferLength < sizeof (ISOCH_MODIFY_STREAM_PROPERTIES)) {

                    ntStatus = STATUS_BUFFER_TOO_SMALL;
                }
                else {

                    IsochModifyStreamProperties = (PISOCH_MODIFY_STREAM_PROPERTIES)ioBuffer;

                    ntStatus = t1394_IsochModifyStreamProperties( device,
                                                                  Request,
                                                                  IsochModifyStreamProperties->hResource,
                                                                  IsochModifyStreamProperties->ChannelMask,
                                                                  IsochModifyStreamProperties->fulSpeed
                                                                  );
                }
            }
            break; // IOCTL_ISOCH_MODIFY_STREAM_PROPERTIES

        case IOCTL_ISOCH_STOP:
            {
                PISOCH_STOP     IsochStop;

                TRACE(TL_TRACE, ("IOCTL_ISOCH_STOP\n"));

                if (InputBufferLength < sizeof(ISOCH_STOP)) {

                    ntStatus = STATUS_BUFFER_TOO_SMALL;
                }
                else {

                    IsochStop = (PISOCH_STOP)ioBuffer;

                    ntStatus = t1394_IsochStop( device,
                                                Request,
                                                IsochStop->hResource,
                                                IsochStop->fulFlags
                                                );
                }
            }
            break; // IOCTL_ISOCH_STOP

        case IOCTL_ISOCH_TALK:
            {
                PISOCH_TALK     IsochTalk;

                TRACE(TL_TRACE, ("IOCTL_ISOCH_TALK\n"));

                if (InputBufferLength < sizeof(ISOCH_TALK)) {

                    ntStatus = STATUS_BUFFER_TOO_SMALL;
                }
                else {

                    IsochTalk = (PISOCH_TALK)ioBuffer;

                    ntStatus = t1394_IsochTalk( device,
                                                Request,
                                                IsochTalk->hResource,
                                                IsochTalk->fulFlags,
                                                IsochTalk->StartTime
                                                );
                }
            }
            break; // IOCTL_ISOCH_TALK

        case IOCTL_GET_LOCAL_HOST_INFORMATION:
            {
                PGET_LOCAL_HOST_INFORMATION     GetLocalHostInformation;

                TRACE(TL_TRACE, ("IOCTL_GET_LOCAL_HOST_INFORMATION\n"));

                if ((InputBufferLength < sizeof(GET_LOCAL_HOST_INFORMATION)) ||
                    (OutputBufferLength < sizeof(GET_LOCAL_HOST_INFORMATION))) {

                    ntStatus = STATUS_BUFFER_TOO_SMALL;
                }
                else {

                    GetLocalHostInformation = (PGET_LOCAL_HOST_INFORMATION)ioBuffer;

                    ntStatus = t1394_GetLocalHostInformation( device,
                                                              Request,
                                                              GetLocalHostInformation->nLevel,
                                                              &GetLocalHostInformation->Status,
                                                              (PVOID)GetLocalHostInformation->Information
                                                              );

                    if (NT_SUCCESS(ntStatus))
                        WdfRequestSetInformation(Request, OutputBufferLength);
                }
            }
            break; // IOCTL_GET_LOCAL_HOST_INFORMATION

        case IOCTL_GET_1394_ADDRESS_FROM_DEVICE_OBJECT:
            {
                PGET_1394_ADDRESS   Get1394Address;

                TRACE(TL_TRACE, ("IOCTL_GET_1394_ADDRESS_FROM_DEVICE_OBJECT\n"));

                if ((InputBufferLength < sizeof(GET_1394_ADDRESS)) ||
                    (OutputBufferLength < sizeof(GET_1394_ADDRESS))) {

                    ntStatus = STATUS_BUFFER_TOO_SMALL;
                }
                else {

                    Get1394Address = (PGET_1394_ADDRESS)ioBuffer;

                    ntStatus = t1394_Get1394AddressFromDeviceObject( device,
                                                                     Request,
                                                                     Get1394Address->fulFlags,
                                                                     &Get1394Address->NodeAddress
                                                                     );

                    if (NT_SUCCESS(ntStatus))
                        WdfRequestSetInformation(Request, OutputBufferLength);
                }
            }
            break; // IOCTL_GET_1394_ADDRESS_FROM_DEVICE_OBJECT

        case IOCTL_CONTROL:
            TRACE(TL_TRACE, ("IOCTL_CONTROL\n"));

            ntStatus = t1394_Control( device,
                                          Request
                                          );

            break; // IOCTL_CONTROL

        case IOCTL_GET_MAX_SPEED_BETWEEN_DEVICES:
            {
                PGET_MAX_SPEED_BETWEEN_DEVICES  MaxSpeedBetweenDevices;

                TRACE(TL_TRACE, ("IOCTL_GET_MAX_SPEED_BETWEEN_DEVICES\n"));

                if ((InputBufferLength < sizeof(GET_MAX_SPEED_BETWEEN_DEVICES)) ||
                    (OutputBufferLength < sizeof(GET_MAX_SPEED_BETWEEN_DEVICES))) {

                    ntStatus = STATUS_BUFFER_TOO_SMALL;
                }
                else {

                    MaxSpeedBetweenDevices = (PGET_MAX_SPEED_BETWEEN_DEVICES)ioBuffer;

                    ntStatus = t1394_GetMaxSpeedBetweenDevices( device,
                                                                Request,
                                                                MaxSpeedBetweenDevices->fulFlags,
                                                                MaxSpeedBetweenDevices->ulNumberOfDestinations,
                                                                (PDEVICE_OBJECT *)&MaxSpeedBetweenDevices->hDestinationDeviceObjects[0],
                                                                &MaxSpeedBetweenDevices->fulSpeed
                                                                );

                    if (NT_SUCCESS(ntStatus))
                        WdfRequestSetInformation(Request, OutputBufferLength);
                }
            }
            break; // IOCTL_GET_MAX_SPEED_BETWEEN_DEVICES

        case IOCTL_SET_DEVICE_XMIT_PROPERTIES:
            {
                PDEVICE_XMIT_PROPERTIES     DeviceXmitProperties;

                TRACE(TL_TRACE, ("IOCTL_SET_DEVICE_XMIT_PROPERTIES\n"));

                if (InputBufferLength < sizeof(DEVICE_XMIT_PROPERTIES)) {

                    ntStatus = STATUS_BUFFER_TOO_SMALL;
                }
                else {

                    DeviceXmitProperties = (PDEVICE_XMIT_PROPERTIES)ioBuffer;

                    ntStatus = t1394_SetDeviceXmitProperties( device,
                                                              Request,
                                                              DeviceXmitProperties->fulSpeed,
                                                              DeviceXmitProperties->fulPriority
                                                              );
                }
            }
            break; // IOCTL_SET_DEVICE_XMIT_PROPERTIES

        case IOCTL_GET_CONFIGURATION_INFORMATION:
            TRACE(TL_TRACE, ("IOCTL_GET_CONFIGURATION_INFORMATION\n"));

            ntStatus = t1394_GetConfigurationInformation( device,
                                                          Request
                                                          );

            break; // IOCTL_GET_CONFIGURATION_INFORMATION

        case IOCTL_BUS_RESET:
            {
                TRACE(TL_TRACE, ("IOCTL_BUS_RESET\n"));

                if (InputBufferLength < sizeof(ULONG)) {

                    ntStatus = STATUS_BUFFER_TOO_SMALL;
                }
                else {

                    ntStatus = t1394_BusReset( device,
                                               Request,
                                               *((PULONG)ioBuffer)
                                               );
                }
            }
            break; // IOCTL_BUS_RESET

        case IOCTL_GET_GENERATION_COUNT:
            {
                TRACE(TL_TRACE, ("IOCTL_GET_GENERATION_COUNT\n"));

                if (OutputBufferLength < sizeof(ULONG)) {

                    ntStatus = STATUS_BUFFER_TOO_SMALL;
                }
                else {

                    ntStatus = t1394_GetGenerationCount( device,
                                                         Request,
                                                         (PULONG)ioBuffer
                                                         );

                    if (NT_SUCCESS(ntStatus)) {
                        WdfRequestSetInformation(Request, OutputBufferLength);
                    }
                }
            }
            break; // IOCTL_GET_GENERATION_COUNT

        case IOCTL_SEND_PHY_CONFIGURATION_PACKET:
            {
                TRACE(TL_TRACE, ("IOCTL_SEND_PHY_CONFIGURATION_PACKET\n"));

                if (InputBufferLength < sizeof(PHY_CONFIGURATION_PACKET)) {

                    ntStatus = STATUS_BUFFER_TOO_SMALL;
                }
                else {

                    ntStatus = t1394_SendPhyConfigurationPacket( device,
                                                                 Request,
                                                                 *(PPHY_CONFIGURATION_PACKET)ioBuffer
                                                                 );
                }
            }
            break; // IOCTL_SEND_PHY_CONFIGURATION_PACKET

        case IOCTL_BUS_RESET_NOTIFICATION:
            {
                TRACE(TL_TRACE, ("IOCTL_BUS_RESET_NOTIFICATION\n"));

                if (InputBufferLength < sizeof(ULONG)) {

                    ntStatus = STATUS_BUFFER_TOO_SMALL;
                }
                else {

                    ntStatus = t1394_BusResetNotification( device,
                                                           Request,
                                                           *((PULONG)ioBuffer)
                                                           );
                }
            }
            break; // IOCTL_BUS_RESET_NOTIFICATION

        case IOCTL_SET_LOCAL_HOST_INFORMATION:
            {
                PSET_LOCAL_HOST_INFORMATION     SetLocalHostInformation;

                TRACE(TL_TRACE, ("IOCTL_SET_LOCAL_HOST_INFORMATION\n"));

                if (InputBufferLength < sizeof(SET_LOCAL_HOST_INFORMATION)) {

                    ntStatus = STATUS_BUFFER_TOO_SMALL;
                }
                else {

                    SetLocalHostInformation = (PSET_LOCAL_HOST_INFORMATION)ioBuffer;

                    if (InputBufferLength < (sizeof(SET_LOCAL_HOST_INFORMATION) +
                                             SetLocalHostInformation->ulBufferSize)) {

                        ntStatus = STATUS_BUFFER_TOO_SMALL;
                    }
                    else {

                        ntStatus = t1394_SetLocalHostProperties( device,
                                                                 Request,
                                                                 SetLocalHostInformation->nLevel,
                                                                 (PVOID)&SetLocalHostInformation->Information
                                                                 );

                        if (NT_SUCCESS(ntStatus))
                            WdfRequestSetInformation(Request, OutputBufferLength);
                    }
                }
            }
            break; // IOCTL_SET_LOCAL_HOST_INFORMATION

        case IOCTL_SET_ADDRESS_DATA:
            {
                PSET_ADDRESS_DATA   SetAddressData;

                TRACE(TL_TRACE, ("IOCTL_SET_ADDRESS_DATA\n"));

                if (InputBufferLength < sizeof(SET_ADDRESS_DATA)) {

                    ntStatus = STATUS_BUFFER_TOO_SMALL;
                }
                else {

                    SetAddressData = (PSET_ADDRESS_DATA)ioBuffer;

                    if (InputBufferLength -sizeof(SET_ADDRESS_DATA)  < SetAddressData->nLength) {

                        ntStatus = STATUS_BUFFER_TOO_SMALL;
                    }
                    else {

                        ntStatus = t1394_SetAddressData( device,
                                                         Request,
                                                         SetAddressData->hAddressRange,
                                                         SetAddressData->nLength,
                                                         SetAddressData->ulOffset,
                                                         (PVOID)SetAddressData->Data
                                                         );
                    }
                }
            }
            break; // IOCTL_SET_ADDRESS_DATA

        case IOCTL_GET_ADDRESS_DATA:
            {
                PGET_ADDRESS_DATA   GetAddressData;

                TRACE(TL_TRACE, ("IOCTL_GET_ADDRESS_DATA\n"));

                if ((InputBufferLength < sizeof(GET_ADDRESS_DATA)) ||
                    (OutputBufferLength < sizeof(GET_ADDRESS_DATA))) {

                    ntStatus = STATUS_BUFFER_TOO_SMALL;
                }
                else {

                    GetAddressData = (PGET_ADDRESS_DATA)ioBuffer;

                    if ((InputBufferLength -sizeof(GET_ADDRESS_DATA)  < GetAddressData->nLength) ||
                        (OutputBufferLength - sizeof (GET_ADDRESS_DATA) < GetAddressData->nLength)) {

                        ntStatus = STATUS_BUFFER_TOO_SMALL;
                    }
                    else {

                        ntStatus = t1394_GetAddressData( device,
                                                         Request,
                                                         GetAddressData->hAddressRange,
                                                         GetAddressData->nLength,
                                                         GetAddressData->ulOffset,
                                                         (PVOID)GetAddressData->Data
                                                         );

                        if (NT_SUCCESS(ntStatus)) {
                            WdfRequestSetInformation(Request, OutputBufferLength);
                        }
                    }
                }
            }
            break; // IOCTL_GET_ADDRESS_DATA

        case IOCTL_BUS_RESET_NOTIFY:

            TRACE(TL_TRACE, ("IOCTL_BUS_RESET_NOTIFY\n"));
            //
            // These requests will be held in the queue in a cancelable state.
            //
            ntStatus = WdfRequestForwardToIoQueue( Request,
                                                   deviceExtension->BusResetRequestsQueue
                                                   );

            if (NT_SUCCESS(ntStatus)) {

                //
                // The Request is now owned by the Framework until it delivers
                // the Request from the new queue to the driver. This means that
                // the Request should not be accessed any further in this routine.
                //
                ntStatus = STATUS_PENDING;
            }

            break; // IOCTL_BUS_RESET_NOTIFY

        case IOCTL_GET_DIAG_VERSION:
            {
                PVERSION_DATA   Version;

                TRACE(TL_TRACE, ("IOCTL_GET_DIAG_VERSION\n"));

                if ((InputBufferLength < sizeof(VERSION_DATA)) &&
                    (OutputBufferLength < sizeof(VERSION_DATA))) {

                        ntStatus = STATUS_BUFFER_TOO_SMALL;
                }
                else {

                    Version = (PVERSION_DATA)ioBuffer;
                    Version->ulVersion = DIAGNOSTIC_VERSION;
                    Version->ulSubVersion = DIAGNOSTIC_SUB_VERSION;

                    WdfRequestSetInformation(Request, OutputBufferLength);
                }
            }
            break; // IOCTL_GET_DIAG_VERSION

        default:
            TRACE(TL_ERROR, ("Invalid ioControlCode = 0x%x\n", IoControlCode));
            ntStatus = STATUS_INVALID_PARAMETER;
            break; // default

    } // switch


    // only complete if the device is there
    if (ntStatus != STATUS_PENDING) {

        WdfRequestComplete(Request, ntStatus);
    }

    EXIT("t1394_IoControl", ntStatus);
    return ;
} // t1394_EvtIoDeviceControl



