#ifndef _DEVENUM_H_
#define _DEVENUM_H_

//
// Define device type for video child enumeration
//
#define HW_ID_DISPLAY_CHILD                                     0x10000000

#define HW_ID_DISPLAY_INDEX_MASK                                0x0000000F  
#define HW_ID_DRIVER_1_ID                                       0x00000010
#define HW_ID_DRIVER_ID_MASK                                    0x00000030  
#define HW_ID_DRIVER_ID_SHIFT                                            4           
#define HW_ID_DISPLAY_ACTIVE                                    0x00000080

#define HW_ID_VIDEO_ADAPTER                                     0xFFFFFFFF

#define HW_ID_NON_ACPI_DEVICE                                   0xF0000000  // For use as a mask to detect ACPI
                                                                            // devices

#define HW_ID_MULTIMEDIA_I2C_CHILD_TUNER                        0x80000003
#define HW_ID_MULTIMEDIA_I2C_CHILD_BROOKTREE_DECODER            0x80000004
#define HW_ID_MULTIMEDIA_I2C_CHILD_TVAUDIO_XBAR                 0x80000005
#define HW_ID_MULTIMEDIA_CHILD_MACROVISION_DETECT               0x80000007 
#define HW_ID_MULTIMEDIA_VIP_CHILD_RAGETHEATER_VIDEO_DECODER    0x80000008 
#define HW_ID_MULTIMEDIA_VIP_CHILD_RAGETHEATER_AUDIO_DECODER    0x80000009 

#define HW_ID_MULTIMEDIA_I2C_CHILD_PHILIPS7114_DECODER          0x8000000B
#define HW_ID_MULTIMEDIA_CHILD_VBICODEC_PARENTALCONTROL_DETECT  0x8000000C
#define HW_ID_MULTIMEDIA_CHILD_VBICODEC_TELETEXT                0x8000000D

#define EXTRACT_DISPLAY_INDEX(ulHwDeviceId)  ( ((ulHwDeviceId & HW_ID_DISPLAY_INDEX_MASK)) )
#define EXTRACT_DRIVER_ID(ulHwDeviceId)      ( ((ulHwDeviceId & HW_ID_DRIVER_ID_MASK)    >> HW_ID_DRIVER_ID_SHIFT) )

//
// Define device types enumerated by ACPI (_DOD).
//

#define HW_ID_ACPI_MONITOR                  0x00000100
#define HW_ID_ACPI_FLAT_PANEL               0x00000110
#define HW_ID_ACPI_TV                       0x00000200
#define HW_ID_ACPI_DIGITAL_FLAT_PANEL       0x00000210

#define CaseMultimediaChild                 case HW_ID_MULTIMEDIA_I2C_CHILD_TUNER:                         \
                                            case HW_ID_MULTIMEDIA_I2C_CHILD_BROOKTREE_DECODER:             \
                                            case HW_ID_MULTIMEDIA_I2C_CHILD_TVAUDIO_XBAR:                  \
                                            case HW_ID_MULTIMEDIA_CHILD_MACROVISION_DETECT:                \
                                            case HW_ID_MULTIMEDIA_VIP_CHILD_RAGETHEATER_VIDEO_DECODER:     \
                                            case HW_ID_MULTIMEDIA_VIP_CHILD_RAGETHEATER_AUDIO_DECODER:     \
                                            case HW_ID_MULTIMEDIA_I2C_CHILD_PHILIPS7114_DECODER:           \
                                            case HW_ID_MULTIMEDIA_CHILD_VBICODEC_PARENTALCONTROL_DETECT:   \
                                            case HW_ID_MULTIMEDIA_CHILD_VBICODEC_TELETEXT


#define IsItAMultiMediaChild(ulHwDeviceId)  ((HW_ID_MULTIMEDIA_I2C_CHILD_TUNER   == ulHwDeviceId) || \
                         (HW_ID_MULTIMEDIA_I2C_CHILD_BROOKTREE_DECODER           == ulHwDeviceId) || \
                         (HW_ID_MULTIMEDIA_I2C_CHILD_TVAUDIO_XBAR                == ulHwDeviceId) || \
                         (HW_ID_MULTIMEDIA_CHILD_MACROVISION_DETECT              == ulHwDeviceId) || \
                         (HW_ID_MULTIMEDIA_VIP_CHILD_RAGETHEATER_VIDEO_DECODER   == ulHwDeviceId) || \
                         (HW_ID_MULTIMEDIA_VIP_CHILD_RAGETHEATER_AUDIO_DECODER   == ulHwDeviceId) || \
                         (HW_ID_MULTIMEDIA_I2C_CHILD_PHILIPS7114_DECODER         == ulHwDeviceId) || \
                         (HW_ID_MULTIMEDIA_CHILD_VBICODEC_PARENTALCONTROL_DETECT == ulHwDeviceId) || \
                         (HW_ID_MULTIMEDIA_CHILD_VBICODEC_TELETEXT               == ulHwDeviceId))

#endif

