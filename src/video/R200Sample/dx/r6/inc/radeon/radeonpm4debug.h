#ifndef _RADEON_PM4DEBUG_H_
#define _RADEON_PM4DEBUG_H_

#include "radeon.h"

// Include the appropriate ASIC header files
#if (RADEON_ASIC < 0x300) // Radeon2/Chaplin/Rage6X

#include "radeon2\chaplin_bf_dump.h"
#include "radeon2\chaplin_pm4debug.h"

#endif // Radeon Builds

#endif //_PM4DEBUG_H_

