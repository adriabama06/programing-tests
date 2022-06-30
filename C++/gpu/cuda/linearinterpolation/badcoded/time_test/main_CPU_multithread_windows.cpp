#define MAX_THREADS 16

#include "Windows.h"

#include <iostream>

struct ArrayObject
{
    int len;
    float* Array;
};

struct thread_data
{
    int* threads_able;
    int thread_id;

    int i;
    float* smallnumber;
    float* diferenceByPrecission;
    float* arr;
};

int getThreadAble(int* list)
{
    for(int t = 0; t < MAX_THREADS; t++) {
        if(list[t] == 0) {
            return t;
        }
    }
    return -1;
}

int getThreadUnAble(int* list)
{
    for(int l = 0; l < MAX_THREADS; l++) {
        if(list[l] == 1) {
            return l;
        }
    }
    return -1;
}

void* work(void* _data)
{
    struct thread_data* data = (struct thread_data*) _data;

    int* threads_able = data->threads_able;
    int thread_id = data->thread_id;

    int i = data->i;
    float* smallnumber = data->smallnumber;
    float* diferenceByPrecission = data->diferenceByPrecission;
    float* arr = data->arr;

    arr[i] = *smallnumber + (*diferenceByPrecission * (i+1));

    threads_able[thread_id] = 0;

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
    int threads_able[MAX_THREADS]; // 0 == not using thread, 1 == using thread
    for(int i = 0; i < MAX_THREADS; i++) {
        threads_able[i] = 0;
    }
    
    int i = 0;

    while (i < precission) {
        int thread_able = getThreadAble(threads_able);

        if(thread_able == -1) {
            int thread_unable = getThreadUnAble(threads_able);

            WaitForSingleObject(threads[thread_unable], INFINITE);
            threads_able[thread_unable] = 0;

            thread_able = getThreadAble(threads_able);
        }

        threads_able[thread_able] = 1;

        thread_data* data = (thread_data*) calloc(1, sizeof(thread_data));

        data->threads_able = threads_able;
        data->thread_id = thread_able;

        data->i = i;
        data->smallnumber = &smallnumber;
        data->diferenceByPrecission = &diferenceByPrecission;
        data->arr = arr;

        threads[thread_able] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) work, (void*) data, 0, NULL);

        i++;
    }
    
    for(int i = 0; i < MAX_THREADS; i++) {
        if(threads_able[i] == 1) {
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

    return 0;
}