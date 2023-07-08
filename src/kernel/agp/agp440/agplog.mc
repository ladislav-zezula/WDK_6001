;/*++ BUILD Version: 0001    // Increment this if a change has global effects
;
;Copyright (c) 1997  Microsoft Corporation
;
;Module Name:
;
;    agplog.mc
;
;Abstract:
;
;    Internationalizable descriptions of AGP devices based on Base Class
;    and Sub Class.
;
;Author:
;
;
;Revision History:
;
;--*/
;
;//
;//  Status values are 32 bit values layed out as follows:
;//
;//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
;//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
;//  +---+-+-------------------------+-------------------------------+
;//  |Sev|C|       Facility          |               Code            |
;//  +---+-+-------------------------+-------------------------------+
;//
;//  where
;//
;//      Sev - is the severity code
;//
;//          00 - Success
;//          01 - Informational
;//          10 - Warning
;//          11 - Error
;//
;//      C - is the Customer code flag
;//
;//      Facility - is the facility code
;//
;//      Code - is the facility's status code
;//
;//
MessageIdTypedef=ULONG

SeverityNames=(Success=0x0:STATUS_SEVERITY_SUCCESS
               Informational=0x1:STATUS_SEVERITY_INFORMATIONAL
               Warning=0x2:STATUS_SEVERITY_WARNING
               Error=0x3:STATUS_SEVERITY_ERROR
              )

FacilityNames=(Agp=0x0
              )

MessageId=0x0000 Facility=Agp Severity=Error SymbolicName=AGP_FAILED_TLB_FLUSHING_VERIFIFICATION
Language=English
Chipset failed validation of AGP TLB flushing functionnality; disabling AGP.
.

MessageId=0x0001 Facility=Agp Severity=Success SymbolicName=AGP_FAILED_CHIPSET_CACHE_FLUSHING_VERIFICATION
Language=English
Chipset failed validation of chipset cache (posted write buffer) flushing functionnality; disabling AGP.
.


