#include "bucket_histogram.h"
#include <string.h>

void parse_bucket_histogram(FILE *file, struct bucket_BGR buckets[], BITMAPINFOHEADER info_header, BITMAPFILEHEADER file_header) {
  fseek(file, bfOffBits, SEEK_SET);
  struct pixel_BGR pixel;
  int n_pixels        = info_header.biWidth * info_header.biHeight;
  int row_size        = ((info_header.biWidth * info_header.biBitCount + 31) / 32) * 4;
  int n_pixels_in_row = (row_size / sizeof(struct pixel_BGR));
  for (size_t i = 0; i < info_header.biHeight; i++) {
    for (size_t j = 0; j < n_pixels_in_row; j++) {
      fread(&pixel, sizeof(struct pixel_BGR), 1, file);
      buckets[pixel.blue / 16].nBlue++;
      buckets[pixel.green / 16].nGreen++;
      buckets[pixel.red / 16].nRed++;
    }
    fseek(file, row_size - n_pixels_in_row * sizeof(struct pixel_BGR), SEEK_CUR);
  }
}

void print_bucket_histogram(struct bucket_BGR buckets[], BITMAPINFOHEADER info_header) {
  printf("HISTOGRAM:\n");
  int offset            = 16;
  int bucket_start      = 0;
  int bucket_end        = 15;
  const char *colors[3] = {"Blue", "Green", "Red"};
  for (size_t k = 0; k < 3; k++) {
    printf("\t %s: \n", colors[k]);
    for (int i = 0; i < offset; i++) {
      printf("\t\t%d-%d: %.2f%%\n", bucket_start + i * offset, bucket_end + i * offset, ((float)buckets[i][k] * 100) / n_pixels);
    }
  }
}