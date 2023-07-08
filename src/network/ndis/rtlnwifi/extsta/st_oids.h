/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:
    st_oids.h

Abstract:
    STA layer OID handling functions
    
Revision History:
      When        What
    ----------    ----------------------------------------------
    08-01-2005    Created
    01-15-2006    Renamed sta_oids.h to st_oids.h
    
Notes:

--*/
#ifndef _STATION_OIDS_H_
#define _STATION_OIDS_H_

typedef NDIS_STATUS (*STA_QUERY_ALGO_PAIR_FUNC)(
    IN  PSTATION                        pStation,
    OUT PDOT11_AUTH_CIPHER_PAIR_LIST    pAuthCipherList,
    IN  ULONG                           TotalLength
    );

NDIS_STATUS
StaSetPowerSavingLevel(
    IN   PSTATION pStation,
    IN   ULONG PowerSavingLevel
    );

#endif // _STATION_OIDS_H_

