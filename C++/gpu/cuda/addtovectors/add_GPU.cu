#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <iostream>

__global__ void vectorAdd(int* a, int* b, int* c) {
    int i = threadIdx.x;

    c[i] = a[i] + b[i];

    return;
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << i << ": " << arr[i] << std::endl;
    }
    std::cout << std::endl;
    return;
}

int main()
{
    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};
    int c[sizeof(a) / sizeof(int)] = { 0 };

    // create pointers
    int* cuda_a = 0;
    int* cuda_b = 0;
    int* cuda_c = 0;

    // allocate memory on GPU
    cudaMalloc(&cuda_a, sizeof(a)); // sizeof(a) is 12 (int (4), int (4), int (4)) in my computer
    cudaMalloc(&cuda_b, sizeof(b));
    cudaMalloc(&cuda_c, sizeof(c));

    // copy data to GPU
    cudaMemcpy(cuda_a, a, sizeof(a), cudaMemcpyHostToDevice);
    cudaMemcpy(cuda_b, b, sizeof(b), cudaMemcpyHostToDevice);
    cudaMemcpy(cuda_c, c, sizeof(c), cudaMemcpyHostToDevice);

    // call function on GPU
    // vectorAdd<<<GRID_SIZE, BLOCK_SIZE>>>(cuda_a, cuda_b, cuda_c);
    vectorAdd<<<1, sizeof(a) / sizeof(int)>>>(cuda_a, cuda_b, cuda_c);
    
    // copy data back to CPU
    cudaMemcpy(c, cuda_c, sizeof(c), cudaMemcpyDeviceToHost);

    printArray(c, sizeof(c) / sizeof(int));

    return 0;
}