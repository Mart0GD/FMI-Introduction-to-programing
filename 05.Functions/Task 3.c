#include<stdio.h>

/*
�������� ��������, ����� ������� ������ ����� � �� �������� ������� ���������� �� 2 ������� ���� ���������. � ��������� �� �������� �������� � ����������� ������� printRealNumber, ����� ������ ������ ����� ���� �������� � �� ����� ����.
*/
void printRealNumber(double number)
{
	printf("%.2lf", number);
}

int main_3()
{
	double number;
	scanf_s("%lf", &number);
	printRealNumber(number);
}