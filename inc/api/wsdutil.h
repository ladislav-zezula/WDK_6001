//+-------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (c) Microsoft Corporation. All rights reserved.
//
//  Component: WSDAPI - Microsoft Web Services for Devices API
// 
//  File: wsdutil.h
//
//  Abstract: WSDAPI Utilities
//
//--------------------------------------------------------------------------
#pragma once

//
// Helpful macros
//
#define WSD_DEFAULT_HOSTING_ADDRESS L"http://*:5357/"
#define WSD_DEFAULT_SECURE_HOSTING_ADDRESS L"https://*:5358/"
#define WSD_DEFAULT_EVENTING_ADDRESS L"http://*:5357/"

#ifdef __cplusplus
extern "C" {
#endif

//
// Configuration
//

// MessageSize: DWORD value between 32768 and 1048576
#define WSDAPI_OPTION_MAX_INBOUND_MESSAGE_SIZE 0x0001

HRESULT WINAPI
WSDSetConfigurationOption(
    DWORD dwOption,
    __in_bcount(cbInBuffer) LPVOID pVoid,
    DWORD cbInBuffer);

HRESULT WINAPI
WSDGetConfigurationOption(
    DWORD dwOption,
    __out_bcount(cbOutBuffer) LPVOID pVoid,
    DWORD cbOutBuffer);
    
//
// Linked memory
//

void * WINAPI 
WSDAllocateLinkedMemory(
    void* pParent, 
    size_t cbSize);

void WINAPI
WSDFreeLinkedMemory(
    void *pVoid);

void WINAPI
WSDAttachLinkedMemory(
    void* pParent,
    void* pChild);

void WINAPI
WSDDetachLinkedMemory(
    void* pVoid);

//
// XML helpers 
//

typedef struct _WSDXML_ELEMENT WSDXML_ELEMENT; 

HRESULT WINAPI
WSDXMLBuildAnyForSingleElement(
    WSDXML_NAME* pElementName, 
    __in_opt LPCWSTR pszText, 
    WSDXML_ELEMENT** ppAny);

HRESULT WINAPI
WSDXMLGetValueFromAny(
    __in LPCWSTR pszNamespace,
    __in LPCWSTR pszName, 
    WSDXML_ELEMENT* pAny, 
    LPCWSTR* ppszValue);

HRESULT WINAPI
WSDXMLAddSibling(
    WSDXML_ELEMENT* pFirst,
    WSDXML_ELEMENT* pSecond);

HRESULT WINAPI
WSDXMLAddChild(
    WSDXML_ELEMENT* pParent,
    WSDXML_ELEMENT* pChild);

HRESULT WINAPI
WSDXMLCleanupElement(
    WSDXML_ELEMENT* pAny);    

HRESULT WINAPI
WSDGenerateFault(
    __in LPCWSTR pszCode,
    __in LPCWSTR pszSubCode,
    __in LPCWSTR pszReason,
    __in LPCWSTR pszDetail,
    IWSDXMLContext* pContext,
    WSD_SOAP_FAULT** ppFault);

HRESULT WINAPI
WSDGenerateFaultEx(
    WSDXML_NAME* pCode, 
    WSDXML_NAME* pSubCode, 
    WSD_LOCALIZED_STRING_LIST* pReasons, 
    __in_opt LPCWSTR pszDetail, 
    WSD_SOAP_FAULT** ppFault);

#ifdef __cplusplus
};
#endif

