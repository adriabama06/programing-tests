// Because the SendInput function is only supported in
// Windows 2000 and later, WINVER needs to be set as
// follows so that SendInput gets defined when windows.h
// is included below.

#define WINVER 0x0500
#include <windows.h>
 
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
 
    // Press the "A" key
    ip.ki.wVk = 0x41; // virtual-key code for the "a" key // https://docs.microsoft.com/es-es/windows/win32/inputdev/virtual-key-codes?redirectedfrom=MSDN
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
 
    // Release the "A" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
 
    // Exit normally
    return 0;
}