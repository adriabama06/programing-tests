typedef struct rgb_struct
{
    unsigned int r;
    unsigned int g;
    unsigned int b;
} rgb;


typedef struct image_struct
{
    unsigned int width;
    unsigned int height;
    rgb* pixels;
} image;

// i use unsigned because you in 2022 i don't know about negative colors or negative resolutions

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    image* img = (image*) malloc(sizeof(image));


    FILE* file_to_save = fopen("image.bin", "rb");

    
    fread(&img->width, sizeof(unsigned int), 1, file_to_save);
    fread(&img->height, sizeof(unsigned int), 1, file_to_save);


    unsigned int pixels_len;
    fread(&pixels_len, sizeof(unsigned int), 1, file_to_save);

    img->pixels = (rgb*) malloc(pixels_len); 

    fread(img->pixels, pixels_len, 1, file_to_save);

    
    fclose(file_to_save);

    unsigned int size = img->width * img->height;

    printf("Read:\nWidth : %u\nHeight : %u\n", img->width, img->height);

    // for check is all ok
    for (unsigned int i = 0; i < size; i++)
    {
        rgb pixel = img->pixels[i];
        printf("rgb(%d, %d, %d)\n", pixel.r, pixel.g, pixel.b);
    }

    return 0;
}