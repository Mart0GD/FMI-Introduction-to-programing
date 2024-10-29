#include <stdio.h>

int main1()
{
    unsigned int a;
    unsigned int b;

    scanf_s("%u %u", &a, &b);

    printf("!a -> %u\n", ~a);
    printf("!b -> %u\n", ~b);
    printf("a && b -> %u\n", a & b);
    printf("a || b -> %u\n", a | b);
    printf("a ^ b -> %u\n", a ^ b);

    return 0;
}