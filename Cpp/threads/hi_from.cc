#include <iostream>
#include <thread>

using namespace std;

void hi_from(int* from)
{
    cout << "Threard " << this_thread::get_id() << " says: Hi from " << *from << endl;
}

int main()
{
    for (int i = 0; i < thread::hardware_concurrency(); i++)
    {
        thread tr(hi_from, &i);
        tr.join();
    }

    return 0;
}