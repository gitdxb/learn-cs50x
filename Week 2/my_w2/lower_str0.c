#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string upp = get_string("Input: ");
    printf("Output: ");
    for (int i = 0, n = strlen(upp); i < n; i++)
    {
        if (upp[i] >= 'A' && upp[i] <= 'Z')
        {
            printf("%c", upp[i] + 32);
        }
        else
        {
            printf("%c", upp[i]);
        }
    }
    printf("\n");
}