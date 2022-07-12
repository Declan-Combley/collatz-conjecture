#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int is_odd(unsigned long long n)
{
    if (n % 2 == 0) {
        return 0;
    }

    return 1;
}

typedef unsigned long long num;

int main(int argc, char **argv)
{
    assert(argv != NULL);

    num number = 27;
    
    if (argc == 2) {
        number = atoll(argv[1]);
    }
    
    clock_t t;
    t = clock();

    printf("x = %lld \n", number);

    num itter = - 1;
    
    while (1) {
        itter++;
        if (is_odd(number) == 1) {
            num result = number * 3 + 1;
            printf("%lld * 3 + 1 -> %lld\n", number, result);
            number = number * 3 + 1;
        } else {
            num result = number / 2;
            printf("%lld / 2 -> %lld\n", number, result);
            number = number / 2;
        }

        if (number == 1) {
            break;
        }
    }
    
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    t = clock() - t;
    printf("\nFinished In %lld itterations And %f seconds\n", itter, time_taken);

    return 0;
}
