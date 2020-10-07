#include <stdio.h>

int main(void)
{
    char *s = "EMMA";
    printf("%s\n", s); // print all string
    printf("%p\n", &s[0]); // printing out address of each char
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);

    printf("%c\n", *s);  // print value of each char in each address
    printf("%c\n", *(s+1));
    printf("%c\n", *(s+2));
    printf("%c\n", *(s+3));
}

/*
#include <cs50.h> #include <stdio.h>
int main(void)
{
    string s = "EMMA";
    printf("%s\n", s);
}
*/