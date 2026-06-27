#include <stdio.h>

int main()
{
    // Almacenar direccion del fichero
    FILE *fichero;
    
    // Abrimos el fichero
    fichero = fopen("example.txt", "rt"); // rt -> Read Text

    if(fichero == NULL) {
        printf("Error: No existe o no se tiene acceso al archivo");
    } else {
        // fputc (putchar) 'c' not "c"
        fputs("hello world from put.c", fichero);
        printf("Escrito y ahora se cerrra, igualmente no se escribio porque esta en read mode");
        fclose(fichero);
    }

    return 0;
}