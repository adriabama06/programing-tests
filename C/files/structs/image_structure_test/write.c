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

    img->width = 4;
    img->height = 4;
    unsigned int size = img->width * img->height;

    img->pixels = (rgb*) malloc(size * sizeof(rgb)); 

    rgb a;
    a.r = 0;
    a.g = 0;
    a.b = 0;

    rgb b;
    b.r = 255;
    b.g = 255;
    b.b = 255;

    for (int i = 0; i < size; i++)
    {
        if((i % 2) == 0)
        {
            img->pixels[i] = a;
        }
        else
        {
            img->pixels[i] = b;
        }
    }
    
    /* // for check is all ok
    for (int i = 0; i < size; i++)
    {
        rgb pixel = img->pixels[i];
        printf("rgb(%d, %d, %d)\n", pixel.r, pixel.g, pixel.b);
    }
    */

    FILE* file_to_save = fopen("image.bin", "wb"); // the file extension doesn't matter, it doesn't affect the result, it's just part of the name

    
    fwrite(&img->width, sizeof(unsigned int), 1, file_to_save);
    fwrite(&img->height, sizeof(unsigned int), 1, file_to_save);


    unsigned int pixels_len = size * sizeof(rgb);
    fwrite(&pixels_len, sizeof(unsigned int), 1, file_to_save);

    
    fwrite(img->pixels, pixels_len, 1, file_to_save);

    
    fclose(file_to_save);

    return 0;
}