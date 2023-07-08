#ifndef _ALIGN_H
#define _ALIGN_H

/*
 * ByteAlign:-
 * The ByteAlign function is used to align any particular ptr etc.
 * on a specific BYTE boundary.
*/


__inline ULONG_PTR ByteAlign(ULONG_PTR Operand, ULONG_PTR Alignment)
{
    return ((Operand + (Alignment -1)) & ~(Alignment -1));
}


// ByteAlignNonZero:-
// Aligns a value to a specific BYTE boundary, 
// if the result is 0, return the minimum alignment.
__inline ULONG_PTR ByteAlignNonZero(ULONG_PTR Operand, ULONG_PTR Alignment)
{
    ULONG_PTR dwAligned = ((Operand + (Alignment -1)) & ~(Alignment -1));
    if (dwAligned == 0)
    {
        dwAligned = Alignment;
    }
    return dwAligned;
}

//This macro checks if a value is a power of two. 
__inline DWORD IsPowerOfTwo(DWORD dwValue)
{
 return ((dwValue & (dwValue-1)) == 0);
}

//This macro aligns a value to the next higher power of two. 
__inline DWORD AlignPowerOfTwo(DWORD dwValue)
{
    DWORD dwRet=1;

    dwValue--;
    
    while(dwValue)
    {
        dwValue >>= 1;
        dwRet <<= 1;
    }

    return dwRet;
}

#endif // _ALIGN_H

