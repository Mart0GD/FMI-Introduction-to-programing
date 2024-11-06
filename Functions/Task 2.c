#include<stdio.h>

/*
Напишете програма, която прочита от конзолата цяло число и принтира на конзолата знака на числото (за нула нека връща '0'). В решението на задачата създайте и използвайте създайте функция sign, което приема цяло число като аргумент и връща символ.
*/

char sign(int number) {
	int isPositive = number > 0;

	return isPositive ? "+" : "-";
}

int main2()
{
	int number;
	scanf_s("%d", &number);

	if (number == 0)
	{
		puts("0");
		return 0;
	}

	printf("%s", sign(number) == 1 ? "-" : "+");
}