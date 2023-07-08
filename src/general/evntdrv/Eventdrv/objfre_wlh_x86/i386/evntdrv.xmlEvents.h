#pragma once
EXTERN_C __declspec(selectany) const GUID DriverControlGuid = {0xb5a0bda9, 0x50fe, 0x4d0e, {0xa8, 0x3d,0xba,0xe3,0xf5,0x8c,0x94,0xd6}};
#define DriverControlGuid_CHANNEL_SYSTEM 0x8
EXTERN_C __declspec(selectany) const EVENT_DESCRIPTOR StartEvent = {0x1, 0x0, 0x8, 0x4, 0x1, 0x0, 0x8000000000000000};
#define StartEvent_value 0x1
EXTERN_C __declspec(selectany) const EVENT_DESCRIPTOR SampleEventA = {0x2, 0x0, 0x8, 0x4, 0x0, 0x0, 0x8000000000000000};
#define SampleEventA_value 0x2
EXTERN_C __declspec(selectany) const EVENT_DESCRIPTOR UnloadEvent = {0x3, 0x0, 0x8, 0x4, 0x2, 0x0, 0x8000000000000000};
#define UnloadEvent_value 0x3
#define MSG_SampleEventA_EventMessage    0xB0000002L

#define MSG_StartEvent_EventMessage      0xB0000001L

#define MSG_UnloadEvent_EventMessage     0xB0000003L

