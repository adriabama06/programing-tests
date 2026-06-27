#include <stdio.h>

int main()
{
    // Almacenar direccion del fichero
    FILE *fichero;
    char caracter = 'A';
    // Abrimos el fichero si no existe lo creara
    fichero = fopen("example.txt", "wt"); // rt -> Read Text

    if(fichero == NULL) {
        printf("Error: No existe o no se tiene acceso al archivo");
    } else {
        fwrite(&caracter, sizeof(caracter), 1, fichero);
        fclose(fichero);
    }

    return 0;
}