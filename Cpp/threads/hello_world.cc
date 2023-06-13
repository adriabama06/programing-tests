#include <iostream>
#include <thread>

using namespace std;

void hello_world()
{
    cout << "Hello world from a thread" << endl;
}

int main()
{
    thread run_hello(hello_world);

    run_hello.join();

    return 0;
}