#include<stdio.h>

// ������ 7: �� �� ������ ��������, ����� ������ ���� ����������� ����� n � ��������� ������� �� 1 �� n*n � ������������ ���.
int main_03_07()
{
	int number = 0;
	scanf_s("%d", &number);

	int Pow2OfNumber = number * number;
	int currentRowMaxNumber = 0;
	for (int i = 1; i <= number; i++)
	{
		currentRowMaxNumber += number;
		if (i % 2 != 0)
		{
			for (int j = (currentRowMaxNumber - number) + 1; j <= currentRowMaxNumber; j++)
			{
				printf("%d ", j);
			}
		}
		else
		{
			for (int z = currentRowMaxNumber; z > currentRowMaxNumber - number; z--)
			{
				printf("%d ", z);
			}
		}
		
		puts("");
	}
	return 0;
}