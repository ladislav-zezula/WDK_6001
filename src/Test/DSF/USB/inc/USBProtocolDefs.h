/*++

Copyright (c) 2005  Microsoft Corporation

Module Name:

    USBProtocolDefs.h

Abstract:

    USB protocol definitions

Author:
@@BEGIN_DDKSPLIT
    Stuart Harper January 2005
@@END_DDKSPLIT

--*/
#ifndef _USBPROTOCOLDEFS_H_
#define _USBPROTOCOLDEFS_H_

#include <PSHPACK1.h>


// Initial address for an unconnected wired device.
#define USB_UnConnected_Device_Address 0

#define USB_UNCONNECTED_ADDRESS(address) ( USB_UnConnected_Device_Address == (address))

#define USB_CONNECTED_ADDRESS(address) ( USB_UnConnected_Device_Address != (address) )

//PID definition taken from
//USB Spec 2.0 chapter 8.3.1

// Token
#define PID_OUT                             1
#define PID_IN                              9
#define PID_SOF                             5
#define PID_SETUP                           13

// Data
#define PID_DATA0                           3
#define PID_DATA1                           11
#define PID_DATA2                           7
#define PID_MDATA                           15

// Handshake
#define USB_ACK                             2
#define USB_NAK                             10
#define USB_STALL                           14
#define USB_NYET                            6

// Special
#define USB_PRE                             12
#define USB_ERR                             12
#define USB_SPLIT                           8
#define USB_PING                            4

/////////////////////////////////////////////////////////////////////
// Spec release
#define USB_SPEC                            0x0200
#define HID_SPEC                            0x0101


/////////////////////////////////////////////////////////////////////
// USB Device specification
#define USB_20_SPEC                        0x0200
#define USB_11_SPEC                        0x0110
#define USB_10_SPEC                        0x0100

/////////////////////////////////////////////////////////////////////
// Default values:
// Device Descriptor
#define HID_MAX_PACKET_SIZE0                0x08
#define MICROSOFT_VENDOR_ID                 0x045E
#define HID_DEVICE_RELEASE                  0x0100
// Endpoint Descriptor
#define HID_MAX_PACKET_SIZE                 0x0008
#define HID_POLLING_INTERVAL                0x0A
#define MAX_POLLING_INTERVAL                0xFF

// Product IDs
#define USB_DEFAULT_KEYBOARD_PRODUCT_ID     0x000B // Microsoft USB Natural Keyboard from keyboard.inf
#define USB_DEFAULT_MOUSE_PRODUCT_ID        0x0040 // Microsoft USB Wheel Mouse Optical from msmouse.inf

/////////////////////////////////////////////////////////////////////
// Descriptor type Table 9.5 usb2.0 spec
#define DEVICE_DESCRIPTOR                   0x01
#define CONFIGURATION_DESCRIPTOR            0x02
#define STRING_DESCRIPTOR                   0x03
#define INTERFACE_DESCRIPTOR                0x04
#define ENDPOINT_DESCRIPTOR                 0x05
#define QUALIFIER_DESCRIPTOR                0x06
#define OTHER_SPEED_DESCRIPTOR              0x07
#define INTERFACE_POWER_DESCRIPTOR          0x08
// Class-specific descriptor types
#define HID_DESCRIPTOR                      0x21
#define REPORT_DESCRIPTOR                   0x22
#define PHYSICAL_DESCRIPTOR                 0x23
#define HUB_DESCRIPTOR                      0x29

// USBDESCRIPTORTYPE defines the high byte of wValue for a
// GET_DESCRIPTOR request

typedef union _USBDESCRIPTORTYPE
{
    BYTE Byte;

#if !defined(MIDL_PASS)
    struct Bits
    {
        BYTE      Descriptor:5;    // bits 0-4 descriptor type as qualified by the Type field
        BYTE      Type:2;          // bits 5-6 
        BYTE      Reserved:1;      // bit 7
    } Bits;
#endif
} USBDESCRIPTORTYPE;

// These are the possible values for USBDESCRIPTORTYPE.Bits.Type
#define USB_DESCRIPTOR_TYPE_STD             0
#define USB_DESCRIPTOR_TYPE_CLASS           1
#define USB_DESCRIPTOR_TYPE_VENDOR          2
#define USB_DESCRIPTOR_TYPE_RESERVED        3




/////////////////////////////////////////////////////////////////////
// REQUEST TYPES
// Taken from USB 2.0 spec. Table 9-2

// Data transfer direction. D7
#define DIR_HOST_TO_DEVICE                  0
#define DIR_DEVICE_TO_HOST                  1

// Type. D6..5
#define TYPE_STANDARD                       0
#define TYPE_CLASS                          1
#define TYPE_VENDOR                         2
#define TYPE_RESERVED                       3

// Recipient D4..0
#define RCPT_DEVICE                         0
#define RCPT_INTERFACE                      1
#define RCPT_ENDPOINT                       2
#define RCPT_OTHER                          3

#if !defined(MIDL_PASS)
#define USB_MAKE_REQUEST_TYPE(direction, type, recipient) (BYTE)( ((BYTE)direction << 7) | ((BYTE)type << 5) | ((BYTE)recipient & 0x03) )
#endif

/////////////////////////////////////////////////////////////////////
// STANDARD REQUESTS
#define GET_STATUS                          0
#define CLEAR_FEATURE                       1
#define SET_FEATURE                         3
#define SET_ADDRESS                         5
#define GET_DESCRIPTOR                      6
#define SET_DESCRIPTOR                      7
#define GET_CONFIGURATION                   8
#define SET_CONFIGURATION                   9
#define GET_INTERFACE                       10
#define SET_INTERFACE                       11
#define SYNCH_FRAME                         12

/////////////////////////////////////////////////////////////////////
// BULK-ONLY MASS STORAGE CLASS REQUESTS
#define USB_BULK_ONLY_MASS_STG_RESET        0xFF
#define USB_BULK_ONLY_MASS_STG_GET_MAX_LUN  0xFE


/////////////////////////////////////////////////////////////////////
// HID CLASS REQUESTS
#define GET_REPORT                          0x01
#define GET_IDLE                            0x02
#define GET_PROTOCOL                        0x03
#define SET_REPORT                          0x09
#define SET_IDLE                            0x0A
#define SET_PROTOCOL                        0x0B

/////////////////////////////////////////////////////////////////////
// HID REPORT TYPES
#define HID_REPORT_TYPE_INPUT               0x01
#define HID_REPORT_TYPE_OUTPUT              0x02
#define HID_REPORT_TYPE_FEATURE             0x03

/////////////////////////////////////////////////////////////////////
// HID protocol types for GET/SET_PROTOCOL requests
#define HID_PROTOCOL_TYPE_BOOT               0x00
#define HID_PROTOCOL_TYPE_REPORT             0x01

///////////////////////////////////////////////////////////////////
// HUB protocol definitions
#define HUB_DEVICE_PROTOCOL_1X                0
#define HUB_DEVICE_PROTOCOL_SINGLE_TT         1
#define HUB_DEVICE_PROTOCOL_MULTI_TT          2

#define HUB_INTERFACE_PROTOCOL_1X                           0
#define HUB_INTERFACE_PROTOCOL_SINGLE_TT                    0
#define HUB_INTERFACE_PROTOCOL_MULTI_TT_IN_SINGLE_TT_MODE   1
#define HUB_INTERFACE_PROTOCOL_MULTI_TT_IN_MULTI_TT_MODE    2

///////////////////////////////////////////////////////////////////
//HUB Class Request code
#define CLEAR_TT_BUFFER                      8
#define RESET_TT                             9
#define GET_TT_STATE                         10
#define STOP_TT                              11

///////////////////////////////////////////////////////////////////
//HUB And PORT Feature selector
#define C_HUB_LOCAL_POWER                    0
#define C_HUB_OVER_CURRENT                   1
#define PORT_CONNECTION                      0
#define PORT_ENABLE                          1
#define PORT_SUSPEND                         2
#define PORT_OVER_CURRENT                    3
#define PORT_RESET                           4
#define PORT_POWER                           8
#define PORT_LOW_SPEED                       9
#define C_PORT_CONNECTION                    16
#define C_PORT_ENABLE                        17
#define C_PORT_SUSPEND                       18
#define C_PORT_OVER_CURRENT                  19
#define C_PORT_RESET                         20
#define PORT_TEST                            21
#define PORT_INDICATOR                       22


/////////////////////////////////////////////////////////////////////
// SETUP Constants
#define USBSETUPSIZE                        8
#define USBINREQUEST                        128

/////////////////////////////////////////////////////////////////////
// BM_REQUESTES
#define BM_GET_DEVICE                       128
#define BM_GET_INTERFACE                    129
#define BM_GET_ENDPOINT                     130

#define BM_SET_DEVICE                       0
#define BM_SET_INTERFACE                    1
#define BM_SET_ENDPOINT                     2


#define HALT_ENDPOINT                       0
#define REMOTE_WAKEUP                       1
#define TEST_MODE                           2

/////////////////////////////////////////////////////////////////////
// Descriptor requests
#define DEVICE_DESCRIPTION_TYPE             0x100     
#define QUALIFIER_DESCRIPTION_TYPE          0x600
#define OTHER_SPEED_DESCRIPTION_TYPE        0x700
#define CONFIG_DESCRIPTION_TYPE             0x200
#define STRING_DESCRIPTION_TYPE             0x300


/////////////////////////////////////////////////////////////////////
// Configuration Descriptor values
// bmAttribute bits in Configuration Descriptor
//  - USB 2.0 9.6.3 (bmAttributes in Table 9-10): Bit 7 is reserved, and always set to one
#define CONFIG_BUS_POWERED                  0x80
#define CONFIG_SELF_POWERED                 0x40
// Not to be confused with Device Remote Wakeup feature selector!
#define CONFIG_REMOTE_WAKEUP                0x20


typedef union _USBCONFIGATTRIBS
{
    BYTE Byte;

#if !defined(MIDL_PASS)

    struct Bits
    {
        BYTE bReserved0_4:5;   // bits 0-4
        BYTE bRemoteWakeup:1;  // bit 5
        BYTE bSelfPowered:1;   // bit 6
        BYTE bReserved7:1;     // bit 7
    } Bits;

#endif

} USBCONFIGATTRIBS;


/////////////////////////////////////////////////////////////////////
// Interface Descriptor values
// bInterfaceClass values
#define USB_HID_CLASS_CODE                  0x03
#define USB_MASS_STORAGE_CLASS_CODE         0x08
#define USB_HUB_CLASS_CODE                  0x09

// bInterfaceSubClass value
#define BOOT_INTERFACE_SUBCLASS             0x01

// bInterfaceProtocol values for HID
#define PROTOCOL_NONE                       0x00
#define PROTOCOL_KEYBOARD                   0x01
#define PROTOCOL_MOUSE                      0x02

/////////////////////////////////////////////////////////////////////
// Endpoint Descriptor values
// Macros for generating bEndpointAddress value
// - USB HID 1.11 Appendix E.5
#define EP_OUT                              0
#define EP_IN                               1
// Bit 0..3     The end point number
// Bit 4..6     Reserved, reset to zero
// Bit 7        Direction, ignored for control endpoints
#define MAKE_ENDPOINT_ADDRESS(num, dir)     ( ((BYTE)(dir) << 7) | ((BYTE)(num) & 0x0F) )

// bmAttributes values
// ENDPOINT TYPES
#define ENDPOINT_TYPE                       0x03
#define CONTROL_ENDPOINT                    0
#define ISOCHRONOUS_ENDPOINT                1
#define BULK_ENDPOINT                       2
#define INTERRUPT_ENDPOINT                  3



//Define standard USB structures which are used to transfer data from the
//host to the endpoints

typedef union _USBREQUESTTYPE
{
    BYTE Byte;

#if !defined(MIDL_PASS)
    struct Bits
    {
        BYTE      Recipient:5;      // bits 0-4
        BYTE      Type:2;           // bits 5-6
        BYTE      Direction:1;      // bit 7
    } Bits;
#endif
} USBREQUESTTYPE;


#if !defined(MIDL_PASS)
C_ASSERT((sizeof(USBREQUESTTYPE) == sizeof(BYTE)));
#endif

typedef struct _USBSETUPREQUEST
{
    USBREQUESTTYPE  bmRequestType;  // Setup request type
    BYTE            bRequest;       // Setup Request
    SHORT           sSetupValue;    // Value for the setup request
    SHORT           sSetupIndex;    // Index for the setup request
    SHORT           sSetupLength;   // Data Length for the device
} USBSETUPREQUEST;


#if !defined(MIDL_PASS)

typedef struct _USBDEVICEDESC
{
    BYTE   bLength; 
    BYTE   bDescriptorType;
    SHORT  sUSB;
    BYTE   bDeviceClass; 
    BYTE   bDeviceSubClass;
    BYTE   bProtocol;
    BYTE   bMaxPacket0;
    SHORT  sVendor; 
    USHORT sProduct; 
    SHORT  sDeviceNumber; 
    BYTE   bManufacturer; 
    BYTE   bProductDesc;  
    BYTE   bSerialNumber; 
    BYTE   bNumConfigs;

} USBDEVICEDESC;


typedef struct _USBCONFIGDESC
{
    BYTE      bLength;
    BYTE      bDescriptorType; 
    SHORT     sTotalLength; 
    BYTE      bNumInterfaces;
    BYTE      bConfigValue; 
    BYTE      bConfig; 
    BYTE      bAttributes; 
    BYTE      bMaxPower; 
} USBCONFIGDESC;


typedef struct _USBINTERFACEDESC
{
    BYTE      bLength; 
    BYTE      bDescriptorType; 
    BYTE      bInterfaceNumber;
    BYTE      bAlternateSetting;
    BYTE      bNumEndpoints;
    BYTE      bClass;
    BYTE      bSubClass;
    BYTE      bProtocol;
    BYTE      bDescription; 
} USBINTERFACEDESC;


#define USB_ENDPOINT_DIRECTION_OUT  0
#define USB_ENDPOINT_DIRECTION_IN   1


typedef union _USBENDPOINTADDRESS
{
    BYTE Byte;

    struct Bits
    {
        BYTE      Number:4;     // bits 0-3
        BYTE      Reserved:3;   // bits 4-6
        BYTE      Direction:1;  // bit 7
    } Bits;

} USBENDPOINTADDRESS;


C_ASSERT((sizeof(USBENDPOINTADDRESS) == sizeof(BYTE)));


#define USB_TRANSFER_TYPE_CONTROL       0
#define USB_TRANSFER_TYPE_ISOCH         1
#define USB_TRANSFER_TYPE_BULK          2
#define USB_TRANSFER_TYPE_INTERRUPT     3

#define USB_SYNC_TYPE_NONE              0
#define USB_SYNC_TYPE_ASYNC             1
#define USB_SYNC_TYPE_ADAPTIVE          2
#define USB_SYNC_TYPE_SYNC              3

#define USB_USAGE_TYPE_DATA             0
#define USB_USAGE_TYPE_FEEDBACK         1
#define USB_USAGE_TYPE_IMPLICIT         2
#define USB_USAGE_TYPE_RESERVED         3

typedef union _USBENDPOINTATTRIBS
{
    BYTE Byte;

    struct Bits
    {
        BYTE      TransferType:2;   // bits 0-1
        BYTE      SyncType:2;       // bits 3-4
        BYTE      UsageType:2;      // bits 5-6
        BYTE      Reserved:2;       // bits 7-8
    } Bits;

} USBENDPOINTATTRIBS;

C_ASSERT((sizeof(USBENDPOINTATTRIBS) == sizeof(BYTE)));


typedef union _USBMAXPACKET
{
    WORD Word;

    struct Bits
    {
        WORD      Size:11;              // bits 0-10
        WORD      AdditionalXactions:2; // bits 11-12
        WORD      Reserved:3;           // bits 13-15
    } Bits;

} USBMAXPACKET;

C_ASSERT((sizeof(USBMAXPACKET) == sizeof(WORD)));


typedef struct _USBENDPOINTDESC
{
    BYTE                bLength; 
    BYTE                bDescriptorType;
    USBENDPOINTADDRESS  Address;
    USBENDPOINTATTRIBS  Attributes;
    USBMAXPACKET        MaxPacket;
    BYTE                bInterval;
} USBENDPOINTDESC;


typedef struct _USBQUALIFIERDESC
{
    BYTE     bLength; 
    BYTE     bDescriptorType;
    SHORT    sUSB;
    BYTE     bDeviceClass; 
    BYTE     bDeviceSubClass;
    BYTE     bProtocol; 
    BYTE     bMaxPacket;
    BYTE     bNumConfigs;
    BYTE     bReserved;
} USBQUALIFIERDESC;


typedef struct _USBSTRINGDESC
{
    BYTE     bLength;
    BYTE     bDescriptorType;
    WCHAR    wchData[1];
} USBSTRINGDESC;


typedef struct _USBSTRINGLANGIDS
{
    BYTE     bLength;
    BYTE     bDescriptorType;
    WORD     wLANGIDs[1];
} USBSTRINGLANGIDS;


typedef struct _USBHIDSTANDARDDESC
{
    BYTE  bLength;
    BYTE  bDescriptorType;
    SHORT bcdHID;
    BYTE  bCountryCode;
    BYTE  bNumDescriptors;
} USBHIDSTANDARDDESC;


typedef struct _USBHIDOPTIONALDESC
{
    BYTE  bClassDescriptorType;
    SHORT sDescriptorLength;
} USBHIDOPTIONALDESC;


typedef struct _USBPHYSICALDESCSET0
{
    BYTE bNumber;
    BYTE bLength;
} USBPHYSICALDESCSET0;


typedef union _USBPHYSICALDESCSET
{
    BYTE bPhysicalInfo;

    struct Bits
    {
        BYTE bPreference : 5;
        BYTE bBias       : 3;
    } Bits;
} USBPHYSICALDESCSET;


typedef struct _USBPHYSICALDESCITEM
{
    BYTE bDesignator;

    union Flags
    {
        BYTE bFlags;

        struct Bits
        {
            BYTE bEffort    : 5;
            BYTE bQualifier : 3;
        } Bits;

    } Flags;

} USBPHYSICALDESCITEM;


typedef union _USBHUBCHARACTERISTICS
{
    WORD wHubCharacteristics;

    struct Bits
    {
        BYTE bLogicalPowerSwitchingMode : 2;
        BYTE fCompoundDevice            : 1;
        BYTE bOverCurrentMode           : 2;
        BYTE bTTThinkTime               : 2;
        BYTE fPortIndicatorSupport      : 1;
        BYTE bReserved                  : 8;
    } Bits;

} USBHUBCHARACTERISTICS;

#if !defined(MIDL_PASS)
C_ASSERT((sizeof(USBHUBCHARACTERISTICS) == sizeof(WORD)));
#endif


typedef struct _USBHUBDESC
{
    BYTE                  bLength;
    BYTE                  bDescriptorType;
    BYTE                  bNumberOfPorts;
    USBHUBCHARACTERISTICS Characteristics;
    BYTE                  bPwrOn2PwrGood;
    BYTE                  bHubContrCurrent;
    BYTE                  bDeviceRemovable[32]; // Defined as its maximum possible size for 255 ports
    BYTE                  bPortPwrCtrlMask[32]; // Defined as its maximum possible size for 255 ports
} USBHUBDESC;

#if !defined(MIDL_PASS)
C_ASSERT((sizeof(USBHUBDESC) == 71));
#endif


typedef union _USBHUBPORTSTATUS
{
    WORD wPortStatus;

    struct Bits
    {
        BYTE  fCurrentConnectionStatus : 1;
        BYTE  fEnabled                 : 1;
        BYTE  fSuspend                 : 1;
        BYTE  fOverCurrent             : 1;
        BYTE  fReset                   : 1;
        BYTE  bReserved1               : 3;
        BYTE  fPortPower               : 1;
        BYTE  fLowSpeedDevice          : 1;
        BYTE  fHighSpeedDevice         : 1;
        BYTE  fTestMode                : 1;
        BYTE  fPortIndicatorControl    : 1;
        BYTE  bReserved2               : 3;
    } Bits;
} USBHUBPORTSTATUS;

#if !defined(MIDL_PASS)
C_ASSERT((sizeof(USBHUBPORTSTATUS) == sizeof(WORD)));
#endif


typedef union _USBHUBPORTSTATUSCHANGE
{
    WORD wPortStatusChange;

    struct Bits
    {
        BYTE  fConnectionStatusChange : 1;
        BYTE  fEnabledChange          : 1;
        BYTE  fSuspendChange          : 1;
        BYTE  fOverCurrentChange      : 1;
        BYTE  fResetChange            : 1;
        BYTE  bReserved1              : 3;
        BYTE  bReserved2              : 8;
    } Bits;
} USBHUBPORTSTATUSCHANGE;
       
#if !defined(MIDL_PASS)
C_ASSERT((sizeof(USBHUBPORTSTATUSCHANGE) == sizeof(WORD)));
#endif


typedef struct _USBHUBPORTDATA
{
    USBHUBPORTSTATUS        PortStatus;
    USBHUBPORTSTATUSCHANGE  PortStatusChange;
} USBHUBPORTDATA;
            
            
// USB Language Identifiers
//
// These are taken directly from http://www.usb.org/developers/docs/USB_LANGIDs.pdf

// USB_MAKE_LANGID(lang, sublang)
//
// Use this macro to create a language ID. For example, for US English
// use:
//
// USB_MAKE_LANGID(USB_LANG_ENGLISH, USB_SUBLANG_ENGLISH_US)

#define USB_MAKE_LANGID(lang, sublang) ((((USHORT)(sublang)) << 10) | (USHORT)(lang))


#define USB_LANG_RESERVED                                   0x00 
#define USB_LANG_ARABIC                                     0x01
#define USB_LANG_BULGARIAN                                  0x02
#define USB_LANG_CATALAN                                    0x03
#define USB_LANG_CHINESE                                    0x04
#define USB_LANG_CZECH                                      0x05
#define USB_LANG_DANISH                                     0x06
#define USB_LANG_GERMAN                                     0x07
#define USB_LANG_GREEK                                      0x08
#define USB_LANG_ENGLISH                                    0x09
#define USB_LANG_SPANISH                                    0x0a
#define USB_LANG_FINNISH                                    0x0b
#define USB_LANG_FRENCH                                     0x0c
#define USB_LANG_HEBREW                                     0x0d
#define USB_LANG_HUNGARIAN                                  0x0e
#define USB_LANG_ICELANDIC                                  0x0f
#define USB_LANG_ITALIAN                                    0x10
#define USB_LANG_JAPANESE                                   0x11
#define USB_LANG_KOREAN                                     0x12
#define USB_LANG_DUTCH                                      0x13
#define USB_LANG_NORWEGIAN                                  0x14
#define USB_LANG_POLISH                                     0x15
#define USB_LANG_PORTUGUESE                                 0x16
#define USB_LANG_ROMANIAN                                   0x18
#define USB_LANG_RUSSIAN                                    0x19
#define USB_LANG_CROATIAN                                   0x1a
#define USB_LANG_SERBIAN                                    0x1a
#define USB_LANG_SLOVAK                                     0x1b
#define USB_LANG_ALBANIAN                                   0x1c
#define USB_LANG_SWEDISH                                    0x1d
#define USB_LANG_THAI                                       0x1e
#define USB_LANG_TURKISH                                    0x1f
#define USB_LANG_URDU                                       0x20
#define USB_LANG_INDONESIAN                                 0x21
#define USB_LANG_UKRANIAN                                   0x22
#define USB_LANG_BELARUSIAN                                 0x23
#define USB_LANG_SLOVENIAN                                  0x24
#define USB_LANG_ESTONIAN                                   0x25
#define USB_LANG_LATVIAN                                    0x26
#define USB_LANG_LITHUANIAN                                 0x27
#define USB_LANG_FARSI                                      0x29
#define USB_LANG_VIETNAMESE                                 0x2a
#define USB_LANG_ARMENIAN                                   0x2b
#define USB_LANG_AZERI                                      0x2c
#define USB_LANG_BASQUE                                     0x2d
#define USB_LANG_MACEDONIAN                                 0x2f // This is actually Macedonian (FYROM)
#define USB_LANG_AFRIKAANS                                  0x36
#define USB_LANG_GEORGIAN                                   0x37
#define USB_LANG_FAEROESE                                   0x38
#define USB_LANG_HINDI                                      0x39
#define USB_LANG_MALAY                                      0x3e
#define USB_LANG_KAZAK                                      0x3f
#define USB_LANG_SWAHILI                                    0x41
#define USB_LANG_UZBEK                                      0x43
#define USB_LANG_TATAR                                      0x44
#define USB_LANG_BENGALI                                    0x45
#define USB_LANG_PUNJABI                                    0x46
#define USB_LANG_GUJARATI                                   0x47
#define USB_LANG_ORIYA                                      0x48
#define USB_LANG_TAMIL                                      0x49
#define USB_LANG_TELUGU                                     0x4a
#define USB_LANG_KANNADA                                    0x4b
#define USB_LANG_MALAYALAM                                  0x4c
#define USB_LANG_ASSAMESE                                   0x4d
#define USB_LANG_MARATHI                                    0x4e
#define USB_LANG_SANSKRIT                                   0x4f
#define USB_LANG_KONKANI                                    0x57
#define USB_LANG_MANIPURI                                   0x58
#define USB_LANG_SINDHI                                     0x59
#define USB_LANG_KASHMIRI                                   0x60
#define USB_LANG_NEPALI                                     0x61
#define USB_LANG_HID                                        0xff
   
#define USB_SUBLANG_ARABIC_SAUDI_ARABIA                     0x01
#define USB_SUBLANG_ARABIC_SAUDI_ARABIA                     0x01
#define USB_SUBLANG_ARABIC_IRAQ                             0x02
#define USB_SUBLANG_ARABIC_EGYPT                            0x03
#define USB_SUBLANG_ARABIC_LIBYA                            0x04
#define USB_SUBLANG_ARABIC_ALGERIA                          0x05
#define USB_SUBLANG_ARABIC_MOROCCO                          0x06
#define USB_SUBLANG_ARABIC_TUNISIA                          0x07
#define USB_SUBLANG_ARABIC_OMAN                             0x08
#define USB_SUBLANG_ARABIC_YEMEN                            0x09
#define USB_SUBLANG_ARABIC_SYRIA                            0x10
#define USB_SUBLANG_ARABIC_JORDAN                           0x11
#define USB_SUBLANG_ARABIC_LEBANON                          0x12
#define USB_SUBLANG_ARABIC_KUWAIT                           0x13
#define USB_SUBLANG_ARABIC_UAE                              0x14
#define USB_SUBLANG_ARABIC_BAHRAIN                          0x15
#define USB_SUBLANG_ARABIC_QATAR                            0x16
#define USB_SUBLANG_AZERI_CYRILLIC                          0x01
#define USB_SUBLANG_AZERI_LATIN                             0x02
#define USB_SUBLANG_CHINESE_TRADITIONAL                     0x01
#define USB_SUBLANG_CHINESE_SIMPLIFIED                      0x02
#define USB_SUBLANG_CHINESE_HONGKONG                        0x03
#define USB_SUBLANG_CHINESE_SINGAPORE                       0x04
#define USB_SUBLANG_CHINESE_MACAU                           0x05
#define USB_SUBLANG_DUTCH                                   0x01
#define USB_SUBLANG_DUTCH_BELGIAN                           0x02
#define USB_SUBLANG_ENGLISH_US                              0x01
#define USB_SUBLANG_ENGLISH_UK                              0x02
#define USB_SUBLANG_ENGLISH_AUS                             0x03
#define USB_SUBLANG_ENGLISH_CAN                             0x04
#define USB_SUBLANG_ENGLISH_NZ                              0x05
#define USB_SUBLANG_ENGLISH_EIRE                            0x06
#define USB_SUBLANG_ENGLISH_SOUTH_AFRICA                    0x07
#define USB_SUBLANG_ENGLISH_JAMAICA                         0x08
#define USB_SUBLANG_ENGLISH_CARIBBEAN                       0x09
#define USB_SUBLANG_ENGLISH_BELIZE                          0x0a
#define USB_SUBLANG_ENGLISH_TRINIDAD                        0x0b
#define USB_SUBLANG_ENGLISH_PHILIPPINES                     0x0c
#define USB_SUBLANG_ENGLISH_ZIMBABWE                        0x0d
#define USB_SUBLANG_FRENCH                                  0x01
#define USB_SUBLANG_FRENCH_BELGIAN                          0x02
#define USB_SUBLANG_FRENCH_CANADIAN                         0x03
#define USB_SUBLANG_FRENCH_SWISS                            0x04
#define USB_SUBLANG_FRENCH_LUXEMBOURG                       0x05
#define USB_SUBLANG_FRENCH_MONACO                           0x06
#define USB_SUBLANG_GERMAN                                  0x01
#define USB_SUBLANG_GERMAN_SWISS                            0x02
#define USB_SUBLANG_GERMAN_AUSTRIAN                         0x03
#define USB_SUBLANG_GERMAN_LUXEMBOURG                       0x04
#define USB_SUBLANG_GERMAN_LIECHTENSTEIN                    0x05
#define USB_SUBLANG_ITALIAN                                 0x01
#define USB_SUBLANG_ITALIAN_SWISS                           0x02
#define USB_SUBLANG_KASHMIRI_INDIA                          0x02
#define USB_SUBLANG_KOREAN                                  0x01
#define USB_SUBLANG_LITHUANIAN                              0x01
#define USB_SUBLANG_MALAY_MALAYSIA                          0x01
#define USB_SUBLANG_MALAY_BRUNEI_DARUSSALAM                 0x02
#define USB_SUBLANG_NEPALI_INDIA                            0x02
#define USB_SUBLANG_NORWEGIAN_BOKMAL                        0x01
#define USB_SUBLANG_NORWEGIAN_NYNORSK                       0x02
#define USB_SUBLANG_PORTUGUESE                              0x01
#define USB_SUBLANG_PORTUGUESE_BRAZILIAN                    0x02
#define USB_SUBLANG_SERBIAN_LATIN                           0x02
#define USB_SUBLANG_SERBIAN_CYRILLIC                        0x03
#define USB_SUBLANG_SPANISH                                 0x01
#define USB_SUBLANG_SPANISH_MEXICAN                         0x02
#define USB_SUBLANG_SPANISH_MODERN                          0x03
#define USB_SUBLANG_SPANISH_GUATEMALA                       0x04
#define USB_SUBLANG_SPANISH_COSTA_RICA                      0x05
#define USB_SUBLANG_SPANISH_PANAMA                          0x06
#define USB_SUBLANG_SPANISH_DOMINICAN_REPUBLIC              0x07
#define USB_SUBLANG_SPANISH_VENEZUELA                       0x08
#define USB_SUBLANG_SPANISH_COLOMBIA                        0x09
#define USB_SUBLANG_SPANISH_PERU                            0x0a
#define USB_SUBLANG_SPANISH_ARGENTINA                       0x0b
#define USB_SUBLANG_SPANISH_ECUADOR                         0x0c
#define USB_SUBLANG_SPANISH_CHILE                           0x0d
#define USB_SUBLANG_SPANISH_URUGUAY                         0x0e
#define USB_SUBLANG_SPANISH_PARAGUAY                        0x0f
#define USB_SUBLANG_SPANISH_BOLIVIA                         0x10
#define USB_SUBLANG_SPANISH_EL_SALVADOR                     0x11
#define USB_SUBLANG_SPANISH_HONDURAS                        0x12
#define USB_SUBLANG_SPANISH_NICARAGUA                       0x13
#define USB_SUBLANG_SPANISH_PUERTO_RICO                     0x14
#define USB_SUBLANG_SWEDISH                                 0x01
#define USB_SUBLANG_SWEDISH_FINLAND                         0x02
#define USB_SUBLANG_URDU_PAKISTAN                           0x01
#define USB_SUBLANG_URDU_INDIA                              0x02
#define USB_SUBLANG_UZBEK_LATIN                             0x01
#define USB_SUBLANG_UZBEK_CYRILLIC                          0x02
#define USB_SUBLANG_HID_USAGE_DATA_DESCRIPTOR               0x01
#define USB_SUBLANG_HID_VENDOR_DEFINED_1                    0x3c
#define USB_SUBLANG_HID_VENDOR_DEFINED_2                    0x3d
#define USB_SUBLANG_HID_VENDOR_DEFINED_3                    0x3e
#define USB_SUBLANG_HID_VENDOR_DEFINED_4                    0x3f

#endif // !defined(MIDL_PASS)



#include <POPPACK.h>



#endif //_USBPROTOCOLDEFS_H_
