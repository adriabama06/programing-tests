# HELP PLEASE!
Some one know how can i get the size of array allocated using malloc:

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int size = 10;
    int *my_array;

    my_array = (int*) malloc(size * sizeof(int));

    printf("%d / %d = %d\n", sizeof(my_array), sizeof(int), sizeof(my_array)/sizeof(int));
    // this give: 4 / 4 = 1
    // how can i get this print: 40 / 4 = 10 (this in theory is the correct size of the array)

    return 0;
}
```
