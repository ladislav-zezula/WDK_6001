/*++

Copyright (c) 2005 Microsoft Corporation

All rights reserved.

THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

File Name:

   cmprofileschema.cpp

Abstract:

   JobOptimalDestinationColorProfile PrintSchema implementation. This implements the
   features, options and enumerations that describe the PrintSchema
   JobOptimalDestinationColorProfile feature.

--*/

#include "precomp.h"
#include "cmprofileschema.h"

LPCWSTR XDPrintSchema::JobOptimalDestinationColorProfile::PROFILE_FEATURE = L"JobOptimalDestinationColorProfile";
LPCWSTR XDPrintSchema::JobOptimalDestinationColorProfile::PROFILE_OPTION = L"Profile";
LPCWSTR XDPrintSchema::JobOptimalDestinationColorProfile::PATH = L"Path";

LPCWSTR XDPrintSchema::JobOptimalDestinationColorProfile::PROFILESELECTOR[] = {
    L"RGB",
    L"ICC",
    L"CMYK"
};


