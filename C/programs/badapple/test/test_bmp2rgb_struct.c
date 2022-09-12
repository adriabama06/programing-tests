/*
this write file: rgb.bin (realy the extension is what you like, dosen't matter)
and after use test_rgb_bin2txt.c for load and do the last conversion
*/

typedef struct rgb_struct
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
} rgb;


typedef struct image_struct
{
    int width;
    int height;
    int size;
    rgb* pixels;
} image;



#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* file = fopen("basic_test.bmp", "rb");

    char info[54] = { 0 }; // char is 8 bit int in C

    fread(info, 1, 54, file); // where is 1 i can write sizeof(char) because equals to 1 or sizeof(info[0]) is the same as sizeof(char)

    int width = *(int*) (info + 18);
    int height = *(int*) (info + 22);
    int bitcount = *(int*) (info + 28);
    int size = (width * 3) * height;

    printf("%d x %d @ %d - - %d\n", width, height, bitcount, size);

    unsigned char* data = (unsigned char*) malloc(size);

    fread(data, 1, size, file);

    image* img = (image*) malloc(sizeof(image));

    img->pixels = (unsigned char *) malloc(size);

    FILE* result = fopen("rgb.bin", "wb");

    for(int row = height - 1; row >= 0; row--) // the rows is reverse or something ¿? mind break
    {
        for(int col = 0; col < width; col++)
        {
            int pos = ((row * width) + col) * 3;
            //fprintf(result, "%d,%d,%d", data[pos], data[pos+1], data[pos+2]);
            
        }
    }

    return 0;
}