#include<stdio.h>

/*
������ 8: ������� �� ���������� ���� ����� n.

��� ���������� ����� �� ���������� ����� � 0, 2, 4, 6 ��� 8, ���� ����� �� �� ������ � ��������� �� ������� �� ����� 3.
��� ���������� ����� �� ���������� ����� � 1, 3, 5, 7 ��� 9, ���� ����� �� �� ������ � ��������� �� ������� �� ����� 2.
����: 123, �����: 121
����: 718, �����: 712
*/
int main_02_08()
{
	int number;
	scanf_s("%d", &number);

	int lastNumber = number % 10;
	number = (number - lastNumber) + ( lastNumber % 2 == 0 ? lastNumber % 3 : lastNumber % 2);

	printf("-> %d", number);

	return 0;
}