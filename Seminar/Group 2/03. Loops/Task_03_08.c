#include<stdio.h>
#include<math.h>
// ������ 8: �� �� ������ ��������, ����� �� �������� ���� ����������� ����� ������� �������� ��� ����:
/*
3:
  3
 23
123
 23
  3
*/
int main_03_8()
{
	int number = 0;
	scanf_s("%d", &number);

	int steps = (number * 2) - 1; // 2 -> 3
	for (int i = 1; i <= steps; i++)
	{
		int absDiffrence = abs(number - i);
		for (int x = 0; x < absDiffrence; x++)
		{
			printf(" ");
		}

		for (int y = absDiffrence + 1; y <= number; y++)
		{
			printf("%d", y);
		}

		puts("");
	}
	return 0;
}