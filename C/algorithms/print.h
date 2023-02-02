#include <stdio.h>

void print_arr(int* arr, unsigned int len)
{
    printf("[\n");

    for (size_t i = 0; i < len; i++)
    {
        printf("    %d", arr[i]);
        
        if(i+1 < len)
        {
            printf(",");
        }

        printf("\n");
    }

    printf("]\n");
}