#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_filename(char* file)
{
    char* filename = (char*) malloc(strlen(file) * sizeof(char));

    strcpy(filename, file);

    char* ext = strrchr(filename, '.');

    if(ext == NULL)
    {
        return 0;
    }

    *ext = '\0';

    return filename;
}

char* get_extension(char* file)
{
    char* filename = (char*) malloc(strlen(file) * sizeof(char));

    strcpy(filename, file);

    char* ext = strrchr(filename, '.');

    if(ext == NULL)
    {
        return 0;
    }

    return ext;
}

int main(int argc, const char *argv[])
{
    if(argc < 2)
    {
        printf("%s <string>\n", argv[0]);
        return 0;
    }

    char* file = (char*) malloc(strlen(argv[1]) * sizeof(char));

    strcpy(file, argv[1]);

    char* filename = get_filename(file);
    char* extension = get_extension(file);

    printf("%s : %s - %s\n", file, filename, extension);

    return 0;
}