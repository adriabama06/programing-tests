#include <iostream>
#include <cstring>

using namespace std;

void toDo(int *number)
{
    cout << number << "\n";
    int parseed = *number;
    cout << parseed << "\n";
}

void secondToDo(int& directParsed)
{
    cout << &directParsed << "\n";
    cout << directParsed << "\n";
}

bool compareCharArray(char char1[], char char2[])
{
    if (strlen(char1) != strlen(char2))
    {
        return false;
    }
    for(int i = 0; i < strlen(char1); i++)
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

// how convert *argv to argv
int main(int argc, char *argv[])
{
    // try int
    int startnumber = 2;
    cout << startnumber << "\n";
    toDo(&startnumber);
    cout << "\n\n\n" << startnumber << "\n";
    secondToDo(startnumber);

    // now with argv
    // ... ._. you can't do it with argv XD so i created an funtion
    
    if(argv[1])
    {
        cout << argv[1] << "\n";
        if(compareCharArray(argv[1], "help"))
        {
            cout << "hello help!" << "\n";
        }
        
    }
    
    return 0;
}