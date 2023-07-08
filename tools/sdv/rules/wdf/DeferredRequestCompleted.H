#include "..\..\sdv-pre-results.h"

#if (aliaswithintimerdpc_SDV_RESULT == SDV_PASSED && aliaswithindispatch_SDV_RESULT == SDV_PASSED && nonpurekmdfdriver_SDV_RESULT == SDV_NA)
   #define SDV_HARNESS SDV_HARNESS_PNP_DEFERRED_IO_REQUESTS
#else
  #pragma message("SDV_NA")
#endif




