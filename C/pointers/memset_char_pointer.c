/*

    THIS CODE DON'T WORK, I NEED HELP FOR KNOW HOW USE MEMSET TO CHAR POINTER

*/

#include <stdio.h>
#include <string.h>

int main()
{
    char* mytext = "Hello World";
    size_t mytext_len = strlen(mytext);
    
    printf("%s %d\n", mytext, mytext_len);

    memset(mytext, '.', 4); // replaces all characters with '.'
    // memset(mytext, '.', sizeof(mytext));

    printf("%s\n", mytext);

    return 0;
}
