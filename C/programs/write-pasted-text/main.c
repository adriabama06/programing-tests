#include <windows.h>
#include <stdio.h>

struct WindowsKey {
    int isUppercase;
    int value; // https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes?redirectedfrom=MSDN
};

struct WindowsKeyArray {
    int length;
    struct WindowsKey* data;
};

struct WindowsKeyArray* convertStringToWindowsKey(char* str)
{
    int strLength = strlen(str);
    struct WindowsKey* values = (struct WindowsKey*) malloc(sizeof(struct WindowsKey) * strLength);

    for (int i = 0; i < strLength; i++)
    {
        int currentChar = str[i];
        
        int winkey = currentChar - 32;

        int isUppercase = (currentChar >= 65 && currentChar <= 90);

        values[i].isUppercase = isUppercase;
        values[i].value = winkey;

        if(currentChar == ' ') {
            values[i].isUppercase = 0;
            values[i].value = 0x20; // 32
            continue;
        }

        if (isUppercase)
        {
            values[i].value = winkey + 32;
        }
    }

    struct WindowsKeyArray* result = (struct WindowsKeyArray*) malloc(sizeof(struct WindowsKeyArray));
    result->length = strLength;
    result->data = values;
   
    return result;
}

char* GetInput()
{
    static char str[100];
    char c;
    int i = 0;
    while ((c = getchar()) != '\n')
    {
        str[i] = c;
        i++;
    }
    str[i] = '\0';
    return str;
}

int GetInputInt()
{
    char* str = GetInput();
    return atoi(str);
}

int main()
{
    int sleep_time = 5000;
    printf("Enter sleep time (in ms): ");
    sleep_time = GetInputInt();
    printf("Set sleep for %d (%ds)\n", sleep_time, sleep_time/1000);

    char* input;
    printf("Enter a string (please only normal charecters like a,b,c... not ),!,?... : ");
    input = GetInput();
    printf("You entered: \"%s\"\n", input);

    Sleep(sleep_time);

    INPUT ip;
 
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; // hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    struct WindowsKeyArray* keys = convertStringToWindowsKey(input);

    for (int i = 0; i < keys->length; i++)
    {
        struct WindowsKey key = keys->data[i];
        int winkey = key.value;
        
        // if is uppercase hold shift

        if (key.isUppercase)
        {
            ip.ki.wVk = 0x10; // virtual-key code for the "shift" key
            ip.ki.dwFlags = 0; // 0 for key press
            SendInput(1, &ip, sizeof(INPUT));
        }

        ip.ki.wVk = winkey;
        ip.ki.dwFlags = 0;
        SendInput(1, &ip, sizeof(INPUT));
 
        ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
        
        if (key.isUppercase)
        {
            ip.ki.wVk = 0x10; // virtual-key code for the "shift" key
            ip.ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
            SendInput(1, &ip, sizeof(INPUT));
        }
        
        Sleep(150);
    }

    return 0;
}