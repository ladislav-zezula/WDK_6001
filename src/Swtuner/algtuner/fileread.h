/**************************************************************************

    AVStream Simulated Hardware Sample Modified to Read Video Disk Files

    Copyright (c) Microsoft Corporation.  All rights reserved.

    File:
        fileread.cpp

    Abstract:
        This file contains the addition routines to read disk based video 
        files and have them accessed by the "fake" hardware in hwsim.cpp

    History:
        created 6/13/2002

**************************************************************************/

class CFileReader {

 protected:
  PKSDEVICE m_Device;
  PUNICODE_STRING m_RegistryPath;
  ULONG m_ulFrequency;

 public:
  CFileReader();
  CFileReader(PKSDEVICE Device, PUNICODE_STRING RegistryPath);
  void SetFrequency(ULONG frequency);
  ULONG GetFrequency();
  ULONG Read(OUT PUCHAR buffer, ULONG sampleSize);
  void Start();
  void Stop();
};





