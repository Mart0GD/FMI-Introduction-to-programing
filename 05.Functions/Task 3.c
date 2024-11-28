#include<stdio.h>

/*
Напишете програма, която прочита реално число и го принтира числото закръглено до 2 символа след запетаята. В решението на задачата създайте и използвайте функция printRealNumber, която приема реално число като аргумент и не връща нищо.
*/
void printRealNumber(double number)
{
	printf("%.2lf", number);
}

int main_3()
{
	double number;
	scanf_s("%lf", &number);
	printRealNumber(number);
}