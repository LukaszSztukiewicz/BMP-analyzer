#include "bmp_header_info.h"
#include "bucket_histogram.h"

int main(int argc, char *argv[]) {
  FILE *file = fopen(argv[1], "rb");

  BITMAPFILEHEADER file_header;
  BITMAPINFOHEADER info_header;

  // parsing and printing file header
  parse_headers(file, &file_header, &info_header);
  print_headers(&file_header, &info_header);

  // check if the file is an uncompressed BMP
  if (info_header.biCompression != 0 || info_header.biBitCount != 24) {
    printf("This program can only handle uncompressed 24-bit BMP files.\n");
    return 1;
  }

  // all members initialized to zeros by providing expilcit curly braces
  int n_pixels                  = info_header.biWidth * info_header.biHeight;
  struct bucket_BGR buckets[16] = {};

  parse_bucket_histogram(file, buckets, n_pixels);
  print_bucket_histogram(buckets, n_pixels);

  switch (argc) {
  case 2:
    printf("Decode steganography? [Y/n] ");
    while (1) {
      char c = getchar();
      getchar();
      if (c == 'Y') {
        printf("Decoding not implemented yet\n");
        break;
      } else if (c == 'n') {
        break;
      } else {
        printf("Invalid input. Try again.\n");
      }
    }
    break;
  case 3:
    // code for grayscale conversion
    // TODO: implement grayscale conversion
    break;
  case 4:
    // code for steganography
    // TODO: implement steganography encoder
    break;
  default:
    printf("Invalid number of arguments\n");
    break;
  }
  fclose(file);
  return 0;
}