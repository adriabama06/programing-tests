/*
In C++, variables are passed to a function by value. When calling a function with an argument, a new variable is instantiated internally and assigned the value passed in the function call.

Any modifications to the value inside the function are performed to this new variable; the variable that was invoked with the function call is unchanged.
*/

#include <iostream>

using namespace std;

void setValueToFive(int x)
{
    std::cout << &x << "\n";
    x = 5;
}

int main()
{
    int x = 3;
    setValueToFive(x);
    cout << "The value of x is " << x << ", setValueToFive() did not modify x.\n";
    // Outputs: The value of x is 3, setValueToFive() did not modify x
    return 0;
}