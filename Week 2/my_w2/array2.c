#include <stdio.h>
#include <cs50.h>

float average(int length, int array[]);

int main (void)
{
    int n = get_int("Enter length: ");

    int scores[n];
    for (int i = 0; i < n; i++)
    {
        scores[i] = get_int("Score %i: ", i + 1);
    }

    // Pass average() to calculate
    printf("Average: %1.f\n", average(n, scores));
}

float average(int length, int array[])
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }

    return (float) sum / (float) length;
}