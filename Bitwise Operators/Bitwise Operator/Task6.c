#include<stdio.h>

int main6()
{
	unsigned int number;  
	unsigned int n;
	scanf_s("%u %u", &number, &n);

	int mask = 1 << n;
	int newNumber = number & ~(mask);

	printf("new number is -> %u", newNumber);

	return 0;
}