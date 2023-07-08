#ifndef _ToasterMof_h_
#define _ToasterMof_h_

// ToasterDeviceInformation - ToasterDeviceInformation
// Toaster driver information
#define ToasterDeviceInformationGuid \
    { 0xbba21300,0x6dd3,0x11d2, { 0xb8,0x44,0x00,0xc0,0x4f,0xad,0x51,0x71 } }

#if ! (defined(MIDL_PASS))
DEFINE_GUID(ToasterDeviceInformation_GUID, \
            0xbba21300,0x6dd3,0x11d2,0xb8,0x44,0x00,0xc0,0x4f,0xad,0x51,0x71);
#endif


typedef struct _ToasterDeviceInformation
{
    // How the toaster is connected to the computer
    ULONG ConnectorType;
    #define ToasterDeviceInformation_ConnectorType_SIZE sizeof(ULONG)
    #define ToasterDeviceInformation_ConnectorType_ID 1

    // This indicates the capacity in Kilo Watts of the toaster device.
    ULONG Capacity;
    #define ToasterDeviceInformation_Capacity_SIZE sizeof(ULONG)
    #define ToasterDeviceInformation_Capacity_ID 2

    // Number of errors that occurred on this device
    ULONG ErrorCount;
    #define ToasterDeviceInformation_ErrorCount_SIZE sizeof(ULONG)
    #define ToasterDeviceInformation_ErrorCount_ID 3

    // Indicates the number of controls on the toaster device.
    ULONG Controls;
    #define ToasterDeviceInformation_Controls_SIZE sizeof(ULONG)
    #define ToasterDeviceInformation_Controls_ID 4

    // The DebugPrintLevel property indicates the debug output level of toaster device.
    ULONG DebugPrintLevel;
    #define ToasterDeviceInformation_DebugPrintLevel_SIZE sizeof(ULONG)
    #define ToasterDeviceInformation_DebugPrintLevel_ID 5

    // The Toaster Model Name.
    CHAR VariableData[1];
    #define ToasterDeviceInformation_ModelName_ID 6

} ToasterDeviceInformation, *PToasterDeviceInformation;

// ToasterNotifyDeviceArrival - ToasterNotifyDeviceArrival
// Notify Toaster Arrival
#define ToasterNotifyDeviceArrivalGuid \
    { 0x01cdaff1,0xc901,0x45b4, { 0xb3,0x59,0xb5,0x54,0x27,0x25,0xe2,0x9c } }

#if ! (defined(MIDL_PASS))
DEFINE_GUID(ToasterNotifyDeviceArrival_GUID, \
            0x01cdaff1,0xc901,0x45b4,0xb3,0x59,0xb5,0x54,0x27,0x25,0xe2,0x9c);
#endif


typedef struct _ToasterNotifyDeviceArrival
{
    // Device Model Name
    CHAR VariableData[1];
    #define ToasterNotifyDeviceArrival_ModelName_ID 1

} ToasterNotifyDeviceArrival, *PToasterNotifyDeviceArrival;

// ToasterControl - ToasterControl
// WMI method
#define ToasterControlGuid \
    { 0xcaae7d9f,0xacf7,0x4737, { 0xa4,0xe9,0x01,0xc2,0x9d,0x3f,0xe1,0x94 } }

#if ! (defined(MIDL_PASS))
DEFINE_GUID(ToasterControl_GUID, \
            0xcaae7d9f,0xacf7,0x4737,0xa4,0xe9,0x01,0xc2,0x9d,0x3f,0xe1,0x94);
#endif

//
// Method id definitions for ToasterControl
#define ToasterControl1     1
typedef struct _ToasterControl1_IN
{
    // 
    ULONG InData;
    #define ToasterControl1_IN_InData_SIZE sizeof(ULONG)
    #define ToasterControl1_IN_InData_ID 1

} ToasterControl1_IN, *PToasterControl1_IN;

#define ToasterControl1_IN_SIZE (FIELD_OFFSET(ToasterControl1_IN, InData) + ToasterControl1_IN_InData_SIZE)

typedef struct _ToasterControl1_OUT
{
    // 
    ULONG OutData;
    #define ToasterControl1_OUT_OutData_SIZE sizeof(ULONG)
    #define ToasterControl1_OUT_OutData_ID 2

} ToasterControl1_OUT, *PToasterControl1_OUT;

#define ToasterControl1_OUT_SIZE (FIELD_OFFSET(ToasterControl1_OUT, OutData) + ToasterControl1_OUT_OutData_SIZE)

#define ToasterControl2     2
typedef struct _ToasterControl2_IN
{
    // 
    ULONG InData1;
    #define ToasterControl2_IN_InData1_SIZE sizeof(ULONG)
    #define ToasterControl2_IN_InData1_ID 1

    // 
    ULONG InData2;
    #define ToasterControl2_IN_InData2_SIZE sizeof(ULONG)
    #define ToasterControl2_IN_InData2_ID 2

} ToasterControl2_IN, *PToasterControl2_IN;

#define ToasterControl2_IN_SIZE (FIELD_OFFSET(ToasterControl2_IN, InData2) + ToasterControl2_IN_InData2_SIZE)

typedef struct _ToasterControl2_OUT
{
    // 
    ULONG OutData;
    #define ToasterControl2_OUT_OutData_SIZE sizeof(ULONG)
    #define ToasterControl2_OUT_OutData_ID 3

} ToasterControl2_OUT, *PToasterControl2_OUT;

#define ToasterControl2_OUT_SIZE (FIELD_OFFSET(ToasterControl2_OUT, OutData) + ToasterControl2_OUT_OutData_SIZE)

#define ToasterControl3     3
typedef struct _ToasterControl3_IN
{
    // 
    ULONG InData1;
    #define ToasterControl3_IN_InData1_SIZE sizeof(ULONG)
    #define ToasterControl3_IN_InData1_ID 1

    // 
    ULONG InData2;
    #define ToasterControl3_IN_InData2_SIZE sizeof(ULONG)
    #define ToasterControl3_IN_InData2_ID 2

} ToasterControl3_IN, *PToasterControl3_IN;

#define ToasterControl3_IN_SIZE (FIELD_OFFSET(ToasterControl3_IN, InData2) + ToasterControl3_IN_InData2_SIZE)

typedef struct _ToasterControl3_OUT
{
    // 
    ULONG OutData1;
    #define ToasterControl3_OUT_OutData1_SIZE sizeof(ULONG)
    #define ToasterControl3_OUT_OutData1_ID 3

    // 
    ULONG OutData2;
    #define ToasterControl3_OUT_OutData2_SIZE sizeof(ULONG)
    #define ToasterControl3_OUT_OutData2_ID 4

} ToasterControl3_OUT, *PToasterControl3_OUT;

#define ToasterControl3_OUT_SIZE (FIELD_OFFSET(ToasterControl3_OUT, OutData2) + ToasterControl3_OUT_OutData2_SIZE)


typedef struct _ToasterControl
{
    // Toaster Control Property
    ULONG ControlValue;
    #define ToasterControl_ControlValue_SIZE sizeof(ULONG)
    #define ToasterControl_ControlValue_ID 1

} ToasterControl, *PToasterControl;

#define ToasterControl_SIZE (FIELD_OFFSET(ToasterControl, ControlValue) + ToasterControl_ControlValue_SIZE)

#endif
