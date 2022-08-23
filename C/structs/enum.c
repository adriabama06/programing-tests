#include <stdio.h>

enum materials {
    stone = 0,
    gold = 1,
    iron = 2,
    diamond = 3,
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