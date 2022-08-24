#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int collatz_conjecture(unsigned long long n, int *itter)
{
    *itter = *itter + 1;

    if (n == 1) {
        printf("%lld\n", n);
        printf("finished in %d itterations\n", *itter);
        return n;
    }

    printf("%lld -> ", n);
    
    if (n % 2 == 0) { return collatz_conjecture(n / 2, itter); }
    
    return collatz_conjecture(n * 3 + 1, itter);
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
    int i = 1;
    int *itter = &i;

    if (n >= 999999999999999999) {
        fprintf(stderr, "error: input is too large: input must be less than 999999999999999999\n");
        exit(1);
    }
    
    collatz_conjecture(n, itter);

    return 0;
}
