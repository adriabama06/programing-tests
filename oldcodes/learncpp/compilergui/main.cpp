#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <cstring>

std::string dir = "ninguno";
std::string output = "ninguno";
std::string version = "c++17";

std::string menu() {
    return
    "\n\n<---- Compiler Gui ---->\n\
\n\
1) Selecciona carpeta : Puesto: " + dir + "\n\
2) Archivo de salida : Puesto: " + output + "\n\
3) Compilar\n\
0) Salir\n\n\
<---------------------->\n\n";
}

void clear() {
    for (int i = 0; i < 16; i++) {
        std::cout << std::endl;
    }
    return;
}

bool isNumber(const std::string& str) {
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

bool endsWith(const std::string &mainStr, const std::string &toMatch) {
    if(mainStr.size() >= toMatch.size() &&
            mainStr.compare(mainStr.size() - toMatch.size(), toMatch.size(), toMatch) == 0)
            return true;
        else
            return false;
}

int main() {
    std::cout << menu();
    
    std::string value;

    std::cin >> value;

    int select = -1;

    if(!isNumber(value)) {
        select = -2;
    }
    
    if(select == -1) {
        select = std::stoi(value);
    }

    if(select == 0) {
        select = -3;
    }
    if(select == 1) {
        clear();
        std::cout << "Pon la ruta completa del directorio: ";
        std::cin >> dir;
        if(endsWith(dir, "\\")) {
            dir = dir.substr(0, dir.size()-1);
        }
        clear();
        main();
    }
    if(select == 2) {
        clear();
        std::cout << "Pon un nombre al archivo de salida: ";
        std::cin >> output;
        clear();
        main();
    }
    if(select == 3) {
        clear();
        std::cout << "Compilando >> " + output + " << en >> " + dir + "\n\n";
            
        std::string toO_ = "g++ -std=" + version + " -c " + dir + "\\*.cpp";

        std::string mkout_ = "g++ -std=c++17 -o " + dir + "\\" + output + " .\\*.o";

        std::string mkclean_ = "del /S /Q .\\*.o ";

        char CHARtoO[toO_.length() + 1];
        strcpy(CHARtoO, toO_.c_str());

        char CHARmkout[mkout_.length() + 1];
        strcpy(CHARmkout, mkout_.c_str());

        char CHARmkclean[mkclean_.length() + 1];
        strcpy(CHARmkclean, mkclean_.c_str());
            
        const char* toO = CHARtoO;
        const char* mkout = CHARmkout;
        const char* mkclean = CHARmkclean;

        std::system(toO);
        std::system(mkout);
        std::system(mkclean);
        clear();
        main();
    }

    if(select == -3) {
        return 0;
    } else {
        main();
    }
}