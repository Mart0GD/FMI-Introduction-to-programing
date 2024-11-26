#include<stdio.h>

/*
Задача 9: Въвеждат се 5 цели числа – a, b, c, d, e. Разглеждаме полинома f(x) = a*x^4 + b*x^3 + c*x^2 + d*x + e. Отпечатайте всички цели решения на f(x) >= 0, където x e в интервала [-100, 100].
Вход: -1 4 0 8 1, Изход: -1 0 2 3
Вход: 0 0 -1 5 -6, Изход: 2 3
*/
int main_03_09()
{
	const MIN_SOLUTION_BOUNDRY = -100;
	const MAX_SOLUTION_BOUNDRY = 100;

	int a, b, c, d, e;
	scanf_s("%d %d %d %d %d", &a, &b, &c, &d, &e);

	double result = 0;
	for (int x = MIN_SOLUTION_BOUNDRY; x <= MAX_SOLUTION_BOUNDRY; x++)
	{
		result = a * (x * x * x * x) + b * (x * x * x) + c * (x * x) + d * x + e;
		//			-1					-4					0			-8		1
		if (result >= 0)
		{
			printf("%d ", x);
		}
	}
	return 0;
}