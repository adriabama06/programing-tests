#include <string.h>
#include <stdio.h>

struct userStruct
{
    char username[30];
    int level;
};

int main()
{
    // 3 => 4, \0 es el 4 porque tiene que haver uno vacio para decir que ese es el tope del array, con sizeof nos dira que hay 3 pero realmente hay uno que es el 4 que esta vacio que el valor es \0
    struct userStruct users[3]; 
    printf("Numero de usuarios: %d\n", (int) (sizeof(users)/sizeof(users[0])));
    for (int i = 0; i < (int) (sizeof(users)/sizeof(users[0])); i++)
    {
        printf("Ponga un nombre de usuario al usuario %d: ", i+1);
        gets(users[i].username);
    
        printf("Ponga un nivel al usuario %d: ", i+1);
        scanf("%d", &users[i].level); // para que lo convierta a digito
        fflush(stdin);
    }
    printf("Los %d usuarios se han registrado correctamente\n", (int) (sizeof(users)/sizeof(users[0])));
    for (int i = 0; i < (int) (sizeof(users)/sizeof(users[0])); i++)
    {
        printf("El usuario %d es: %s, esta al nivel %d\n", i+1, users[i].username, users[i].level);
    }
    
    return 0;
};