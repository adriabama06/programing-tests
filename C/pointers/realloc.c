#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char* argv[])
{
    if(argc < 2)
    {
        printf("%s <start string>\n", argv[0]);

        return 0;
    }

    char* start_str = (char*) malloc(strlen(argv[1]) * sizeof(char));

    strcpy(start_str, argv[1]);

    while (1)
    {
        char* buff = (char*) malloc(1024 * sizeof(char));
        scanf("%s", buff);
        if(strcmp(buff, "exit") == 0)
        {
            break;
        }
        size_t buff_len = strlen(buff)+1;

        start_str = (char*) realloc(start_str, (strlen(start_str) + buff_len) * sizeof(char));

        strcat(start_str, " ");
        strcat(start_str, buff);
    }

    printf("Final string:\n%s\n", start_str);
    
    free(start_str);

    return 0;
}