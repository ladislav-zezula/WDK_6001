#if !defined(NTDDI_VERSION)

#error NTDDI_VERSION must be defined to include this file.

#elif (NTDDI_VERSION >= NTDDI_VISTA)

/*++

Copyright (c) 1989  Microsoft Corporation

Module Name:

    fcbtable.h

Abstract:

    This module defines the data structures that facilitate management of the
    collection of FCB's associated with a NET_ROOT

Author:
--*/


#ifndef _RXFCBTABLE_
#define _RXFCBTABLE_

typedef struct _RX_FCB_TABLE_ENTRY {

    //
    //  Normal Header for Refcounted Structure
    //

    NODE_TYPE_CODE NodeTypeCode;
    NODE_BYTE_SIZE NodeByteSize;

    //
    //  the computed hash value
    //

    ULONG HashValue;

    //
    //  the path associated with the FCB
    //

    UNICODE_STRING Path;

    //
    //  the threaded list of all entries in a bucket.
    //

    LIST_ENTRY HashLinks;

    //
    //  Statistics for amortising lookup costs
    //

    LONG Lookups;
} RX_FCB_TABLE_ENTRY, *PRX_FCB_TABLE_ENTRY;


#define RX_FCB_TABLE_NUMBER_OF_HASH_BUCKETS 32

typedef struct _RX_FCB_TABLE {

    //
    //  Normal Header for refcounted data structures
    //

    NODE_TYPE_CODE NodeTypeCode;
    NODE_BYTE_SIZE NodeByteSize;

    //
    //  version stamp changes on each insertion/removal
    //

    __volatile ULONG Version;

    BOOLEAN CaseInsensitiveMatch;
    USHORT NumberOfBuckets;

    //
    //  Statistics for table maintenance
    //

    __volatile LONG Lookups;
    __volatile LONG FailedLookups;
    __volatile LONG Compares;

    //
    //  Resource used to control table access
    //

    ERESOURCE TableLock;

    //
    //  TableEntry for the Null string
    //

    PRX_FCB_TABLE_ENTRY TableEntryForNull;

    //
    //  the hash buckets
    //

    LIST_ENTRY HashBuckets[RX_FCB_TABLE_NUMBER_OF_HASH_BUCKETS];
} RX_FCB_TABLE, *PRX_FCB_TABLE;

extern
VOID
RxInitializeFcbTable (
    IN OUT PRX_FCB_TABLE FcbTable,
    IN BOOLEAN CaseInsensitiveMatch
    );

extern 
VOID
RxFinalizeFcbTable (
    IN OUT PRX_FCB_TABLE FcbTable
    );

extern 
PFCB
RxFcbTableLookupFcb (
    IN  PRX_FCB_TABLE FcbTable,
    IN  PUNICODE_STRING Path
    );

extern 
NTSTATUS
RxFcbTableInsertFcb (
    IN OUT PRX_FCB_TABLE FcbTable,
    IN OUT PFCB Fcb
    );

extern 
NTSTATUS
RxFcbTableRemoveFcb (
    IN OUT PRX_FCB_TABLE FcbTable,
    IN OUT PFCB Fcb
    );

#define RxAcquireFcbTableLockShared(TABLE,WAIT) \
        ExAcquireResourceSharedLite( &(TABLE)->TableLock, WAIT )

#define RxAcquireFcbTableLockExclusive(TABLE,WAIT) \
        ExAcquireResourceExclusiveLite( &(TABLE)->TableLock, WAIT )

#define RxReleaseFcbTableLock(TABLE)  \
        ExReleaseResourceLite( &(TABLE)->TableLock )

#define RxIsFcbTableLockExclusive(TABLE) ExIsResourceAcquiredExclusiveLite( &(TABLE)->TableLock )

#define RxIsFcbTableLockAcquired(TABLE) ( ExIsResourceAcquiredSharedLite( &(TABLE)->TableLock ) || \
                                          ExIsResourceAcquiredExclusiveLite( &(TABLE)->TableLock ) )


#endif

#elif (NTDDI_VERSION >= NTDDI_WS03)

/*++

Copyright (c) 1989  Microsoft Corporation

Module Name:

    fcbtable.h

Abstract:

    This module defines the data structures that facilitate management of the
    collection of FCB's associated with a NET_ROOT

Author:
--*/


#ifndef _RXFCBTABLE_
#define _RXFCBTABLE_

typedef struct _RX_FCB_TABLE_ENTRY {

    //
    //  Normal Header for Refcounted Structure
    //

    NODE_TYPE_CODE NodeTypeCode;
    NODE_BYTE_SIZE NodeByteSize;

    //
    //  the computed hash value
    //

    ULONG HashValue;

    //
    //  the path associated with the FCB
    //

    UNICODE_STRING Path;

    //
    //  the threaded list of all entries in a bucket.
    //

    LIST_ENTRY HashLinks;

    //
    //  Statistics for amortising lookup costs
    //

    LONG Lookups;
} RX_FCB_TABLE_ENTRY, *PRX_FCB_TABLE_ENTRY;


#define RX_FCB_TABLE_NUMBER_OF_HASH_BUCKETS 32

typedef struct _RX_FCB_TABLE {

    //
    //  Normal Header for refcounted data structures
    //

    NODE_TYPE_CODE NodeTypeCode;
    NODE_BYTE_SIZE NodeByteSize;

    //
    //  version stamp changes on each insertion/removal
    //

    ULONG Version;

    BOOLEAN CaseInsensitiveMatch;
    USHORT NumberOfBuckets;

    //
    //  Statistics for table maintenance
    //

    LONG Lookups;
    LONG FailedLookups;
    LONG Compares;

    //
    //  Resource used to control table access
    //

    ERESOURCE TableLock;

    //
    //  TableEntry for the Null string
    //

    PRX_FCB_TABLE_ENTRY TableEntryForNull;

    //
    //  the hash buckets
    //

    LIST_ENTRY HashBuckets[RX_FCB_TABLE_NUMBER_OF_HASH_BUCKETS];
} RX_FCB_TABLE, *PRX_FCB_TABLE;

extern
VOID
RxInitializeFcbTable (
    IN OUT PRX_FCB_TABLE FcbTable,
    IN BOOLEAN CaseInsensitiveMatch
    );

extern 
VOID
RxFinalizeFcbTable (
    IN OUT PRX_FCB_TABLE FcbTable
    );

extern 
PFCB
RxFcbTableLookupFcb (
    IN  PRX_FCB_TABLE FcbTable,
    IN  PUNICODE_STRING Path
    );

extern 
NTSTATUS
RxFcbTableInsertFcb (
    IN OUT PRX_FCB_TABLE FcbTable,
    IN OUT PFCB Fcb
    );

extern 
NTSTATUS
RxFcbTableRemoveFcb (
    IN OUT PRX_FCB_TABLE FcbTable,
    IN OUT PFCB Fcb
    );

#define RxAcquireFcbTableLockShared(TABLE,WAIT) \
        ExAcquireResourceSharedLite( &(TABLE)->TableLock, WAIT )

#define RxAcquireFcbTableLockExclusive(TABLE,WAIT) \
        ExAcquireResourceExclusiveLite( &(TABLE)->TableLock, WAIT )

#define RxReleaseFcbTableLock(TABLE)  \
        ExReleaseResourceLite( &(TABLE)->TableLock )

#define RxIsFcbTableLockExclusive(TABLE) ExIsResourceAcquiredExclusiveLite( &(TABLE)->TableLock )

#define RxIsFcbTableLockAcquired(TABLE) ( ExIsResourceAcquiredSharedLite( &(TABLE)->TableLock ) || \
                                          ExIsResourceAcquiredExclusiveLite( &(TABLE)->TableLock ) )


#endif


#elif (NTDDI_VERSION >= NTDDI_WINXP)

/*++

Copyright (c) 1989  Microsoft Corporation

Module Name:

    fcbtable.h

Abstract:

    This module defines the data structures that facilitate management of the
    collection of FCB's associated with a NET_ROOT

Author:
Revision History:

    This was derived from the original implementation of prefix tables done
    by Joe Linn.

--*/


#ifndef _RXFCBTABLE_
#define _RXFCBTABLE_

typedef struct _RX_FCB_TABLE_ENTRY {

    // Normal Header for Refcounted Structure
    NODE_TYPE_CODE NodeTypeCode;
    NODE_BYTE_SIZE NodeByteSize;

    // the computed hash value
    ULONG      HashValue;

    // the path associated with the FCB
    UNICODE_STRING Path;

    // the threaded list of all entries in a bucket.
    LIST_ENTRY HashLinks;

    // Statistics for amortising lookup costs
    LONG       Lookups;
} RX_FCB_TABLE_ENTRY, *PRX_FCB_TABLE_ENTRY;


#define RX_FCB_TABLE_NUMBER_OF_HASH_BUCKETS 32

typedef struct _RX_FCB_TABLE {

    // Normal Header for refcounted data structures
    NODE_TYPE_CODE NodeTypeCode;
    NODE_BYTE_SIZE NodeByteSize;

    // version stamp changes on each insertion/removal
    ULONG Version;

    BOOLEAN CaseInsensitiveMatch;
    USHORT  NumberOfBuckets;

    // Statistics for table maintenance
    LONG    Lookups;
    LONG    FailedLookups;
    LONG    Compares;

    // Resource used to control table access
    ERESOURCE TableLock;

    // TableEntry for the Null string
    PRX_FCB_TABLE_ENTRY pTableEntryForNull;

    // the hash buckets
    LIST_ENTRY HashBuckets[RX_FCB_TABLE_NUMBER_OF_HASH_BUCKETS];
} RX_FCB_TABLE, *PRX_FCB_TABLE;

extern VOID
RxInitializeFcbTable(
    IN OUT PRX_FCB_TABLE pFcbTable,
    IN     BOOLEAN       CaseInsensitiveMatch);

extern VOID
RxFinalizeFcbTable(
    IN OUT PRX_FCB_TABLE pFcbTable);

extern PFCB
RxFcbTableLookupFcb(
    IN  PRX_FCB_TABLE    pFcbTable,
    IN  PUNICODE_STRING  pPath);

extern NTSTATUS
RxFcbTableInsertFcb (
    IN OUT PRX_FCB_TABLE pFcbTable,
    IN OUT PFCB          pFcb);

extern NTSTATUS
RxFcbTableRemoveFcb (
    IN OUT PRX_FCB_TABLE pFcbTable,
    IN OUT PFCB          pFcb);

#define RxAcquireFcbTableLockShared(pFcbTable,Wait) \
        ExAcquireResourceSharedLite(&(pFcbTable)->TableLock,Wait)

#define RxAcquireFcbTableLockExclusive(pFcbTable,Wait) \
        ExAcquireResourceExclusiveLite(&(pFcbTable)->TableLock,Wait)

#define RxReleaseFcbTableLock(pFcbTable)  \
        ExReleaseResourceLite(&(pFcbTable)->TableLock)

#define RxIsFcbTableLockExclusive(PTABLE) ExIsResourceAcquiredExclusiveLite(&(PTABLE)->TableLock)

#define RxIsFcbTableLockAcquired(PTABLE) ( ExIsResourceAcquiredSharedLite(&(PTABLE)->TableLock) || \
                                              ExIsResourceAcquiredExclusiveLite(&(PTABLE)->TableLock) )


#endif


#elif (NTDDI_VERSION >= NTDDI_WIN2K)

/*++

Copyright (c) 1989  Microsoft Corporation

Module Name:

    fcbtable.h

Abstract:

    This module defines the data structures that facilitate management of the
    collection of FCB's associated with a NET_ROOT

Author:
--*/


#ifndef _RXFCBTABLE_
#define _RXFCBTABLE_

typedef struct _RX_FCB_TABLE_ENTRY {

    // Normal Header for Refcounted Structure
    NODE_TYPE_CODE NodeTypeCode;
    NODE_BYTE_SIZE NodeByteSize;

    // the computed hash value
    ULONG      HashValue;

    // the path associated with the FCB
    UNICODE_STRING Path;

    // the threaded list of all entries in a bucket.
    LIST_ENTRY HashLinks;

    // Statistics for amortising lookup costs
    LONG       Lookups;
} RX_FCB_TABLE_ENTRY, *PRX_FCB_TABLE_ENTRY;


#define RX_FCB_TABLE_NUMBER_OF_HASH_BUCKETS 32

typedef struct _RX_FCB_TABLE {

    // Normal Header for refcounted data structures
    NODE_TYPE_CODE NodeTypeCode;
    NODE_BYTE_SIZE NodeByteSize;

    // version stamp changes on each insertion/removal
    ULONG Version;

    BOOLEAN CaseInsensitiveMatch;
    USHORT  NumberOfBuckets;

    // Statistics for table maintenance
    LONG    Lookups;
    LONG    FailedLookups;
    LONG    Compares;

    // Resource used to control table access
    ERESOURCE TableLock;

    // TableEntry for the Null string
    PRX_FCB_TABLE_ENTRY pTableEntryForNull;

    // the hash buckets
    LIST_ENTRY HashBuckets[RX_FCB_TABLE_NUMBER_OF_HASH_BUCKETS];
} RX_FCB_TABLE, *PRX_FCB_TABLE;

extern VOID
RxInitializeFcbTable(
    IN OUT PRX_FCB_TABLE pFcbTable,
    IN     BOOLEAN       CaseInsensitiveMatch);

extern VOID
RxFinalizeFcbTable(
    IN OUT PRX_FCB_TABLE pFcbTable);

extern PFCB
RxFcbTableLookupFcb(
    IN  PRX_FCB_TABLE    pFcbTable,
    IN  PUNICODE_STRING  pPath);

extern NTSTATUS
RxFcbTableInsertFcb (
    IN OUT PRX_FCB_TABLE pFcbTable,
    IN OUT PFCB          pFcb);

extern NTSTATUS
RxFcbTableRemoveFcb (
    IN OUT PRX_FCB_TABLE pFcbTable,
    IN OUT PFCB          pFcb);

#define RxAcquireFcbTableLockShared(pFcbTable,Wait) \
        ExAcquireResourceShared(&(pFcbTable)->TableLock,Wait)

#define RxAcquireFcbTableLockExclusive(pFcbTable,Wait) \
        ExAcquireResourceExclusive(&(pFcbTable)->TableLock,Wait)

#define RxReleaseFcbTableLock(pFcbTable)  \
        ExReleaseResource(&(pFcbTable)->TableLock)

#define RxIsFcbTableLockExclusive(PTABLE) ExIsResourceAcquiredExclusive(&(PTABLE)->TableLock)

#define RxIsFcbTableLockAcquired(PTABLE) ( ExIsResourceAcquiredShared(&(PTABLE)->TableLock) || \
                                              ExIsResourceAcquiredExclusive(&(PTABLE)->TableLock) )


#endif


#else /* NTDDI_VERSION */

#error This file cannot be included for this NTDDI_VERSION.

#endif /* NTDDI_VERSION */


