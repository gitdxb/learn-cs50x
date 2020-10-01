#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[4];

    people[0].name = "EMMA";
    people[0].number = "617–555–0100";

    people[1].name = "RODRIGO";
    people[1].number = "244-124-9112";

    people[2].name = "BRIAN";
    people[2].number = "777-235-1111";

    people[3].name = "DAVID";
    people[3].number = "878-000-1234";

    // Search for EMMA

    for (int i = 0; i < 4; i++)
    {
        if (strcmp(people[i].name, "EMMA") == 0)
        {
            printf("found: %s\n", people[i].number);
            return 0;
        }
    }
    printf("not found.\n");
    return 1;

}