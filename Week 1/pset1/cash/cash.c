#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars;
    do
    {
        // Ask user for input
        dollars = get_float("Change owed: ");
    }
    while (dollars <= 0);

    // Convert dollar to cents
    int cents = round(dollars * 100);

    int coins = 0;
    while (cents >= 1)
    {
        if (cents >= 25)
        {
            cents -= 25;
            coins++;
        }
        else if (cents >= 10)
        {
            cents -= 10;
            coins++;
        }
        else if (cents >= 5)
        {
            cents -= 5;
            coins++;
        }
        else if (cents >= 1)
        {
            cents -= 1;
            coins++;
        }

    }
    printf("%i\n", coins);
}