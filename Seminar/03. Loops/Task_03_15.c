#include<stdio.h>
#include<math.h>
/*
������ 15: �������� ��������, ����� ������ ��� ���������� ����� n � k � �������� ���������� �� log_k(n), ���������� ������.
����: 16 2, �����: 4
����: 100000 2, �����: 16
����: 35 3, �����: 3
����: 256 16, �����: 2
*/
int main_03_15()
{
	int  base, product;
	scanf_s("%d %d", &product , &base);

	int power = 0;
	int newNumber = 1;
	while (newNumber <= product)
	{
		power++;  
		newNumber *= base;
	}

	printf("%d", power - 1);
	return 0;
}