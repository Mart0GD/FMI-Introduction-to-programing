#include<stdio.h>
/*
������ 3 (���� �� ������): �������� �� ��������� �� ����������� ������. �� �� ������ ��������, ����� �������� ������ �.
�������� �� ������ ����: ������� (s), ������������ (r), ���� (c) � ���������� (t).
�� ������ ��� �� ����� �� ���� ���� �� �������� (square, rectangle, circle ��� triangle).

��� �������� � �������, �� ��������� ��� �� ���� ���� ����� � ������� �� �������� ��.
��� �������� � ������������, �� ���������� ��� ���� �� ����� ��� ����� � ��������� �� �������� ��.
��� �������� � ����, �� ��������� ��� �� ���� ���� ����� � �������� �� �����.
��� �������� � ����������, �� ���������� ��� ���� �� ����� ��� ����� � ��������� �� �������� �� � ��������� �� ���������� ��� ���.
����: s 5, �����: 25
����: r 7 2.5, �����: 17.5
����: c 6, �����: 113.097
*/
int main_02_03()
{
	const double pi = 3.1415927;

	char shape;
	scanf_s("%c", &shape);

	double area = 0;
	if (shape == 's')
	{
		double side;
		scanf_s("%lf", &side);

		area = side * side;
	}
	else if (shape == 'r')
	{
		double sideA, sideB;
		scanf_s("%lf %lf", &sideA, &sideB);

		area = sideA * sideB;
	}
	else if (shape == 'c')
	{
		double radius;
		scanf_s("%lf", &radius);

		area = (radius * radius) * pi;
	}
	else if (shape == 't')
	{
		double side, height;
		scanf_s("%lf %lf", &side, &height);

		area = (side * height) / 2;
	}

	printf("area -> %.2lf", area);
	return;
}