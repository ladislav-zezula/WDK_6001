#include "..\..\sdv-pre-results.h"

#if (fdodriver_SDV_RESULT == SDV_PASSED && nonpurekmdfdriver_SDV_RESULT==SDV_NA)
   #define SDV_HARNESS SDV_HARNESS_PNP_IO_REQUESTS
#else
  #pragma message("SDV_NA")
#endif
