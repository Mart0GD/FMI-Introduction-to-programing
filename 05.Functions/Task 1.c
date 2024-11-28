#include<stdio.h>

/*
Напишете програма, която прочита от конзолата цяло число и принтира абсолютната стойност на числото. В решението на задачата създайте и използвайте
функция absolute, която приема цяло число като аргумент и връща цяло чисо.
*/

int absolute(int number) {
	return number < 0 ? -number : number;
}

int main_1()
{
	int number;

	scanf_s("%d", &number);
	
	printf("%d", absolute(number));
	return 0;
}