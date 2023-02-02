#include <stdio.h>
#include <stdlib.h>
#include "print.h"

int calc_media(int* arr, unsigned int len)
{
    int sum = 0;
    for (size_t i = 0; i < len; i++)
    {
        sum += arr[i];
    }
    
    return sum / len;
}

int main(int argc, const char** argv)
{
    if(argc < 2) {
        printf("%s <int's...>\n", argv[0]);
        return 0;
    }

    unsigned int len = argc - 1;
    int* arr = malloc(len * sizeof(int));

    for (size_t i = 0; i < len; i++)
    {
        arr[i] = atoi(argv[i+1]);
    }

    int media = calc_media(arr, len);

    print_arr(arr, len);

    printf("Media: %d\n", media);

    free(arr);

    return 0;
}