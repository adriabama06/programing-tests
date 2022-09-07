#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* slice(const char* str, int start, int end) {
    char* toreturn = (char*) calloc(1, end-start);
    int toreturn_len = 0;
    for(int i = start; i <= (end-1); i++)
    {
        toreturn[toreturn_len] = str[i];
        toreturn_len += 1;
    }
    toreturn[toreturn_len] = '\0';

    return toreturn;
}

int main()
{
    char* text = "Hola, soy adriabama06, me gusta minecraft, y no se que mas";
    //char* sl = slice(text, 6, strlen(text));
    char* sl = slice(text, 6, 21);

    printf("%s\n%s\n", text, sl);
}