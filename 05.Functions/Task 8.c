#include<stdio.h>

/*
�������� ��������, ����� ������� ���� ����� � �������� �� ��������� ����� �� �������� ������ ���� ���-�������� �������. �������� � ����������� ����������� �������.
*/

int findChildBitIndex(int number) {
	int index = -1;

	int counter = 0;
	while (index < 0)
	{
		index = number >> counter & 1 ? counter : -1;
		counter++;
	}

	return index;
}

void printZerosInNumberUntilChildBit(int number, int indexOfChildBit)
{
	for (int i = 0; i < indexOfChildBit; i++)
	{
		printf("0");
	}
}

int main_08()
{
	int number = 0;
	scanf_s("%d", &number);

	int indexOfChildBit = findChildBitIndex(number);

	if (indexOfChildBit == 0)
	{
		puts("Child bit is at index 0!");
		return 0;
	}

	printZerosInNumberUntilChildBit(number, indexOfChildBit);
	return 0;
}