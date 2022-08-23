#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* char1 = "hello world";
    char* char2 = "bye world";
    char* char3 = "XD";

    char** char_array = (char**) malloc(4 * sizeof(char*));

    char_array[0] = (char*) malloc(sizeof(char1));
    char_array[1] = (char*) malloc(sizeof(char2));
    char_array[3] = (char*) malloc(sizeof(char3));

    //memcpy(char_array[0], char1, sizeof(char1));
    //memcpy(char_array[1], char2, sizeof(char2));
    //memcpy(char_array[3], char3, sizeof(char3));

    // or in this case for strings is easy do:

    strcpy(char_array[0], char1);
    strcpy(char_array[1], char2);
    strcpy(char_array[3], char3);

    for (int i = 0; i < (3 + 1); i++)
    {
        printf("%d = %s\n", i, char_array[i]);
    }

    printf("---\n");

    char1 = "AE"; // cause i do a copy the char1 is not used

    for (int i = 0; i < (3 + 1); i++)
    {
        printf("%d = %s\n", i, char_array[i]);
    }

    printf("---\n");

    char_array[0] = "ae"; // but if i drectly go to char_array, and change the string will change

    for (int i = 0; i < (3 + 1); i++)
    {
        printf("%d = %s\n", i, char_array[i]);
    }

    printf("---\n");

    // or clear all for use chars for other things
    char1 = "";
    char2 = "";
    char3 = "";

    for (int i = 0; i < (3 + 1); i++)
    {
        printf("%d = %s\n", i, char_array[i]);
    }

    return 0;
}
