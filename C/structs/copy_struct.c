#define FIRST_HUMAN_NAME "Pablo"
#define FIRST_HUMAN_SURNAME "Escobar"
#define FIRST_HUMAN_AGE 23

#define CLONE1_NAME "Copy of Pablo"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HUMAN_STRUCT {
    char* name;
    char* surname;
    unsigned int age;
} HUMAN;

int main()
{
    HUMAN* first_human = (HUMAN*) malloc(sizeof(HUMAN));
    first_human->age = FIRST_HUMAN_AGE;

    
    first_human->name = (char*) malloc(strlen(FIRST_HUMAN_NAME) * sizeof(char));
    strcpy(first_human->name, FIRST_HUMAN_NAME);


    first_human->surname = (char*) malloc(strlen(FIRST_HUMAN_SURNAME) * sizeof(char));
    strcpy(first_human->surname, FIRST_HUMAN_SURNAME);


    HUMAN* clone1 = (HUMAN*) malloc(sizeof(HUMAN));

    clone1->name = (char*) malloc(strlen(first_human->name) * sizeof(char));
    clone1->surname = (char*) malloc(strlen(first_human->surname) * sizeof(char));

    printf("%d\n", sizeof(*first_human));

    memcpy(clone1, first_human, sizeof(*first_human));

    clone1->name = (char*) malloc(strlen(CLONE1_NAME) * sizeof(char));
    strcpy(clone1->name, CLONE1_NAME);
    clone1->age = 1;

    printf("Original: %s : %s : %d\n", first_human->name, first_human->surname, first_human->age);
    printf("Clone 1: %s : %s : %d\n", clone1->name, clone1->surname, clone1->age);

    return 0;
}