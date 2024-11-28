#include<stdio.h>
#include<limits.h>

/*
�������� ��������, ����� ������� ���� ������������� ����� n �� ���������, ���� ����� ������� ��� n ������ �����. �������� �� ��������� ��� �� ��� � ���-�������, ���-�������� � ����� � ������-������������� �� ��������, ���� ����� �� ��� � ���������� �� 2��� ������ ���� ���������.
*/

int main_5()
{
	int n;
	scanf_s("%d", &n);

	int min = INT_MAX;
	int max = INT_MIN;
	double avg;

	for (int i = 0; i < n; i++)
	{
		int number;
		scanf_s("%d", &number);

		min = number < min ? number : min;
		max = number > max ? number : max;
	}

	avg = (min + max) / 2.0;

	printf("Min = %lf\n", (double)min);
	printf("Max = %lf\n", (double)max);
	printf("Average = %.2lf\n", avg);

	return 0;
}