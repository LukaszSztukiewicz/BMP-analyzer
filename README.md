# BMP Analyzer

Color distribution analyzer, grayscale-to converter and steganography tool.

Written entirely in C language.

Created by Łukasz Sztukiewicz & Michał Wiliński.

- Formatter: [Clang 15.0.0](https://clang.llvm.org/docs/ClangFormatStyleOptions.html)
- Compiled with: gcc -g -Wall -Wextra *.c -o main
- Tested against Valgrind

## Usage

### Input formats:
Printing parsed information headers from BMP file and histogram of RGB colors
  

    $ ./program PATH-TO-BMP-FILE

Converting BMP file to grayscale

     $ ./program PATH-TO-INPUT-BMP-FILE PATH-TO-OUTPUT-BMP-FILE

Steganography: hide a text inside BMP pixel array

     $ ./program PATH-TO-INPUT-BMP PATH-TO-ENCODED-BMP "text to be hidden"

Steganography: decode hidden text inside BMP pixel array

     $ ./program PATH-TO-ENCODED-BMP

> BITMAPFILEHEADER
> 
>  ...
> 
> BITMAPINFOHEADER
> 
>  ...
> 
> RGB histogram
> 
> ...
> 
> Decode steganography? [Y/n]
> 
> hidden text

### Examples