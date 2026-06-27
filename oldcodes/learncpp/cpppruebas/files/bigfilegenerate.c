#include <stdio.h>

const long long int max = 4294967296;

int main()
{
    FILE *fichero;
    fichero = fopen("compress.txt", "wt");
    if(fichero == NULL) {
        printf("Error: No existe o no se tiene acceso al archivo");
    } else {
        for (long long int i = 0; i < max; i++)
        {
            //printf("%lld\n", i);
            char buff[3] = {i +'0', '\n', '\0'};
            //printf("%c - %lld\n", caracter, i);
            fwrite(&buff, sizeof(buff[0]), 2 /*write only A and \n*/, fichero);
        }
        fclose(fichero);
    }
    return 0;
}