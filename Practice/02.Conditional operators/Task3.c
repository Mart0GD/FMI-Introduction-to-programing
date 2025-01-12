#include<stdio.h>

/*
Напишете програма, която прочита от конзолата цяло число в интервала [1, 12], което ще репрезентира месец от годината и извежда колко дни има в месеца.
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