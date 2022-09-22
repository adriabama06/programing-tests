#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    if(argc < 2)
    {
        printf("%s -f <output file> -w <conent>", argv[0]);
        return 0;
    }

    char* output_file = { 0 };
    char* content = { 0 };

    for (int i = 1; i < argc; i++)
    {
        const char* arg = argv[i];

        // (char*) malloc(256 * sizeof(char));

        if(strcmp(arg, "-f") == 0)
        {
            i++;

            output_file = (char*) malloc(strlen(argv[i]));

            strcpy(output_file, argv[i]);
        }
        
        if(strcmp(arg, "-w") == 0)
        {
            i++;

            content = (char*) malloc(strlen(argv[i]));

            strcpy(content, argv[i]);
        }
    }
    

    if(output_file[0] == 0)
    {
        strcpy(output_file, "output.txt");
    }

    if(content[0] == 0)
    {
        printf("Please use -w for write conent, write the conentn in \"here\" if has space or special charecters\n");
        return 0;
    }

    FILE* foutput= fopen(output_file, "w");

    if(foutput == NULL)
    {
        printf("Error opening \"%s\" in write mode\n", output_file);
        return 1;
    }

    int r = fprintf(foutput, content);

    if(r != strlen(content))
    {
        printf("Error writing \"%s\", writed %d and expected %d\n", output_file, r, strlen(content));
        return 1;
    }

    fclose(foutput);

    return 0;
}