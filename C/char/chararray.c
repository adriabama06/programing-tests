#include <stdio.h>
#include <stdlib.h>

int main()
{
    // char* = char[] = "hello world";
    // char** = char*[] = {"hello world", "bye world"};

    char* char1 = "hello world";
    char* char2 = "bye world";
    char* char3 = "XD";

    //(char**) malloc(sizeof(char*) * 4); // i do prefer calloc when i do test
    char** char_array = (char**) calloc(4, sizeof(char*));

    char_array[0] = char1;
    char_array[1] = char2;
    // char_array[2] is null cause dont put data
    char_array[3] = char3;
    
    for (size_t i = 0; i < (3 + 1); i++)
    {
        printf("%d = %s\n", i, char_array[i]);
    }

    return 0;
}