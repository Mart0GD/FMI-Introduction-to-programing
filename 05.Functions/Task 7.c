#include<stdio.h>

/*
Напишете програма, която прочита цяло число и принтира на конзолата броят на битовете, които са равни на 1. В решенето на задачата създайте и използвайте функция count1BitsInNumber, която приема цяло число като аргумент и връща цяло число.
*/

int count1BitsInNumber(int number)
{
	int oneBitsSum = 0;
	for (int i = 0; i < (sizeof(int) * 8); i++)
	{
		oneBitsSum += (number >> i) & 1;
	}

	return oneBitsSum;
}

int main()
{
	int number;
	scanf_s("%d", &number);

	printf("%d", count1BitsInNumber(number));
}