#include<stdio.h>

int main9()
{
	const int MASK = 7;

	unsigned int number;
	scanf_s("%u", &number);

	//0000 0000 0000 0000 0000 0000 1010 1010 
	// ^
	//0000 0000 0000 0000 0000 0000 0000 0111
	// 
	//0000 0000 0000 0000 0000 0000 1010 1101 

	unsigned int newNumber = number ^ MASK;

	printf("new number is -> %u", newNumber);

	return 0;
}