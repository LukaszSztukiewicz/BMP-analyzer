#ifndef GRAYSCALE_CONVERTER_H
#define GRAYSCALE_CONVERTER_H
#include "bmp_header_info.h"
void convert_to_grayscale(FILE *file, FILE *outfile, BITMAPINFOHEADER *info_header, BITMAPFILEHEADER *file_header);
#endif