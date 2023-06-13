#include <iostream>
#include <thread>

using namespace std;

int main()
{
    auto do_some_work = [](int x)
    {
        for (int i = 0; i < 10; i++)
        {
            int y = x + i;
            cout << "Power " << y << "^2 = " << y * y << endl;
        }
    };

    thread run_work(do_some_work, 5);

    run_work.join();

    return 0;
}