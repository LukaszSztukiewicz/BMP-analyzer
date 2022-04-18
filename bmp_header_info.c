#include "bmp_header_info.h"

void parse_headers(FILE *file, BITMAPFILEHEADER *file_header, BITMAPINFOHEADER *info_header) {
    fread(file_header, sizeof(BITMAPFILEHEADER), 1, file);
    fread(info_header, sizeof(BITMAPINFOHEADER), 1, file);
}
void print_headers(BITMAPFILEHEADER *file_header, BITMAPINFOHEADER *info_header) {
    printf("BITMAPFILEHEADER:\n");
    switch (file_header->bfType) {
        case 0x4D42:
            printf("\tbfType: 0x4D42 (BM)\n");
            break;
        case 0x4D5A:
            printf("\tbfType: 0x4D5A Zipped Bitmap\n");
            break;
        default:
            printf("\tbfType: Unknown\n");
            break;
    }
    printf("\tbfSize: %d\n", file_header->bfSize);
    printf("\tbfReserved1: %x\n", file_header->bfReserved1);
    printf("\tbfReserved2: %x\n", file_header->bfReserved2);
    printf("\tbfOffBits: %d\n", file_header->bfOffBits);
    printf("BITMAPINFOHEADER:\n");
    printf("\tbiSize: %d\n", info_header->biSize);
    printf("\tbiWidth: %d\n", info_header->biWidth);
    printf("\tbiHeight: %d\n", info_header->biHeight);
    printf("\tbiPlanes: %d\n", info_header->biPlanes);
    printf("\tbiBitCount: %d\n", info_header->biBitCount);
    printf("\tbiCompression: %d\n", info_header->biCompression);
    printf("\tbiSizeImage: %d\n", info_header->biSizeImage);
    printf("\tbiXPelsPerMeter: %d\n", info_header->biXPelsPerMeter);
    printf("\tbiYPelsPerMeter: %d\n", info_header->biYPelsPerMeter);
    printf("\tbiClrUsed: %d\n", info_header->biClrUsed);
    printf("\tbiClrImportant: %d\n", info_header->biClrImportant);
}