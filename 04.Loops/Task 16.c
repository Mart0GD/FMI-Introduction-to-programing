#include<stdio.h>

/*
�������� ��������, ����� ������� 2 ���� ����� �� ���������, ������ ������� ���� � ������� � �� �������� �� ���������. 
������������ ���������� � ����������� �� 2�� �����, ����������� ���� �������� ��������� ��������.
*/
int main16()
{
	int numberOne, numberTwo;
	scanf_s("%d %d", &numberOne, &numberTwo);

	int msbNumberOne = log2(numberOne) + 1;
	int msbNumberTwo = log2(numberTwo) + 1;
	int smaller = msbNumberOne < msbNumberTwo ? msbNumberOne : msbNumberTwo;

	int stepover = 0;
	int mask = 1;
	int product = 0;
	for (int i = 0; i < smaller; i++)
	{
		int biggerNumberCurrentBit = numberOne & mask;
		numberOne >>= 1;

		int smallerNumberCurrentBit = numberTwo & mask;
		numberTwo >>= 1;


	}

	return 0;
}