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
        printf("Se pudo leer el archivo! Ahora se cerrara");
        fclose(fichero);
    }

    return 0;
}