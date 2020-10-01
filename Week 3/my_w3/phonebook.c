#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;

const int NUMBER = 2;

int main(void)
{
    person people[NUMBER];

    for (int i = 0; i < NUMBER; i++)
    {
        people[i].name = get_string("Enter name: ");
        people[i].number = get_string("Enter number: ");
    }

    for (int j = 0; j < 2; j++)
    {
        if (strcmp(people[j].name, "David") == 0)
        {
            printf("found.\n");
            return 0;
        }
    }
    printf("not found\n");
    return 1;
}