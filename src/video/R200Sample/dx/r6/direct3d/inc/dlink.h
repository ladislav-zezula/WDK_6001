#ifndef _DLINK_H_
#define _DLINK_H_

#define DL_ALLOC_CHUNK_SIZE 4096ul

/////////////////////////////////////////////////////////////////////////////////////////
//
// A general double link list
// 
// A client can call vDL_Initialize to create the list with nodes of a given size
//        (say the size of a strucutre).
// Then the client can call pvDL_Alloc to allocate a node.
// Then the client can call vDL_Insert to insert the node into the linked list.
// Then the client can call vDL_Remove to remove the node from the linked list.
// Then the client can call vDL_Free to free the node.
// Then the client can call vDL_Destroy and free up all memory.
//
// Note that pvDL_Alloc allocates many nodes, at once and hands them out one at a time.
// Note that vDL_Free only puts a node into a free list to be recycled.
//
// Alternatively, if all the client wants, is for Dlink to aggregate a large number
// of small node allocations into a small number of large memory allocations, the
// insert and remove become superfluous.
// A client can call vDL_Initialize to create the list with nodes of a given size
//        (say the size of a strucutre).
// Then the client can call pvDL_Alloc to allocate a node.
// Then the client can call vDL_Free to free the node.
//
/////////////////////////////////////////////////////////////////////////////////////////

#include <atilist.h>

typedef struct _DLinkList
{
    DWORD       dwNodeSize;     // The size of the clients node memory.
                                // Note we allocate this, plus two pointers per node.
    LPVOID     *pvHead;         // The head of the client's list
    LPVOID     *pvTail;         // The tail of the client's list
  
    DWORD       dwTotalNodes;   // The total number of nodes
    DWORD       dwFreeNodes;    // The number of nodes in the free list
    DWORD       dwNodesInList;  // The number of nodes in the client's list

    LPVOID     *pvFreeHead;     // The head of the free list

    ATILIST     alHeadNodes;    // Head nodes are pointers to memory allocated. Many nodes
                                // are allocated at once, but a head node points to the original
                                // memory allocated, a.k.a the head node.
    DWORD       dwNumUsedHeadNodes;     // The number of head nodes already used
} DLinkList, *LPDlinkList;


/////////////////////////////////////////////////////////////////////////////////////////
//
// External functions - these can be called from outside Dlink.c
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
//
// vDL_Initialize initializes the linked list.
// vDL_Destroy destroys the list and frees all memory.
// In order to destroy:
//   vDL_Remove all vDL_Insert'ed nodes.
//   vDL_Free all pvDL_Alloc'ed nodes.
//
/////////////////////////////////////////////////////////////////////////////////////////
extern void vDL_Initialize(LPDlinkList pDlink, DWORD dwNodeSize);
extern void vDL_Destroy(PVOID lpATIDXObj, LPDlinkList pDlink);

/////////////////////////////////////////////////////////////////////////////////////////
//
// pvDL_Alloc allocates a node (potentiall from the free list), and returns a pointer to it.
// vDL_Free frees a node to the free list. A node cannot be freed if it is still in the
// client's linked list. Call vDL_Remove before freeing.
//
/////////////////////////////////////////////////////////////////////////////////////////
extern LPVOID pvDL_Alloc(PVOID lpATIDXObj, LPDlinkList pDlink);
extern void vDL_Free(LPDlinkList pDlink, LPVOID pvNode);

/////////////////////////////////////////////////////////////////////////////////////////
//
// vDL_Insert inserts a node into the client list after pvPrev.
// vDL_Insert places the node at the head of the list is pvPrev is null.
// pvPrev must be NULL, or a node in the client's list.
//
/////////////////////////////////////////////////////////////////////////////////////////
extern void vDL_Insert(LPDlinkList pDlink, LPVOID pvNode, LPVOID pvPrev);

/////////////////////////////////////////////////////////////////////////////////////////
//
// vDL_Remove removes a node from the client's list. pvNode must be in the client's list.
//
/////////////////////////////////////////////////////////////////////////////////////////
extern void vDL_Remove(LPDlinkList pDlink, LPVOID pvNode);

/////////////////////////////////////////////////////////////////////////////////////////
//
// pvDL_GetNext and pvDL_GetPrev return the next and previous nodes, respectively.
//
/////////////////////////////////////////////////////////////////////////////////////////
_inline LPVOID pvDL_GetNext(LPDlinkList pDlink, LPVOID pvNode)
{
    LPVOID *ppvNext;
    HSLASSERT(pDlink != NULL);
    HSLASSERT(pvNode != NULL);
    ppvNext = (LPVOID *)((LPBYTE)pvNode + pDlink->dwNodeSize);
    return *ppvNext;
}

_inline LPVOID pvDL_GetPrev(LPDlinkList pDlink, LPVOID pvNode)
{
    LPVOID *ppvPrev;
    HSLASSERT(pDlink != NULL);
    HSLASSERT(pvNode != NULL);
    ppvPrev = (LPVOID *)((LPBYTE)pvNode + pDlink->dwNodeSize + sizeof(LPVOID));
    return *ppvPrev;
}

_inline LPVOID pvDL_GetHead(LPDlinkList pDlink)
{
    HSLASSERT(pDlink != NULL);
    return pDlink->pvHead;
}

_inline LPVOID pvDL_GetTail(LPDlinkList pDlink)
{
    HSLASSERT(pDlink != NULL);
    return pDlink->pvTail;
}

_inline DWORD dwDl_GetNumNodesInList(LPDlinkList pDlink)
{
    HSLASSERT(pDlink != NULL);
    return pDlink->dwNodesInList;
}

#endif

