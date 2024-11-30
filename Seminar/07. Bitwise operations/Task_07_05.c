#include<stdio.h>
#define SIGNED_INT_SIZE 32
/*
Задача 5: Напишете функция, която по подадени цели числа n и k връща дали k в двоичен запис (разглеждайки го без водещите 0-ли) е част от двоичния запис на n.
Вход: 15 3, Изход: true
Вход: 13 5, Изход: true
Вход: 13 7, Изход: false
*/

int decimalToBinary(int number, int binaryRepresentation[]) {
	
	int index = 0;
	while (number != 0)
	{
		binaryRepresentation[index] = number % 2;
		number /= 2;
		index++;
	}

	return index;
}

int isInfix(int num1[], int num2[], int num1LastIndex, int num2LastIndex) {

	if (num2LastIndex > num1LastIndex) { return 0; }

	int num1CurrentIndex = 0;
	int num2CurrentIndex = 0;
	int changed = 0;
	while (num2CurrentIndex <= num2LastIndex)
	{
		if (num1CurrentIndex == num1LastIndex && num2CurrentIndex < num2LastIndex)
		{
			return 0;
		}

		if (num1[num1CurrentIndex] == num2[num2CurrentIndex])
		{
			num2CurrentIndex++;
			num1CurrentIndex++;
			changed = 1;
			continue;
		}
		else if (num1[num1CurrentIndex] != num2[num2CurrentIndex] && changed)
		{
			num2CurrentIndex = 0;
			num1CurrentIndex++;
			changed = 0;
			continue;
		}

		num1CurrentIndex++;
	}

	return 1;
}

int main_07_05() {
	int num1, num2;
	scanf_s("%d %d", &num1, &num2);
	
	int binaryrepresentationOfNum1[SIGNED_INT_SIZE] = { 0 };
	int num1BinaryLength = decimalToBinary(num1, binaryrepresentationOfNum1);

	int binaryrepresentationOfNum2[SIGNED_INT_SIZE] = { 0 };
	int num2BinaryLength = decimalToBinary(num2, binaryrepresentationOfNum2);

	printf("%d binary infix of %d -> %d", num1, num2, isInfix(binaryrepresentationOfNum1, binaryrepresentationOfNum2, num1BinaryLength - 1, num2BinaryLength - 1));
	
	return 0;
}