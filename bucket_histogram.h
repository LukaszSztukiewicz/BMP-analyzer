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
typedef struct bucket_BGR {
  // number of pixels in the bucket from each color
  uint32_t nBlue;
  uint32_t nGreen;
  uint32_t nRed;
} bucket_BGR;
#pragma pack(pop)

void parse_bucket_histogram(FILE *file, struct bucket_BGR buckets[], int n_pixles, int bfOffBits, int bufferSize);
void print_bucket_histogram(struct bucket_BGR buckets[], int n_pixles);