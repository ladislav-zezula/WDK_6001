#ifndef _TESTWMI_H_INCLUDED

#define _TESTWMI_H_INCLUDED

#define _WIN32_DCOM

#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <windows.h>
#include <wchar.h>
#include <commctrl.h>        // For common controls, e.g. Tree
#include <objidl.h>
#include <objbase.h>
#include <ole2.h>
#include <wbemcli.h>
#define STRSAFE_NO_DEPRECAT
#include <strsafe.h>
#include <assert.h>

//
// Resource editor generated header file.
//

#include "resource.h"

//
// Default namespace.
//

#define DEFAULT_NAMESPACE      L"root\\wmi"

#define ROOT_CLASS             NULL

#define ASSERT(_Exp)           assert(_Exp)


typedef struct _PROPERTY_INFO {
   IWbemServices    *pIWbemServices;
   IWbemClassObject *pInstance;
   LPTSTR           lpszProperty;
   LPTSTR           lpszType;
   LPVARIANT        pvaValue;
}  PROPERTY_INFO, *LPPROPERTY_INFO;
  
//
// Function defined in testwmi.cpp
//

int APIENTRY WinMain (__in HINSTANCE hInst,
                      __in_opt HINSTANCE hPrevInstance, 
                      __in_opt LPSTR lpCmdLine,         
                      int nCmdShow);

INT_PTR CALLBACK MainDlgProc (HWND hwndDlg,
                              UINT uMsg,
                              WPARAM wParam,
                              LPARAM lParam);

INT_PTR CALLBACK DlgProcScalar (HWND hwndDlg,
                                UINT uMsg,
                                WPARAM wParam,
                                LPARAM lParam);

VOID ListDefaults (HWND hwndDlg);

VOID ShowProperties (HWND hwndDlg,
                     HWND hwndInstTree);

VOID EditProperty (HWND hwndDlg,
                   HWND hwndPropTree);

BOOL ModifyProperty (HWND hwndDlg);

BOOL DisplayArrayProperty (__in LPTSTR lpszProperty,
                           VARIANT *pvaValue,
                           HWND hwndDlg);

HRESULT AddToList (HWND hwndDlg,
                  VARIANT *pvaValue);

VOID ModifyArrayProperty(HWND hwndDlg,
                         LPPROPERTY_INFO pPropInfo);

VOID RefreshOnClassSelection (HWND hwndDlg);

LPTSTR GetSelectedClass (HWND hwndClassList);

LPTSTR GetSelectedItem (HWND hwndTree);

VOID InsertItem (HWND hwndTree,
                 __in LPTSTR lpszItem);

VOID PrintError (HRESULT        hr,
                 UINT           uiLine,
                 __in LPTSTR    lpszFile,
                 LPCTSTR        lpFmt,
                 ...);

//
// Functions defined in wmicode.c
//

IWbemServices *ConnectToNamespace (VOID);

VOID EnumInstances (IWbemServices *pIWbemServices,
                    __in LPTSTR   lpszClass,
                    HWND          hwndInstTree);

VOID EnumProperties (IWbemServices *pIWbemServices,
                     __in LPTSTR   lpszClass,
                     __in LPTSTR   lpszInstance,
                     HWND          hwndPropTree);

IWbemClassObject *GetInstanceReference (IWbemServices *pIWbemServices,
                                        __in LPTSTR   lpszClass,
                                        __in LPTSTR   lpszInstance);

BOOL IsInstance (IWbemClassObject *pInst,
                 __in LPTSTR lpszInstance);

BOOL GetPropertyValue (IWbemClassObject *pRef,
                       __in LPTSTR lpszProperty, 
                       VARIANT *pvaPropertyValue,
                       __deref_opt_out_opt LPTSTR *lppszPropertyType);

HRESULT UpdatePropertyValue (IWbemServices *pIWbemServices,
                             IWbemClassObject *pInstance,
                             __in LPTSTR lpszProperty,
                             LPVARIANT pvaNewValue);

BSTR StringToBstr (__in_opt LPTSTR lpSrc,
                  int nLenSrc);

LPTSTR BstrToString (BSTR lpSrc,
                    int nLenSrc);


#endif // _TESTWMI_H_INCLUDED

