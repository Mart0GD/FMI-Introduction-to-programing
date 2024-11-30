#include<stdio.h>
#include<limits.h>
/*
������ 1: �� �� ������ �������, ����� ������ ���� ����������� ����� n � ����� ���� �����, ����� �� ������ �� ������ �����, �� ��������� � �������� ���.
����: 531261, �����: 112356
*/

int getCurrentNumberOccurances(int number, int currentDigit) {
	
	int counter = 0;
	while (number)
	{
		if (number % 10 == currentDigit)
		{
			counter++;
		}

		number /= 10;
	}

	return counter;
}

int sortNumber(int number) {

	int currentNumberSeenCount = 0;
	int sortedNumber = 0;
	for (int i = 0; i <= 9; i++)
	{
		int currentNumberSeenCount = getCurrentNumberOccurances(number, i);

		for (int j = 0; j < currentNumberSeenCount; j++)
		{
			sortedNumber *= 10;
			sortedNumber += i;
		}
	}

	return sortedNumber;
}

int main_04_01() {
	int number = 0;
	scanf_s("%d", &number);

	int sortedNumber = sortNumber(number);

	printf("Sorted number -> %d", sortedNumber);
	return 0;
}