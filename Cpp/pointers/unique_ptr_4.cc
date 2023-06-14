#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    string name;

    Person(string new_name) {
        this->name = move(new_name);

        cout << "Person " << this->name << " created" << endl;
    }
};

int main() {
    string name = "Adri";
    
    Person person(move(name));
    
    cout << "Name: " << name << endl; // Imprime una cadena vacía

    return 0;
}