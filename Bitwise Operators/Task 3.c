#include<stdio.h>

int main3()
{
	unsigned int n;

	scanf_s("%u", &n);

	// 10
	// 100
	// 1000
	// 10000

	long long int twoToThePowerOfN = 1 << n;

	printf("2^n -> %llu", twoToThePowerOfN);
}