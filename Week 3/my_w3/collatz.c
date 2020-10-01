#include <stdio.h>
#include <cs50.h>

int collatz(int i);

int main(void)
{
    int input = get_int("Enter a number: ");

    collatz(input);
}

int collatz(int i)
{
    int c = 0;
    if (i == 1)
    {
        return 0;
    }
    else
    {
        if (i % 2 == 0)
        {
            //i /= 2;
            return 1 + collatz(i / 2);
        }
        else
        {
            //i = 3 * i + 1;
            return 1 + collatz(3 * i + 1);
        }
    }
    //printf("i now is: %i\n", i);
    return 0;
}