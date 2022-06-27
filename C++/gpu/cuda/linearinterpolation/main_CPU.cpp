#include <iostream>

struct ArrayObject
{
    int len;
    float* Array;
};

void printArray(ArrayObject* array)
{
    for(int i = 0; i < array->len; i++) {
        std::cout << "[" << i << "] = " << array->Array[i] << std::endl;
    }
    std::cout << std::endl;
}

void work(int i, float* smallnumber, float* diferenceByPrecission, float* arr)
{
    arr[i] = *smallnumber + (*diferenceByPrecission * (i+1));
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

    float diferenceByPrecission = diference / (precission+1);

    for(int i = 0; i < precission; i++) {
        work(i, &smallnumber, &diferenceByPrecission, arr);
    }

    static struct ArrayObject toreturn = {0, 0};

    toreturn.len = precission;
    toreturn.Array = arr;
    
    return &toreturn;
}

int main()
{
    struct ArrayObject *arr = interpolate(0, 100, 4);

    printArray(arr);

    return 0;
}