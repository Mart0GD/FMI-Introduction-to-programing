#include<stdio.h>
#include<math.h>

/*
�������� ��������, ����� ������� ���� ������������� ����� �� ��������� �:

���������� ��������� ��,
����� �� ������� ��,
��������� �� � �������,
����������� �� � �������,
���� ����� �� ���� �����������, ��� ����� �� ����� �� ������� ��, ���������� �� ���� �� ������� � ����� �� �������.

������ �� ����������� �����:

153 = 1^3 + 5^3 + 3^3;

���� ����� � ���������, ��� �� � ����������.
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