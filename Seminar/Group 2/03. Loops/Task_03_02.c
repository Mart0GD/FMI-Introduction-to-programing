#include<stdio.h>
#include<math.h>

/*
Задача 2: Да се напише програма, която приема две цели положителни числa – a и b и отпечатва всички прости числа в интервала [a, b].
Вход: 10 20, Изход: 11, 13, 17, 19
Вход: 1 20, Изход: 2 3 5 7 11 13 17 19
Вход: 20 1, Изход:
*/
int main_03_02()
{
	int bottom, top;
	scanf_s("%d %d", &bottom, &top);

	int isPrime = 0;
	int numSqrt = 0;
	for (int i = bottom; i <= top; i++)
	{
		isPrime = 1;
		numSqrt = sqrt(i);
		for (int j = 2; j <= numSqrt; j++)
		{
			if (i % j == 0)
			{
				isPrime = 0;
				break;
			}
		}

		if (isPrime && i != 1)
		{
			printf("%d ", i);
		}
	}

	return 0;
}