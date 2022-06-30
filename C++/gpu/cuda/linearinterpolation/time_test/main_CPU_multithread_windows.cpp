#define MAX_THREADS 16

#include <Windows.h>

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

struct thread_data
{
    int startIndex;
    int endIndex;

    float* smallnumber;
    float* diferenceByPrecission;
    float* arr;
};

void* work(void* _data)
{
    struct thread_data* data = (struct thread_data*) _data;

    int startIndex = data->startIndex;
    int endIndex = data->endIndex;

    float* smallnumber = data->smallnumber;
    float* diferenceByPrecission = data->diferenceByPrecission;
    float* arr = data->arr;

    for(int i = startIndex; i < endIndex; i++) {
        arr[i] = *smallnumber + (*diferenceByPrecission * (i+1));
    }

    return NULL;
}

struct ArrayObject* interpolate(float x, float y, int precission)
{
    float* arr;
    arr = (float*) calloc(precission, sizeof(float));

    float smallnumber = x;
    float diference = y - x;

    if(x > y) {
        smallnumber = y;
        diference = x - y;
    }

    float diferenceByPrecission = diference / (precission+1);


    HANDLE threads[MAX_THREADS];
    
    if(precission < MAX_THREADS) {
        for(int i = 0; i < precission; i++) {
            arr[i] = smallnumber + (diferenceByPrecission * (i+1));
        }
    } else {
        int numberToAddToIndex = precission / MAX_THREADS;

        for(int i = 0; i < MAX_THREADS; i++) {
            struct thread_data* data = (struct thread_data*) calloc(1, sizeof(struct thread_data));
            data->startIndex = i * numberToAddToIndex;
            data->endIndex = (i+1) * numberToAddToIndex;
            data->smallnumber = &smallnumber;
            data->diferenceByPrecission = &diferenceByPrecission;
            data->arr = arr;

            threads[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) work, data, 0, NULL);
        }

        for(int i = 0; i < MAX_THREADS; i++) {
            WaitForSingleObject(threads[i], INFINITE);
        }
    }

    struct ArrayObject* arrayObject = (struct ArrayObject*) calloc(1, sizeof(struct ArrayObject));
    arrayObject->len = precission;
    arrayObject->Array = arr;

    return arrayObject;
}

int main()
{
    float x = 0;
    float y = 100;
    int precission = 450000000;

    struct ArrayObject* arrayObject = interpolate(x, y, precission);

    //printArray(arrayObject);

    return 0;
}