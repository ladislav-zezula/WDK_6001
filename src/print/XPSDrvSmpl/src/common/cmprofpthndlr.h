/*++

Copyright (c) 2005 Microsoft Corporation

All rights reserved.

THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

File Name:

   cmprofpthndlr.h

Abstract:

   JobOptimalDestinationColorProfile PrintTicket handling definition.
   The JobOptimalDestinationColorProfile PT handler is used to extract
   JobOptimalDestinationColorProfile settings from a PrintTicket and populate
   the JobOptimalDestinationColorProfile data structure with the retrieved
   settings. The class also defines a method for setting the feature in
   the PrintTicket given the data structure.

--*/

#pragma once

#include "pthndlr.h"
#include "cmprofiledata.h"

class CColorManageProfilePTHandler : public CPTHandler
{
public:
    CColorManageProfilePTHandler(
        __in IXMLDOMDocument2* pPrintTicket
        );

    virtual ~CColorManageProfilePTHandler();

    HRESULT
    GetData(
        __out XDPrintSchema::JobOptimalDestinationColorProfile::JobOptimalDestinationColorProfileData* pCmData
        );

    HRESULT
    SetData(
        __in CONST XDPrintSchema::JobOptimalDestinationColorProfile::JobOptimalDestinationColorProfileData* pCmData
        );
};


