#include <stdio.h>
#include <stdlib.h>

struct ArrayObject
{
    int len;
    float* Array;
};

void save(struct ArrayObject* arr)
{
    FILE* f = fopen("resultC.txt", "w");
    
    int cuantity = 1000000;

    int limitedSelection = arr->len / cuantity;

    for(int i = 0; i < cuantity; i++) {
        fprintf(f, "%d %f\n", i * limitedSelection, arr->Array[i * limitedSelection]);
    }

    fclose(f);
}

void work(int startIndex, int endIndex, float* smallnumber, float* diferenceByPrecission, float* arr)
{
    for(int i = startIndex; i < endIndex; i++) {
        arr[i] = *smallnumber + (*diferenceByPrecission * (i+1));
    }
}

struct ArrayObject* interpolate(float x, float y, int precission)
{
    float *arr;
    arr = (float*) calloc(precission, sizeof(float));

    float smallnumber = x;
    float diference = y - x;

    if(x > y) {
        smallnumber = y;
        diference = x - y;
    }

    float diferenceByPrecission = diference / (precission + 1);


    work(0, precission, &smallnumber, &diferenceByPrecission, arr);


    static struct ArrayObject toreturn = {0, 0};

    toreturn.len = precission;
    toreturn.Array = arr;
    
    return &toreturn;
}

int main()
{
    struct ArrayObject *arr = interpolate(0, 1000, 450000000);

    save(arr);

    return 0;
}