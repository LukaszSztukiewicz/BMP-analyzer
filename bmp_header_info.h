#ifndef BMP_HEADER_INFO_H
#define BMP_HEADER_INFO_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint16_t WORD;
typedef uint32_t DWORD;
typedef int32_t LONG;

// pack the structs (memory alignment change) with pragma pack
#pragma pack(push, 1)
// https://docs.microsoft.com/en-us/windows/win32/api/wingdi/ns-wingdi-bitmapfileheader
typedef struct tagBITMAPFILEHEADER {
  WORD bfType;
  DWORD bfSize;
  WORD bfReserved1;
  WORD bfReserved2;
  DWORD bfOffBits;
} BITMAPFILEHEADER, *LPBITMAPFILEHEADER, *PBITMAPFILEHEADER;
#pragma pack(pop)

#pragma pack(push, 1)
// https://docs.microsoft.com/pl-pl/previous-versions/dd183376(v=vs.85)
typedef struct tagBITMAPINFOHEADER {
  DWORD biSize;
  LONG biWidth;
  LONG biHeight;
  WORD biPlanes;
  WORD biBitCount;
  DWORD biCompression;
  DWORD biSizeImage;
  LONG biXPelsPerMeter;
  LONG biYPelsPerMeter;
  DWORD biClrUsed;
  DWORD biClrImportant;
} BITMAPINFOHEADER, *LPBITMAPINFOHEADER, *PBITMAPINFOHEADER;
#pragma pack(pop)

void parse_headers(FILE *file, BITMAPFILEHEADER *file_header, BITMAPINFOHEADER *info_header);

void print_headers(BITMAPFILEHEADER *file_header, BITMAPINFOHEADER *info_header);

#endif
