#include<stdio.h>

/*
������ 14: �������� ��������, ����� ������ ��� ���������� ����� a � b � ������ ���� ���������� ����� � ��������� [a, b], ������ �� ������ � �������������� �� ������� �� ��������.
����: 1 10, �����: 9
����: 120 125, �����: 1
����: 125 120, �����: 0
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