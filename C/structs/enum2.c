#include <stdio.h>

enum materials { // define numbers is optional, C automatically add number by the order, like: stone 0, gold 1, but you can put manually an number, like sotne 1, gold 10, iron 100...
    stone,
    gold,
    iron,
    diamond,
};

int main()
{
    enum materials selected = iron;

    switch (selected)
    {
    case stone:
        printf("Selected is: stone\n");
        break;
    
    case gold:
        printf("Selected is: gold\n");
        break;

    case iron:
        printf("Selected is: iron\n");
        break;

    case diamond:
        printf("Selected is: diamond\n");
        break;
    
    default:
        printf("Idk what is\n");
        break;
    }

    return 0;
}