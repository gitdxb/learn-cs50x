#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int i = get_int("I: ");
    int j = get_int("J: ");


    printf("%p\n", &i);
    printf("%p\n", &j);
    
    if (i == j)
        printf("SAME.\n");
    else
        printf("DIFFERENT.\n");
    
}