#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

int main(void)
{
    string s = get_string("str: ");
    string t = s;

    t[0] = toupper(t[0]);

    // Print string twice
    printf("s: %s\n", s); // Also capitalize the str, fail
    printf("t: %s\n", t);
}