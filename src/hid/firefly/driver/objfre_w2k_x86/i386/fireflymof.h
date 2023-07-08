#ifndef _fireflymof_h_
#define _fireflymof_h_

// FireflyDeviceInformation - FireflyDeviceInformation
// Firefly driver information
#define FireflyDeviceInformationGuid \
    { 0xab27db29,0xdb25,0x42e6, { 0xa3,0xe7,0x28,0xbd,0x46,0xbd,0xb6,0x66 } }

#if ! (defined(MIDL_PASS))
DEFINE_GUID(FireflyDeviceInformation_GUID, \
            0xab27db29,0xdb25,0x42e6,0xa3,0xe7,0x28,0xbd,0x46,0xbd,0xb6,0x66);
#endif


typedef struct _FireflyDeviceInformation
{
    // Current state of the tail light.
    BOOLEAN TailLit;
    #define FireflyDeviceInformation_TailLit_SIZE sizeof(BOOLEAN)
    #define FireflyDeviceInformation_TailLit_ID 1

} FireflyDeviceInformation, *PFireflyDeviceInformation;

#define FireflyDeviceInformation_SIZE (FIELD_OFFSET(FireflyDeviceInformation, TailLit) + FireflyDeviceInformation_TailLit_SIZE)

#endif
