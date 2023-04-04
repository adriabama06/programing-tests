#include <stdio.h>
#include <wchar.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <locale.h>
#endif

int main()
{
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #else
    setlocale(LC_ALL, "");
    #endif
    
    wchar_t wc = L'ñ';

    wprintf(L"%lc\n", wc);

    return 0;
}