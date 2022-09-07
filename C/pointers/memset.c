#include <stdio.h>
#include <string.h>

int main()
{
    char mytext[] = "Hello World";
    printf("%s\n", mytext);

    memset(mytext, '.', strlen(mytext)); // replaces all characters with '.'
    // memset(mytext, '.', sizeof(mytext)); // use sizeof if is an static char*

    printf("%s\n", mytext);

    return 0;
}
