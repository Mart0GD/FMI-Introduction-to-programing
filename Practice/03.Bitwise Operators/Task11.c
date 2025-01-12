#include<stdio.h>

int main11()
{
	int number;

	scanf_s("%d", &number);

	int isNegative = (number >> 31) < 0;
	unsigned int newNumber = (((~number) + 1) * isNegative) + (!isNegative * number);

	printf("new number is -> %u", newNumber);

	return 0;
}