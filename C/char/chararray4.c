#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* temp = "hello world";

    char** char_array = (char**) malloc(3 * sizeof(char*));

    char_array[0] = (char*) malloc(strlen(temp));
    strcpy(char_array[0], temp);
    
    temp = "bye world";

    char_array[1] = (char*) malloc(strlen(temp));
    strcpy(char_array[1], temp);

    temp = "XD";

    char_array[2] = (char*) malloc(strlen(temp));
    strcpy(char_array[2], temp);

    for (int i = 0; i < 3; i++)
    {
        printf("%d = %s\n", i, char_array[i]);
    }

    return 0;
}
