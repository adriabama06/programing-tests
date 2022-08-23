#include <stdio.h>

enum materials { // for example if i set unknown as -1 autamatically will start count from -1 to 3 cause diamond the last will be number 3
    unknown = -1,
    stone,
    gold,
    iron,
    diamond,
};

int main()
{
    // enum materials selected; // but by default is number 0
    enum materials selected = unknown;

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

    printf("The code is: %d\n", selected);

    return 0;
}
