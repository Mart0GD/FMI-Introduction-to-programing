#include<stdio.h>

/*
Задача 7 (Калкулатор): Въвеждат се две реални числа и една операция (+, -, *, /). Напишете примитивен калкулатор, който поддържа изброените операции върху реални числа.
Вход: 7 9 +, Изход: 16
Вход: 10 3 /, Изход: 3.33333
Вход: 5 23 $, Изход: Invalid operation!
*/
int main02_07()
{
	double num1, num2;
	char operation;
	scanf_s("%lf %lf %c", &num1, &num2, &operation);

	switch (operation)
	{
		case '+':
			printf("%lf", num1 + num2);
			break;
		case '-':
			printf("%lf", num1 - num2);
			break;
		case '/':
			printf("%lf", num1 / num2);
			break;
		case '*':
			printf("%lf", num1 * num2);
			break;
		default:
			puts("Invalid operation!");
		break;
	}
	return 0;
}