#define WINVER 0x0500
#include <windows.h>
#include <stdio.h>

int main()
{
    // This structure will be used to create the keyboard
    // input event.
    INPUT ip;
 
    // Pause for 5 seconds.
    Sleep(5000);
 
    // Set up a generic keyboard event.
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; // hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
 
    char* text = "HELLO WORLD";
    int i = 0;
    char currentC = text[i];
    while (currentC != '\0')
    {
        printf("%c\n", currentC);
        ip.ki.wVk = currentC;
        ip.ki.dwFlags = 0;
        SendInput(1, &ip, sizeof(INPUT));
 
        ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
        i++;
        currentC = text[i];
        Sleep(150);
    }
    


    return 0;
}