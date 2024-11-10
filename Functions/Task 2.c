#include<stdio.h>

/*
�������� ��������, ����� ������� �� ��������� ���� ����� � �������� �� ��������� ����� �� ������� (�� ���� ���� ����� '0'). � ��������� �� �������� �������� � ����������� �������� ������� sign, ����� ������ ���� ����� ���� �������� � ����� ������.
*/

char sign(int number) {
	int isPositive = number > 0;

	return isPositive ? "+" : "-";
}

int main2()
{
	int number;
	scanf_s("%d", &number);

	if (number == 0)
	{
		puts("0");
		return 0;
	}

	printf("%s", sign(number) == 1 ? "-" : "+");
}