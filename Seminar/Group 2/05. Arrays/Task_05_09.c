#include<stdio.h>

/*
������ 9: �������� �������, ����� ������ ���� k � ������� � ����� ����������� �� k-��� ��� �� ����������� �� ������. �������� �� �������� ������� �� �������!
����: 6, �����: 1 5 10 10 5 1
*/

//n!/k!(n-k)!
int main_05_09() {
	int n = 0;
	scanf_s("%d", &n);

	int nFactorial = 1;
	int kFactorial = 1;
	int nMinusKFactorial = 1;

	for (int i = 1; i <= n; i++)
	{
		nFactorial *= i;
	}

	for (int k = 0; k <= n; k++)
	{
		kFactorial = 1;
		nMinusKFactorial = 1;

		for (int i = 1; i <= k; i++)
		{
			kFactorial *= i;
		}

		for (int j = 1; j <= n - k; j++)
		{
			nMinusKFactorial *= j;
		}

		printf("%d ", nFactorial / (kFactorial * nMinusKFactorial));
	}

	return 0;
}