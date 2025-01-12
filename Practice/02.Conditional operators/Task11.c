#include<stdio.h>
#include<math.h>

/*
Напишете програма, която приема три реални числа и определя дали тези числа могат да бъдат страни на триъгълник. 
Ако може да се образува триъгълник, програмата трябва да определи и какъв тип е той:

Равностранен триъгълник -> “equilateral”
Равнобедрен триъгълник -> “isosceles”
Разностранен триъгълник -> “scalene”
Ако не може да се образува триъгълник -> “not a triangle”
*/
int main11()
{
	const int x1 = 0, y1 = 0, x2 = 5, y2 = 5;

	double sideA, sideB, sideC;
	scanf_s("%lf %lf %lf", &sideA, &sideB, &sideC);

	int isTriangleReal = sideA + sideB >= sideC;
	if (!isTriangleReal)
	{
		printf("not a triangle");
		return;
	}

	if (sideA == sideB == sideC)
	{
		printf("equilateral");
	}
	else if (sideA == sideB || sideB == sideC || sideC == sideA)
	{
		printf("isosceles");
	}
	else
	{
		printf("scalene");
	}

}