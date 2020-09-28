#include <string.h>
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    int key;
    char c;
    if (argc < 2 || argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (argc == 2)
    {
        char *p;
        int k = (int)strtol(argv[1], &p, 10);
        if (*p != '\0')
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        if (!isdigit(*argv[1]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else  // When arg is valid
        {
            key = atoi(argv[1]);
            string s = get_string("plaintext: ");
            int n = strlen(s);
            printf("ciphertext: ");
            for (int i = 0; i < n; i++)
            {
                if (isalpha(s[i]))
                {
                    if (isupper(s[i]))
                    {
                        c = ((s[i] - 65) + key) % 26;
                        printf("%c", c + 65);
                    }
                    else if (islower(s[i]))
                    {
                        c = ((s[i] - 97) + key) % 26;
                        printf("%c", c + 97);
                    }
                }
                else
                {
                    printf("%c", s[i]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}

