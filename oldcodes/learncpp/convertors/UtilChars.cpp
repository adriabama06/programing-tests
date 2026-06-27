#include "UtilChars.h"
#include <cstring>

using namespace UtilChars;
using namespace std;

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