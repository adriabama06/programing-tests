#include <stdlib.h>

#include "interpolation.h"

struct ArrayObject *interpolate(float x, float y, int precission)
{
    float *arr;
    arr = (float*) calloc(precission, sizeof(float));

    precission = precission + 1;
    float smallnumber = x;
    float diference = y - x;

    if(x > y) {
        smallnumber = y;
        diference = x - y;
    }

    float diferenceByPrecission = diference / precission;

    for(int i = 1; i < precission; i++) {
        arr[i-1] = smallnumber + (diferenceByPrecission * i);
    }

    static struct ArrayObject toreturn = {0, 0};

    toreturn.len = precission-1;
    toreturn.Array = arr;
    
    return &toreturn;
}