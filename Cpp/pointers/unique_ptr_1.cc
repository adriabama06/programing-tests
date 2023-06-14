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

void do_math(unique_ptr<Human>& human) {
    human->magicAge();
}

int do_work() {
    // Crear un unique_ptr para Human
    unique_ptr<Human> human = make_unique<Human>("Adri", 22);
    //unique_ptr<Human> human = unique_ptr<Human>(new Human("Adri", 22));


    // Pasar unique_ptr de human a: do_math
    do_math(human);

    // Devuelve age:
    return human->age;
}

int main() {
    int magic = do_work();

    cout << "Magic: " << magic << endl;

    return 0;
}