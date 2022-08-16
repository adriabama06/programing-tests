#include <stdio.h>

int main()
{
    signed int signed_int_ = 0xFFFFFFFF; // -1
    unsigned int unsigned_int_ = 0xFFFFFFFF; // -1?
    
    printf("Signed int: %d\n", signed_int_); // -1
    printf("Unsigned int: %u\n", unsigned_int_); // 4294967295

    /*

    Why?
    32 bit unsinged int can have values from 0 to 2^32 - 1 (0 to 4 294 967 295)

    32 bit signed int can have values from −2^32 / 2 to 2^32 / 2 − 1 (-2147483648 to 2147483647)
    
    */

    return 0;
}