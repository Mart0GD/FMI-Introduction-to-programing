#include<stdio.h>
#include<math.h>

/*
�������� ��������, ����� �� ����� ���� ���� ����������, ����� ���� �� �������� �������� ��������:

+ -> ������ 2 �����;
- -> ������� 2 �����;
* -> �������� 2 �����;
/ -> ���� 2 �����;
^ -> ������� ���� ����� �� ���������� ������;
V -> ������ ����� ��������� �� 1 �����;
~ -> ������ ����� (��������� ��������) �� 1 �����;
���������� ����� �� ������� ������ �� ���������, ���� ������ ������ �� � ������� ������ ����-���������� (��� �� �, ���� �� �� ������ ��������� ��������� � ���������� �� �������� �������� ��) � ��   ������� ����� ����� (������) ������ �� �������, �� �� ���� �� ������� �������� ����������. ���� ���������� �� ���������� �������� ��������� ���������� �� 2���� ����� ���� ���������.*/

int main6()
{
	char operation;
	scanf_s("%c", &operation);

	float inputOne;
	float inputTwo;
	float result;
	switch (operation)
	{
		case '+':
			puts("insert two numbers:");
			scanf_s("%f %f", &inputOne, &inputTwo);

			result = inputOne + inputTwo;
			break;

		case '-':
			puts("insert two numbers:");
			scanf_s("%f %f", &inputOne, &inputTwo);

			result = inputOne - inputTwo;
			break;

		case '*':
			puts("insert two numbers:");
			scanf_s("%f %f", &inputOne, &inputTwo);

			result = inputOne * inputTwo;
			break;

		case '/':
			puts("insert two numbers:");
			scanf_s("%f %f", &inputOne, &inputTwo);

			result = inputOne / inputTwo;
			break;

		case '^':
			puts("insert number and power:");
			scanf_s("%f %f", &inputOne, &inputTwo);

			result = pow(inputOne, inputTwo);
			break;

		case 'V':
			puts("insert number:");
			scanf_s("%f", &inputOne);

			result = sqrt(inputOne);
			break;

		case '~':
			puts("insert number:");
			scanf_s("%f", &inputOne);

			result = abs(inputOne);
			break;

		default:
			puts("no operation found!");
			return;
	}

	printf("%.2f", result);
	return 0;
}