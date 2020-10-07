#include <stdio.h>

void swap(int *a, int *b);

int main (void)
{
    int x = 1;
    int y = 2;

    printf("x now is %i, y now is %i\n", x, y);
    swap(&x, &y);
    printf("x now is %i, y now is %i\n", x, y);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
