#include<stdio.h>
#include<math.h>

/*
Напишете програма, която прочита цяло неотрицателно число от конзолата и:

принтираме обратното му,
сбора на цифрите му,
палиндром ли е числото,
нарцистично ли е числото,
Едно число ще бъде нарцистично, ако сбора на всяка от цифрите му, повдигнато на броя на цифрите е равен на числото.

Пример за нарцистично число:

153 = 1^3 + 5^3 + 3^3;

Едно число е палиндром, ако то е симетрично.
*/
int main8()
{
	int number;
	scanf_s("%d", &number);

	int digit = 0;
	int sumOfDigits = 0;
	int palindome = 0;
	int digitsCount = 0;
	int numberTemp = number;

	while (numberTemp != 0)
	{
		digit = numberTemp % 10;
		numberTemp /= 10;

		palindome += digit;
		if (numberTemp != 0) { palindome *= 10; }

		sumOfDigits += digit;
		digitsCount++;
	}

	printf("Reversed -> %d\n", palindome);
	printf("Sum of digits -> %d\n", sumOfDigits);

	int narcissisticNumber = 0;
	numberTemp = number;
	for (int i = 0; i < digitsCount; i++)
	{
		digit = numberTemp % 10;
		numberTemp /= 10;

		narcissisticNumber += pow(digit, digitsCount);
	}

	printf("Is number narcissistic -> %d\n", narcissisticNumber == number);
	printf("Is number Palindrome -> %d\n", palindome == number);
}