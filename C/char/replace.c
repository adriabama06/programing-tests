#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* replace(const char* str, const char to_search, const char replace_value) {
    char* toreturn = (char*) calloc(1, strlen(str));
    int toreturn_len = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == to_search) {
            if(replace_value == '\0') {
                continue;
            }

            toreturn[toreturn_len] = replace_value;
        } else {
            toreturn[toreturn_len] = str[i];
        }
        toreturn_len += 1;
    }

    toreturn[toreturn_len] = '\0';

    return toreturn;
}

int main()
{
    char* text = "Hola, soy adriabama06, me gusta minecraft, y no se que mas";
    char* replaced1 = replace(text, ',', '\0');
    char* replaced2 = replace(text, ',', '.');

    printf("%s\n%s\n%s\n", text, replaced1, replaced2);
}