#include<stdio.h>
#include<math.h>

/*
�������� ��������, ����� ������ ��� ���� ����� � ��������� ���� �� ��������� ������� ���� (��� � �����) � ��������.
��� ������ � �������, ���������� ������ �� ������ ��������� �valid date�, � �������� ������ �invalid date�. �� �����������, ���������� ����������� ������.
*/
int main13()
{
	int day, month;
	scanf_s("%d %d", &day, &month);

	int isDayCorrect;
	switch (month)
	{
		case 1:
			isDayCorrect = day > 0 && day <= 31;
		break;

		case 2:
			isDayCorrect = day > 0 && day <= 28;
			break;

		case 3:
			isDayCorrect = day > 0 && day <= 31;
			break;

		case 4:
			isDayCorrect = day > 0 && day <= 30;
			break;

		case 5:
			isDayCorrect = day > 0 && day <= 31;
			break;

		case 6:
			isDayCorrect = day > 0 && day <= 30;
			break;

		case 7:
			isDayCorrect = day > 0 && day <= 31;
			break;

		case 8:
			isDayCorrect = day > 0 && day <= 31;
			break;

		case 9:
			isDayCorrect = day > 0 && day <= 30;
			break;

		case 10:
			isDayCorrect = day > 0 && day <= 31;
			break;

		case 11:
			isDayCorrect = day > 0 && day <= 30;
			break;

		case 12:
			isDayCorrect = day > 0 && day <= 31;
			break;

		default:
			printf("Invalid day!!!");
			return;
	}

	if (!isDayCorrect)
	{
		printf("Invalid day!!!");
		return;
	}

	printf("day is Valid");
}