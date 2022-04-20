#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1)
typedef struct pixel_BGR {
  uint8_t blue;
  uint8_t green;
  uint8_t red;
};
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct bucket_BGR {
  // number of pixels in the bucket from each color
  // colors are in order of blue, green, red
  // each bucket contains 16 consecutive values i.e first 0-15, then 16-31, etc
  uint32_t nBlue;
  uint32_t nGreen;
  uint32_t nRed;
};
#pragma pack(pop)

void parse_bucket_histogram(FILE *file, struct bucket_BGR *buckets);
void print_bucket_histogram(struct bucket_BGR *buckets);