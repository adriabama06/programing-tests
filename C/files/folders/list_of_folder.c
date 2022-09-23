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
        printf("%d - %s ", files_count, entry->d_name);
        
        if(entry->d_type == DT_REG)
        {
            printf("(regular file type)\n");
        }
        
        else if(entry->d_type == DT_DIR)
        {
            printf("(directory type)\n");
        }
        
        else if(entry->d_type == DT_FIFO)
        {
            printf("(pipe type)\n");
        }
        
        else if(entry->d_type == DT_SOCK)
        {
            printf("(socket type)\n");
        }

        else if(entry->d_type == DT_CHR)
        {
            printf("(charecter device type)\n");
        }

        else if(entry->d_type == DT_BLK)
        {
            printf("(block type)\n");
        }

        else if(entry->d_type == DT_LNK)
        {
            printf("(symbolic link type)\n");
        }
    }

    closedir(dir_to_scan);

    return 0;
}