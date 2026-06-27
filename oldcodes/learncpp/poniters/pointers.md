# Example of pointers

### define an number
```c++
void main()
{
    int x = 100;

    return 0;
}
```
```
MEMORY:

#M1 x = 100
- - - - - -
#M2 void
- - - - - -
#M3 void
- - - - - -
#M4 void
```

### define multiple numbers
```c++
void main()
{
    int x = 50;
    int y = 25;
    int z = x + y;
    
    return 0;
}
```
```
MEMORY:

#M1 x = 50
- - - - - -
#M2 y = 25
- - - - - -
#M3 z = 75
- - - - - -
#M4 void
```
### create pointer
```c++
void main()
{
    int *anpointer;
    int annumber = 5;
    anpointer = &annumber;

    return 0;
}
```
```
MEMORY:

#M1 anpointer = #M2
- - - - - -
#M2 annumber = 5
- - - - - -
#M3 void
- - - - - -
#M4 void
```
`*anpointer` at start is null, after `anpointer = &annumber;` `anpointer` say go to `#M2` where is `annumber`
### update value from pointer
```c++
void main()
{
    int *anpointer;
    int annumber = 5;
    anpointer = &annumber;

    // convert annumber and *anpointer : 5 -> 10
    annumber = *anpointer + 5;

    // convert annumber and *anpointer : 10 -> 0
    *anpointer = 0;
    // don't do anpointer whiout * if you do this you change memory acces
    return 0;
}
```
```
MEMORY brefore - *anpointer = 0; :

#M1 anpointer = #M2
- - - - - -
#M2 annumber = 10
- - - - - -
#M3 void
- - - - - -
#M4 void
```
```
MEMORY At end:

#M1 anpointer = #M2
- - - - - -
#M2 annumber = 0
- - - - - -
#M3 void
- - - - - -
#M4 void
```
create an variable with number 5 and using the pointer is the same number of the variable adding 5 result is 10 and at end set pointer is like copy of variable to 0



```c++
#include <iostream>

using namespace std;

void main()
{
    // create of an variable int x
    int x = 5;
    // if you edit *ReferenceOfX you update x
    int *PointerOfX = &x;
    // if you edit &ReferenceOfX you update x
    int &ReferenceOfX = x;

    cout << x << "\n"; // 5
    cout << PointerOfX << "\n" // 0x0... for example 0x01 like #M1
    cout << ReferenceOfX << "\n" // 5

    cout << &x << "\n"; // 0x0... for example 0x01 like #M1 & say te acces memory
    cout << *PointerOfX << "\n" // 5
    cout << &ReferenceOfX << "\n" // 0x0... for example 0x01 like #M1 & say te acces memory

    // you now update x
    ReferenceOfX = 2;

    cout << x << "\n"; // 2
    cout << PointerOfX << "\n" // 0x0... for example 0x01 like #M1
    cout << ReferenceOfX << "\n" // 2

    cout << &x << "\n"; // 0x0... for example 0x01 like #M1 & say te acces memory
    cout << *PointerOfX << "\n" // 2
    cout << &ReferenceOfX << "\n" // 0x0... for example 0x01 like #M1 & say te acces memory

    return 0;
}
```
```
MEMORY At end:

#M1 x = 5 <- ReferenceOfX // is at the same point
- - - - - -
#M2 PointerOfX = #M1
- - - - - -
#M3 void
- - - - - -
#M4 void
```

### resumen

`int x = 5;`

`&x` direction of the memory of an variable -> `0x0...`

`*x` get content of the memory -> `5`

`x` get content -> `5`

`int *y = &x;`

`&y` direction of the memory of an variable -> `0x0...`

`*y` get content of the memory -> `5`

`y` direction of the memory -> `0x0...`