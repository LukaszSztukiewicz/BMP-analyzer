#include "bmp_header_info.h"

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "rb");

    BITMAPFILEHEADER file_header;
    BITMAPINFOHEADER info_header;

    // parsing and printing file header
    parse_headers(file, &file_header, &info_header);
    print_headers(&file_header, &info_header);

    // histogram
    // TODO: implement histogram
    switch (argc)
    {
    case 2:
        printf("Decode steganography? [Y/n] ");
        while (1){
            char c = getchar();
            getchar();
            if (c == 'Y'){
                printf("Decoding not implemented yet\n");
                break;
            }
            else if (c == 'n'){
                break;
            }else{
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