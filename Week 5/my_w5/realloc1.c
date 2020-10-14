#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    list[0] = 10;
    list[1] = 20;
    list[2] = 30;

    int *tmp = realloc(list, 4 * sizeof(int));
    if (tmp == NULL)
    {
        return 1;
    }

    list = tmp; // Copy pointer address from tmp[] to list][]

    list[3] = 40; // Resize list[] by updating 1 more item

    for (int i = 0; i <4; i++)
    {
        printf("%i\n", list[i]);
    }

    free(list);
    return 0;
}