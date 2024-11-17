#include<stdio.h>
/*
Задача 6: Въвежда се цяло число. Да се напише програма, която отпечата с думи кой ден от седмицата е.
Вход: 1, Изход: Monday
Вход: 5, Изход: Friday
Вход: 250, Изход: Invalid day!
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