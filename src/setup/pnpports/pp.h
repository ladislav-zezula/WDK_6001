#ifndef PP_H
#define PP_H

#define SERIAL_ADVANCED_SETTINGS
#include "msports.h"

#ifdef USE_P_TRACE_ERR
#define P_TRACE_ERR(_x) MessageBox( GetFocus(), TEXT(_x), TEXT("ports traceerr"), MB_OK | MB_ICONINFORMATION );
#define W_TRACE_ERR(_x) MessageBox( GetFocus(), _x, TEXT("ports traceerr"), MB_OK | MB_ICONINFORMATION );
#else
#define P_TRACE_ERR(_x)
#define W_TRACE_ERR(_x)
#endif

#define DO_COM_PORT_RENAMES

#define RX_MIN 1
#define RX_MAX 14
#define TX_MIN 1
#define TX_MAX 16

TCHAR m_szDevMgrHelp[];

//
// Structures
//
typedef struct
{
   DWORD BaudRate;       // actual baud rate
   DWORD Parity;         // index into dlg selection
   DWORD DataBits;       // index into dlg selection
   DWORD StopBits;       // index into dlg selection
   DWORD FlowControl;    // index into dlg selection
   TCHAR szComName[20];  // example: "COM5"  (no colon)
} PP_PORTSETTINGS, *PPP_PORTSETTINGS;

typedef struct _ADVANCED_DATA
{
    BOOL   HidePolling;
    BOOL   UseFifoBuffersControl;
    BOOL   UseFifoBuffers;
    BOOL   UseRxFIFOControl;
    BOOL   UseTxFIFOControl;
    DWORD  FifoRxMax;
    DWORD  FifoTxMax;
    DWORD  RxFIFO;
    DWORD  TxFIFO;
    DWORD  PollingPeriod;

    TCHAR  szComName[20];
    TCHAR  szNewComName[20];

    HKEY             hDeviceKey;         // (like ROOT\LEGACY_BEEP\0000)
    HCOMDB           hComDB;

    HDEVINFO         DeviceInfoSet;
    PSP_DEVINFO_DATA DeviceInfoData;

} ADVANCED_DATA, *PADVANCED_DATA;

typedef struct _PORT_PARAMS
{
   PP_PORTSETTINGS              PortSettings;
   HDEVINFO                     DeviceInfoSet;
   PSP_DEVINFO_DATA             DeviceInfoData;
   BOOL                         ShowAdvanced;
   BOOL                         AdvancedChanged;
   BOOL                         ChangesEnabled;
   PADVANCED_DATA               pAdvancedData;
} PORT_PARAMS, *PPORT_PARAMS;


///////////////////////////////////////////////////////////////////////////////////
// Port Settings Property Page Prototypes
///////////////////////////////////////////////////////////////////////////////////

HPROPSHEETPAGE
InitSettingsPage(
    PROPSHEETPAGE *      Psp,
    OUT PPORT_PARAMS    Params
    );

UINT CALLBACK
PortSettingsDlgCallback(
    HWND hwnd,
    UINT uMsg,
    LPPROPSHEETPAGE ppsp
    );

INT_PTR APIENTRY
PortSettingsDlgProc(
    IN HWND   hDlg,
    IN UINT   uMessage,
    IN WPARAM wParam,
    IN LPARAM lParam
    );

void
SavePortSettings(
    IN HWND             DialogHwnd,
    IN LPCTSTR           ComName,
    IN PPORT_PARAMS     Params
    );

void
GetPortSettings(
    IN HWND             DialogHwnd,
    IN LPCTSTR           ComName,
    IN PPORT_PARAMS     Params
    );

VOID
SetCBFromRes(
    HWND  HwndCB, 
    DWORD ResId, 
    DWORD Default,
    BOOL  CheckDecimal);

BOOL
FillCommDlg(
    IN HWND DialogHwnd
    );

ULONG
FillPortSettingsDlg(
    IN HWND             DialogHwnd,
    IN PPORT_PARAMS     Params
    );

ULONG
SavePortSettingsDlg(
    IN HWND             DialogHwnd,
    IN PPORT_PARAMS     Params
    );

ULONG
FillPortNameCb(
    HWND           ParentHwnd,
    PADVANCED_DATA Params
    );

///////////////////////////////////////////////////////////////////////////////////
// Advanced Dialog Prototypes
///////////////////////////////////////////////////////////////////////////////////
INT_PTR APIENTRY
AdvancedPortsDlgProc(
    IN HWND   hDlg,
    IN UINT   uMessage,
    IN WPARAM wParam,
    IN LPARAM lParam
    );

ULONG
FillAdvancedDlg(
    IN HWND             DialogHwnd,
    IN PADVANCED_DATA   AdvancedData
    );

ULONG
SaveAdvancedDlg(
    IN HWND             DialogHwnd,
    IN PPORT_PARAMS     Params
);

BOOL
DisplayAdvancedDialog(
    IN     HWND             DialogHwnd,
    IN OUT PADVANCED_DATA   AdvancedData
);

void
InitializeControls(
    IN HWND             DialogHwnd,
    IN PADVANCED_DATA   AdvancedData
    );

void
RestoreAdvancedDefaultState(
    IN HWND             DialogHwnd,
    IN PADVANCED_DATA   AdvancedData
    );

ULONG
SaveAdvancedSettings(
    IN HWND             DialogHwnd,
    IN PADVANCED_DATA   AdvancedData
    );

void
RestorePortSettings(
    HWND                DialogHwnd,
    PPORT_PARAMS        Params
);

void
SetTrackbarTicks(
    IN HWND   TrackbarHwnd,
    IN DWORD  MinVal,
    IN DWORD  MaxVal
    );

void
SetLabelText(
    IN HWND  LabelHwnd, 
    IN DWORD ResId,
    IN ULONG Value
    );

void
HandleTrackbarChange(
    IN HWND DialogHwnd, 
    IN HWND TrackbarHwnd
    );

void
EnableFifoControls(
    HWND DialogHwnd,
    BOOL Enabled
    );

// Context help header file and arrays for devmgr ports tab


#endif // PP_H

