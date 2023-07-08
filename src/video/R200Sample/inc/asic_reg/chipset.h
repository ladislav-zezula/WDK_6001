

//*********************************************************************
//
// C Header:     chipset.h
// Description:  Contains the PCI IDs of Known Chipsets
//
// Copyright (c) 1997-2002 ATI Technologies Inc. (unpublished)
//
//	 All rights reserved.
//	 The year included in the foregoing notice is the year of creation of the work.
//
//*********************************************************************
#ifndef _chipset_h
#define _chipset_h

// ChipSet and Device ID for different mother boards

//ATI chipset
#define VENDOR_ID_ATI              0x1002

//  Intel's
#define VENDOR_ID_INTEL            0x8086
#define CHIPSET_i440FX_NORTH       0x12378086     // i440FX Host Bridge (no AGP)
#define CHIPSET_i440TX_NORTH       0x71008086     // i440NX Host Bridge (no AGP)
#define CHIPSET_i440BX_NORTH       0x71908086     // i440BX/ZX Host Bridge
#define CHIPSET_i440BX_SOUTH       0x71918086     // i440BX/ZX PCI to PCI Bridge
#define CHIPSET_i440BX_NOAGP_NORTH 0x71928086     // i440BX (AGP_DIS=1) Host Bridge
#define CHIPSET_i440LX_NORTH       0x71808086     // i440LX/EX Host Bridge
#define CHIPSET_i440LX_SOUTH       0x71818086     // i440LX/EX PCI to PCI Bridge
#define CHIPSET_i440LX_NOAGP_NORTH 0x71828086     // i440LX (AGP_DIS=1) Host Bridge
#define CHIPSET_i440GX_NORTH       0x71A08086     // i440GX Host Bridge
#define CHIPSET_i440GX_SOUTH       0x71A18086     // i440GX PCI to PCI Bridge
#define CHIPSET_i440GX_NOAGP_NORTH 0x71A28086     // i440GX (AGP_DIS=1) Host Bridge
#define CHIPSET_i440NX_NORTH       0x84CA8086     // i440NX Host Bridge

#define CHIPSET_i810_NORTH         0x71208086     // i810 Host Bridge
#define CHIPSET_i810_SOUTH         0x71218086     // i810 PCI to PCI Bridge
#define CHIPSET_i810_DC100_NORTH   0x71228086     // i810-DC100 Host Bridge
#define CHIPSET_i810_DC100_SOUTH   0x71238086     // i810-DC100 PCI to PCI Bridge
#define CHIPSET_i810E_NORTH        0x71248086     // i810E Host Bridge (no AGP)
#define CHIPSET_i810E_SOUTH        0x71258086     // i810E PCI to PCI Bridge
#define CHIPSET_i815_NORTH         0x11308086     // Solano i815 Host Bridge
#define CHIPSET_i820_FULL_NORTH    0x25008086     // Camino i820 Host Bridge (Full SKU)
#define CHIPSET_i820_NORTH         0x25018086     // Camino i820 Host Bridge (UP only SKU)
#define CHIPSET_i820_RDRAM_NORTH   0x250B8086     // Camino i820 Host Bridge (RDRAM only SKU)
#define CHIPSET_i820_SOUTH         0x250F8086     // Camino i820 PCI to PCI Bridge
#define CHIPSET_i830MP_NORTH       0x35758086     // Almador i830MP Host Bridge
#define CHIPSET_i840_NORTH         0x1A218086     // i840 Host Bridge
#define CHIPSET_i840_SOUTH         0x1A238086     // i840 PCI to PCI Bridge
#define CHIPSET_i845_NORTH         0x1A308086     // Brookdale i845 Host Bridge
#define CHIPSET_i850_NORTH         0x25308086     // i850 Host Bridge
#define CHIPSET_i860_NORTH         0x25318086     // i860 Host Bridge
#define CHIPSET_ODEM_NORTH         0x33408086     // Intel ODEM Host Bridge
#define CHIPSET_PLACER_NORTH       0x25508086     // Intel FRIDAY HARBOR (8x chipset) Host Bridge (TODO: Need to change to proper name)
#define CHIPSET_GRANITEBAY_NORTH   0x255d8086     // Intel GRANITE BAY (8x chipset) Host Bridge (TODO: Need to change to proper name)
#define CHIPSET_i845GL_NORTH       0x25608086     // Intel 845GL Host Bridge
#define CHIPSET_i845GL_SOUTH       0x25618086     // Intel 845GL PCI to PCI Bridge
#define CHIPSET_E7205_NORTH        0x25528086     // Intel E7205 (8x chipset) Host Bridge

//  ALI's
#define VENDOR_ID_ALI              0x10b9
#define CHIPSET_ALI_1541           0x154110b9
#define CHIPSET_ALI_1543           0x524310b9
#define CHIPSET_ALI_1647           0x164710b9
#define CHIPSET_ALI_1649           0x164910b9
#define CHIPSET_ALI_1651           0x165110b9

//  VIA's 2x and 4x chipsets
#define VENDOR_ID_VIA              0x1106
#define CHIPSET_VIA693_NORTH       0x05971106
#define CHIPSET_VIA694_NORTH       0x06911106
#define CHIPSET_VIAKT133_NORTH     0x03051106
#define CHIPSET_VIAKT400_NORTH     0x31891106     // VIA's AGP 8x chipset.
#define CHIPSET_VIAKX133_NORTH     0x03911106
#define CHIPSET_VIA694_SOUTH       0x85981106
#define CHIPSET_VIA694_Z_NORTH     0x06051106
#define CHIPSET_VIAP4X400_NORTH    0x31681106     // VIA's AGP 8X chipset.

//  SIS's
#define VENDOR_ID_SIS              0x1039
#define CHIPSET_SIS_5600           0x56001039
#define CHIPSET_SIS_645            0x06451039
#define CHIPSET_SIS_648            0x06481039

// AMD
#define VENDOR_ID_AMD              0x1022
#define CHIPSET_AMD750_NORTH       0x70061022
#define CHIPSET_AMD750_SOUTH       0x70071022
#define CHIPSET_AMD761_NORTH       0x700E1022
#define CHIPSET_AMD761_SOUTH       0x700F1022
#define CHIPSET_AMD762_NORTH       0x700C1022
#define CHIPSET_AMD762_SOUTH       0x700D1022

// ServerWorks
#define VENDOR_ID_SERVERWORKS      0x1166

// NVidia - NForce.
#define VENDOR_ID_NVIDIA           0x10DE
#define CHIPSET_NFORCE220_NORTH    0x01A410DE



// Notation:
//   chipset[(dependence)] -- comment
//   - chipset:
//     - name of the chipset
//   - dependence:
//      - reg__field? - the value depends on the setting of 'field' in 'reg'
//      - 1             - hardwired to 1.
//      - 0             - hardwired to 0.
//      - =0            - always 0 only, if programmed
//      - none          - see comment
//


//
// Chipset non-specific offsets off AGP's CAPPTR,
// and some of their field values.
// Ref: AGP spec.
//

#define CHIPSET_NORTH__AGPSTAT                    0x00000004  // AGP Status Register
#define CHIPSET_NORTH__AGPSTAT__FW                0x00000010L // i815(0), i820(AGPCTRL__FWCE?), i840(1), i850(1), i860(1), AMD761(AGP4XDYNCOMP__FW_EN?), AMD762

#define CHIPSET_NORTH__AGPCMD                     0x00000008  // AGP Command Register
#define CHIPSET_NORTH__AGPCMD__FW_EN              0x00000010L // i815(=0), i820, i840, i850, i860, AMD761(AGP4XDYNCOMP__FW_EN?), AMD762

//
// Chipset specific offsets off AGP's CAPPTR,
// and some of their field values.
// Ref: chipset specific spec. from manufacturers.
//

// Intel's chipset
#define CHIPSET_INTEL_NORTH__AGPCTRL              0x00000010  // AGP Command Register
#define CHIPSET_i820_NORTH__AGPCTRL__FWCE         0x00000002L // Only for: i820 -- fast write capability enable

#define CHIPSET_i815_NORTH__CAPID                 0x00000088  // Product Specific Capability Identification Register
#define CHIPSET_i815_NORTH__CAPID2                0x0000008C  // Product Specific Capability Identification Register 2
#define CHIPSET_i815_NORTH__CAPID2__MOBILE_CAP    0x00000001  // Only for: i815 -- mobile capable bit

#define CHIPSET_i845_NORTH__CAPID                 0x000000E4  // Product Specific Capability Identification Register
#define CHIPSET_i845_NORTH__CAPID__MOBILE_PM_CAP  0x40000000  // Only for: i845 -- mobile power management capability bit


// AMD's chipset
#define CHIPSET_AMD761_NORTH__AGP4XDYNCOMP        0x00000014  // AGP4x Dynamic Compensation Register
#define CHIPSET_AMD761_NORTH__AGP4XDYNCOMP__FW_EN 0x00000080L

#endif


