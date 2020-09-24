#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;

    do
    {
        height = get_int("How tall do you want your pyramid?\n");
    }
    while (height < 1 || height > 8);
    for (int row = 1; row <= height; row++)
        {
            for (int blocks = 0; blocks < height; blocks++)
            {
                if (blocks < height - row)
                    {
                        printf(".");
                    }
                else
                {
                    printf("#");
                }
            }
        printf("\n");
        }
}