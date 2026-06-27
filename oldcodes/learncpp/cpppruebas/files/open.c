#include <stdio.h>

int main()
{
    // Almacenar direccion del fichero
    FILE *fichero;
    
    // Abrimos el fichero
    fichero = fopen("example.txt", "rt"); // rt -> Read Text

    return 0;
}