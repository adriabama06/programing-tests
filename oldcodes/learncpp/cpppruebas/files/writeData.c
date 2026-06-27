#include <string.h>
#include <stdio.h>

int main()
{
    // Almacenar direccion del fichero
    FILE *fichero;
    char frase[100];
    // Abrimos el fichero
    fichero = fopen("writehere.txt", "wt"); // rt -> Read Text

    if(fichero == NULL) {
        printf("Error: No existe o no se tiene acceso al archivo");
    } else {
        printf("Escribe texto para meter en writehere.txt: ");
        gets(frase);
        fwrite(&frase, strlen(frase), 1, fichero);
        fclose(fichero);
    }

    return 0;
}