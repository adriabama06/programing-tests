#include <iostream>
#include <chrono>
using namespace std;

int main()
{
    cout << "inicio";
    auto begin = chrono::high_resolution_clock::now();
    long long int number = 3000000;
    for(long long int i = 0; i < number; i++)
    {
        //cout << endl << i;
    }
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << endl;
    cout << elapsed.count() * 1e-9;
    cout << endl;
    cout << "he terminado";
    return 0;
}