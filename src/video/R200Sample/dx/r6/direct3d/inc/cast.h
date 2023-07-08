
#ifndef _CAST_H
#define _CAST_H

// use this macro to cast one type to another while keeping the same bits
// Do not use this if you want integer 123 to become float 123.0 or other similar
// casts

#define SAMEBITS_CAST(new_type,old_object) (*((new_type *)&old_object))

#endif _CAST_H
