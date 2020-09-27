#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string names[4];
    names[0] = "EMMA";
    names[1] = "RODRIGO";
    names[2] = "BRIAN";
    names[3] = "DAVID";

    printf("Name 1: %s\n", names[0]);
    printf("Name 2: %c%c%c%c\n", names[0][0], names[0][1], names[0][2], names[0][3]);
    printf("Null character: %i\n", names[0][4]);
}