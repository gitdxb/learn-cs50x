#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string a = get_string("a: ");
    string b = get_string("b: ");

    if (a == b)
        printf("Same.\n");
    else
        printf("Different.\n");
}