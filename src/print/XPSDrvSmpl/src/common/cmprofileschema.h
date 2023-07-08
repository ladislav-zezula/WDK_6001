/*++

Copyright (c) 2005 Microsoft Corporation

All rights reserved.

THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

File Name:

   cmintentsschema.h

Abstract:

   JobOptimalDestinationColorProfile PrintSchema definition. This defines the features,
   options and enumerations that describe the PrintSchema JobOptimalDestinationColorProfile
   feature within a XDPrintSchema::JobOptimalDestinationColorProfile namespace.


--*/

#pragma once

#include "schema.h"

namespace XDPrintSchema
{
    //
    // PageColorManagement elements described as Printschema keywords
    //
    namespace JobOptimalDestinationColorProfile
    {
        //
        // Feature name
        //
        extern LPCWSTR PROFILE_FEATURE;

        //
        // Profile option
        //
        extern LPCWSTR PROFILE_OPTION;


        extern LPCWSTR PATH;

        //
        // Who specified the profile to use
        //
        enum EProfileOption
        {
            RGB = 0, EProfileOptionMin = 0,
            ICC,
            CMYK,
            EProfileOptionMax
        };

        extern LPCWSTR PROFILESELECTOR[EProfileOptionMax];

        //
        // Page color profile name
        //
        extern LPCWSTR PROFILENAME;
    }
}


