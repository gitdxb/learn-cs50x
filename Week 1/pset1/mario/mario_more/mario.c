#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int h;

    do
    {
        // Ask user input for height
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);
    for (int i = 1; i <= h; i++)
    {
        for (int j = 0; j < h; j++)
        {
            if (j < h - i)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("  ");
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}