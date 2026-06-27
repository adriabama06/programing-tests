#include <iostream>
#include <string>

using namespace std;

struct UsuarioStruct
{
    int numero;
    char texto[30];
};

int main()
{
    struct UsuarioStruct *usuario; // SOLO Almacena la direccion

    usuario = new struct UsuarioStruct; // Se reserva la memoria

    cout << "Pon un numero: ";
    cin >> usuario->numero;
    
    cout << "Escibe un texto: ";
    cin.get(usuario->texto, sizeof(usuario->texto));

    // Porque -> y no . ? Es porque usuario no es una estructura, solo es una direccion, es un puntero a una estrucutra

    cout << "\nNumero: " << usuario->numero;
    cout << "\nTexto: " << usuario->texto;

    delete usuario;// Libera la memoria

    return 0;
}