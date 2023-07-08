//
//  Windows Server (Printing) Driver Development Kit Samples.
//
//
//  Copyright (c) 1990 - 2005 Microsoft Corporation.
//  All Rights Reserved.
//
//
//  This source code is intended only as a supplement to Microsoft
//  Development Tools and/or on-line documentation.  See these other
//  materials for detailed information regarding Microsoft code samples.
// 
//  THIS CODE AND INFORMATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY
//  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//  PARTICULAR PURPOSE.
//

#include "precomp.h"
#pragma hdrstop

#include "acallback.hpp"
#include "notifydata.hpp"

VOID
SendAsyncNotification(
    __in LPWSTR     pPrinterName,
    EOEMDataSchema  action
    )
{
    WCHAR pServerResponse[] = L"Server response";

    IPrintAsyncNotifyChannel *pIAsynchNotification = NULL;
    CPrintOEMAsyncNotifyCallback *pIAsynchCallback = new CPrintOEMAsyncNotifyCallback;

    RouterCreatePrintAsyncNotificationChannel(pPrinterName,
                                             const_cast<GUID*>(&SAMPLE_NOTIFICATION_UI), 
                                             kPerUser,
                                             kBiDirectional,
                                             pIAsynchCallback,
                                             &pIAsynchNotification);

    pIAsynchCallback->Release();
    
    if (pIAsynchNotification)
    {
        CPrintOEMAsyncNotifyDataObject *pClientNotification = new CPrintOEMAsyncNotifyDataObject(reinterpret_cast<BYTE*>(&action), 
                                                                                                 sizeof(EOEMDataSchema),
                                                                                                 const_cast<GUID*>(&SAMPLE_NOTIFICATION_UI));

        if (pClientNotification)
        {
            pIAsynchNotification->SendNotification(pClientNotification);

            pClientNotification->Release();
        }          
    }
}

VOID
SendAsyncUINotification(
    __in LPWSTR          pPrinterName
    )
{
    WCHAR pszMsg[] = L"<?xml version=\"1.0\" ?>" \
                     L"<asyncPrintUIRequest xmlns=\"http://schemas.microsoft.com/2003/print/asyncui/v1/request\">" \
                     L"<v1><requestOpen><balloonUI><title>AsyncUI sample</title><body>This text is a sample.</body>" \
                     L"</balloonUI></requestOpen></v1></asyncPrintUIRequest>";

    IPrintAsyncNotifyChannel *pIAsynchNotification = NULL;
    CPrintOEMAsyncNotifyCallback *pIAsynchCallback = new CPrintOEMAsyncNotifyCallback;

    RouterCreatePrintAsyncNotificationChannel(pPrinterName,
                                             const_cast<GUID*>(&MS_ASYNCNOTIFY_UI), 
                                             kPerUser,
                                             kBiDirectional,
                                             pIAsynchCallback,
                                             &pIAsynchNotification);

    pIAsynchCallback->Release();
    
    if (pIAsynchNotification)
    {
        CPrintOEMAsyncNotifyDataObject *pClientNotification = new CPrintOEMAsyncNotifyDataObject(reinterpret_cast<BYTE*>(pszMsg), 
                                                                                                 sizeof(pszMsg),
                                                                                                 const_cast<GUID*>(&MS_ASYNCNOTIFY_UI));

        if (pClientNotification)
        {
            pIAsynchNotification->SendNotification(pClientNotification);

            pClientNotification->Release();
        }          
    }
}

