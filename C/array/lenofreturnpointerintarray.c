#include <stdio.h>

int* pointerArray()
{
    static int arr[5];
    printf("arr: %d\n", sizeof(arr)/sizeof(arr[0])); // arr: 4
    printf("%d / %d\n", sizeof(arr), sizeof(arr[0])); // 20 / 4
    return arr;
}

int main()
{
    int *mainArr = pointerArray();
    printf("mainArr: %d\n", sizeof(mainArr)/sizeof(mainArr[0])); // mainArr: 5
    printf("%d / %d\n", sizeof(mainArr), sizeof(mainArr[0])); // 4 / 4

    return 0;
}