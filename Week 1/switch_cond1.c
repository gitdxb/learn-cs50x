#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("x: ");
    switch(x)
    {
        case 5:
            printf("Five, ");
        case 4:
            printf("Four, ");
        case 3:
            printf("Three, ");
        case 2:
            printf("Two, ");
        case 1:
            printf("One.\n");
        default:
            printf("Blast off!\n");
    }
}