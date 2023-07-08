/*--

Copyright (C) Microsoft Corporation, 1991 - 1999

Module Name:

    sense.c

Abstract:

    This file contains the methods needed to accurately
    determine how to retry requests on CDROM device types.

Environment:

    kernel mode only

Revision History:

--*/

#include "stddef.h"
#include "string.h"

#include "ntddk.h"
#include "classpnp.h"
#include "ntddstor.h"
#include "cdrom.h"
#include "ntstrsafe.h"

#ifdef DEBUG_USE_WPP
#include "sense.tmh"
#endif

#ifdef ALLOC_PRAGMA
//#pragma alloc_text(INIT, DriverEntry)
#endif

#define UNITS_PER_SECOND (10*1000*1000)
#define SECONDS_TO_100NS_UNITS(x) \
    (((LONGLONG)x) * UNITS_PER_SECOND)



//
// FROM CLASSPNP\CLASSP.H
//  Lots of retries of synchronized SCSI commands that devices may not
//  even support really slows down the system (especially while booting).
//  (Even GetDriveCapacity may be failed on purpose if an external disk is powered off).
//  If a disk cannot return a small initialization buffer at startup
//  in two attempts (with delay interval) then we cannot expect it to return
//  data consistently with four retries.
//  So don't set the retry counts as high here as for data SRBs.
//
//  If we find that these requests are failing consecutively,
//  despite the retry interval, on otherwise reliable media,
//  then we should either increase the retry interval for
//  that failure or (by all means) increase these retry counts as appropriate.
//
//  If adding any further special-case items, be sure to add extra CASE statement
//  to InterpretSenseInfo2() routine.
//

#define TOTAL_COUNT_RETRY_DEFAULT       8
#define TOTAL_COUNT_RETRY_LOCK_MEDIA    1
#define TOTAL_COUNT_RETRY_MODESENSE     1
#define TOTAL_COUNT_RETRY_READ_CAPACITY 1


#define TOTAL_SECONDS_RETRY_TIME_WRITE          160
#define TOTAL_SECONDS_RETRY_TIME_MEDIUM_REMOVAL 120

BOOLEAN
InterpretSenseInfo2(
    __in      PDEVICE_OBJECT       Fdo,
    __in_opt  PIRP                 OriginalRequest, // not always the same as in SRB
    __in      PSCSI_REQUEST_BLOCK  Srb,
              UCHAR                MajorFunctionCode,
              ULONG                IoDeviceCode,
              ULONG                PreviousRetryCount,
    __in_opt  SRB_HISTORY *        RequestHistory_DoNotUse, // don't use -- want to treat as const; see local variable of same name
    __out     NTSTATUS *           Status,
    __out __range(0,MAXIMUM_RETRY_FOR_SINGLE_IO_IN_100NS_UNITS)
    LONGLONG * RetryIn100nsUnits
    )
{
    LONGLONG           localRetryIn100nsUnits = 0;
    BOOLEAN            retry = FALSE;
    UCHAR      const   opCode = Srb->Cdb[0];
    CDB        const * cdb = (CDB const *)(Srb->Cdb);
    LONGLONG           total100nsUnitsSinceFirstSend = -1;
    SRB_HISTORY const * RequestHistory = RequestHistory_DoNotUse;
    SENSE_DATA sense; RtlZeroMemory(&sense, sizeof(SENSE_DATA));

    // setup sense data -- use normalized copy when available, but since history is not always non-NULL,
    // need to also see if can get it from the SRB.
    if (RequestHistory != NULL)
    {
        RtlCopyMemory(&sense, &( RequestHistory->History[ RequestHistory->UsedHistoryCount-1 ].NormalizedSenseData ), sizeof(SENSE_DATA));
    }
    else if ((Srb->SenseInfoBuffer != NULL) && (Srb->SenseInfoBufferLength != 0))
    {
        RtlCopyMemory(&sense, Srb->SenseInfoBuffer, min(Srb->SenseInfoBufferLength, sizeof(SENSE_DATA)));
    }

    // determine total time this IO has been outstanding (-1 used if unknown)
    if (RequestHistory != NULL)
    {
        LARGE_INTEGER tmp;
        KeQueryTickCount(&tmp);
        tmp.QuadPart -= RequestHistory->History[0].TickCountSent.QuadPart;
        tmp.QuadPart *= KeQueryTimeIncrement();
        total100nsUnitsSinceFirstSend = tmp.QuadPart;
    }

    // first, call the original ClassInterpretSenseInfo().  This gives a default
    // retry time, and also may have other side effects.
    {
        ULONG seconds = 0;
        retry = ClassInterpretSenseInfo(Fdo,
                                        Srb,
                                        MajorFunctionCode,
                                        IoDeviceCode,
                                        PreviousRetryCount,
                                        Status,
                                        &seconds);
        localRetryIn100nsUnits = SECONDS_TO_100NS_UNITS(seconds);
    }

    // TODO: add lots more logic to this section of the code....
    //       Currently just took CLASSPNP code
    if (opCode == SCSIOP_MEDIUM_REMOVAL)
    {
        if (( cdb->AsByte[1]         == 0) &&
            ( cdb->AsByte[2]         == 0) &&
            ( cdb->AsByte[3]         == 0) &&
            ((cdb->AsByte[4] & 0xFC) == 0)
            )
        {
            // byte[4] == 0x3 or byte[4] == 0x1  ==  UNLOCK OF MEDIA
            if ((cdb->AsByte[4] & 0x01) == 0)
            {
                if (// we have time-based information available
                    (total100nsUnitsSinceFirstSend != -1) &&
                    // total time for unlock has not been exceeded
                    (total100nsUnitsSinceFirstSend <  SECONDS_TO_100NS_UNITS(TOTAL_SECONDS_RETRY_TIME_MEDIUM_REMOVAL))
                    )
                {
                    // keep retrying unlock operation for some time
                    retry = TRUE;
                }
            }
            else // LOCK REQUEST
            {
                // do not retry LOCK requests more than once (per CLASSPNP code)
                if (PreviousRetryCount > TOTAL_COUNT_RETRY_LOCK_MEDIA)
                {
                    retry = FALSE;
                }
            }
        }

        // want a minimum time to retry of 2 seconds
        if ((*Status == STATUS_DEVICE_NOT_READY) &&
            (sense.AdditionalSenseCode == SCSI_ADSENSE_LUN_NOT_READY))
        {
            localRetryIn100nsUnits = max(localRetryIn100nsUnits, SECONDS_TO_100NS_UNITS(2));
        }
        else if (SRB_STATUS(Srb->SrbStatus) == SRB_STATUS_SELECTION_TIMEOUT)
        {
            localRetryIn100nsUnits = max(localRetryIn100nsUnits, SECONDS_TO_100NS_UNITS(2));
        }
    }
    else if ((opCode == SCSIOP_MODE_SENSE) || (opCode == SCSIOP_MODE_SENSE10))
    {
        // want a minimum time to retry of 2 seconds
        if ((*Status == STATUS_DEVICE_NOT_READY) &&
            (sense.AdditionalSenseCode == SCSI_ADSENSE_LUN_NOT_READY))
        {
            localRetryIn100nsUnits = max(localRetryIn100nsUnits, SECONDS_TO_100NS_UNITS(2));
        }
        else if (SRB_STATUS(Srb->SrbStatus) == SRB_STATUS_SELECTION_TIMEOUT)
        {
            localRetryIn100nsUnits = max(localRetryIn100nsUnits, SECONDS_TO_100NS_UNITS(2));
        }

        // Want to ignore a STATUS_VERIFY_REQUIRED error because it either
        // doesn't make sense or is required to satisfy the VERIFY.
        if (*Status == STATUS_VERIFY_REQUIRED)
        {
            retry = TRUE;
        }
        else if (SRB_STATUS(Srb->SrbStatus) == SRB_STATUS_DATA_OVERRUN){
            /*
             *  This is a HACK.
             *  Atapi returns SRB_STATUS_DATA_OVERRUN when it really means
             *  underrun (i.e. success, and the buffer is longer than needed).
             *  So treat this as a success.
             *  When the caller of this function sees that the status was changed to success,
             *  it will add the transferred length to the original irp.
             */
            *Status = STATUS_SUCCESS;
            retry = FALSE;
        }

        // limit the count of retries
        if (PreviousRetryCount > TOTAL_COUNT_RETRY_MODESENSE)
        {
            retry = FALSE;
        }
    }
    else if ((opCode == SCSIOP_READ_CAPACITY) || (opCode == SCSIOP_READ_CAPACITY16))
    {
        // Want to ignore a STATUS_VERIFY_REQUIRED error because it either
        // doesn't make sense or is required to satisfy the VERIFY.
        if (*Status == STATUS_VERIFY_REQUIRED)
        {
            retry = TRUE;
        }

        if (PreviousRetryCount > TOTAL_COUNT_RETRY_READ_CAPACITY)
        {
            retry = FALSE;
        }

    }
    else if (IS_SCSIOP_READWRITE(opCode))
    {
        // only perform the OVERRIDE_VERIFY_VOLUME check if there is an associated irp
        if (OriginalRequest != NULL)
        {
            PIO_STACK_LOCATION currentStack = IoGetCurrentIrpStackLocation(OriginalRequest);

            // NOTE: We do not currently low-memory retry
            //       due to inability to split all writes
            //       to PAGE_SIZE (i.e. CD-RW Packet Writing)
            // if (*Status == STATUS_INSUFFICIENT_RESOURCES)...

            //
            //  Retry if still verifying a (possibly) reloaded disk/cdrom.
            //
            if (TEST_FLAG(currentStack->Flags, SL_OVERRIDE_VERIFY_VOLUME) &&
                (*Status == STATUS_VERIFY_REQUIRED)
                )
            {
                *Status = STATUS_IO_DEVICE_ERROR;
                retry = TRUE;
            }
        }

        //
        // Special-case handling of READ/WRITE commands.  These commands now
        // have a 120 second timeout, but the preferred behavior (and that
        // taken by many drives) is to immediately report 2/4/x on OPC and
        // similar commands.  Thus, retries must occur for at least 160
        // seconds (120 seconds + four 10 second retries) as a conservative
        // guess.
        //
        if (retry)
        {
            
            CDROM_DATA const * cdData = ((FUNCTIONAL_DEVICE_EXTENSION*)Fdo->DeviceExtension)->CommonExtension.DriverData;

            ASSERT(RequestHistory != NULL);
            if (total100nsUnitsSinceFirstSend < 0)
            {
                retry = (PreviousRetryCount <= TOTAL_COUNT_RETRY_DEFAULT);
            }
            else if (total100nsUnitsSinceFirstSend > SECONDS_TO_100NS_UNITS(TOTAL_SECONDS_RETRY_TIME_WRITE))
            {
                retry = FALSE;
            }
            else
            {
                NOTHING; // we'll keep the default.
            }

            //
            // How long should we request a delay for during writing?  This
            // depends entirely on the current write speed of the drive.  If we
            // request retries too quickly, we can overload the processor on the
            // drive (resulting in garbage being written), but too slowly results
            // in lesser performance.
            //
            // TODO: On write speed changes (SPT or otherwise), snoop to determine
            //       new write speed.
            //

            localRetryIn100nsUnits = cdData->ReadWriteRetryDelay100nsUnits;

        } // end retry for 160 seconds modification
    }
    else if (opCode == SCSIOP_GET_PERFORMANCE)
    {
        if (SRB_STATUS(Srb->SrbStatus) == SRB_STATUS_DATA_OVERRUN){
            /*
             *  This is a HACK.
             *  Atapi returns SRB_STATUS_DATA_OVERRUN when it really means
             *  underrun (i.e. success, and the buffer is longer than needed).
             *  So treat this as a success.
             *  When the caller of this function sees that the status was changed to success,
             *  it will add the transferred length to the original irp.
             */
            *Status = STATUS_SUCCESS;
            retry = FALSE;
        }

        // limit retries to GET_PERFORMANCE commands to default retry count
        if (PreviousRetryCount > TOTAL_COUNT_RETRY_DEFAULT)
        {
            retry = FALSE;
        }
    }
    else // default handler -- checks for retry count only.
    {
        if (PreviousRetryCount > TOTAL_COUNT_RETRY_DEFAULT)
        {
            retry = FALSE;
        }

    }

    // Finally, check if the original irp has been cancelled.  If so, do not
    // retry and set failure statuses to STATUS_CANCELLED instead of
    // continuing to retry....
    if ((!NT_SUCCESS(*Status))    && 
        (OriginalRequest != NULL) &&
        OriginalRequest->Cancel   &&
        retry
        )
    {
        DbgPrintEx(DPFLTR_CDROM_ID, DPFLTR_WARNING_LEVEL,
                   "Request %p was cancelled when it would have been retried\n",
                   OriginalRequest
                   );
        retry = FALSE;
        *Status = STATUS_REQUEST_CANCELED;
    }

    // Copy the retry time back to the caller
    *RetryIn100nsUnits = localRetryIn100nsUnits;

    if (retry)
    {
        DbgPrintEx(DPFLTR_CDROM_ID, DPFLTR_TRACE_LEVEL,
                   "Command shall be retried in %2I64d.%03I64d seconds\n",
                   (localRetryIn100nsUnits / 10000000),
                   (localRetryIn100nsUnits / 10000) % 1000
                   );
    }
    else
    {
        DbgPrintEx(DPFLTR_CDROM_ID, DPFLTR_WARNING_LEVEL,
                   "Will not retry; Sense/ASC/ASCQ of %02x/%02x/%02x\n",
                   sense.SenseKey,
                   sense.AdditionalSenseCode,
                   sense.AdditionalSenseCodeQualifier
                   );
    }
    return retry;
}

VOID
ValidateSrbHistoryDataPresumptions(
    __in     SRB_HISTORY const * RequestHistory
    )
{
#if DBG
    // validate that all fully-compressed items are before any non-fully-compressed items of any particular sense/asc/ascq
    // validate that there is at most one partially-compressed item of any particular sense/asc/ascq
    // validate that all items of any particular sense/asc/ascq that are uncompressed are at the end
    // THUS: A(255) A(255) A( 40) A(  0) A(  0) is legal for all types with A as sense/asc/ascq
    //       A(0)   B(255) A(  0) B( 17) B(  0) is also legal because A/B are different types of error

    ULONG i;
    for (i = 0; i < RequestHistory->UsedHistoryCount; i++)
    {
        SRB_HISTORY_ITEM const * toMatch = &( RequestHistory->History[i] );
        UCHAR const srbStatus = toMatch->SrbStatus;
        UCHAR const sense     = toMatch->NormalizedSenseData.SenseKey;
        UCHAR const asc       = toMatch->NormalizedSenseData.AdditionalSenseCode;
        UCHAR const ascq      = toMatch->NormalizedSenseData.AdditionalSenseCodeQualifier;
        ULONG j;

        BOOLEAN foundPartiallyCompressedItem =
            (toMatch->ClassDriverUse !=    0) &&
            (toMatch->ClassDriverUse != 0xFF) ;
        BOOLEAN foundUncompressedItem =
            (toMatch->ClassDriverUse ==    0) ;

        for (j = i+1; j < RequestHistory->UsedHistoryCount; j++)
        {
            SRB_HISTORY_ITEM const * found = &( RequestHistory->History[j] );
            if ((srbStatus == found->SrbStatus) &&
                (sense     == found->NormalizedSenseData.SenseKey) &&
                (asc       == found->NormalizedSenseData.AdditionalSenseCode) &&
                (ascq      == found->NormalizedSenseData.AdditionalSenseCodeQualifier)
                )
            {
                // found a matching type, so validate ordering rules
                if (foundUncompressedItem && (found->ClassDriverUse != 0))
                {
                    DbgPrintEx(DPFLTR_CDROM_ID, DPFLTR_ERROR_LEVEL,
                               "History data has compressed history following uncompressed history "
                               "for srbstatus/sense/asc/ascq of %02x/%02x/%02x/%02x at indices %d (%08x) and %d (%08x)\n",
                               srbStatus, sense, asc, ascq,
                               i,i, j,j
                               );
                    ASSERT(FALSE);
                }
                else if (foundPartiallyCompressedItem && (found->ClassDriverUse == 0xFF))
                {
                    DbgPrintEx(DPFLTR_CDROM_ID, DPFLTR_ERROR_LEVEL,
                               "History data has fully compressed history following partially compressed history "
                               "for srbstatus/sense/asc/ascq of %02x/%02x/%02x/%02x at indices %d (%08x) and %d (%08x)\n",
                               srbStatus, sense, asc, ascq,
                               i,i, j,j
                               );
                    ASSERT(FALSE);
                }

                // update if we have now found partially compressed and/or uncompressed items
                if (found->ClassDriverUse == 0)
                {
                    foundUncompressedItem = TRUE;
                }
                else if (found->ClassDriverUse != 0xFF)
                {
                    foundPartiallyCompressedItem = TRUE;
                }
            } // end match of (toMatch,found)
        } // end loop j
    } // end loop i
#endif
    return;
}

VOID
CompressSrbHistoryData(
    __in     PDEVICE_OBJECT DeviceObject,
    __inout  PSRB_HISTORY   RequestHistory
    )
{
    ULONG i;
    ASSERT( RequestHistory->UsedHistoryCount == RequestHistory->TotalHistoryCount );
    ValidateSrbHistoryDataPresumptions(RequestHistory);

    // TODO: scan for duplicates, and compress (up to 255) duplicate SENSE/ASC/ASCQ combinations
    //       save number of compressed into ClassDriverUse field...
    for (i=0; i < RequestHistory->UsedHistoryCount; i++)
    {
        // for each item...
        PSRB_HISTORY_ITEM toMatch = &( RequestHistory->History[i] );
        // hint: read const qualifiers backwards.  i.e. srbstatus is a const UCHAR
        // so, "UCHAR const * const x" is read "x is a const pointer to a const UCHAR"
        // unfortunately, "const UCHAR" is equivalent to "UCHAR const", which causes
        // people no end of confusion due to its widespread use.
        UCHAR const srbStatus = toMatch->SrbStatus;
        UCHAR const sense     = toMatch->NormalizedSenseData.SenseKey;
        UCHAR const asc       = toMatch->NormalizedSenseData.AdditionalSenseCode;
        UCHAR const ascq      = toMatch->NormalizedSenseData.AdditionalSenseCodeQualifier;
        ULONG j;

        // see if there are any at higher indices with identical Sense/ASC/ASCQ
        for (j = i+1; (toMatch->ClassDriverUse != 0xFF) && (j < RequestHistory->UsedHistoryCount); j++)
        {
            PSRB_HISTORY_ITEM found = &( RequestHistory->History[j] );
            // close enough match?
            if ((srbStatus == found->SrbStatus) &&
                (sense     == found->NormalizedSenseData.SenseKey) &&
                (asc       == found->NormalizedSenseData.AdditionalSenseCode) &&
                (ascq      == found->NormalizedSenseData.AdditionalSenseCodeQualifier)) {

                // add the fields to keep reasonable track of delay times.
                if (toMatch->MillisecondsDelayOnRetry + found->MillisecondsDelayOnRetry < toMatch->MillisecondsDelayOnRetry) {
                    toMatch->MillisecondsDelayOnRetry = MAXULONG;
                } else {
                    toMatch->MillisecondsDelayOnRetry += found->MillisecondsDelayOnRetry;
                }

                // this found item cannot contain any compressed entries because
                // the first entry with a given set of sense/asc/ascq will always
                // either be full (0xFF) or be the only partially-full entry with
                // that sense/asc/ascq.
                ASSERT(found->ClassDriverUse == 0);
                // add the counts so we still know how many retries total
                toMatch->ClassDriverUse++;


                // if not the last entry, need to move later entries earlier in the array
                if (j != RequestHistory->UsedHistoryCount-1) {
                    // how many entries remain?
                    SIZE_T remainingBytes = RequestHistory->UsedHistoryCount - 1 - j;
                    remainingBytes *= sizeof(SRB_HISTORY_ITEM);

                    // note that MOVE is required due to overlapping entries
                    RtlMoveMemory(found, found+1, remainingBytes);

                    // Finally, decrement the number of used history count and
                    // decrement j to rescan the current location again
                    --RequestHistory->UsedHistoryCount;
                    --j;
                } // end moving of array elements around
            } // end of close enough match
        } // end j loop
    } // end i loop 

    // unable to compress duplicate sense/asc/ascq, so just lose the most recent data
    if (RequestHistory->UsedHistoryCount == RequestHistory->TotalHistoryCount)
    {
        PSRB_HISTORY_ITEM item = &( RequestHistory->History[ RequestHistory->TotalHistoryCount-1 ] );
        RequestHistory->ClassDriverUse[0] += item->ClassDriverUse; // how many did we "lose"?
        RequestHistory->UsedHistoryCount--;
    }

    // finally, zero any that are no longer in use
    ASSERT( RequestHistory->UsedHistoryCount != RequestHistory->TotalHistoryCount);
    {
        SIZE_T bytesToZero = RequestHistory->TotalHistoryCount - RequestHistory->UsedHistoryCount;
        bytesToZero *= sizeof(SRB_HISTORY_ITEM);
        RtlZeroMemory(&(RequestHistory->History[RequestHistory->UsedHistoryCount]), bytesToZero);
    }

    ValidateSrbHistoryDataPresumptions(RequestHistory);
    return;
}



