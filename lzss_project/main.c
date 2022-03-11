#include "lzss.h"
#include <stdio.h>
#include <time.h>

void printbincharpad(char c) {
    for (int i = 7; i >= 0; --i) {
        putchar((c & (1 << i)) ? '1' : '0');
    }
//    putchar(' ');
}

void readFile(char *fileName) {
    FILE *file;
    char c;
    file = fopen(fileName, "rb");
    while ((c = fgetc(file)) != EOF) {
        printbincharpad(c);
    }
    printbincharpad(c);
    while ((c = fgetc(file)) != EOF) {
        printbincharpad(c);
    }
}

void delete(char *filename) {
    FILE *srcFile;
    FILE *destFile;
    char c;
    srcFile = fopen(filename, "r");
//    destFile = fopen("../text/sam/sam_copy.txt", "w");
    while ((c = fgetc(srcFile)) != EOF) {
        printf("%d ", c);
//        if (c != '\r')
//            putc(c, destFile);
    }
//    putc(c, destFile);
}

int main(int argc, char **argv) {
    int ret, encode = 1;
    clock_t start, end;
    char *filesArray[6] = {
//            "../text/pitches/pitches.50MB",
//            "../text/dna/dna.50MB",
            "../text/sam/sam.txt",
            "../text/sam/sam_copy.txt",
//            "../text/english/english.50MB",
//            "../text/proteins/proteins.50MB",
//            "../text/sources/sources.50MB",
//            "../text/xml/xml.50MB"
    };
    char *decodedFilesArray[6] = {
//            "../text/pitches/decode_output",
//            "../text/dna/decode_output",
//            "../text/english/decode_output",
            "../text/sam/decode_output.txt",
//            "../text/proteins/decode_output",
//            "../text/sources/decode_output",
//            "../text/xml/decode_output"
    };
    char *encodedFilesArray[6] = {
//            "../text/pitches/encode_output",
//            "../text/dna/encode_output",
//            "../text/english/encode_output",
            "../text/sam/encode_output.txt",
//            "../text/proteins/encode_output",
//            "../text/sources/encode_output",
//            "../text/xml/encode_output"
    };
//    printbincharpad('I');
//    printf("\n");
//    readFile(encodedFilesArray[0]);
    FILE *originalFile, *encodedFile, *decodedFile;

//    delete(filesArray[0]);
//    printf("\n");
//    delete(filesArray[1]);
    for (int i = 0; i < 0; ++i) {
        if (encode) {
            originalFile = fopen(filesArray[i], "rb");
            encodedFile = fopen(encodedFilesArray[i], "wb");
            start = clock();
            ret = EncodeLZSS(originalFile, encodedFile);
            end = clock();
            if (ret != 0)
                fputs("error in decoding\n", stderr);
            fseek(originalFile, 0L, SEEK_END);
            long originalFileSize = ftell(originalFile);
            fseek(encodedFile, 0L, SEEK_END);
            long encodedFileSize = ftell(encodedFile);
            double compressionRatio = (double) encodedFileSize / (double) originalFileSize;
            printf("\033[0;32m");
            printf("%s\n", filesArray[i] + 8);
            printf("\033[0;37m");
            printf("Input file size: %20ld\n", originalFileSize);
            printf("compressed file size: %15ld\n", encodedFileSize);
            printf("compression ratio: %15.2lf%%\n", compressionRatio * 100);
            printf("compression time: %15.2lf sec\n", ((double) (end - start)) / CLOCKS_PER_SEC);

            fclose(originalFile);
            fclose(encodedFile);
        } else {
            encodedFile = fopen(encodedFilesArray[i], "rb");
            decodedFile = fopen(decodedFilesArray[i], "wb");
            start = clock();
            ret = DecodeLZSS(encodedFile, decodedFile);
            end = clock();
            if (ret != 0)
                fputs("error in encoding\n", stderr);
            printf("\033[0;32m");
            printf("%s\n", filesArray[i] + 8);
            printf("\033[0;37m");
            printf("decompression time: %15.2lf sec\n", ((double) (end - start)) / CLOCKS_PER_SEC);

            fclose(encodedFile);
            fclose(decodedFile);
        }
        printf("\n");
    }
    readFile(encodedFilesArray[0]);
    return ret;
}
