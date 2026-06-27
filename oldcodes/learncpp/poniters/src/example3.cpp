/*
In C++ (not in C), you can pass a variable by reference by passing in a variable, and defining the function's parameter like int &x. Any modifications to the variable inside the function will also affect the variable here in this scope too.
*/

#include <iostream>

using namespace std;

void setValueToFiveWithReference(int& x)
{
    cout << x << "\n";
    x = 5;
}

int main()
{
    int x = 3;
    setValueToFiveWithReference(x);
    cout << "The value of x is " << x << ", setPointerValueToFive() modified x.\n";
    // Outputs: The value of x is 5, setPointerValueToFive() modified x
}