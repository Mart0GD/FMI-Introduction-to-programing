#include<stdio.h>

int main7()
{
	unsigned int number;
	unsigned int n;
	scanf_s("%u %u", &number, &n);

	unsigned int newNumber = number | 1 << n;

	printf("new number is -> %u", newNumber);

	return 0;
}