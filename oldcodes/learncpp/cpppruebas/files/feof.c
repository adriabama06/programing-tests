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
        while (feof(fichero) == 0) // En C no existe true y false
        {
            printf("%c", caracter);
            caracter = fgetc(fichero);
        }
        
        fclose(fichero);
    }

    return 0;
}