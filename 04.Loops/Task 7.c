#include<stdio.h>
#include<math.h>

/*
�������� ��������, ����� ������� ���� ����������� ����� �� ��������� � ����� ���� �� � ������ � ���� �� � ���������.

������ ����� �� �������� �����, ��-������ �� 1, ����� ��� ���� 2 �������� - 1 � ���� ��. (������� �� ������ �����: 2, 3, 5, 7, 11)

��������� ����� �� �������� �����, ����� � ����� �� ������ �� �������� ��������, ��� ����. (������: 6 = 1 + 2 + 3)
*/
int main_7()
{
	int number;
	scanf_s("%d", &number);

	int isPrime = 1;
	for (int i = 2; i < number / 2; i++)
	{
		if (number % i == 0)
		{
			isPrime = 0;
			break;
		}
	}
	
	int sum = 0;
	for (int i = 1; i < number; i++)
	{
		if (number % i == 0)
		{
			sum += i;
		}
	}

	int isPerfect = sum == number;
	printf("Prime: %d\n", isPrime);
	printf("Perfect: %d", isPerfect);

	return 0;
}