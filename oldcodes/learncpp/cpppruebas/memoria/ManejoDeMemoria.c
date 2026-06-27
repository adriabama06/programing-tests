#include <stdlib.h>
#include <stdio.h>

struct UsuarioStruct
{
    int numero;
    char texto[30];
};


int main()
{
    struct UsuarioStruct *usuario; // SOLO Almacena la direccion

    usuario = (struct UsuarioStruct *) malloc(sizeof(struct UsuarioStruct)); // Se reserva la memoria
    
    printf("Pon un numero: ");
    scanf("%d", &usuario->numero);

    fflush(stdin);
    printf("Escribe un texto: ");
    gets(usuario->texto);

    // Porque -> y no . ? Es porque usuario no es una estructura, solo es una direccion, es un puntero a una estrucutra

    printf("\nNumero: %d", usuario->numero);
    printf("\nTexto: %s", usuario->texto);

    free(usuario); // Libera la memoria

    return 0;
}