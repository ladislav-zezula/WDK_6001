#pragma once

// Common data structures/functions used by the r200 driver for clone view helper


typedef enum _R200_ESCCODE
{      
     R200_GETID=1,
     R200_GETTOPOLOGY=2,   

}R200_ESCCODE;

#pragma pack(push,8)


typedef struct _R200_GetIDData
{
    ULONG * pulCount; //number of entries
    ULONG * pulID; //Array of ULONGs which receives the ID' sof sources or targets
    ULONG ulFlags; //ULONG which is set to GETID_SOURCE (1) if GetID() is used to get source identifiers or GETID_TARGET(0) if GetID() is used to get target identifiers

}R200_GetIDData, *PR200_GetIDData;

typedef struct _R200_TopologyData
{
    ULONG ulSourceID;
    ULONG * pulCount;
    ULONG * pulTargetID;
}R200_TopologyData, *PR200_TopologyData;

typedef struct _R200_SetTopologyData
{
    DWORD dwCode;
    DWORD dwMode;
    ULONG ulCloneSourceID;
    ULONG ulCount;
    ULONG * pulTargetID;
}R200_SetTopologyData, *PR200_SetTopologyData;


//Struct for Escape data


typedef struct _R200_EscData
{
    R200_ESCCODE dwEscapeCode;
    union
        {            
            R200_GetIDData sGetIDData;
            R200_TopologyData sTopologyData;            
        };

}R200_EscData, *PR200_EscData;  

#pragma pack(pop)



