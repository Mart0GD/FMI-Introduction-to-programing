#include<stdio.h>

/*
�������� ��������, ����� ������� ���� ����� � �������� �� ��������� ����� �� ��������, ����� �� ����� �� 1. � �������� �� �������� �������� � ����������� ������� count1BitsInNumber, ����� ������ ���� ����� ���� �������� � ����� ���� �����.
*/

int count1BitsInNumber(int number)
{
	int oneBitsSum = 0;
	for (int i = 0; i < (sizeof(int) * 8); i++)
	{
		oneBitsSum += (number >> i) & 1;
	}

	return oneBitsSum;
}

int main()
{
	int number;
	scanf_s("%d", &number);

	printf("%d", count1BitsInNumber(number));
}