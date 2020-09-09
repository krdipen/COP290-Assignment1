#include <stdio.h>

int myPattern(int n) {
    int i;
    int fact = 1;
    if (n < 0) {
        printf("Error! Factorial of a negative number doesn't exist.");
        return -1;
    }
    else {
        for (i = 1; i <= n; ++i) {
            fact *= i;
        }
    }
    return fact;
}
