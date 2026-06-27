#include <string.h>
#include <stdio.h>

struct userStruct
{
    char username[30];
    int discriminator;
    char real_name[40];
};

int main()
{
    struct userStruct user; // puedes hacerlo en array[] puedes tener un array de user
    printf("Ponga un nombre de usuario: ");
    gets(user.username);
    
    printf("Ponga un discriminator: ");
    scanf("%d", &user.discriminator); // para que lo convierta a digito    
    
    // el scanf desactiva el stdin asi que hay que volver a activarlo
    fflush(stdin);
    printf("Ponga su nombre real: ");
    gets(user.real_name);
    
    char oclutate[40];
    for (int i = 0; i < strlen(user.real_name); i++)
    {
        if(strlen(user.real_name) >= 3 && i < strlen(user.real_name) / 3) {
            oclutate[i] = user.real_name[i];
        } else {
            if(user.real_name[i] == ' ') {
                oclutate[i] = ' ';
            } else {
                oclutate[i] = '-';
            }
        }
    }
    
    printf("Usuario: %s#%d\nReal name: %s", user.username, user.discriminator, oclutate);
    return 0;
};