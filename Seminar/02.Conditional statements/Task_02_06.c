#include<stdio.h>
/*
������ 6: ������� �� ���� �����. �� �� ������ ��������, ����� �������� � ���� ��� ��� �� ��������� �.
����: 1, �����: Monday
����: 5, �����: Friday
����: 250, �����: Invalid day!
*/

int main02_06()
{
	int dayOfTheWeek;
	scanf_s("%d", &dayOfTheWeek);

	switch (dayOfTheWeek) {

		case 1 :
			puts("Monday");
		break;
		case 2:
			puts("Tuesday");
			break;
		case 3:
			puts("Wednesday");
			break;
		case 4:
			puts("Thursday");
			break;
		case 5:
			puts("Friday");
			break;
		case 6:
			puts("Saturday");
			break;
		case 7:
			puts("Sunday");
			break;
		default:
			puts("Invalid day!");
			break;
	}

	return 0;
}