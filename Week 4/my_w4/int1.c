#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;

    printf("%p\n", &n);
    printf("%p\n", p); // Copy address of n
    printf("%i\n", *p);
    printf("%p\n", &p); // Actual address of p
}
/* 
int *p = &n without an error because its combine 2 steps in 1, like:
int *p;
p = &n;

But, normally can't make: *p = &n => It's an error
*/