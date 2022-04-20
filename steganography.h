#ifndef STEGANOGRAPHY_H
#define STEGANOGRAPHY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "bmp_header_info.h"

unsigned char get_steg_char(FILE *file);
void write_steg_char(FILE *file, unsigned char message_length_dec);

void decode_steg(FILE *file, BITMAPFILEHEADER *file_header, BITMAPINFOHEADER *info_header);
void encode_steg(FILE *file, BITMAPFILEHEADER *file_header, BITMAPINFOHEADER *info_header, char *message);

#endif