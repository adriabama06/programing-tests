/*
A function can be written to perform the same task but instead accept a pointer as the argument. This lowers the memory footprint of the program. Unnecessary duplicate variables aren't created. The function can modify the variable's value directly. Any modifications to the variable in the function affect the variable here in this scope too.
*/

#include <iostream>

using namespace std;

void setPointerValueToFive(int *x)
{
    cout << *x << "\n";
    *x = 5;
}

int main()
{
    int x = 3;
    setPointerValueToFive(&x);
    cout << "The value of x is " << x << ", setPointerValueToFive() modified x.\n";
    // Outputs: The value of x is 5, setPointerValueToFive() modified x
}