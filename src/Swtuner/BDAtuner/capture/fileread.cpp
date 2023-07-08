//==========================================================================;
//
//  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
//  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
//  PURPOSE.
//
//  Copyright (c) Microsoft Corporation.  All Rights Reserved.
//
//==========================================================================;

#define DEFINE_REG_VAR
#include "BDACap.h"
ULONG g_FileCompleteStatus = 0;
ULONG g_FileChangeIndex = -1;

/**************************************************************************
    PAGEABLE CODE
**************************************************************************/
    
#ifdef ALLOC_PRAGMA
#pragma code_seg()
#endif // ALLOC_PRAGMA

#define VIDEO_READ_BUFFER_SIZE PS_SAMPLE_SIZE*10

PCWSTR  MpegFileName193250kHz=L"\\??\\C:\\mpeg\\LipSync4.ts"; //chan10
PCWSTR  MpegFileName199250kHz=L"\\??\\C:\\mpeg\\Ber192-3.trp"; //chan11
PCWSTR  MpegFileName205250kHz=L"\\??\\C:\\mpeg\\205250kHz.ts"; //chan12
PCWSTR  MpegFileName211250kHz=L"\\??\\C:\\mpeg\\211250kHz.ts"; //chan13

PCWSTR  MpegFileName537250kHz=L"\\??\\C:\\mpeg\\Ber192-3.trp"; //chan25
PCWSTR  MpegFileName615250kHz=L"\\??\\C:\\mpeg\\Sample_Type09_25M_pure.ts"; //chan38
PCWSTR  MpegFileName621250kHz=L"\\??\\C:\\mpeg\\Ch77dump.ts"; //chan39
//PCWSTR  MpegFileName943250kHz=L"\\??\\D:\\mpeg\\Ber192-3.trp"; //chan149

//PCWSTR NAMED_PIPE_NAME = L"\\??\\pipe\\FrequencyPipe";
PCWSTR NAMED_PIPE_NAME = L"\\??\\C:\\Windows\\system32\\FrequencyPipe.txt";
PCWSTR FREQUENCY_PIPE_NAME = L"\\??\\C:\\FrequencyToRead.txt";

ULONG ReadBufferSize = VIDEO_READ_BUFFER_SIZE;



typedef struct tag_ReadVideoStreamFile {
   KSPIN_LOCK  LockAccess;
   ULONG       Status;
   IO_STATUS_BLOCK IoStatus;
   HANDLE      VideoFile;
   CHAR *      ReadBuffers[2];
   ULONG       ReadBufferFill[2];
   ULONG       ReadBufferGet[2];
   ULONG       ReadIndex;
   PVOID       CaptureBuffer;
   ULONG       CaptureRemaining;
   ULONG       CaptureIndex;
   ULONG       ReadCount;
   ULONG       RewindCount;
   ULONG       GetSuccess;
   ULONG       GetFail;
   ULONG       GetFailRun;
   ULONG       GetFailRunMax;
   BOOL        StopRequest;
   KEVENT      ReadEvent;
   KEVENT      InitEvent;
   PIO_WORKITEM  ThreadItem;
   PWSTR        FileName;
   ULONG        Tunerfrequency;
  CCaptureDevice* CDevice;
  CFileReader   *FileReader;
} ReadVideoStreamFile,*PReadVideoStreamFile;

PReadVideoStreamFile VideoStream;
PReadVideoStreamFile VidReadStart(IN PDEVICE_OBJECT DeviceObject, PCWSTR FileName,CFileReader* cfr);
PReadVideoStreamFile VidReadStop(PReadVideoStreamFile ReadDataBlock);
VOID VidReadWorkItem(IN PDEVICE_OBJECT DeviceObject,IN PVOID Context);
ULONG VidGetCaptureData(__out_ecount(Length) PVOID Buffer,ULONG Length,PReadVideoStreamFile ReadDataBlock);

CFileReader::CFileReader() {
    m_pFileName = MpegFileName193250kHz;
}

CFileReader::CFileReader(PKSDEVICE Device, PUNICODE_STRING RegistryPath) {
  CCaptureDevice* CDevice;
  m_Device = Device;
  CDevice = reinterpret_cast <CCaptureDevice *> (Device -> Context);
  m_RegistryPath = RegistryPath;
  m_pFileName = MpegFileName193250kHz;
  m_ulFrequency = CDevice->Get_theFrequency();
  DbgPrint("Filename %S", m_pFileName);
}

void CFileReader::Start() {
  VideoStream = VidReadStart(m_Device->PhysicalDeviceObject, m_pFileName, this);
}

void CFileReader::Stop() {
  VideoStream = VidReadStop(VideoStream);
}

ULONG CFileReader::Read(OUT PUCHAR buffer, ULONG sampleSize) {
  return VidGetCaptureData(buffer, sampleSize, VideoStream);
}

void CFileReader::SetFrequency(ULONG frequency) {
  DbgPrint("SetFrequency %ld\n", frequency);
  m_ulFrequency = frequency;
}

ULONG CFileReader::GetFrequency() {
  return m_ulFrequency;
}
 
PReadVideoStreamFile VidReadStart(IN PDEVICE_OBJECT DeviceObject, PCWSTR FileName, CFileReader* cfr)
{
   KIRQL             SpinIrql;
   DbgPrint( "VidReadStart %S\n", FileName);

   PReadVideoStreamFile ReadDataBlock;
   NTSTATUS     WaitStatus;

   //  First, allocate buffers
   ReadDataBlock = (PReadVideoStreamFile)ExAllocatePoolWithTag(NonPagedPool,
      sizeof(ReadVideoStreamFile), MS_SAMPLE_ANALOG_POOL_TAG);
   if (!ReadDataBlock) {
   }

   RtlZeroMemory(ReadDataBlock,
      sizeof(ReadVideoStreamFile));
   ReadDataBlock->ReadBuffers[0]=(CHAR *)ExAllocatePoolWithTag(NonPagedPool,
      ReadBufferSize, MS_SAMPLE_ANALOG_POOL_TAG);
   if (!ReadDataBlock->ReadBuffers[0]) {
   }

   ReadDataBlock->ReadBuffers[1]=(CHAR *)ExAllocatePoolWithTag(NonPagedPool,
      ReadBufferSize, MS_SAMPLE_ANALOG_POOL_TAG);
   if (!ReadDataBlock->ReadBuffers[0]) {
   }


   //   Now, get events and mutex 
   KeInitializeEvent(&(ReadDataBlock->ReadEvent),
      SynchronizationEvent,
      FALSE);

   KeInitializeEvent(&(ReadDataBlock->InitEvent),
             SynchronizationEvent,
             FALSE);

    ReadDataBlock->FileReader = cfr;

   KeInitializeSpinLock(&(ReadDataBlock->LockAccess));
    KeAcquireSpinLock(&(ReadDataBlock->LockAccess),
       &SpinIrql);
//     ReadDataBlock->CDevice = reinterpret_cast <CCaptureDevice *> (cfr->m_Device -> Context);
    ReadDataBlock->Tunerfrequency = cfr->GetFrequency();

    KeReleaseSpinLock(&(ReadDataBlock->LockAccess),
       SpinIrql);

    size_t FileNameLength = 0;
    RtlStringCbLengthW(FileName, 2147483647 * sizeof(WCHAR), &FileNameLength);
    
    ReadDataBlock->FileName =(WCHAR *)ExAllocatePoolWithTag(NonPagedPool,
       FileNameLength+2, MS_SAMPLE_ANALOG_POOL_TAG);

    RtlStringCbCopyW((WCHAR *)ReadDataBlock->FileName, FileNameLength+2, FileName);

   // worker thread item for reads
   ReadDataBlock->ThreadItem=IoAllocateWorkItem(DeviceObject);

   IoQueueWorkItem(ReadDataBlock->ThreadItem,
      VidReadWorkItem,
      CriticalWorkQueue,
      ReadDataBlock);

   WaitStatus = KeWaitForSingleObject(&(ReadDataBlock->InitEvent),
      Executive,
      KernelMode,
      FALSE,
      NULL);

   if (!NT_SUCCESS(WaitStatus)) {
       return NULL;
   }

   return ReadDataBlock;
}


PReadVideoStreamFile VidReadStop(PReadVideoStreamFile ReadDataBlock)
{
    DbgPrint( "VidReadStop\n");


   NTSTATUS Status;
   ReadDataBlock->StopRequest=TRUE;

   Status = KeSetEvent(&(ReadDataBlock->ReadEvent),  //Trigger stop
      0,
      FALSE);
   if (Status) {
       // Do something
   }

   Status = KeWaitForSingleObject(&(ReadDataBlock->InitEvent), //Wait for stop
           Executive,
           KernelMode,
           FALSE,
           NULL);

   if (!NT_SUCCESS(Status)) {
       // Do something
   }

   IoFreeWorkItem(ReadDataBlock->ThreadItem); // Release Work Item
   ExFreePool(ReadDataBlock->ReadBuffers[0]);
   ExFreePool(ReadDataBlock->ReadBuffers[1]);
   ExFreePool(ReadDataBlock);
   return 0;
}



DWORD ReadDWORDFromFile()
{
   OBJECT_ATTRIBUTES FileObject;
   UNICODE_STRING    FileName; 
   NTSTATUS          Status;
    HANDLE _hFrequencyPipeHandle;
    UNICODE_STRING namedPipe;
    OBJECT_ATTRIBUTES attr;

    RtlInitUnicodeString ( &namedPipe, FREQUENCY_PIPE_NAME);

    InitializeObjectAttributes ( 
        &attr,
        &namedPipe,
        OBJ_CASE_INSENSITIVE | OBJ_KERNEL_HANDLE,
        NULL,
        NULL
        );

    IO_STATUS_BLOCK ioStatusBlock;

    Status = ZwCreateFile( &_hFrequencyPipeHandle, 
                                GENERIC_READ, 
                                &attr, 
                                &ioStatusBlock, 
                                NULL, 
                                0, 
                                FILE_SHARE_READ, 
                                FILE_OPEN_IF, 
                                FILE_SYNCHRONOUS_IO_NONALERT|FILE_NON_DIRECTORY_FILE, 
                                NULL,
                                0 ); 

    if(!NT_SUCCESS(Status)) 
    {
        DbgPrint( "ReadDWORDFromFile  Error Creating the File 0x%08x\n", Status); 
    }

    DWORD dwFromFile;
       
    Status = ZwReadFile(_hFrequencyPipeHandle,
              NULL,
              NULL,
              NULL,
              &ioStatusBlock,
              &dwFromFile,
              sizeof(dwFromFile),
               NULL,
              NULL);

    if (!NT_SUCCESS(Status)) {
        DbgPrint( "VidReadWorkItem::ZwReadFile Failed\n");
    return 0;
    }

    // DbgPrint( "ReadDWORDFromFile::ZwReadFile %d\n", dwFromFile);

    ZwClose(_hFrequencyPipeHandle);

//    DbgPrint( "WriteDWORDToFile:: %d\n", dwFromFile);
    
    return dwFromFile;
}

DWORD 
GetDefaultStreamLocation(IN PDEVICE_OBJECT DeviceObject, OUT PUNICODE_STRING FileName)
{
    // 1) Convert dword frequency to string.
    // 2) find matching key in registry
    // 3) read StreamLocation value from registry.
    // 4) pass key back to caller.
    
    NTSTATUS Status = STATUS_SUCCESS;

    UNICODE_STRING DefaultStreamKeyName;
    RtlInitUnicodeString(&DefaultStreamKeyName, L"\\Registry\\Machine\\System\\PSWTuner\\Device Parameters");

    UNICODE_STRING StreamLocation;
    RtlZeroMemory(&StreamLocation, sizeof(StreamLocation));
    
    Status = PptRegGetSz(RTL_REGISTRY_ABSOLUTE, 
                        DefaultStreamKeyName.Buffer,
                        L"DefaultStreamLocation", 
                        &StreamLocation);
    if (!NT_SUCCESS(Status))
    {
        DbgPrint( "%s  Error reading the registry 0x%08x\n", __FUNCTION__, Status); 
        // There was an error, use the default filename.
        RtlInitUnicodeString(&StreamLocation, MpegFileName193250kHz);        
        Status = STATUS_SUCCESS;
    }
    DbgPrint("Stream Location %S\n", StreamLocation.Buffer);

    if(StreamLocation.Length)
      RtlInitUnicodeString(FileName, StreamLocation.Buffer);
    else
#ifdef ATSC_RECEIVER
      RtlInitUnicodeString(FileName, MpegFileName193250kHz);
#else
      RtlInitUnicodeString(FileName, MpegFileName199250kHz);
#endif

    return Status;
}
DWORD 
GetStreamLocationFromFrequency(IN PDEVICE_OBJECT DeviceObject, IN DWORD dwFreq, OUT PUNICODE_STRING FileName)
{
    // 1) Convert dword frequency to string.
    // 2) find matching key in registry
    // 3) read StreamLocation value from registry.
    // 4) pass key back to caller.
    
    NTSTATUS Status = STATUS_SUCCESS;
    UNICODE_STRING KeyName;
    KeyName.Buffer = (LPWSTR)ExAllocatePoolWithTag(NonPagedPool,
                                              MAX_PATH+1, 
                                              MS_SAMPLE_ANALOG_POOL_TAG
                                              );
    KeyName.Length = MAX_PATH;
    KeyName.MaximumLength = MAX_PATH;

    UNICODE_STRING StubName;
    RtlInitUnicodeString(&StubName, L"\\Registry\\Machine\\System\\PSWTuner\\Device Parameters\\");

    RtlCopyUnicodeString(&KeyName, &StubName);

    UNICODE_STRING Freq;
    Freq.Buffer = (LPWSTR)ExAllocatePoolWithTag(NonPagedPool,
                                              MAX_PATH+1, 
                                              MS_SAMPLE_ANALOG_POOL_TAG
                                              );
    Freq.Length = MAX_PATH;
    Freq.MaximumLength = MAX_PATH;
    
    RtlZeroMemory(Freq.Buffer,  MAX_PATH+1);
    RtlIntegerToUnicodeString(dwFreq, 10, &Freq);

    DbgPrint("Converted Frequency value %S\n", Freq.Buffer);

    RtlAppendUnicodeStringToString(&KeyName, &Freq);

    DbgPrint("KeyName %S\n", KeyName.Buffer);


    UNICODE_STRING StreamLocation;
    RtlZeroMemory(&StreamLocation, sizeof(StreamLocation));
    
    Status = PptRegGetSz(RTL_REGISTRY_ABSOLUTE, 
                        KeyName.Buffer,
                        L"StreamLocation", 
                        &StreamLocation);
    if (!NT_SUCCESS(Status))
    {
        DbgPrint( "%s  Error reading the registry 0x%08x\n", __FUNCTION__, Status); 
        // There was an error, use the default stream filename.
        Status = GetDefaultStreamLocation(DeviceObject, &StreamLocation);
    }
    DbgPrint("Stream Location %S\n", StreamLocation.Buffer);

    RtlInitUnicodeString(FileName, StreamLocation.Buffer);

    return Status;
}
VOID VidReadWorkItem(IN PDEVICE_OBJECT DeviceObject,IN PVOID Context)
{
    DbgPrint( "VidReadWorkItem\n");

   OBJECT_ATTRIBUTES FileObject;
   UNICODE_STRING    FileName; 
   NTSTATUS          Status;
   BOOL              FirstPass=TRUE;
   KIRQL             SpinIrql;

   PReadVideoStreamFile ReadDataBlock= static_cast<PReadVideoStreamFile>( Context);

   DbgPrint("Filename %S", ReadDataBlock->FileName);

/* 10/12/04 currently crashing.*/
/*    // Create Named Pipe
    Status = NtCreateNamedPipeFile (
                &_hNamedPipeHandle,
                FILE_ANY_ACCESS,
                &attr,
                &ioStatusBlock,
                FILE_SHARE_READ | FILE_SHARE_WRITE,
                FILE_CREATE,
                0,
                0,  //FILE_PIPE_BYTE_STREAMTYPE,
                0,  //FILE_PIPE_BYTE_STREAM_MODE,
                     0,  // FILE_PIPE_QUEUE_OPERATION,
                1,
                0,
                0,
                NULL//&nTimeOut
                );

    if (NT_SUCCESS (Status))
    {
        KdPrint (("Pipe created succesfully\n")); 
    }
*/

   DbgPrint( "VidReadWorkItem  Check for change in named pipe and/or config file. \n");

    HANDLE _hNamedPipeHandle;
    UNICODE_STRING namedPipe;
    OBJECT_ATTRIBUTES attr;
/*
    RtlInitUnicodeString ( &namedPipe, NAMED_PIPE_NAME );
    InitializeObjectAttributes ( 
        &attr,
        &namedPipe,
        OBJ_CASE_INSENSITIVE | OBJ_KERNEL_HANDLE,
        NULL,
        NULL
        );
  //   nTimeOut.QuadPart = -1000;
    IO_STATUS_BLOCK ioStatusBlock;

    Status = ZwCreateFile( &_hNamedPipeHandle, 
                                SYNCHRONIZE|FILE_ANY_ACCESS, 
                                &attr, 
                                &ioStatusBlock, 
                                NULL, 
                                0, 
                                FILE_SHARE_READ|FILE_SHARE_WRITE, 
                                FILE_OPEN_IF, 
                                FILE_SYNCHRONOUS_IO_NONALERT|FILE_NON_DIRECTORY_FILE, 
                                NULL,
                                0 ); 

    if(!NT_SUCCESS(Status)) 
    {
        DbgPrint( "VidReadWorkItem  Error Creating the File 0x%08x\n", Status); 
    }

    DbgPrint( "VidReadWorkItem:: about to ZwReadFile\n");

   FILE_STANDARD_INFORMATION StandardInfo;
   
   Status = ZwQueryInformationFile( _hNamedPipeHandle,
                                      &ioStatusBlock,
                                      &StandardInfo,
                                      sizeof(FILE_STANDARD_INFORMATION),
                                      FileStandardInformation );

    if (!NT_SUCCESS(Status)) 
    {
        DbgPrint("Error querying info on file %x\n", Status);
        ZwClose( _hNamedPipeHandle );
    }
   
   ULONG LengthOfFile;
   LengthOfFile = StandardInfo.EndOfFile.LowPart;

   DbgPrint("File length is %d\n", LengthOfFile);


    //  Signal Event to fill both buffers
    LPSTR pszFileName;

     pszFileName = (LPSTR)ExAllocatePoolWithTag(NonPagedPool,
                                                                          LengthOfFile+1, 
                                                                          MS_SAMPLE_ANALOG_POOL_TAG
                                                                          );
   RtlZeroMemory(pszFileName,  LengthOfFile+1);

//    LARGE_INTEGER liOffset;
//    liOffset.HighPart = 0;
//    liOffset.LowPart = 2;
    Status = ZwReadFile(_hNamedPipeHandle,
              NULL,
              NULL,
              NULL,
              &ioStatusBlock,
              pszFileName,
              LengthOfFile,
               NULL,
              NULL);

    if (!NT_SUCCESS(Status)) {
        DbgPrint( "VidReadWorkItem::ZwReadFile Failed\n");
    return;
    }

    //DbgPrint( "VidReadWorkItem::ZwReadFile read %d bytes\n", ioStatusBlock.Information);
    DbgPrint( "VidReadWorkItem::ZwReadFile %s\n", pszFileName);

    ANSI_STRING ansiFileName;
    if (ioStatusBlock.Status == STATUS_SUCCESS)
    {
       RtlInitAnsiString(&ansiFileName, pszFileName);
       Status = RtlAnsiStringToUnicodeString(&FileName,  &ansiFileName, TRUE);  // LEAK!!
       if (!NT_SUCCESS(Status)) 
        {
            DbgPrint( "VidReadWorkItem:: RtlAnsiStringToUnicodeString failed 0x%d\n",Status);
            return;
        }

    }
    else
    {
       RtlInitUnicodeString(&FileName,  ReadDataBlock->FileName);
    }


    Status = ZwClose(_hNamedPipeHandle);
    if(!NT_SUCCESS(Status)) 
    {
        DbgPrint( "VidReadWorkItem  Error Closing the filehandle 0x%08x\n", Status); 
    }
  

*/
//    RtlInitUnicodeString(&FileName,  ReadDataBlock->FileName);

#if !PROPERTYSET_CAPTUREDRIVER
    DWORD dwInitialFreq = ReadDWORDFromFile();
#else if

   KeInitializeSpinLock(&(ReadDataBlock->LockAccess));
    KeAcquireSpinLock(&(ReadDataBlock->LockAccess),
       &SpinIrql);
    ReadDataBlock->Tunerfrequency = ReadDataBlock->FileReader->GetFrequency();
    ULONG dwInitialFreq = ReadDataBlock->Tunerfrequency;
    KeReleaseSpinLock(&(ReadDataBlock->LockAccess),
       SpinIrql);
    if(!dwInitialFreq)
       dwInitialFreq = ReadDWORDFromFile();
#endif

    if(dwInitialFreq)
    {
       Status = GetStreamLocationFromFrequency(DeviceObject, dwInitialFreq, &FileName);
    }
    else
    {
        GetDefaultStreamLocation(DeviceObject,&FileName);
    }

    InitializeObjectAttributes(&FileObject,
       &FileName,
       OBJ_KERNEL_HANDLE,    
       NULL,
       NULL);

    Status = ZwCreateFile(&(ReadDataBlock->VideoFile),
       FILE_READ_DATA | SYNCHRONIZE,
       &FileObject,
       &(ReadDataBlock->IoStatus),
       NULL,
       FILE_ATTRIBUTE_NORMAL,
       FILE_SHARE_READ,
       FILE_OPEN,
       FILE_SYNCHRONOUS_IO_NONALERT,
       NULL,
       0);

    if (!NT_SUCCESS(Status)) {
        DbgPrint( "VidReadWorkItem::ZwCreateFile Failed %08x\n", Status);
           Status = KeSetEvent(&(ReadDataBlock->InitEvent), 0,FALSE);
    return;
    }

    //  Signal Event to fill both buffers
    Status = ZwReadFile(ReadDataBlock->VideoFile,
              NULL,
              NULL,
              NULL,
              &(ReadDataBlock->IoStatus),
              ReadDataBlock->ReadBuffers[0],
              VIDEO_READ_BUFFER_SIZE,
              NULL,
              NULL);

    if (!NT_SUCCESS(Status)) {
        DbgPrint( "VidReadWorkItem::ZwReadFile Failed\n");
           Status = KeSetEvent(&(ReadDataBlock->InitEvent),0,FALSE);
    return;
    }

    // Set size from read
    KeAcquireSpinLock(&(ReadDataBlock->LockAccess),
       &SpinIrql);
    ReadDataBlock->ReadBufferFill[0]=(ULONG)ReadDataBlock->IoStatus.Information;
    ReadDataBlock->ReadCount++;
    KeReleaseSpinLock(&(ReadDataBlock->LockAccess),
       SpinIrql);

    do {
//        DbgPrint( "VidReadWorkItem:: about to acquire spinlock2\n");
       KeAcquireSpinLock(&(ReadDataBlock->LockAccess),
          &SpinIrql);
       ReadDataBlock->ReadIndex++;  // Switch Buffers

       if(ReadDataBlock->ReadIndex>1)
          ReadDataBlock->ReadIndex=0;

       // Lock buffer so only we can get to it
       if(FirstPass) {
          // On initilization, let start() continue
          FirstPass=FALSE;
          Status = KeSetEvent(&(ReadDataBlock->InitEvent),
                  0,
                  FALSE);
           if (Status) {
           }
       }
       KeReleaseSpinLock(&(ReadDataBlock->LockAccess),
          SpinIrql);
//       DbgPrint( "VidReadWorkItem:: post release spinlock2\n");

       // Wait for buffer to be needed

        Status = KeWaitForSingleObject(&(ReadDataBlock->ReadEvent),
           Executive,
           KernelMode,
           FALSE,
           NULL);

    if (!NT_SUCCESS(Status)) {
        DbgPrint( "VidReadWorkItem::KeWaitForSingleObject Failed\n");
        return;
    }

        if(ReadDataBlock->StopRequest){  // Stop Code Here
           Status = ZwClose(ReadDataBlock->VideoFile); // Close File
       if (!NT_SUCCESS(Status)) {
           return;
       }

           Status = KeSetEvent(&(ReadDataBlock->InitEvent),
              0,
              FALSE);
       if (Status) {
       }

           return;  //  bye bye thread
        }

//        DbgPrint( "VidReadWorkItem:: about to read from video file line 307\n");
//        DbgPrint( "VidReadWorkItem::GetCurrentIRQL:  %d\n", KeGetCurrentIrql());

    // read the current frequency value and change filenames if needed.

#if !PROPERTYSET_CAPTUREDRIVER
    DWORD dwCurrentFreq = ReadDWORDFromFile();
#else if
    KeInitializeSpinLock(&(ReadDataBlock->LockAccess));
    KeAcquireSpinLock(&(ReadDataBlock->LockAccess),
       &SpinIrql);
    ReadDataBlock->Tunerfrequency = ReadDataBlock->FileReader->GetFrequency();
    ULONG dwCurrentFreq = ReadDataBlock->Tunerfrequency;
    KeReleaseSpinLock(&(ReadDataBlock->LockAccess),
       SpinIrql);

    if(!dwCurrentFreq)
       dwCurrentFreq = ReadDWORDFromFile();
#endif

    // if the frequency is different, close the old file, and open the new file.
    if (dwInitialFreq != dwCurrentFreq)
    {
        Status = ZwClose(ReadDataBlock->VideoFile); // Close File
        if (!NT_SUCCESS(Status)) 
        {
            DbgPrint("Couldn't close the old file 0x%08x", Status);
        }
        // Ensure the setting is updated.
        dwInitialFreq = dwCurrentFreq;

        // now, open the new file.
        UNICODE_STRING _pFileName;
        Status = GetStreamLocationFromFrequency(DeviceObject, dwCurrentFreq, &_pFileName);

        if (!NT_SUCCESS(Status))
        {
            DbgPrint( "VidReadWorkItem  Error Getting StreamLocation 0x%08x\n", Status); 
        }
        DbgPrint("New Filename %S", _pFileName.Buffer);

        InitializeObjectAttributes(&FileObject,
                   &_pFileName,
                   OBJ_KERNEL_HANDLE,
                   NULL,
                   NULL);


        Status = ZwCreateFile(&(ReadDataBlock->VideoFile),
               FILE_READ_DATA | SYNCHRONIZE,
               &FileObject,
               &(ReadDataBlock->IoStatus),
               NULL,
               FILE_ATTRIBUTE_NORMAL,
               FILE_SHARE_READ,
               FILE_OPEN,
               FILE_SYNCHRONOUS_IO_NONALERT,
               NULL,
               0);

        if (!NT_SUCCESS(Status)) 
        {
            DbgPrint("Couldn't close the old file 0x%08x", Status);
        }
            

    }
   


        Status = ZwReadFile(ReadDataBlock->VideoFile,
              NULL,
              NULL,
              NULL,
              &(ReadDataBlock->IoStatus),
              ReadDataBlock->ReadBuffers[ReadDataBlock->ReadIndex],
              VIDEO_READ_BUFFER_SIZE,
              NULL,
              NULL);

    if (!NT_SUCCESS(Status)) {
        DbgPrint( "VidReadWorkItem::ZwReadFile line 715 Failed\n");
        return;
    }

    // Set size from read
        KeAcquireSpinLock(&(ReadDataBlock->LockAccess),
           &SpinIrql);
        ReadDataBlock->ReadCount++;
        
        if (ReadDataBlock->IoStatus.Information<ReadBufferSize) {

       if (g_FileChangeIndex == -1) g_FileChangeIndex = ReadDataBlock->ReadIndex;


           ULONG RewindReadSize=(ULONG)(ReadBufferSize-ReadDataBlock->IoStatus.Information);
           PUCHAR RewindBuffer=(PUCHAR) ReadDataBlock->ReadBuffers[ReadDataBlock->ReadIndex];
           IO_STATUS_BLOCK RewindCompletion;
           NTSTATUS RewindStatus;
           FILE_POSITION_INFORMATION Rewind;

           RtlZeroMemory(RewindBuffer,
              RewindReadSize);
           ReadDataBlock->IoStatus.Information=ReadBufferSize;
           KeReleaseSpinLock(&(ReadDataBlock->LockAccess),
             SpinIrql);

           RtlZeroMemory(&Rewind,
              sizeof(FILE_POSITION_INFORMATION));

           RewindStatus = ZwSetInformationFile(ReadDataBlock->VideoFile,
              &RewindCompletion,
              &Rewind,
              sizeof(FILE_POSITION_INFORMATION),
              FilePositionInformation);

       if (!NT_SUCCESS(RewindStatus)) {
           DbgPrint( "VidReadWorkItem::ZwSetInformationFile Failed\n");
           return;
       }

           KeAcquireSpinLock(&(ReadDataBlock->LockAccess),
              &SpinIrql);
           ReadDataBlock->RewindCount++;
        }

        ReadDataBlock->ReadBufferFill[ReadDataBlock->ReadIndex] = 
           (ULONG)ReadDataBlock->IoStatus.Information;

        KeReleaseSpinLock(&(ReadDataBlock->LockAccess),
          SpinIrql);  

    } while ( TRUE );
}


typedef struct _NAMED_PIPE_CREATE_PARAMETERS {
    ULONG NamedPipeType;
    ULONG ReadMode;
    ULONG CompletionMode;
    ULONG MaximumInstances;
    ULONG InboundQuota;
    ULONG OutboundQuota;
    LARGE_INTEGER DefaultTimeout;
    BOOLEAN TimeoutSpecified;
} NAMED_PIPE_CREATE_PARAMETERS, *PNAMED_PIPE_CREATE_PARAMETERS;

NTSTATUS  NtCreateNamedPipeFile (
            OUT PHANDLE FileHandle,
            IN ULONG DesiredAccess,
            IN POBJECT_ATTRIBUTES ObjectAttributes,
            OUT PIO_STATUS_BLOCK IoStatusBlock,
            IN ULONG ShareAccess,
            IN ULONG CreateDisposition,
            IN ULONG CreateOptions,
            IN ULONG NamedPipeType,
            IN ULONG ReadMode,
            IN ULONG CompletionMode,
            IN ULONG MaximumInstances,
            IN ULONG InboundQuota,
            IN ULONG OutboundQuota,
            IN PLARGE_INTEGER DefaultTimeout OPTIONAL 
            )  
{   
    NAMED_PIPE_CREATE_PARAMETERS NamedPipeParms;
    NTSTATUS Status;
    __try   
    {   
        if ( DefaultTimeout )
        {
            NamedPipeParms.TimeoutSpecified = TRUE;
            NamedPipeParms.DefaultTimeout.QuadPart = DefaultTimeout->QuadPart;
        }
        else
        {   
            NamedPipeParms.TimeoutSpecified = FALSE;
        } 
          
        NamedPipeParms.NamedPipeType = NamedPipeType;
        NamedPipeParms.ReadMode = ReadMode;
        NamedPipeParms.CompletionMode = CompletionMode;
        NamedPipeParms.MaximumInstances = MaximumInstances;
        NamedPipeParms.InboundQuota = InboundQuota;
        NamedPipeParms.OutboundQuota = OutboundQuota;
        Status = IoCreateFile (
                    FileHandle,
                    DesiredAccess,
                    ObjectAttributes,
                    IoStatusBlock,
                    NULL,
                    0,
                    ShareAccess,
                    CreateDisposition,
                    CreateOptions,
                    NULL,
                    0,
                    CreateFileTypeNamedPipe,
                    &NamedPipeParms,
                    0   
                    );

        return Status;
    }   
    __except (EXCEPTION_EXECUTE_HANDLER)   
    {
       KdPrint (("NtCreateNamedPipeFile: Exception occured.\n"));
       return STATUS_UNSUCCESSFUL;   
    }
}    


ULONG VidGetCaptureData(__out_ecount(Length) PVOID Buffer,ULONG Length,PReadVideoStreamFile ReadDataBlock)
{

   ULONG ThisIndex;
   ULONG NextIndex;
   CHAR * GetBuffer;
   CHAR * PutBuffer;
   ULONG Length1;
   ULONG Length2;
   NTSTATUS Status;


   KeAcquireSpinLockAtDpcLevel(&(ReadDataBlock->LockAccess));


   ThisIndex = ReadDataBlock->CaptureIndex;
  
   if(ThisIndex == 0)
      NextIndex=1;
   else
      NextIndex=0;

   if (ThisIndex == g_FileChangeIndex) { 
       g_FileCompleteStatus = 1;
       g_FileChangeIndex = -1;
   }

   Length1 = ReadDataBlock->ReadBufferFill[ThisIndex]-
      ReadDataBlock->ReadBufferGet[ThisIndex];

   //   Get not spanned across buffers
   if(Length1>=Length) {

      //  first get from buffer, start read to next
      if(!ReadDataBlock->ReadBufferGet[ThisIndex]) {  

         Status = KeSetEvent(&(ReadDataBlock->ReadEvent),
            0,
            FALSE);
     if (Status) {
         return 0;
     }
      }

      // Copy Buffer
      GetBuffer = ReadDataBlock->ReadBuffers[ThisIndex];
      GetBuffer=&GetBuffer[ReadDataBlock->ReadBufferGet[ThisIndex]];

      RtlCopyMemory(Buffer,
         GetBuffer,
         Length);

      //  Increment Get Offset
      ReadDataBlock->ReadBufferGet[ThisIndex]+=Length;

      //  Buffer to very end
      if(Length1==Length)  {

         ReadDataBlock->ReadBufferGet[ThisIndex]=0;  // Reset Get Offset
         ReadDataBlock->ReadBufferFill[ThisIndex]=0;  //  Reset Fill Bytes
         ReadDataBlock->CaptureIndex=NextIndex;      // Swap Buffers

      }

      ReadDataBlock->GetSuccess++;
      KeReleaseSpinLockFromDpcLevel(&(ReadDataBlock->LockAccess));
      return Length;
   }

   // Handle Spanned Gets

   //  Get bytes available in next buffer
   Length2=ReadDataBlock->ReadBufferFill[NextIndex]-
      ReadDataBlock->ReadBufferGet[NextIndex];

   //   Return zero if can't fully satisfy request
   if((Length1+Length2) < Length) {
      ReadDataBlock->GetFail++;
      KeReleaseSpinLockFromDpcLevel(&(ReadDataBlock->LockAccess));
      return 0;
   }

    GetBuffer = ReadDataBlock->ReadBuffers[ThisIndex];
    GetBuffer=&GetBuffer[ReadDataBlock->ReadBufferGet[ThisIndex]];
    PutBuffer=(CHAR *)Buffer;

    if(Length1) { // Should always be >0

       RtlCopyMemory(Buffer,
          GetBuffer,
          Length1);

       PutBuffer = &PutBuffer[Length1];  //  Bump Put Buffer 
       Length -= Length1;
    } 
      
    GetBuffer=ReadDataBlock->ReadBuffers[NextIndex];

    RtlCopyMemory(PutBuffer,
       GetBuffer,
       Length);

    ReadDataBlock->ReadBufferGet[ThisIndex]=0;  // Reset Get Offset on First Buffer    
    ReadDataBlock->ReadBufferFill[ThisIndex]=0;  //  Reset Fill Bytes 
    ReadDataBlock->CaptureIndex=NextIndex;      // Swap Buffers
    ReadDataBlock->ReadBufferGet[NextIndex]=Length;  //  Set Next Offset
    ReadDataBlock->CaptureIndex=NextIndex;      // Swap Buffers

    // Trigger Read Event
    Status = KeSetEvent(&(ReadDataBlock->ReadEvent),
           0,
           FALSE);
    if (Status) {
    // Do something
    }

    ReadDataBlock->GetSuccess++;
    KeReleaseSpinLockFromDpcLevel(&(ReadDataBlock->LockAccess));
    return Length;
}








