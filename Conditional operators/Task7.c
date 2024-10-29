#include<stdio.h>
#include<math.h>

/*
��������, �� ������� � ��������� ����������� ������� (0, 0). �� �� ������ ��������, ����� �� �������� ���������� �� �������� ����� (x, y) � ������ �� ��������� r, ������ ���� ������� � �����, ��� ��� �� �� ������� �� ����� � ������ (0, 0) � ������ r;
*/
int main7()
{
	double const e = 0.001;
	int const circleCenterX = 0;
	int const circleCenterY = 0;

	int x, y;
	double radius;

	puts("insert x and y:");
	scanf_s("%d %d", &x, &y);
	puts("insert radius:");
	scanf_s("%lf", &radius);

	double distance = sqrt(pow(x, 2) + pow(y, 2));
	int isInside = distance < radius;
	double onBorder = fabs(distance - radius) <= ( (fabs(distance) < fabs(radius) ? fabs(radius) : fabs(distance)) * e);

	if (onBorder) { puts("point is on the border"); }
	else if (isInside) { puts("point is inside"); }
	else { puts("point is outside"); }

	return 0;
}