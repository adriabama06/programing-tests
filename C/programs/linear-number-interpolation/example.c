#include <stdio.h>

#include "interpolation.h"

int main()
{
    struct ArrayObject *result;
    result = interpolate(0, 100, 4);

    for(int i = 0; i < result->len; i++) {
        printf("[%i] = %f\n", i, result->Array[i]);
    }

    return 0;
}