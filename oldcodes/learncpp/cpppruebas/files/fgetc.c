#include <string.h>
#include <stdio.h>

int main()
{
    // Almacenar direccion del fichero
    FILE *fichero;
    char caracter;
    // Abrimos el fichero
    fichero = fopen("example.txt", "rt"); // rt -> Read Text

    if(fichero == NULL) {
        printf("Error: No existe o no se tiene acceso al archivo");
    } else {
        caracter = fgetc(fichero);
        printf("Caracter extraido: %c", caracter);
        fclose(fichero);
    }

    return 0;
}