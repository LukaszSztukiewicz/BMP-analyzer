#ifndef GRAYSCALE_CONVERTER_H
#define GRAYSCALE_CONVERTER_H
#include "bmp_header_info.h"
#include "bucket_histogram.h"

void convert_to_grayscale(FILE *file, FILE *outfile, bucket_BGR *buckets, BITMAPINFOHEADER *info_header, BITMAPFILEHEADER *file_header);
#endif