#include<stdio.h>
#include<math.h>
//
//int main()
//{
//	int number;
//
//	scanf_s("%d", &number);
//
//	int lastDigit = number % 10;
//	number /= 10;
//	int secondDigit = number % 10;
//	number /= 10;
//	int firstDigit = number % 10;
//
//	int reverse = ((((0 + lastDigit) * 10) + secondDigit) * 10) + firstDigit; // bez cikli tolkoz ;D
//	int sumOfCubeDigits = pow(firstDigit, 3) + pow(secondDigit, 3) + pow(lastDigit, 3);
//
//	printf("Reversed: ");
//	printf("%d\n", reverse);
//
//	printf("Sum of cubes: ");
//	printf("%d\n", sumOfCubeDigits);
//
//	return 0;
//}