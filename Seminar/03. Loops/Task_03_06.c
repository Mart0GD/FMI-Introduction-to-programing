#include<stdio.h>

/*
������ 6: ������� �� ���� ����� n, ���������� �� n �� ���� �����.
�� �� ������ ��������, ����� ��������� �������, ���������� �� ������� �����, �������� �� 2.
*/
int main_03_06()
{
	int n;
	scanf_s("%d", &n);

	int currentNumber = 0;
	int finalNumber = 0;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &currentNumber);

		if (currentNumber % 2 == 0)
		{
			finalNumber *= 10;
			finalNumber += currentNumber;
		}
	}

	printf("%d", finalNumber * 2);
	return 0;
}