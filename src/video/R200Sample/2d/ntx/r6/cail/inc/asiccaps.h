

/*
;-------------------------------------------------------------------------------------
;  C/ASM Header:    caps.h
;
;  Copyright (c) 1999-2002 ATI Technologies Inc. (unpublished)
;
;  All rights reserved.
;  The year included in the foregoing notice is the year of creation of the work.
;
;-------------------------------------------------------------------------------------

;-------------------------------------------------------------------------------------
;  Header file containing Caps for supported Asics
;
;  The DDI_CAPS structure contains an array, Caps, with NUM_CAPS_DWORDS dwords.  Up
;  to 32*NUM_CAPS_DWORDS capabilities can be stored.
;
;  The various capabilities will be assigned values 0,1,2,... in an enum statement.
;  Bits 31-5 of the capability value give the array index, and bits 4-0 give the bit
;  position within the array entry.  For example, a capability value of 37 will
;  correspond to bit 5 in Caps[1].  The translations between capability values and
;  the bits in the Caps array will be automatic - the user does not need to know
;  anything.
;
;  Sample DDI_CAPS bit positions:
;     CapSet(0)    00000000000000000000000000000001B in Caps[0]
;     CapSet(1)    00000000000000000000000000000010B in Caps[0]
;     CapSet(37)   00000000000000000000000000100000B in Caps[1]
;
;  Sample uses of CapEnabled,CheckCap
;     In C file:  if (CapEnabled DDI_Asic_Caps.Caps,7){...}
;
;     In Asm file:  CheckCap DDI_Asic_Caps,7
;                   .if (!ZERO?)
;                     ...
;                   .endif
;-------------------------------------------------------------------------------------

;-------------------------------------------------------------------------------------
;  Revisions:
;  1.0 [jch] 99-07-27  Initial implementation
;-------------------------------------------------------------------------------------

;-------------------------------------------------------------------------------------
;  E Q U A T E S
;-------------------------------------------------------------------------------------
*/
#ifndef NUM_CAPS_DWORDS
#define NUM_CAPS_DWORDS  8
#endif
#ifndef PULONG
typedef unsigned long * PULONG;
#endif
#ifndef PUCHAR
typedef unsigned char * PUCHAR;
#endif
/*
;-------------------------------------------------------------------------------------
;  S T R U C T U R E S
;-------------------------------------------------------------------------------------
*/
typedef struct tagDDI_ASIC_INIT_INFO {
    unsigned long                           FamilyID;
    unsigned long                           AsicID;
    unsigned long                           RevNo;
    unsigned long                           EmulatedRevNo;
    PULONG                                  DDICapsList;
    PUCHAR                                  AsicName;                                                                      
} DDI_ASIC_INIT_INFO;

typedef struct tagDDI_CAPS {
    unsigned long   CapsSize;
    unsigned long   FamilyID;
    unsigned long   AsicID;
    unsigned long   RevNo;
    unsigned long   EmulatedRevNo;
    unsigned long   Caps[NUM_CAPS_DWORDS];
} DDI_CAPS, * LPDDI_CAPS;
#define SIZE_DDI_CAPS                    sizeof(DDI_CAPS)
/*
;-------------------------------------------------------------------------------------
;  M A C R O S
;
;-------------------------------------------------------------------------------------
*/
#define CapInit(c)                         ((DWORD)(1) << (c & 0x1F))
#define CapSet(addr,c)       ( addr[(c/32)] |=  ((DWORD)(1) << (c & 0x1F)) )
#define CapUnSet(addr,c)     ( addr[(c/32)] &=  ((DWORD)(-1) - ((DWORD)(1) << (c & 0x1F))) )
#define CapEnabled(addr,c)   ( addr[(c/32)] &   ((DWORD)(1) << (c & 0x1F)) )
/*
;-------------------------------------------------------------------------------------
;  C A P A B I L I T I E S - asm and c values must be the same
;
;-------------------------------------------------------------------------------------
*/
#define   DDI_CAP_NIL                       0

#define   DDI_CAP_AGP                       1
#define   DDI_CAP_DUALCRTC                  2
#define   DDI_CAP_RPTR_WRITEBACK            3
#define   DDI_CAP_AGP_WRITE_1x              4
#define   DDI_CAP_AGP_WRITE_2x              5
#define   DDI_CAP_AGP_WRITE_4x              6
#define   DDI_CAP_AGP_WRITE_8x              7
#define   DDI_CAP_USER100MICROCODE          16
#define   DDI_CAP_USERV100MICROCODE         17
#define   DDI_CAP_USER200MICROCODE          18
#define   DDI_CAP_USER300MICROCODE          19
#define   DDI_CAP_USER400MICROCODE          20


#define   DDI_CAP_DFP_HOTPLUG              32
#define   DDI_CAP_ACPI_D0                  33
#define   DDI_CAP_ACPI_D1                  34
#define   DDI_CAP_ACPI_D2                  35
#define   DDI_CAP_ACPI_D3                  36
#define   DDI_CAP_DPMS_D0                  37
#define   DDI_CAP_DPMS_D1                  38
#define   DDI_CAP_DPMS_D2                  39
#define   DDI_CAP_DPMS_D3                  40
#define   DDI_CAP_HWICON                   41
#define   DDI_CAP_MULTIFUNCTION            42
#define   DDI_CAP_AGP_WRITE                43
#define   DDI_CAP_PER_PIXEL_ALPHABLEND     44
#define   DDI_CAP_2D_INDIRECT_BUFFER       45
#define   DDI_CAP_FIREGL_BOARD             46
#define   DDI_CAP_MULTIFUNCTION_SECONDARY  47
#define   DDI_CAP_FB_APERTURE_MODE2        48
#define   DDI_CAP_EXTEND_POWER_CONNECTOR   49
#define   DDI_CAP_NO_PCI_BM                50
#define   DDI_CAP_APM_SUPPORT              51
#define   DDI_CAP_SWITCHAPMTOACPI          52
#define   DDI_CAP_SECONDARY_SCISSORS_IN_SW 53
#define   DDI_CAP_SECONDARY_NUM_UNITS_ONE  54
#define   DDI_CAP_VGA_COMPATIBLE_FIX       55
#define   DDI_CAP_ACPI_HIBERNATE           56
#define   DDI_CAP_REALTIME_STREAM          57
#define   DDI_CAP_VGA_BLUESCREEN_FIX       58
#define   DDI_CAP_EXP_SUSPEND_RESUME_FIX   59
#define   DDI_CAP_MOBILE                   60
#define   DDI_CAP_DPMS_FOR_DUALCRTC        61
#define   DDI_CAP_HOTKEY                   62
#define   DDI_CAP_SUPPORT_MACROTILING_ONLY 63

#define   DDI_CAP_REVERSE_MONO_PATTERN     67
#define   DDI_CAP_HW_BUG_POLYLINE_ROPS     70
#define   DDI_CAP_HW_BUG_NEG_TEXT_OFFSET   71
#define   DDI_CAP_PALETTE_DIB_XLATE        72
#define   DDI_CAP_INTEL850_WORKAROUND      73
#define   DDI_CAP_MEMTWOCHANNEL            78
#define   DDI_CAP_NOSTOPIOSTRAPONIKOS      79
#define   DDI_CAP_GLOBAL_PMAN_ENABLE       80
#define   DDI_CAP_TCLALWAYSBYPASS          81
#define   DDI_CAP_DISABLEDRL0WR            82
#define   DDI_CAP_CABOASIC                 83
#define   DDI_CAP_R200_MC_CNTL             85
#define   DDI_CAP_APM_AGP_HANG_WORKAROUND  86
#define   DDI_CAP_R200ASIC                 87
#define   DDI_CAP_ONE_TIME_REG_PROGRAMABLE 88
#define   DDI_CAP_HALF_MODE_FIX            89
#define   DDI_CAP_DUAL_HOTPLUG_DFP         90
#define   DDI_CAP_HAS_GEYSERVILLE_IRQ      91
#define   DDI_CAP_LCD_BLOOMING_FIX         92
#define   DDI_CAP_FAST_WRITE               93
#define   DDI_CAP_RV200PLUSRV250ASIC       94
#define   DDI_CAP_WORKAROUND_FORCEMCGUIHANG 95

#define   DDI_CAP_DISABLE_TCL_BYPASS          96
#define   DDI_CAP_ENABLE_HW_0_DEBUG           97
#define   DDI_CAP_ENABLE_MEM_VSYN             98
#define   DDI_CAP_R200_AIW                    99
#define   DDI_CAP_VIA_RBFB_WORKAROUND        102
#define   DDI_CAP_DISABLE_3D_TILING_EXP      103
#define   DDI_CAP_R300ASIC                   104
#define   DDI_CAP_RS200ASIC                  105
#define   DDI_CAP_RV250ASIC                  106
#define   DDI_CAP_ENABLE_HALF_SPEED_SCLK     107
#define   DDI_CAP_TEMP_VBIOS_TABLE3_4        108
#define   DDI_CAP_WORKAROUND_FORCEMCHOSTHANG 109
#define   DDI_CAP_NBAGP_EN                   110
#define   DDI_CAP_X_Y_MODE_EN                111
#define   DDI_CAP_PRIMARYMICROTILING_EN      112
#define   DDI_CAP_MEMFOURCHANNEL             113
#define   DDI_CAP_ONE_PRIM_PER_PASS_ENABLE   114
#define   DDI_CAP_R300A11_CGCGM_WORKAROUND   115
#define   DDI_CAP_RL_CONFIG                  116
#define   DDI_CAP_DISABLE_DYN_CLK_FOR_CP     117
#define   DDI_CAP_DISABLE_DYN_CLK_FOR_DISPREGS 118
#define   DDI_CAP_PLL_READ_ERROR             119
#define   DDI_CAP_SET_2ND_ADAPTER_PM_STATUS_TO_D0 120
#define   DDI_CAP_RV280ASIC                  121
#define   DDI_CAP_RV350ASIC                  122
#define   DDI_CAP_BRESENHAM_LINE_BUG_FIX     123
#define   DDI_CAP_OVERCLOCK_PROTECT          124
#define   DDI_CAP_UNDERCLOCK_PROTECT         125
#define   DDI_CAP_R400ASIC                   126
#define   DDI_CAP_R300_MC_CNTL               127

#define   DDI_CAP_TMDS_PLL_ACTIVE_LOW        128
#define   DDI_CAP_NON_PM4_READ_COMBINE       129
#define   DDI_CAP_R350ASIC                   130
#define   DDI_CAP_R300_DERIVATIVES           131
#define   DDI_CAP_ATOM_ARCH_BIOS             132
#define   DDI_CAP_CLEAR_CUTOFF_BEFORE_POWERDOWN 133
#define   DDI_CAP_AGP_CALIBRATION_FIX        134
#define   DDI_CAP_FB_REMAP                   135

