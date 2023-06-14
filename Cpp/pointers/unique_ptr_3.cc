#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> source = {1, 2, 3, 4, 5};

    cout << "Before: Source size: " << source.size() << ", pointer: " << &source << endl;  // Imprime "Source size: 0"

    vector<int> destination = move(source);

    cout << "After: Source size: " << source.size() << ", pointer: " << &source << endl;  // Imprime "Source size: 0"
    cout << "Destination size: " << destination.size() << ", pointer: " << &destination <<endl;  // Imprime "Destination size: 5"

    return 0;
}