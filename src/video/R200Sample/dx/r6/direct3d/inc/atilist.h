

//    
//  $Workfile: atilist.h $
//  
//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//

#ifndef _ATILIST_H__
#define _ATILIST_H__

//*****************************************************************************
//
// Atilist is an implementation of a generic list (array). The list will grow
// as needed when requested by the client. The list is grown by realloc'ing
// the memory. As a result, the client should not cache pointer to any item in
// the list because the list may move around in memory. All accesses should be
// achived temporary access of a pointer retrived by passing an index into
// AL_GetEntry.
//
// Note that atilist is wholly an inline implementation, with no accompanying
// C file.
// 
//*****************************************************************************


//*****************************************************************************
// Defines and typedefs
//*****************************************************************************

typedef struct _ATILIST
{
  LPVOID pvArray;       // The list (a.k.a. array) of items
  DWORD dwEntrySize;    // The size of each item
  DWORD dwNumEntries;   // The number of items currently in the list
} ATILIST, *LPATILIST;


//*****************************************************************************
// Inlines
//*****************************************************************************


/*****************************************************************************
* void AL_Create( LPATILIST pAl, DWORD dwEntrySize )
*
* Args:
*       pAl          The list to be created
*       dwEntrySize  The size of each item in the list in bytes
*
* Returns: None
*
* Description:
*       Intializes the list with zero entries.  
*
******************************************************************************/
__inline void AL_Create( LPATILIST pAl, DWORD dwEntrySize )
{
  HSLASSERT( dwEntrySize );

  pAl->pvArray = NULL;
  pAl->dwEntrySize = dwEntrySize;
  pAl->dwNumEntries = 0ul;
}

/*****************************************************************************
* BOOL AL_IsListValid( LPATILIST pAl )
*
* Args:
*       pAl          The list in question
*
* Returns: TRUE if list has been created; FALSE otherwise
*
* Description:
*       Checks to see if the list is valide
*
******************************************************************************/
__inline BOOL AL_IsListValid( LPATILIST pAl )
{
  if ((pAl == NULL) || (pAl->dwEntrySize == 0))
  {
    return FALSE;
  }
  return TRUE;
}

/*****************************************************************************
* LPVOID AL_GetEntry( LPATILIST pAl, DWORD dwIndex )
*
* Args:
*       pAl          The list in question
*       dwIndex      The the index of the item to be retrieved
*
* Returns: Pointer to the item in question
*
* Description:
*       Retrieves a pointer to an item at the index if the list has that
*       many entires. Returns NULL otherwise.
*
******************************************************************************/
__inline LPVOID AL_GetEntry( LPATILIST pAl, DWORD dwIndex )
{
  HSLASSERT( pAl );

  if( dwIndex >= pAl->dwNumEntries )
  { return NULL; }

  return (LPVOID)((LPBYTE)pAl->pvArray + dwIndex * pAl->dwEntrySize );
}

/*****************************************************************************
* BOOL AL_IsEntryValid( LPATILIST pAl, DWORD dwIndex )
*
* Args:
*       pAl          The list in question
*       dwIndex      The the index of the item to be retrieved
*
* Returns: TRUE is list is large enough for that entry, FALSE otherwise
*
* Description:
*       Checks to see if the list is large enough for the index in question.
*
******************************************************************************/
__inline BOOL AL_IsEntryValid( LPATILIST pAl, DWORD dwIndex )
{
  HSLASSERT( pAl );

  if( dwIndex >= pAl->dwNumEntries )
  { return FALSE; }

  return TRUE;
}


/*****************************************************************************
* BOOL AL_SimpleGrowArray( LPATIDXOBJECT lpATIDXObj, LPATILIST pAl, DWORD dwIndex )
*
* Args:
*       pAl          The list in question
*       dwIndex      Minimum index to grow the list to.
*
* Returns: TRUE is list can be grown, FALSE otherwise
*
* Description:
*       If necessary, grows the list to accomodate the index passed in. This
*       function will only grow the list so that is just large enough for the
*       index passed in. This is a bad idea if you call AL_GrowArray with
*       incrementing indices because the list will be realloced every time.
*       Generally speaking, AL_GrowArray is a better choice.
*
******************************************************************************/
__inline BOOL AL_SimpleGrowArray( LPVOID lpATIDXObj, LPATILIST pAl, DWORD dwIndex )
{
  DWORD     dwNewIndex = 0;
  DWORD     dwNewSize = 0;
  
  HSLASSERT( pAl );
  HSLASSERT( pAl->dwEntrySize );

  dwNewIndex = dwIndex + 1;

  if (dwNewIndex < dwIndex)     // Handle overflow
  {
    return FALSE;
  }
  
  if (dwNewIndex > (ULONG_MAX / pAl->dwEntrySize))  // Handle overflow
  {
    return FALSE;
  }

  dwNewSize = dwNewIndex * pAl->dwEntrySize;

  if( dwIndex >= pAl->dwNumEntries )
  {
    LPVOID pvNewArray = (LPVOID *)pDdHslSharedMemCallocEx( lpATIDXObj, dwNewSize );

    if( pvNewArray == NULL )
    { return FALSE; }

    if( pAl->dwNumEntries )
    {
      memcpy( pvNewArray, pAl->pvArray, pAl->dwNumEntries * pAl->dwEntrySize );
      bDdHslSharedMemFreeEx( lpATIDXObj, pAl->pvArray );
    }

    pAl->dwNumEntries = dwIndex;
    pAl->pvArray = pvNewArray;
  }

  return TRUE;
}


/*****************************************************************************
* BOOL AL_GrowArray( LPATIDXOBJECT lpATIDXObj, LPATILIST pAl, DWORD dwIndex )
*
* Args:
*       pAl          The list in question
*       dwIndex      Minimum index to grow the list to.
*
* Returns: TRUE is list can be grown, FALSE otherwise
*
* Description:
*       If necessary, grows the list to accomodate the index passed in. This
*       function will geometrically grow the size of the array so that
*       the realloc function is not called often if AL_GrowArray is called
*       with incrementing indices. This function also rounds up to the
*       nearest page when allocating.
*
******************************************************************************/
__inline BOOL AL_GrowArray( LPVOID lpATIDXObj, LPATILIST pAl, DWORD dwIndex )
{
  HSLASSERT( pAl );
  HSLASSERT( pAl->dwEntrySize );

  if( dwIndex >= pAl->dwNumEntries )
  {
    LPVOID pvNewArray;
    DWORD dwMemSize;

    // Always work in integer number of pages
    if( pAl->dwNumEntries )
    { dwMemSize = ((pAl->dwNumEntries * pAl->dwEntrySize) + 4095ul) & ~4095ul; }
    else
    { dwMemSize = 4096ul; }

    // Double the amount to allocate each time.
    while( dwMemSize < (dwIndex + 1) * pAl->dwEntrySize )
    {
      dwMemSize <<= 1;
      if( !dwMemSize )
      { return FALSE; }
    }

    //Note: this call automatically zeros its allocated memory.
    pvNewArray = (LPVOID *)pDdHslSharedMemCallocEx( lpATIDXObj, dwMemSize );

    if( pvNewArray == NULL )
    { return FALSE; }

    if( pAl->dwNumEntries )
    {
      memcpy( pvNewArray, pAl->pvArray, pAl->dwNumEntries * pAl->dwEntrySize );
      bDdHslSharedMemFreeEx( lpATIDXObj, pAl->pvArray );
    }

    pAl->dwNumEntries = dwMemSize / pAl->dwEntrySize;
    pAl->pvArray = pvNewArray;
  }

  return TRUE;
}


/*****************************************************************************
* void AL_Destroy( LPATIDXOBJECT lpATIDXObj, LPATILIST pAl, DWORD dwIndex )
*
* Args:
*       pAl          The list in question
*
* Returns: Nothing
*
* Description:
*       Frees any allocated memory and nulls out the list.
*
******************************************************************************/
__inline void AL_Destroy( LPVOID lpATIDXObj, LPATILIST pAl )
{
  HSLASSERT( pAl );

  if( pAl && (pAl->dwNumEntries ) )
  {
    bDdHslSharedMemFreeEx( lpATIDXObj, pAl->pvArray );
    pAl->pvArray = NULL;
    pAl->dwEntrySize = 0ul;
    pAl->dwNumEntries = 0ul;
  }
}

/*****************************************************************************
* LPVOID AL_GetNewEntry( LPATIDXOBJECT lpATIDXObj, LPATILIST pAl, DWORD dwIndex )
*
* Args:
*       pAl          The list in question
*       dwIndex      The the index where the new entry will reside
*
* Returns: Pointer to a zero'ed array entry.
*
* Description:
*       This function will return a zero'ed array entry to the caller
*       corresponding to the provided index.  The array is grown to fit the
*       index if necessary.
*
******************************************************************************/
__inline LPVOID AL_GetNewEntry( LPVOID lpATIDXObj, LPATILIST pAl, DWORD dwIndex )
{
    LPVOID lpArrayEntry = NULL;

    HSLASSERT( pAl );

    if ( !AL_IsEntryValid(pAl, dwIndex) )
    {
        //Grow the list to make room for the new item.
        if ( AL_GrowArray(lpATIDXObj, pAl, dwIndex) )
        {
            //No need to zero out the memory since GrowArray did it for us.
            return AL_GetEntry(pAl, dwIndex);
        }
        else
        {
            return NULL;
        }
    }

    //If we are reusing an existing array entry, be sure to zero it out.
    lpArrayEntry = AL_GetEntry(pAl, dwIndex);
    ZeroMemory(lpArrayEntry, pAl->dwEntrySize);

    return lpArrayEntry;
}

#endif

