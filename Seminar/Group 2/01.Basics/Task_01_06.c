#include<stdio.h>
#include<math.h>

// Задача 6: Въвеждат се две цели числа - a и b. Да се отпечата резултата от (a + b)^4 - (a-b)^2.
int main01_6()
{
	int a, b;
	scanf_s("%d %d", &a, &b);

	int sum = a + b;

	int abToThePowerOfFour = sum * sum * sum * sum;
	int abToThePowerOfFour2 = pow(a, 4) + 4 * pow(a, 3) * b + 6 * pow(a, 2) * pow(b, 2) + 4 * a * pow(b, 3) + pow(b, 4);

	int abToThePowerOfTwo= sum * sum;

	printf("(a + b)^4 first method: %d\n", abToThePowerOfFour);
	printf("(a + b)^4 second method: %d\n", abToThePowerOfFour2);

	printf("(a + b)^2: %d", abToThePowerOfTwo);
	return 0;
}