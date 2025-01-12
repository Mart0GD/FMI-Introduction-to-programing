#include<stdio.h>

//Напишете програма, която прочита 2 числа от конзолата и проверява дали 2рото се съдържа в първото. infix
int main_17_2()
{// 127823 27
	int number, potentialInfix;
	scanf_s("%d %d", &number, &potentialInfix);

	if (potentialInfix > number)
	{
		puts("Not an infix");
		return 0;
	}

	int numberCopy = number;
	int potentialInfixCopy = potentialInfix;
	int changed = 0;
	while (potentialInfixCopy > 0)
	{
		if (numberCopy == 0 && potentialInfix > 0)
		{
			puts("Not an infix");
			return 0;
		}

		if (numberCopy % 10 == potentialInfixCopy % 10)
		{
			potentialInfixCopy /= 10;
			numberCopy /= 10;
			changed = 1;
			continue;
		}

		if (changed && (numberCopy % 10 != potentialInfixCopy % 10))
		{
			potentialInfixCopy = potentialInfix;
			changed = 0;
			continue;
		}
		
		numberCopy /= 10;
	}

	printf("Number is infix");

	return 0;
}