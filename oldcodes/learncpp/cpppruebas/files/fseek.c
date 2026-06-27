#include <string.h>
#include <stdio.h>

struct StructPersona
{
    char nombre[30];
    int edad;
};

/*
fseek modes:
SEEK_SET, 0, Salta desde el principio del fichero
SEEK_CUR, 1, Salta desde la posicion actual
SEEK_END, 2, Salta desde el final del fichero
*/

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
        fseek(fichero, 2*sizeof(struct StructPersona), SEEK_SET);
        fread(&persona, sizeof(struct StructPersona), 1, fichero);
        printf("\n\nNombre: %s", persona.nombre);
        printf("\nEdad: %d", persona.edad);

        fread(&persona, sizeof(persona), 1, fichero);

        fclose(fichero);
    }

    return 0;
}