#include <iostream>
#include <memory>

using namespace std;

class test
{
public:
    test()
    {
        cout << "Test created" << endl;
    }
    ~test()
    {
        cout << "Test deleted" << endl;
    }
};

test create_test()
{
    test some = test(); // prints Test created, because we return the test, don't throw test deleted

    return some;
}

unique_ptr<int[]> create_unique()
{
    unique_ptr<int[]> u_ptr = unique_ptr<int[]>(new int[10]);

    cout << u_ptr.get() << endl;

    return u_ptr;
}

int main()
{
    test some = create_test();

    unique_ptr<int[]> u_ptr = create_unique();

    cout << u_ptr.get() << endl;

    return 0;
}
// prints test deleted at the end, because the object is destroyed when is not necesary