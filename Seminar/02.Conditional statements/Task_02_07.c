#include<stdio.h>

/*
������ 7 (����������): �������� �� ��� ������ ����� � ���� �������� (+, -, *, /). �������� ���������� ����������, ����� �������� ���������� �������� ����� ������ �����.
����: 7 9 +, �����: 16
����: 10 3 /, �����: 3.33333
����: 5 23 $, �����: Invalid operation!
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