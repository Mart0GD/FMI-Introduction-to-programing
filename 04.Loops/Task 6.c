#include<stdio.h>

// �������� ��������, ����� ������� 2 ���� ����� � ����� ���-�������� �� ��� �������.
int main6()
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

	int k = 0;
	while (a % b != 0)
	{
		k = a % b;
		a = b;
		b = k;
	}

	printf("%d", k);
	return 0;
}