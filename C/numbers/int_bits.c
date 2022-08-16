#include <stdint.h> 
/*

get int in 8, 16, 32, 64 bits

using easy
unint8_t / int8_t
uint16_t / int16_t
uint32_t / int32_t
uint64_t / int64_t

*/

int main()
{
    // for every put the max value of the type in the variable
    uint8_t u_number_8 = UINT8_MAX;    // 255                  unsigned char
    uint16_t u_number_16 = UINT16_MAX; // 65535                unsigned short
    uint32_t u_number_32 = UINT32_MAX; // 4294967295           unsigned int
    uint64_t u_number_64 = UINT64_MAX; // 18446744073709551615 unsigned long
    //                                                        |               | <- Idk if this values changes if the machine is only 32 or 64 bits
    // for every put the min value of the type in the variable
    uint8_t u_number_8_min = 0; // the min value of the usigned int is 0
    uint16_t u_number_16_min = 0;
    uint32_t u_number_32_min = 0;
    uint64_t u_number_64_min = 0;





    // for every put the max value of the type in the variable
    int8_t number_8 = INT8_MAX;    // 127                 signed char
    int16_t number_16 = INT16_MAX; // 32767               signed short
    int32_t number_32 = INT32_MAX; // 2147483647          signed short
    int64_t number_64 = INT64_MAX; // 9223372036854775807 signed long

    // for every put the min value of the type in the variable
    int8_t number_8_min = INT8_MIN;    // -128
    int16_t number_16_min = INT16_MIN; // -32768
    int32_t number_32_min = INT32_MIN; // -2147483648
    int64_t number_64_min = INT64_MIN; // -9223372036854775808
    
    return 0;
}