#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, const char *argv[])
{
    DIR* dir_to_scan = opendir(".");

    if(argc > 1)
    {
        dir_to_scan = opendir(argv[1]);
    }

    if(dir_to_scan == NULL)
    {
        printf("Unable to read directory\n");
        return 1;
    }

    struct dirent *entry;
    
    for (int files_count = 0; (entry = readdir(dir_to_scan)) != NULL; files_count++)
    {
        printf("%d - %s\n", files_count, entry->d_name);
    }

    closedir(dir_to_scan);

    return 0;
}