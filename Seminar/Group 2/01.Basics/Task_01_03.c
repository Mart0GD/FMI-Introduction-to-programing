#include<stdio.h>

/*
Задача 3: Въвеждат се две цели числа. Да се отпечата по-голямото от двете.
Вход: 265, 44, Изход: 265
*/
int main01_3()
{
	int number1, number2;
	scanf_s("%d %d", &number1, &number2);

	int number1Bigger = number1 > number2;
	int biggerNumber = number1Bigger * number1 + !(number1Bigger)*number2;

	printf("%d", biggerNumber);
	return 0;
}