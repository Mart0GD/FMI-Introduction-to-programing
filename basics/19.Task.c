#include<stdio.h>

//int main()
//{
//	int a;
//	int x, y;
//	int number;
//	int b, c;
//
//	scanf_s("%d %d %d %d %d %d", &a, &x, &y, &number, &b, &c);
//
//	int numberDigitOne = number % 10;
//	int numberDigitTwo = (number / 10) % 10;
//	int numberDigitThree = (number / 100) % 10;
//
//	int bDigitOne = b % 10;
//	int bDigitTwo = (b / 10) % 10;
//	int bDigitThree = (b / 100) % 10;
//	int bReverse = (((bDigitOne * 10) + bDigitTwo) * 10) + bDigitThree;
//
//	int cDigitOne = c % 10;
//	int cDigitTwo = (c / 10) % 10;
//	int cDigitThree = (c / 100) % 10;
//	int cReverse = (((cDigitOne * 10) + cDigitTwo) * 10) + cDigitThree;
//
//	printf("q1 -> %d\n", (a % 4 == 0) || (a % 7 == 0)); 
//	printf("q2 -> %d\n", x || y);
//	printf("q3 -> %d\n", x && y);
//	printf("q4 -> %d\n", x ^ y); // ;D
//	printf("q5 -> %d\n", (numberDigitOne < numberDigitTwo < numberDigitThree) || (numberDigitOne > numberDigitTwo > numberDigitThree));
//	printf("q6 -> %d\n", b == bReverse && c == cReverse);
//
//
//
//	return 0;
//}