#ifndef _E100_DEF_H_
#define _E100_DEF_H_

//-------------------------------------------------------------------------
// NON_TRANSMIT_CB -- Generic Non-Transmit Command Block
//-------------------------------------------------------------------------
typedef struct _NON_TRANSMIT_CB
{
    union
    {
        MULTICAST_CB_STRUC  Multicast;
        CONFIG_CB_STRUC     Config;
        IA_CB_STRUC         Setup;
        DUMP_CB_STRUC       Dump;
        FILTER_CB_STRUC     Filter;
    }   NonTxCb;

} NON_TRANSMIT_CB, *PNON_TRANSMIT_CB;

//-------------------------------------------------------------------------
// WMI header file e100_wmi.h, generated by wmimofck utility from e100.bmf
//-------------------------------------------------------------------------

//#include "e100_wmi.h"

#endif //_E100_DEF_H_
