#include<stdio.h>

/*
�������� ��������, ����� ������� �� ��������� ���� ����� � �������� ����������� �������� �� �������. � ��������� �� �������� �������� � �����������
������� absolute, ����� ������ ���� ����� ���� �������� � ����� ���� ����.
*/

int absolute(int number) {
	return number < 0 ? -number : number;
}

int main_1()
{
	int number;

	scanf_s("%d", &number);
	
	printf("%d", absolute(number));
	return 0;
}