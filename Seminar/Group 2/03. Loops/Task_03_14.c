#include<stdio.h>

/*
Задача 14: Напишете програма, която приема две естествени числа a и b и намира броя естествени числа в интервала [a, b], такива че сумата и произведението от цифрите им съвпадат.
Вход: 1 10, Изход: 9
Вход: 120 125, Изход: 1
Вход: 125 120, Изход: 0
*/
int main_03_14()
{
	int bottom, top;
	scanf_s("%d %d", &bottom, &top);

	int countOfNumbersWithEqualProductAndSumOfDigits = 0;
	int currentNumberCopy;
	int currentDigit = 0;
	int sumOfdigits = 0;
	int productOfDigits = 1;
	for (int i = bottom; i < top; i++)
	{
		currentNumberCopy = i;
		sumOfdigits = 0;
		productOfDigits = 1;
		while (currentNumberCopy != 0)
		{
			currentDigit = currentNumberCopy % 10;
			currentNumberCopy /= 10;

			sumOfdigits += currentDigit;
			productOfDigits *= currentDigit;
		}

		if (sumOfdigits == productOfDigits)
		{
			countOfNumbersWithEqualProductAndSumOfDigits++;
		}
	}

	printf("%d", countOfNumbersWithEqualProductAndSumOfDigits);
	return 0;
}