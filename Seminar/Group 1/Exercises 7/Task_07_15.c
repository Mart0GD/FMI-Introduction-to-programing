#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main_07_15() {
    const unsigned int MAX = 2147483647;
    const unsigned int SQRT_MAX = (unsigned int)sqrt(MAX);

    unsigned char* is_prime = (unsigned char*)malloc((MAX + 1) * sizeof(unsigned char));
    if (!is_prime) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (unsigned int i = 0; i <= MAX; i++) {
        is_prime[i] = 1;
    }

    is_prime[0] = 0;
    is_prime[1] = 0;

    for (unsigned int p = 2; p <= SQRT_MAX; p++) {
        if (is_prime[p]) {
            for (unsigned int multiple = p * p; multiple <= MAX; multiple += p) {
                is_prime[multiple] = 0;
            }
        }
    }

    unsigned int primesCount = 0;
    for (unsigned int i = 2; i <= MAX; i++) {
        if (is_prime[i]) {
            primesCount++;
        }
    }

    printf("Total number of primes up to %u: %u\n", MAX, primesCount);
    free(is_prime);
    return 0;
}
