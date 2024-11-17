#include<stdio.h>

int main10()
{
	const int MASK = 0b10101010101010101010101010101010;
	unsigned int number;

	// 0101 0101 0101 0101 0101 0101 0101 0100
	//
	// 1010	1010 1010 1010 1010 1010 1010 1010	
	//
	// 1111 1111 1111 1111 1111 1111 1111 1110

	scanf_s("%u", &number);

	unsigned int newNumber = number ^ MASK;

	printf("new number is -> %u", newNumber);

	return 0;
}