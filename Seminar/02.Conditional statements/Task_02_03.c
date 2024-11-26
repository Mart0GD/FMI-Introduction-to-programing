#include<stdio.h>
/*
Задача 3 (Лице на фигура): Въвеждат се размерите на геометрична фигура. Да се напише програма, която пресмята лицето й.
Фигурите са четири вида: квадрат (s), правоъгълник (r), кръг (c) и триъгълник (t).
На първия ред на входа се чете вида на фигурата (square, rectangle, circle или triangle).

Ако фигурата е квадрат, на следващия ред се чете едно число – дължина на страната му.
Ако фигурата е правоъгълник, на следващите два реда се четат две числа – дължините на страните му.
Ако фигурата е кръг, на следващия ред се чете едно число – радиусът на кръга.
Ако фигурата е триъгълник, на следващите два реда се четат две числа – дължината на страната му и дължината на височината към нея.
Вход: s 5, Изход: 25
Вход: r 7 2.5, Изход: 17.5
Вход: c 6, Изход: 113.097
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