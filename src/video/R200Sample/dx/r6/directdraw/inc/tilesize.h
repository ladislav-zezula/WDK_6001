
#ifndef TILESIZE_H
#define TILESIZE_H

typedef struct
{
    DWORD  dwHeight;  // lines
    DWORD  dwWidth;   // bytes
} TILESIZE;

#define MICROTILE_8BPP   0
#define MICROTILE_16BPP  1
#define MICROTILE_32BPP  2
#define MICROTILE_DXT1   3
#define MICROTILE_DXT2   4
#define MICROTILE_DXT3   4
#define MICROTILE_DXT4   4
#define MICROTILE_DXT5   4  

__inline DWORD GetMicroTileSizeIndex(LPDDPIXELFORMAT lpDDPF)
{
  if (lpDDPF->dwFlags & DDPF_FOURCC)
  {
    switch (lpDDPF->dwFourCC)
    {
    case FOURCC_DXT1:        return MICROTILE_DXT1;
    case FOURCC_DXT2:        return MICROTILE_DXT2;
    case FOURCC_DXT3:        return MICROTILE_DXT3;
    case FOURCC_DXT4:        return MICROTILE_DXT4;
    case FOURCC_DXT5:        return MICROTILE_DXT5;
    case FOURCC_YUY2:        return MICROTILE_16BPP;
    case FOURCC_UYVY:        return MICROTILE_16BPP;
    case D3DFMT_V16U16:      return MICROTILE_32BPP;
    case D3DFMT_Q8W8V8U8:    return MICROTILE_32BPP;
#if (DIRECT3D_VERSION >= 0x0900)
    case D3DFMT_A8B8G8R8:    return MICROTILE_32BPP;
    case D3DFMT_X8B8G8R8:    return MICROTILE_32BPP;
#endif //(DIRECT3D_VERSION)
    case D3DFMT_W11V11U10:   return MICROTILE_32BPP;
    case D3DFMT_A2W10V10U10: return MICROTILE_32BPP;
    case D3DFMT_A2B10G10R10: return MICROTILE_32BPP;
    }

    return 0;
  }
  else if (lpDDPF->dwFlags & DDPF_BUMPDUDV)    //It's a bump map
  {
    switch (lpDDPF->dwBumpBitCount)
    {
    case 8:  return MICROTILE_8BPP;
    case 16: return MICROTILE_16BPP;
    case 32: return MICROTILE_32BPP;
    }
  }
  else // RGB
  {
    switch (lpDDPF->dwRGBBitCount)
    {
    case 8:  return MICROTILE_8BPP;
    case 16: return MICROTILE_16BPP;
    case 32: return MICROTILE_32BPP;
    }
  }

  return 0;
}

__inline DWORD GetMacroTileSize(DWORD dwMicroTileEnabled, DWORD *dwWidth, DWORD *dwHeight)
{
    if(dwMicroTileEnabled)
    {
        *dwWidth = 128;
        *dwHeight = 8;
    }
    else
    {
        *dwWidth = 256;
        *dwHeight = 4;
    }
}

#endif /* TILESIZE_H */

