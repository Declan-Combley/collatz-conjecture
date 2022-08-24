#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int collatz_conjecture(unsigned long long n)
{
    if (n == 1) {
        printf("%11lld  | * 3 + 1 \n", n);
        printf("%11d  | \\ 2  \n", 4);
        printf("%11d  | \\ 2  \n", 2);
        printf("%11d  | * 3 + 1\n", 1);
        printf("%10s...|  \n", " ");
        printf("%10s ..|  \n", " ");
        printf("%10s  .|  \n", " ");
        return n;
    }

    if (n % 2 == 0) { 
        printf("%11lld  | \\ 2  \n", n);
        return collatz_conjecture(n / 2);
    }
    
    printf("%11lld  | * 3 + 1  \n", n);
    return collatz_conjecture(n * 3 + 1);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "error: expected one argument: %d arguments is invalid\n", argc - 1);
        exit(1);
    }

    for (size_t i = 0; i < strlen(argv[1]); i++) {
        if (isdigit(argv[1][i] != 0)) {
            fprintf(stderr, "error: %s is invalid: must be an integer greater than 1\n", argv[1]);
            exit(1);
        }
    }

    if (atoll(argv[1]) <= 1) {
        fprintf(stderr, "error: input must be an integer greater than 1: %s is invalid\n", argv[1]);
        exit(1);
    }

    unsigned long long n = atoll(argv[1]);

    if (n >= 999999999999999999) {
        fprintf(stderr, "error: input is too large: input must be less than 999999999999999999\n");
        exit(1);
    }

    collatz_conjecture(n);

    return 0;
}
