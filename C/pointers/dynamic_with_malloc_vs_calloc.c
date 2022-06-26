/*

Basic diferences between malloc and calloc:

malloc:
It is a function that creates one block of memory of a fixed size.
It only takes one argumemt.
It is faster then calloc.
It has high time efficiency.
It is used to indicate memory allocation.

calloc:
It is a function that assigns more then one block of memory to a single variable.
It takes two arguments.
It is slower than malloc().
It has low time efficiency.
It is used to indicate contiguous memory allcoation.


calloc() gives you a zero-initialized buffer, while malloc() leaves the memory uninitialized.

For large allocations, most calloc implementations under mainstream OSes will get known-zeroed pages from the OS (e.g. via POSIX mmap(MAP_ANONYMOUS) or Windows VirtualAlloc) so it doesn't need to write them in user-space. This is how normal malloc gets more pages from the OS as well; calloc just takes advantage of the OS's guarantee.

This means calloc memory can still be "clean" and lazily-allocated, and copy-on-write mapped to a system-wide shared physical page of zeros. (Assuming a system with virtual memory.)

Some compilers even can optimize malloc + memset(0) into calloc for you, but you should use calloc explicitly if you want the memory to read as 0.

If you aren't going to ever read memory before writing it, use malloc so it can (potentially) give you dirty memory from its internal free list instead of getting new pages from the OS. (Or instead of zeroing a block of memory on the free list for a small allocation).

Embedded implementations of calloc may leave it up to calloc itself to zero memory if there's no OS, or it's not a fancy multi-user OS that zeros pages to stop information leaks between processes.

On embedded Linux, malloc could mmap(MAP_UNINITIALIZED|MAP_ANONYMOUS), which is only enabled for some embedded kernels because it's insecure on a multi-user system.


https://www.geeksforgeeks.org/difference-between-malloc-and-calloc-with-examples/
https://stackoverflow.com/questions/1538420/difference-between-malloc-and-calloc

*/

#include <stdio.h>
#include <stdlib.h>

void printArray(int* arr, int len) {
    for(int i = 0; i < len; i++) {
        printf("%d = %d\n", i, arr[i]);
    }
}

int main()
{
    int size = 10;

    int* my_malloc_array;
    int* my_calloc_array;

    my_malloc_array = (int*) malloc(size * sizeof(int)); // malloc allocates memory for the array
    my_calloc_array = (int*) calloc(size, sizeof(int)); // calloc allocates memory for the array and initializes it to 0

    printf("Malloc : %d / %d = %d\n", sizeof(my_malloc_array), sizeof(int), sizeof(my_malloc_array)/sizeof(int));
    printArray(my_malloc_array, size); // print random numbers

    printf("\nCalloc : %d / %d = %d\n", sizeof(my_calloc_array), sizeof(int), sizeof(my_calloc_array)/sizeof(int));
    printArray(my_calloc_array, size); // print 0s

    // free the memory allocated for the array
    free(my_malloc_array);
    free(my_calloc_array);

    return 0;
}