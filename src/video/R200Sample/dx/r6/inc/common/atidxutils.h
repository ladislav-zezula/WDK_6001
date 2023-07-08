#ifndef _ATIDXUTILS_H_
#define _ATIDXUTILS_H_


////////////////////////////////////////////////////////////////////////
// DwSizeOf
////////////////////////////////////////////////////////////////////////
#define DwSizeOf(item)  (sizeof(item)>>2)


////////////////////////////////////////////////////////////////////////
//
// void AtiDwordCopy
//
////////////////////////////////////////////////////////////////////////
__inline void AtiDwordCopy(LPDWORD pdwDest, LPDWORD pdwSrc, DWORD dwDwords )
{
#ifndef _WIN64
  _asm
  {
    mov ecx, dwDwords
    mov esi, pdwSrc
    mov edi, pdwDest
    rep movsd
  }
#else
  // Another compatible optimization needs to
  // be done for WIN64.
  memcpy( pdwDest, pdwSrc, dwDwords << 2 );
#endif
}

#endif // _ATIDXUTILS_H_

