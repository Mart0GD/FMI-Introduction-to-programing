#include<stdio.h>

/*
�������� ��������, ����� ������� �� ��������� ���� ����� � ��������� [1, 12], ����� �� ������������ ����� �� �������� � ������� ����� ��� ��� � ������.
*/
int main3()
{
	int month;
	scanf_s("%d", &month);

	int days = 0;
	switch (month) {
		default: days++;

		case 4:
		case 6:
		case 9:
		case 11: 
			days += 30;
			break;

		case 2:
			days += 28;
			break;
	}

	printf("%d", days);
	return 0;
}