#include <stdlib.h>
#include <stdio.h>

#define MAX8 256
#define MAX16 65536
#define MAX32 4294967296

void process(long long int MAX)
{
    long long int* reservated;
    for (long long int i = 0; i < MAX / 1000; i++)
    {
        reservated = (long long int*) malloc(1000);
    }
    reservated = (long long int*) malloc(0);
    free(reservated);
}

void process64()
{
    for (long long int i = 0; i < 4294967296; i++)
    {
        malloc(4294967296);
    }
}


int main()
{

    printf("Estas seguro? (y/n) ");
    char sure = 'n';
    scanf("%c", &sure);
    fflush(stdin);
    if(sure == 'n')
    {
        exit(1);
        return 1;
    }
    if(sure == 'y')
    {
        process(MAX16);
    }
    printf("Tu ordenador pudo aguantar?\n");
    _sleep(1000);
    printf("Quieres iniciar la version de 32 bits (%lld bytes)? (y/n) ", MAX32);
    char do32 = 'n';
    scanf("%c", &do32);
    fflush(stdin);
    if(do32 == 'n')
    {
        exit(2);
        return 2;
    }
    if(do32 == 'y')
    {
        process(MAX32);
    }
    printf("Tu ordenador pudo aguantar?\n");
    _sleep(2000);
    printf("Claro! Si es de 64 bits claro que podia con 32 bits (4GB)\n");
    _sleep(3000);
    printf("Quieres iniciar la version de 64 bits (18446744073709552000 bytes)? (y/n) ");
    char do64 = 'n';
    scanf("%c", &do64);
    fflush(stdin);
    if(do64 == 'n')
    {
        exit(3);
        return 3;
    }
    if(do64 == 'y')
    {
        process64();
        printf("Esto es muy raro... Como pudiste?\n");
    }
    return 0;
}