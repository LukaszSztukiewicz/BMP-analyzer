#include "bmp_header_info.h"
#include "bucket_histogram.h"
#include "grayscale_converter.h"
#include "steganography.h"

int main(int argc, char *argv[]) {
  FILE *file    = fopen(argv[1], "rb");
  FILE *outfile = fopen(argv[2], "wb");

  BITMAPFILEHEADER file_header;
  BITMAPINFOHEADER info_header;

  // parsing and printing file header
  parse_headers(file, &file_header, &info_header);

  switch (argc) {
  case 2:
    print_headers(&file_header, &info_header);

    // check if the file is an uncompressed BMP
    if (info_header.biCompression != 0 || info_header.biBitCount != 24) {
      printf("This program can only handle uncompressed 24-bit BMP files.\n");
      return 1;
    }

    // all members initialized to zeros by providing expilcit curly braces
    bucket_BGR buckets[16] = {};
    parse_bucket_histogram(file, buckets, &info_header, &file_header);
    print_bucket_histogram(buckets, &info_header);

    printf("Decode steganography? [Y/n] ");
    while (1) {
      char c = getchar();
      getchar();
      if (c == 'Y') {
        decode_steg(file, &file_header);
        break;
      } else if (c == 'n') {
        break;
      } else {
        printf("Invalid input. Try again. ");
      }
    }
    break;

  case 3:
    // code for grayscale conversion
    fseek(file, 0, SEEK_SET);
    fseek(outfile, 0, SEEK_SET);
    fwrite(&file_header, sizeof(BITMAPFILEHEADER), 1, outfile);
    fwrite(&info_header, sizeof(BITMAPINFOHEADER), 1, outfile);

    convert_to_grayscale(file, outfile, &info_header, &file_header);

    fclose(outfile);
    break;

  case 4:
    // STEGANOGRAPHY
    fseek(file, 0, SEEK_SET);
    fseek(outfile, 0, SEEK_SET);
    fwrite(&file_header, sizeof(BITMAPFILEHEADER), 1, outfile);
    fwrite(&info_header, sizeof(BITMAPINFOHEADER), 1, outfile);
    encode_steg(file, outfile, &file_header, argv[3]);

    char buffer[1024];
    while (fread(buffer, sizeof(char), 1024, file) > 0) {
      fwrite(buffer, sizeof(char), 1024, outfile);
    }
    fclose(outfile);
    break;

  default:
    printf("Invalid number of arguments\n");
    break;
  }
  fclose(file);
  return 0;
}