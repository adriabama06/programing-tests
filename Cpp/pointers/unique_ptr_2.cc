#include <iostream>
#include <memory>

using namespace std;

class Human {
public:
    string name;
    int age;

    Human(string name, int age) {
        this->name = name;
        this->age = age;

        cout << "Human " << name << " with " << age << " years old, spawned" << endl;
    }
    ~Human() {
        cout << "Human " << name << " with " << age << " years old, died" << endl;
    }

    void magicAge()
    {
        this->age = this->name.c_str()[0] + this->age;
    }
};

// Crea un humano usando unique_ptr y devuélvelo
unique_ptr<Human> create_human() {
    unique_ptr<Human> human = make_unique<Human>("Adri", 22);
    return human; // No se necesita std::move() aquí
}

// Crea un humano usando create_human() y usa la función magicAge, y muestra en la consola el nombre y edad
void do_work() {
    unique_ptr<Human> human = create_human();

    human->magicAge();

    cout << "Magic: " << human->age << endl;
}

int main() {
    do_work();

    return 0;
}