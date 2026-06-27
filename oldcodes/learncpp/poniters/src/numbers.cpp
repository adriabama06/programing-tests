/*
@see https://gist.github.com/ericandrewlewis/720c374c29bbafadedc9
*/

#include <iostream>

using namespace std;

// C++ Pointer Tutorial
int main()
{
    /*
    "Regular" variables (not pointers)
    To understand a pointer, let's review "regular" variables first.
    If you're familiar with a programming language without pointers like JavaScript, this is what you think when you hear "variable".
    When declaring a variable by identifier (or name), the variable is synonymous with its value.
    */

    int number = 3;
    cout << "number is initialized with a value of " << number << "\n";
    // Outputs: number is initialized with a value of 3

    // The value of the variable can be modified directly.
    number++;
    number = number * 2;
    cout << "After modifying number, its value is now " << number << "\n";

    // Every value lives at memory addresses. The memory address of a variable can be accessed using the & operator.
    // Outputs: After modifying number, its value is now 8
    cout << "The number variable's value lives at memory address " << &number << "\n";


    /*
    What is a pointer?
    A pointer is a variable that holds a memory address where a value lives. [ need a super brief description of why pointers are useful here ]

    Declare an empty pointer variable
    A pointer is a variable that holds a memory address where a value lives.

    A pointer is declared using the * operator before an identifier.

    As C++ is a statically typed language, the type is required to declare a pointer. This is the type of data that will live at the memory address it points to.
    */


    int *numberPointer;
    cout << "The numberPointer points to the memory address " << numberPointer << ".\n";
    // Outputs: The numberPointer points to the memory address 0x0
    /*
    We've initialized a pointer, but it points nowhere, it has no memory address.
    Note that 0x0 is equivalent to 0. It's just the hexadecimal representation of 0, which memory addresses are expressed in.
    */
    
    /*
    Set a pointer's memory address
    We can set the memory address the pointer points to using the memory address of the number variable.

    The memory address of any variable can be accessed using the & operator.
    */
    numberPointer = &number;
    cout << "The numberPointer points to the memory address `" << numberPointer << "`, which is the memory address of number\n";
    // Outputs: The numberPointer points to the memory address 0x1001054a0
    // NOTE: if you run this code, you will get a different memory address.


    /*
    Declare a pointer while assigning its address a value

    When declaring a pointer, we can alternatively instantiate a variable at its memory address.
    */
    // put this if brefore has not declared *numberPointer
    // int *numberPointer = new int(3);
    // Instantiating a variable with the new operator always returns a pointer.


    // Access and modify the value at a pointer's memory address
    // The value at the memory address pointed to can be accessed with the dereference operator, *.
    *numberPointer = 4;
    cout << "The variable's value has been modified using the pointer. The variable's value is now " << number << "\n";
    // Outputs: The variable's value has been modified using the pointer. The variable's value is now 4
}