#ifndef _wmidata_h_
#define _wmidata_h_

// Vendor_EC1 - EC1
// Description of embedded class 1
#define Vendor_EC1Guid \
    { 0xa1c15015,0xb069,0x11d1, { 0x92,0x90,0x00,0xa0,0xc9,0x06,0x29,0x10 } }

#if ! (defined(MIDL_PASS))
DEFINE_GUID(Vendor_EC1_GUID, \
            0xa1c15015,0xb069,0x11d1,0x92,0x90,0x00,0xa0,0xc9,0x06,0x29,0x10);
#endif


typedef struct _EC1
{
    // boolean data
    BOOLEAN Xboolean;
    #define EC1_Xboolean_SIZE sizeof(BOOLEAN)
    #define EC1_Xboolean_ID 1

    // unsigned character data
    UCHAR Xuint8;
    #define EC1_Xuint8_SIZE sizeof(UCHAR)
    #define EC1_Xuint8_ID 2

    // unsigned short data
    USHORT Xuint16;
    #define EC1_Xuint16_SIZE sizeof(USHORT)
    #define EC1_Xuint16_ID 3

    // unsigned long data
    ULONG Xuint32;
    #define EC1_Xuint32_SIZE sizeof(ULONG)
    #define EC1_Xuint32_ID 4

    // unsigned long long data
    ULONGLONG Xuint64;
    #define EC1_Xuint64_SIZE sizeof(ULONGLONG)
    #define EC1_Xuint64_ID 5

    // signed byte data
    CHAR Xint8;
    #define EC1_Xint8_SIZE sizeof(CHAR)
    #define EC1_Xint8_ID 6

    // singed short data
    SHORT Xint16;
    #define EC1_Xint16_SIZE sizeof(SHORT)
    #define EC1_Xint16_ID 7

    // singed long data
    LONG Xint32;
    #define EC1_Xint32_SIZE sizeof(LONG)
    #define EC1_Xint32_ID 8

    // signed long long data
    LONGLONG Xint64;
    #define EC1_Xint64_SIZE sizeof(LONGLONG)
    #define EC1_Xint64_ID 9

} EC1, *PEC1;

#define EC1_SIZE (FIELD_OFFSET(EC1, Xint64) + EC1_Xint64_SIZE)

// Vendor_EC2 - EC2
// Description of embedeed class 2
#define Vendor_EC2Guid \
    { 0xa1c15016,0xb069,0x11d1, { 0x92,0x90,0x00,0xa0,0xc9,0x06,0x29,0x10 } }

#if ! (defined(MIDL_PASS))
DEFINE_GUID(Vendor_EC2_GUID, \
            0xa1c15016,0xb069,0x11d1,0x92,0x90,0x00,0xa0,0xc9,0x06,0x29,0x10);
#endif


typedef struct _EC2
{
    // Fixed length array of 8 booleans
    BOOLEAN Xboolean[8];
    #define EC2_Xboolean_SIZE sizeof(BOOLEAN[8])
    #define EC2_Xboolean_ID 1

    // Fixed length array of 8 unsigned characters
    UCHAR Xuint8[8];
    #define EC2_Xuint8_SIZE sizeof(UCHAR[8])
    #define EC2_Xuint8_ID 2

    // Fixed length array of 4 unsigned shorts
    USHORT Xuint16[4];
    #define EC2_Xuint16_SIZE sizeof(USHORT[4])
    #define EC2_Xuint16_ID 3

    // Fixed length array of 2 usingned long
    ULONG Xuint32[2];
    #define EC2_Xuint32_SIZE sizeof(ULONG[2])
    #define EC2_Xuint32_ID 4

    // Unsigned long long
    ULONGLONG Xuint64;
    #define EC2_Xuint64_SIZE sizeof(ULONGLONG)
    #define EC2_Xuint64_ID 5

    // Fixed length array of 8 signed characters
    CHAR Xint8[8];
    #define EC2_Xint8_SIZE sizeof(CHAR[8])
    #define EC2_Xint8_ID 6

    // Fixed length array of 4 signed short
    SHORT Xint16[4];
    #define EC2_Xint16_SIZE sizeof(SHORT[4])
    #define EC2_Xint16_ID 7

    // Fixed length array of 2 signed long
    LONG Xint32[2];
    #define EC2_Xint32_SIZE sizeof(LONG[2])
    #define EC2_Xint32_ID 8

    // Signed long long
    LONGLONG Xint64;
    #define EC2_Xint64_SIZE sizeof(LONGLONG)
    #define EC2_Xint64_ID 9

} EC2, *PEC2;

#define EC2_SIZE (FIELD_OFFSET(EC2, Xint64) + EC2_Xint64_SIZE)

// WmiSampleClass1 - WmiSampleClass1
// Description of sample class 1
#define WmiSampleClass1Guid \
    { 0x15d851f1,0x6539,0x11d1, { 0xa5,0x29,0x00,0xa0,0xc9,0x06,0x29,0x10 } }

#if ! (defined(MIDL_PASS))
DEFINE_GUID(WmiSampleClass1_GUID, \
            0x15d851f1,0x6539,0x11d1,0xa5,0x29,0x00,0xa0,0xc9,0x06,0x29,0x10);
#endif

//
// Method id definitions for WmiSampleClass1
#define SetEC1     1
typedef struct _SetEC1_IN
{
    // 
    BOOLEAN Xboolean;
    #define SetEC1_IN_Xboolean_SIZE sizeof(BOOLEAN)
    #define SetEC1_IN_Xboolean_ID 1

    // 
    UCHAR Xuint8;
    #define SetEC1_IN_Xuint8_SIZE sizeof(UCHAR)
    #define SetEC1_IN_Xuint8_ID 2

    // 
    USHORT Xuint16;
    #define SetEC1_IN_Xuint16_SIZE sizeof(USHORT)
    #define SetEC1_IN_Xuint16_ID 3

    // 
    ULONG Xuint32;
    #define SetEC1_IN_Xuint32_SIZE sizeof(ULONG)
    #define SetEC1_IN_Xuint32_ID 4

    // 
    ULONGLONG Xuint64;
    #define SetEC1_IN_Xuint64_SIZE sizeof(ULONGLONG)
    #define SetEC1_IN_Xuint64_ID 5

    // 
    CHAR Xint8;
    #define SetEC1_IN_Xint8_SIZE sizeof(CHAR)
    #define SetEC1_IN_Xint8_ID 6

    // 
    SHORT Xint16;
    #define SetEC1_IN_Xint16_SIZE sizeof(SHORT)
    #define SetEC1_IN_Xint16_ID 7

    // 
    LONG Xint32;
    #define SetEC1_IN_Xint32_SIZE sizeof(LONG)
    #define SetEC1_IN_Xint32_ID 8

    // 
    LONGLONG Xint64;
    #define SetEC1_IN_Xint64_SIZE sizeof(LONGLONG)
    #define SetEC1_IN_Xint64_ID 9

} SetEC1_IN, *PSetEC1_IN;

#define SetEC1_IN_SIZE (FIELD_OFFSET(SetEC1_IN, Xint64) + SetEC1_IN_Xint64_SIZE)

#define DummyMethod     2

typedef struct _WmiSampleClass1
{
    // boolean data
    BOOLEAN Xboolean;
    #define WmiSampleClass1_Xboolean_SIZE sizeof(BOOLEAN)
    #define WmiSampleClass1_Xboolean_ID 1

    // unsigned character data
    UCHAR Xuint8;
    #define WmiSampleClass1_Xuint8_SIZE sizeof(UCHAR)
    #define WmiSampleClass1_Xuint8_ID 2

    // unsigned short data
    USHORT Xuint16;
    #define WmiSampleClass1_Xuint16_SIZE sizeof(USHORT)
    #define WmiSampleClass1_Xuint16_ID 3

    // unsigned long data
    ULONG Xuint32;
    #define WmiSampleClass1_Xuint32_SIZE sizeof(ULONG)
    #define WmiSampleClass1_Xuint32_ID 4

    // unsigned long long data
    ULONGLONG Xuint64;
    #define WmiSampleClass1_Xuint64_SIZE sizeof(ULONGLONG)
    #define WmiSampleClass1_Xuint64_ID 5

    // signed byte data
    CHAR Xint8;
    #define WmiSampleClass1_Xint8_SIZE sizeof(CHAR)
    #define WmiSampleClass1_Xint8_ID 6

    // singed short data
    SHORT Xint16;
    #define WmiSampleClass1_Xint16_SIZE sizeof(SHORT)
    #define WmiSampleClass1_Xint16_ID 7

    // singed long data
    LONG Xint32;
    #define WmiSampleClass1_Xint32_SIZE sizeof(LONG)
    #define WmiSampleClass1_Xint32_ID 8

    // signed long long data
    LONGLONG Xint64;
    #define WmiSampleClass1_Xint64_SIZE sizeof(LONGLONG)
    #define WmiSampleClass1_Xint64_ID 9

} WmiSampleClass1, *PWmiSampleClass1;

#define WmiSampleClass1_SIZE (FIELD_OFFSET(WmiSampleClass1, Xint64) + WmiSampleClass1_Xint64_SIZE)

// WmiSampleClass2 - WmiSampleClass2
// Description of Sample Class 2
#define WmiSampleClass2Guid \
    { 0x15d851f2,0x6539,0x11d1, { 0xa5,0x29,0x00,0xa0,0xc9,0x06,0x29,0x10 } }

#if ! (defined(MIDL_PASS))
DEFINE_GUID(WmiSampleClass2_GUID, \
            0x15d851f2,0x6539,0x11d1,0xa5,0x29,0x00,0xa0,0xc9,0x06,0x29,0x10);
#endif


typedef struct _WmiSampleClass2
{
    // Embedded class data
    EC1 EmbeddedClass1;
    #define WmiSampleClass2_EmbeddedClass1_SIZE sizeof(EC1)
    #define WmiSampleClass2_EmbeddedClass1_ID 1

} WmiSampleClass2, *PWmiSampleClass2;

#define WmiSampleClass2_SIZE (FIELD_OFFSET(WmiSampleClass2, EmbeddedClass1) + WmiSampleClass2_EmbeddedClass1_SIZE)

// WmiSampleClass3 - WmiSampleClass3
// Description of Sample Class 3
#define WmiSampleClass3Guid \
    { 0x15d851f3,0x6539,0x11d1, { 0xa5,0x29,0x00,0xa0,0xc9,0x06,0x29,0x10 } }

#if ! (defined(MIDL_PASS))
DEFINE_GUID(WmiSampleClass3_GUID, \
            0x15d851f3,0x6539,0x11d1,0xa5,0x29,0x00,0xa0,0xc9,0x06,0x29,0x10);
#endif


typedef struct _WmiSampleClass3
{
    // Fixed length array of 4 embedded classes
    EC1 EmbeddedClass1[4];
    #define WmiSampleClass3_EmbeddedClass1_SIZE sizeof(EC1[4])
    #define WmiSampleClass3_EmbeddedClass1_ID 1

} WmiSampleClass3, *PWmiSampleClass3;

#define WmiSampleClass3_SIZE (FIELD_OFFSET(WmiSampleClass3, EmbeddedClass1) + WmiSampleClass3_EmbeddedClass1_SIZE)

// WmiSampleClass5 - WmiSampleClass5
// Description of Sample Class 5
#define WmiSampleClass5Guid \
    { 0x15d851f5,0x6539,0x11d1, { 0xa5,0x29,0x00,0xa0,0xc9,0x06,0x29,0x10 } }

#if ! (defined(MIDL_PASS))
DEFINE_GUID(WmiSampleClass5_GUID, \
            0x15d851f5,0x6539,0x11d1,0xa5,0x29,0x00,0xa0,0xc9,0x06,0x29,0x10);
#endif


typedef struct _WmiSampleClass5
{
    // Embedded class data
    EC2 EmbeddedClass2;
    #define WmiSampleClass5_EmbeddedClass2_SIZE sizeof(EC2)
    #define WmiSampleClass5_EmbeddedClass2_ID 1

} WmiSampleClass5, *PWmiSampleClass5;

#define WmiSampleClass5_SIZE (FIELD_OFFSET(WmiSampleClass5, EmbeddedClass2) + WmiSampleClass5_EmbeddedClass2_SIZE)

// WmiSampleClass6 - WmiSampleClass6
// Description of Sample Class 6
#define WmiSampleClass6Guid \
    { 0x15d851f6,0x6539,0x11d1, { 0xa5,0x29,0x00,0xa0,0xc9,0x06,0x29,0x10 } }

#if ! (defined(MIDL_PASS))
DEFINE_GUID(WmiSampleClass6_GUID, \
            0x15d851f6,0x6539,0x11d1,0xa5,0x29,0x00,0xa0,0xc9,0x06,0x29,0x10);
#endif


typedef struct _WmiSampleClass6
{
    // Fixed length array of 4 embedded classes
    EC2 EmbeddedClass2[4];
    #define WmiSampleClass6_EmbeddedClass2_SIZE sizeof(EC2[4])
    #define WmiSampleClass6_EmbeddedClass2_ID 1

} WmiSampleClass6, *PWmiSampleClass6;

#define WmiSampleClass6_SIZE (FIELD_OFFSET(WmiSampleClass6, EmbeddedClass2) + WmiSampleClass6_EmbeddedClass2_SIZE)

#endif
