#include<stdio.h>
#include<math.h>

/*
�������� ��������, ����� ������� ���� ����� � �������� ��������� �� ������������� (�� ���-�������� ��� ���-������� ���). ������� �� ���������� �������� 0 (����� �� 5 �� ����������� "00000000000000000000000000000101", � ����������� "101").
*/
int main_10()
{
	const int intSize = (sizeof(int) * 8) - 1;

	int number;
	scanf_s("%d", &number);

	if (number == 0)
	{
		puts("0");
		return 0;
	}

	int mostSignifficantBitPlace = number > 0 ? log2(number) + 1 : intSize;
	
	for (int i = mostSignifficantBitPlace; i > 0; i--)
	{
		printf("%d", (number >> (i == 0 ? 0 : i - 1)) & 1);
	}

	return 0;
}