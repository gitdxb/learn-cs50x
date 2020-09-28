#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h> // for round()
#include <ctype.h>

// Congratulations! Today is your day. You're off to Great Places! You're off and away!
int main(void)
{
    // Asking for text input
    string s = get_string("Text: ");

    float letters = 0, words = 0, sentences = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isalpha(s[i]))
        {
            letters++;
        }
        if (isspace(s[i]))
        {
            words++;
        }
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            sentences++;
        }
    }
    // Average letters
    float avg_letter = (letters * 100) / (words + 1);

    // Average sentences
    float avg_sen = (sentences * 100) / (words + 1);

    // Coleman-Liau index
    int index = round((0.0588 * avg_letter) - (0.296 * avg_sen) - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index == 2)
    {
        printf("Grade 2\n");
    }
    else if (index == 3)
    {
        printf("Grade 3\n");
    }
    else if (index == 4)
    {
        printf("Grade 4\n");
    }
    else if (index == 5)
    {
        printf("Grade 5\n");
    }
    else if (index == 6)
    {
        printf("Grade 6\n");
    }
    else if (index == 7)
    {
        printf("Grade 7\n");
    }
    else if (index == 8)
    {
        printf("Grade 8\n");
    }
    else if (index == 9)
    {
        printf("Grade 9\n");
    }
    else if (index == 10)
    {
        printf("Grade 10\n");
    }
    else if (index == 11)
    {
        printf("Grade 11\n");
    }
    else if (index == 12)
    {
        printf("Grade 12\n");
    }
    else if (index == 13)
    {
        printf("Grade 13\n");
    }
    else if (index == 14)
    {
        printf("Grade 14\n");
    }
    else if (index == 15)
    {
        printf("Grade 15\n");
    }
}