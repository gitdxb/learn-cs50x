#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(3 * sizeof(int)); // Make room for 3 integers

    if (list == NULL)
    {
        return 1; // When malloc can't provide free memory
    }

    list[0] = 11;
    list[1] = 22;
    list[2] = 34;

    int *tmp = malloc(4 * sizeof(int)); // Make room for 4 integer, temporarily
    if (tmp == NULL)
    {
        return 1; // When malloc can't provide some free memory for tmp[]
    }

    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i]; // Copy 3 int from list to temp[]
    }

    tmp[3] = 74;

    free(list); // Free memory from old list[]

    list = tmp; // Don't get it?

    for (int i = 0; i < 4; i++)
    {
        list[i] = tmp[i];   // Copy tmp[] to list[]
        printf("List item %i now is: %i\n", i + 1, list[i]);
    }

    free(tmp);
    return 0;
}