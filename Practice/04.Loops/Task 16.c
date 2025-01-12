#include<stdio.h>
#include<math.h>
/*
Напишете програма, която прочита 2 цели числа от конзолата, намира техният сбор и разлика и ги принтира на конзолата. 
Реализирайте събирането и изваждането на 2те числа, използвайки само побитови логически операции.

*/

int add(int num1, int num2) 
{
	unsigned carry = 0;
	while (num2 != 0) // 1000 1111
	{
		carry = num1 & num2; // 1000, 00000

		num1 = (num1 ^ num2);// 0111, 10111
		num2 = carry << 1;//10000, 000000
	}

	return num1;
}

int subtract(int num1, int num2)
{
	unsigned leftover = 0;
	while (num2 != 0) // 101 100 -> 1
	{
		leftover = ~num1 & num2; // 000

		num1 = (num1 ^ num2); //110
		num2 = leftover << 1;//0000
	}

	return num1;
}

int main_16()
{
	int numberOne, numberTwo;
	scanf_s("%d %d", &numberOne, &numberTwo);


	printf("%d + %d = ", numberOne, numberTwo);
	printf("%d\n", add(numberOne, numberTwo));
	
	printf("%d - %d = ", numberOne, numberTwo);
	printf("%d", subtract(numberOne, numberTwo));

	return 0;
}