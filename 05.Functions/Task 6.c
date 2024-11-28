#include<stdio.h>
#include<limits.h>

/*
Напишете програма, която прочита 2 цели числа start и end и принтира всички числа в интервала [start, end], които имат еднакви съседни цифри (примерни числа: 77, 112, 100). В реализацията на тази програма създайте и използвайте функция предикат hasNeighboringIdenticalDigits.
*/

int hasNeighboringIdenticalDigits(int number)
{
	int currentDigit = INT_MIN;
	int previousDigit = INT_MAX;

	while (number != 0)
	{
		currentDigit = number % 10;
		number /= 10;

		if (currentDigit == previousDigit)
		{
			return 1;
		}

		previousDigit = currentDigit;
	}

	return 0;
}

int main_6()
{
	int start, end;
	scanf_s("%d %d", &start, &end);

	for (int i = start; i <= end; i++)
	{
		if (hasNeighboringIdenticalDigits(i))
		{
			printf("%d\n", i);
		}
	}
}