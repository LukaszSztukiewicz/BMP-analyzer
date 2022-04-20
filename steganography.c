#include "steganography.h"

unsigned char get_steg_char(FILE *file){
    unsigned char message_length_dec = 0;
    for (int i = 7; i >= 0; i--){
        message_length_dec += (fgetc(file) & 1) << i;
    }
    return message_length_dec;
}

void write_steg_char(FILE *file, unsigned char message_length_dec){
    for (int i = 7; i >= 0; i--){
        fputc((message_length_dec >> i) & 1, file);
    }
}

void decode_steg(FILE *file, BITMAPFILEHEADER *file_header, BITMAPINFOHEADER *info_header){
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

void encode_steg(FILE *file, BITMAPFILEHEADER *file_header, BITMAPINFOHEADER *info_header, char *message){
    fseek(file, file_header->bfOffBits, SEEK_SET);
    unsigned char length = strlen(message);
    if (length > 255){
        printf("Error: message too long.\n");
        return;
    }
    write_steg_char(file, length);
    for (int i = 0; i < length; i++){
        write_steg_char(file, message[i]);
    }
    printf("Message encoded.\n");
}
