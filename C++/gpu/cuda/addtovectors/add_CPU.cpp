#include <iostream>

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

    for (int i = 0; i < sizeof(c) / sizeof(int); i++)
    {
        c[i] = a[i] + b[i];
    }
    
    printArray(c, sizeof(c) / sizeof(int));

    return 0;
}