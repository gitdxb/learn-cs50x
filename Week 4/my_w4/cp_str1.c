// copy string with pointer
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *s = get_string("Str: ");
    char *t = malloc(strlen(s) + 1); // +1 for the null character when copy

    for (int i = 0, n = strlen(s); i < n + 1; i++)  // +1 for null char
    {
        t[i] = s[i];
    }

    t[0] = toupper(s[0]);

    printf("%s\n", s);
    printf("%s\n", t);
    free(t);
}

// copy of string from T wont affect S, because they don't share the same address in pointer
