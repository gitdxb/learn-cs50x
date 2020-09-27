#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string s = get_string("Input: ");
    printf("Output: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] != 0) // Not printing null character
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
    printf("Length of the length: %lu\n", strlen(s));
}