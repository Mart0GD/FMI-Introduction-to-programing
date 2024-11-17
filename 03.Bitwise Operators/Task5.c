#include<stdio.h>

int main5()
{
	const int MASK = 1;

	unsigned int number;  
	scanf_s("%u", &number);

	int isNumberEven = !(number & MASK);

	printf("the number is (1 for even 0 for odd): %u", isNumberEven);

	return 0;
}