#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        // Asking height input from user
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    for (int i = 0; i < n; i++)
    {

        for (int k = n; k > i + 1; k--)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

