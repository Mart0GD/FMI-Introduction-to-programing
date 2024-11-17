#include<stdio.h>

int main()
{
	unsigned int number;

	scanf_s("%u", &number);

	int isNumberAPowerOfTwo = number != 1 && number != 0 && (number & (number - 1)) == 0;

	printf("%u", isNumberAPowerOfTwo);

	return 0;
}
//0000 0010 02 002 2 2 STX control - B
//0000 0010 02 002 2 2 STX control - B
//0000 0100 04 004 4 4 EOT control - D
//0000 1000 08 010 8 8 BS control - H
//0001 0000 10 020 16 16 DLE control - P