#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int size = 10;
    int *my_array;

    my_array = (int*) malloc(size * sizeof(int));

    printf("%d / %d = %d\n", sizeof(my_array), sizeof(int), sizeof(my_array)/sizeof(int));
}