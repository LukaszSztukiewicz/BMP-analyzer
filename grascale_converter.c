#include "bmp_header_info.h"
#include "bucket_histogram.h"
#include "grayscale_converter.h"
#include <string.h>

void convert_to_grayscale(FILE *file, FILE *outfile, BITMAPINFOHEADER *info_header, BITMAPFILEHEADER *file_header) {
  fseek(file, file_header->bfOffBits, SEEK_SET);
  fseek(outfile, file_header->bfOffBits, SEEK_SET);

  struct pixel_BGR pixel;
  int row_size        = ((info_header->biWidth * info_header->biBitCount + 31) / 32) * 4;
  int n_pixels_in_row = (row_size / sizeof(struct pixel_BGR));
  int pad_size        = row_size - (n_pixels_in_row * sizeof(struct pixel_BGR));

  for (LONG i = 0; i < info_header->biHeight; i++) {
    for (LONG j = 0; j < n_pixels_in_row; j++) {
      fread(&pixel, sizeof(struct pixel_BGR), 1, file);
      uint8_t gray = (pixel.blue + pixel.green + pixel.red) / 3;
      pixel.blue   = gray;
      pixel.green  = gray;
      pixel.red    = gray;
      fwrite(&pixel, sizeof(struct pixel_BGR), 1, outfile);
    }
    fseek(file, pad_size, SEEK_CUR);
    fseek(outfile, pad_size, SEEK_CUR);
  }
}
