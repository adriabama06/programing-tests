/*
file.bmp
First 54 bytes is for data of the image like resolution, color depth, etc...
byte 18 is for width in signed int
byte 22 is for height in signed int
byte 28 is for bitcount (color depth * color channel) (in my case i got 24 because is 8 bit * R G B like : (8*3 = 24))
for get the size for malloc do: ((width * bitcount + 31) / 32) * 4 * height; or using my calc: (width * 3) * height
*/

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

    //FILE* result = fopen("rgb.txt", "w"); // the next step

    for(int row = height - 1; row >= 0; row--) // the rows is reverse or something ¿? mind break
    {
        printf("Start Row :\n");
        for(int col = 0; col < width; col++)
        {
            int pos = ((row * width) + col) * 3;
            printf("rgb(%d, %d, %d)\n", data[pos], data[pos+1], data[pos+2]);
        }
        printf(": End Row\n");
    }  

    return 0;
}