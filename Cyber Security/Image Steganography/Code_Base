#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encode text into an image
void encode(char *image_path, char *text) {
    FILE *fp = fopen(image_path, "rb+");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    fseek(fp, 0, SEEK_END);
    long image_size = ftell(fp);
    rewind(fp);

    char *image_data = (char *)malloc(image_size * sizeof(char));
    fread(image_data, 1, image_size, fp);

    // Embed text into LSB (Least Significant Bit) of image pixels
    int text_len = strlen(text);
    int text_index = 0;

    for (int i = 0; i < image_size; ++i) {
        if (text_index >= text_len) break;

        // Embed text into LSB of image_data[i]
        image_data[i] = (image_data[i] & 0xFE) | ((text[text_index] >> 7) & 0x01);
        ++i;

        if (text_index >= text_len) break;
        image_data[i] = (image_data[i] & 0xFE) | ((text[text_index] >> 6) & 0x01);
        ++i;

        if (text_index >= text_len) break;
        image_data[i] = (image_data[i] & 0xFE) | ((text[text_index] >> 5) & 0x01);
        ++i;

        if (text_index >= text_len) break;
        image_data[i] = (image_data[i] & 0xFE) | ((text[text_index] >> 4) & 0x01);
        ++i;

        if (text_index >= text_len) break;
        image_data[i] = (image_data[i] & 0xFE) | ((text[text_index] >> 3) & 0x01);
        ++i;

        if (text_index >= text_len) break;
        image_data[i] = (image_data[i] & 0xFE) | ((text[text_index] >> 2) & 0x01);
        ++i;

        if (text_index >= text_len) break;
        image_data[i] = (image_data[i] & 0xFE) | ((text[text_index] >> 1) & 0x01);
        ++i;

        if (text_index >= text_len) break;
        image_data[i] = (image_data[i] & 0xFE) | (text[text_index] & 0x01);
        ++i;

        ++text_index;
    }

    rewind(fp);
    fwrite(image_data, 1, image_size, fp);

    free(image_data);
    fclose(fp);
}

// Function to decode text from an image
void decode(char *image_path) {
    FILE *fp = fopen(image_path, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    fseek(fp, 0, SEEK_END);
    long image_size = ftell(fp);
    rewind(fp);

    char *image_data = (char *)malloc(image_size * sizeof(char));
    fread(image_data, 1, image_size, fp);

    fclose(fp);

    // Extract text from LSB (Least Significant Bit) of image pixels
    int text_len = 0;
    char extracted_text[1000] = {0}; // Assuming maximum text length of 1000 characters

    for (int i = 0; i < image_size; ++i) {
        if (text_len >= 1000) break;

        char bit = image_data[i] & 0x01;
        extracted_text[text_len] = (extracted_text[text_len] << 1) | bit;

        if ((i + 1) % 8 == 0) ++text_len;
    }

    printf("Extracted text: %s\n", extracted_text);

    free(image_data);
}

int main() {
    char image_path[] = "image.png";
    char text_to_hide[] = "Hello, this is a secret message hidden in an image!";

    // Encode text into the image
    encode(image_path, text_to_hide);

    // Decode text from the image
    decode(image_path);

    return 0;
}
