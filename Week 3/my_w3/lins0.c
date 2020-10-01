// Linear search

#include <stdio.h>
#include <cs50.h>

int main (void)
{

    int numbers[] = { 1,2,3,4,5,6,7,8,9,10};
    for (int i = 0; i < n; i++)
    {
        if (numbers[i] == 50)
        {
            printf("found\n");
            return 0;
        }
    }
    printf("not found\n");
    return 1;
}