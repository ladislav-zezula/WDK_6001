/*++

Copyright (c) 2005 Microsoft Corporation

All rights reserved.

THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

File Name:

   cmprofpthndlr.cpp

Abstract:

   JobOptimalDestinationColorProfile PrintTicket handling implementation.
   The JobOptimalDestinationColorProfile PT handler is used to extract
   JobOptimalDestinationColorProfile settings from a PrintTicket and populate
   the JobOptimalDestinationColorProfile data structure with the retrieved
   settings. The class also defines a method for setting the feature in
   the PrintTicket given the data structure.

--*/

#include "precomp.h"
#include "debug.h"
#include "globals.h"
#include "xdexcept.h"
#include "ptquerybld.h"
#include "cmprofpthndlr.h"

using XDPrintSchema::SCHEMA_STRING;
using XDPrintSchema::PRINTTICKET_NAME;

using XDPrintSchema::JobOptimalDestinationColorProfile::JobOptimalDestinationColorProfileData;
using XDPrintSchema::JobOptimalDestinationColorProfile::EProfileOption;
using XDPrintSchema::JobOptimalDestinationColorProfile::EProfileOptionMin;
using XDPrintSchema::JobOptimalDestinationColorProfile::EProfileOptionMax;
using XDPrintSchema::JobOptimalDestinationColorProfile::PROFILE_FEATURE;
using XDPrintSchema::JobOptimalDestinationColorProfile::PROFILE_OPTION;
using XDPrintSchema::JobOptimalDestinationColorProfile::PROFILESELECTOR;
using XDPrintSchema::JobOptimalDestinationColorProfile::PATH;

/*++

Routine Name:

    CColorManageProfilePTHandler::CColorManageProfilePTHandler

Routine Description:

    CColorManageProfilePTHandler class constructor

Arguments:

    pPrintTicket - Pointer to the DOM document representation of the PrintTicket

Return Value:

    None

--*/
CColorManageProfilePTHandler::CColorManageProfilePTHandler(
    __in IXMLDOMDocument2* pPrintTicket
    ) :
    CPTHandler(pPrintTicket)
{
}

/*++

Routine Name:

    CColorManageProfilePTHandler::~CColorManageProfilePTHandler

Routine Description:

    CColorManageProfilePTHandler class destructor

Arguments:

    None

Return Value:

    None

--*/
CColorManageProfilePTHandler::~CColorManageProfilePTHandler()
{
}

/*++

Routine Name:

    CColorManageProfilePTHandler::GetData

Routine Description:

    The routine fills the data structure passed in with color profile data
    retrieved from the PrintTicket passed to the class constructor.

Arguments:

    pCmData - Pointer to the color profile data structure to be filled in

Return Value:

    HRESULT
    S_OK                - On success
    E_ELEMENT_NOT_FOUND - Feature not present in PrintTicket
    E_*                 - On error

--*/
HRESULT
CColorManageProfilePTHandler::GetData(
    __out JobOptimalDestinationColorProfileData* pCmData
    )
{
    HRESULT hr = S_OK;

    if (SUCCEEDED(hr = CHECK_POINTER(pCmData, E_POINTER)))
    {
        CComBSTR        bstrQuery;
        CComBSTR        value;

        CPTQueryBuilder queryProfile(m_bstrFrameworkPrefix);

        if (SUCCEEDED(hr = queryProfile.AddProperty(m_bstrKeywordsPrefix, CComBSTR(PROFILE_FEATURE))) &&
            SUCCEEDED(hr = queryProfile.AddProperty(m_bstrKeywordsPrefix, CComBSTR(PROFILE_OPTION))) &&
            SUCCEEDED(hr = queryProfile.GetQuery(&bstrQuery)) &&
            SUCCEEDED(hr = QueryNodeValue(bstrQuery, &value)))
        {
            //
            // Get the profile type
            //
            for (EProfileOption cmProfile = EProfileOptionMin;
                 cmProfile < EProfileOptionMax;
                 cmProfile = static_cast<EProfileOption>(cmProfile + 1))
            {
                if (value == PROFILESELECTOR[cmProfile])
                {
                    pCmData->cmProfile = cmProfile;
                    break;
                }
            }

            if (SUCCEEDED(hr))
            {
                if (pCmData->cmProfile <  EProfileOptionMin ||
                    pCmData->cmProfile >= EProfileOptionMax)
                {
                    hr = E_FAIL;
                }
            }
        }

        if (SUCCEEDED(hr) &&
            SUCCEEDED(hr = queryProfile.AddProperty(m_bstrKeywordsPrefix, CComBSTR(PATH))) &&
            SUCCEEDED(hr = queryProfile.GetQuery(&bstrQuery)))
        {
            //
            // Get the profile name
            //
            hr = QueryNodeValue(bstrQuery, &pCmData->cmProfileName);
        }
    }

    ERR_ON_HR_EXC(hr, E_ELEMENT_NOT_FOUND);
    return hr;
}

/*++

Routine Name:

    CColorManageProfilePTHandler::SetData

Routine Description:

    This routine sets the color profile data in the PrintTicket
    passed to the class constructor.

Arguments:

    pCmData - Pointer to the color profile data to be set in the PrintTicket

Return Value:

    HRESULT
    S_OK - On success
    E_*  - On error

--*/
HRESULT
CColorManageProfilePTHandler::SetData(
    __in CONST JobOptimalDestinationColorProfileData* pCmData
    )
{
    HRESULT hr = S_OK;

    if (SUCCEEDED(hr = CHECK_POINTER(pCmData, E_POINTER)))
    {
        if (pCmData->cmProfile <  EProfileOptionMin ||
            pCmData->cmProfile >= EProfileOptionMax)
        {
            hr = E_INVALIDARG;
        }
    }

    if (SUCCEEDED(hr))
    {
        CComPtr<IXMLDOMElement> pRootProperty(NULL);
        CComPtr<IXMLDOMElement> pProfProperty(NULL);
        CComPtr<IXMLDOMElement> pPathProperty(NULL);

        CComBSTR bstrProperty(PROFILE_FEATURE);
        CComBSTR bstrProfile(PROFILESELECTOR[pCmData->cmProfile]);

        if (SUCCEEDED(hr = DeleteProperty(bstrProperty)) &&
            SUCCEEDED(hr = CreateProperty(bstrProperty, &pRootProperty)) &&
            SUCCEEDED(hr = CreateProperty(CComBSTR(PROFILE_OPTION), CComBSTR(SCHEMA_STRING), bstrProfile, &pProfProperty)) &&
            SUCCEEDED(hr = CreateProperty(CComBSTR(PATH), CComBSTR(SCHEMA_STRING), pCmData->cmProfileName, &pPathProperty)) &&
            SUCCEEDED(hr = pProfProperty->appendChild(pPathProperty, NULL)) &&
            SUCCEEDED(hr = pRootProperty->appendChild(pProfProperty, NULL)))
        {
            hr = AppendToElement(CComBSTR(PRINTTICKET_NAME), pRootProperty);
        }
    }

    ERR_ON_HR(hr);
    return hr;
}


