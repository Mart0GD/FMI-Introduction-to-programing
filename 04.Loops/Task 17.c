#include<stdio.h>
#include<math.h>

//Напишете програма, която прочита 2 числа от конзолата и проверява дали 2рото се съдържа в първото.
int main_17()
{
	int numberOne, numberTwo;
	scanf_s("%d %d", &numberOne, &numberTwo);

	int sizeOfNumberOne = 0;
	int numberTemp = numberOne;
	while (numberTemp != 0)
	{
		numberTemp /= 10;
		sizeOfNumberOne++;
	}

	int sizeOfNumberTwo = 0;
	numberTemp = numberTwo;
	while (numberTemp != 0)
	{
		numberTemp /= 10;
		sizeOfNumberTwo++;
	}

	if (sizeOfNumberOne < sizeOfNumberTwo)
	{
		puts("False!");
		return;
	}

	int newNumber;
	int digit = 0;
	numberTemp = numberOne;
	for (int i = 0; i <= sizeOfNumberOne - sizeOfNumberTwo; i++)
	{
		newNumber = 0;

		for (int j = 0; j < sizeOfNumberTwo; j++)
		{
			digit = numberTemp / ((int)pow(10, sizeOfNumberOne - 1  - j - i));
			numberTemp -= digit * ((int)pow(10, sizeOfNumberOne - 1 - j - i));

			newNumber += digit;
			newNumber *= j + 1 != sizeOfNumberTwo ? 10 : 1;
		}
		
		if (newNumber == numberTwo)
		{
			puts("True");
			return;
		}

		numberTemp = numberOne % ((int)pow(10, sizeOfNumberOne - 1 - i));
	}

	puts("False!");
	return 0;
}