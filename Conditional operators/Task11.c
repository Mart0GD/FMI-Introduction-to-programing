#include<stdio.h>
#include<math.h>

/*
�������� ��������, ����� ������ ��� ������ ����� � �������� ���� ���� ����� ����� �� ����� ������ �� ����������. 
��� ���� �� �� �������� ����������, ���������� ������ �� �������� � ����� ��� � ���:

������������ ���������� -> �equilateral�
����������� ���������� -> �isosceles�
������������ ���������� -> �scalene�
��� �� ���� �� �� �������� ���������� -> �not a triangle�
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