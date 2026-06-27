#include <iostream>
#include <string>
#include "sayhi.h"
#include "filemanager.h"

int main() {
    //std::string mystring = "hola";
    sayhi_H::sayhi();
    sayhi_H::sayhi();
    std::string nombre;

    std::getline(std::cin, nombre);

    std::cout << sayhi_H::genIntro(nombre) << std::endl;

    std::cout << "Vamos a crear un archvo\n";

    std::cout << "Ponle un nombre: ";

    std::string fname;
    std::string fdata;

    std::getline(std::cin, fname);

    std::cout << "Pon lo que quieres que vaya dentro: \n";

    std::getline(std::cin, fdata);

    std::ofstream createdfile = filemanager::createFile(fname);

    createdfile << fdata;

    std::cout << "Archivo creado !";

    return 0;
}