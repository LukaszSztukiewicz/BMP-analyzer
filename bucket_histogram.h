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
  // number of pixels in the bucket from each color
  struct colors{
    uint32_t nBlue;
    uint32_t nGreen;
    uint32_t nRed;
  }
  uint32_t arr[3];
} bucket_BGR;
#pragma pack(pop)

void parse_bucket_histogram(FILE *file, struct bucket_BGR buckets[], BITMAPINFOHEADER , BITMAPFILEHEADER);
void print_bucket_histogram(struct bucket_BGR buckets[], BITMAPINFOHEADER);