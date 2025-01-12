#include<stdio.h>
#include<math.h>

/*
Напишете програма, която ще служи като мини калкулатор, който може да извършва следните операции:

+ -> Събира 2 числа;
- -> Изважда 2 числа;
* -> Умножава 2 числа;
/ -> Дели 2 числа;
^ -> Повдига едно число на определена степен;
V -> Намира корен квадратен на 1 число;
~ -> Намира модул (абсолютна стойност) на 1 число;
Програмата първо ще прочита символ от конзолата, този символ трябва да е валиден спрямо горе-изброените (ако не е, нека да се изведе подходящо съобщение и програмата да приключи работата си) и да   прецени колко числа (реални) трябва да прочете, за да може да изпълни коректно операцията. След изпълнение на операцията принтира резултата форматиран до 2рото число след запетаята.*/

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