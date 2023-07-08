
#ifndef _OFFSETPITCH_H
#define _OFFSETPITCH_H
//
// For Rage 5, the offset is in units of 1Kb, and the pitch is
// in units of 64 bytes.  Furthermore, the offset field is
// 22 bits wide, and the pitch field is 8 bits wide.  In the R128,
// the offset is only 21 bits wide, and the pitch is 10 bits wide.
// The Rage 5 has two tile bits, one for macrotiling and one for
// microtiling.
//
#define PM4_R5_DST_PITCH_OFFSET(MTile,uTile,offset, pitch) \
    ((((offset) >> 10) & ((1 << 22) - 1))                  \
     | ((((pitch) >> 6) & ((1 << 8) - 1)) << 22)           \
     | (((uTile) & 0x1) << 30)                             \
     | (((MTile) & 0x1) << 31))


//
// This function calculates tile/utile/offset/pitch register
// values when antialiasing is enabled.
//

#endif // _OFFSETPITCH_H
