#include "bmp_header_info.h"
#include "steganography.h"


int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "rb");
    FILE *outfile = fopen(argv[2], "wb");

    BITMAPFILEHEADER file_header;
    BITMAPINFOHEADER info_header;

    // parsing and printing file header
    parse_headers(file, &file_header, &info_header);
    // TODO: implement histogram
    switch (argc)
    {
    case 2:
        print_headers(&file_header, &info_header);
        // PRINT HISTOGRAM HERE
        printf("Decode steganography? [Y/n] ");
        while (1){
            char c = getchar();
            getchar();
            if (c == 'Y'){
                decode_steg(file, &file_header, &info_header);
                break;
            }
            else if (c == 'n'){
                break;
            }else{
                printf("Invalid input. Try again. ");
            }
        }
        break;
    case 3:
        // code for grayscale conversion 
        // TODO: implement grayscale conversion
        break;
    case 4:
        // STEGANOGRAPHY
        fseek(file, 0, SEEK_SET);
        fseek(outfile, 0, SEEK_SET);
        // copy the file header
        fwrite(&file_header, sizeof(BITMAPFILEHEADER), 1, outfile);
        // copy the info header
        fwrite(&info_header, sizeof(BITMAPINFOHEADER), 1, outfile);
        // copy the image data
        int size = info_header.biSizeImage;
        unsigned char *image_data = malloc(size);
        // handle allocation error
        if (image_data == NULL){
            printf("Error: malloc failed.\n");
            return 1;
        }
        fseek(file, file_header.bfOffBits, SEEK_SET);
        fseek(outfile, file_header.bfOffBits, SEEK_SET);
        fread(image_data, size, 1, file);
        fwrite(image_data, size, 1, outfile);
        free(image_data);
        encode_steg(outfile, &file_header, &info_header, argv[3]);
        break;
    default:
        printf("Invalid number of arguments\n");
        break;
    }
    fclose(outfile);
    fclose(file);
    return 0;
}