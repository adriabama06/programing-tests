#include <string.h>
#include <stdio.h>

struct StructPersona
{
    char nombre[30];
    int edad;
};


int main()
{
    // Almacenar direccion del fichero
    FILE *fichero;
    struct StructPersona persona;
    // Abrimos el fichero
    fichero = fopen("example.dat", "rb"); // rb -> Read Byte, // tambien puede ser .txt, .lo_que_sea

    if(fichero == NULL) {
        printf("Error: No existe o no se tiene acceso al archivo");
    } else {
        fread(&persona, sizeof(persona), 1, fichero);
        while (feof(fichero) == 0) // en C no existe true o false
        {
            printf("\n\nNombre: %s", persona.nombre);
            printf("\nEdad: %d", persona.edad);
            fread(&persona, sizeof(persona), 1, fichero);
        }
        
        fclose(fichero);
    }

    return 0;
}