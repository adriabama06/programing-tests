#include <stdio.h>
#include <string.h>

int endsWith(const char* str, const char* sub_str)
{
    int str_len = strlen(str);
    int sub_str_len = strlen(sub_str);

    if(sub_str_len > str_len)
    {
        return 0;
    }

    for (int i = 0; i < sub_str_len; i++)
    {
        if(str[(str_len - sub_str_len) + i] != sub_str[i])
        {
            return 0;
        }
    }
    
    return 1;
}

int main(int argc, const char *argv[])
{
    if(argc < 3)
    {
        return 0;
    }

    if(endsWith(argv[1], argv[2]))
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }

    return 0;
}