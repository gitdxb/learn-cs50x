#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long input;
    do
    {
        input = get_long("Number: ");
    }
    while (input < 1);
    printf("Input: %li\n", input);
}