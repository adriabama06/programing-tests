#include <stdio.h>

int main()
{
    int *basicArr[4];
    printf("%d\n", sizeof(basicArr)/sizeof(basicArr[0]));

    return 0;
}