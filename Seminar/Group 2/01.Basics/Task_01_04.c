#include<stdio.h>

/*
������ 4: ������� �� ���� ���������� �����. �� �� �������� ���������� �����, ������� � �������.
����: 265, �����: 563
����: 289, �����: 983
*/
int main01_4()
{
	int number;
	scanf_s("%d", &number);

	int digitOne = number % 10;
	int digitTwo = (number / 10) % 10;
	int digitThree = (number / 100) % 10;

	int newNumber = ((((digitOne * 10) + digitTwo) * 10) + digitThree);

	printf("%d", newNumber + 1);
	return 0;
}