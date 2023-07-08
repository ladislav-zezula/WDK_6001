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

/***************************************************************************
    File    : tstream.cpp
    Abstract: This class synthesizes a transport stream for output from the
              encoder filter.
****************************************************************************/
#include "BDACap.h"
extern UNICODE_STRING g_RegistryPath;
extern ULONG g_FileCompleteStatus;


#ifdef ALLOC_PRAGMA
#pragma code_seg()
#endif // ALLOC_PRAGMA

CTsSynthesizer::
CTsSynthesizer (
      PKSDEVICE Device,
      ULONG PacketSize,
      ULONG PacketsPerBuffer,
      ULONG Frequency
      ) :
  m_PacketSize (PacketSize),
  m_PacketsPerBuffer (PacketsPerBuffer),
  m_SynthesisBuffer (NULL),
  m_fileReader(Device, &g_RegistryPath)
{
  m_liInitialPerformanceCounter = KeQueryPerformanceCounter(&m_liPerformanceFrequency);
  m_llFrameCount = 0;
  m_ulFrequency = Frequency;
}


void
CTsSynthesizer::
SynthesizeTS (
    )
{
    // Copy the synthesized transport stream to the synthesis buffer
}


ULONG
CTsSynthesizer::
GetFrequency()
{
  return m_ulFrequency;
}

void
CTsSynthesizer::
SetFrequency(ULONG ulFrequency)
{
  m_fileReader.SetFrequency(ulFrequency);
}


PUCHAR
CTsSynthesizer::
GetTsLocation (
    ULONG PacketIndex
    )
{
//    DbgPrint( "GetTSLocation\n");
  
  LARGE_INTEGER liPerformanceCounter;
  ULONG BufferRemaining;

  if (g_FileCompleteStatus == 1) {
      m_liInitialPerformanceCounter = KeQueryPerformanceCounter(&m_liPerformanceFrequency);
      m_llFrameCount = 0;
      g_FileCompleteStatus = 0;
  }
  
  
  liPerformanceCounter.QuadPart = KeQueryPerformanceCounter(NULL).QuadPart 
    - m_liInitialPerformanceCounter.QuadPart;

  LONGLONG llFrameCount = liPerformanceCounter.QuadPart/m_liPerformanceFrequency.QuadPart * FRAME_RATE; 
  
  m_Cursor = NULL;
  if (llFrameCount >= m_llFrameCount - 15 * FRAME_RATE) {
    BufferRemaining = m_fileReader.Read(m_SynthesisBuffer, m_SampleSize);
    
    if (BufferRemaining) {
      m_llFrameCount++;
      m_Cursor = m_SynthesisBuffer + PacketIndex * m_PacketSize;
    } 

  } 
  
  return m_Cursor;
}
    
//
// PutPacket():
//
// Place a transport stream packet at the default cursor location.
// The cursor location must be set via GetTsLocation(PacketIndex).
//
void
CTsSynthesizer::
PutPacket (
   PUCHAR  TsPacket
   )
  
{
  //
  //  Copy the transport packet to the synthesis buffer.
  //
  RtlCopyMemory (
	m_Cursor,
	TsPacket,
	m_PacketSize
	);
  m_Cursor += m_PacketSize;
}

void
CTsSynthesizer::
SetSampleSize (
    ULONG PacketSize,
    ULONG PacketsPerBuffer
    )
{
  m_PacketSize = PacketSize;
  m_PacketsPerBuffer = PacketsPerBuffer;
  m_SampleSize = PacketSize * PacketsPerBuffer;
}

