#include "steganography.h"

unsigned char get_steg_char(FILE *file){
    unsigned char message_length_dec = 0;
    for (int i = 7; i >= 0; i--){
        message_length_dec += (fgetc(file) & 1) << i;
    }
    return message_length_dec;
}

void write_steg_char(FILE *file, FILE *outfile, unsigned char message){
    for (int i = 7; i >= 0; i--){
        unsigned char curr_byte = fgetc(file);
        fputc((curr_byte & 0xFE) | ((message >> i) & 1), outfile);
    }
}

void decode_steg(FILE *file, BITMAPFILEHEADER *file_header){
    fseek(file, file_header->bfOffBits, SEEK_SET);
    unsigned char length = get_steg_char(file);
    char *message = malloc(length + 1);
    if (message == NULL){
        printf("Error: malloc failed.\n");
        return;
    }
    for (int i = 0; i < length; i++){
        message[i] = get_steg_char(file);
    }
    message[length] = '\0';
    printf("Message: %s\n", message);
    free(message);
}

void encode_steg(FILE *file, FILE *outfile, BITMAPFILEHEADER *file_header, char *message){
    fseek(file, file_header->bfOffBits, SEEK_SET);
    fseek(outfile, file_header->bfOffBits, SEEK_SET);
    unsigned char length = strlen(message);
    write_steg_char(file, outfile, length);
    for (int i = 0; i < length; i++){
        write_steg_char(file, outfile,  message[i]);
    }
    printf("Message encoded.\n");
}
