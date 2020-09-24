#include <math.h>
#include <stdio.h>

int main() {
    long number = 4003600000000014;
    long digit = floor(log10(number)) + 1;
    printf("Length is: %li\n", digit);
    long arr[digit];
    int i;
    for (i = digit; i > 0; i--) {
        arr[digit-i] = (long)(number/pow(10,i-1)) % 10;
        printf("%li : %li\n", digit-i, arr[digit-i]);
    }
}