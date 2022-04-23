#ifndef STEGANOGRAPHY_H
#define STEGANOGRAPHY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "bmp_header_info.h"

unsigned char get_steg_char(FILE *file);
void write_steg_char(FILE *file, FILE *outfile, unsigned char message);

void decode_steg(FILE *file, BITMAPFILEHEADER *file_header);
void encode_steg(FILE *file, FILE *outfile, BITMAPFILEHEADER *file_header, char *message);

#endif