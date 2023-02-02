#include "cuda_runtime.h"
#include "device_launch_parameters.h"

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

__global__ void work(float* smallnumber, float* diferenceByPrecission, float* arr)
{
    int i = threadIdx.x;
    
    arr[i] = *smallnumber + (*diferenceByPrecission * (i+1));
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

    float diferenceByPrecission = diference / (precission + 1);

    float* cuda_smallnumber;
    float* cuda_diferenceByPrecission;
    float* cuda_arr;

    cudaMalloc(&cuda_smallnumber, sizeof(float));
    cudaMalloc(&cuda_diferenceByPrecission, sizeof(float));
    cudaMalloc(&cuda_arr, sizeof(float) * precission);

    cudaMemcpy(cuda_smallnumber, &smallnumber, sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(cuda_diferenceByPrecission, &diferenceByPrecission, sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(cuda_arr, &arr, sizeof(float) * precission, cudaMemcpyHostToDevice);

    work<<<1, precission>>>(cuda_smallnumber, cuda_diferenceByPrecission, cuda_arr);

    cudaMemcpy(arr, cuda_arr, sizeof(float) * precission, cudaMemcpyDeviceToHost);

    static struct ArrayObject toreturn = {0, 0};

    toreturn.len = precission;
    toreturn.Array = arr;
    
    return &toreturn;
}

int main()
{
    struct ArrayObject *result = interpolate(0, 100, 4);

    printArray(result);

    return 0;
}