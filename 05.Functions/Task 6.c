#include<stdio.h>
#include<limits.h>

/*
�������� ��������, ����� ������� 2 ���� ����� start � end � �������� ������ ����� � ��������� [start, end], ����� ���� ������� ������� ����� (�������� �����: 77, 112, 100). � ������������ �� ���� �������� �������� � ����������� ������� �������� hasNeighboringIdenticalDigits.
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