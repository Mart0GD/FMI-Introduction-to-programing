#include<stdio.h>
#include<math.h>

/*
Задача 3: Да се напише програма, която приема две цели положителни числа – a и b и отпечатва всички числа, цифрите на които са различни.
Вход: 20 35,
Изход: 20, 21, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 34, 35
Вход: 120 135,
Изход: 120, 123, 124, 125, 126, 127, 128, 129, 130, 132, 134, 135
Вход: 20 1,
Изход:
*/
int main_03_03()
{
	int bottom, top;
	scanf_s("%d %d", &bottom, &top);

	int isNumberComposedOfDiffrentNumbers = 0;

	int numberTemp;
	int currentDigit;
	int remainingNumber;
	for (int i = bottom; i <= top; i++)
	{
		numberTemp = i;  
		isNumberComposedOfDiffrentNumbers = 1;

		while (numberTemp != 0)
		{
			currentDigit = numberTemp % 10;
			remainingNumber = numberTemp / 10;
			numberTemp /= 10;

			while (remainingNumber != 0)
			{
				if (remainingNumber % 10 == currentDigit)
				{
					isNumberComposedOfDiffrentNumbers = 0;
					numberTemp = 0;
					break;
				}
				remainingNumber /= 10;
			}
		}
		
		if (isNumberComposedOfDiffrentNumbers)
		{
			printf("%d ", i);
		}

	}

	return 0;
}