
#include "..\..\sdv-pre-results.h"
#if (nonpurekmdfdriver_SDV_RESULT == SDV_NA)
   #define SDV_HARNESS SDV_HARNESS_DRIVER_CREATE
   #define init_free 1
#else
  #pragma message("SDV_NA")  
#endif
