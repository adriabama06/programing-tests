/**
 * ---------------------
 * PLEASE READ README.md
 * ---------------------
 */

#include <stdio.h>
#include <stdlib.h>

struct CustomArray // i called CustomArray but you can set the name you like, i believe ArrayObject can be better
{
    int* Array;
    int len;
};


struct CustomArray getIntArray(int firstvalue, int endvalue, int refillvalue) {
    int len = 10;
    int* arr;
    arr = (int*) malloc(len * sizeof(int));

    arr[0] = firstvalue;
    
    for(int i = 1; i < len-1; i++) {
        arr[i] = refillvalue;
    }

    arr[len-1] = endvalue;

    struct CustomArray toreturn = {arr, len};
    return toreturn;
}

struct CustomArray getIntArray(int firstvalue, int endvalue, int refillvalue, int sizeofarray) {
    int len = sizeofarray;
    int* arr;
    arr = (int*) malloc(len * sizeof(int));

    arr[0] = firstvalue;
    
    for(int i = 1; i < len-1; i++) {
        arr[i] = refillvalue;
    }

    arr[len-1] = endvalue;

    struct CustomArray toreturn = {arr, len};
    return toreturn;
}

int main()
{
    struct CustomArray myarr;

    myarr = getIntArray(5, 2, 9);

    for(int i = 0; i < myarr.len; i++) {
        printf("%d = %d\n", i, myarr.Array[i]);
    }

    return 0;
}