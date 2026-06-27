#include <string.h>
#include <stdio.h>

int main()
{
    // Almacenar direccion del fichero
    FILE *fichero;
    int SizeDeLaCadena = 256;
    char cadena[256];
    char *resultado;
    // Abrimos el fichero
    fichero = fopen("example.txt", "rt"); // rt -> Read Text

    if(fichero == NULL) {
        printf("Error: No existe o no se tiene acceso al archivo");
    } else {
        //                cadena, tamaño max de la cadena
        resultado = fgets(cadena, SizeDeLaCadena, fichero); // como maximo solo sepueden leer 256 por el char limitante
        while (resultado != NULL) // para solucionarlo hacemos un while para leer el resto del archivo hasta que no quede más
        {
            printf("%s", cadena);
            resultado = fgets(cadena, SizeDeLaCadena, fichero);
        }
        
        fclose(fichero);
    }

    return 0;
}