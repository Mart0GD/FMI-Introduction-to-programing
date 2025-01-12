#include<stdio.h>

//int main()
//{
//	int borderA;
//	int borderB;
//	int numberToCheck;
//
//	printf("Enter number area (2 whole numbers) and one number to check: ");
//	scanf_s("%d %d %d", &borderA, &borderB, &numberToCheck);
//
//	int isBorderASmaller = borderA < borderB;
//	int lowerBorder = borderA * isBorderASmaller + borderB * !isBorderASmaller;
//	int upperBorder = borderA * !isBorderASmaller + borderB * isBorderASmaller;
//
//	printf("answer:\n");
//	printf("%d", lowerBorder <= numberToCheck && numberToCheck <= upperBorder);
// 
//	return 0;
//}