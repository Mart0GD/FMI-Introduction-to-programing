#include<stdio.h>

/*
������ 3: �������� �� ��� ���� �����. �� �� �������� ��-�������� �� �����.
����: 265, 44, �����: 265
*/
int main01_3()
{
	int number1, number2;
	scanf_s("%d %d", &number1, &number2);

	int number1Bigger = number1 > number2;
	int biggerNumber = number1Bigger * number1 + !(number1Bigger)*number2;

	printf("%d", biggerNumber);
	return 0;
}