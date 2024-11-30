#include<stdio.h>
#include<math.h>
/*
������ 3: �� �� ������ �������, ����� ������ ���� ����������� ����� n � ��������� ������ ������� �� n, ����� �� ������.
��������� 1: ����� ����� � ������ �� ���� ��!
��������� 2: ��� ��������� �� ������ �������, �� �� ��������� ��������.
����: 123432, �����: 2, 3, 43, 12343, 3, 23, 2
����: 753, �����: 3, 53, 5, 7
����: 149, �����: 149
*/

int reverseNumber(int number) {
	int reversed = 0;
	while (number != 0)
	{
		reversed *= 10;
		reversed += number % 10;
		number /= 10;
	}

	return reversed;
}

int numberLength(int number) {

	int length = 0;
	while (number != 0){
		number /= 10;
		length++;
	}

	return length;
}

int isPrime(int number) {
	if (number == 1) return 0;

	int sqrtNumber = sqrt(number);
	for (int i = 2; i <= sqrtNumber; i++)
	{
		if (number % i == 0)
		{
			return 0;
		}
	}

	return 1;
}

void printfAllPrimeInfixes(int number) {

	int length = numberLength(number);
	int currentNumber = 0;

	int numberCopy = reverseNumber(number);
	for (int i = 0; i < length; i++)
	{
		currentNumber = 0;
		for (int j = 0; j < length - i; j++)
		{
			currentNumber *= 10;
			currentNumber += numberCopy % 10;
			numberCopy /= 10;

			if (isPrime(currentNumber))
			{
				printf("%d ", currentNumber);
			}
		}
		numberCopy = reverseNumber(number) / pow(10, i + 1);
	}
}

int main_04_03() {

	int number = 0;
	scanf_s("%d", &number);

	printfAllPrimeInfixes(number);
	return 0;
}