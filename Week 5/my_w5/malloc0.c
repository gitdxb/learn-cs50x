// y doesn't have a value, or memory assigned to store a value like x

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x;
    int *y;

    x = malloc(sizeof(int));

    *x = 42;
    *y = 43;
}