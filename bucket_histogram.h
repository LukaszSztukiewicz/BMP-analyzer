#ifndef BUCKET_HISTOGRAM_H
#define BUCKET_HISTOGRAM_H
#include "bmp_header_info.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1)
typedef struct pixel_BGR {
  uint8_t blue;
  uint8_t green;
  uint8_t red;
} pixel_BGR;
#pragma pack(pop)

#pragma pack(push, 1)
typedef union bucket_BGR {
  struct colors {
    uint32_t nBlue, nGreen, nRed;
  } colors;
  uint32_t color_array[3];
} bucket_BGR;
#pragma pack(pop)

void parse_bucket_histogram(FILE *file, bucket_BGR *buckets, BITMAPINFOHEADER *info_header, BITMAPFILEHEADER *file_header);
void print_bucket_histogram(bucket_BGR *buckets, BITMAPINFOHEADER *info_header);

#endif