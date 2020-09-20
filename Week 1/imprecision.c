// Something not accurate: imprecision
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float x = get_float("x: ");
    float y = get_float("y: ");

    printf("Result: %.20f\n", x / y);
}