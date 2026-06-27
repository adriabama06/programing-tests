#include <iostream>
#include <string>

int sayhi() {
    std::cout << "Hi!\n";
    return 0;
}

std::string genIntro(std::string name) {
    std::string i = "Bienvenido... " + name + "!";
    return i; 
}