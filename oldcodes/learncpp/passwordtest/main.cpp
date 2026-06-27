#include <iostream>
#include <cstring>
bool compareCharArray(char char1[], char char2[])
{
    if (strlen(char1) != strlen(char2))
    {
        return false;
    }
    for (int i = 0; i < strlen(char1); i++)
    {
        if (char1[i] == char2[i])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}
bool compareCharArray(char char1[], const char char2[])
{
    if (strlen(char1) != strlen(char2))
    {
        return false;
    }
    for (int i = 0; i < strlen(char1); i++)
    {
        if (char1[i] == char2[i])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}
bool compareCharArray(const char char1[], const char char2[])
{
    if (strlen(char1) != strlen(char2))
    {
        return false;
    }
    for (int i = 0; i < strlen(char1); i++)
    {
        if (char1[i] == char2[i])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[])
{
    if(argc <= 1) {
        std::cout << "No args";
        return 2;
    }
    std::cout << argv[1] << "\n\n";
    const char lowerCase[] = "abcdefghijklmnopqrstuvwxyz";
    const char upperCase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char numbers[] = "1234567890";
    const char special[] = "`~!@#$%^&*()-=_+[]{}|;':\",./<>?\\";
    if(compareCharArray(argv[1], "lower")) {
        std::cout << "lower mode";
        const int len = 8;
        char key[len];
        int k[len];
        for(int i = 0; i < len; i++)
        {
            key[i] = 'a';
            k[i] = 0;
        }
        for(int i = 0; i < len*len; i++)
        {
            for (int l = 0; l < len; l++)
            {
                key[l] = lowerCase[k[l]];
                k[l]++;
                if(compareCharArray(argv[3], key))
                {
                    std::cout << key;
                    return 1;
                }
            }
        }
        std::cout << key;
    }
    return 0;
}