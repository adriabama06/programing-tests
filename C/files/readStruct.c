#include <stdio.h>
#include <stdlib.h>

int len(char* s)
{
    int l = 0;
    while (s[l] != '\0')
    {
        l++;
    }
    return l;
}

struct UserStruct
{
    char* username;
    char* realname;
    int age;
};

void printUser(struct UserStruct *u)
{
    printf("username: %s,\nrealname: %s,\nage: %d\n", u->username, u->realname, u->age);
}

int main()
{
    struct UserStruct u;

    FILE *file;

    file = fopen("data.txt", "rb");

    int usernameLen;
    int realnameLen;

    fread(&usernameLen, sizeof(int), 1, file); // know what is the len of charecters of the username
    
    u.username = (char *) malloc(sizeof(char) * (usernameLen + 1)); // reserve memory
    
    fread(u.username, usernameLen, 1, file); // then read
    //*(u.username + usernameLen) = 0;

    fread(&realnameLen, sizeof(int), 1, file);
    
    u.realname = (char *) malloc(sizeof(char) * (realnameLen + 1));
    
    fread(u.realname, realnameLen, 1, file);

    fread(&u.age, sizeof(int), 1, file); // read things like int is easy

    fclose(file);

    printUser(&u);

    return 0;
}
