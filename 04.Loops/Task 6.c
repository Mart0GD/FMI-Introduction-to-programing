#include<stdio.h>

// Напишете програма, която прочита 2 цели числа и връща най-големият им общ делител.
int main_6()
{
	int numberOne;
	int numberTwo;
	scanf_s("%d %d", &numberOne, &numberTwo);

	if (numberOne == numberTwo)
	{
		printf("%d", numberOne);
	}

	int a = numberOne < numberTwo ? numberTwo : numberOne;
	int b = a == numberOne ? numberTwo : numberOne;

	if (b == 0)
	{
		puts("No LCD!");
		return 0;
	}

	int k = 0;
	while (b != 0)
	{
		k = a % b;
		a = b;
		b = k;
	}

	printf("%d", a);
	return 0;
}